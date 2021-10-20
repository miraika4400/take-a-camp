////////////////////////////////////////////////////
//
//    tileクラスの処理[tile.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "tile.h"
#include "manager.h"
#include "renderer.h"
#include "resource_shader.h"
#include "camera_base.h"
#include "light.h"
#include "collision.h"
#include "bullet.h"
#ifdef _DEBUG
#include "keyboard.h"
#endif

//*****************************
// マクロ定義
//*****************************
#define PEINT_COUNT 60  // 再度塗れるようになるまでのカウント

//*****************************
// 静的メンバ変数宣言
//*****************************

//******************************
// コンストラクタ
//******************************
CTile::CTile() :CModel(OBJTYPE_TILE)
{                       
	m_color = TILE_DEFAULT_COLOR;
	m_pCollison = NULL;
}

//******************************
// デストラクタ
//******************************
CTile::~CTile()
{
}

//******************************
// クラス生成
//******************************
CTile * CTile::Create(D3DXVECTOR3 pos)
{
	// メモリの確保
	CTile *pTile;
	pTile = new CTile;

	// 初期化
	pTile->Init();

	// 各値の代入・セット
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // オブジェクトタイプ

	return pTile;
}

//******************************
// 初期化処理
//******************************
HRESULT CTile::Init(void)
{
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// モデル割り当て
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_GENERAL_BOX));

	// サイズの設定
	SetSize(TILE_SIZE);

	// 色の設定
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	return S_OK;
}

//******************************
// 終了処理
//******************************
void CTile::Uninit(void)
{
	CModel::Uninit();
}

//******************************
// 更新処理
//******************************
void CTile::Update(void)
{
	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + TILE_ONE_SIDE / 2, GetPos().z), TILE_ONE_SIDE / 2);
	}
	else
	{
		if (m_pCollison->GetPos() != D3DXVECTOR3(GetPos().x, GetPos().y + TILE_ONE_SIDE / 2, GetPos().z))
		{
			m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + TILE_ONE_SIDE / 2, GetPos().z));
		}
	}

	// 弾との当たり判定
	CollisionBullet();
}

//******************************
// 描画処理
//******************************
void CTile::Draw(void)
{
	/////////////////////////////　
	//仮
	// 色の設定
	D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
	mat->MatD3D.Ambient = m_color;
	mat->MatD3D.Diffuse = m_color;
	mat->MatD3D.Specular = m_color;
	mat->MatD3D.Emissive = m_color;

	////////////////////////////

	CModel::Draw();
}

//******************************
// モデル描画処理
//******************************
void CTile::DrawModel(void)
{
	//デバイス情報の取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DMATERIAL9 matDef; //現在のマテリアル保持用
	D3DXMATERIAL*pMat;   //マテリアルデータへのポインタ

	// モデルデータの取得
	CResourceModel::Model * pModelData = GetModelData();

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &pModelData->mtxWorld);

	//現在のマテリアルを取得する
	pDevice->GetMaterial(&matDef);

	// シェーダー情報の取得
	CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_TILE);
	if (shader.pEffect != NULL)
	{
		// シェーダープログラムに値を送る
		SetShaderVariable(shader.pEffect, pModelData);
		if (pModelData->pBuffMat != NULL)
		{
			//マテリアルデータへのポインタを取得
			pMat = (D3DXMATERIAL*)pModelData->pBuffMat->GetBufferPointer();

			// パス数の取得
			UINT numPass = 0;
			shader.pEffect->Begin(&numPass, 0);

			// パス数分描画処理のループ
			for (int nCntEffect = 0; nCntEffect < (int)numPass; nCntEffect++)
			{
				for (int nCntMat = 0; nCntMat < (int)pModelData->nNumMat; nCntMat++)
				{
					//マテリアルのアンビエントにディフューズカラーを設定
					pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

					//マテリアルの設定
					pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
					// テクスチャ
					pDevice->SetTexture(0, pModelData->apTexture[nCntMat]);

					// 色の情報を送る
					shader.pEffect->SetFloatArray("DiffuseColor", (float*)&m_color, 4);

					// シェーダパスの描画開始
					shader.pEffect->BeginPass(nCntEffect);
					//モデルパーツの描画
					pModelData->pMesh->DrawSubset(nCntMat);
					// シェーダパスの終了
					shader.pEffect->EndPass();

					pMat[nCntMat] = pModelData->defMat[nCntMat];
				}
			}
			// シェーダー終了
			shader.pEffect->End();
		}
	}
	//保持していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);
	// テクスチャ情報の初期化
	pDevice->SetTexture(0, 0);
}


//=============================
// シェーダーに値を送る
//=============================
void CTile::SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData)
{
	if (pEffect != NULL)
	{
		// シェーダーに情報を渡す
		D3DXMATRIX mat;
		D3DXMatrixIdentity(&mat);
		mat = pModelData->mtxWorld * (*CManager::GetCamera()->GetViewMtx())* (*CManager::GetCamera()->GetProjectionMtx());
		// ワールドプロジェクション
		pEffect->SetMatrix("WorldViewProj", &mat);
		// ワールド座標
		pEffect->SetMatrix("World", &pModelData->mtxWorld);
		// ライトディレクション
		D3DXVECTOR3 lightDir = LIGHT_DIR_BASE;
		pEffect->SetFloatArray("LightDirection", (float*)&D3DXVECTOR3(lightDir.x, lightDir.y, lightDir.z), 3);

		// 視点位置
		D3DXVECTOR3 eye = CManager::GetCamera()->GetPos();
		pEffect->SetFloatArray("Eye", (float*)&D3DXVECTOR3(eye.x, eye.y, eye.z), 3);

		// スペキュラの情報を送る
		pEffect->SetFloatArray("SpecularColor", (float*)&D3DXCOLOR(1.0f,1.0f,1.0f,1.0f), 4);
	}
}

//******************************
// 弾との当たり判定
//******************************
void CTile::CollisionBullet(void)
{
	CBullet * pBullet = (CBullet*)GetTop(OBJTYPE_BULLET);

	while (pBullet != NULL)
	{
		if (CCollision::CollisionSphere(GetCollision(), pBullet->GetCollision()))
		{

			return;
		}
		pBullet = (CBullet*)pBullet->GetNext();
	}
}
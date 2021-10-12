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
#include "collision.h"
#include "player.h"
#include "color_manager.h"
#include "scene3d.h"
#include "resource_texture.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// マクロ定義
//*****************************
#define DEFAULT_COLOR D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)
#define PEINT_COUNT 60  // 再度塗れるようになるまでのカウント

//*****************************
// 静的メンバ変数宣言
//*****************************

//******************************
// コンストラクタ
//******************************
CTile::CTile() :CModel(OBJTYPE_TILE)
{
	m_pCollison = NULL;                          
	m_color = DEFAULT_COLOR;
	m_nPrevNum = -1;                             // 今塗られているカラーの番号*デフォルトは-1
	m_nStep = 0;                                 // 今の塗段階
	m_nCntStep = 0;                              // 再度塗り可能カウント
	m_nLastHitPlayerNum = -1;
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

	// アイコン
	m_pIcon = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE, 0.0f, TILE_ONE_SIDE));
	m_pIcon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CROSS_MARK));
	m_pIcon->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pIcon->SetPriority(OBJTYPE_UI);

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
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y+ TILE_ONE_SIDE/2, GetPos().z), TILE_ONE_SIDE/2);
	}


	// プレイヤーとの当たり判定
	CollisionPlayer();
	
	// アイコンの管理
	ManageIcon();

	if (m_nCntStep > 0)
	{
		m_nCntStep--;
	}
#ifdef _DEBUG
	// デバッグキー

	// キーボードの取得
	CInputKeyboard * pKey = CManager::GetKeyboard();

	if (pKey->GetKeyPress(DIK_NUMPADENTER))
	{// 前進
		m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
#endif // _DEBUG
}

//******************************
// 描画処理
//******************************
void CTile::Draw(void)
{
	/////////////////////////////
	//仮;
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
// プレイヤーとの当たり判定
//******************************
void CTile::CollisionPlayer(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (CCollision::CollisionSphere(m_pCollison, pPlayer->GetCollision()))
		{
			Peint(pPlayer->GetColorNumber(), pPlayer->GetPlayerNumber());
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//******************************
// アイコンの管理
//******************************
void CTile::ManageIcon(void)
{
	// 位置の調整
	D3DXVECTOR3 pos = m_pIcon->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) +1.0f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 1.0f, GetPos().z);

		m_pIcon->SetPos(pos);
	}
}

//******************************
// 塗処理
//******************************
void CTile::Peint(int nColorNumber , int nPlayerNum)
{
	if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum )
	{
		m_nLastHitPlayerNum = nPlayerNum;

		if (m_nPrevNum == -1)
		{// 今何も塗られていない
			m_nPrevNum = nColorNumber;
			m_color = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep);
			m_nStep++;
			m_nCntStep = PEINT_COUNT;
		}
		else if (m_nPrevNum == nColorNumber)
		{// 今塗られているのとから塗る番号の比較
			if (m_nStep < COLOR_STEP_NUM)
			{
				m_nStep++;
				m_color = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep-1);
				
				m_nCntStep = PEINT_COUNT;
			}
		}
		else
		{
			if (m_nStep == 1)
			{
				m_nPrevNum = -1;
				m_color = DEFAULT_COLOR;
				m_nStep = 0;
				m_nCntStep = PEINT_COUNT;
			}
			else
			{
				m_nStep--;
				m_color = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep-1);
				m_nCntStep = PEINT_COUNT;
			}
		}
	}

}

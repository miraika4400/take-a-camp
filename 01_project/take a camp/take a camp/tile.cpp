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

#ifdef _DEBUG
#include "manager.h"
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
//====================================================
//
//    dummy_tileクラスの処理[dummy_tile.cpp]
//    Author:伊藤　陽梧
//
//====================================================

//====================================================
// インクルード
//====================================================
#include "titletransition_tile.h"
#include "scene3d.h"
#include "resource_texture.h"

//====================================================
// コンストラクタ
//====================================================
CTitleTransitionTile::CTitleTransitionTile()
{
	m_pCrossPolygon = NULL;
}

//====================================================
// デストラクタ
//====================================================
CTitleTransitionTile::~CTitleTransitionTile()
{
}

//====================================================
// クラス生成
//====================================================
void CTitleTransitionTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// メモリの確保
	CTitleTransitionTile *pTile;
	pTile = new CTitleTransitionTile;

	// 初期化
	pTile->Init();

	// 各値の代入・セット
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // オブジェクトタイプ
	pTile->SetRide(true);			  // 載れないようにフラグを立てる

	// ×マークの生成
	//pTile->m_pCrossPolygon = CScene3d::Create(D3DXVECTOR3(pos.x, pos.y + (TILE_SIZE_Y / 2) + 1.0f, pos.z), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	//pTile->m_pCrossPolygon->SetColor(col);
	//pTile->m_pCrossPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CROSS_MARK));
	//pTile->m_pCrossPolygon->SetPriority(OBJTYPE_MAP);
}

//====================================================
// 初期化処理
//====================================================
HRESULT CTitleTransitionTile::Init(void)
{
	// タイルの初期化
	if (FAILED(CTile::Init()))
	{
		return E_FAIL;
	}

	// タイルの色のセット
	SetColor(TILE_DEFAULT_COLOR);

	return S_OK;
}

//====================================================
// 終了処理
//====================================================
void CTitleTransitionTile::Uninit(void)
{
	// タイルの終了
	CTile::Uninit();
}
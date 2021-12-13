//=============================================================================
//
// ワープ床ヘッダー [warp_tile.cpp]
// Author : 吉田 悠人
//
//=============================================================================

//*****************************
// インクルード
//*****************************
#include "warp_tile.h"
#include <vector>
//******************************
// 静的メンバ変数宣言
//******************************
int CWarpTile::m_nTotalWarpTile = 0;
std::vector<CWarpTile*> CWarpTile::m_pWarpTile;
//******************************
// コンストラクタ
//******************************
CWarpTile::CWarpTile()
{
	m_WarpType = WARP_TILE_TYPE_NONE;
}

//******************************
// デストラクタ
//******************************
CWarpTile::~CWarpTile()
{
}

//******************************
// 生成処理
//******************************
CWarpTile * CWarpTile::Create(D3DXVECTOR3 pos, WARP_TILE_TYPE nWarpTile)
{
	//
	//if (m_nTotalWarpTile == 0)
	//{

	//}
	//else
	//{
	//}

	//動的配列にメモリ確保
	m_pWarpTile.emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(m_nTotalWarpTile)!=NULL)
	{
		//位置設定
		m_pWarpTile.at(m_nTotalWarpTile)->SetPos(pos);
		//識別用数値設定
		m_pWarpTile.at(m_nTotalWarpTile)->m_WarpType = nWarpTile;
		//初期化処理
		m_pWarpTile.at(m_nTotalWarpTile)->Init();
		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}
	

	return m_pWarpTile.at(m_nTotalWarpTile-1);
}

//******************************
// 初期化処理
//******************************
HRESULT CWarpTile::Init(void)
{
	//タイル初期化処理
	CTile::Init();
	//タイプごとの見た目変化
	switch (m_WarpType)
	{
	case WARP_TILE_TYPE_1:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_2:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
		break;
	}

	return S_OK;
}

//******************************
// 終了処理
//******************************
void CWarpTile::Uninit(void)
{
	//動的配列の削除
	for (int nWarpCount=0; nWarpCount<m_nTotalWarpTile; nWarpCount++)
	{
		if (m_pWarpTile.at(nWarpCount) = this)
		{
			m_nTotalWarpTile--;
			m_pWarpTile.erase(m_pWarpTile.begin() + (nWarpCount - 1));
			break;
		}
	}

	//終了処理
	CTile::Uninit();
}

//******************************
// 更新処理
//******************************
void CWarpTile::Update(void)
{

}

//******************************
// プレイヤーが乗っているか
//******************************
void CWarpTile::HitPlayerAction(CPlayer * pPlayer)
{

}

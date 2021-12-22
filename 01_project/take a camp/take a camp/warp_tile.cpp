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
#include "player.h"
#include <vector>
#include <time.h>

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
	m_WarpState = WARP_TILE_NORMAL;
	m_WarpType  = WARP_TILE_TYPE_NONE;
}

//******************************
// デストラクタ
//******************************
CWarpTile::~CWarpTile()
{
}

//******************************
// 生成処理(タイプ1)
//******************************
void CWarpTile::Create_1(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//動的配列にメモリ確保
	m_pWarpTile.emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(m_nTotalWarpTile)!=NULL)
	{
		//識別用数値設定
		m_pWarpTile.at(m_nTotalWarpTile)->m_WarpType = WARP_TILE_TYPE_1;
		//初期化処理
		m_pWarpTile.at(m_nTotalWarpTile)->Init();
		//位置設定
		m_pWarpTile.at(m_nTotalWarpTile)->SetPos(pos);
		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}
}

//******************************
// 生成処理(タイプ2)
//******************************
void CWarpTile::Create_2(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//動的配列にメモリ確保
	m_pWarpTile.emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(m_nTotalWarpTile) != NULL)
	{
		//識別用数値設定
		m_pWarpTile.at(m_nTotalWarpTile)->m_WarpType = WARP_TILE_TYPE_2;
		//初期化処理
		m_pWarpTile.at(m_nTotalWarpTile)->Init();
		//位置設定
		m_pWarpTile.at(m_nTotalWarpTile)->SetPos(pos);
		m_pWarpTile.at(m_nTotalWarpTile)->SetPriority(OBJTYPE_TILE); 	// オブジェクトタイプ

		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}
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
		SetColor(D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_2:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f,0.0f,1.0f,1.0f));
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
		if (m_pWarpTile.at(nWarpCount) == this)
		{
			m_nTotalWarpTile--;
			m_pWarpTile.erase(m_pWarpTile.begin() + (nWarpCount));
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
	switch (m_WarpState)
	{
		//通常状態
	case WARP_TILE_NORMAL:
		break;
		//ワープ状態
	case WARP_TILE_WARP:
		break;
		//機能停止状態
	case WARP_TILE_STOP:
		break;

	}

	// タイル更新処理
	CTile::Update();
}

//******************************
// プレイヤーが乗っているか
//******************************
void CWarpTile::HitPlayerAction(CPlayer * pPlayer)
{
	switch (m_WarpState)
	{
	
	case WARP_TILE_NORMAL:	//通常状態
	{
		//タイルに乗れなくなるフラグを立てる
		SetRide(true);
		//プレイヤーをストップ状態に変更
		pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);

		//同タイプのクラス保存用変数
		CWarpTile ** pWarpTile = nullptr;
		//数保存
		int nArray = 0;
		//同じタイプからワープ先を決める
		for (int nWarpCount = 0; nWarpCount<m_nTotalWarpTile; nWarpCount++)
		{
			//同じタイプか&&自分以外のポインタ
			if (m_WarpType == m_pWarpTile.at(nWarpCount)->m_WarpType
				&&m_pWarpTile.at(nWarpCount) != this)
			{
				//同タイプのポインタ取得
				pWarpTile[nArray] = m_pWarpTile.at(nWarpCount);
				//プラス
				nArray++;
			}
		}

		//ランダム関数の初期化
		srand((unsigned int)time(NULL));
		//ランダムに飛ばすタイル
		int nRandTile = rand() % nArray;

		//NULLチェック
		if (pWarpTile[nRandTile] != nullptr)
		{
			//ワープ状態の変更
			m_WarpState = WARP_TILE_WARP;
			//ワープ先のステート変化
			pWarpTile[nRandTile]->m_WarpState = WARP_TILE_STOP;
			//ランダムにタイルの位置に飛ばす
			pPlayer->SetPos(pWarpTile[nRandTile]->GetPos());
		}
	}
		break;
	case WARP_TILE_WARP:	//ワープ状態

		break;
	case WARP_TILE_STOP:	//停止状態
		//プレイヤーをストップ状態に変更
		pPlayer->SetState(CPlayer::PLAYER_STATE_NORMAL);
		break;

	}
}

//******************************
// プレイヤーが降りた処理
//******************************
void CWarpTile::HitPlayerActionRelease(void)
{
	if (m_WarpState == WARP_TILE_STOP)
	{
		//タイルのステートを変化
		m_WarpState = WARP_TILE_NORMAL;
		//タイルに乗れるフラグを立てる
		SetRide(false);
	}
}

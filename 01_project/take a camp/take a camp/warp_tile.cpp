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
#include "collision.h"
#include "sound.h"
#include <vector>
#include <time.h>

//*****************************
//マクロ定義
//*****************************
#define MAX_RESTRAINT (20)
//******************************
// 静的メンバ変数宣言
//******************************
int CWarpTile::m_nTotalWarpTile = 0;
std::vector<std::vector<CWarpTile*>> CWarpTile::m_pWarpTile(WARP_TILE_TYPE_MAX, std::vector<CWarpTile*>(0));

//******************************
// コンストラクタ
//******************************
CWarpTile::CWarpTile()
{
	memset(&m_nPlayerCount, 0, sizeof(m_nPlayerCount));
	m_nLyncTile = 0;
	memset(&m_WarpState, WARP_TILE_NORMAL, sizeof(m_WarpState));
	m_WarpType = WARP_TILE_TYPE_NONE;
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
	m_pWarpTile.at(WARP_TILE_TYPE_1).emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1)->m_WarpType = WARP_TILE_TYPE_1;
		//初期化処理
		m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1)->Init();
		//位置設定
		m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1)->SetPos(pos);
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
	m_pWarpTile.at(WARP_TILE_TYPE_2).emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1)->m_WarpType = WARP_TILE_TYPE_2;
		//初期化処理
		m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1)->Init();
		//位置設定
		m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1)->SetPos(pos);
		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}
}

//******************************
// 生成処理(タイプ3)
//******************************
void CWarpTile::Create_3(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//動的配列にメモリ確保
	m_pWarpTile.at(WARP_TILE_TYPE_3).emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1)->m_WarpType = WARP_TILE_TYPE_3;
		//初期化処理
		m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1)->Init();
		//位置設定
		m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1)->SetPos(pos);
		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}

}

//******************************
// 生成処理(タイプ4)
//******************************
void CWarpTile::Create_4(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//動的配列にメモリ確保
	m_pWarpTile.at(WARP_TILE_TYPE_4).emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1)->m_WarpType = WARP_TILE_TYPE_4;
		//初期化処理
		m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1)->Init();
		//位置設定
		m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1)->SetPos(pos);
		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}

}

//******************************
// 生成処理(タイプ5)
//******************************
void CWarpTile::Create_5(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//動的配列にメモリ確保
	m_pWarpTile.at(WARP_TILE_TYPE_5).emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1)->m_WarpType = WARP_TILE_TYPE_5;
		//初期化処理
		m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1)->Init();
		//位置設定
		m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1)->SetPos(pos);
		//ワープタイルの総数追加
		m_nTotalWarpTile++;
	}

}

//******************************
// 生成処理(タイプ6)
//******************************
void CWarpTile::Create_6(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//動的配列にメモリ確保
	m_pWarpTile.at(WARP_TILE_TYPE_6).emplace_back(new CWarpTile);

	//NULLチェック
	if (m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1)->m_WarpType = WARP_TILE_TYPE_6;
		//初期化処理
		m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1)->Init();
		//位置設定
		m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1)->SetPos(pos);
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
	case WARP_TILE_TYPE_3:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_4:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_5:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_6:
		//テクスチャの設定

		//カラーの設定
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
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
	for (int nWarpType=0; nWarpType<WARP_TILE_TYPE_MAX; nWarpType++)
	{
		//配列の最大数取得
		int nMaxArray = m_pWarpTile.at(nWarpType).size();

		//配列分回す
		for (int nWarpCount = 0; nWarpCount<nMaxArray; nWarpCount++)
		{
			if (m_pWarpTile.at(nWarpType).at(nWarpCount) == this)
			{
				m_pWarpTile.at(nWarpType).erase(m_pWarpTile.at(nWarpType).begin() + (nWarpCount));
				break;
			}
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

	// タイル更新処理
	CTile::Update();
}

//******************************
// プレイヤーが乗っているか
//******************************
void CWarpTile::HitPlayerAction(CPlayer * pPlayer)
{
	// サウンド情報の取得
	CSound *pSound = CManager::GetSound();

	switch (m_WarpState[pPlayer->GetPlayerNumber()])
	{
	case WARP_TILE_NORMAL:	//通常状態
		{
			//プレイヤーの状況確認
			if (pPlayer->GetState() != CPlayer::PLAYER_STATE_STOP
				&&pPlayer->GetState() != CPlayer::PLAYER_STATE_DEATH)
			{
				//プレイヤーが動いてないときにステートを停止状態に変更
				if (pPlayer->GetMoveFlag())
				{
					pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);
					m_WarpState[pPlayer->GetPlayerNumber()] = WARP_TILE_WARP;

					// SE再生
					pSound->Play(CSound::LABEL_SE_WARP);
				}
			}
			break;
		}
	case WARP_TILE_WARP:	//ワープ状態
		{
			//ワープ先の設定
			D3DXVECTOR3 Tile = RandTileSelect();
			//プレイヤーの位置設定
			pPlayer->SetPos(D3DXVECTOR3(Tile.x, pPlayer->GetPos().y, Tile.z));
			
			m_pWarpTile.at(m_WarpType).at(m_nLyncTile)->m_WarpState[pPlayer->GetPlayerNumber()] = WARP_TILE_WARP_AFTER;
			break;
		}
	case WARP_TILE_WARP_AFTER:	//ワープ先状態
		{
			m_nPlayerCount[pPlayer->GetPlayerNumber()]++;
			if (m_nPlayerCount[pPlayer->GetPlayerNumber()]>MAX_RESTRAINT)
			{
				//プレイヤーをノーマル状態に変更
				pPlayer->SetState(CPlayer::PLAYER_STATE_NORMAL);
			}
			break;
		}
	}
}

//******************************
// プレイヤーが降りた処理
//******************************
void CWarpTile::HitPlayerActionRelease(CPlayer*pPlayer)
{
	if (m_WarpState[pPlayer->GetPlayerNumber()] == WARP_TILE_WARP_AFTER)
	{
		//配列の最大数取得
		int nMaxArray = m_pWarpTile.at(m_WarpType).size();

		for (int nWarpCount = 0; nWarpCount < nMaxArray; nWarpCount++)
		{
			//タイルのステートを変化
			m_pWarpTile.at(m_WarpType).at(nWarpCount)->m_WarpState[pPlayer->GetPlayerNumber()] = WARP_TILE_NORMAL;
			m_nPlayerCount[pPlayer->GetPlayerNumber()] = 0;
		}
	}

}

//******************************
// 他のワープ先をランダムで取得
//******************************
D3DXVECTOR3 CWarpTile::RandTileSelect(void)
{
	//ループを続けるか
	bool bLync = false;
	//ランダムの最大値
	int nMaxRand = m_pWarpTile.at(m_WarpType).size();
	//ランダム関数の初期化
	srand((unsigned int)time(NULL));
	//同じタイルを選ばないように設定
	while (!bLync)
	{
		//ランダムに飛ばすタイル
		m_nLyncTile = rand() % nMaxRand;
		if (m_pWarpTile.at(m_WarpType).at(m_nLyncTile) != this)
		{
			//ループを抜ける
			bLync = true;

		}
	}
	//ランダムに跳ぶタイル位置取得
	return m_pWarpTile.at(m_WarpType).at(m_nLyncTile)->GetPos();

}


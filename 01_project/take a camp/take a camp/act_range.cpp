//=============================================================================
//
// 行動範囲ヘッダ [act_range.h]
// Author : 吉田 悠人
//
//=============================================================================
//*****************************
// インクルード
//*****************************
#include "act_range.h"
#include "player.h"
#include "tile.h"
#include "stage.h"
#include "game.h"


//=============================================================================
// コンストラクタ
//=============================================================================
CActRange::CActRange()
{
	//変数初期化
	m_pPlayer = nullptr;
	memset(&m_MapData, 0, sizeof(CStage::MAP_DATA));
	memset(&m_PlayerPos, 0, sizeof(D3DXVECTOR3));
	memset(&m_bPlayerMove, true, sizeof(bool[PLAYER_MOVE_MAX]));
}

//=============================================================================
// デストラクタ
//=============================================================================
CActRange::~CActRange()
{
}

//=============================================================================
// プレイヤーがどの位置にいるか
//=============================================================================
void CActRange::PlayerPos(void)
{
	//マップデータがあるか
	if (&m_MapData != NULL)
	{
		//プレイヤー位置取得
		D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

		for (int nBlockY = 0; nBlockY < m_MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				D3DXVECTOR3 BlockPos = D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos;
				if (PlayerPos.x>BlockPos.x - TILE_ONE_SIDE/2
					&&PlayerPos.x<BlockPos.x + TILE_ONE_SIDE/2
					&&PlayerPos.z>BlockPos.z - TILE_ONE_SIDE/2
					&&PlayerPos.z<BlockPos.z + TILE_ONE_SIDE/2)
				{
					//位置取得
					m_PlayerPos.x = (float)nBlockX;
					m_PlayerPos.z = (float)nBlockY;
				}
			}
		}
	}

}

//=============================================================================
// プレイヤーの移動範囲
//=============================================================================
void CActRange::ActRange(void)
{
	D3DXVECTOR3 Range[PLAYER_MOVE_MAX] =
	{
		D3DXVECTOR3(0,0,-1),
		D3DXVECTOR3(-1,0,0),
		D3DXVECTOR3(1,0,0),
		D3DXVECTOR3(0,0,1)
	};

	//上下左右にプレイヤーが移動できるか
	for (int nMove = 0; nMove<PLAYER_MOVE_MAX; nMove++)
	{
		//上下左右のタイルがあるか
		if (m_MapData.BlockData[(int)(m_PlayerPos.z + Range[nMove].z)].nBlockType[(int)(m_PlayerPos.x + Range[nMove].x)] == CStage::BLOCK_TYPE_NONE)
		{
			//移動できないためfalse
			m_bPlayerMove[nMove] = false;
		}
		else
		{
			//移動できるためtrue
			m_bPlayerMove[nMove] = true;
		}
	}
}

//=============================================================================
// 生成処理関数
//=============================================================================
CActRange * CActRange::Create(CPlayer * pPlayer)
{
	//メモリ確保
	CActRange *pActRange = nullptr;
	pActRange = new CActRange;
	
	//NULLチェック
	if (pActRange != NULL)
	{
		pActRange->m_pPlayer = pPlayer;	//プレイヤーのポインター
		pActRange->Init();				//初期化処理
	}

	return pActRange;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CActRange::Init(void)
{
	//最初の位置取得
	PlayerPos();
	//マップ情報取得
	m_MapData = CGame::GetStage()->GetMapData();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CActRange::Uninit(void)
{
	//オブジェクトの破棄
	Release();
}

//=============================================================================
// 更新関数
//=============================================================================
void CActRange::Update(void)
{
	//最初の位置取得
	PlayerPos();

	// プレイヤーの移動範囲
	ActRange();
}

//=============================================================================
// 描画関数
//=============================================================================
void CActRange::Draw(void)
{
}

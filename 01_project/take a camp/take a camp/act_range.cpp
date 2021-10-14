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
	m_bDeath  = false;
	memset(&m_MapData, 0, sizeof(CStage::MAP_DATA));
	memset(&m_ActPos, 0, sizeof(D3DXVECTOR3));
	memset(&m_bPlayerMove, true, sizeof(bool[PLAYER_MOVE_MAX]));
	memset(&m_OtherAct, 0, sizeof(OTHER_ACT[PLAYER_MOVE_MAX - 1]));
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
					m_ActPos.x = (float)nBlockX;
					m_ActPos.z = (float)nBlockY;
				}
			}
		}
	}

}

//=============================================================================
// マップ上のプレイヤーの移動判定関数
//=============================================================================
void CActRange::ActMove(int nMoveX, int nMoveZ)
{
	m_ActPos = D3DXVECTOR3(nMoveX, 0.0f, nMoveZ) + m_ActPos;
}

//=============================================================================
// 他のプレイヤーにぶつかり止まる判定
//=============================================================================
void CActRange::OtherPlayer(void)
{
	//リストのトップ取得
	CActRange* pActRange = (CActRange*)GetTop(OBJTYPE_ACT_RANGE);
	//他プレイヤー
	int nOtherPlayer = 0;
	//NULLチェック
	while (pActRange != NULL)
	{
		//自分以外
		if (pActRange != this)
		{
			//プレイヤーのマップ位置取得
			m_OtherAct[nOtherPlayer].OtherActPos = pActRange->GetActPos();
			//プレイヤーが死んでいるか
			m_OtherAct[nOtherPlayer].bDeath = pActRange->GetDeath();
			//次のプレイヤーへ
			nOtherPlayer++;
		}
		//次のポインタへ
		pActRange = (CActRange*)pActRange->GetNext();
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
		if (m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CStage::BLOCK_TYPE_NONE)
		{
			//移動できないためfalse
			m_bPlayerMove[nMove] = false;
		}
		else
		{
			for (int nPlayer = 0; nPlayer<MAX_PLAYER - 1; nPlayer++)
			{
				if ((m_ActPos + Range[nMove]) == m_OtherAct[nPlayer].OtherActPos && !m_OtherAct[nPlayer].bDeath)
				{
					//移動できないためfalse
					m_bPlayerMove[nMove] = false;
					break;
				}
				else
				{
					//移動できるためtrue
					m_bPlayerMove[nMove] = true;
				}
			}
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
		pActRange->SetPriority(OBJTYPE_ACT_RANGE); // オブジェクトタイプ
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
	//マップ情報取得
	m_MapData = CGame::GetStage()->GetMapData();

	//最初の位置取得
	PlayerPos();
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
	//他のプレイヤーのマップ位置
	OtherPlayer();
	// プレイヤーの移動範囲
	ActRange();
}

//=============================================================================
// 描画関数
//=============================================================================
void CActRange::Draw(void)
{
}

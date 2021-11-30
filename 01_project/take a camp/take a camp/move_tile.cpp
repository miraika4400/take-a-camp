////////////////////////////////////////////////////
//
//    動くタイルの処理[move_tile.cpp]
//    Author:吉田 悠人
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "move_tile.h"
#include "game.h"
#include "player.h"
#include "collision.h"

//*****************************
// マクロ定義
//*****************************
#define MOVE_SPEED (20)				// 移動が終わるまでのフレーム
#define MOVE_DIST  (TILE_ONE_SIDE)	// 移動距離

//******************************
// コンストラクタ
//******************************
CMoveTile::CMoveTile()
{
	m_bReversal = false;
	m_bStep = false;
	m_nMoveCount = 0;
	m_MoveState = MOVE_STATE_NORMAL;
	ZeroMemory(&m_Move, sizeof(m_Move));
}

//******************************
// デストラクタ
//******************************
CMoveTile::~CMoveTile()
{
}

////******************************
//// クラス生成
////******************************
//void CMoveTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
//{
//	// メモリの確保
//	CMoveTile *pTile;
//	pTile = new CMoveTile;
//	
//	//NULLチェック
//	if (pTile != NULL)
//	{
//		// 初期化
//		pTile->Init();
//
//		// 各値の代入・セット
//		pTile->m_Move = D3DXVECTOR3(0.0f, 0.0f, -20.0f) + pos;
//		pTile->SetPos(pos);
//		pTile->SetPriority(OBJTYPE_TILE); // オブジェクトタイプ
//
//	}
//}

//******************************
// 初期化関数
//******************************
HRESULT CMoveTile::Init(void)
{

	//タイルの初期化処理
	CTile::Init();
	//色の設定
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	//移動方向の判定
	HitTile();

	return S_OK;
}

//******************************
// 更新処理
//******************************
void CMoveTile::Update(void)
{
	CTile::Update();
	switch (m_MoveState)
	{
	case MOVE_STATE_NORMAL:
		
		break;
	case MOVE_STATE_MOVE:

		//移動処理
		Move();
		//当たり判定
		HitTile();
		
		break;
	default:
		
		break;
	}
}

//******************************
// プレイヤーとヒット時の処理
//******************************
void CMoveTile::HitPlayerAction(CPlayer * pPlayer)
{
	//通常状態の時
	if (m_MoveState == MOVE_STATE_NORMAL)
	{
		//タイルのステートを変化
		m_MoveState = MOVE_STATE_MOVE;
	}

	//プレイヤーの動きを止める
	if (pPlayer->GetState() != CPlayer::PLAYER_STATE_STOP
		&&pPlayer->GetState() != CPlayer::PLAYER_STATE_DEATH)
	{
		pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);
	}


	//現在位置
	D3DXVECTOR3 pos = GetPos();


	//プレイヤーを移動させる処理
	pPlayer->SetPos(D3DXVECTOR3(pos.x, pPlayer->GetPos().y, pos.z));

}

//******************************
// タイルの移動処理
//******************************
void CMoveTile::Move(void)
{

	//現在位置
	D3DXVECTOR3 pos = GetPos();
	//位置計算
	pos += (m_Move - pos) / (float)(MOVE_SPEED - m_nMoveCount);
	//位置設定
	SetPos(pos);

	//カウントアップ
	m_nMoveCount++;

	//カウントが一定に達したら
	if (MOVE_SPEED <= m_nMoveCount)
	{
		// カウント初期化
		m_nMoveCount = 0;
		// 反転しているか
		MoveRot(m_bReversal);
	}
}

//******************************
// 他のタイルとの当たり判定
//******************************
void CMoveTile::HitTile(void)
{
	//現在位置
	D3DXVECTOR3 Hitpos = D3DXVECTOR3((m_Move.x), GetPos().y, (m_Move.z));
	//リストのトップ取得
	CTile * pTile = CTile::GetHitTile(Hitpos);
	
	//NULLチェック
	if (pTile != NULL
		&&pTile != this)
	{
		//移動方向反転
		if (!m_bReversal)m_bReversal = true;
		else m_bReversal = false;
		// 反転しているか
		MoveRot(m_bReversal);
		//ステートを通常状態に変更
		m_MoveState = MOVE_STATE_NORMAL;
	}
}


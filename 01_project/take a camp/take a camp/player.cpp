////////////////////////////////////////////////////
//
//    playerクラスの処理[player.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "player.h"
#include "manager.h"
#include "keyboard.h"
#include "joypad.h"
#include "collision.h"
#include "debug_log.h"
#include "act_range.h"
#include "tile.h"

//*****************************
// マクロ定義
//*****************************
#define MOVE_DIST (TILE_ONE_SIDE)	// 移動距離
#define MOVE_FRAME 5				// 移動速度
#define COLLISION_RADIUS 20.0f

//*****************************
// 静的メンバ変数宣言
//*****************************

//******************************
// コンストラクタ
//******************************
CPlayer::CPlayer() :CModel(OBJTYPE_PLAYER)
{
	m_nPlayerNumber = 0;
	m_bMove = false;
	m_pCollison = NULL;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	m_MoveCoutn = 0;
	///////////////////////////////////////////////
	//仮
	m_color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	///////////////////////////////////////////////
}

//******************************
// デストラクタ
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// クラス生成
//******************************
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, int nPlayerNumber)
{
	// メモリの確保
	CPlayer *pPlayer;
	pPlayer = new CPlayer;

	// initで使うから先に代入
	pPlayer->m_nPlayerNumber = nPlayerNumber;

	// 初期化
	pPlayer->Init();

	// 各値の代入・セット
	pPlayer->SetPos(pos);
	pPlayer->SetPriority(OBJTYPE_PLAYER); // オブジェクトタイプ

	return pPlayer;
}

//******************************
// 初期化処理
//******************************
HRESULT CPlayer::Init(void)
{
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// モデル割り当て
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_PLAYER01));

	// 移動フラグの初期化
	m_bMove = true;

	//移動範囲クラスの生成
	m_pActRange = CActRange::Create(this);

	return S_OK;
}

//******************************
// 終了処理
//******************************
void CPlayer::Uninit(void)
{
	CModel::Uninit();
}

//******************************
// 更新処理
//******************************
void CPlayer::Update(void)
{
	// 移動処理
	Move();
	m_pActRange->PlayerPos();
	// 当たり判定の位置
	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS/2);
	}
	else
	{
		m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
	}

	// 
#ifdef _DEBUG
	// キーボードの取得
	CInputKeyboard * pKey = CManager::GetKeyboard();

	if (pKey->GetKeyPress(DIK_NUMPAD1))
	{
		m_color = D3DXCOLOR(0.8f, 0.8f, 1.0f, 1.0f);
	}
	if (pKey->GetKeyPress(DIK_NUMPAD2))
	{
		m_color = D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f);
	}
	if (pKey->GetKeyPress(DIK_NUMPAD3))
	{
		m_color = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (pKey->GetKeyPress(DIK_NUMPAD4))
	{
		m_color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}

#endif // _DEBUG

}

//******************************
// 描画処理
//******************************
void CPlayer::Draw(void)
{
	CModel::Draw();
}

//******************************
// 移動処理
//******************************
void CPlayer::Move(void)
{
	if (m_bMove)
	{
		// キーボードの取得
		CInputKeyboard * pKey = CManager::GetKeyboard();

		if (pKey->GetKeyPress(DIK_W)
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// 前進
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
		}
		else if (pKey->GetKeyPress(DIK_S)
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// 後退
			m_Move.z += MOVE_DIST;
			m_bMove = false;
		}
		else if (pKey->GetKeyPress(DIK_A)
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// 左
			m_Move.x += MOVE_DIST;
			m_bMove = false;
		}
		else if (pKey->GetKeyPress(DIK_D) 
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_RIGHT))
		{// 右
			m_Move.x -= MOVE_DIST;
			m_bMove = false;
		}
	}
	else
	{
		// 座標の取得
		D3DXVECTOR3 pos = GetPos();

		//移動計算
		pos += (m_Move - pos) / (float)(MOVE_FRAME - m_MoveCoutn);
		
		//位置設定
		SetPos(pos);

		//カウントアップ
		m_MoveCoutn++;

		//カウントが一定に達する
		if (m_MoveCoutn>=MOVE_FRAME)
		{
			//カウント初期化
			m_MoveCoutn = 0;
			//移動できるように
			m_bMove = true;
		}
	}
}

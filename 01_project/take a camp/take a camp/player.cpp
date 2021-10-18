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
#include "bullet.h"

//*****************************
// マクロ定義
//*****************************
#define MOVE_DIST (TILE_ONE_SIDE)	// 移動距離
#define MOVE_FRAME 8				// 移動速度
#define COLLISION_RADIUS 20.0f
#define MODEL_SIZE D3DXVECTOR3( 1.0f, 1.0f, 1.0f)
#define ROTDEST_PREVIOUS 270.0f		// 前方向き
#define ROTDEST_AFTER 90.0f			// 後方向き
#define ROTDEST_LEFT 180.0f			// 左向き
#define ROTDEST_RIGHT 0.0f			// 右向き
#define ROT_SPEED 0.3f				// 回転速度
#define ROT_FACING_01 180			// 回転の基準
#define ROT_FACING_02 360			// 回転向き

//*****************************
// 静的メンバ変数宣言
//*****************************
int CPlayer::m_anControllKey[5][CPlayer::KEY_MAX] =
{
	{ DIK_W,DIK_S,DIK_A,DIK_D,DIK_E },
	{ DIK_UP,DIK_DOWN,DIK_LEFT,DIK_RIGHT,DIK_NUMPAD1 },
	{ DIK_U,DIK_J,DIK_H,DIK_K,DIK_I },
	{ DIK_NUMPAD8,DIK_NUMPAD5,DIK_NUMPAD4,DIK_NUMPAD6,DIK_NUMPAD9 }
};

//******************************
// コンストラクタ
//******************************
CPlayer::CPlayer() :CModel(OBJTYPE_PLAYER)
{
	m_nPlayerNumber = 0;
	m_bMove = false;
	m_pCollison = NULL;
	m_nColor = 0;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	m_MoveCoutn = 0;

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
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber)
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
	pPlayer->SetRot(rot);
	pPlayer->SetPriority(OBJTYPE_PLAYER); // オブジェクトタイプ
	pPlayer->m_Move = pos;

	//移動範囲クラスの生成
	pPlayer->m_pActRange = CActRange::Create(pPlayer);

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

	m_nColor = m_nPlayerNumber;

	// モデルのサイズの設定
	SetSize(MODEL_SIZE);

	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);

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
	// 当たり判定の位置
	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS/2);
	}
	else
	{
		m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
	}

	// 弾の処理
	Bullet();

	// 向きの取得
	D3DXVECTOR3 rot = GetRot();

	while (m_rotDest.y - rot.y > D3DXToRadian(ROT_FACING_01))
	{
		m_rotDest.y -= D3DXToRadian(ROT_FACING_02);
	}

	while (m_rotDest.y - rot.y < D3DXToRadian(-ROT_FACING_01))
	{
		m_rotDest.y += D3DXToRadian(ROT_FACING_02);
	}

	// 目標の向きに変える
	rot += (m_rotDest - rot)*ROT_SPEED;

	// 向き設定
	SetRot(rot);

	// 
#ifdef _DEBUG
	// キーボードの取得
	if (m_nPlayerNumber == 0)
	{
		CInputKeyboard * pKey = CManager::GetKeyboard();

		/*if (pKey->GetKeyPress(DIK_NUMPAD1))
		{
			m_nColor = 0;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD2))
		{
			m_nColor = 1;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD3))
		{
			m_nColor = 2;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD4))
		{
			m_nColor = 3;
		}
		}*/
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

		if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_PROGRESS])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// 前進
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, -1);

			m_rotDest.y= D3DXToRadian(ROTDEST_PREVIOUS);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RECESSION])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// 後退
			m_Move.z += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, 1);

			m_rotDest.y = D3DXToRadian(ROTDEST_AFTER);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_LEFT])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// 左
			m_Move.x += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(-1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_LEFT);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RIGHT])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_RIGHT))
		{// 右
			m_Move.x -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_RIGHT);
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
		if (m_MoveCoutn >= MOVE_FRAME)
		{
			//カウント初期化
			m_MoveCoutn = 0;
			//移動できるように
			m_bMove = true;
		}
	}
}

//******************************
// 弾の処理
//******************************
void CPlayer::Bullet(void)
{
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CPlayer *pPlayer;

	// 座標の取得
	D3DXVECTOR3 pos = GetPos();

	// スペースボタンを押したら
	if (pKey->GetKeyTrigger(m_anControllKey[m_nPlayerNumber][KEY_BULLET]))
	{
		CBullet::Create(D3DXVECTOR3(pos.x, pos.y, pos.z));
	}

	//位置設定
	SetPos(pos);
}
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

//*****************************
// マクロ定義
//*****************************
#define MOVE_SPEED 3 

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
}

//******************************
// デストラクタ
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// クリエイト(球)
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
		// 座標の取得
		D3DXVECTOR3 pos = GetPos();

		// キーボードの取得
		CInputKeyboard * pKey = CManager::GetKeyboard();

		if (pKey->GetKeyPress(DIK_W))
		{// 前進
			pos.z -= MOVE_SPEED;
		}
		if (pKey->GetKeyPress(DIK_S))
		{// 後退
			pos.z += MOVE_SPEED;
		}
		if (pKey->GetKeyPress(DIK_A))
		{// 左
			pos.x += MOVE_SPEED;
		}
		if (pKey->GetKeyPress(DIK_D))
		{// 右
			pos.x -= MOVE_SPEED;
		}

		SetPos(pos);
	}
}

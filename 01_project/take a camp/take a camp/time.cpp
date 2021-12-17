//===================================================
//
//    timeクラスの処理[time.cpp]
//    Author:西潟 栞那汰
//
//====================================================

//**********************************
//インクルード
//**********************************
#include "manager.h"
#include "fade.h"
#include "time.h"
#include "number.h"
#include "game_finish.h"
#include "player.h"

//==================================
// コンストラクタ
//==================================
CTime::CTime() :CScene(OBJTYPE_UI_2)
{
	//制限時間のクリア
	m_nTime = TIME_UP;
	m_nA = 0;
	m_bTime = true;
}

//==================================
// デストラクタ
//==================================
CTime::~CTime()
{
}

//==================================
// クリエイト
//==================================
CTime * CTime::Create(void)
{
	//メモリの確保
	CTime *pTime = new CTime;

	// 初期化処理
	pTime->Init();

	// オブジェクトタイプの設定
	pTime->SetPriority(OBJTYPE_UI_2);

	return pTime;
}

//==================================
// 初期化処理
//==================================
HRESULT CTime::Init(void)
{
	// 最大桁数分ループ
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit] = CNumber::Create(0,
			D3DXVECTOR3((float)(1000 + nCntDigit * 40), 50.0f, 0.0f),
			D3DXVECTOR3(20, 20, 0),
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
	return S_OK;
}

//==================================
// 終了処理
//==================================
void CTime::Uninit(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		if (m_apNumber[nCntDigit] != NULL)
		{
			m_apNumber[nCntDigit]->Uninit();
			delete m_apNumber[nCntDigit];
			m_apNumber[nCntDigit] = NULL;
		}
	}

	// 開放処理
	Release();
}

//==================================
// 更新処理
//==================================
void CTime::Update(void)
{
	if (m_bTime == true)
	{
		m_nA++;
		if (m_nA % 60 <= 0)
		{
			m_nTime--;
		}
	}

	//数字表示
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit]->Update();

		m_apNumber[nCntDigit]->SetNumber((int)((m_nTime % (int)(powf(10.0f, (MAX_TIME_DIGIT - nCntDigit)))) / (float)(powf(10, (MAX_TIME_DIGIT - nCntDigit - 1)))));
	}
	// 0になったら
	if (m_nTime <= 0)
	{
		// カウントを止める
		m_nA = 0;
		m_nTime = 0;

		// プレイヤーの動きを止める
		FinishPlayer();

		// FINISHの生成
		CGameFinish::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, FINISH_POS_Y, 0.0f), D3DXVECTOR3(FINISH_SIZE_X, FINISH_SIZE_Y, 0.0f));
	}
}

//==================================
// 描画処理
//==================================
void CTime::Draw(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit]->Draw();
	}
}

//=============================================================================
// プレイヤーを止める
//=============================================================================
void CTime::FinishPlayer(void)
{
	CPlayer*pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		pPlayer->SetUpdateFlag(false);

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

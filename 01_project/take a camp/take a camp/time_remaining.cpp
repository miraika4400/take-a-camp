//=============================================================================
//
// 残りタイムの処理 [time_remaining.cpp]
// Author : 佐藤颯紀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "time_remaining.h"
#include "scene.h"
#include "number.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define REMAINING_TIME 60 

//=============================================================================
// コンストラクタ
//=============================================================================
CTime_Remaining::CTime_Remaining() :CScene(OBJTYPE_UI_2)
{
	m_nTime = REMAINING_TIME;	// 残り時間
}

//=============================================================================
// デストラクタ
//=============================================================================
CTime_Remaining::~CTime_Remaining()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CTime_Remaining * CTime_Remaining::Create(void)
{
	CTime_Remaining *pRemaining = NULL;

	// メモリの確保
	pRemaining = new CTime_Remaining;

	// NULLチェック
	if (pRemaining != NULL)
	{
		// 初期化
		pRemaining->Init();

		// オブジェクトタイプ
		pRemaining->SetPriority(OBJTYPE_UI_2);
	}

	return pRemaining;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTime_Remaining::Init(void)
{
	// 桁分回す
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// ナンバー生成処理
		m_apNumber[nCntDigit] = CNumber::Create(0,
			D3DXVECTOR3((float)(SCREEN_WIDTH / 2 + nCntDigit * 75), 100.0f, 0.0f),
			D3DXVECTOR3(75, 75, 0),
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTime_Remaining::Uninit(void)
{
	// 桁分回す
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// NULLチェック
		if (m_apNumber[nCntDigit] != NULL)
		{
			// 終了処理
			m_apNumber[nCntDigit]->Uninit();
			delete m_apNumber[nCntDigit];
			m_apNumber[nCntDigit] = NULL;
		}
	}

	// 開放処理
	Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTime_Remaining::Update(void)
{
	// 回数分回す
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// 更新処理
		m_apNumber[nCntDigit]->Update();

		// ナンバーの配置
		m_apNumber[nCntDigit]->SetNumber((int)((m_nTime % (int)(powf(10.0f, (MAX_DIGIT - nCntDigit)))) / (float)(powf(10, (MAX_DIGIT - nCntDigit - 1)))));
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CTime_Remaining::Draw(void)
{
	// 回数分回す
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// 描画処理
		m_apNumber[nCntDigit]->Draw();
	}
}
//===================================================
//
// 塗りスコア表示処理 [score_paint.cpp]
//    Author : 吉田 悠人
//
//====================================================

//**********************************
//インクルード
//**********************************
#include "number.h"
#include "chara_select.h"
#include "score_paint.h"
#include "color_tile.h"

//**********************************
//インクルード
//**********************************
#define SCORE_SIZE		(D3DXVECTOR3(40.0f, 30.0f, 0.0f))
#define CREATE_POS_Y	(400.0f)
#define SCORE_SPACE		(SCREEN_WIDTH/4)

//==================================
// コンストラクタ
//==================================
CScorePaint::CScorePaint()
{
	//初期化
	memset(m_apNumber, 0, sizeof(m_apNumber));		// ナンバーのクリア
	memset(m_pos, 0, sizeof(m_pos));// 位置
	for (int nPlayer = 0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		m_col[nPlayer] = D3DXCOLOR(0.8f, 0.3f, 0.8f, 1.0f);	// カラー
	}
	m_nPlayerNum = 0;
}

//==================================
// デストラクタ
//==================================
CScorePaint::~CScorePaint()
{
}

//==================================
// クリエイト
//==================================
CScorePaint * CScorePaint::Create(void)
{
	// メモリの確保
	CScorePaint *pScorePaint = NULL;
	pScorePaint = new CScorePaint;

	//NULLチェック
	if (pScorePaint != NULL)
	{
		// 初期化処理
		pScorePaint->Init();
		// オブジェクトタイプの設定
		pScorePaint->SetPriority(OBJTYPE_UI);
	}
	return pScorePaint;
}

//==================================
// 初期化処理
//==================================
HRESULT CScorePaint::Init(void)
{
	// プレイヤー人数取得
	m_nPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// X軸生成用変数
	float fPosX = (SCREEN_WIDTH / 2) - (((float)(m_nPlayerNum - 1) * SCORE_SPACE) / 2) + ((SCORE_SIZE.x / 2)*(MAX_PAINT_SCORE_DIGIT - 1));

	// 最大桁数分ループ
	for (int nPlayer = 0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		//プレイ人数分生成
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			for (int nCntDigit = 0; nCntDigit < MAX_PAINT_SCORE_DIGIT; nCntDigit++)
			{
				m_apNumber[nPlayer][nCntDigit] = CNumber::Create(0,
					D3DXVECTOR3((float)(fPosX - nCntDigit * (SCORE_SIZE.x)), CREATE_POS_Y, 0.0f),
					SCORE_SIZE,
					m_col[nPlayer]);
			}
			fPosX += SCORE_SPACE;
		}
	}

	// 最大桁数分ループ
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			SetPaintScore(nPlayer, CColorTile::GetTileNum(nPlayer));
		}
	}

	return S_OK;
}

//==================================
// 終了処理
//==================================
void CScorePaint::Uninit(void)
{
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		for (int nCntDigit = 0; nCntDigit < MAX_PAINT_SCORE_DIGIT; nCntDigit++)
		{
			if (m_apNumber[nPlayer][nCntDigit] != NULL)
			{
				m_apNumber[nPlayer][nCntDigit]->Uninit();
				delete m_apNumber[nPlayer][nCntDigit];
				m_apNumber[nPlayer][nCntDigit] = NULL;
			}
		}
	}

	// 開放処理
	Release();
}

//==================================
// 更新処理
//==================================
void CScorePaint::Update(void)
{
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		for (int nCntDigit = 0; nCntDigit < MAX_PAINT_SCORE_DIGIT; nCntDigit++)
		{
			//NULLチェック
			if (m_apNumber[nPlayer][nCntDigit] != NULL)
			{
				m_apNumber[nPlayer][nCntDigit]->Update();

			}
		}
	}
}

//==================================
// 描画処理
//==================================
void CScorePaint::Draw(void)
{
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		for (int nCntDigit = 0; nCntDigit < MAX_PAINT_SCORE_DIGIT; nCntDigit++)
		{
			//NULLチェック
			if (m_apNumber[nPlayer][nCntDigit] != NULL)
			{
				m_apNumber[nPlayer][nCntDigit]->Draw();
			}
		}
	}
}

//=============================
// スコア計算処理
//=============================
void CScorePaint::SetPaintScore(int nPlayer, int nScore)
{
	int nInteger = 0;//計算用変数

	for (int nCntDigit = 0; nCntDigit < MAX_PAINT_SCORE_DIGIT; nCntDigit++)
	{
		nInteger = int(nScore / pow(10, nCntDigit + 1)); //1の位以下を切り捨てる
		nInteger = int(nInteger * pow(10, nCntDigit + 1));
		m_apNumber[nPlayer][nCntDigit]->SetNumber(int((nScore - nInteger) / pow(10, nCntDigit)));
	}
}

//===================================================
//
// 塗りスコア表示処理 [score_paint.cpp]
//    Author : 吉田 悠人
//
//====================================================

//**********************************
//インクルード
//**********************************
#include "total_score.h"
#include "chara_select.h"
#include "score.h"
#include "color_tile.h"
#include "kill_count.h"
#include "scene2d.h"

//**********************************
//インクルード
//**********************************
#define PAINT_POS_Y		(400.0f)
#define KILL_POS_Y		(500.0f)
#define SCORE_SPACE		(SCREEN_WIDTH/4)
#define TOTAL_BG_SIZE	(D3DXVECTOR3(150.0f,300.0f,0.0f))

//==================================
// コンストラクタ
//==================================
CTotalScore::CTotalScore()
{
	m_pBg = NULL;
}

//==================================
// デストラクタ
//==================================
CTotalScore::~CTotalScore()
{
}

//==================================
// クリエイト
//==================================
CTotalScore * CTotalScore::Create(void)
{
	// メモリの確保
	CTotalScore *pTotalScore = NULL;
	pTotalScore = new CTotalScore;

	//NULLチェック
	if (pTotalScore != NULL)
	{
		// 初期化処理
		pTotalScore->Init();
		// オブジェクトタイプの設定
		pTotalScore->SetPriority(OBJTYPE_UI);
	}
	return pTotalScore;
}

//==================================
// 初期化処理
//==================================
HRESULT CTotalScore::Init(void)
{
	// プレイヤー人数取得
	int nPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// X軸生成用変数
	float fPosX = (SCREEN_WIDTH / 2) - (((float)(nPlayerNum - 1) * SCORE_SPACE) / 2);

	// 最大桁数分ループ
	for (int nPlayer = 0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		//プレイ人数分生成
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			//それぞれ生成
			//背景
			m_pBg = CScene2d::Create();
			m_pBg->SetPos(D3DXVECTOR3(fPosX, SCREEN_HEIGHT / 2, 0.0f));
			m_pBg->SetSize(TOTAL_BG_SIZE);
			m_pBg->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f));
			m_pBg->SetPriority(OBJTYPE_BG);

			//塗りスコア
			CScore::Create(D3DXVECTOR3(fPosX, PAINT_POS_Y, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CColorTile::GetTileNum(nPlayer));
			//キルスコア
			CScore::Create(D3DXVECTOR3(fPosX, KILL_POS_Y, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CKillCount::GetTotalKill(nPlayer));

			fPosX += SCORE_SPACE;
		}
	}


	return S_OK;
}

//==================================
// 終了処理
//==================================
void CTotalScore::Uninit(void)
{

	// 開放処理
	Release();
}

//==================================
// 更新処理
//==================================
void CTotalScore::Update(void)
{
}

//==================================
// 描画処理
//==================================
void CTotalScore::Draw(void)
{
}

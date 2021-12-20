//===================================================
//
//    ゲージクラスの処理[gage.cpp]
//    Author:増澤 未来
//
//====================================================

//**********************************
// インクルード
//**********************************
#include "result_graph.h"
#include "gauge.h"
#include "scene2d.h"
#include "color_tile.h"
#include "color_manager.h"
#include "chara_select.h"
#include "keyboard.h"
#include "manager.h"
#include "effect_result_explosion.h"
#include "character_polygon.h"

//**********************************
// マクロ定義
//**********************************
#define GAUGE_WIDTH  (180.0f)   // ゲージの幅
#define GAUGE_HEIGHT (575.0f)  // ゲージの高さ*最大値
#define GAUGE_SPACE  (275.0f)  // 各ゲージの間隔
#define BG_SIZE		(D3DXVECTOR3(SCREEN_WIDTH-15,SCREEN_HEIGHT-20,0.0f)) // 背景サイズ
#define BG_COLOR	(D3DXCOLOR(0.4f,0.4f,0.4f,0.6f))                     // 背景色
#define BACK_GAUGE_SIZE (40)                                             // バックゲージサイズ
#define BACK_GAUGE_COLOR (D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))                // バックゲージカラー
#define GAUGE_POS_Y (710.0f)                                             // ゲージ座標Y
#define MIN_POINT 1.0f                                                   // 0点でもゲージを出すため最低値の加算
#define START_RATE 0.001f                                                // スタート時のゲージ係数
#define ANNOUNCEMENT_RATE 0.1f                                           // 順位発表時のゲージ係数
#define RANK_ANNOUNCEMENT_COUNT 100                                      // 順位発表カウント
#define EXPLOSION_POS_1 D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f)
#define EXPLOSION_POS_2 D3DXVECTOR3(0.0f,SCREEN_HEIGHT,0.0f)
#define BG_COLOR_RATE 0.05f
#define CHARACTER_POLYGON_SIZE (DEFAULT_CHARACTER_POLYGON_SIZE*0.6f)
#define CHARACTER_HEIGHT_DIST ((SCREEN_HEIGHT - CHARACTER_POLYGON_SIZE.y / 2.0f)-20.0f/2.0f)
#define CHARACTER_HEIGHT_ADD 15.0f

//**********************************
// 静的メンバ変数宣言
//**********************************

//==================================
// コンストラクタ
//==================================
CResultGraph::CResultGraph() :CScene(OBJTYPE_UI_2)
{
	// 変数のクリア
	m_pBg = NULL;                // 背景ポリゴン
	ZeroMemory(&m_aGauge,sizeof(m_aGauge));  // ゲージクラス
    m_fMaxNum = 0.0f;
	m_nActionRank = 0;
	m_nActionCnt = 0;
	m_bgCol = BG_COLOR;
	m_bgColDist = BG_COLOR;
}

//==================================
// デストラクタ
//==================================
CResultGraph::~CResultGraph()
{
}

//==================================
// クリエイト
//==================================
CResultGraph * CResultGraph::Create(void)
{
	// メモリの確保
	CResultGraph *pGraph;
	pGraph = new CResultGraph;
	pGraph->Init();

	return pGraph;
}

//==================================
// 初期化処理
//==================================
HRESULT CResultGraph::Init(void)
{
	// 背景カラー
	m_bgCol = BG_COLOR;
	m_bgColDist = BG_COLOR;

	// グラフ背景の生成
	m_pBg = CScene2d::Create();
	m_pBg->SetSize(BG_SIZE);
	m_pBg->SetColor(m_bgCol);
	m_pBg->SetPriority(OBJTYPE_BG);

    m_fMaxNum = 0.0f; // 前回のゲーム中一番高いスコア

	for (int nCntColor = 0; nCntColor < GET_COLORMANAGER->GetColorNum(); nCntColor++)
	{
		// プレイヤー番号の取得
		int nPlayerNum = GET_COLORMANAGER->GetUsePlayerNum(nCntColor);
		if (nPlayerNum == -1) continue;

		for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
		{
			// [プレイヤー番号]が使っているカラー番号の保管
			m_aGauge[nPlayerNum][nCntGauge].m_nColorNum = nCntColor;
		}

		int nTileNum = CColorTile::GetTileNum(nPlayerNum) + (int)MIN_POINT;
		Rank rank = { nPlayerNum ,nTileNum };
		m_aRankData.push_back(rank);
		// 最大数の保管
		if (m_fMaxNum < nTileNum)
		{
			m_fMaxNum = (float)nTileNum;
		}
	}

	// プレイヤー数の取得
	int nEntryPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// 生成位置X軸の調整
	float posX = (SCREEN_WIDTH/2.0f) - ((float)(nEntryPlayerNum - 1) * GAUGE_SPACE) / 2.0f;

	float fCreateCharaHeight = -200.0f;
	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		if (!CCharaSelect::GetEntryData(nCntPlayer).bEntry) continue;

		for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
		{
			// ゲージで使う値の設定
			float fWight = GAUGE_WIDTH;
			float fHeight = GAUGE_HEIGHT;
			D3DXCOLOR col = GET_COLORMANAGER->GetIconColor(m_aGauge[nCntPlayer][nCntGauge].m_nColorNum);
			if (nCntGauge == 0)
			{
				fWight = GAUGE_WIDTH + BACK_GAUGE_SIZE;
				fHeight = GAUGE_HEIGHT + BACK_GAUGE_SIZE / 2.0f;
				col = BACK_GAUGE_COLOR;
			}

			// ゲージの生成
			m_aGauge[nCntPlayer][nCntGauge].pGauge = CGauge::Create(D3DXVECTOR3(posX, GAUGE_POS_Y, 0.0f), fWight, fHeight, m_fMaxNum, col);

			// 目標値の設定
			m_aGauge[nCntPlayer][nCntGauge].pGauge->SetValueDist(CColorTile::GetTileNum(m_aGauge[nCntPlayer][nCntGauge].m_nColorNum) + MIN_POINT);

		}

		CCharacterPolygon * pCharaPolygon = CCharacterPolygon::Create(D3DXVECTOR3(posX, fCreateCharaHeight, 0.0f));
		fCreateCharaHeight -= 200.0f;
		pCharaPolygon->SetSize(CHARACTER_POLYGON_SIZE);
		pCharaPolygon->SetCharaType(CCharaSelect::GetEntryData(nCntPlayer).charaType);
		pCharaPolygon->SetRimColor(GET_COLORMANAGER->GetStepColor(CCharaSelect::GetEntryData(nCntPlayer).nColorNum, 1));
		pCharaPolygon->SetTexColor(GET_COLORMANAGER->GetIconColor(CCharaSelect::GetEntryData(nCntPlayer).nColorNum));
		
		m_apCharaPolygon.push_back(pCharaPolygon);

		// ゲージの設定
		m_aGauge[nCntPlayer][GAUGE_BACK].pGauge->SetMode(CGauge::MODE_HEIGHT_SELF);
		m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetMode(CGauge::MODE_HEIGHT_AUTO);
		m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetHeightDist(GAUGE_HEIGHT / 2.0f);
		m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetRate(START_RATE);
		posX += GAUGE_SPACE;
	}
	// ランクソート処理
	std::sort(m_aRankData.begin(), m_aRankData.end(), [](Rank const& lhs, Rank const& rhs) {return (lhs.nPaintNum > rhs.nPaintNum); });

	// アクション順位の初期化
	m_nActionRank = m_aRankData.size() - 1;
	// アクションカウントの初期化
	m_nActionCnt = 0;
	
	return S_OK;
}

//==================================
// 終了処理
//==================================
void CResultGraph::Uninit(void)
{

	// 開放処理
	Release();
}

//==================================
// 更新処理
//==================================
void CResultGraph::Update(void)
{
	// グラフ
	ManageGraph();

	// 背景色の管理
	ManageBackGroundColor();

	for (int nCnt = 0; nCnt < (int)m_apCharaPolygon.size(); nCnt++)
	{
		D3DXVECTOR3 pos = m_apCharaPolygon[nCnt]->GetPos();
		if (pos.y < CHARACTER_HEIGHT_DIST)
		{
			pos.y += CHARACTER_HEIGHT_ADD;
			if (pos.y > CHARACTER_HEIGHT_DIST)
			{
				pos.y = CHARACTER_HEIGHT_DIST;
			}
			m_apCharaPolygon[nCnt]->SetPos(pos);
		}
	}
}

//==================================
// 描画処理
//==================================
void CResultGraph::Draw(void)
{

}

//==================================
// グラフ管理
//==================================
void CResultGraph::ManageGraph(void)
{
	m_nActionCnt++;

	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		if (m_nActionRank >= 0)
		{
			if (m_nActionCnt >= RANK_ANNOUNCEMENT_COUNT && m_aRankData[m_nActionRank].nPlayerNum == nCntPlayer)
			{
				m_nActionCnt = 0;
				m_nActionRank--;
				m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetMode(CGauge::MODE_VALUE_AUTO);
				m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetRate(ANNOUNCEMENT_RATE);

				D3DXCOLOR iconCol = GET_COLORMANAGER->GetIconColor(m_aGauge[nCntPlayer][GAUGE_FRONT].m_nColorNum);
				CResultExplosion::Create(EXPLOSION_POS_1, iconCol);
				CResultExplosion::Create(EXPLOSION_POS_2, iconCol);

				// 背景色の変更
				m_bgColDist = GET_COLORMANAGER->GetStepColor(m_aGauge[nCntPlayer][GAUGE_FRONT].m_nColorNum,0);
			}
		}

		// NULLチェック
		if (m_aGauge[nCntPlayer][GAUGE_BACK].pGauge == NULL || m_aGauge[nCntPlayer][1].pGauge == NULL) continue;

		// バックゲージの値の設定
		m_aGauge[nCntPlayer][GAUGE_BACK].pGauge->SetHeight(m_aGauge[nCntPlayer][1].pGauge->GetHeight() + (BACK_GAUGE_SIZE / 2.0f));
	}
}

//==================================
// 背景色の管理
//==================================
void CResultGraph::ManageBackGroundColor(void)
{
	m_bgCol.r += (m_bgColDist.r - m_bgCol.r)*BG_COLOR_RATE;
	m_bgCol.g += (m_bgColDist.g - m_bgCol.g)*BG_COLOR_RATE;
	m_bgCol.b += (m_bgColDist.b - m_bgCol.b)*BG_COLOR_RATE;

	//m_pBg->SetColor(m_bgCol);
}

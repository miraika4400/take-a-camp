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

//**********************************
// マクロ定義
//**********************************
#define GAUGE_WIDTH  50.0f   // ゲージの幅
#define GAUGE_HEIGHT 500.0f  // ゲージの高さ*最大値
#define GAUGE_SPACE  150.0f  // 各ゲージの間隔
#define BG_SIZE    D3DXVECTOR3(SCREEN_WIDTH/2-15,SCREEN_HEIGHT/2-20,0.0f)
#define BG_COLOR D3DXCOLOR(0.0f,0.0f,0.0f,0.6f)
#define GAUGE_RATE 0.03f

//**********************************
// 静的メンバ変数宣言
//**********************************

//==================================
// コンストラクタ
//==================================
CResultGraph::CResultGraph() :CScene(OBJTYPE_UI)
{
	// 変数のクリア
	m_pBg = NULL;                // 背景ポリゴン
	ZeroMemory(&m_aGauge,sizeof(m_aGauge));  // ゲージクラス
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
	// グラフ背景の生成
	m_pBg = CScene2d::Create();
	m_pBg->SetSize(BG_SIZE);
	m_pBg->SetColor(BG_COLOR);
	m_pBg->SetPriority(OBJTYPE_BG);

	float fMaxNum = 0.0f; // 前回のゲーム中一番高いスコア

	for (int nCntColor = 0; nCntColor < GET_COLORMANAGER->GetColorNum(); nCntColor++)
	{
		int nPlayerNum = GET_COLORMANAGER->GetUsePlayerNum(nCntColor);
		if (nPlayerNum != -1)
		{
			// [プレイヤー番号]が使っているカラー番号の保管
			m_aGauge[nPlayerNum].m_nColorNum = nCntColor;

			// 最大数の保管
			if (fMaxNum < CColorTile::GetTileNum(nPlayerNum))
			{
				fMaxNum = (float)CColorTile::GetTileNum(nPlayerNum);
			}
		}
	}
	// プレイヤーの生成
	// 生成位置X軸の調整
	float posX = (SCREEN_WIDTH/2) - ((float)(MAX_PLAYER - 1) * GAUGE_SPACE) / 2;

	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		m_aGauge[nCntPlayer].pGauge = CGauge::Create(&m_aGauge[nCntPlayer].fGraphData, D3DXVECTOR3(posX, 700.0f, 0.0f), GAUGE_WIDTH, GAUGE_HEIGHT, fMaxNum, GET_COLORMANAGER->GetIconColor(m_aGauge[nCntPlayer].m_nColorNum));
		m_aGauge[nCntPlayer].fGraphData = 0;
		posX += GAUGE_SPACE;
	}

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
	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		m_aGauge[nCntPlayer].fGraphData += ((CColorTile::GetTileNum(m_aGauge[nCntPlayer].m_nColorNum)) - m_aGauge[nCntPlayer].fGraphData)*GAUGE_RATE;
	}
}

//==================================
// 描画処理
//==================================
void CResultGraph::Draw(void)
{

}
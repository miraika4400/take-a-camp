////////////////////////////////////////////////////
//
//    ステージ選択ポリゴンクラスの処理[stage_select_polygon.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//=============================
// インクルード
//=============================
#include "stage_select_polygon.h"
#include "scene2d.h"
#include "dynamic_texture.h"

//=============================
// マクロ定義
//=============================
#define POS  (D3DXVECTOR3( SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f, 0.0f))  // Y座標
#define SIZE  (D3DXVECTOR3( SCREEN_WIDTH,SCREEN_HEIGHT, 0.0f)) // サイズ
#define SIZE_MIN_RATE 0.5f

//=============================
// 静的メンバ変数宣言
//=============================
const std::vector<int> CStageSelectPolygon::m_anDrawObjNum =
{
	CScene::OBJTYPE_BG,
	CScene::OBJTYPE_TILE,
	CScene::OBJTYPE_COLOR_TILE,
	CScene::OBJTYPE_MAP,
};

//=============================
// コンストラクタ
//=============================
CStageSelectPolygon::CStageSelectPolygon()
{
	// 変数のクリア
	ZeroMemory(&m_apPolygon, sizeof(m_apPolygon));
	m_pDynamicTex = NULL;
}

//=============================
// デストラクタ
//=============================
CStageSelectPolygon::~CStageSelectPolygon()
{
}

//=============================
// クリエイト
//=============================
CStageSelectPolygon * CStageSelectPolygon::Create(void)
{
	// メモリの確保
	CStageSelectPolygon *pPointa = new CStageSelectPolygon;
	// 初期化
	pPointa->Init();

	return pPointa;
}

//=============================
// 初期化処理
//=============================
HRESULT CStageSelectPolygon::Init(void)
{
	D3DXVECTOR3 size = SIZE;
	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		// ポリゴン生成
		m_apPolygon[nCntUi] = CScene2d::Create();
		m_apPolygon[nCntUi]->SetPos(POS);
		m_apPolygon[nCntUi]->SetSize(size);
		m_apPolygon[nCntUi]->OutList();

		size *= SIZE_MIN_RATE;
	}

	SetPriority(OBJTYPE_UI);

	m_pDynamicTex = CDynamicTexture::Create(D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	return S_OK;
}

//=============================
// 終了処理
//=============================
void CStageSelectPolygon::Uninit(void)
{
	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		if (m_apPolygon[nCntUi] != NULL)
		{
			m_apPolygon[nCntUi]->Uninit();
			delete m_apPolygon[nCntUi];
			m_apPolygon[nCntUi] = NULL;
		}
	}

	// テクスチャクラスの破棄
	if (m_pDynamicTex != NULL)
	{
		m_pDynamicTex->Uninit();
		delete m_pDynamicTex;
		m_pDynamicTex = NULL;
	}

	// 開放処理
	Release();
}

//=============================
// 更新処理
//=============================
void CStageSelectPolygon::Update(void)
{
}

//=============================
// 描画処理
//=============================
void CStageSelectPolygon::Draw(void)
{
	if (m_pDynamicTex == NULL) return;

	
	// テクスチャにオブジェクトを書き込む
	m_pDynamicTex->Begin();
	for (int nCntObj = 0; nCntObj < (int)m_anDrawObjNum.size(); nCntObj++)
	{
		CScene*pScene = GetTop(m_anDrawObjNum[nCntObj]);
		while (pScene != NULL)
		{
			// 描画
			pScene->Draw();

			// ネクスト
			pScene = pScene->GetNext();
		}
	}
	// レンダーターゲットを戻す
	m_pDynamicTex->End();

	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		if (m_apPolygon[nCntUi] != NULL)
		{
			m_apPolygon[nCntUi]->BindTexture(m_pDynamicTex->GetTexture());
			m_apPolygon[nCntUi]->Draw();
		}
	}
}
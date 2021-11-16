////////////////////////////////////////////////////
//
//    塗時間クラスの処理[paint_time.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "paint_time.h"
#include "scene3d.h"
#include "tile.h"
#include "resource_texture.h"

//******************************
// マクロ定義
//******************************
#define COLOR D3DXCOLOR(0.8f,0.8f,0.8f,m_fAlpha)
#define ALPHA_RATE 0.1f

//******************************
// コンストラクタ
//******************************
CPaintTime::CPaintTime():CScene(OBJTYPE_EFFECT)
{
	m_bDraw = false;
	m_nCntFrame = 0;
	m_nFrame = 0;
	m_fAlpha = 0.0f;
}

//******************************
// デストラクタ
//******************************
CPaintTime::~CPaintTime()
{
}

//******************************
// クラス生成
//******************************
CPaintTime * CPaintTime::Create(void)
{
	// クラス生成
	CPaintTime * pInstace = new CPaintTime;

	// 初期化処理
	pInstace->Init();

	return pInstace;
}

//******************************
// 初期化処理
//******************************
HRESULT CPaintTime::Init(void)
{
	// 初期化
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		m_apPolygon[nCntPolygon] = CScene3d::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(TILE_ONE_SIDE-5.0f, 0.0, TILE_ONE_SIDE - 5.0f));
		m_apPolygon[nCntPolygon]->SetColor(COLOR);
		m_apPolygon[nCntPolygon]->ReConnection();
	}

	// テクスチャの割り当て
	m_apPolygon[PARTS_FRAME]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CLOCK_FRAME));
	m_apPolygon[PARTS_HANDS]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CLOCK_HANDS));

	// カウントの初期化
	m_nCntFrame = 0;
	m_nFrame = 0;
	m_bDraw = false;
	m_fAlpha = 0.0f;

	return S_OK;
}

//******************************
// 終了処理
//******************************
void CPaintTime::Uninit(void)
{
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->Uninit();
			delete m_apPolygon[nCntPolygon];
			m_apPolygon[nCntPolygon] = NULL;
		}
	}

	Release();
}

//******************************
// 更新処理
//******************************
void CPaintTime::Update(void)
{
	if (m_bDraw)
	{
		m_nCntFrame++;
		// 針を回す
		float fRotY = D3DXToRadian(((float)m_nCntFrame / (float)m_nFrame)*360.0f);
		m_apPolygon[PARTS_HANDS]->SetRot(D3DXVECTOR3(0.0f, fRotY, 0.0f));

		if (m_nCntFrame > m_nFrame)
		{
			m_bDraw = false;
		}
	}
	else
	{
		m_fAlpha += (0.0f - m_fAlpha)*ALPHA_RATE;
	}

	// カラーの設定
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		m_apPolygon[nCntPolygon]->SetColor(COLOR);
	}
}

//******************************
// 描画処理
//******************************
void CPaintTime::Draw(void)
{
	// 描画
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->Draw();
		}
	}
}

//******************************
// 座標のセット
//******************************
void CPaintTime::SetPos(D3DXVECTOR3 pos)
{
	// 描画
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->SetPos(pos);
		}
	}
}

//******************************
// セット
//******************************
void CPaintTime::SetPaintTime(int nFrame)
{
	m_bDraw = true;
	m_apPolygon[PARTS_HANDS]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_nCntFrame = 0;
	m_nFrame = nFrame;
	m_fAlpha = 1.0f;
}

//******************************
// 描画フラグのセット
//******************************
void CPaintTime::SetDrawFlag(bool bFlag)
{
	m_bDraw = bFlag;

	if (!m_bDraw)
	{
		m_fAlpha = 0.0f;
	}
}

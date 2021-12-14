//=============================================================================
//
// テキストヘッダ [text.h]
// Author : 伊藤陽梧
//
//=============================================================================

//=============================
// インクルード
//=============================
#include "text.h"
#include "manager.h"
#include "renderer.h"
#include <map>

//=============================
// マクロ定義
//=============================
#define FONT_PATH ("data/fonts/meiryo.ttc")

//=============================
// コンストラクタ
//=============================
CText::CText()
{
	m_pFont = nullptr;
	ZeroMemory(&m_pos, sizeof(m_pos));
	m_fHeight = 0.0f;
	m_fWidth = 0.0f;
	ZeroMemory(&m_col, sizeof(m_col));
	m_format = NULL;
	ZeroMemory(&m_fontName, sizeof(m_fontName));
	ZeroMemory(&m_str, sizeof(m_str));
	nCountBite = 0;
	nShowTime = 0;
}

//=============================
// デストラクタ
//=============================
CText::~CText()
{
}

//=============================
// クリエイト
//=============================
CText * CText::Create(const D3DXVECTOR3 pos, const float fHeight, const float fWidth, const char* pStr, const FORMAT format, const D3DCOLOR col)
{
	// メモリの確保
	CText *pText = new CText;

	pText->m_pos = pos;
	pText->m_fHeight = fHeight;
	pText->m_fWidth = fWidth;
	wsprintf(pText->m_str, pStr);
	pText->m_format = format;
	pText->m_col = col;

	// 初期化
	pText->Init();
	return pText;
}

//=============================
// 初期化処理
//=============================
HRESULT CText::Init(void)
{
	//フォント生成
	D3DXCreateFont(CManager::GetRenderer()->GetDevice(),
		m_fHeight,
		m_fWidth,
		0,
		0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		FONT_PATH,
		&m_pFont);

	return S_OK;
}

//=============================
// 終了処理
//=============================
void CText::Uninit(void)
{
	if (m_pFont != NULL)
	{
		m_pFont->Release();
		m_pFont = NULL;
	}

	// 開放処理
	Release();
}

//=============================
// 更新処理
//=============================
void CText::Update(void)
{
	
}

//=============================
// 描画処理
//=============================
void CText::Draw(void)
{
	char disp[512];

	strncpy(disp, m_str, nCountBite);
	disp[nCountBite] = '\0';

	RECT rect;
	SetRect(&rect, -200, -80, 220, 500);

	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_pFont->DrawText(NULL, disp, -1, &rect, DT_LEFT | DT_WORDBREAK, m_col);

	if (nCountBite < 500)
	{
		if (nShowTime % 1 == 0)
		{
			nCountBite += 2;
		}
		nShowTime++;
	}

}
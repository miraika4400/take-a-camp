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
	ZeroMemory(&m_WindowRange, sizeof(m_WindowRange));
	m_nCountBite = 0;
	m_nShowTime = 0;
	m_bAllShow = false;
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
CText * CText::Create(const D3DXVECTOR2 pos, const float fHeight, const float fWidth, const FORMAT format, const D3DCOLOR col)
{
	// メモリの確保
	CText *pText = new CText;

	pText->m_pos = pos;
	pText->m_fHeight = fHeight;
	pText->m_fWidth = fWidth;
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
		(INT)m_fHeight,
		(UINT)m_fWidth,
		0,
		0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
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
	// 表示する文字数を制限する
	std::string Getstr = m_str.substr(0, m_nCountBite + 1);

	// 無駄に通したくないのでサイズ分だけにする
	if (m_nCountBite < (signed)m_str.size())
	{
		// 文字を何フレームで表示するか
		if (m_nShowTime % 1 == 0)
		{
			// 1バイト文字と2バイト文字の判別
			if (IsDBCSLeadByte(Getstr[m_nCountBite]) == 0)
			{
				m_nCountBite++;
			}
			else
			{
				m_nCountBite += 2;
			}
			m_nShowTime = 0;
		}

		// 文字表示フレームを加算
		m_nShowTime++;
		m_bAllShow = false;
	}
	else
	{
		// 全部表示されたらフラグ建て
		m_bAllShow = true;
	}

	// 調整中
	RECT rect;
	SetRect(&rect, -200, -80, 220, 500);

	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_pFont->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, m_col);
}

//=============================
// 文字追加処理
//=============================
void CText::AddText(std::string str_text)
{
	m_str += str_text;
}

//=============================
// テキスト削除する処理
//=============================
void CText::ClearText(void)
{
	m_nCountBite = 0;
	m_nShowTime = 0;
	m_str.erase(m_str.begin(), m_str.end());
	m_str.shrink_to_fit();
}

//=============================
// テキスト削除する処理
//=============================
void CText::SetWindowRange(D3DXVECTOR2 WindowRange[])
{
	memcpy(m_WindowRange, WindowRange, sizeof(WindowRange));
	//m_WindowRange = WindowRange;
}

//=============================
// テキスト削除する処理
//=============================
void CText::SetFontSize(D3DXVECTOR2 FontSize)
{
	m_fHeight = FontSize.x;
	m_fWidth = FontSize.y;
}

//=============================
// テキスト削除する処理
//=============================
void CText::SetColor(D3DXCOLOR color)
{
	m_col = color;
}

//=============================
// テキスト削除する処理
//=============================
void CText::SetPos(D3DXVECTOR2 pos)
{
	m_pos = pos;
}
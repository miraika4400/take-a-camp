//=============================================================================
//
// �e�L�X�g�w�b�_ [text.h]
// Author : �ɓ��z��
//
//=============================================================================

//=============================
// �C���N���[�h
//=============================
#include "text.h"
#include "manager.h"
#include "renderer.h"

//=============================
// �}�N����`
//=============================
#define FONT_PATH ("data/fonts/meiryo.ttc")

//=============================
// �R���X�g���N�^
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
// �f�X�g���N�^
//=============================
CText::~CText()
{
}

//=============================
// �N���G�C�g
//=============================
CText * CText::Create(const D3DXVECTOR3 pos, const float fHeight, const float fWidth, const char* pStr, const FORMAT format, const D3DCOLOR col)
{
	// �������̊m��
	CText *pText = new CText;

	pText->m_pos = pos;
	pText->m_fHeight = fHeight;
	pText->m_fWidth = fWidth;
	wsprintf(pText->m_str, pStr);
	pText->m_format = format;
	pText->m_col = col;

	// ������
	pText->Init();
	return pText;
}

//=============================
// ����������
//=============================
HRESULT CText::Init(void)
{
	//�t�H���g����
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
// �I������
//=============================
void CText::Uninit(void)
{
	if (m_pFont != NULL)
	{
		m_pFont->Release();
		m_pFont = NULL;
	}

	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CText::Update(void)
{
	
}

//=============================
// �`�揈��
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
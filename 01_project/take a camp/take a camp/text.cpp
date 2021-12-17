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
#include <map>

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
	ZeroMemory(&m_WindowRange, sizeof(m_WindowRange));
	m_nCountBite = 0;
	m_nShowTime = 0;
	m_bAllShow = false;
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
CText * CText::Create(const D3DXVECTOR2 pos, const float fHeight, const float fWidth, const FORMAT format, const D3DCOLOR col)
{
	// �������̊m��
	CText *pText = new CText;

	pText->m_pos = pos;
	pText->m_fHeight = fHeight;
	pText->m_fWidth = fWidth;
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
	// �\�����镶�����𐧌�����
	std::string Getstr = m_str.substr(0, m_nCountBite + 1);

	// ���ʂɒʂ������Ȃ��̂ŃT�C�Y�������ɂ���
	if (m_nCountBite < (signed)m_str.size())
	{
		// ���������t���[���ŕ\�����邩
		if (m_nShowTime % 1 == 0)
		{
			// 1�o�C�g������2�o�C�g�����̔���
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

		// �����\���t���[�������Z
		m_nShowTime++;
		m_bAllShow = false;
	}
	else
	{
		// �S���\�����ꂽ��t���O����
		m_bAllShow = true;
	}

	// ������
	RECT rect;
	SetRect(&rect, -200, -80, 220, 500);

	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_pFont->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, m_col);
}

//=============================
// �����ǉ�����
//=============================
void CText::AddText(std::string str_text)
{
	m_str += str_text;
}

//=============================
// �e�L�X�g�폜���鏈��
//=============================
void CText::ClearText(void)
{
	m_nCountBite = 0;
	m_nShowTime = 0;
	m_str.erase(m_str.begin(), m_str.end());
	m_str.shrink_to_fit();
}

//=============================
// �e�L�X�g�폜���鏈��
//=============================
void CText::SetWindowRange(D3DXVECTOR2 WindowRange[])
{
	memcpy(m_WindowRange, WindowRange, sizeof(WindowRange));
	//m_WindowRange = WindowRange;
}

//=============================
// �e�L�X�g�폜���鏈��
//=============================
void CText::SetFontSize(D3DXVECTOR2 FontSize)
{
	m_fHeight = FontSize.x;
	m_fWidth = FontSize.y;
}

//=============================
// �e�L�X�g�폜���鏈��
//=============================
void CText::SetColor(D3DXCOLOR color)
{
	m_col = color;
}

//=============================
// �e�L�X�g�폜���鏈��
//=============================
void CText::SetPos(D3DXVECTOR2 pos)
{
	m_pos = pos;
}
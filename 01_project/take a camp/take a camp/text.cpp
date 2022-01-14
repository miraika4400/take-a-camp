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
#define SHIFT_POS (2)

//=============================
// �R���X�g���N�^
//=============================
CText::CText()
{
	ZeroMemory(&m_apFont, sizeof(m_apFont));
	ZeroMemory(&m_pos, sizeof(m_pos));
	ZeroMemory(&m_Fontsize, sizeof(m_Fontsize));
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
CText * CText::Create(const D3DXVECTOR2 pos, const D3DXVECTOR2 fontsize, const FORMAT format, const D3DCOLOR col)
{
	// �������̊m��
	CText *pText = new CText;

	pText->m_pos = pos;
	pText->m_Fontsize = fontsize;
	pText->m_format = format;
	pText->m_col = col;
	pText->SetPriority(OBJTYPE_UI_2);

	// ������
	pText->Init();
	return pText;
}

//=============================
// ����������
//=============================
HRESULT CText::Init(void)
{
	for (int nFont = 0; nFont < MAX_FONT_NUM; nFont++)
	{
		//�t�H���g����
		D3DXCreateFont(CManager::GetRenderer()->GetDevice(),
			(INT)(m_Fontsize.x),
			(UINT)(m_Fontsize.y),
			0,
			0,
			FALSE,
			SHIFTJIS_CHARSET,
			OUT_DEFAULT_PRECIS,
			PROOF_QUALITY,
			DEFAULT_PITCH,
			FONT_PATH,
			&m_apFont[nFont]);
	}

	return S_OK;
}

//=============================
// �I������
//=============================
void CText::Uninit(void)
{
	for (int nFont = 0; nFont < MAX_FONT_NUM; nFont++)
	{
		if (m_apFont[nFont] != NULL)
		{
			m_apFont[nFont]->Release();
			m_apFont[nFont] = NULL;
		}
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
	SetRect(&rect, (int)m_WindowRange[0].x, (int)m_WindowRange[0].y - SHIFT_POS, (int)m_WindowRange[1].x, (int)m_WindowRange[1].y - SHIFT_POS);
	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_apFont[0]->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	SetRect(&rect, (int)m_WindowRange[0].x, (int)m_WindowRange[0].y + SHIFT_POS, (int)m_WindowRange[1].x, (int)m_WindowRange[1].y + SHIFT_POS);
	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_apFont[1]->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	SetRect(&rect, (int)m_WindowRange[0].x - SHIFT_POS, (int)m_WindowRange[0].y, (int)m_WindowRange[1].x - SHIFT_POS, (int)m_WindowRange[1].y);
	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_apFont[2]->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	SetRect(&rect, (int)m_WindowRange[0].x + SHIFT_POS, (int)m_WindowRange[0].y, (int)m_WindowRange[1].x + SHIFT_POS, (int)m_WindowRange[1].y);
	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_apFont[3]->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	SetRect(&rect, (int)m_WindowRange[0].x, (int)m_WindowRange[0].y, (int)m_WindowRange[1].x, (int)m_WindowRange[1].y);
	OffsetRect(&rect, (int)m_pos.x, (int)m_pos.y);
	m_apFont[4]->DrawText(NULL, m_str.substr(0, m_nCountBite).c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK, m_col);
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

//===============================
// �e�L�X�g��\������͈͂̐ݒ�
//===============================
void CText::SetWindowRange(D3DXVECTOR2 WindowRange[2])
{
	m_WindowRange[0] = WindowRange[0];
	m_WindowRange[1] = WindowRange[1];
}

//=============================
// �����̃T�C�Y�̐ݒ�
//=============================
void CText::SetFontSize(D3DXVECTOR2 FontSize)
{
	m_Fontsize = FontSize;

	// �r���ŃT�C�Y�ς����Ȃ���������������N���G�C�g����
	Init();
}

//=============================
// �F�̐ݒ�
//=============================
void CText::SetColor(D3DXCOLOR color)
{
	m_col = color;
}

//=============================
// ���W�̐ݒ�
//=============================
void CText::SetPos(D3DXVECTOR2 pos)
{
	m_pos = pos;
}
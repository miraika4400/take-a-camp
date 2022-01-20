//====================================================
//
// tutorial�̏���[tutorial.cpp]
// Author:�ɓ��z��
//
//====================================================

//=============================
// �C���N���[�h
//=============================
#include "titleback_ui.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "keyboard.h"
#include "joypad.h"
#include "resource_texture.h"
#include "fade.h"

//=============================
// �}�N����`
//=============================
#define TEXTURE_SIZE (D3DXVECTOR3(805.0f / 2.0f, 66.0f / 2.0f, 0.0f))	// �^�C�g���߂�p�̃e�N�X�`���̃T�C�Y
#define TEXTURE_POS (D3DXVECTOR3(SCREEN_WIDTH - (TEXTURE_SIZE.x / 2.0f), SCREEN_HEIGHT - (TEXTURE_SIZE.y / 2.0f), 0.0f))	// �^�C�g���߂�p�̃e�N�X�`���̍��W
#define ALPHACHANGE_FLOAT (0.005f)	// ���l��ς���l

//=============================
// �R���X�g���N�^
//=============================
CTitlebackui::CTitlebackui()
{
	m_pTitlebackTex = nullptr;
	m_fAlpha = 0.0f;
	m_bAlphaChange = false;
}

//=============================
// �f�X�g���N�^
//=============================
CTitlebackui::~CTitlebackui()
{
}

//=============================
// �N���G�C�g
//=============================
CTitlebackui * CTitlebackui::Create()
{
	// �������̊m��
	CTitlebackui *pTitlebackui = new CTitlebackui;

	// ������
	pTitlebackui->Init();

	// �ꎞ�I�Ƀv���C�I���e�B�[��UI�ɂ���
	pTitlebackui->SetPriority(OBJTYPE_UI_2);
	return pTitlebackui;
}

//=============================
// ����������
//=============================
HRESULT CTitlebackui::Init()
{
	m_pTitlebackTex = CPolygon::Create(TEXTURE_POS, TEXTURE_SIZE, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pTitlebackTex->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TITLEBACK));
	return S_OK;
}

//=============================
// �I������
//=============================
void CTitlebackui::Uninit()
{
}

//=============================
// �X�V����
//=============================
void CTitlebackui::Update()
{
	if (m_pTitlebackTex)
	{
		// ���l��ς���
		m_pTitlebackTex->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_fAlpha));
	}

	// �����ɂ���ă��l��ς���
	if (!m_bAlphaChange)
	{
		m_fAlpha += ALPHACHANGE_FLOAT;
	}
	else
	{
		m_fAlpha -= ALPHACHANGE_FLOAT;
	}

	if (m_fAlpha >= 1.0f)
	{
		m_bAlphaChange = true;
	}
	else if (m_fAlpha <= 0.0f)
	{
		m_bAlphaChange = false;
	}

	// �W���C�p�b�h�̎擾
	CInputJoypad* pJoypad = CManager::GetJoypad();

	for (int nCount = 0; nCount < XUSER_MAX_COUNT; nCount++)
	{
		if (pJoypad->GetButtonState(XINPUT_GAMEPAD_BACK, CInputJoypad::BUTTON_TRIGGER, nCount))
		{
			CManager::GetFade()->SetFade(CManager::MODE_TITLE);
		}
	}
}

//=============================
// �`�揈��
//=============================
void CTitlebackui::Draw()
{
	if (m_pTitlebackTex)
	{
		m_pTitlebackTex->Draw();
	}
}
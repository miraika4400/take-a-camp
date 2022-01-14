//=============================================================================
//
// �^�C�g���̃{�^���̏��� [button_title.cpp]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "button_title.h"
#include "keyboard.h"
#include "joypad.h"
#include "manager.h"
#include "fade.h"
#include "resource_texture.h"
#include "sound.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define BUTTON_SIZE D3DXVECTOR3(350.0f,100.0f,0.0f)	// �T�C�Y
#define BUTTON_COLOR D3DXCOLOR(1.0f,1.0f,1.0f,1.0f)		// �J���[
#define NOT_BUTTON_COLOR D3DXCOLOR(1.0f,1.0f,1.0f,0.5f)	// �I������ĂȂ��Ƃ��̃J���[

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CButton_Title::CButton_Title()
{
	m_nButton = 0;
	m_type = BUTTON_NONE;
	m_color = BUTTON_COLOR;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CButton_Title::~CButton_Title()
{

}

//=============================================================================
// ��������
//=============================================================================
CButton_Title * CButton_Title::Create(D3DXVECTOR3 pos, BUTTON_TYPE type)
{
	// �������̊m��
	CButton_Title *pButton_Title;
	pButton_Title = new CButton_Title;

	// ������
	pButton_Title->Init();

	// �e�l�̑��
	pButton_Title->SetPos(pos);
	pButton_Title->SetPriority(OBJTYPE_UI_2);
	pButton_Title->m_type = type;

	// �^�C�v���X�^�[�g�������ꍇ
	if (pButton_Title->m_type == BUTTON_START)
	{
		pButton_Title->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_BUTTON_START));
	}
	// �^�C�v���`���[�g���A���������ꍇ
	if (pButton_Title->m_type == BUTTON_TUTORIAL)
	{
		pButton_Title->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTYRE_BUTTON_TUTORIAL));
	}

	return pButton_Title;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CButton_Title::Init(void)
{
	// ����������
	CButton::Init();

	// �T�C�Y�ݒ�
	SetSize(BUTTON_SIZE);

	// �J���[�ݒ�
	SetColor(BUTTON_COLOR);

	// �����{�^��
	m_nButton = BUTTON_START;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CButton_Title::Uninit(void)
{
	// �I������
	CButton::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CButton_Title::Update(void)
{
	// �X�V����
	CButton::Update();

	// �I������
	Select();
	// �F�̏���
	Collar();
}

//=============================================================================
// �I������
//=============================================================================
void CButton_Title::Select(void)
{
	// �L�[�{�[�h�ƃW���C�p�b�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CInputJoypad * pJoypad = CManager::GetJoypad();
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// ��L�[���������Ƃ�
	if (pKey->GetKeyTrigger(DIK_UP))
	{
		// ���݂̃{�^�������Z����
		m_nButton--;
	}

	// ���L�[���������Ƃ�
	if (pKey->GetKeyTrigger(DIK_DOWN))
	{
		// ���݂̃{�^�������Z����
		m_nButton++;
	}

	for (int nControllNum = 0; nControllNum < XUSER_MAX_COUNT; nControllNum++)
	{
		// �X�e�B�b�N�̍��W
		D3DXVECTOR2 StickPos = pJoypad->GetStickState(pJoypad->PAD_LEFT_STICK, nControllNum);

		// ��L�[���������Ƃ�
		if (pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_UP, CInputJoypad::BUTTON_TRIGGER, nControllNum))
		{
			// ���݂̃{�^�������Z����
			m_nButton--;
		}

		// ���L�[���������Ƃ�
		if (pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_DOWN, CInputJoypad::BUTTON_TRIGGER, nControllNum))
		{
			// ���݂̃{�^�������Z����
			m_nButton++;
		}

		// �O��艺�ɂ�������
		if (m_nButton <= -1)
		{
			m_nButton = BUTTON_TUTORIAL;
		}

		// �ő�l����ɂ������珉���l�ɖ߂�
		if (m_nButton >= BUTTON_MAX)
		{
			m_nButton = 0;
		}

		// �G���^�[���������Ƃ�
		if (pKey->GetKeyTrigger(DIK_RETURN)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_A, CInputJoypad::BUTTON_TRIGGER, nControllNum))
		{
			// �{�^���̎�ނ��X�^�[�g�������ꍇ
			if (m_nButton == BUTTON_START)
			{
				// �Q�[����ʂɑJ��
				CManager::GetFade()->SetFade(CManager::MODE_CHARA_SELECT);
				CManager::SetDecMode(CManager::MODE_GAME);
			}
			// �{�^���̎�ނ��`���[�g���A���������ꍇ
			if (m_nButton == BUTTON_TUTORIAL)
			{
				// �`���[�g���A����ʂɑJ��
				CManager::GetFade()->SetFade(CManager::MODE_CHARA_SELECT);
				CManager::SetDecMode(CManager::MODE_TUTORIAL);
			}

			// SE�Đ�
			pSound->Play(CSound::LABEL_SE_BUTTON);

		}
	}
}

//=============================================================================
// �F�̏���
//=============================================================================
void CButton_Title::Collar(void)
{
	// �{�^�����I������Ă�����
	if (m_type == m_nButton)
	{
		// �F�ݒ�
		SetColor(BUTTON_COLOR);
	}

	// �{�^�����I������Ă��Ȃ�������
	if (m_type != m_nButton)
	{
		// �F�ݒ�
		SetColor(NOT_BUTTON_COLOR);
	}
}
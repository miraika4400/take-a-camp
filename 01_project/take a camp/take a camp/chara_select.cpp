////////////////////////////////////////////////////
//
//    �L�����I���N���X�̏���[chara_select.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "chara_select.h"
#include "joypad.h"
#include "manager.h"
#include "chara_select_ui.h"
#include "keyboard.h"
#include "manager.h"
#include "fade.h"

//=============================
// �}�N����`
//=============================

//=============================
// �ÓI�����o�ϐ��錾
//=============================
CCharaSelect::Entry_Data CCharaSelect::m_aEntryData[MAX_PLAYER] = {};
int CCharaSelect::m_nEntryPlayerNum = 0;

//=============================
// �R���X�g���N�^
//=============================
CCharaSelect::CCharaSelect()
{
	// �ϐ��̃N���A
	ZeroMemory(&m_abUseControll, sizeof(m_abUseControll));
}

//=============================
// �f�X�g���N�^
//=============================
CCharaSelect::~CCharaSelect()
{
}

//=============================
// �N���G�C�g
//=============================
CCharaSelect * CCharaSelect::Create(void)
{
	// �������̊m��
	CCharaSelect *pGame = new CCharaSelect;
	// ������
	pGame->Init();

	return pGame;
}

//=============================
// ����������
//=============================
HRESULT CCharaSelect::Init(void)
{
	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		m_aEntryData[nCntData].bController = false;
		m_aEntryData[nCntData].bEntry= false;
		m_aEntryData[nCntData].nColorNum = nCntData; // ��
		m_aEntryData[nCntData].nControllNum = -1;
		m_aEntryData[nCntData].charaType = CPlayer::CHARA_TYPE_FIGHTER;
		m_abUseControll[nCntData] = false;
	}

	CCharaSelectUi::Create();
	return S_OK;
}

//=============================
// �I������
//=============================
void CCharaSelect::Uninit(void)
{
	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CCharaSelect::Update(void)
{

	// �G���g���[����
	EntryPlayer();

#ifdef _DEBUG

	if(CManager::GetKeyboard()->GetKeyTrigger(DIK_F1))
	{
		CManager::GetFade()->SetFade(CManager::MODE_GAME);
	}

	CountEntryPlayerNum();
#endif // _DEBUG


}

//=============================
// �`�揈��
//=============================
void CCharaSelect::Draw(void)
{
}

//=============================
// �v���C���[�̃G���g���[����
//=============================
void CCharaSelect::EntryPlayer(void)
{
	CInputJoypad * pJoy = CManager::GetJoypad();

	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{

		if (m_aEntryData[nCntData].bEntry)
		{
			// �G���g���[��������
			if (pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, m_aEntryData[nCntData].nControllNum))
			{
				// �G���g���[��Ԃɂ���
				m_aEntryData[nCntData].bEntry = false;
				// �R���g���[���[�t���O
				m_aEntryData[nCntData].bController = false;
				// �R���g���[���[���g�p��Ԃ�
				m_abUseControll[m_aEntryData[nCntData].nControllNum] = false;
				// �R���g���[���[�ԍ��̃Z�b�g
				m_aEntryData[nCntData].nControllNum = -1;
				break;
			}
		}

		for (int nCntJoy = 0; nCntJoy < MAX_PLAYER; nCntJoy++)
		{
			// �G���g���[����
			if (!m_aEntryData[nCntData].bEntry && !m_abUseControll[nCntJoy])
			{// �G���g���[��Ԃ���Ȃ��Ƃ�
				if (pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, nCntJoy))
				{
					// �G���g���[��Ԃɂ���
					m_aEntryData[nCntData].bEntry = true;
					// �R���g���[���[�t���O
					m_aEntryData[nCntData].bController = true;
					// �R���g���[���[�ԍ��̃Z�b�g
					m_aEntryData[nCntData].nControllNum = nCntJoy;
					// �R���g���[���[���g�p��Ԃ�
					m_abUseControll[nCntJoy] = true;
					break;
				}
			}
		}
	}
}

//=============================
// �G���g���[�l���̃J�E���g
//=============================
void CCharaSelect::CountEntryPlayerNum(void)
{
	m_nEntryPlayerNum = 0;
	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		if (m_aEntryData[nCntData].bEntry)
		{// �G���g���[�t���O��true�̎��ɃJ�E���g����
			m_nEntryPlayerNum++;
		}
	}
}

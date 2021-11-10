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
	ZeroMemory(&m_abUseJoy, sizeof(m_abUseJoy));
	ZeroMemory(&m_abUseKey, sizeof(m_abUseKey));
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
		m_abUseJoy[nCntData] = false;
		m_abUseKey[nCntData] = false;
	}

	ResetEntryPlayer();

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

	if(CManager::GetKeyboard()->GetKeyTrigger(DIK_F1)|| CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
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
// �L�����N�^�[���̃��Z�b�g
//=============================
void CCharaSelect::ResetEntryPlayer(void)
{
	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		m_aEntryData[nCntData].bController = false;
		m_aEntryData[nCntData].bEntry = false;
		m_aEntryData[nCntData].nColorNum = nCntData; // ��
		m_aEntryData[nCntData].nControllNum = -1;
		m_aEntryData[nCntData].charaType = CPlayer::CHARA_TYPE_FIGHTER;
	}

	m_nEntryPlayerNum = 0;
}

//=============================
// �v���C���[�̃G���g���[����
//=============================
void CCharaSelect::EntryPlayer(void)
{
	// �G���g���[
	auto EntryPlayer = [this](int nCntData, int nCntJoy, bool bController)
	{
		// �G���g���[��Ԃɂ���
		m_aEntryData[nCntData].bEntry = true;
		// �R���g���[���[�t���O
		m_aEntryData[nCntData].bController = bController;
		// �R���g���[���[�ԍ��̃Z�b�g
		m_aEntryData[nCntData].nControllNum = nCntJoy;
		// �R���g���[���[���g�p��Ԃ�
		if (bController) m_abUseJoy[nCntJoy] = true;
		else m_abUseKey[nCntJoy] = true;
	};

	// �G���g���[��������
	auto EntryCancelPlayer = [this](int nCntData)
	{
		// �G���g���[��Ԃɂ���
		m_aEntryData[nCntData].bEntry = false;
		// �R���g���[���[�E�L�[�{�[�h���g�p��Ԃ�
		if (m_aEntryData[nCntData].bController) m_abUseJoy[m_aEntryData[nCntData].nControllNum] = false;
		else m_abUseKey[m_aEntryData[nCntData].nControllNum] = false;

		// �R���g���[���[�t���O
		m_aEntryData[nCntData].bController = false;
		// �R���g���[���[�ԍ��̃Z�b�g
		m_aEntryData[nCntData].nControllNum = -1;
	};

	CInputJoypad * pJoy = CManager::GetJoypad();
	CInputKeyboard *pKey = CManager::GetKeyboard();

	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		if (m_aEntryData[nCntData].bEntry)
		{
			// �G���g���[��������
			if (   m_aEntryData[nCntData].bController && pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, m_aEntryData[nCntData].nControllNum)
				||!m_aEntryData[nCntData].bController && pKey->GetKeyTrigger(CPlayer::GetPlayerControllKey(m_aEntryData[nCntData].nControllNum, CPlayer::KEY_PROGRESS)))
			{
				EntryCancelPlayer(nCntData);
				break;
			}
		}

		for (int nCntJoy = 0; nCntJoy < MAX_PLAYER; nCntJoy++)
		{
			// �G���g���[����
			if (!m_aEntryData[nCntData].bEntry)
			{// �G���g���[��Ԃ���Ȃ��Ƃ�
				if (!m_abUseJoy[nCntJoy] && pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, nCntJoy))
				{// �R���g���[���[�ŃG���g���[
					EntryPlayer(nCntData, nCntJoy, true);
					break;
				}

				// �G���g���[�L�[�̎擾*�O�i�L�[
				int nEntryKey = CPlayer::GetPlayerControllKey(nCntJoy, CPlayer::KEY_PROGRESS);
				if (!m_abUseKey[nCntJoy] && pKey->GetKeyTrigger(CPlayer::GetPlayerControllKey(nCntJoy, CPlayer::KEY_PROGRESS)))
				{// �L�[�{�[�h�ŃG���g���[
					EntryPlayer(nCntData, nCntJoy, false);
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

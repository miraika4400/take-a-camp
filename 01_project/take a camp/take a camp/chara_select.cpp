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
#include "player.h"
#include "camera_charaselect.h"
#include "bg.h"

//=============================
// �}�N����`
//=============================
#define WAIT_TIME 10

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
	ZeroMemory(&m_anWaitCnt, sizeof(m_anWaitCnt));
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

	// �G���g���[���̃��Z�b�g
	ResetEntryPlayer();
	// UI�̐���
	CCharaSelectUi::Create();
	// �J��������
	CManager::SetCamera(CCharaSelectCamera::Create());
	// �w�i�̐���
	CBg::Create();
	return S_OK;
}

//=============================
// �I������
//=============================
void CCharaSelect::Uninit(void)
{
	// �J�����N���X�̉������
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
		pCamera = NULL;
	}

	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CCharaSelect::Update(void)
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}
	// �G���g���[����
	EntryPlayer();

#ifdef _DEBUG

	if(CManager::GetKeyboard()->GetKeyTrigger(DIK_F1)|| CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
	{
		switch (CManager::GetDecMode())
		{
		case CManager::MODE_TUTORIAL:
			CManager::GetFade()->SetFade(CManager::MODE_TUTORIAL);
			break;

		case CManager::MODE_GAME:
			CManager::GetFade()->SetFade(CManager::MODE_STAGE_SELECT);
			break;

		default:
			break;
		}
	}

	CountEntryPlayerNum();
#endif // _DEBUG

}

//=============================
// �`�揈��
//=============================
void CCharaSelect::Draw(void)
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}
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
		m_aEntryData[nCntData].charaType = CResourceCharacter::CHARACTER_KNIGHT;
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
		// �L�����^�C�v
		m_aEntryData[nCntData].charaType = CResourceCharacter::CHARACTER_KNIGHT;
		// �R���g���[���[���g�p��Ԃ�
		if (bController) m_abUseJoy[nCntJoy] = true;
		// �L�[�{�[�h���g�p��Ԃ�
		else m_abUseKey[nCntJoy] = true;
		// �J�E���g�̏�����
		m_anWaitCnt[nCntData] = 0;
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
				// �G���g���[�̃L�����Z��
				EntryCancelPlayer(nCntData);
				break;
			}
			if (m_anWaitCnt[nCntData] > 0) m_anWaitCnt[nCntData]--;
			CharacterSelect(nCntData);
		}

		for (int nCntJoy = 0; nCntJoy < MAX_PLAYER; nCntJoy++)
		{
			// �G���g���[����
			if (!m_aEntryData[nCntData].bEntry)
			{// �G���g���[��Ԃ���Ȃ��Ƃ�
				if (!m_abUseJoy[nCntJoy] && pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, nCntJoy))
				{// �R���g���[���[�ŃG���g���[
					EntryPlayer(nCntData, nCntJoy, true);
					pJoy->EnableVibration(1.0f, 1.0f, 10.0f, nCntJoy);
					break;
				}

				// �G���g���[�L�[�̎擾*�O�i�L�[
				int nEntryKey = CPlayer::GetPlayerControllKey(nCntJoy, CPlayer::KEY_PROGRESS);
				if (!m_abUseKey[nCntJoy] && pKey->GetKeyTrigger(CPlayer::GetPlayerControllKey(nCntJoy, CPlayer::KEY_PROGRESS)))
				{// �L�[�{�[�h�ŃG���g���[
					EntryPlayer(nCntData, nCntJoy, false);
					break;
				}
				m_aEntryData[nCntData].charaType = CResourceCharacter::CHARACTER_NONE;
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

//=============================
// �L�����Z���N�g
//=============================
void CCharaSelect::CharacterSelect(int nCntData)
{
	if (m_anWaitCnt[nCntData] > 0) return;

	CInputJoypad * pJoy = CManager::GetJoypad();
	CInputKeyboard *pKey = CManager::GetKeyboard();
	// �X�e�B�b�N�̍��W
	D3DXVECTOR2 StickPos = pJoy->GetStickState(pJoy->PAD_LEFT_STICK, m_aEntryData[nCntData].nControllNum);

	int nType = m_aEntryData[nCntData].charaType;
	// �L�����̑I������
	if (!m_aEntryData[nCntData].bController && pKey->GetKeyPress(CPlayer::GetPlayerControllKey(m_aEntryData[nCntData].nControllNum, CPlayer::KEY_LEFT))
		|| m_aEntryData[nCntData].bController && ((StickPos.x < 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoy->GetButtonState(XINPUT_GAMEPAD_DPAD_LEFT, pJoy->BUTTON_PRESS, m_aEntryData[nCntData].nControllNum)))
	{
		
		// �i��
		nType++;		
		if (nType >= CResourceCharacter::CHARACTER_MAX)
		{
			nType = 0;
		}
		m_aEntryData[nCntData].charaType = (CResourceCharacter::CHARACTER_TYPE)nType;
		m_anWaitCnt[nCntData] = WAIT_TIME;
		return;
	}
	if (!m_aEntryData[nCntData].bController && pKey->GetKeyPress(CPlayer::GetPlayerControllKey(m_aEntryData[nCntData].nControllNum, CPlayer::KEY_RIGHT))
		|| m_aEntryData[nCntData].bController && ((StickPos.x > 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoy->GetButtonState(XINPUT_GAMEPAD_DPAD_RIGHT, pJoy->BUTTON_PRESS, m_aEntryData[nCntData].nControllNum)))
	{
		// �߂�
		nType--;
		if (nType < 0)
		{
			nType = CResourceCharacter::CHARACTER_MAX - 1;
		}
		m_aEntryData[nCntData].charaType = (CResourceCharacter::CHARACTER_TYPE)nType;

		m_anWaitCnt[nCntData] = WAIT_TIME;
		return;
	}

	// �J�E���g�̏�����
	m_anWaitCnt[nCntData] = 0;
}

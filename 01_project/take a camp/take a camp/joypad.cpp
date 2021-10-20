//====================================================
//
// �W���C�p�b�h�N���X�̏���[joypad.cpp]
// Author:�ɓ��z��
//
//====================================================

//====================================================
// �C���N���[�h
//====================================================
#include "joypad.h"

//====================================================
// �R���X�g���N�^
//====================================================
CInputJoypad::CInputJoypad()
{
	// ������
	memset(m_aJoyState, 0, sizeof(m_aJoyState));
	memset(m_aJoyStateTrigger, 0, sizeof(m_aJoyStateTrigger));
	memset(m_aJoyStateRelease, 0, sizeof(m_aJoyStateRelease));
	
	memset(m_aJoyStateLTRT, 0, sizeof(m_aJoyStateLTRT));
	memset(m_aJoyStateTriggerLTRT, 0, sizeof(m_aJoyStateTriggerLTRT));
	memset(m_aJoyStateReleaseLTRT, 0, sizeof(m_aJoyStateReleaseLTRT));
}

//====================================================
// �f�X�g���N�^
//====================================================
CInputJoypad::~CInputJoypad()
{
}

//====================================================
// ����������
//====================================================
HRESULT CInputJoypad::Init(HINSTANCE hInstance, HWND hWnd)
{
	return S_OK;
}

//====================================================
// �I������
//====================================================
void CInputJoypad::Uninit(void)
{
	// �I��������Ƀo�C�u���[�V�����������Ȃ��悤�ɂ���
	XInputEnable(false);

	CInput::Uninit();
}

//====================================================
// �X�V����
//====================================================
void CInputJoypad::Update(void)
{
	// �R���g���[���̏��
	XINPUT_STATE state;

	// �X�V����O�ɏ�����
	memset(m_aJoyStateTrigger, 0, sizeof(m_aJoyStateTrigger));
	memset(m_aJoyStateRelease, 0, sizeof(m_aJoyStateRelease));
	memset(m_aJoyStateTriggerLTRT, 0, sizeof(m_aJoyStateTriggerLTRT));
	memset(m_aJoyStateReleaseLTRT, 0, sizeof(m_aJoyStateReleaseLTRT));

	for (int nCountJoystick = 0; nCountJoystick < MAX_JOYSTICK_NUM; nCountJoystick++)
	{
		// �W���C�p�b�h�̏��̎擾
		if (GetPadState(state, nCountJoystick) == ERROR_SUCCESS)
		{
			// �{�^���̍X�V
			for (int nCntButton = 0; nCntButton < MAX_PAD_BUTTON; nCntButton++)
			{
				//�L�[�����[�X
				m_aJoyStateRelease[nCountJoystick][nCntButton] = (m_aJoyState[nCountJoystick][nCntButton] ^ state.Gamepad.wButtons) & ~state.Gamepad.wButtons;

				// �����Ă�Ƃ��ɃL�[�̏�������
				if (state.Gamepad.wButtons == Return_XInput((PAD_BUTTON_STATE)nCntButton))
				{
					//�L�[�g���K�[
					m_aJoyStateTrigger[nCountJoystick][nCntButton] = (m_aJoyState[nCountJoystick][nCntButton] ^ state.Gamepad.wButtons) & state.Gamepad.wButtons;

					//�L�[�v���X����ۑ�
					m_aJoyState[nCountJoystick][nCntButton] = state.Gamepad.wButtons;
				}
				else
				{
					//�L�[�v���X����ۑ�
					m_aJoyState[nCountJoystick][nCntButton] = 0;
				}
			}

			// LTRT�̍X�V
			for (int nCntTrigger = 0; nCntTrigger < MAX_PAD_TRIGGER; nCntTrigger++)
			{
				switch ((PAD_TRRIGER_STATE)nCntTrigger)
				{
				case PAD_LT: // ���g���K�[
					UpdateTriggerState(state.Gamepad.bLeftTrigger, nCntTrigger, nCountJoystick);
					break;

				case PAD_RT: // �E�g���K�[
					UpdateTriggerState(state.Gamepad.bRightTrigger, nCntTrigger, nCountJoystick);
					break;

				default:
					break;
				}
			}
		}
	}
}

//====================================================
// Xinput�̃{�^����Ԃ�����
// Pad_Button_State:�R���g���[���̃{�^��
//====================================================
WORD CInputJoypad::Return_XInput(const PAD_BUTTON_STATE Pad_Button_State)
{
	switch (Pad_Button_State)
	{
	case PAD_A:
		return XINPUT_GAMEPAD_A;
		break;

	case PAD_B:
		return XINPUT_GAMEPAD_B;
		break;

	case PAD_X:
		return XINPUT_GAMEPAD_X;
		break;

	case PAD_Y:
		return XINPUT_GAMEPAD_Y;
		break;
	case PAD_LB:
		return XINPUT_GAMEPAD_LEFT_SHOULDER;
		break;

	case PAD_RB:
		return XINPUT_GAMEPAD_RIGHT_SHOULDER;
		break;

	case PAD_BACK:
		return XINPUT_GAMEPAD_BACK;
		break;

	case PAD_START:
		return XINPUT_GAMEPAD_START;
		break;

	case PAD_UP:
		return XINPUT_GAMEPAD_DPAD_UP;
		break;

	case PAD_DOWN:
		return XINPUT_GAMEPAD_DPAD_DOWN;
		break;

	case PAD_LEFT:
		return XINPUT_GAMEPAD_DPAD_LEFT;
		break;

	case PAD_RIGHT:
		return XINPUT_GAMEPAD_DPAD_RIGHT;
		break;

	case PAD_LEFT_THUMB:
		return XINPUT_GAMEPAD_LEFT_THUMB;
		break;

	case PAD_RIGHT_THUMB:
		return XINPUT_GAMEPAD_RIGHT_THUMB;
		break;

	default:
		break;
	}
	return 0;
}

//====================================================
// �񋓌^�̃{�^����Ԃ�����
// Xinput_Gamepad:�R���g���[���̃{�^��
//====================================================
int CInputJoypad::Return_Button(const WORD Xinput_Gamepad)
{
	switch (Xinput_Gamepad)
	{
	case XINPUT_GAMEPAD_A:
		return PAD_A;
		break;

	case XINPUT_GAMEPAD_B:
		return PAD_B;
		break;

	case XINPUT_GAMEPAD_X:
		return PAD_X;
		break;

	case XINPUT_GAMEPAD_Y:
		return PAD_Y;
		break;
	case XINPUT_GAMEPAD_LEFT_SHOULDER:
		return PAD_LB;
		break;

	case XINPUT_GAMEPAD_RIGHT_SHOULDER:
		return PAD_RB;
		break;

	case XINPUT_GAMEPAD_BACK:
		return PAD_BACK;
		break;

	case XINPUT_GAMEPAD_START:
		return PAD_START;
		break;

	case XINPUT_GAMEPAD_DPAD_UP:
		return PAD_UP;
		break;

	case XINPUT_GAMEPAD_DPAD_DOWN:
		return PAD_DOWN;
		break;

	case XINPUT_GAMEPAD_DPAD_LEFT:
		return PAD_LEFT;
		break;

	case XINPUT_GAMEPAD_DPAD_RIGHT:
		return PAD_RIGHT;
		break;

	case XINPUT_GAMEPAD_LEFT_THUMB:
		return PAD_LEFT_THUMB;
		break;

	case XINPUT_GAMEPAD_RIGHT_THUMB:
		return PAD_RIGHT_THUMB;
		break;

	default:
		break;
	}
	return 0;
}

//====================================================
// �{�^���̎擾
// wButton_State:�ǂ̃{�^����
// Push_State:�������ݕ�
// nJoystickNum:�R���g���[���̔ԍ�
// �Ԃ�l:������Ă��邩�̔���
//====================================================
bool CInputJoypad::GetButtonState(const WORD wButton_State, const BUTTON_PUSH_STATE Push_State, int nJoystickNum)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(state));	// ������

	// �W���C�p�b�h�̏��̎擾
	if (GetPadState(state, nJoystickNum) == ERROR_SUCCESS)
	{
		// �������ɂ���ēn�����̂�ς���
		switch (Push_State)
		{
		case BUTTON_PRESS:
			return GetJoystickPress(wButton_State, Return_Button(wButton_State), nJoystickNum);
			break;

		case BUTTON_TRIGGER:
			return GetJoystickTrigger(wButton_State, Return_Button(wButton_State), nJoystickNum);
			break;

		case BUTTON_RELEASE:
			return GetJoystickRelease(wButton_State, Return_Button(wButton_State), nJoystickNum);
			break;
		default:
			break;
		}
	}
	return false;
}

//====================================================
// LT�ART�̉������݂̎擾
// Pad_Trigger_State:LT�ART�ǂ�����
// Push_State:�������ݕ�
// nJoystickNum:�R���g���[���̔ԍ�
// �Ԃ�l:������Ă��邩�̔���
//====================================================
bool CInputJoypad::GetTriggerState(const PAD_TRRIGER_STATE Pad_Trigger_State, const BUTTON_PUSH_STATE Push_State, int nJoystickNum)
{
	XINPUT_STATE state;

	// �g���K�[�̃f�b�h�]�[��
	int Trigger_Dedzone = XINPUT_GAMEPAD_TRIGGER_THRESHOLD;

	// �W���C�p�b�h�̏��̎擾
	if (GetPadState(state, nJoystickNum) == ERROR_SUCCESS)
	{
		// �������ɂ���ēn�����̂�ς���
		switch (Push_State)
		{
		case BUTTON_PRESS:
			return GetJoystickPressLTRT(Pad_Trigger_State, nJoystickNum);
			break;

		case BUTTON_TRIGGER:
			return GetJoystickTriggerLTRT(Pad_Trigger_State, nJoystickNum);
			break;

		case BUTTON_RELEASE:
			return GetJoystickReleaseLTRT(Pad_Trigger_State, nJoystickNum);
			break;
		default:
			break;
		}
	}
	return false;
}

//====================================================
// LT�ART�̉������݋�̎擾
// Pad_Trigger_State:LT�ART�ǂ�����
// nJoystickNum:�R���g���[���̔ԍ�
// �Ԃ�l:�g���K�[�̉������݋
//====================================================
int CInputJoypad::GetTriggerPushCondition(const PAD_TRRIGER_STATE Pad_Trigger_State, int nJoystickNum)
{
	XINPUT_STATE state;

	// �g���K�[�̃f�b�h�]�[��
	int Trigger_Dedzone = XINPUT_GAMEPAD_TRIGGER_THRESHOLD;

	// �W���C�p�b�h�̏��̎擾
	if (GetPadState(state, nJoystickNum) == ERROR_SUCCESS)
	{
		switch (Pad_Trigger_State)
		{
		case PAD_LT: // ���g���K�[
			if (state.Gamepad.bLeftTrigger > Trigger_Dedzone)
			{
				// ���͂���Ă���Ȃ�l��Ԃ�
				return state.Gamepad.bLeftTrigger;
			}
			break;

		case PAD_RT: // �E�g���K�[
			if (state.Gamepad.bRightTrigger > Trigger_Dedzone)
			{
				// ���͂���Ă���Ȃ�l��Ԃ�
				return state.Gamepad.bRightTrigger;
			}
			break;

		default:
			break;
		}
	}
	return 0;
}

//====================================================
// �X�e�B�b�N�̎擾
// Pad_Stick_State:�X�e�B�b�N�̔ԍ�
// nJoystickNum:�R���g���[���̔ԍ�
// �Ԃ�l:�X�e�B�b�N�̍��W
//====================================================
D3DXVECTOR2 CInputJoypad::GetStickState(const PAD_STICK_STATE Pad_Stick_State, int nJoystickNum)
{
	XINPUT_STATE state;

	// �E�A���X�e�B�b�N�̃f�b�h�]�[��
	int Left_Thumb_Dedzone = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
	int Right_Thumb_Dedzone = XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;

	// �W���C�p�b�h�̏��̎擾
	if (GetPadState(state, nJoystickNum) == ERROR_SUCCESS)
	{
		switch (Pad_Stick_State)
		{
		case PAD_LEFT_STICK:
			// ���X�e�B�b�N
			if (state.Gamepad.sThumbLX > Left_Thumb_Dedzone ||
				state.Gamepad.sThumbLX < -Left_Thumb_Dedzone ||
				state.Gamepad.sThumbLY > Left_Thumb_Dedzone ||
				state.Gamepad.sThumbLY < -Left_Thumb_Dedzone)
			{
				// ���͂���Ă���Ȃ�l��Ԃ�
				return D3DXVECTOR2(state.Gamepad.sThumbLX, state.Gamepad.sThumbLY);
			}
			break;

		case PAD_RIGHT_STICK:
			// �E�X�e�B�b�N
			if (state.Gamepad.sThumbRX > Right_Thumb_Dedzone ||
				state.Gamepad.sThumbRX < -Right_Thumb_Dedzone ||
				state.Gamepad.sThumbRY > Right_Thumb_Dedzone ||
				state.Gamepad.sThumbRY < -Right_Thumb_Dedzone)
			{
				// ���͂���Ă���Ȃ�l��Ԃ�
				return D3DXVECTOR2(state.Gamepad.sThumbRX, state.Gamepad.sThumbRY);
			}
			break;

		default:
			break;
		}
	}
	// ���͂���ĂȂ��Ȃ�0.0f��Ԃ�
	return D3DXVECTOR2(0.0f, 0.0f);
}


//====================================================
// �o�C�u���[�V�����̊J�n
// L_magnification:���̃o�C�u���[�V�����̔{��(0.0f�`1.0f)
// R_magnification:�E�̃o�C�u���[�V�����̔{��(0.0f�`1.0f)
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
void CInputJoypad::EnableVibration(const float L_magnification, const float R_magnification, int nJoystickNum)
{
	// �U���l���o��
	float fL_vib = 65535 * L_magnification;
	float fR_vib = 65535 * R_magnification;

	// �U���p�̍\����
	XINPUT_VIBRATION vibration;

	// ������
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	// �U���l���
	vibration.wLeftMotorSpeed = (WORD)fL_vib;
	vibration.wRightMotorSpeed = (WORD)fR_vib;

	// �U��������
	XInputSetState(nJoystickNum, &vibration);
}

//====================================================
// �o�C�u���[�V�����̏I��
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
void CInputJoypad::DisableVibration(int nJoystickNum)
{
	// �U���p�̍\����
	XINPUT_VIBRATION vibration;

	// ������
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	// �U���l���
	vibration.wLeftMotorSpeed = 0;
	vibration.wRightMotorSpeed = 0;

	// �U�����~�߂�
	XInputSetState(nJoystickNum, &vibration);
}

//====================================================
// �g���K�[�̍X�V����
// nTriggerPush:�g���K�[�̉������񂾗�
// nPadTrigger:�X�e�B�b�N�̍��W
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
void CInputJoypad::UpdateTriggerState(const int nTriggerPush, const int nPadTrigger, int nJoystickNum)
{
	if (nTriggerPush > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		//�L�[�g���K�[
		m_aJoyStateTriggerLTRT[nJoystickNum][nPadTrigger] = (m_aJoyStateLTRT[nJoystickNum][nPadTrigger] ^ true) & true;

		//�L�[�����[�X
		m_aJoyStateReleaseLTRT[nJoystickNum][nPadTrigger] = false;

		//�L�[�v���X����ۑ�
		m_aJoyStateLTRT[nJoystickNum][nPadTrigger] = true;
	}
	else
	{
		if (nTriggerPush == 0 && m_aJoyStateLTRT[nJoystickNum][nPadTrigger] == true)
		{
			//�L�[�����[�X
			m_aJoyStateReleaseLTRT[nJoystickNum][nPadTrigger] = true;
		}

		//�L�[�v���X����ۑ�
		m_aJoyStateLTRT[nJoystickNum][nPadTrigger] = false;
	}
}

//====================================================
// �v���X���̎擾
// wPad_State:�{�^���̒l
// nPad_Bottan:�R���g���[���̃{�^��
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
bool CInputJoypad::GetJoystickPress(const WORD wPad_State, const int nPad_Bottan, int nJoystickNum)
{
	return m_aJoyState[nJoystickNum][nPad_Bottan] & wPad_State ? true : false;
}

//====================================================
// �g���K�[���̎擾
// wPad_State:�{�^���̒l
// nPad_Bottan:�R���g���[���̃{�^��
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
bool CInputJoypad::GetJoystickTrigger(const WORD wPad_State, const int nPad_Bottan, int nJoystickNum)
{
	return m_aJoyStateTrigger[nJoystickNum][nPad_Bottan] & wPad_State ? true : false;
}

//====================================================
// �����[�X���̎擾
// wPad_State:�{�^���̒l
// nPad_Bottan:�R���g���[���̃{�^��
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
bool CInputJoypad::GetJoystickRelease(const WORD wPad_State, const int nPad_Bottan, int nJoystickNum)
{
	return m_aJoyStateRelease[nJoystickNum][nPad_Bottan] & wPad_State ? true : false;
}

//====================================================
// �v���X���̎擾
// nPad_Trigger:�g���K�[�̔ԍ�
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
bool CInputJoypad::GetJoystickPressLTRT(const int nPad_Trigger, const int nJoystickNum)
{
	return m_aJoyStateLTRT[nJoystickNum][nPad_Trigger];
}

//====================================================
// �g���K�[���̎擾
// nPad_Trigger:�g���K�[�̔ԍ�
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
bool CInputJoypad::GetJoystickTriggerLTRT(const int nPad_Trigger, const int nJoystickNum)
{
	return m_aJoyStateTriggerLTRT[nJoystickNum][nPad_Trigger];
}

//====================================================
// �����[�X���̎擾
// nPad_Trigger:�g���K�[�̔ԍ�
// nJoystickNum:�R���g���[���̔ԍ�
//====================================================
bool CInputJoypad::GetJoystickReleaseLTRT(const int nPad_Trigger, const int nJoystickNum)
{
	return m_aJoyStateReleaseLTRT[nJoystickNum][nPad_Trigger];
}

//====================================================
// �W���C�p�b�h�̏��̎擾
// state:�R���g���[���̏��
// nJoystickNum:�R���g���[���̔ԍ�
// �Ԃ�l:�R���g���[�����ڑ�����Ă��邩�ǂ���
//====================================================
DWORD CInputJoypad::GetPadState(XINPUT_STATE& state, int nJoystickNum)
{
	ZeroMemory(&state, sizeof(state));						// ������
	DWORD dwResult = XInputGetState(nJoystickNum, &state);	// ���擾

	return dwResult;
}

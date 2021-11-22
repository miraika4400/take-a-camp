//====================================================
//
// �W���C�p�b�h�w�b�_ [joypad.h]
// Author:�ɓ��z��
//
//====================================================

// ��d�C���N���[�h�h�~
#ifndef _JOYPAD_H_
#define _JOYPAD_H_

//====================================================
// �C���N���[�h�t�@�C��
//====================================================
#include "main.h"
#include "input.h"

//====================================================
//�}�N����`
//====================================================
#define MAX_JOYSTICK_NUM (4)			// JOYPAD�ڑ����

//�W���C�p�b�h�N���X
class CInputJoypad : public CInput
{
public:

	typedef enum
	{
		// �{�^��
		PAD_UP = 0,			// �\���L�[�̏�
		PAD_DOWN,			// �\���L�[�̉�
		PAD_LEFT,			// �\���L�[�̍�
		PAD_RIGHT,			// �\���L�[�̉E
		PAD_START,			// Start
		PAD_BACK,			// Back
		PAD_LEFT_THUMB,		// ���X�e�B�b�N�̉�������
		PAD_RIGHT_THUMB,	// �E�X�e�B�b�N�̉�������
		PAD_LB,				// LB
		PAD_RB,				// RB
		PAD_A,				// A�{�^��
		PAD_B,				// B�{�^��
		PAD_X,				// X�{�^��
		PAD_Y,				// Y�{�^��
		MAX_PAD_BUTTON		// �{�^���̍ő�l
	}PAD_BUTTON_STATE;

	typedef enum
	{
		// �g���K�[
		PAD_LT = 0,			// ���g���K�[
		PAD_RT,				// �E�g���K�[
		MAX_PAD_TRIGGER		// �g���K�[�̍ő�l
	}PAD_TRRIGER_STATE;

	typedef enum
	{
		// �X�e�B�b�N
		PAD_LEFT_STICK,		// ���X�e�B�b�N
		PAD_RIGHT_STICK,	// �E�X�e�B�b�N
	}PAD_STICK_STATE;

	typedef enum
	{
		BUTTON_PRESS = 0,
		BUTTON_TRIGGER,
		BUTTON_RELEASE
	}BUTTON_PUSH_STATE;

	//============
	// �����o�֐�
	//============
	CInputJoypad();
	~CInputJoypad();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);	// ������
	void Uninit(void);								// �I��
	void Update(void);								// �X�V

	void EnableVibration(const float L_vib, const float R_vib, const float fVibTime, const int nJoystickNum);	// �o�C�u���[�V�����̊J�n
	void DisableVibration(const int nJoystickNum);																// �o�C�u���[�V�����̏I��

	//============
	// �Q�b�^�[
	//============
	bool GetButtonState(const WORD pad_state, const BUTTON_PUSH_STATE Push_Stateint, const int nJoystickNum);				// �{�^���̉������݂̎擾
	bool GetTriggerState(const PAD_TRRIGER_STATE pad_state, const BUTTON_PUSH_STATE Push_State, const int nJoystickNum);	// LT�ART�̉������݂̎擾
	int GetTriggerPushCondition(const PAD_TRRIGER_STATE pad_state, const int nJoystickNum);									// LT�ART�̉������݋�̎擾
	D3DXVECTOR2 GetStickState(const PAD_STICK_STATE Pad_Stick_State, const int nJoystickNum);								// �X�e�B�b�N�̎擾
private:
	//============
	// �����o�֐�
	//============
	WORD Return_XInput(const PAD_BUTTON_STATE Pad_Botton_State);	// Xinput�̃{�^����Ԃ�����
	int Return_Button(const WORD Xinput_Gamepad);					// �񋓌^�̃{�^����Ԃ�����

	void UpdateButton(const XINPUT_STATE state, const int nJoystickNum);							// �{�^���̍X�V����
	void UpdateTrigger(const XINPUT_STATE state, const int nJoystickNum);							// �g���K�[�̍X�V����
	void UpdateTriggerState(const int nTriggerPush, const int nPadTrigger, const int nJoystickNum);	// �g���K�[�̏��X�V����
	void UpdateVibration(const int nJoystickNum);													// �U���̍X�V

	//============
	// �Q�b�^�[
	//============
	DWORD GetPadState(XINPUT_STATE& state, const int nJoystickNum);									// �W���C�p�b�h�̏��̎擾
	bool GetJoystickPress(const WORD wPad_State, const int nPad_Bottan, const int nJoystickNum);	// �{�^���̃v���X���̎擾
	bool GetJoystickTrigger(const WORD wPad_State, const int nPad_Bottan, const int nJoystickNum);	// �{�^���̃g���K�[���̎擾
	bool GetJoystickRelease(const WORD wPad_State, const int nPad_Bottan, const int nJoystickNum);	// �{�^���̃����[�X���̎擾
	bool GetJoystickPressLTRT(const int nPad_Trigger, const int nJoystickNum);						// LTRT�̃v���X���̎擾
	bool GetJoystickTriggerLTRT(const int nPad_Trigger, const int nJoystickNum);					// LTRT�̃g���K�[���̎擾
	bool GetJoystickReleaseLTRT(const int nPad_Trigger, const int nJoystickNum);					// LTRT�̃����[�X���̎擾

	//============
	// �����o�ϐ�
	//============
	WORD m_aJoyState[MAX_JOYSTICK_NUM][MAX_PAD_BUTTON];			// �W���C�p�b�h�̓��͏�񃏁[�N
	WORD m_aJoyStateTrigger[MAX_JOYSTICK_NUM][MAX_PAD_BUTTON];	// �W���C�p�b�h�̃g���K�[���
	WORD m_aJoyStateRelease[MAX_JOYSTICK_NUM][MAX_PAD_BUTTON];	// �W���C�p�b�h�̃����[�X���

	bool m_aJoyStateLTRT[MAX_JOYSTICK_NUM][MAX_PAD_TRIGGER];		// LTRT�̓��͏�񃏁[�N
	bool m_aJoyStateTriggerLTRT[MAX_JOYSTICK_NUM][MAX_PAD_TRIGGER];	// LTRT�̃g���K�[���
	bool m_aJoyStateReleaseLTRT[MAX_JOYSTICK_NUM][MAX_PAD_TRIGGER];	// LTRT�̃����[�X���

	float m_fVibrationTime[MAX_JOYSTICK_NUM];	// �U�����鎞��
};
#endif
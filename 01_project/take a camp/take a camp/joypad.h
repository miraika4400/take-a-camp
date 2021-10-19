//====================================================
//
// ジョイパッドヘッダ [joypad.h]
// Author:伊藤陽梧
//
//====================================================

// 二重インクルード防止
#ifndef _JOYPAD_H_
#define _JOYPAD_H_

//====================================================
// インクルードファイル
//====================================================
#include "main.h"
#include "input.h"

//====================================================
//マクロ定義
//====================================================
#define MAX_JOYSTICK_NUM (4)			// JOYPAD接続上限

//ジョイパッドクラス
class CInputJoypad : public CInput
{
public:

	typedef enum
	{
		// ボタン
		PAD_UP = 0,			// 十字キーの上
		PAD_DOWN,			// 十字キーの下
		PAD_LEFT,			// 十字キーの左
		PAD_RIGHT,			// 十字キーの右
		PAD_START,			// Start
		PAD_BACK,			// Back
		PAD_LEFT_THUMB,		// 左スティックの押し込み
		PAD_RIGHT_THUMB,	// 右スティックの押し込み
		PAD_LB,				// LB
		PAD_RB,				// RB
		PAD_A,				// Aボタン
		PAD_B,				// Bボタン
		PAD_X,				// Xボタン
		PAD_Y,				// Yボタン
		MAX_PAD_BUTTON		// ボタンの最大値
	}PAD_BUTTON_STATE;

	typedef enum
	{
		// トリガー
		PAD_LT = 0,			// 左トリガー
		PAD_RT,				// 右トリガー
		MAX_PAD_TRIGGER		// トリガーの最大値
	}PAD_TRRIGER_STATE;

	typedef enum
	{
		// スティック
		PAD_LEFT_STICK,		// 左スティック
		PAD_RIGHT_STICK,	// 右スティック
	}PAD_STICK_STATE;

	typedef enum
	{
		BUTTON_PRESS = 0,
		BUTTON_TRIGGER,
		BUTTON_RELEASE
	}BUTTON_PUSH_STATE;

	//============
	// メンバ関数
	//============
	CInputJoypad();
	~CInputJoypad();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);	// 初期化
	void Uninit(void);								// 終了
	void Update(void);								// 更新

	// ゲッター
	bool GetButtonState(const WORD pad_state, const BUTTON_PUSH_STATE Push_Stateint, int nJoystickNum = 0);				// ボタンの押し込みの取得
	bool GetTriggerState(const PAD_TRRIGER_STATE pad_state, const BUTTON_PUSH_STATE Push_State, int nJoystickNum = 0);	// LT、RTの押し込みの取得
	int GetTriggerPushCondition(const PAD_TRRIGER_STATE pad_state, int nJoystickNum = 0);								// LT、RTの押し込み具合の取得

	void EnableVibration(const float L_vib, const float R_vib, int nJoystickNum = 0);	// バイブレーションの開始
	void DisableVibration(int nJoystickNum = 0);										// バイブレーションの終了
private:
	WORD Return_XInput(const PAD_BUTTON_STATE Pad_Botton_State);	// Xinputのボタンを返す処理
	int Return_Button(const WORD Xinput_Gamepad);					// 列挙型のボタンを返す処理

	void UpdateTriggerState(const int nTriggerPush, const int nPadTrigger, int nJoystickNum = 0);	// トリガーの更新処理

	// ゲッター
	DWORD GetPadState(XINPUT_STATE& state, int nJoystickNum = 0);									// ジョイパッドの情報の取得
	D3DXVECTOR2 GetStickState(const PAD_STICK_STATE Pad_Stick_State, int nJoystickNum = 0);			// スティックの取得
	bool GetJoystickPress(const WORD wPad_State, const int nPad_Bottan, int nJoystickNum = 0);		// ボタンのプレス情報の取得
	bool GetJoystickTrigger(const WORD wPad_State, const int nPad_Bottan, int nJoystickNum = 0);	// ボタンのトリガー情報の取得
	bool GetJoystickRelease(const WORD wPad_State, const int nPad_Bottan, int nJoystickNum = 0);	// ボタンのリリース情報の取得
	bool GetJoystickPressLTRT(const int nPad_Trigger, int nJoystickNum = 0);						// LTRTのプレス情報の取得
	bool GetJoystickTriggerLTRT(const int nPad_Trigger, int nJoystickNum = 0);						// LTRTのトリガー情報の取得
	bool GetJoystickReleaseLTRT(const int nPad_Trigger, int nJoystickNum = 0);						// LTRTのリリース情報の取得

	// メンバ変数
	WORD m_aJoyState[MAX_JOYSTICK_NUM][MAX_PAD_BUTTON];			// ジョイパッドの入力情報ワーク
	WORD m_aJoyStateTrigger[MAX_JOYSTICK_NUM][MAX_PAD_BUTTON];	// ジョイパッドのトリガー情報
	WORD m_aJoyStateRelease[MAX_JOYSTICK_NUM][MAX_PAD_BUTTON];	// ジョイパッドのリリース情報

	bool m_aJoyStateLTRT[MAX_JOYSTICK_NUM][MAX_PAD_TRIGGER];		// LTRTの入力情報ワーク
	bool m_aJoyStateTriggerLTRT[MAX_JOYSTICK_NUM][MAX_PAD_TRIGGER];	// LTRTのトリガー情報
	bool m_aJoyStateReleaseLTRT[MAX_JOYSTICK_NUM][MAX_PAD_TRIGGER];	// LTRTのリリース情報
};
#endif
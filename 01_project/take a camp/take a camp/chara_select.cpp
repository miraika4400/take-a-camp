////////////////////////////////////////////////////
//
//    キャラ選択クラスの処理[chara_select.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//=============================
// インクルード
//=============================
#include "chara_select.h"
#include "joypad.h"
#include "manager.h"
#include "chara_select_ui.h"
#include "keyboard.h"
#include "manager.h"
#include "fade.h"

//=============================
// マクロ定義
//=============================

//=============================
// 静的メンバ変数宣言
//=============================
CCharaSelect::Entry_Data CCharaSelect::m_aEntryData[MAX_PLAYER] = {};
int CCharaSelect::m_nEntryPlayerNum = 0;

//=============================
// コンストラクタ
//=============================
CCharaSelect::CCharaSelect()
{
	// 変数のクリア
	ZeroMemory(&m_abUseJoy, sizeof(m_abUseJoy));
	ZeroMemory(&m_abUseKey, sizeof(m_abUseKey));
}

//=============================
// デストラクタ
//=============================
CCharaSelect::~CCharaSelect()
{
}

//=============================
// クリエイト
//=============================
CCharaSelect * CCharaSelect::Create(void)
{
	// メモリの確保
	CCharaSelect *pGame = new CCharaSelect;
	// 初期化
	pGame->Init();

	return pGame;
}

//=============================
// 初期化処理
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
// 終了処理
//=============================
void CCharaSelect::Uninit(void)
{
	// 開放処理
	Release();
}

//=============================
// 更新処理
//=============================
void CCharaSelect::Update(void)
{

	// エントリー処理
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
// 描画処理
//=============================
void CCharaSelect::Draw(void)
{
}

//=============================
// キャラクター数のリセット
//=============================
void CCharaSelect::ResetEntryPlayer(void)
{
	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		m_aEntryData[nCntData].bController = false;
		m_aEntryData[nCntData].bEntry = false;
		m_aEntryData[nCntData].nColorNum = nCntData; // 仮
		m_aEntryData[nCntData].nControllNum = -1;
		m_aEntryData[nCntData].charaType = CPlayer::CHARA_TYPE_FIGHTER;
	}

	m_nEntryPlayerNum = 0;
}

//=============================
// プレイヤーのエントリー処理
//=============================
void CCharaSelect::EntryPlayer(void)
{
	// エントリー
	auto EntryPlayer = [this](int nCntData, int nCntJoy, bool bController)
	{
		// エントリー状態にする
		m_aEntryData[nCntData].bEntry = true;
		// コントローラーフラグ
		m_aEntryData[nCntData].bController = bController;
		// コントローラー番号のセット
		m_aEntryData[nCntData].nControllNum = nCntJoy;
		// コントローラーを使用状態に
		if (bController) m_abUseJoy[nCntJoy] = true;
		else m_abUseKey[nCntJoy] = true;
	};

	// エントリー解除処理
	auto EntryCancelPlayer = [this](int nCntData)
	{
		// エントリー状態にする
		m_aEntryData[nCntData].bEntry = false;
		// コントローラー・キーボードを非使用状態に
		if (m_aEntryData[nCntData].bController) m_abUseJoy[m_aEntryData[nCntData].nControllNum] = false;
		else m_abUseKey[m_aEntryData[nCntData].nControllNum] = false;

		// コントローラーフラグ
		m_aEntryData[nCntData].bController = false;
		// コントローラー番号のセット
		m_aEntryData[nCntData].nControllNum = -1;
	};

	CInputJoypad * pJoy = CManager::GetJoypad();
	CInputKeyboard *pKey = CManager::GetKeyboard();

	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		if (m_aEntryData[nCntData].bEntry)
		{
			// エントリー解除処理
			if (   m_aEntryData[nCntData].bController && pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, m_aEntryData[nCntData].nControllNum)
				||!m_aEntryData[nCntData].bController && pKey->GetKeyTrigger(CPlayer::GetPlayerControllKey(m_aEntryData[nCntData].nControllNum, CPlayer::KEY_PROGRESS)))
			{
				EntryCancelPlayer(nCntData);
				break;
			}
		}

		for (int nCntJoy = 0; nCntJoy < MAX_PLAYER; nCntJoy++)
		{
			// エントリー処理
			if (!m_aEntryData[nCntData].bEntry)
			{// エントリー状態じゃないとき
				if (!m_abUseJoy[nCntJoy] && pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, nCntJoy))
				{// コントローラーでエントリー
					EntryPlayer(nCntData, nCntJoy, true);
					break;
				}

				// エントリーキーの取得*前進キー
				int nEntryKey = CPlayer::GetPlayerControllKey(nCntJoy, CPlayer::KEY_PROGRESS);
				if (!m_abUseKey[nCntJoy] && pKey->GetKeyTrigger(CPlayer::GetPlayerControllKey(nCntJoy, CPlayer::KEY_PROGRESS)))
				{// キーボードでエントリー
					EntryPlayer(nCntData, nCntJoy, false);
					break;
				}
			}
		}
	}
}

//=============================
// エントリー人数のカウント
//=============================
void CCharaSelect::CountEntryPlayerNum(void)
{
	m_nEntryPlayerNum = 0;
	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{
		if (m_aEntryData[nCntData].bEntry)
		{// エントリーフラグがtrueの時にカウントする
			m_nEntryPlayerNum++;
		}
	}
}

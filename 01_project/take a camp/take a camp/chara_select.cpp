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
	ZeroMemory(&m_abUseControll, sizeof(m_abUseControll));
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
		m_aEntryData[nCntData].bController = false;
		m_aEntryData[nCntData].bEntry= false;
		m_aEntryData[nCntData].nColorNum = nCntData; // 仮
		m_aEntryData[nCntData].nControllNum = -1;
		m_aEntryData[nCntData].charaType = CPlayer::CHARA_TYPE_FIGHTER;
		m_abUseControll[nCntData] = false;
	}

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

	if(CManager::GetKeyboard()->GetKeyTrigger(DIK_F1))
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
// プレイヤーのエントリー処理
//=============================
void CCharaSelect::EntryPlayer(void)
{
	CInputJoypad * pJoy = CManager::GetJoypad();

	for (int nCntData = 0; nCntData < MAX_PLAYER; nCntData++)
	{

		if (m_aEntryData[nCntData].bEntry)
		{
			// エントリー解除処理
			if (pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, m_aEntryData[nCntData].nControllNum))
			{
				// エントリー状態にする
				m_aEntryData[nCntData].bEntry = false;
				// コントローラーフラグ
				m_aEntryData[nCntData].bController = false;
				// コントローラーを非使用状態に
				m_abUseControll[m_aEntryData[nCntData].nControllNum] = false;
				// コントローラー番号のセット
				m_aEntryData[nCntData].nControllNum = -1;
				break;
			}
		}

		for (int nCntJoy = 0; nCntJoy < MAX_PLAYER; nCntJoy++)
		{
			// エントリー処理
			if (!m_aEntryData[nCntData].bEntry && !m_abUseControll[nCntJoy])
			{// エントリー状態じゃないとき
				if (pJoy->GetButtonState(XINPUT_GAMEPAD_START, CInputJoypad::BUTTON_TRIGGER, nCntJoy))
				{
					// エントリー状態にする
					m_aEntryData[nCntData].bEntry = true;
					// コントローラーフラグ
					m_aEntryData[nCntData].bController = true;
					// コントローラー番号のセット
					m_aEntryData[nCntData].nControllNum = nCntJoy;
					// コントローラーを使用状態に
					m_abUseControll[nCntJoy] = true;
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

////////////////////////////////////////////////////
//
//    ゲームクラスの処理[game.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//=============================
// インクルード
//=============================
#include "game.h"
#include "number.h"
#include "score.h" 
#include "mouse.h"
#include "camera_tps.h"
#include "light.h"
#include "fade.h"
#include "keyboard.h"
#include "particle.h"
#include "time.h"
#include "joypad.h"
#include "result.h"
#include "bg.h"

//=============================
// マクロ定義
//=============================

//=============================
// 静的メンバ変数宣言
//=============================
CLight  *CGame::m_pLight = NULL;      // ライトクラスポインタ
CRuleManager* CGame::m_pRuleManager = NULL; // ルールマネージャークラス

//=============================
// コンストラクタ
//=============================
CGame::CGame()
{
	// 変数のクリア
}

//=============================
// デストラクタ
//=============================
CGame::~CGame()
{
}

//=============================
// クリエイト
//=============================
CGame * CGame::Create(void)
{
	// メモリの確保
	CGame *pGame = new CGame;
	// 初期化
	pGame->Init();
	return pGame;
}

//=============================
// 初期化処理
//=============================
HRESULT CGame::Init(void)
{
	// ポーズの初期化
	CManager::SetActivePause(false);

	CManager::SetCamera(CCamera::Create());

	CBg::Create();
	// ライトクラスの生成
	m_pLight = new CLight;
	// ライトクラスの初期化
	if (m_pLight != NULL)
	{
		if (FAILED(m_pLight->Init()))
		{
			return -1;
		}
	}

	return S_OK;
}

//=============================
// 終了処理
//=============================
void CGame::Uninit(void)
{
	// カメラクラスの解放処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
		pCamera = NULL;
	}
	
	// ライト
	if (m_pLight != NULL)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = NULL;
	}



	// 開放処理
	Release();
}

//=============================
// 更新処理
//=============================
void CGame::Update(void)
{

	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

#ifdef _DEBUG
	// デバッグ用画面遷移コマンド
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F1))
	{
		CManager::GetFade()->SetFade(CManager::MODE_RESULT);
	}

#endif // _DEBUG

}

//=============================
// 描画処理
//=============================
void CGame::Draw(void)
{
	CCamera * pCamera = CManager::GetCamera();
    // カメラのセット
    if (pCamera != NULL)
    {
		pCamera->SetCamera();
    }
}
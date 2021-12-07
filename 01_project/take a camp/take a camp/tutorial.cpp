////////////////////////////////////////////////////
//
//    tutorialの処理[tutorial.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//=============================
// インクルード
//=============================
#include "tutorial.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "keyboard.h"
#include "mouse.h"
#include "joypad.h"
#include "fade.h"
#include "resource_texture.h"
#include "sound.h"
#include "camera_base.h"
#include "map.h"
#include "light.h"
#include "bg.h"
#include "text.h"

//**********************************
// 静的メンバ変数宣言
//**********************************
LPDIRECT3DTEXTURE9 CTutorial::m_pTexture[TUTORIAL_NUM] = {};

//**********************************
// マクロ定義
//**********************************

//=============================
// コンストラクタ
//=============================
CTutorial::CTutorial()
{
	m_pPolygon = NULL;
	m_nNumTutorial = 0;
}

//=============================
// デストラクタ
//=============================
CTutorial::~CTutorial()
{
}

//=============================
// クリエイト
//=============================
CTutorial * CTutorial::Create(void)
{
	// メモリの確保
	CTutorial *pTitle = new CTutorial;

	// 初期化
	pTitle->Init();
	return pTitle;
}

//=============================
// 初期化処理
//=============================
HRESULT CTutorial::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//// テクスチャの生成
	//m_pTexture[0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SPEECHBUBBLE);

	m_pPolygon = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f),
		D3DXVECTOR3(512.0f, 256.0f, 0.0f),
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SPEECHBUBBLE));

	// 背景の設定
	CBg::Create();

	// カメラ生成
	CManager::SetCamera(CCamera::Create());
	CMap::Create(CMapManager::MAP_TYPE_1);

	// ライトクラスの生成
	CManager::SetLight();

	CText::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f), 25.0f, 10.0f, "好きな食べ物はメロンと梅干しとサーモンと生ハムで、嫌いな食べ物は野菜全般とみずみずしい食べ物です。", CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	return S_OK;
}

//=============================
// 終了処理
//=============================
void CTutorial::Uninit(void)
{
	if (m_pPolygon != NULL)
	{
		// ポリゴンの終了処理
		m_pPolygon->Uninit();

		// メモリの解放
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	// カメラクラスの解放処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
		pCamera = NULL;
	}

	// ライトクラスの解放処理
	CLight * pLight = CManager::GetLight();
	if (pLight != NULL)
	{
		// ライトの終了処理
		pLight->Uninit();

		// メモリの解放
		delete pLight;
		pLight = NULL;
	}

	// 開放処理
	Release();
}

//=============================
// 更新処理
//=============================
void CTutorial::Update(void)
{
	//// ポリゴンの更新処理
	//m_pPolygon->Update();

	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN) ||
		CManager::GetMouse()->GetMouseTrigger(0) /*||
		CManager::GetJoypad()->GetJoystickTrigger(3, 0)*/)
	{
		m_nNumTutorial++;
		if (m_nNumTutorial >= TUTORIAL_NUM)
		{
			CManager::GetFade()->SetFade(CManager::MODE_TITLE);
		}
		//else
		//{
		//	m_pPolygon->BindTexture(m_pTexture[m_nNumTutorial]);
		//}
	}
	//if (CManager::GetKeyboard()->GetKeyTrigger(DIK_BACKSPACE) /*||
	//	CManager::GetJoypad()->GetJoystickTrigger(2, 0)*/)
	//{
	//	m_nNumTutorial--;
	//	if (m_nNumTutorial < 0)
	//	{
	//		m_nNumTutorial = 0;
	//	}

	//	m_pPolygon->BindTexture(m_pTexture[m_nNumTutorial]);
	//}

	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}
}

//=============================
// 描画処理
//=============================
void CTutorial::Draw(void)
{
	// ポリゴンの描画処理
	m_pPolygon->Draw();

	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}
}

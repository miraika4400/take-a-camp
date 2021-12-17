//====================================================
//
//    tutorialの処理[tutorial.cpp]
//    Author:伊藤　陽梧
//
//====================================================

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
#include "color_tile.h"
#include "chara_select.h"
#include "player.h"
#include "debug_log.h"
#include "kill_count.h"
#include "resource_text.h"

//**********************************
// 静的メンバ変数宣言
//**********************************
LPDIRECT3DTEXTURE9 CTutorial::m_pTexture[TUTORIAL_NUM] = {};

//**********************************
// マクロ定義
//**********************************
#define TARGET_PAINT (10)		// 塗る枚数
#define TARGET_OVERPAINT (10)	// 重ね塗りする枚数
#define TARGET_KILL (2)			// スキルで倒す人数

//=============================
// コンストラクタ
//=============================
CTutorial::CTutorial()
{
	m_pMap = nullptr;
	m_pPolygon = nullptr;
	m_pText = nullptr;
	ZeroMemory(&m_bTask, sizeof(m_bTask));
	ZeroMemory(&m_bEntry, sizeof(m_bEntry));
	m_Tutorialphase = PHASE_PAINT;
	m_nTextNum = 0;
	m_bNextText = false;
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
CTutorial * CTutorial::Create()
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
HRESULT CTutorial::Init()
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//// テクスチャの生成
	//m_pTexture[0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SPEECHBUBBLE);

	//m_pPolygon = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f),
	//	D3DXVECTOR3(512.0f, 256.0f, 0.0f),
	//	D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	//m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SPEECHBUBBLE));

	// 背景の設定
	CBg::Create();

	// カメラ生成
	CManager::SetCamera(CCamera::Create());

	// マップ生成
	m_pMap = CMap::Create(CMapManager::MAP_TYPE_1);

	return S_OK;
}

//=============================
// 終了処理
//=============================
void CTutorial::Uninit()
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

	// 開放処理
	Release();
}

//=============================
// 更新処理
//=============================
void CTutorial::Update()
{
	//// ポリゴンの更新処理
	//m_pPolygon->Update();

	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
	{
		CManager::GetFade()->SetFade(CManager::MODE_TITLE);
	}

	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

	// フェーズごとに処理を変える
	switch (m_Tutorialphase)
	{
		//case PHAZE_MOVE:
		//	for (int nCount = 0; nCount < CCharaSelect::GetEntryPlayerNum(); nCount++)
		//	{
		//		if (CColorTile::GetTileNum(nCount, 1) >= 10)
		//		{
		//			m_bTask[nCount] = true;
		//			if (m_bTask[nCount])
		//			{
		//				nTaskClear++;
		//			}
		//		}
		//		if (CCharaSelect::GetEntryPlayerNum() == nTaskClear)
		//		{
		//			m_Tutorialphase = PHAZE_PAINT;
		//		}
		//	}
		//	break;

	case PHASE_PAINT:
		for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
		{
			CheckTaskClear(CColorTile::GetTileNum(nCount, 1), TARGET_PAINT, nCount);
		}
		break;

	case PHASE_OVERPAINT:
		for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
		{
			CheckTaskClear(CColorTile::GetTileNum(nCount, 3), TARGET_OVERPAINT, nCount);
		}
		break;

	case PHASE_ATTACK:
		for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
		{
			CheckTaskClear(CKillCount::GetTotalKill(nCount), TARGET_KILL, nCount);
		}
		break;

	case PHASE_FINALATTACK:
		for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
		{
			CheckTaskClear(CKillCount::GetTotalKill(nCount), TARGET_KILL, nCount);
		}
		break;

	default:
		break;
	}

	// タイルの色のカウント
	CKillCount::AddTotalKill();
	CColorTile::CountColorTile();

	CDebugLog::Init();
	CDebugLog::Print("1P:Kill:%d\n", CKillCount::GetTotalKill(0));
	CDebugLog::Print("2P:Kill:%d\n", CKillCount::GetTotalKill(1));
	CDebugLog::Print("3P:Kill:%d\n", CKillCount::GetTotalKill(2));
	CDebugLog::Print("4P:Kill:%d\n", CKillCount::GetTotalKill(3));

	CDebugLog::Print("赤:%d(一:%d,二:%d,三:%d)\n", CColorTile::GetTileNum(0), CColorTile::GetTileNum(0, 1), CColorTile::GetTileNum(0, 2), CColorTile::GetTileNum(0, 3));
	CDebugLog::Print("青:%d(一:%d,二:%d,三:%d)\n", CColorTile::GetTileNum(1), CColorTile::GetTileNum(1, 1), CColorTile::GetTileNum(1, 2), CColorTile::GetTileNum(1, 3));
	CDebugLog::Print("緑:%d(一:%d,二:%d,三:%d)\n", CColorTile::GetTileNum(2), CColorTile::GetTileNum(2, 1), CColorTile::GetTileNum(2, 2), CColorTile::GetTileNum(2, 3));
	CDebugLog::Print("橙:%d(一:%d,二:%d,三:%d)\n", CColorTile::GetTileNum(3), CColorTile::GetTileNum(3, 1), CColorTile::GetTileNum(3, 2), CColorTile::GetTileNum(3, 3));

	CDebugLog::Print("チュートリアル:%d\n", m_Tutorialphase);

	if (!m_bNextText)
	{
		UpdateText();
	}
	else if(m_pText->GetAllShowText())
	{
		if (CManager::GetKeyboard()->GetKeyTrigger(DIK_1))
		{
			m_pText->ClearText();
			m_bNextText = false;
		}
	}
}

//=============================
// 描画処理
//=============================
void CTutorial::Draw()
{
	if (m_pPolygon != NULL)
	{
		// ポリゴンの描画処理
		m_pPolygon->Draw();
	}

	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}
}

//=============================
// タスクを完了したのかチェックする処理
//=============================
void CTutorial::CheckTaskClear(const int nCurTaskNum, const int nTargetNum, const int nPlayernum)
{
	// タスクごとの処理で受け取った数とその目標数を比べる
	if (nCurTaskNum >= nTargetNum)
	{
		m_bTask[nPlayernum] = true;
	}

	// trueの数を数える
	int nTaskClear = std::count(std::begin(m_bTask), std::end(m_bTask), true);

	// プレイヤー数とタスクを完了した数が一致してたら
	if (CCharaSelect::GetEntryPlayerNum() == nTaskClear)
	{
		// 次のフェーズへの移行
		int nTutorialphase = (int)m_Tutorialphase;
		nTutorialphase++;
		m_Tutorialphase = (TUTORIALPHASE)nTutorialphase;

		// タスクの初期化
		ZeroMemory(&m_bTask, sizeof(m_bTask));
	}
}

void CTutorial::UpdateText(void)
{
	if (!m_pText)
	{
		m_pText = CText::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f), 25.0f, 10.0f, CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}

	// リソーステキストのポインタ取得
	CResourceText * pResourceText = CResourceText::GetResourceText();

	while (!pResourceText->GetMapString(m_nTextNum).empty())
	{
		if (pResourceText->GetMapString(m_nTextNum).find("TEXT_DATASET") == 0)
		{
			while (pResourceText->GetMapString(m_nTextNum).find("END_TEXT_DATASET") != 0)
			{
				if (pResourceText->GetMapString(m_nTextNum).find("SAY") == 0)
				{
					std::string str = CResourceText::GetResourceText()->GetMapString(m_nTextNum);
					str = str.substr(6);
					m_pText->AddText(str);
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("NR") == 0)
				{
					m_pText->AddText("\n");
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("ENTER") == 0)
				{
					m_bNextText = true;
					return;
				}
				m_nTextNum++;
			}
		}
		m_nTextNum++;
	}
}
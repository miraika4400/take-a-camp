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
	m_bTextEnd = false;
	ZeroMemory(&m_nCurTaskNum, sizeof(m_nCurTaskNum));
	ZeroMemory(&m_nOldCurTaskNum, sizeof(m_nOldCurTaskNum));
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

	//if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
	//{
	//	CManager::GetFade()->SetFade(CManager::MODE_TITLE);
	//}

	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

	if (m_bTextEnd)
	{
		// プレイヤーの更新出来るようにする
		StartPlayer(true);
	}

	if (!m_bNextText)
	{
		UpdateText();
	}
	else if (m_pText->GetAllShowText() && !m_bTextEnd)
	{
		// プレイヤーの更新を止める
		StartPlayer(false);

		if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
		{
			m_pText->ClearText();
			m_bNextText = false;
		}
	}
	else
	{
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

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		CDebugLog::Print("現在のタスクごとの数:%d\n", m_nCurTaskNum[nCount]);
	}

	CDebugLog::Print("チュートリアル:%d\n", m_Tutorialphase);
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
	// 現在のタスクごとの数と1フレーム前の数を比べる
	if (nCurTaskNum > m_nOldCurTaskNum[nPlayernum])
	{
		m_nCurTaskNum[nPlayernum] += nCurTaskNum - m_nOldCurTaskNum[nPlayernum];
	}

	// タスクごとの処理で受け取った数とその目標数を比べる
	if (m_nCurTaskNum[nPlayernum] >= nTargetNum)
	{
		m_bTask[nPlayernum] = true;
	}

	// 現在のタスクごとの数を1フレーム前の数にする
	m_nOldCurTaskNum[nPlayernum] = nCurTaskNum;

	// trueの数を数える
	int nTaskClear = std::count(std::begin(m_bTask), std::end(m_bTask), true);

	// プレイヤー数とタスクを完了した数が一致してたら
	if (CCharaSelect::GetEntryPlayerNum() == nTaskClear)
	{
		// 次のテキストを表示する
		m_bNextText = false;

		// 次のフェーズに移行する
		NextPhase();

		// タスクの初期化
		ZeroMemory(&m_bTask, sizeof(m_bTask));
		ZeroMemory(&m_nCurTaskNum, sizeof(m_nCurTaskNum));
		//ZeroMemory(&m_nOldCurTaskNum, sizeof(m_nOldCurTaskNum));
	}
}

//============================================
// テキストの表示
//============================================
void CTutorial::UpdateText(void)
{
	if (!m_pText)
	{
		m_pText = CText::Create(D3DXVECTOR2(SCREEN_WIDTH / 2.0f, 600.0f), 50.0f, 20.0f, CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}

	// リソーステキストのポインタ取得
	CResourceText * pResourceText = CResourceText::GetResourceText();

	while (!pResourceText->GetMapString(m_nTextNum).empty()
		|| !pResourceText->GetMapString(m_nTextNum + 1).empty())
	{
		if (pResourceText->GetMapString(m_nTextNum).find("TEXT_DATASET") == 0)
		{
			m_bTextEnd = false;
		}

		if (!m_bTextEnd)
		{
			while (pResourceText->GetMapString(m_nTextNum).find("END_TEXT_DATASET") != 0)
			{
				std::string str = CResourceText::GetResourceText()->GetMapString(m_nTextNum);

				if (pResourceText->GetMapString(m_nTextNum).find("WINDOWRANGE") == 0)
				{
					str = str.substr(14);

					D3DXVECTOR2 Windowrange[2];
					ZeroMemory(&Windowrange, sizeof(Windowrange));
					sscanf(str.c_str(), "%f %f %f %f", &Windowrange[0].x, &Windowrange[0].y, &Windowrange[1].x, &Windowrange[1].y);
					m_pText->SetWindowRange(Windowrange);
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("FONTSIZE") == 0)
				{
					str = str.substr(11);

					D3DXVECTOR2 FontSize;
					ZeroMemory(&FontSize, sizeof(FontSize));
					sscanf(str.c_str(), "%f %f", &FontSize.x, &FontSize.y);
					m_pText->SetFontSize(FontSize);
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("COLOR") == 0)
				{
					str = str.substr(8);

					D3DXCOLOR color;
					ZeroMemory(&color, sizeof(color));
					sscanf(str.c_str(), "%f %f %f %f", &color.r, &color.g, &color.b, &color.a);
					m_pText->SetColor(color);
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("POS") == 0)
				{
					str = str.substr(6);

					D3DXVECTOR2 Pos;
					ZeroMemory(&Pos, sizeof(Pos));
					sscanf(str.c_str(), "%f %f", &Pos.x, &Pos.y);
					m_pText->SetPos(Pos);
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("SAY") == 0)
				{
					str = str.substr(6);
					m_pText->AddText(str);
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("NR") == 0)
				{
					m_pText->AddText("\n");
				}
				else if (pResourceText->GetMapString(m_nTextNum).find("ENTER") == 0)
				{
					m_nTextNum++;
					m_bNextText = true;
					return;
				}
				m_nTextNum++;
			}
			m_bTextEnd = true;
			m_bNextText = true;
			m_nTextNum++;
			return;
		}
		m_nTextNum++;
	}
}

//============================================
// 次のフェーズへの移行
//============================================
void CTutorial::NextPhase(void)
{
	int nTutorialphase = (int)m_Tutorialphase;
	nTutorialphase++;
	m_Tutorialphase = (TUTORIALPHASE)nTutorialphase;
}

//============================================
// プレイヤー更新のフラグを変える
//============================================
void CTutorial::StartPlayer(bool bUpdate)
{
	CPlayer*pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		pPlayer->SetUpdateFlag(bUpdate);

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}
//====================================================
//
// tutorialの処理[tutorial.cpp]
// Author:伊藤　陽梧
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
#include "light.h"
#include "bg.h"
#include "text.h"
#include "color_tile.h"
#include "chara_select.h"
#include "player.h"
#include "debug_log.h"
#include "kill_count.h"
#include "resource_text.h"
#include "paintnum.h"
#include "skill_gauge.h"
#include "map.h"
#include "resource_map.h"
#include "dummy.h"

//=============================
// マクロ定義
//=============================
#define TARGET_PAINT (15)			// 塗る枚数
#define TARGET_OVERPAINT (15)		// 重ね塗りする枚数
#define TARGET_KILL (5)				// スキルで倒す人数
#define ADD_TEXTWINDOWRANGE (10.0f)	// テキストウィンドウの範囲を加算する値
#define TEXTWINDOW_COLOR (D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.2f))	// テキストウィンドウの色
#define TEXTSHOWTIME (90)			// テキストを表示する時間

//=============================
// コンストラクタ
//=============================
CTutorial::CTutorial()
{
	m_pMap = nullptr;
	m_pTextWindow = nullptr;
	m_pText = nullptr;
	m_bTask = nullptr;
	m_Tutorialphase = PHASE_PAINT;
	m_nTextNum = 0;
	m_bNextText = false;
	m_bTextEnd = false;
	ZeroMemory(&m_nCurTaskNum, sizeof(m_nCurTaskNum));
	ZeroMemory(&m_nOldCurTaskNum, sizeof(m_nOldCurTaskNum));
	m_nTextShowTime = 0;
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

	// 一時的にプライオリティーをUIにする
	pTitle->SetPriority(OBJTYPE_UI_2);
	return pTitle;
}

//=============================
// 初期化処理
//=============================
HRESULT CTutorial::Init()
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// 背景の設定
	CBg::Create();

	// カメラ生成
	CManager::SetCamera(CCamera::Create());

	// マップ生成
	m_pMap = CMap::Create(CMapManager::MAP_TYPE_TUTORIAL);

	// テキスト表示するときの背景を作る
	if (!m_pTextWindow)
	{
		m_pTextWindow = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),
			TEXTWINDOW_COLOR);
	}

	// ダミーを作る
	DummyCreate();

	// プレイヤーが動けなかったから動けるようにする
	StartPlayer(true);

	// サウンド情報の取得
	CSound *pSound = CManager::GetSound();
	// BGM停止
	pSound->Stop(CSound::LABEL_BGM_SELECT);
	// BGM再生
	pSound->Play(CSound::LABEL_BGM_GAME);


	return S_OK;
}

//=============================
// 終了処理
//=============================
void CTutorial::Uninit()
{
	if (m_pTextWindow)
	{
		// ポリゴンの終了処理
		m_pTextWindow->Uninit();

		// メモリの解放
		delete m_pTextWindow;
		m_pTextWindow = NULL;
	}

	// カメラクラスの解放処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera)
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
	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

	// テキスト表示するときの背景のセット
	SetTextWindow();

	// テキスト表示が終わったら
	if (m_bTextEnd)
	{
		// プレイヤーの更新出来るようにする
		StartPlayer(true);

		// テキストウィンドウの色を無色に
		m_pTextWindow->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));

		// フェーズごとに処理を変える
		switch (m_Tutorialphase)
		{
		case PHASE_PAINT: // 塗るフェーズ
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CColorTile::GetTileNum(nCount, 1), TARGET_PAINT * CCharaSelect::GetEntryPlayerNum(), nCount);
			}
			break;

		case PHASE_OVERPAINT: // 重ね塗りするフェーズ
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CColorTile::GetTileNum(nCount, 3), TARGET_OVERPAINT * CCharaSelect::GetEntryPlayerNum(), nCount);
			}
			break;

		case PHASE_ATTACK: // かかしを攻撃するフェーズ
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CKillCount::GetTotalKill(nCount), TARGET_KILL * CCharaSelect::GetEntryPlayerNum(), nCount);
			}
			break;

		case PHASE_FINALATTACK: // かかしを必殺技で攻撃するフェーズ
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CKillCount::GetTotalKill(nCount), TARGET_KILL * CCharaSelect::GetEntryPlayerNum(), nCount);
			}

			// 必殺技フェーズはゲージを常時最大に
			Max_Playergauge();
			break;

		default:
			break;
		}

	}

	// テキスト表示
	if (!m_bNextText)
	{
		// テキストの更新
		UpdateText();

		// ウインドウの背景の色の設定
		m_pTextWindow->SetColor(TEXTWINDOW_COLOR);

		// 表示する時間の設定
		m_nTextShowTime = TEXTSHOWTIME;
	}
	// 一文表示終えたら
	else if (m_pText->GetAllShowText() && !m_bTextEnd)
	{
		// 表示する時間の減算
		m_nTextShowTime--;

		// テキストを表示する時間が0になったら
		if (m_nTextShowTime <= 0)
		{
			// テキストのクリアと次のテキスト表示
			m_pText->ClearText();
			m_bNextText = false;
		}
	}

	// タイルの色のカウント
	CKillCount::AddTotalKill();
	CColorTile::CountColorTile();

#ifdef _DEBUG
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F1))
	{
		CManager::GetFade()->SetFade(CManager::MODE_TITLE);
	}

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
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		CDebugLog::Print("1フレーム前のタスクごとの数:%d\n", m_nOldCurTaskNum[nCount]);
	}
	CDebugLog::Print("チュートリアル:%d\n", m_Tutorialphase);
#endif // _DEBUG
}

//=============================
// 描画処理
//=============================
void CTutorial::Draw()
{
	// カメラクラス更新処理
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}

	if (m_pTextWindow != NULL)
	{
		// ポリゴンの描画処理
		m_pTextWindow->Draw();
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

	int nAllTaskNum = 0;

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		nAllTaskNum += m_nCurTaskNum[nCount];
	}

	// タスクごとの処理で受け取った数とその目標数を比べる
	if (nAllTaskNum >= nTargetNum)
	{
		m_bTask = true;
	}

	// 現在のタスクごとの数を1フレーム前の数にする
	m_nOldCurTaskNum[nPlayernum] = nCurTaskNum;

	// タスクを完了した数が一致してたら
	if (m_bTask)
	{
		// 次のテキストを表示する
		m_bNextText = false;

		// 次のフェーズに移行する
		NextPhase();

		// タスクの初期化
		m_bTask = nullptr;
		ZeroMemory(&m_nCurTaskNum, sizeof(m_nCurTaskNum));

		// 倒した数が必殺技と攻撃で同期しているので
		// 必殺技フェーズ以外は1フレーム前の数を初期化
		if (m_Tutorialphase != PHASE_FINALATTACK)
		{
			ZeroMemory(&m_nOldCurTaskNum, sizeof(m_nOldCurTaskNum));
		}
	}
}

//============================================
// テキストの表示
//============================================
void CTutorial::UpdateText(void)
{
	if (!m_pText)
	{
		m_pText = CText::Create(D3DXVECTOR2(SCREEN_WIDTH / 2.0f, 600.0f), D3DXVECTOR2(50.0f, 20.0f), CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}
	else
	{
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

					if (pResourceText->GetMapString(m_nTextNum).find("POS") == 0)
					{
						str = str.substr(6);

						D3DXVECTOR2 Pos;
						ZeroMemory(&Pos, sizeof(Pos));
						sscanf(str.c_str(), "%f %f", &Pos.x, &Pos.y);
						m_pText->SetPos(Pos);
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("WINDOWRANGE") == 0)
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

//============================================
// プレイヤーのゲージを最大にする
//============================================
void CTutorial::Max_Playergauge(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer)
	{
		pPlayer->GetSkillgauge()->SkillGauge_Max();
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//============================================
// ダミーを作る処理
//============================================
void CTutorial::DummyCreate(void)
{
	CMapManager::MAP_DATA MapData = m_pMap->GetMapData();

	//マップデータがあるか
	if (&MapData != NULL)
	{
		for (int nBlockY = 0; nBlockY < MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				// プレイヤーの生成
				switch (MapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case CMapManager::BLOCK_TYPE_DUMMY:	//1Pスタート位置
					CDummy::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
					break;

				default:
					break;
				}
			}
		}
	}
}

//============================================
// テキスト表示するときの背景のセット
//============================================
void CTutorial::SetTextWindow(void)
{
	// 頂点座標の設定
	D3DXVECTOR3 Pos[NUM_VERTEX];

	if (m_pText)
	{
		// 頂点座標の設定
		Pos[0] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[0].x - ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[0].y - ADD_TEXTWINDOWRANGE, 0.0f);
		Pos[1] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[1].x + ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[0].y - ADD_TEXTWINDOWRANGE, 0.0f);
		Pos[2] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[0].x - ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[1].y + ADD_TEXTWINDOWRANGE, 0.0f);
		Pos[3] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[1].x + ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[1].y + ADD_TEXTWINDOWRANGE, 0.0f);
	}

	if (m_pTextWindow)
	{
		// 頂点ごとの情報をセット
		m_pTextWindow->SetVertexPos(Pos);
	}
}
////////////////////////////////////////////////////
//
//    tileクラスの処理[tile.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "color_tile.h"
#include "collision.h"
#include "player.h"
#include "color_manager.h"
#include "scene3d.h"
#include "resource_texture.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// マクロ定義
//*****************************
#define TILE_DEFAULT_COLOR D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)
#define PEINT_COUNT 60  // 再度塗れるようになるまでのカウント
#define PLAYER_HIT_POS_Y TILE_POS_Y - 3.0f

//*****************************
// 静的メンバ変数宣言
//*****************************
int CColorTile::m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1] = {};

//******************************
// コンストラクタ
//******************************
CColorTile::CColorTile()
{
	m_pFrame = NULL;
	m_nPrevNum = -1;                             // 今塗られているカラーの番号*デフォルトは-1
	m_nStep = 0;                                 // 今の塗段階
	m_nCntStep = 0;                              // 再度塗り可能カウント
	m_nLastHitPlayerNum = -1;                    // 現在の塗られている番号
}

//******************************
// デストラクタ
//******************************
CColorTile::~CColorTile()
{
}

//******************************
// クラス生成
//******************************
CColorTile * CColorTile::Create(D3DXVECTOR3 pos)
{
	// メモリの確保
	CColorTile *pTile;
	pTile = new CColorTile;

	// 初期化
	pTile->Init();

	// 各値の代入・セット
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_COLOR_TILE); // オブジェクトタイプ

	return pTile;
}

//******************************
// 色の数を数える
//******************************
void CColorTile::CountColorTile(void)
{
	// タイル数の初期化
	ZeroMemory(&m_anTileNum, sizeof(m_anTileNum));

	CColorTile*pTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

	while (pTile != NULL)
	{
		// ペイント番号の取得
		int nPeintNum = pTile->GetPeintNum();

		if (nPeintNum >= 0)
		{
			// タイル数の取得
			m_anTileNum[nPeintNum][0] += pTile->GetStepNum();
			m_anTileNum[nPeintNum][pTile->GetStepNum()]++;
		}
		
		// リストを進める
		pTile = (CColorTile*)pTile->GetNext();
	}
}

//******************************
// 初期化処理
//******************************
HRESULT CColorTile::Init(void)
{
	if (FAILED(CTile::Init()))
	{
		return E_FAIL;
	}

	// アイコン
	m_pFrame = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	m_pFrame->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_FRAME));
	m_pFrame->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	m_pFrame->SetPriority(OBJTYPE_UI);

	// 変数の初期化
	m_nPrevNum = -1;                             // 今塗られているカラーの番号*デフォルトは-1
	m_nStep = 0;                                 // 今の塗段階
	m_nCntStep = 0;                              // 再度塗り可能カウント
	m_nLastHitPlayerNum = -1;                    // 現在の塗られている番号

	return S_OK;
}

//******************************
// 終了処理
//******************************
void CColorTile::Uninit(void)
{
	CTile::Uninit();
}

//******************************
// 更新処理
//******************************
void CColorTile::Update(void)
{

	// タイルのアップデート
	CTile::Update();

	// アイコンの管理
	ManageFrame();

	if (m_nCntStep > 0)
	{
		m_nCntStep--;
	}


#ifdef _DEBUG
	// デバッグキー

	// キーボードの取得
	CInputKeyboard * pKey = CManager::GetKeyboard();

	if (pKey->GetKeyPress(DIK_NUMPADENTER))
	{// 盤面リセット
		ResetTile();
	}
#endif // _DEBUG
}

//******************************
// タイルのリセット処理
//******************************
void CColorTile::ResetTile(void)
{
	SetColor(TILE_DEFAULT_COLOR);

	// 変数の初期化
	m_nPrevNum = -1;                             // 今塗られているカラーの番号*デフォルトは-1
	m_nStep = 0;                                 // 今の塗段階
	m_nCntStep = 0;                              // 再度塗り可能カウント
	m_nLastHitPlayerNum = -1;                    // 最後に当たったプレイヤー番号
	
}

//******************************
// 弾と当たったときのアクション*トリガー
//******************************
void CColorTile::HitPlayerActionTrigger(CPlayer * pPlayer)
{
	Peint(pPlayer->GetColorNumber(), pPlayer->GetPlayerNumber());

	D3DXVECTOR3 pos = GetPos();
	pos.y = PLAYER_HIT_POS_Y;
	SetPos(pos);
}

//******************************
// アイコンの管理
//******************************
void CColorTile::ManageFrame(void)
{
	// 位置の調整
	D3DXVECTOR3 pos = m_pFrame->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 1.0f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 1.0f, GetPos().z);

		m_pFrame->SetPos(pos);
	}

	// 色の設定
	if (m_nStep != 0)
	{
		m_pFrame->SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, 2));
	}
	else
	{
		m_pFrame->SetColor(TILE_DEFAULT_COLOR);
	}
}

//******************************
// 塗処理
//******************************
void CColorTile::Peint(int nColorNumber, int nPlayerNum)
{
	if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum)
	{
		// カウントの初期化
		m_nCntStep = PEINT_COUNT;

		// 最後に当たったプレイヤーの保存
		m_nLastHitPlayerNum = nPlayerNum;

		if (m_nPrevNum == -1)
		{// 今何も塗られていない

			 // カラー番号の保存
			m_nPrevNum = nColorNumber;
			// 色の取得
			SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep));
			// 色段階を進める
			m_nStep++;

		}
		else if (m_nPrevNum == nColorNumber)
		{// 今塗られているのとから塗る番号が一致

			if (m_nStep < COLOR_STEP_NUM)
			{
				// 段階を進める
				m_nStep++;
				// 色の取得
				SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
			}
		}
		else
		{// 今塗られてる色と塗る色が違う

			if (m_nStep == 1)
			{// 段階が一の時
			 // カラー番号の保存
				m_nPrevNum = nColorNumber;
				// カラーの取得
				SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1));
			}
			else
			{// 段階が2以上の時

			 // 段階を減らす
				m_nStep--;
				// 色の取得
				SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
			}
		}
	}

}

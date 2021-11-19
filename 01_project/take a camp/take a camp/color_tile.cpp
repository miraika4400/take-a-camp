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
#include "particle.h"
#include "peint_collision.h"
#include "max_color_effect.h"
#include "paint_time.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// マクロ定義
//*****************************
#define PEINT_COUNT (60)		// 再度塗れるようになるまでのカウント
#define PLAYER_HIT_POS_Y (TILE_POS_Y - 3.0f)

//*****************************
// 静的メンバ変数宣言
//*****************************
int CColorTile::m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1] = {};

//******************************
// コンストラクタ
//******************************
CColorTile::CColorTile()
{
	m_ColorTileState = COLOR_TILE_NORMAL;
	m_pFrame	= NULL;
	m_nPrevNum	= -1;					// 今塗られているカラーの番号*デフォルトは-1
	m_nStep		= 0;					// 今の塗段階
	m_nCntStep	= 0;					// 再度塗り可能カウント
	m_nLastHitPlayerNum = -1;			// 現在の塗られている番号4
	m_nCntFrem	= 0;
	m_distColor	= TILE_DEFAULT_COLOR;
	m_pPaintTime = NULL;
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
void CColorTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// メモリの確保
	CColorTile *pTile;
	pTile = new CColorTile;

	// 初期化
	pTile->Init();

	// 各値の代入・セット
	pTile->SetPos(pos);
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
// 指定座標とぶつかっているタイルの取得処理
//******************************
CColorTile * CColorTile::GetHitColorTile(D3DXVECTOR3 pos)
{
	CCollision*pCollision = CCollision::CreateSphere(pos, TILE_ONE_SIDE / 4);

	CColorTile*pTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

	while (pTile != NULL)
	{
		if (CCollision::CollisionSphere(pCollision,pTile->GetCollision()))
		{
			if (pCollision != NULL)
			{
				pCollision->ReConnection();
				pCollision->Uninit();
				delete pCollision;
				pCollision = NULL;
			}

			return pTile;
		}
		// リストを進める
		pTile = (CColorTile*)pTile->GetNext();
	}

	if (pCollision != NULL)
	{
		pCollision->ReConnection();
		pCollision->Uninit();
		delete pCollision;
		pCollision = NULL;
	}

	return NULL;
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
	m_pFrame->SetColor(TILE_DEFAULT_COLOR);
	m_pFrame->SetPriority(OBJTYPE_UI);

	// 変数の初期化
	m_nPrevNum = -1;                             // 今塗られているカラーの番号*デフォルトは-1
	m_nStep = 0;                                 // 今の塗段階
	m_nCntStep = 0;                              // 再度塗り可能カウント
	m_nLastHitPlayerNum = -1;                    // 現在の塗られている番号
	
	SetPriority(OBJTYPE_COLOR_TILE); // オブジェクトタイプ

	m_pPaintTime = CPaintTime::Create();
	

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

		// 色の管理
		ManageColor();
	}

	if (m_nStep == 3)
	{
		m_nCntFrem++;

		if(m_nCntFrem % 10 <= 0)
		{
			D3DXVECTOR3 pos = m_pFrame->GetPos();
			CParticle::Create(D3DXVECTOR3(pos.x + (float)(rand() % 16 -8), pos.y, pos.z + (float)(rand() % 16 - 8)), D3DXVECTOR3(0.0f, 0.25f, 0.0f), D3DXVECTOR3(3.0f, 3.0f, 3.0f), 500, GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1), EFFECT_DEFAULT_FADE_OUT_RATE, CParticle::PARTICLE_SQUARE);
		}
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
// タイルの塗り段階下げ
//******************************
void CColorTile::ColorDown(int nCount)
{
	//塗り段階を引く
	m_nStep = m_nStep - nCount;

	//0より小さい場合
	if (m_nStep <= 0)
	{
		//タイルリセット
		ResetTile();
	}
	//ゼロ以上の場合
	else
	{
		// 色の取得
		m_distColor = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1);

		//カラー変更
		m_distColor.r = (m_distColor.r);
		m_distColor.g = (m_distColor.g);
		m_distColor.b = (m_distColor.b);

		//カラーセット
		SetColor(m_distColor);
	}
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
// 塗り判定と当たった時のアクション
//******************************
void CColorTile::HItPeint(CPeintCollision * pPeint)
{
	//塗り処理
	Peint(pPeint->GetColorNumber(), pPeint->GetPlayerNum());
	//死亡フラグ
	pPeint->Death();
}

//******************************
// アイコンの管理
//******************************
void CColorTile::ManageFrame(void)
{
	// 位置の調整
	D3DXVECTOR3 pos = m_pFrame->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z);

		m_pFrame->SetPos(pos);
	}

	// 塗時間位置
	m_pPaintTime->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z));

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
// 色の管理
//******************************
void CColorTile::ManageColor(void)
{
	D3DXCOLOR col = GetColor();

	float fRate = 1.0f / PEINT_COUNT;
	
	col.r += (m_distColor.r) * fRate;
	col.g += (m_distColor.g) * fRate;
	col.b += (m_distColor.b) * fRate;

	SetColor(col);
}

//******************************
// 塗処理
//******************************
void CColorTile::Peint(int nColorNumber, int nPlayerNum)
{
	//ステートが通常か
	if (m_ColorTileState == COLOR_TILE_NORMAL)
	{
		if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum)
		{
			// カウントの初期化
			m_nCntStep = PEINT_COUNT;
		//	m_pPaintTime->SetPaintTime(PEINT_COUNT);

			// 最後に当たったプレイヤーの保存
			m_nLastHitPlayerNum = nPlayerNum;

			if (m_nPrevNum == -1)
			{// 今何も塗られていない

			 // カラー番号の保存
				m_nPrevNum = nColorNumber;
				// 色の取得
				//SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep));
				m_distColor = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep);

				m_distColor.r = (m_distColor.r - TILE_DEFAULT_COLOR.r);
				m_distColor.g = (m_distColor.g - TILE_DEFAULT_COLOR.g);
				m_distColor.b = (m_distColor.b - TILE_DEFAULT_COLOR.b);
				// 色段階を進める
				m_nStep++;
			}
			else if (m_nPrevNum == nColorNumber)
			{// 今塗られているとから塗る番号が一致

				if (m_nStep < COLOR_STEP_NUM)
				{
					// 段階を進める
					m_nStep++;
					// 色の取得
					//SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
					m_distColor = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1);

					m_distColor.r = (m_distColor.r - GetColor().r);
					m_distColor.g = (m_distColor.g - GetColor().g);
					m_distColor.b = (m_distColor.b - GetColor().b);

					if (m_nStep == COLOR_STEP_NUM)
					{
						// 塗最大
						CMaxColorEffect::Create(GetPos(), GET_COLORMANAGER->GetIconColor(m_nPrevNum));
						// ペイントタイムは出さない
						m_pPaintTime->SetDrawFlag(false);
					}
				}
				else
				{
					// ペイントタイムは出さない
					m_pPaintTime->SetDrawFlag(false);
					m_nCntStep = 0;
				}
			}
			else
			{// 今塗られてる色と塗る色が違う

				if (m_nStep == 1)
				{// 段階が一の時
				 // カラー番号の保存
					m_nPrevNum = nColorNumber;
					// カラーの取得
					//SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1));
					m_distColor = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1);
					m_distColor.r = (m_distColor.r - GetColor().r);
					m_distColor.g = (m_distColor.g - GetColor().g);
					m_distColor.b = (m_distColor.b - GetColor().b);
				}
				else
				{// 段階が2以上の時

				 // 段階を減らす
					m_nStep--;
					// 色の取得
					//SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
					m_distColor = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1);
					m_distColor.r = (m_distColor.r - GetColor().r);
					m_distColor.g = (m_distColor.g - GetColor().g);
					m_distColor.b = (m_distColor.b - GetColor().b);
				}
			}
		}

	}
}

//******************************
// チャージフラグ処理
//******************************
bool CColorTile::ChargeFlag(int nPlayerNum)
{
	//ステートが通常状態か
	if (m_ColorTileState == COLOR_TILE_NORMAL)
	{
		//プレイヤーが塗ったタイルか
		if (nPlayerNum == m_nLastHitPlayerNum&&m_nStep > 0)
		{
			//ステートをチャージ状態に移行
			m_ColorTileState = COLOR_TILE_CHARGE;
			return true;
		}
	}
	return false;
}

//=============================================================================
//
// ゲーム終了UIの処理 [game_finish.cpp]
// Author : 佐藤颯紀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "game_finish.h"
#include "manager.h"
#include "fade.h"
#include "polygon.h"
#include "resource_texture.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define FADE_TAIME (100)	// フェードするまでの間隔

//=============================================================================
// コンストラクタ
//=============================================================================
CGameFinish::CGameFinish()
{
	m_pPolygon = NULL;							// ポリゴン情報
	m_pos = VEC3_ZERO;							// 位置情報
	m_size = VEC3_ZERO;
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	// 色情報
	m_nCount = 0;								// カウンター
}

//=============================================================================
// デストラクタ
//=============================================================================
CGameFinish::~CGameFinish()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CGameFinish * CGameFinish::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CGameFinish *pFinish = NULL;

	// メモリの確保
	pFinish = new CGameFinish;

	// NULLチェック
	if (pFinish != NULL)
	{
		// 位置設定
		pFinish->m_pos = pos;
		// サイズ設定
		pFinish->m_size = size;
		// 初期化処理呼び出し
		pFinish->Init();
		// オブジェクトタイプ
		pFinish->SetPriority(OBJTYPE_UI_2);
	}

	return pFinish;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CGameFinish::Init(void)
{
	// 色設定
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// ポリゴンの生成
	m_pPolygon = CPolygon::Create(
		m_pos,
		m_size,
		m_col);

	m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_FINISH));

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CGameFinish::Uninit(void)
{
	if (m_pPolygon != NULL)
	{
		// ポリゴンの終了処理
		m_pPolygon->Uninit();

		// メモリの解放
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	// 開放処理
	Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CGameFinish::Update(void)
{
	// ポリゴンの更新処理
	m_pPolygon->Update();

	// 毎フレームごとにカウントを増やしていく
	m_nCount++;

	if (m_nCount == FADE_TAIME)
	{
		// リザルトに画面遷移
		CManager::GetFade()->SetFade(CManager::MODE_RESULT);
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CGameFinish::Draw(void)
{
	// ポリゴンの描画処理
	m_pPolygon->Draw();
}

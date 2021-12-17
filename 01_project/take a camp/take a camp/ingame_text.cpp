//=============================================================================
//
// インゲームのテキスト処理 [ingame_text.cpp]
// Author : 佐藤颯紀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "ingame_text.h"
#include "manager.h"
#include "polygon.h"
#include "resource_texture.h"

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CInGameText::CInGameText()
{
	m_pPolygon = NULL;							// ポリゴン情報
	m_pos = VEC3_ZERO;							// 位置情報
	m_size = VEC3_ZERO;							// サイズ
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	// 色情報
	m_nCount = 0;								// カウンター

}

//=============================================================================
// デストラクタ
//=============================================================================
CInGameText::~CInGameText()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CInGameText * CInGameText::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CInGameText *pInGameText = NULL;

	// メモリの確保
	pInGameText = new CInGameText; 
	
	// NULLチェック
	if (pInGameText != NULL)
	{
		// 位置設定
		pInGameText->m_pos = pos;
		// サイズ設定
		pInGameText->m_size = size;
		// 初期化処理呼び出し
		pInGameText->Init();
		// オブジェクトタイプ
		pInGameText->SetPriority(OBJTYPE_UI_2);
	}

	return pInGameText;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CInGameText::Init(void)
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
void CInGameText::Uninit(void)
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
void CInGameText::Update(void)
{
	// ポリゴンの更新処理
	m_pPolygon->Update();

	// 毎フレームごとにカウントを増やしていく
	m_nCount++;

	if (m_nCount == 80)
	{
		// 終了処理
		Uninit();
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CInGameText::Draw(void)
{
	// ポリゴンの描画処理
	m_pPolygon->Draw();
}
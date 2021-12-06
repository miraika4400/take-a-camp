//=============================================================================
//
// ゲーム開始の処理 [game_start.h]
// Author : 佐藤颯紀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "game_start.h"
#include "polygon.h"
#include "resource_texture.h"
#include "game.h"

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CGame_Start::CGame_Start()
{
	m_pPolygon = NULL;
	m_pos = VEC3_ZERO;
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_nCount = 0;
	m_bStart = false;
}

//=============================================================================
// デストラクタ
//=============================================================================
CGame_Start::~CGame_Start()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CGame_Start * CGame_Start::Create(D3DXVECTOR3 pos , D3DXVECTOR3 size,TYPE_START type)
{
	CGame_Start *pStart = NULL;

	// メモリの確保
	pStart = new CGame_Start;

	// NULLチェック
	if (pStart != NULL)
	{
		// 位置設定
		pStart->m_pos = pos;
		// サイズ設定
		pStart->m_size = size;
		// タイプ設定
		pStart->m_type = type;
		// 初期化処理呼び出し
		pStart->Init();

		// オブジェクトタイプ
		pStart->SetPriority(OBJTYPE_UI);
	}

	return pStart;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CGame_Start::Init(void)
{
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// ポリゴンの生成
	m_pPolygon = CPolygon::Create(
		m_pos,
		m_size,
		m_col);

	// readyなら
	if (m_type == TYPE_START_READEY)
	{
		m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TITLE));
	}

	// GOなら
	if (m_type == TYPE_START_GO)
	{
		m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTYRE_BUTTON_TUTORIAL));
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CGame_Start::Uninit(void)
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
void CGame_Start::Update(void)
{
	// ポリゴンの更新処理
	m_pPolygon->Update();

	// 毎フレームごとにカウントを増やしていく
	m_nCount++;

	if (m_type == TYPE_START_READEY)
	{
		// 表示を消す
		if (m_nCount == 10)
		{
			m_bStart = true;

			m_col.a = 0.0f;
		}
	}

	if (m_bStart == true)
	{
		Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 200.0f, 0.0f), D3DXVECTOR3(750.0f, 200.0f, 0.0f), CGame_Start::TYPE_START_GO);
	}

	if (m_type == TYPE_START_GO)
	{
		// 表示を消す
		if (m_nCount == 10)
		{
			// 終了処理
			Uninit();
			return;
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CGame_Start::Draw(void)
{
	// ポリゴンの描画処理
	m_pPolygon->Draw();
}


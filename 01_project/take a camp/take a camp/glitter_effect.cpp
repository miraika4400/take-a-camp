//=============================================================================
//
// キラキラ✧エフェクト [glitter_effect.cpp]
// Author : 吉田 悠人
//
//=============================================================================

//*****************************
// インクルード
//*****************************
#include "glitter_effect.h"

//*****************************
//マクロ定義
//*****************************
#define LIFE_DOWN	(60)							// ライフが何フレームで下がるか
#define MAX_SIZE	(D3DXVECTOR3(10.0f,10.0f,0.0f))	// 最大サイズ
#define MIN_SIZE	(D3DXVECTOR3(0.0f,0.0f,0.0f))	// 最小サイズ

//******************************
// コンストラクタ
//******************************
CGlitter::CGlitter()
{
	m_nLife = 0;
	m_nLifeCunt = 0;
	m_bDeath = false;
	m_nMidpoint = 0;
	m_nSizeFps = 0;
}

//******************************
// デストラクタ
//******************************
CGlitter::~CGlitter()
{
}

//******************************
// 生成処理
//******************************
void CGlitter::Create(D3DXVECTOR3 pos,int nLife, D3DXCOLOR col)
{
	//メモリ確保
	CGlitter* pGlitter = nullptr;
	pGlitter = new CGlitter;

	//NULLチェック
	if (pGlitter != nullptr)
	{
		//初期化処理
		pGlitter->Init();
		
		//位置設定
		pGlitter->SetPos(pos);
		//ライフ設定
		pGlitter->m_nLife = nLife;
		pGlitter->m_nMidpoint = nLife / 2;
		//カラー設定
		pGlitter->SetColor(col);
	}
}

//******************************
// 初期化処理
//******************************
HRESULT CGlitter::Init(void)
{
	//ビルボード初期化処理
	CBillboard::Init();
	//テクスチャ設定

	return E_NOTIMPL;
}

//******************************
// 終了処理
//******************************
void CGlitter::Update(void)
{
	//ライフダウン処理
	LifeDown();

	//大きさの処理
	SizeChange();

	//死亡フラグが立っているとき
	if (m_bDeath)
	{
		//終了処理
		Uninit();
	}
}

//*****************************
//　大きさ設定処理関数
//*****************************
void CGlitter::SizeChange(void)
{
	//大きさ取得
	D3DXVECTOR3 size = GetSize();

	m_nSizeFps++;
	
	if (m_nLifeCunt>m_nMidpoint)
	{
		size += MAX_SIZE / ((m_nMidpoint * LIFE_DOWN) - m_nSizeFps);
		m_nSizeFps = 0;
	}
	else
	{
		size += MIN_SIZE / ((m_nMidpoint * LIFE_DOWN) - m_nSizeFps);
		m_nSizeFps = 0;
	}
	
}

//*****************************
//　ライフダウン処理関数
// 一秒に1ライフを引く
//*****************************
void CGlitter::LifeDown(void)
{
	//カウントを進める
	m_nLifeCunt++;

	//一定の数値に達したら
	if (m_nLifeCunt >= LIFE_DOWN)
	{
		//初期化
		m_nLifeCunt = 0;
		//ライフダウン
		m_nLife--;

		//ライフが0以下になったら
		if (m_nLife <= 0)
		{
			//死亡フラグを立てる
			m_bDeath = true;
		}
	}
}

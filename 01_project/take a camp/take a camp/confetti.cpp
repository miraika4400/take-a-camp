//===================================================
//
// 紙吹雪処理 [confetti.cpp]
//    Author : 増澤 未来
//
//====================================================

//**********************************
//インクルード
//**********************************
#include "confetti.h"

//**********************************
//マクロ定義
//**********************************
#define MIN_SIZE (5.0f)          // 最小サイズ
#define RAND_SIZE_AMPLITUDE (10) // 乱数のふり幅
#define ADJUST_RAND 100.0f       // 乱数生成時調整値


//==================================
// コンストラクタ
//==================================
CConfetti::CConfetti() :CScene2d(OBJTYPE_EFFECT_2)
{
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_moveDist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);;
}

//==================================
// デストラクタ
//==================================
CConfetti::~CConfetti()
{
}

//==================================
// クリエイト
//==================================
CConfetti * CConfetti::Create(void)
{
	// メモリの確保
	CConfetti *pConfetti = NULL;
	pConfetti = new CConfetti;

	//NULLチェック
	if (pConfetti != NULL)
	{
		// 初期化処理
		pConfetti->Init();
		// オブジェクトタイプの設定
		pConfetti->SetPriority(OBJTYPE_EFFECT_2);
	}
	return pConfetti;
}

//==================================
// 初期化処理
//==================================
HRESULT CConfetti::Init(void)
{
	CScene2d::Create();

	float fRandSize = (float)(rand() % (RAND_SIZE_AMPLITUDE*(int)ADJUST_RAND));
	fRandSize = MIN_SIZE + (fRandSize / ADJUST_RAND);

	return S_OK;
}

//==================================
// 更新処理
//==================================
void CConfetti::Update(void)
{
}

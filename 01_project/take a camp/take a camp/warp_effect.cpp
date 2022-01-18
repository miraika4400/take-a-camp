//=============================================================================
//
// ワープエフェクト [warp_effect.cpp]
// Author : 吉田 悠人
//
//=============================================================================

//*****************************
// インクルード
//*****************************
#include "warp_effect.h"

//******************************
// コンストラクタ
//******************************
CWarpEffect::CWarpEffect()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//******************************
// デストラクタ
//******************************
CWarpEffect::~CWarpEffect()
{

}

//******************************
// クラス生成
//******************************
void CWarpEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 GoalPos, D3DXCOLOR col)
{
	//メモリ確保
	CWarpEffect* pWarpEffect = nullptr;
	pWarpEffect = new CWarpEffect;

	//NULLチェック
	if (pWarpEffect != nullptr)
	{
		//初期化処理
		pWarpEffect->Init();

		//位置設定
		pWarpEffect->m_pos = pos;
		//目的地設定
		pWarpEffect->m_GoalPos = GoalPos;
		//色設定
		pWarpEffect->m_col = col;

	}
}

//******************************
// 初期化処理
//******************************
HRESULT CWarpEffect::Init(void)
{
	return E_NOTIMPL;
}

//******************************
// 終了処理
//******************************
void CWarpEffect::Uninit(void)
{
}

//******************************
// 更新処理
//******************************
void CWarpEffect::Update(void)
{
}

//******************************
// 描画処理
//******************************
void CWarpEffect::Draw(void)
{
}

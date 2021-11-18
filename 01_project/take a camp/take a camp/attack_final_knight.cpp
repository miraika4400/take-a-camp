//=============================================================================
//
// ナイトの必殺技範囲タイプの処理 [attack_final_knight.cpp]
// Author : 佐藤颯紀
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_final_knight.h"
#include "tile.h"
#include "player.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackFinalknight::CAttackFinalknight()
{
	m_nAttackFinalCount = 0;
	m_nType = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackFinalknight::~CAttackFinalknight()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CAttackFinalknight * CAttackFinalknight::Create(CPlayer* pPlayer)
{
	// メモリ確保
	CAttackFinalknight* pAttackFinalKnight = NULL;
	pAttackFinalKnight = new CAttackFinalknight;

	if (pAttackFinalKnight != NULL)
	{
		pAttackFinalKnight->SetPlayer(pPlayer);	// プレイヤークラス取得
		pAttackFinalKnight->SetPos(pPlayer->GetPos());	// 位置設定
		pAttackFinalKnight->SetRot(pPlayer->GetRot());	// 向き設定
		pAttackFinalKnight->SetAttackFinalType(CResourceCharacter::CHARACTER_KNIGHT);	// タイプ設定
		pAttackFinalKnight->Init();				// 初期化処理
	}
	return pAttackFinalKnight;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CAttackFinalknight::Init(void)
{
	// 初期化処理
	CAttackFinal::Init();

	return S_OK;
}

//=============================================================================
// 必殺生成関数
//=============================================================================
void CAttackFinalknight::AttackFinalCreate(void)
{
	// 必殺フラグが立っているか
	if (GetAttackFinalFlag())
	{
		// カウントアップ
		m_nAttackFinalCount++;

		VisualizationAttackArea(m_nType);

		// カウントが一定になったら
		if (m_nAttackFinalCount >= GetFinalAttackSquare().nAttackFrame[m_nType])
		{
			// 必殺処理
			AttackFinal(m_nType);
			// タイプが一定になったら
			if (m_nType == MAX_FINAL_HIT_TYPE)
			{
				// 状態の初期化
				SetState(FINAL_ATTACK_STATE_NOMAL);
				// フラグの初期化
				SetAttackFinalFlag(false);
				// タイプの初期化
				m_nType = 0;
			}
			else
			{
				// 次の攻撃タイプへ
				m_nType++;
			}
			// カウント初期化
			m_nAttackFinalCount = 0;
		}
	}
}
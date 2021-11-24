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
		pAttackFinalKnight->SetAttackType(CResourceCharacter::CHARACTER_KNIGHT);	// タイプ設定
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
	CAttackBased::Init();

	return S_OK;
}

//=============================================================================
// 必殺生成関数
//=============================================================================
void CAttackFinalknight::AttackCreate(void)
{
	// 必殺フラグが立っているか
	if (GetState() == ATTACK_STATE_ATTACK)
	{
		// カウントアップ
		m_nAttackFinalCount++;

		VisualizationAttackArea(m_nType);

		// カウントが一定になったら
		if (m_nAttackFinalCount >= GetAttackSquare().nAttackFrame[m_nType])
		{
			// 必殺処理
			Attack(m_nType);
			// タイプが一定になったら
			if (m_nType == MAX_HIT_TYPE)
			{
				//フラグの初期化
				SetState(ATTACK_STATE_NORMAL);
				//タイプ初期化
				m_nType = 0;
				//レベルの初期化
				CAttackBased::SetLevel(0);
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
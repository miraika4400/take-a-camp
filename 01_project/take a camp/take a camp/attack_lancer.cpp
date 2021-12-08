//=============================================================================
//
// 攻撃範囲タイプ騎士 [attack_knight.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_lancer.h"
#include "tile.h"
#include "player.h"
#include "attack.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackLancer::CAttackLancer()
{
	m_nAttackCount = 0;
	m_nType = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackLancer::~CAttackLancer()
{
}

//=============================================================================
// 生成処理
//=============================================================================
CAttackLancer * CAttackLancer::Create(CPlayer* pPlayer)
{
	//メモリ確保
	CAttackLancer* pAttackLancer = NULL;
	pAttackLancer = new CAttackLancer;

	if (pAttackLancer != NULL)
	{
		pAttackLancer->SetType(CResourceCharacter::CHARACTER_LANCER);
		pAttackLancer->SetPlayer(pPlayer);	// プレイヤークラス取得
		pAttackLancer->Init();				// 初期化処理
	}
	return pAttackLancer;
}

//=============================================================================
// 攻撃生成関数
//=============================================================================
void CAttackLancer::AttackCreate(void)
{
	//攻撃フラグが立っているか
	if (GetState() == ATTACK_STATE_ATTACK
		|| GetState() == ATTACK_STATE_FINALATTACK)
	{
		//カウントアップ
		m_nAttackCount++;

		// 攻撃範囲の可視化
		VisualizationAttackArea(m_nType);

		//カウントが一定になったら
		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
		{
			//攻撃処理
			Attack(m_nType);
			//タイプが一定になったら
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
				//次の攻撃タイプへ
				m_nType++;
			}
			//カウント初期化
			m_nAttackCount = 0;

		}
	}
}
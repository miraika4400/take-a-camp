//=============================================================================
//
// 攻撃範囲タイプ魔法使い [attack_wizard.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_wizard.h"
#include "tile.h"
#include "player.h"
#include "attack.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackWizard::CAttackWizard()
{
	m_nAttackCount = 0;
	m_nType = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackWizard::~CAttackWizard()
{
}

//=============================================================================
// 生成処理
//=============================================================================
CAttackWizard * CAttackWizard::Create(CPlayer* pPlayer)
{
	//メモリ確保
	CAttackWizard* pAttackWizard = NULL;
	pAttackWizard = new CAttackWizard;

	if (pAttackWizard != NULL)
	{
		pAttackWizard->SetType(CResourceCharacter::CHARACTER_WIZARD);
		pAttackWizard->SetPlayer(pPlayer);	// プレイヤークラス取得
		pAttackWizard->Init();				// 初期化処理
	}
	return pAttackWizard;
}

//=============================================================================
// 攻撃生成関数
//=============================================================================
void CAttackWizard::AttackCreate(void)
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
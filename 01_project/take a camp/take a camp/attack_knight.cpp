//=============================================================================
//
// 攻撃範囲タイプ騎士 [attack_knight.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_knight.h"
#include "tile.h"
#include "player.h"
#include "attack.h"
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"


//=============================================================================
// コンストラクタ
//=============================================================================
CAttackKnight::CAttackKnight()
{
	m_nAttackCount = 0;
	m_nType = 0;

}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackKnight::~CAttackKnight()
{
}

//=============================================================================
// 生成処理
//=============================================================================
CAttackKnight * CAttackKnight::Create(CPlayer* pPlayer)
{
	//メモリ確保
	CAttackKnight* pAttackKnight = NULL;
	pAttackKnight = new CAttackKnight;

	if (pAttackKnight != NULL)
	{
		pAttackKnight->SetType(CResourceCharacter::CHARACTER_KNIGHT);
		pAttackKnight->SetPlayer(pPlayer);	// プレイヤークラス取得
		pAttackKnight->Init();				// 初期化処理
	}
	return pAttackKnight;
}

//=============================================================================
// 攻撃生成関数
//=============================================================================
void CAttackKnight::AttackCreate(void)
{	
	//プレイヤーのポインタ
	CPlayer *pPlaryer = GetPlayer();
	
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
	
			//スキルエフェクトの生成
			
				for (int nCnt = 0; nCnt < GetAttackSquare().nMaxHitRange; nCnt++)
				{
					int n = GetAttackSquare().SquareData[nCnt].RangeType;

					if (GetAttackSquare().SquareData[nCnt].RangeType == m_nType + 2)
					{
						//行列計算
						D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
						D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nCnt].AttackPos * TILE_ONE_SIDE;
						CreatePos.x = ((cosf(pPlaryer->GetRot().y)*AttackPos.x) + (sinf(pPlaryer->GetRot().y)*AttackPos.z));
						CreatePos.y = 1 * AttackPos.y;
						CreatePos.z = ((-sinf(pPlaryer->GetRot().y)*AttackPos.x) + (cosf(pPlaryer->GetRot().y)*AttackPos.z));

						//エフェクト生成
						CSkill_effect::Create(pPlaryer->GetPos() + CreatePos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
						GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
						GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_KNIGHT);
					}
				}
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
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
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"
#include "sound.h"
#include "particle.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackLancer::CAttackLancer()
{
    /*m_nAttackCount = 0;
    m_nType = 0;*/
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
// エフェクト生成
//=============================================================================
void CAttackLancer::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{
	CPlayer *pPlayer = GetPlayer();
	//エフェクト生成
   // CSkill_effect::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, LANCER_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(),0),
	//GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1),
	//GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 2), LANCER_EFFECT_LIFE, CSkill_effect::SKILLTYPE_LANCER, GetPlayer());
	if (state == CAttackBased::ATTACK_STATE_FINALATTACK)
	{
		D3DXVECTOR3 rot = pPlayer->GetRotDest();
		float fAngle = D3DXToDegree(rot.y);
		if ((int)fAngle / 90 % 2 == 0)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);

		}
		else if ((int)fAngle / 90 % 2 == 1 || (int)fAngle / 90 % 2 == -1)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y) + 180.0f, pPlayer, CParticle::PARTICLE_THUKI);
		}
		else
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);

		}
	}
	if (state == CAttackBased::ATTACK_STATE_ATTACK)
	{
		D3DXVECTOR3 rot = pPlayer->GetRotDest();
		float fAngle = D3DXToDegree(rot.y);
		if ((int)fAngle / 90 % 2 == 0)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);

		}
		else if ((int)fAngle / 90 % 2 == 1 || (int)fAngle / 90 % 2 == -1)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y) + 180.0f, pPlayer, CParticle::PARTICLE_THUKI);
		}
		else
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);

		}
	}

}

//=============================================================================
// SE再生
//=============================================================================
void CAttackLancer::PlaySE(void)
{
    // サウンド情報の取得
    CSound *pSound = CManager::GetSound();

    // レベル情報の取得
    int nLevel = GetLevel();

    // 通常攻撃なら
    if (nLevel < MAX_LEVEL)
    {
        // SE再生
        pSound->Play(CSound::LABEL_SE_YARI_ATTACK);
    }
    //　必殺なら
    else
    {
        // SE再生
        pSound->Play(CSound::LABEL_SE_YARI_FINALATTACK);
    }
}

////=============================================================================
//// 攻撃生成関数
////=============================================================================
//void CAttackLancer::AttackCreate(void)
//{
//	//プレイヤーのポインタ
//	CPlayer *pPlaryer = GetPlayer();
//
//	//攻撃フラグが立っているか
//	if (GetState() == ATTACK_STATE_ATTACK
//		|| GetState() == ATTACK_STATE_FINALATTACK)
//	{
//		//カウントアップ
//		m_nAttackCount++;
//
//		// 攻撃範囲の可視化
//		VisualizationAttackArea(m_nType);
//
//		//スキルエフェクトの生成
//		if (m_nType == MIN_HIT_TYPE)
//		{
//			for (int nCnt = 0; nCnt < GetAttackSquare().nMaxHitRange; nCnt++)
//			{
//
//				//行列計算
//				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//				D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nCnt].AttackPos * TILE_ONE_SIDE;
//				CreatePos.x = ((cosf(pPlaryer->GetRot().y)*AttackPos.x) + (sinf(pPlaryer->GetRot().y)*AttackPos.z));
//				CreatePos.y = 1 * AttackPos.y;
//				CreatePos.z = ((-sinf(pPlaryer->GetRot().y)*AttackPos.x) + (cosf(pPlaryer->GetRot().y)*AttackPos.z));
//
//				//エフェクト生成
//				CSkill_effect::Create(pPlaryer->GetPos() + CreatePos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
//					GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
//					GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_KNIGHT);
//			}
//
//		}
//
//		//カウントが一定になったら
//		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
//		{
//			//攻撃処理
//			Attack(m_nType);
//			//タイプが一定になったら
//			if (m_nType == MAX_HIT_TYPE)
//			{
//				//フラグの初期化
//				SetState(ATTACK_STATE_NORMAL);
//				//タイプ初期化
//				m_nType = 0;
//				//レベルの初期化
//				CAttackBased::SetLevel(0);
//			}
//			else
//			{
//				//次の攻撃タイプへ
//				m_nType++;
//			}
//			//カウント初期化
//			m_nAttackCount = 0;
//
//		}
//	}
//}
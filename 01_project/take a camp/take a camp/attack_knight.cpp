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
		pAttackKnight->SetPlayer(pPlayer);	//プレイヤークラス取得
		pAttackKnight->SetRot(pPlayer->GetRot());	//向き設定
		pAttackKnight->SetPos(pPlayer->GetPos());	//位置設定
		pAttackKnight->SetAttackType(CResourceCharacter::CHARACTER_KNIGHT);	//タイプセット
		pAttackKnight->Init();		//初期化処理
	}
	return pAttackKnight;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CAttackKnight::Init(void)
{
	CAttackBased::Init();
	return S_OK;
}

//=============================================================================
// 攻撃生成関数
//=============================================================================
void CAttackKnight::AttackCreate(void)
{
	//攻撃フラグが立っているか
	if (GetState() == ATTACK_STATE_ATTACK)
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
//=============================================================================
//
// 攻撃範囲タイプ1 [attack_1.cpp]
// Author : 吉田悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_1.h"
#include "tile.h"
#include "player.h"
//=============================================================================
// マクロ定義
//=============================================================================
#define ATTACK_COUNT (60*0.4f)

#define ATTACK_COUNT_1 (60*0)
#define ATTACK_COUNT_2 (60*0.4f)
#define ATTACK_COUNT_3 (60*0.7f)
#define ATTACK_COUNT_4 (60*1)

//=============================================================================
// コンストラクタ
//=============================================================================
CAttack1::CAttack1()
{
	m_nAttackCount = 0;
	m_nType = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttack1::~CAttack1()
{
}

//=============================================================================
// 生成処理
//=============================================================================
CAttack1 * CAttack1::Create(CPlayer* pPlayer)
{
	//メモリ確保
	CAttack1* pAttack1 = NULL;
	pAttack1 = new CAttack1;

	if (pAttack1 != NULL)
	{
		pAttack1->SetPlayer(pPlayer);	//プレイヤークラス取得
		pAttack1->SetRot(pPlayer->GetRot());	//向き設定
		pAttack1->SetPos(pPlayer->GetPos());	//位置設定
		pAttack1->SetAttackType(CAttackManager::ATTACK_TYPE_1);	//タイプセット
		pAttack1->Init();		//初期化処理
	}
	return pAttack1;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CAttack1::Init(void)
{
	CAttackBased::Init();
	return S_OK;
}

//=============================================================================
// 更新関数
//=============================================================================
void CAttack1::Update(void)
{
	AttackCreate();
}

//=============================================================================
// 攻撃生成関数
//=============================================================================
void CAttack1::AttackCreate(void)
{
	//攻撃フラグが立っているか
	if (GetAttackFlag())
	{
		//カウントアップ
		m_nAttackCount++;

		//カウントが一定になったら
		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
		{
			//攻撃処理
			Attack(m_nType);
			//タイプが一定になったら
			if (m_nType == MAX_HIT_TYPE)
			{
				//フラグの初期化
				SetAttackFlag(false);
				//タイプ初期化
				m_nType = 0;
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
//=============================================================================
//
// 攻撃範囲タイプ奇術師 [attack_magician.cpp]
// Author : 増澤 未来
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_magician.h"
#include "tile.h"
#include "player.h"
#include "attack.h"
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"

//*****************************
//マクロ定義
//*****************************
#define TRUMP_EFFECT_POS (D3DXVECTOR3(0.0f,5.0f,0.0f))	// スキル位置
#define TRUMP_EFFECT_SIZE (D3DXVECTOR3(4.0f,3.0f,0.0f))	// スキルサイズ
//=============================================================================
// コンストラクタ
//=============================================================================
CAttackMagician::CAttackMagician()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackMagician::~CAttackMagician()
{
}

//=============================================================================
// 生成処理
//=============================================================================
CAttackMagician * CAttackMagician::Create(CPlayer* pPlayer)
{
	//メモリ確保
	CAttackMagician* pAttackKnight = NULL;
	pAttackKnight = new CAttackMagician;

	if (pAttackKnight != NULL)
	{
		pAttackKnight->SetType(CResourceCharacter::CHARACTER_MAGICIAN);
		pAttackKnight->SetPlayer(pPlayer);	// プレイヤークラス取得
		pAttackKnight->Init();				// 初期化処理
	}
	return pAttackKnight;
}

//=============================================================================
// エフェクト生成
//=============================================================================
void CAttackMagician::CreateEffect(D3DXVECTOR3 pos)
{
	//プレイヤーのポインタ
	CPlayer *pPlaryer = GetPlayer();
	//エフェクト生成
	CSkill_effect::Create(pPlaryer->GetPos() + pos + TRUMP_EFFECT_POS, TRUMP_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_MAGICIAN);
}

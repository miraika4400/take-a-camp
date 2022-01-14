//=============================================================================
//
// スキルサークル処理 [skill_effect.cpp]
// Author : 齋藤大行
//
//=============================================================================

//=============================================================================
//インクルードファイル
//=============================================================================
#include "skill_circle.h"
#include "skill_effect.h"
#include "base_Cylinder.h"
#include "resource_texture.h"
#include "manager.h"
#include "renderer.h"
#include "particle.h"

//=============================================================================
// マクロ定義
//=============================================================================



//=============================================================================
//静的メンバー変数
//=============================================================================


CSkill_effect::CSkill_effect()
{
	m_type = SKILLTYPE_KNIGHT;
}

CSkill_effect::~CSkill_effect()
{
}

void CSkill_effect::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col1, const D3DXCOLOR col2, const D3DXCOLOR col3,const int nlife, const SKILLTYPE type ,CPlayer * pPlayer)
{	

	switch (type)
	{
	case SKILLTYPE_KNIGHT:

		CSkill_circle::Create(pos, size+ NORMAL_SKIIL_SIZESHIFT, col1, nlife, CSkill_circle::EFFECTTYPE_SKIIL, pPlayer);
		CSkill_circle::Create(pos, size , col3, nlife, CSkill_circle::EFFECTTYPE_SKIILMINI, pPlayer);
		break;

	case SKILLTYPE_ARCHER:
		break;

	case SKILLTYPE_WIZARD:
		//CParticle::Create(pos + EXPLOSION_SKIIL_POSSHIFT + EXPLOSION_SKIIL_SHADOW_POSSHIFT, EXPLOSION_SKIIL_MOVE, size - EXPLOSION_SKIIL_SIZESHIFT, nlife, col1, 0.05, CParticle::PARTICLE_METEOR_SHADOW,pPlayer);
		//CParticle::Create(pos + EXPLOSION_SKIIL_POSSHIFT, EXPLOSION_SKIIL_MOVE, size, nlife, col1, 0.05, CParticle::PARTICLE_METEOR,pPlayer);

		CSkill_circle::Create(pos + EXPLOSION_SKIIL_METEOR_IMPACT_POS, size - EXPLOSION_SKIIL_METEOR_IMPACT_SIZE + EXPLOSION_SKIIL_METEOR_IMPACT_SIZESHIFT, col3, nlife, CSkill_circle::EFFECTTYPE_IMPACT, pPlayer);

		break;

	case SKILLTYPE_WIZARD_FINALATTACK:
		CSkill_circle::Create(pos, size - EXPLOSION_SKIIL_CENTER_SIZE + EXPLOSION_SKIIL_CENTER_SIZESHIFT, col3, nlife, CSkill_circle::EFFECTTYPE_METEOR_CENTER, pPlayer);
		CSkill_circle::Create(pos, size + EXPLOSION_SKIIL_IMPACT_SIZE - EXPLOSION_SKIIL_IMPACT_SIZESHIFT, col2, nlife, CSkill_circle::EFFECTTYPE_METEOR_IMPACT, pPlayer);
		CSkill_circle::Create(pos, size, col3, nlife, CSkill_circle::EFFECTTYPE_METEOR, pPlayer);

		break;

	case SKILLTYPE_LANCER:

		break;

	case SKILLTYPE_MAGICIAN:

		break;

	case SKILLTYPE_THIER:
		

				CParticle::Create(pos + SLASH_SKIIL_POSSHIFT, EXPLOSION_SKIIL_MOVE, size, nlife, col3, 0.05, CParticle::PARTICLE_SLASH);
		
		break;


	}
}

//=============================================================================
//
// スキルサークル処理 [skill_circle.cpp]
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

//=============================================================================
//静的メンバー変数
//=============================================================================


CSkill_effect::CSkill_effect(int nPliority)
{
}

CSkill_effect::~CSkill_effect()
{
}

CSkill_effect * CSkill_effect::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col1, const D3DXCOLOR col2, const D3DXCOLOR col3, const SKILLTYPE type)
{	
	CSkill_effect * pSkill_effect;
	pSkill_effect = new CSkill_effect;
	pSkill_effect->m_type = type;
	pSkill_effect->Init();

	switch (pSkill_effect->m_type)
	{
	case SKILLTYPE_KNIGHT:

		CSkill_circle::Create(pos, size, col1, CSkill_circle::EFFECTTYPE_SKIIL);
		CSkill_circle::Create(pos, size + D3DXVECTOR3(3.0f, 0.0f, 3.0f), col2, CSkill_circle::EFFECTTYPE_SKIILMINI);
		break;

	case SKILLTYPE_ARCHER:

		break;

	case SKILLTYPE_WIZARD:

		break;

	case SKILLTYPE_LANCER:

		break;

	case SKILLTYPE_MAGICIAN:

		break;

	case SKILLTYPE_THIER:

		break;

	default:
		break;
	}

	return pSkill_effect;
}

HRESULT CSkill_effect::Init(void)
{
	
	if (FAILED(CSkill_circle::Init()))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CSkill_effect::Uninit(void)
{
	CSkill_circle::Uninit();
}

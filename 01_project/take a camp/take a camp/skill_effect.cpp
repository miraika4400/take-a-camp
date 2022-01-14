//=============================================================================
//
// �X�L���G�t�F�N�g��` [skill_effect.cpp]
// Author : �V����s
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "skill_circle.h"
#include "skill_effect.h"
#include "base_Cylinder.h"
#include "resource_texture.h"
#include "manager.h"
#include "renderer.h"
#include "skill_trump.h"
#include "skill_arrow_rain.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define KNIGHT_POSSHIFT (D3DXVECTOR3(3.0f, 0.0f, 3.0f))
#define ARCHER_CREATE_POS (D3DXVECTOR3(0.0f, 25.0f, 0.0f))	//�|���̃G�t�F�N�g�����ʒu


//=============================================================================
//�ÓI�����o�[�ϐ�
//=============================================================================



//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSkill_effect::CSkill_effect()
{
	m_type = SKILLTYPE_KNIGHT;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSkill_effect::~CSkill_effect()
{
}

//=============================================================================
// ��������
//=============================================================================
void CSkill_effect::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col1, const D3DXCOLOR col2, const D3DXCOLOR col3, const SKILLTYPE type)
{	
	//�^�C�v���Ƃɐ�������
	switch (type)
	{
	case SKILLTYPE_KNIGHT:
		CSkill_circle::Create(pos, size, col1, CSkill_circle::EFFECTTYPE_SKIIL);
		CSkill_circle::Create(pos, size + KNIGHT_POSSHIFT, col2, CSkill_circle::EFFECTTYPE_SKIILMINI);
		break;

	case SKILLTYPE_ARCHER:
		CSkillArrowRain::Create(pos + ARCHER_CREATE_POS, col1);
		break;

	case SKILLTYPE_WIZARD:

		break;

	case SKILLTYPE_LANCER:

		break;

	case SKILLTYPE_MAGICIAN:
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(-45), D3DXToRadian(60)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(-45), D3DXToRadian(50)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(-45), D3DXToRadian(40)), col1);
		
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(45), D3DXToRadian(60)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(45), D3DXToRadian(50)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(45), D3DXToRadian(40)), col1);

		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(135), D3DXToRadian(60)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(135), D3DXToRadian(50)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(135), D3DXToRadian(40)), col1);
		
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(-135), D3DXToRadian(60)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(-135), D3DXToRadian(50)), col1);
		CSkillTrump::Create(D3DXVECTOR3(pos.x, pos.y + 5, pos.z), size, D3DXVECTOR3(0, D3DXToRadian(-135), D3DXToRadian(40)), col1);

		break;

	case SKILLTYPE_THIER:

		break;

	default:
		break;
	}
}

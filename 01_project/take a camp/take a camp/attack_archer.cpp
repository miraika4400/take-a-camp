//=============================================================================
//
// �U���͈̓^�C�v�|�g�� [attack_archer.cpp]
// Author : ���V ����
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_archer.h"
#include "tile.h"
#include "player.h"
#include "attack.h"
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"


//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackArcher::CAttackArcher()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackArcher::~CAttackArcher()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackArcher * CAttackArcher::Create(CPlayer* pPlayer)
{
	//�������m��
	CAttackArcher* pAttackKnight = NULL;
	pAttackKnight = new CAttackArcher;

	if (pAttackKnight != NULL)
	{
		pAttackKnight->SetType(CResourceCharacter::CHARACTER_ARCHER);
		pAttackKnight->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackKnight->Init();				// ����������
	}
	return pAttackKnight;
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================
void CAttackArcher::CreateEffect(D3DXVECTOR3 pos)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();
	//�G�t�F�N�g����
	CSkill_effect::Create(pPlaryer->GetPos() + pos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
	GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
	GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), ARCHER_EFFECT_LIFE , CSkill_effect::SKILLTYPE_KNIGHT);
	
}

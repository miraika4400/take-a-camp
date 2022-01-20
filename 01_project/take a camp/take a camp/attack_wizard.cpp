//=============================================================================
//
// �U���͈̓^�C�v���@�g�� [attack_wizard.cpp]
// Author : �V����s
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_wizard.h"
#include "tile.h"
#include "player.h"
#include "attack.h"
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"
#include "sound.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackWizard::CAttackWizard()
{
	/*m_nAttackCount = 0;
	m_nType = 0;*/
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackWizard::~CAttackWizard()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackWizard * CAttackWizard::Create(CPlayer* pPlayer)
{

	//�������m��
	CAttackWizard* pAttackWizard = NULL;
	pAttackWizard = new CAttackWizard;

	if (pAttackWizard != NULL)
	{
		pAttackWizard->SetType(CResourceCharacter::CHARACTER_WIZARD);
		pAttackWizard->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackWizard->Init();				// ����������
	}
	return pAttackWizard;
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================

void CAttackWizard::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{

	if (state == CAttackBased::ATTACK_STATE_FINALATTACK)
	{
		CPlayer *pPlaryer = GetPlayer();
		//�G�t�F�N�g����
		CSkill_effect::Create(pPlaryer->GetPos() + pos + WIZARD_EFFECT_POS, WIZARD_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 0),
			GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 1),
			GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 2), WIZARD_EFFECT_LIFE, CSkill_effect::SKILLTYPE_WIZARD_FINALATTACK, GetPlayer());
	}
	if (state == CAttackBased::ATTACK_STATE_ATTACK)
	{
		CPlayer *pPlaryer = GetPlayer();
		//�G�t�F�N�g����
		CSkill_effect::Create(pPlaryer->GetPos() + pos + WIZARD_EFFECT_POS, WIZARD_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 0),
			GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 1),
			GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 2), WIZARD_EFFECT_LIFE, CSkill_effect::SKILLTYPE_WIZARD, GetPlayer());
	}

}
//=============================================================================
// SE�Đ�
// Author:�����D�I
//=============================================================================
void CAttackWizard::PlaySE(void)
{
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// ���x�����̎擾
	int nLevel = GetLevel();

	// �ʏ�U���Ȃ�
	if (nLevel < MAX_LEVEL)
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_MAHOU_ATTACK);
	}
	//�@�K�E�Ȃ�
	else
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_MAHOU_FINALATTACK);
	}
}

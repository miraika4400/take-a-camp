//=============================================================================
//
// �U���͈̓^�C�v��p�t [attack_magician.cpp]
// Author : ���V ����
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_magician.h"
#include "tile.h"
#include "player.h"
#include "attack.h"
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"
#include "sound.h"

//*****************************
//�}�N����`
//*****************************
#define TRUMP_EFFECT_POS (D3DXVECTOR3(0.0f,5.0f,0.0f))	// �X�L���ʒu
#define TRUMP_EFFECT_SIZE (D3DXVECTOR3(4.0f,3.0f,0.0f))	// �X�L���T�C�Y
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackMagician::CAttackMagician()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackMagician::~CAttackMagician()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackMagician * CAttackMagician::Create(CPlayer* pPlayer)
{
	//�������m��
	CAttackMagician* pAttackKnight = NULL;
	pAttackKnight = new CAttackMagician;

	if (pAttackKnight != NULL)
	{
		pAttackKnight->SetType(CResourceCharacter::CHARACTER_MAGICIAN);
		pAttackKnight->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackKnight->Init();				// ����������
	}
	return pAttackKnight;
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================
void CAttackMagician::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();
	//�G�t�F�N�g����
	CSkill_effect::Create(pPlaryer->GetPos() + pos + TRUMP_EFFECT_POS, TRUMP_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), MAGICIAN_EFFECT_LIFE, CSkill_effect::SKILLTYPE_MAGICIAN, GetPlayer());
}

//=============================================================================
// SE�Đ�
// Author:�����D�I
//=============================================================================
void CAttackMagician::PlaySE(void)
{
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// SE�Đ�
	pSound->Play(CSound::LABEL_SE_KIJUTUSI_ATTACK);
}


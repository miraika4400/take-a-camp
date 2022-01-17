//=============================================================================
//
// �U���͈̓^�C�v���� [attack_knight.cpp]
// Author : ���V ����
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_thief.h"
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
CAttackThief::CAttackThief()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackThief::~CAttackThief()
{
	
	
}

//=============================================================================
// ��������
//=============================================================================
CAttackThief * CAttackThief::Create(CPlayer* pPlayer)
{
	//�������m��
	CAttackThief* pAttackKnight = NULL;
	pAttackKnight = new CAttackThief;

	if (pAttackKnight != NULL)
	{
		pAttackKnight->SetType(CResourceCharacter::CHARACTER_THIEF);
		pAttackKnight->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackKnight->Init();				// ����������
	}
	return pAttackKnight;
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================
void CAttackThief::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();
	//�G�t�F�N�g����
	CSkill_effect::Create(pPlaryer->GetPos() + pos + THIEF_EFFECT_POS, THIEF_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 0),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(),1),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(),2), THIER_EFFECT_LIFE, CSkill_effect::SKILLTYPE_THIER, GetPlayer());
}

//=============================================================================
// SE�Đ�
//=============================================================================
void CAttackThief::PlaySE(void)
{
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// ���x�����̎擾
	int nLevel = GetLevel();

	// �ʏ�U���Ȃ�
	if (nLevel < MAX_LEVEL)
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_TOZOKU_ATTACK);
	}
	//�@�K�E�Ȃ�
	else
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_TOZOKU_FINALATTACK);
	}
}
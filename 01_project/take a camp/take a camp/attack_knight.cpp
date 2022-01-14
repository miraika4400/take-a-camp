//=============================================================================
//
// �U���͈̓^�C�v�R�m [attack_knight.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_knight.h"
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
CAttackKnight::CAttackKnight()
{
	/*m_nAttackCount = 0;
	m_nType = 0;*/
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackKnight::~CAttackKnight()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackKnight * CAttackKnight::Create(CPlayer* pPlayer)
{
	//�������m��
	CAttackKnight* pAttackKnight = NULL;
	pAttackKnight = new CAttackKnight;

	if (pAttackKnight != NULL)
	{
		pAttackKnight->SetType(CResourceCharacter::CHARACTER_KNIGHT);
		pAttackKnight->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackKnight->Init();				// ����������
	}
	return pAttackKnight;
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================
void CAttackKnight::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();
	int nLevel = GetLevel();

	//�G�t�F�N�g����
	CSkill_effect::Create(pPlaryer->GetPos() + pos + KNIGHT_EFFECT_POS, KNIGHT_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 0),
	GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 1),
	GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 2), KNIGHT_EFFECT_LIFE, CSkill_effect::SKILLTYPE_KNIGHT, GetPlayer());
}

//=============================================================================
// SE�Đ�
//=============================================================================
void CAttackKnight::PlaySE(void)
{
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// ���x�����̎擾
	int nLevel = GetLevel();

	// �ʏ�U���Ȃ�
	if (nLevel < MAX_LEVEL)
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_KENSI_ATTACK);
	}
	//�@�K�E�Ȃ�
	else
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_KENSI_FINALATTACK);
	}

}


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
#include "skill_arrow.h"
#include "sound.h"

//*****************************
//�}�N����`
//*****************************
#define ARROW_LIFE (60*3)

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackArcher::CAttackArcher()
{
	m_pSkillArrow = nullptr;
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
	if (GetState() == ATTACK_STATE_FINALATTACK)
	{
		//�G�t�F�N�g����
		CSkill_effect::Create(pPlaryer->GetPos() + pos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 1),
			GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 2),
			GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 3), CSkill_effect::SKILLTYPE_ARCHER);

	}
}

//=============================================================================
// �G�t�F�N�g(���)����
//=============================================================================
void CAttackArcher::OnceEffect(D3DXVECTOR3 pos)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();

	if (GetState() == ATTACK_STATE_ATTACK)
	{
		D3DXVECTOR3 rot = pPlaryer->GetRotDest();
		//��̃G�t�F�N�g����
		CSkillArrow::Create(pPlaryer->GetPos() + D3DXVECTOR3(0.0f, 10.0f, 0.0f), D3DXVECTOR3(cosf(rot.y + D3DXToRadian(90))*3.0f, 0.0f, -sinf(rot.y + D3DXToRadian(90))*3.0f), D3DXToDegree(rot.y), GetAttackSquare().nMaxHitRange,GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()));
	}
}


//=============================================================================
// SE�Đ�
//=============================================================================
void CAttackArcher::PlaySE(void)
{
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// ���x�����̎擾
	int nLevel = GetLevel();

	// �ʏ�U���Ȃ�
	if (nLevel < MAX_LEVEL)
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_YUMI_ATTACK);
	}
	//�@�K�E�Ȃ�
	else
	{
		// SE�Đ�
		pSound->Play(CSound::LABEL_SE_YUMI_FINALATTACK);
	}

}


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
void CAttackKnight::CreateEffect(D3DXVECTOR3 pos)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();
	int nLevel = GetLevel();

	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	//�G�t�F�N�g����
	CSkill_effect::Create(pPlaryer->GetPos() + pos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_KNIGHT);

	//if (nLevel < 3)
	//{
	//	// SE�Đ�
	//	pSound->Play(CSound::LABEL_SE_KENSI_ATTACK);
	//}

	//if (nLevel == 3)
	//{
	//	pSound->Play(CSound::LABEL_SE_KENSI_FINALATTACK);
	//}
}


//=============================================================================
//
// �U���͈̓^�C�v�R�m [attack_knight.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_lancer.h"
#include "tile.h"
#include "player.h"
#include "attack.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackLancer::CAttackLancer()
{
	m_nAttackCount = 0;
	m_nType = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackLancer::~CAttackLancer()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackLancer * CAttackLancer::Create(CPlayer* pPlayer)
{
	//�������m��
	CAttackLancer* pAttackLancer = NULL;
	pAttackLancer = new CAttackLancer;

	if (pAttackLancer != NULL)
	{
		pAttackLancer->SetType(CResourceCharacter::CHARACTER_LANCER);
		pAttackLancer->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackLancer->Init();				// ����������
	}
	return pAttackLancer;
}

//=============================================================================
// �U�������֐�
//=============================================================================
void CAttackLancer::AttackCreate(void)
{
	//�U���t���O�������Ă��邩
	if (GetState() == ATTACK_STATE_ATTACK
		|| GetState() == ATTACK_STATE_FINALATTACK)
	{
		//�J�E���g�A�b�v
		m_nAttackCount++;

		// �U���͈͂̉���
		VisualizationAttackArea(m_nType);

		//�J�E���g�����ɂȂ�����
		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
		{
			//�U������
			Attack(m_nType);
			//�^�C�v�����ɂȂ�����
			if (m_nType == MAX_HIT_TYPE)
			{
				//�t���O�̏�����
				SetState(ATTACK_STATE_NORMAL);
				//�^�C�v������
				m_nType = 0;
				//���x���̏�����
				CAttackBased::SetLevel(0);
			}
			else
			{
				//���̍U���^�C�v��
				m_nType++;
			}
			//�J�E���g������
			m_nAttackCount = 0;

		}
	}
}
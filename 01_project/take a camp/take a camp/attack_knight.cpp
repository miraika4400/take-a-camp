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

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackKnight::CAttackKnight()
{
	m_nAttackCount = 0;
	m_nType = 0;
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
		pAttackKnight->SetPlayer(pPlayer);	//�v���C���[�N���X�擾
		pAttackKnight->SetRot(pPlayer->GetRot());	//�����ݒ�
		pAttackKnight->SetPos(pPlayer->GetPos());	//�ʒu�ݒ�
		pAttackKnight->SetAttackType(CResourceCharacter::CHARACTER_KNIGHT);	//�^�C�v�Z�b�g
		pAttackKnight->Init();		//����������
	}
	return pAttackKnight;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CAttackKnight::Init(void)
{
	CAttackBased::Init();
	return S_OK;
}

//=============================================================================
// �U�������֐�
//=============================================================================
void CAttackKnight::AttackCreate(void)
{
	//�U���t���O�������Ă��邩
	if (GetState() == ATTACK_STATE_ATTACK)
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
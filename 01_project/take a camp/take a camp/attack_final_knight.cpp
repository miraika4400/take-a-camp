//=============================================================================
//
// �i�C�g�̕K�E�Z�͈̓^�C�v�̏��� [attack_final_knight.cpp]
// Author : �����D�I
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_final_knight.h"
#include "tile.h"
#include "player.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackFinalknight::CAttackFinalknight()
{
	m_nAttackFinalCount = 0;
	m_nType = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackFinalknight::~CAttackFinalknight()
{

}

//=============================================================================
// ��������
//=============================================================================
CAttackFinalknight * CAttackFinalknight::Create(CPlayer* pPlayer)
{
	// �������m��
	CAttackFinalknight* pAttackFinalKnight = NULL;
	pAttackFinalKnight = new CAttackFinalknight;

	if (pAttackFinalKnight != NULL)
	{
		pAttackFinalKnight->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
		pAttackFinalKnight->SetPos(pPlayer->GetPos());	// �ʒu�ݒ�
		pAttackFinalKnight->SetRot(pPlayer->GetRot());	// �����ݒ�
		pAttackFinalKnight->SetAttackType(CResourceCharacter::CHARACTER_KNIGHT);	// �^�C�v�ݒ�
		pAttackFinalKnight->Init();				// ����������
	}
	return pAttackFinalKnight;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CAttackFinalknight::Init(void)
{
	// ����������
	CAttackBased::Init();

	return S_OK;
}

//=============================================================================
// �K�E�����֐�
//=============================================================================
void CAttackFinalknight::AttackCreate(void)
{
	// �K�E�t���O�������Ă��邩
	if (GetState() == ATTACK_STATE_ATTACK)
	{
		// �J�E���g�A�b�v
		m_nAttackFinalCount++;

		VisualizationAttackArea(m_nType);

		// �J�E���g�����ɂȂ�����
		if (m_nAttackFinalCount >= GetAttackSquare().nAttackFrame[m_nType])
		{
			// �K�E����
			Attack(m_nType);
			// �^�C�v�����ɂȂ�����
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
				// ���̍U���^�C�v��
				m_nType++;
			}
			// �J�E���g������
			m_nAttackFinalCount = 0;
		}
	}
}
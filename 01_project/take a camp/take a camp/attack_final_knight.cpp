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
		pAttackFinalKnight->SetAttackFinalType(CResourceCharacter::CHARACTER_KNIGHT);	// �^�C�v�ݒ�
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
	CAttackFinal::Init();

	return S_OK;
}

//=============================================================================
// �K�E�����֐�
//=============================================================================
void CAttackFinalknight::AttackFinalCreate(void)
{
	// �K�E�t���O�������Ă��邩
	if (GetAttackFinalFlag())
	{
		// �J�E���g�A�b�v
		m_nAttackFinalCount++;

		VisualizationAttackArea(m_nType);

		// �J�E���g�����ɂȂ�����
		if (m_nAttackFinalCount >= GetFinalAttackSquare().nAttackFrame[m_nType])
		{
			// �K�E����
			AttackFinal(m_nType);
			// �^�C�v�����ɂȂ�����
			if (m_nType == MAX_FINAL_HIT_TYPE)
			{
				// ��Ԃ̏�����
				SetState(FINAL_ATTACK_STATE_NOMAL);
				// �t���O�̏�����
				SetAttackFinalFlag(false);
				// �^�C�v�̏�����
				m_nType = 0;
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
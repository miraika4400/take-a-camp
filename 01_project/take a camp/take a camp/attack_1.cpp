//=============================================================================
//
// �U���͈̓^�C�v1 [attack_1.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_1.h"
#include "tile.h"
#include "player.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttack1::CAttack1()
{
	m_nAttackCount = 0;
	m_nType = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttack1::~CAttack1()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttack1 * CAttack1::Create(CPlayer* pPlayer)
{
	//�������m��
	CAttack1* pAttack1 = NULL;
	pAttack1 = new CAttack1;

	if (pAttack1 != NULL)
	{
		pAttack1->SetPlayer(pPlayer);	//�v���C���[�N���X�擾
		pAttack1->SetRot(pPlayer->GetRot());	//�����ݒ�
		pAttack1->SetPos(pPlayer->GetPos());	//�ʒu�ݒ�
		pAttack1->SetAttackType(CAttackManager::ATTACK_TYPE_1);	//�^�C�v�Z�b�g
		pAttack1->Init();		//����������
	}
	return pAttack1;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CAttack1::Init(void)
{
	CAttackBased::Init();
	return S_OK;
}

////=============================================================================
//// �X�V�֐�
////=============================================================================
//void CAttack1::Update(void)
//{
//}

//=============================================================================
// �U�������֐�
//=============================================================================
void CAttack1::AttackCreate(void)
{
	//�U���t���O�������Ă��邩
	if (GetAttackFlag())
	{
		//�J�E���g�A�b�v
		m_nAttackCount++;

		//�J�E���g�����ɂȂ�����
		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
		{
			//�U������
			Attack(m_nType);
			//�^�C�v�����ɂȂ�����
			if (m_nType == MAX_HIT_TYPE)
			{
				//�t���O�̏�����
				SetAttackFlag(false);
				//�^�C�v������
				m_nType = 0;
			}
			else
			{
				//���̍U���^�C�v��
				m_nType++;
			}
			//�J�E���g������
			m_nAttackCount = 0;
		}
		
		//else
		//{
		//	//�^�C�v����v���Ă��邩
		//	for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
		//	{
		//		//�s��v�Z
		//		D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		//		//�U���ʒu
		//		D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
		//		CreatePos.x = ((cosf(GetRot().y)*AttackPos.x) + (sinf(GetRot().y)*AttackPos.z));
		//		CreatePos.y = 1 * AttackPos.y;
		//		CreatePos.z = ((-sinf(GetRot().y)*AttackPos.x) + (cosf(GetRot().y)*AttackPos.z));
		//		
		//		CColorTile*pTile = CColorTile::GetHitColorTile(CreatePos + GetPos());
		//		if (pTile != NULL)
		//		{
		//			pTile->GetFrame()->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
		//		}
		//	}
		//}
	}
}
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
	//�G�t�F�N�g����
	CSkill_effect::Create(pPlaryer->GetPos() + pos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
		GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_KNIGHT);
}

//
////=============================================================================
//// �U�������֐�
////=============================================================================
//void CAttackKnight::AttackCreate(void)
//{	
//	//�v���C���[�̃|�C���^
//	CPlayer *pPlaryer = GetPlayer();
//	
//	//�U���t���O�������Ă��邩
//	if (GetState() == ATTACK_STATE_ATTACK
//		|| GetState() == ATTACK_STATE_FINALATTACK)
//	{
//		//�J�E���g�A�b�v
//		m_nAttackCount++;
//
//		// �U���͈͂̉���
//		VisualizationAttackArea(m_nType);
//
//		//�J�E���g�����ɂȂ�����
//		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
//		{
//			//�U������
//			Attack(m_nType);
//	
//			//�X�L���G�t�F�N�g�̐���
//			if (m_nType == MIN_HIT_TYPE)
//			{
//				for (int nCnt = 0; nCnt < GetAttackSquare().nMaxHitRange; nCnt++)
//				{
//					
//					//�s��v�Z
//					D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//					D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nCnt].AttackPos * TILE_ONE_SIDE;
//					CreatePos.x = ((cosf(pPlaryer->GetRot().y)*AttackPos.x) + (sinf(pPlaryer->GetRot().y)*AttackPos.z));
//					CreatePos.y = 1 * AttackPos.y;
//					CreatePos.z = ((-sinf(pPlaryer->GetRot().y)*AttackPos.x) + (cosf(pPlaryer->GetRot().y)*AttackPos.z));
//
//					//�G�t�F�N�g����
//					CSkill_effect::Create(pPlaryer->GetPos() + CreatePos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
//					GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
//					GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_KNIGHT);
//				}
//				
//			}
//
//			//�^�C�v�����ɂȂ�����
//			if (m_nType == MAX_HIT_TYPE)
//			{
//				//�t���O�̏�����
//				SetState(ATTACK_STATE_NORMAL);
//				//�^�C�v������
//				m_nType = 0;
//				//���x���̏�����
//				CAttackBased::SetLevel(0);
//			}
//			else
//			{
//				//���̍U���^�C�v��
//				m_nType++;
//			}
//			//�J�E���g������
//			m_nAttackCount = 0;
//
//		
//		}
//		
//	}
//}
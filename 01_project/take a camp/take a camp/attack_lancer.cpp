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
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"
#include "sound.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackLancer::CAttackLancer()
{
    /*m_nAttackCount = 0;
    m_nType = 0;*/
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
// �G�t�F�N�g����
//=============================================================================
void CAttackLancer::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{
    CPlayer *pPlaryer = GetPlayer();
    //�G�t�F�N�g����
    CSkill_effect::Create(pPlaryer->GetPos() + pos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
 	GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
	GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), LANCER_EFFECT_LIFE, CSkill_effect::SKILLTYPE_KNIGHT, GetPlayer());
}

//=============================================================================
// SE�Đ�
//=============================================================================
void CAttackLancer::PlaySE(void)
{
    // �T�E���h���̎擾
    CSound *pSound = CManager::GetSound();

    // ���x�����̎擾
    int nLevel = GetLevel();

    // �ʏ�U���Ȃ�
    if (nLevel < MAX_LEVEL)
    {
        // SE�Đ�
        pSound->Play(CSound::LABEL_SE_YARI_ATTACK);
    }
    //�@�K�E�Ȃ�
    else
    {
        // SE�Đ�
        pSound->Play(CSound::LABEL_SE_YARI_FINALATTACK);
    }
}

////=============================================================================
//// �U�������֐�
////=============================================================================
//void CAttackLancer::AttackCreate(void)
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
//		//�X�L���G�t�F�N�g�̐���
//		if (m_nType == MIN_HIT_TYPE)
//		{
//			for (int nCnt = 0; nCnt < GetAttackSquare().nMaxHitRange; nCnt++)
//			{
//
//				//�s��v�Z
//				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//				D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nCnt].AttackPos * TILE_ONE_SIDE;
//				CreatePos.x = ((cosf(pPlaryer->GetRot().y)*AttackPos.x) + (sinf(pPlaryer->GetRot().y)*AttackPos.z));
//				CreatePos.y = 1 * AttackPos.y;
//				CreatePos.z = ((-sinf(pPlaryer->GetRot().y)*AttackPos.x) + (cosf(pPlaryer->GetRot().y)*AttackPos.z));
//
//				//�G�t�F�N�g����
//				CSkill_effect::Create(pPlaryer->GetPos() + CreatePos + NORMAL_SKIIL_POS, NORMAL_SKIIL_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel()),
//					GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() - 1),
//					GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), pPlaryer->GetChargeTilelevel() + 1), CSkill_effect::SKILLTYPE_KNIGHT);
//			}
//
//		}
//
//		//�J�E���g�����ɂȂ�����
//		if (m_nAttackCount >= GetAttackSquare().nAttackFrame[m_nType])
//		{
//			//�U������
//			Attack(m_nType);
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
//		}
//	}
//}
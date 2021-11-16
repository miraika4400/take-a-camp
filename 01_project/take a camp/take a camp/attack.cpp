//=============================================================================
//
// �U����� [attack.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack.h"
#include "tile.h"
#include "resource_attack.h"
#include "player.h"
#include "bullet.h"
#include "scene3d.h"
#include "attack_area.h"
#include "color_tile.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define CHARGE_COUNT (60*1)	//�`���[�W�ɂ����鎞��

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackBased::CAttackBased() :CScene(OBJTYPE_SYSTEM)
{
	//����������
	m_nAttackType	= CAttackManager::ATTACK_TYPE_1;
	m_pos			= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	memset(&m_AttackSquare, 0, sizeof(m_AttackSquare));
	m_pPlayer		= NULL;
	m_nLevel		= 0;
	m_nChargeCount	= 0;
	ZeroMemory(&m_apAttackArea, sizeof(m_apAttackArea));
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackBased::~CAttackBased()
{
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CAttackBased::Init(void)
{
	int nMaxAttackNum = 0;
	
	//�U���^�C�v�Z�b�g
	for (int nLevel = 0; nLevel < MAX_ATTACK_LEVEL; nLevel++)
	{
		m_AttackSquare[nLevel] = CAttackManager::GetAttack(m_nAttackType, nLevel);
		if (nMaxAttackNum < m_AttackSquare[nLevel].nMaxHitRange)
		{
			nMaxAttackNum = m_AttackSquare[nLevel].nMaxHitRange;
		}
	}

	for(int nCntArea = 0 ; nCntArea < nMaxAttackNum; nCntArea++)
	{
		m_apAttackArea[nCntArea] = CAttackArea::Create();
	}

	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CAttackBased::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CAttackBased::Update(void)
{
	//�X�e�[�g���Ƃ̏���
	switch (m_AttackState)
	{
	case ATTACK_STATE_NORMAL:	//�ʏ���
		break;

	case ATTACK_STATE_CHARGE:	//�`���[�W���
		// �`���[�W����
		Charge();
		break;

	case ATTACK_STATE_ATTACK:	//�U�����
		// �U����������
		AttackCreate();
		break;

	//����ȊO�̏��
	default:
		m_AttackState = ATTACK_STATE_NORMAL;
		break;
	}

}

//=============================================================================
// �`��֐�
//=============================================================================
void CAttackBased::Draw(void)
{
}

//=============================================================================
// �U���֐�
//=============================================================================
void CAttackBased::Attack(int AttackType)
{
	for (int nAttack = 0; nAttack < m_AttackSquare[m_nLevel].nMaxHitRange; nAttack++)
	{
		//�^�C�v����v���Ă��邩
		if (m_AttackSquare[m_nLevel].SquareData[nAttack].RangeType == AttackType + (int)CAttackManager::ATTACK_RANGE_HIT_1)
		{
			//�s��v�Z
			D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//�U���ʒu
			D3DXVECTOR3 AttackPos = m_AttackSquare[m_nLevel].SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(m_rot.y)*AttackPos.x) + (sinf(m_rot.y)*AttackPos.z));
			CreatePos.y = 1 * AttackPos.y;
			CreatePos.z = ((-sinf(m_rot.y)*AttackPos.x) + (cosf(m_rot.y)*AttackPos.z));
			//�����蔻�萶��
			CBullet::Create(CreatePos + m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pPlayer->GetPlayerNumber());
		}

	}
}

//=============================================================================
// �`���[�W�t���O�����֐�
//=============================================================================
void CAttackBased::ChargeFlag(int nMaxLevel)
{
	//���݂̏�Ԃ��ʏ�̏ꍇ
	if (m_AttackState == ATTACK_STATE_NORMAL)
	{
		//�`���[�W��ԂɈڍs
		m_AttackState = ATTACK_STATE_CHARGE;
		//���x���̍ő�l�̎擾
		m_nMaxLevel = nMaxLevel;
	}
}

//=============================================================================
// �`���[�W�����֐�
// Akuthor: �g�c �I�l
//=============================================================================
void CAttackBased::Charge(void)
{
	//�J�E���g�A�b�v
	m_nChargeCount++;

	//���ɒB���Ă��邩
	if (m_nChargeCount>CHARGE_COUNT)
	{
		//���݂̃��x�������E�̃��x�����Ⴂ
		if (m_nLevel<m_nMaxLevel)
		{
			m_nLevel++;
		}
		//�J�E���g������
		m_nChargeCount = 0;
	}

}

//=============================================================================
// �U���X�C�b�`�֐�
//=============================================================================
void CAttackBased::AttackSwitch(void)
{
	//�U�������Ă��Ȃ�������
	if (m_AttackState == ATTACK_STATE_CHARGE)
	{
		//�U����ԂɈڍs
		m_AttackState = ATTACK_STATE_ATTACK;
		//�ʒu�擾
		SetPos(m_pPlayer->GetPos());
		//�����擾
		SetRot(m_pPlayer->GetRotDest());
		//�J�E���g������
		m_nChargeCount = 0;
	
		// �`���[�W�����Ă���v���C���[�̎擾
		CColorTile * pColorTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

		while (pColorTile != NULL)
		{
			//�`���[�W�����Ă���^�C���擾
			if (pColorTile->GetColorTileState() == CColorTile::COLOR_TILE_CHARGE
				&&pColorTile->GetLasthitPlayerNum()== m_pPlayer->GetPlayerNumber())
			{
				//�h��i�K�̏���
				pColorTile->ColorDown(m_nLevel+1);
				//�^�C���X�e�[�g
				pColorTile->SetColorTileState(CColorTile::COLOR_TILE_NORMAL);
			}
			// ���X�g��i�߂�
			pColorTile = (CColorTile*)pColorTile->GetNext();
		}


	}
}

//=============================================================================
// �U���}�X�f�[�^�Q�b�^�[�֐�
//=============================================================================
void CAttackBased::SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare)
{
	m_AttackSquare[m_nLevel] = AttackSquare;
}

//=============================================================================
// �U���}�X�f�[�^�Q�b�^�[�֐�
//=============================================================================
CAttackManager::ATTACK_SQUARE_DATA CAttackBased::GetAttackSquare()
{
	return m_AttackSquare[m_nLevel];
}

//=============================================================================
// �U���͈̘͂g�̐F��ς��鏈��
// Akuthor: ���V ����
//=============================================================================
void CAttackBased::VisualizationAttackArea(int nAttackType)
{
	//�U���t���O�������Ă��邩
	if (m_AttackState == ATTACK_STATE_ATTACK)
	{
		//�^�C�v����v���Ă��邩
		for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
		{
			//�^�C�v����v���Ă��邩
			if (m_AttackSquare[m_nLevel].SquareData[nAttack].RangeType >= nAttackType + (int)CAttackManager::ATTACK_RANGE_HIT_1)
			{
				//�s��v�Z
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//�U���ʒu
				D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
				CreatePos.x = ((cosf(GetRot().y)*AttackPos.x) + (sinf(GetRot().y)*AttackPos.z));
				CreatePos.y = 1 * AttackPos.y;
				CreatePos.z = ((-sinf(GetRot().y)*AttackPos.x) + (cosf(GetRot().y)*AttackPos.z));

				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					m_apAttackArea[nAttack]->SetPos(CreatePos + m_pos + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
					m_apAttackArea[nAttack]->SetDrawFlag(true);
				}
			}
			else
			{
				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetDrawFlag(false);
				}
			}
		}
	}
	else
	{
		CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPlayer()->GetPosDest());
		if (pHitTile != NULL)
		{
			//�^�C�v����v���Ă��邩
			for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
			{
				//�s��v�Z
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//�U���ʒu
				D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
				CreatePos.x = ((cosf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (sinf(GetPlayer()->GetRotDest().y)*AttackPos.z));
				CreatePos.y = 1 * AttackPos.y;
				CreatePos.z = ((-sinf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (cosf(GetPlayer()->GetRotDest().y)*AttackPos.z));

				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					m_apAttackArea[nAttack]->SetPos(CreatePos + GetPlayer()->GetPosDest() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
					m_apAttackArea[nAttack]->SetDrawFlag(true);
				}

			}
		}
	}
}

//=============================================================================
// �U���͈̓|���S���̃��Z�b�g
// Akuthor: ���V ����
//=============================================================================
void CAttackBased::ResetAttackArea(void)
{
	for (int nCntArea = 0; nCntArea < MAX_ATTACK_AREA_NUM; nCntArea++)
	{
		if (m_apAttackArea[nCntArea] != NULL)
		{
			m_apAttackArea[nCntArea]->SetDrawFlag(false);
			m_apAttackArea[nCntArea]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_apAttackArea[nCntArea]->SetSize(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		}
	}
}

//=============================================================================
//
// �K�E�Z�̏��� [attack_final.cpp]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_final.h"
#include "tile.h"
#include "resource_attack.h"
#include "player.h"
#include "scene3d.h"
#include "bullet.h"
#include "color_tile.h"
#include "attack_area.h"
#include "peint_collision.h"
#include "collision.h"
//=============================================================================
// �}�N����`
//=============================================================================

//=============================================================================
// �ÓI�����o�[�ϐ��錾
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackFinal::CAttackFinal() : CScene(OBJTYPE_SYSTEM)
{
	m_pos = VEC3_ZERO;		// �ʒu
	m_rot = VEC3_ZERO;		// ����
	memset(&m_FinalAttackSquare, 0, sizeof(m_FinalAttackSquare));
	memset(&m_apAttackArea, 0, sizeof(m_apAttackArea));
	m_bAttackFinal = false;	// �K�E�Z�t���O
	m_pPlayer = NULL;		// �v���C���[���
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackFinal::~CAttackFinal()
{

}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CAttackFinal::Init(void)
{
	int nMaxAttackNum = 0;

	// �U���^�C�v�̃Z�b�g
	m_FinalAttackSquare = CFinalAttackManager::GetFinalAttack(m_FinalAttackType);

	if (nMaxAttackNum < m_FinalAttackSquare.nMaxHitRange)
	{
		nMaxAttackNum = m_FinalAttackSquare.nMaxHitRange;
	}

	for (int nCntArea = 0; nCntArea < nMaxAttackNum; nCntArea++)
	{
		m_apAttackArea[nCntArea] = CAttackArea::Create();
	}

	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CAttackFinal::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CAttackFinal::Update(void)
{
	//AttackFinalCreate();

	switch (m_FinalAttackState)
	{
	case FINAL_ATTACK_STATE_NOMAL:

	case FINAL_ATTACK_STATE_ATTACK:
		AttackFinalCreate();
		break;
	default:
		m_FinalAttackState = FINAL_ATTACK_STATE_NOMAL;
		break;
	}
}

//=============================================================================
// �`��֐�
//=============================================================================
void CAttackFinal::Draw(void)
{

}

//=============================================================================
// �K�E�X�C�b�`�֐�
//=============================================================================
void CAttackFinal::AttackFinalSwitch(void)
{
	// �U������Ă��Ȃ�������
	if (m_bAttackFinal == false)
	{
		m_FinalAttackState = FINAL_ATTACK_STATE_ATTACK;
		// �t���O�I��
		SetAttackFinalFlag(true);
		// �ʒu�擾
		SetPos(m_pPlayer->GetPos());
		// �����擾
		SetRot(m_pPlayer->GetRot());
	}
}

//=============================================================================
// �K�E�֐�
//=============================================================================
void CAttackFinal::AttackFinal(int AttackFinalType)
{
	for (int nAttackFinal = 0; nAttackFinal < m_FinalAttackSquare.nMaxHitRange; nAttackFinal++)
	{
		// �^�C�v����v���Ă��邩
		if (m_FinalAttackSquare.SquareData[nAttackFinal].RangeType == AttackFinalType + (int)CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_1)
		{
			// �s��v�Z
			D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			// �U���ʒu
			D3DXVECTOR3 AttackFinalPos = m_FinalAttackSquare.SquareData[nAttackFinal].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(m_rot.y)*AttackFinalPos.x) + (sin(m_rot.y)*AttackFinalPos.z));
			CreatePos.y = 1 * AttackFinalPos.y;
			CreatePos.z = ((-sinf(m_rot.y)*AttackFinalPos.x) + (cosf(m_rot.y)*AttackFinalPos.z));
			// �����蔻�萶��
			CBullet::Create(CreatePos + m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pPlayer->GetPlayerNumber());

			// �F�h�鏈��
			m_pPeintCollision[nAttackFinal] = CPeintCollision::Create(CreatePos + m_pos, m_pPlayer->GetPlayerNumber());
		}
	}
}

//=============================================================================
// �U���͈̘͂g�̐F��ς��鏈��
// Akuthor: ���V ����
//=============================================================================
void CAttackFinal::VisualizationAttackArea(int AttackFinalType)
{
	//�U���t���O�������Ă��邩
	if (GetAttackFinalFlag())
	{
		//�^�C�v����v���Ă��邩
		for (int nAttack = 0; nAttack < GetFinalAttackSquare().nMaxHitRange; nAttack++)
		{
			if (m_FinalAttackSquare.SquareData[nAttack].RangeType >= AttackFinalType + (int)CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_1)
			{
				//�s��v�Z
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//�U���ʒu
				D3DXVECTOR3 AttackPos = GetFinalAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
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
		CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPlayer()->GetPos());
		if (pHitTile != NULL)
		{
			//�^�C�v����v���Ă��邩
			for (int nAttack = 0; nAttack < GetFinalAttackSquare().nMaxHitRange; nAttack++)
			{
				//�s��v�Z
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//�U���ʒu
				D3DXVECTOR3 AttackPos = GetFinalAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
				CreatePos.x = ((cosf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (sinf(GetPlayer()->GetRotDest().y)*AttackPos.z));
				CreatePos.y = 1 * AttackPos.y;
				CreatePos.z = ((-sinf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (cosf(GetPlayer()->GetRotDest().y)*AttackPos.z));

				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					m_apAttackArea[nAttack]->SetPos(CreatePos + GetPlayer()->GetPos() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
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
void CAttackFinal::ResetAttackArea(void)
{
	for (int nCntArea = 0; nCntArea < MAX_ATTACK_FINAL_AREA_NUM; nCntArea++)
	{
		if (m_apAttackArea[nCntArea] != NULL)
		{
			m_apAttackArea[nCntArea]->SetDrawFlag(false);
			m_apAttackArea[nCntArea]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_apAttackArea[nCntArea]->SetSize(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		}
	}
}
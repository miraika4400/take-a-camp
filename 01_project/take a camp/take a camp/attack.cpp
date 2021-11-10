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
// �R���X�g���N�^
//=============================================================================
CAttackBased::CAttackBased() :CScene(OBJTYPE_SYSTEM)
{
	//����������
	m_nAttackType = CAttackManager::ATTACK_TYPE_1;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	memset(&m_AttackSquare, 0, sizeof(CAttackManager::ATTACK_SQUARE_DATA));
	m_bAttack = false;
	m_pPlayer = NULL;
	m_nLevel = 0;
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
	//�U���^�C�v�Z�b�g
	for (int nLevel = 0; nLevel < MAX_ATTACK_LEVEL; nLevel++)
	{
		m_AttackSquare[nLevel] = CAttackManager::GetAttack(m_nAttackType, nLevel);

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
	AttackCreate();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CAttackBased::Draw(void)
{
}

//=============================================================================
// �U���^�C�v�Z�b�^�[�֐�
//=============================================================================
void CAttackBased::SetAttackType(CAttackManager::ATTACK_TYPE AttackType)
{
	m_nAttackType = AttackType;
}

//=============================================================================
// �U���^�C�v�Q�b�^�[�֐�
//=============================================================================
CAttackManager::ATTACK_TYPE CAttackBased::GetAttackType(void)
{
	return m_nAttackType;
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
// �ʒu�Z�b�^�[�֐�
//=============================================================================
void CAttackBased::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//=============================================================================
// �ʒu�Q�b�^�[�֐�
//=============================================================================
D3DXVECTOR3 CAttackBased::GetPos(void)
{
	return m_pos;
}

//=============================================================================
// �����Z�b�^�[�֐�
//=============================================================================
void CAttackBased::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//=============================================================================
// �����Q�b�^�[�֐�
//=============================================================================
D3DXVECTOR3 CAttackBased::GetRot(void)
{
	return m_rot;
}

//=============================================================================
// �U���t���O�Z�b�^�[�֐�
//=============================================================================
void CAttackBased::SetAttackFlag(bool bAttack)
{
	m_bAttack = bAttack;
}

//=============================================================================
// �U���X�C�b�`�֐�
//=============================================================================
void CAttackBased::AttackSwitch(int nLevel)
{
	//�U������Ă��Ȃ�������
	if (!m_bAttack)
	{
		//�t���O�I��
		SetAttackFlag(true);
		//�ʒu�擾
		SetPos(m_pPlayer->GetPos());
		//�����擾
		SetRot(m_pPlayer->GetRotDest());
		//���x���擾
		m_nLevel = nLevel;
	}
}

//=============================================================================
// �U���t���O�Q�b�^�[�֐�
//=============================================================================
bool CAttackBased::GetAttackFlag(void)
{
	return m_bAttack;
}

//=============================================================================
// �v���C���[�|�C���^�Q�b�^�[�֐�
//=============================================================================
void CAttackBased::SetPlayer(CPlayer * pPlayer)
{
	m_pPlayer = pPlayer;
}

//=============================================================================
// �v���C���[�|�C���^�Q�b�^�[�֐�
//=============================================================================
CPlayer * CAttackBased::GetPlayer(void)
{
	return m_pPlayer;
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
// �U���͈̘͂g�̐F��ς��鏈��
// Akuthor: ���V ����
//=============================================================================
void CAttackBased::ChangeFrameColor()
{
	//�U���t���O�������Ă��邩
	if (GetAttackFlag())
	{
		//�^�C�v����v���Ă��邩
		for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
		{
			//�s��v�Z
			D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//�U���ʒu
			D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(GetRot().y)*AttackPos.x) + (sinf(GetRot().y)*AttackPos.z));
			CreatePos.y = 1 * AttackPos.y;
			CreatePos.z = ((-sinf(GetRot().y)*AttackPos.x) + (cosf(GetRot().y)*AttackPos.z));

			CTile*pTile = CTile::GetHitTile(CreatePos + GetPos());
			if (pTile != NULL)
			{
				pTile->GetAttackAreaPolygon()->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
				pTile->GetAttackAreaPolygon()->SetPos(pTile->GetPos() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
				pTile->GetAttackAreaPolygon()->SetDrawFlag(true);
			}
		}
	}
	else
	{
		CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPlayer()->GetPos());
		if (pHitTile != NULL)
		{
			m_nLevel = pHitTile->GetStepNum() - 1;
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

				CTile*pTile = CTile::GetHitTile(CreatePos + GetPlayer()->GetPos());
				if (pTile != NULL)
				{
					pTile->GetAttackAreaPolygon()->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					pTile->GetAttackAreaPolygon()->SetPos(pTile->GetPos() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
					pTile->GetAttackAreaPolygon()->SetDrawFlag(true);
				}
			}
		}
	}
}

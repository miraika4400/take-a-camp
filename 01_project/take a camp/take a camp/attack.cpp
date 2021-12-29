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
#include "attack_knight.h"
#include "attack_wizard.h"
#include "attack_lancer.h"
#include "attack_thief.h"
#include "attack_magician.h"
#include "attack_archer.h"
#include "tile.h"
#include "resource_attack.h"
#include "player.h"
#include "bullet.h"
#include "scene3d.h"
#include "attack_area.h"
#include "color_tile.h"
#include "peint_collision.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define ATTACK_AREA_EFFECT_POS (D3DXVECTOR3(0.0f,10.0f,0.0f))
#define CHARGE_COUNT (60*1)		// �`���[�W�ɂ����鎞��
#define LEVEL_MAX    (4)		// �ő僌�x��
#define CANCEL_COUNT (60*0.1f)	// �U���L�����Z���̃J�E���g
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackBased::CAttackBased() :CScene(OBJTYPE_SYSTEM)
{
	//����������
	memset(&m_AttackSquare, 0, sizeof(m_AttackSquare));
	m_pPlayer		= NULL;
	m_nLevel		= 0;
	m_nCancelCount	= 0;
	m_nChargeCount	= 0;
	m_AttackState = ATTACK_STATE_NORMAL;
	ZeroMemory(&m_apAttackArea, sizeof(m_apAttackArea));
	ZeroMemory(&m_anChargeValue, sizeof(m_anChargeValue));
	m_bAttack = false;	// �K�E�t���O
	m_bChargeTile = false;
	m_bCancel = false;
	m_nAttackCount = 0;
	m_nType = 0;

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackBased::~CAttackBased()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackBased * CAttackBased::Create(CPlayer * pPlayer, CResourceCharacter::CHARACTER_TYPE Type)
{
	//�������m��
	CAttackBased* pAttack = NULL;

	switch (Type)
	{
	case CResourceCharacter::CHARACTER_KNIGHT:
		pAttack = CAttackKnight::Create(pPlayer);
		break;
	case CResourceCharacter::CHARACTER_LANCER:
		pAttack = CAttackLancer::Create(pPlayer);
		break;
	case CResourceCharacter::CHARACTER_WIZARD:
		pAttack = CAttackWizard::Create(pPlayer);
		break;
	case CResourceCharacter::CHARACTER_THIEF:
		pAttack = CAttackThief::Create(pPlayer);
		break;
	case CResourceCharacter::CHARACTER_MAGICIAN:
		pAttack = CAttackMagician::Create(pPlayer);
		break;
	case CResourceCharacter::CHARACTER_ARCHER:
		pAttack = CAttackArcher::Create(pPlayer);
		break;
	default:
		break;
	}

	//pAttack = new CAttackBased;
	//if (pAttack != NULL)
	//{
	//	pAttack->SetPlayer(pPlayer);		//�v���C���[�N���X�擾
	//	pAttack->Init();					//����������
	//}
	return pAttack;
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
		
		// �`���[�W���Ԃ̎擾
		m_anChargeValue[nLevel] = CResourceCharacter::GetResourceCharacter()->GetCharacterData(m_nAttackType).anChargeTime[nLevel];
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
	{
		//���l�̏�����
		if (m_nLevel != 0)
		{
			m_nLevel = 0;
			m_nChargeCount = 0;
			m_nAttackCount = 0;
			m_nType = 0;
		}
		
		//�U���͈͂̃��Z�b�g
		ResetAttackArea();
		//�`���[�W�^�C���t���O�������Ă����
		if (m_bChargeTile == true)
		{
			// �`���[�W�����Ă���v���C���[�̎擾
			CColorTile * pColorTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

			while (pColorTile != NULL)
			{
				//�`���[�W�����Ă���^�C���擾
				if (pColorTile->GetColorTileState() == CColorTile::COLOR_TILE_CHARGE
					&&pColorTile->GetLasthitPlayerNum() == m_pPlayer->GetPlayerNumber())
				{
					//�^�C���X�e�[�g
					pColorTile->SetColorTileState(CColorTile::COLOR_TILE_NORMAL);
					return;
				}
				// ���X�g��i�߂�
				pColorTile = (CColorTile*)pColorTile->GetNext();
			}
		}

		//�L�����Z���t���O�������Ă��邩
		if (m_bCancel == true)
		{
			//�J�E���g�A�b�v
			m_nCancelCount++;

			if (m_nCancelCount >= CANCEL_COUNT)
			{
				//�L�����Z���t���O�����
				m_bCancel = false;
				//�L�����Z���J�E���g������
				m_nCancelCount = 0;
				//�`���[�W�J�E���g������
				m_nChargeCount = 0;
			}

		}
	}
	break;

	
	case ATTACK_STATE_CHARGE:		// �`���[�W���	
		VisualizationAttackArea();	// �U���͈͕\��
		Charge();					// �`���[�W����
		break;

	case ATTACK_STATE_ATTACK:		// �U�����			
		AttackCreate();				// �U����������
		break;

	case ATTACK_STATE_FINALATTACKWAITING:	// �K�E�Z�ҋ@���	
		VisualizationAttackArea();		// �U���͈͕\��
		m_nLevel = LEVEL_MAX - 1;		// ���x�����ő�l�ɂ���
		break;

	case ATTACK_STATE_FINALATTACK:		// �K�E�Z�g�p���			
		AttackCreate();					// �U����������
		break;


	default:							//����ȊO�̏��
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
			//�ʒu�擾
			D3DXVECTOR3 pos = m_pPlayer->GetPos();
			//�����擾
			D3DXVECTOR3 rot = m_pPlayer->GetRotDest();

			//�U���ʒu
			D3DXVECTOR3 AttackPos = m_AttackSquare[m_nLevel].SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(rot.y)*AttackPos.x) + (sinf(rot.y)*AttackPos.z));
			CreatePos.y = 1 * AttackPos.y;
			CreatePos.z = ((-sinf(rot.y)*AttackPos.x) + (cosf(rot.y)*AttackPos.z));
			//�����蔻�萶��
			CBullet::Create(CreatePos + pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pPlayer->GetPlayerNumber());

			// �K�E�Z�̑łĂ郌�x���Ȃ�
			if (m_nLevel == LEVEL_MAX - 1)
			{
				// �F�h�鏈��
				m_pPeintCollision[nAttack] = CPeintCollision::Create(CreatePos + pos, m_pPlayer->GetPlayerNumber());
			}
		}
	}
}

//=============================================================================
// �`���[�W�t���O�����֐�
//=============================================================================
void CAttackBased::ChargeFlag(void)
{
	//���݂̏�Ԃ��ʏ�̏ꍇ
	if (m_AttackState == ATTACK_STATE_NORMAL)
	{
		if (!m_bCancel)
		{
			// �������Ă���^�C���̎擾
			CColorTile*pHitTile = CColorTile::GetHitColorTile(m_pPlayer->GetPos());

			//�G��Ă���^�C���̎���(NULL�`�F�b�N, �J���[�̊m�F)
			if (pHitTile != NULL&&pHitTile->GetPeintNum() == m_pPlayer->GetColorNumber())
			{
				//�^�C�����`���[�W�o���邩�擾
				if (pHitTile->ChargeFlag(m_pPlayer->GetPlayerNumber()))
				{
					//�`���[�W�^�C���t���O�𗧂Ă�
					m_bChargeTile = true;
					//�`���[�W��ԂɈڍs
					m_AttackState = ATTACK_STATE_CHARGE;
					//���x���̍ő�l�̎擾
					m_nMaxLevel = pHitTile->GetStepNum() - 1;
				}
			}
		}
		else
		{
			m_nCancelCount = 0;
		}
	}
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================
void CAttackBased::CreateEffect(D3DXVECTOR3 pos)
{
}

//=============================================================================
// �`���[�W�����֐�
// Akuthor: �g�c �I�l�A���V����
//=============================================================================
void CAttackBased::Charge(void)
{
	//�J�E���g�A�b�v
	m_nChargeCount++;

	for (int nCntLevel = 0; nCntLevel < MAX_ATTACK_LEVEL; nCntLevel++)
	{
		// �ő僌�x���̔���
		if (nCntLevel > m_nMaxLevel)
		{
			break;
		}
		// �`���[�W���Ԃɉ��������x���ɂ���
		if (m_nChargeCount > m_anChargeValue[nCntLevel])
		{
			m_nLevel = nCntLevel;
		}
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
				return;
			}
			// ���X�g��i�߂�
			pColorTile = (CColorTile*)pColorTile->GetNext();
		}
	}
}

//=============================================================================
// �K�E�ҋ@�t���O�֐�
//=============================================================================
void CAttackBased::AttackFinalFlag(void)
{
	//�L�����Z���t���O�������Ă��Ȃ���
	if (!m_bCancel)
	{
		// �U����Ԃ���Ȃ��Ȃ�
		if (m_AttackState == CAttackBased::ATTACK_STATE_NORMAL
			|| m_AttackState == CAttackBased::ATTACK_STATE_FINALATTACKWAITING)
		{
			SetState(CAttackBased::ATTACK_STATE_FINALATTACKWAITING);
		}
	}
	else
	{
		m_nCancelCount = 0;
	}
}

//=============================================================================
// �K�E�Z�X�C�b�`�֐�
//=============================================================================
void CAttackBased::AttackFinalSwitch(void)
{
	// �K�E�Z�ҋ@���Ȃ�
	if (m_AttackState == ATTACK_STATE_FINALATTACKWAITING)
	{
		//�K�E�Z�g�p��ԂɈڍs
		m_AttackState = ATTACK_STATE_FINALATTACK;
	}
}

//=============================================================================
// �U���L�����Z���X�C�b�`�֐�
//=============================================================================
void CAttackBased::CancelSwitch(void)
{

	//�U�����`���[�W���Ă�����
	if (m_AttackState == ATTACK_STATE_CHARGE)
	{
		// �`���[�W�����Ă���v���C���[�̎擾
		CColorTile * pColorTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);
		while (pColorTile != NULL)
		{
			//�`���[�W�����Ă���^�C���擾
			if (pColorTile->GetColorTileState() == CColorTile::COLOR_TILE_CHARGE
				&&pColorTile->GetLasthitPlayerNum() == m_pPlayer->GetPlayerNumber())
			{
				//�^�C���X�e�[�g
				pColorTile->SetColorTileState(CColorTile::COLOR_TILE_NORMAL);
				break;
			}
			// ���X�g��i�߂�
			pColorTile = (CColorTile*)pColorTile->GetNext();
		}
	}

	//�U���͈͂̃��Z�b�g
	ResetAttackArea();
	//�U���L�����Z�����
	m_bCancel = true;
	//�ʏ��ԂɈڍs
	m_AttackState = ATTACK_STATE_NORMAL;
}

//=============================================================================
// �U����������
//=============================================================================
void CAttackBased::AttackCreate(void)
{
	//�v���C���[�̃|�C���^
	CPlayer *pPlaryer = GetPlayer();

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
      
			for (int nCnt = 0; nCnt < m_AttackSquare[m_nLevel].nMaxHitRange; nCnt++)
			{
				if (GetAttackSquare().SquareData[nCnt].RangeType == m_nType + 2)
				{
					//�s��v�Z
					D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nCnt].AttackPos * TILE_ONE_SIDE;
					CreatePos.x = ((cosf(pPlaryer->GetRotDest().y)*AttackPos.x) + (sinf(pPlaryer->GetRotDest().y)*AttackPos.z));
					CreatePos.y = 1 * AttackPos.y;
					CreatePos.z = ((-sinf(pPlaryer->GetRotDest().y)*AttackPos.x) + (cosf(pPlaryer->GetRotDest().y)*AttackPos.z));

					CreateEffect(CreatePos);
				}
			}
					
				
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
	//�U���t���O�ƕK�E�Z�t���O�������Ă��邩
	if (m_AttackState == ATTACK_STATE_ATTACK
		|| m_AttackState == ATTACK_STATE_FINALATTACK)
	{
		//�^�C�v����v���Ă��邩
		for (int nAttack = 0; nAttack < m_AttackSquare[m_nLevel].nMaxHitRange; nAttack++)
		{
			//�^�C�v����v���Ă��邩
			if (m_AttackSquare[m_nLevel].SquareData[nAttack].RangeType >= nAttackType + (int)CAttackManager::ATTACK_RANGE_HIT_1)
			{
				//�ʒu�擾
				D3DXVECTOR3 pos = m_pPlayer->GetPos();
				//�����擾
				D3DXVECTOR3 rot = m_pPlayer->GetRot();
				//�s��v�Z
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//�U���ʒu
				D3DXVECTOR3 AttackPos = m_AttackSquare[m_nLevel].SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
				CreatePos.x = ((cosf(rot.y)*AttackPos.x) + (sinf(rot.y)*AttackPos.z));
				CreatePos.y = 1 * AttackPos.y;
				CreatePos.z = ((-sinf(rot.y)*AttackPos.x) + (cosf(rot.y)*AttackPos.z));

				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					m_apAttackArea[nAttack]->SetPos(CreatePos + pos + ATTACK_AREA_EFFECT_POS);
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
		if (m_nLevel < 0)
		{
			return;
		}
		// �^�C�v����v���Ă��邩
		for (int nAttack = 0; nAttack < m_AttackSquare[m_nLevel].nMaxHitRange; nAttack++)
		{
			//�s��v�Z
			D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//�U���ʒu
			D3DXVECTOR3 AttackPos = m_AttackSquare[m_nLevel].SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (sinf(GetPlayer()->GetRotDest().y)*AttackPos.z));
			CreatePos.y = 1 * AttackPos.y;
			CreatePos.z = ((-sinf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (cosf(GetPlayer()->GetRotDest().y)*AttackPos.z));

			if (m_apAttackArea[nAttack] != NULL)
			{
				m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
				m_apAttackArea[nAttack]->SetPos(CreatePos + GetPlayer()->GetPos() + ATTACK_AREA_EFFECT_POS);
				m_apAttackArea[nAttack]->SetDrawFlag(true);
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

//=============================================================================
// �U���͈͂̃����[�X
// Akuthor: ���V ����
//=============================================================================
void CAttackBased::ReleaseAttakcArea(void)
{
	//�U���G���A�̉��
	for (int nCntArea = 0; nCntArea < MAX_ATTACK_AREA_NUM; nCntArea++)
	{
		if (m_apAttackArea[nCntArea] != NULL)
		{
			m_apAttackArea[nCntArea]->OutList();
			m_apAttackArea[nCntArea]->Uninit();
			delete m_apAttackArea[nCntArea];
			m_apAttackArea[nCntArea] = NULL;
		}
	}
}

//=============================================================================
//
// �s���͈̓w�b�_ [act_range.h]
// Author : �g�c �I�l
//
//=============================================================================
//*****************************
// �C���N���[�h
//*****************************
#include "act_range.h"
#include "player.h"
#include "tile.h"
#include "map.h"
#include "game.h"


//=============================================================================
// �R���X�g���N�^
//=============================================================================
CActRange::CActRange()
{
	//�ϐ�������
	m_pPlayer = nullptr;
	m_bDeath = false;
	memset(&m_MapData, 0, sizeof(m_MapData));
	memset(&m_ActPos, 0, sizeof(m_ActPos));
	memset(&m_bPlayerMove, true, sizeof(m_bPlayerMove));
	memset(&m_OtherAct, 0, sizeof(m_OtherAct));
	memset(&m_NewActPos, 0, sizeof(m_NewActPos));
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CActRange::~CActRange()
{
}

//=============================================================================
// �v���C���[���ǂ̈ʒu�ɂ��邩
//=============================================================================
void CActRange::PlayerPos(void)
{
	//�}�b�v�f�[�^�����邩
	if (&m_MapData != NULL)
	{
		//�v���C���[�ʒu�擾
		D3DXVECTOR3 PlayerPos = m_pPlayer->GetPos();

		for (int nBlockY = 0; nBlockY < m_MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				D3DXVECTOR3 BlockPos = D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos;
				if (PlayerPos.x>BlockPos.x - TILE_ONE_SIDE / 2
					&& PlayerPos.x<BlockPos.x + TILE_ONE_SIDE / 2
					&& PlayerPos.z>BlockPos.z - TILE_ONE_SIDE / 2
					&& PlayerPos.z<BlockPos.z + TILE_ONE_SIDE / 2)
				{
					//�ʒu�擾
					m_ActPos.x = (float)nBlockX;
					m_ActPos.z = (float)nBlockY;

				}
			}
		}
	}

}

//=============================================================================
// �}�b�v��̃v���C���[�̈ړ�����֐�
//=============================================================================
bool CActRange::ActMove(int nMoveX, int nMoveZ)
{
	//�ړ������擾
	m_NewActPos.x = nMoveX + m_ActPos.x;
	m_NewActPos.z = nMoveZ + m_ActPos.z;
	if (nMoveX<0)
	{
		return m_bPlayerMove[PLAYER_MOVE_RIGHT];
	}
	if (nMoveX>0)
	{
		return m_bPlayerMove[PLAYER_MOVE_LEFT];
	}
	if (nMoveZ<0)
	{
		return m_bPlayerMove[PLAYER_MOVE_UP];
	}
	if (nMoveZ>0)
	{
		return m_bPlayerMove[PLAYER_MOVE_DOWN];
	}

	return false;
}

//=============================================================================
// ���̃v���C���[�ɂԂ���~�܂锻��
//=============================================================================
void CActRange::OtherPlayer(void)
{

	//���X�g�̃g�b�v�擾
	CActRange* pActRange = (CActRange*)GetTop(OBJTYPE_ACT_RANGE);
	//���v���C���[
	int nOtherPlayer = 0;

	//NULL�`�F�b�N
	while (pActRange != NULL)
	{
		//�����ȊO
		if (pActRange != this)
		{
			//�v���C���[�̃}�b�v�ʒu�擾
			m_OtherAct[nOtherPlayer].OtherActPos = pActRange->GetActPos();
			//�v���C���[�̃}�b�v�ړ��ʒu�擾
			m_OtherAct[nOtherPlayer].OtherNewActPos = pActRange->GetNewActPos();
			//�v���C���[������ł��邩
			m_OtherAct[nOtherPlayer].bDeath = pActRange->GetDeath();
			//�v���C���[���ړ����Ă��邩
			m_OtherAct[nOtherPlayer].bMove = pActRange->GetMove();
			//���̃v���C���[��
			nOtherPlayer++;
		}
		//���̃|�C���^��
		pActRange = (CActRange*)pActRange->GetNext();
	}
}

//=============================================================================
// �v���C���[�̈ړ��͈�
//=============================================================================
void CActRange::ActRange(void)
{
	D3DXVECTOR3 Range[PLAYER_MOVE_MAX] =
	{
		D3DXVECTOR3(0,0,-1),
		D3DXVECTOR3(0,0,1),
		D3DXVECTOR3(1,0,0),
		D3DXVECTOR3(-1,0,0)
	};

	//�㉺���E�Ƀv���C���[���ړ��ł��邩
	for (int nMove = 0; nMove<PLAYER_MOVE_MAX; nMove++)
	{
		//�㉺���E�̃^�C�������邩
		if (m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CMapManager::BLOCK_TYPE_NONE
			|| m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CMapManager::BLOCK_TYPE_1P_START
			|| m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CMapManager::BLOCK_TYPE_2P_START
			|| m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CMapManager::BLOCK_TYPE_3P_START
			|| m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CMapManager::BLOCK_TYPE_4P_START)
		{
			//�ړ��ł��Ȃ�����false
			m_bPlayerMove[nMove] = false;
		}
		else
		{
			//�v���C���[�̊m�F
			for (int nPlayer = 0; nPlayer<MAX_PLAYER - 1; nPlayer++)
			{
				if ((m_ActPos + Range[nMove]) == m_OtherAct[nPlayer].OtherActPos && !m_OtherAct[nPlayer].bDeath)
				{
					//�ړ��ł��Ȃ�����false
					m_bPlayerMove[nMove] = false;
					break;
				}
				else if ((m_ActPos + Range[nMove]) == m_OtherAct[nPlayer].OtherNewActPos
					&& !m_OtherAct[nPlayer].bDeath
					&& !m_OtherAct[nPlayer].bMove)
				{
					//�ړ��ł��Ȃ�����false
					m_bPlayerMove[nMove] = false;
					break;
				}
				else
				{
					//�ړ��ł��邽��true
					m_bPlayerMove[nMove] = true;
				}
			}
		}
	}
}

//=============================================================================
// ���������֐�
//=============================================================================
CActRange * CActRange::Create(CPlayer * pPlayer)
{
	//�������m��
	CActRange *pActRange = nullptr;
	pActRange = new CActRange;

	//NULL�`�F�b�N
	if (pActRange != NULL)
	{
		pActRange->SetPriority(OBJTYPE_ACT_RANGE); // �I�u�W�F�N�g�^�C�v
		pActRange->m_pPlayer = pPlayer;	//�v���C���[�̃|�C���^�[
		pActRange->Init();				//����������
	}

	return pActRange;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CActRange::Init(void)
{
	//�}�b�v���擾
	m_MapData = CMapManager::GetMapData(CGame::GetMapType());

	//�ŏ��̈ʒu�擾
	PlayerPos();

	m_NewActPos = m_ActPos;
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CActRange::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CActRange::Update(void)
{

	// ���̃v���C���[�̃}�b�v�ʒu
	OtherPlayer();
	// �v���C���[�̈ړ��͈�
	ActRange();
	// �v���C���[�̈ʒu�擾
	PlayerPos();

}

//=============================================================================
// �`��֐�
//=============================================================================
void CActRange::Draw(void)
{
}

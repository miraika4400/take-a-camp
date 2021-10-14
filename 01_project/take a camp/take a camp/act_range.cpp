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
#include "stage.h"
#include "game.h"


//=============================================================================
// �R���X�g���N�^
//=============================================================================
CActRange::CActRange()
{
	//�ϐ�������
	m_pPlayer = nullptr;
	m_bDeath  = false;
	memset(&m_MapData, 0, sizeof(CStage::MAP_DATA));
	memset(&m_ActPos, 0, sizeof(D3DXVECTOR3));
	memset(&m_bPlayerMove, true, sizeof(bool[PLAYER_MOVE_MAX]));
	memset(&m_OtherAct, 0, sizeof(OTHER_ACT[PLAYER_MOVE_MAX - 1]));
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
				if (PlayerPos.x>BlockPos.x - TILE_ONE_SIDE/2
					&&PlayerPos.x<BlockPos.x + TILE_ONE_SIDE/2
					&&PlayerPos.z>BlockPos.z - TILE_ONE_SIDE/2
					&&PlayerPos.z<BlockPos.z + TILE_ONE_SIDE/2)
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
void CActRange::ActMove(int nMoveX, int nMoveZ)
{
	m_ActPos = D3DXVECTOR3(nMoveX, 0.0f, nMoveZ) + m_ActPos;
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
			//�v���C���[������ł��邩
			m_OtherAct[nOtherPlayer].bDeath = pActRange->GetDeath();
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
		D3DXVECTOR3(-1,0,0),
		D3DXVECTOR3(1,0,0),
		D3DXVECTOR3(0,0,1)
	};

	//�㉺���E�Ƀv���C���[���ړ��ł��邩
	for (int nMove = 0; nMove<PLAYER_MOVE_MAX; nMove++)
	{
		//�㉺���E�̃^�C�������邩
		if (m_MapData.BlockData[(int)(m_ActPos.z + Range[nMove].z)].nBlockType[(int)(m_ActPos.x + Range[nMove].x)] == CStage::BLOCK_TYPE_NONE)
		{
			//�ړ��ł��Ȃ�����false
			m_bPlayerMove[nMove] = false;
		}
		else
		{
			for (int nPlayer = 0; nPlayer<MAX_PLAYER - 1; nPlayer++)
			{
				if ((m_ActPos + Range[nMove]) == m_OtherAct[nPlayer].OtherActPos && !m_OtherAct[nPlayer].bDeath)
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
	m_MapData = CGame::GetStage()->GetMapData();

	//�ŏ��̈ʒu�擾
	PlayerPos();
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
	//���̃v���C���[�̃}�b�v�ʒu
	OtherPlayer();
	// �v���C���[�̈ړ��͈�
	ActRange();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CActRange::Draw(void)
{
}

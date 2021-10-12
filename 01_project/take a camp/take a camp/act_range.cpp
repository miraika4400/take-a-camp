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
	memset(&m_MapData, 0, sizeof(CStage::MAP_DATA));
	memset(&m_PlayerPos, 0, sizeof(D3DXVECTOR3));
	memset(&m_bPlayerMove, true, sizeof(bool[PLAYER_MOVE_MAX]));
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
					m_PlayerPos.x = (float)nBlockX;
					m_PlayerPos.z = (float)nBlockY;
				}
			}
		}
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
		if (m_MapData.BlockData[(int)(m_PlayerPos.z + Range[nMove].z)].nBlockType[(int)(m_PlayerPos.x + Range[nMove].x)] == CStage::BLOCK_TYPE_NONE)
		{
			//�ړ��ł��Ȃ�����false
			m_bPlayerMove[nMove] = false;
		}
		else
		{
			//�ړ��ł��邽��true
			m_bPlayerMove[nMove] = true;
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
	//�ŏ��̈ʒu�擾
	PlayerPos();
	//�}�b�v���擾
	m_MapData = CGame::GetStage()->GetMapData();
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
	//�ŏ��̈ʒu�擾
	PlayerPos();

	// �v���C���[�̈ړ��͈�
	ActRange();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CActRange::Draw(void)
{
}

//=============================================================================
//
// �}�b�v�N���X [map.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "map.h"
#include "tile.h"
#include "color_tile.h"
#include "player.h"
#include "spawn_tile.h"
#include "color_manager.h"
#include "item.h"
#include <time.h>

//=============================================================================
// �}�N����`
//=============================================================================
#define COLOR_TILE_PLUS_HEIGHT 0.0f // �J���[�^�C���������ЂƂ������邽�тɐ����ʒu����������
#define COLOR_TILE_INIT_HEIGHT -TILE_SIZE_Y/2 // �J���[�^�C�����߂̍���
//#define COLOR_TILE_PLUS_HEIGHT 50.0f // �J���[�^�C���������ЂƂ������邽�тɐ����ʒu����������
//#define COLOR_TILE_INIT_HEIGHT 500.0f // �J���[�^�C�����߂̍���
#define MAX_ITEM_SPAWN_COUNT (60*10)	//�A�C�e���X�|�[���̍ő�J�E���g

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CMap::CMap()
{
	m_nItemSpawnCount = 0;
	memset(&m_MapData, 0, sizeof(m_MapData));
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CMap::~CMap()
{
}

//=============================================================================
// ���������֐�
//=============================================================================
CMap * CMap::Create(CMapManager::MAP_TYPE MapType)
{
	// �������̊m��
	CMap *pMap;
	pMap = new CMap;
	if (pMap != NULL)
	{
		//�}�b�v���擾
		pMap->SetMapData(CMapManager::GetMapData(MapType));
		//����������
		pMap->Init();
	}

	return pMap;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CMap::Init(void)
{
	//�}�b�v����
	MapCreate();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CMap::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CMap::Update(void)
{
	ItemSpawn();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CMap::Draw(void)
{

}
//=============================================================================
// �}�b�v�����֐�
//=============================================================================
void CMap::MapCreate(void)
{
	//�}�b�v�f�[�^�����邩
	if (&m_MapData != NULL)
	{
		float ColorTileHeight = COLOR_TILE_INIT_HEIGHT;

		for (int nBlockY = 0; nBlockY < m_MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				//�}�X�ڂ̃^�C�v�擾
				switch (m_MapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case CMapManager::BLOCK_TYPE_NONE:	//�Ȃ�
					break;
				case CMapManager::BLOCK_TYPE_1P_START:	//1P�X�^�[�g�ʒu
				{
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f,0.0f,0.0f), 0);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(0).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, TILE_POS_Y, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case CMapManager::BLOCK_TYPE_2P_START:	//2P�X�^�[�g�ʒu
				{
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(1).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, TILE_POS_Y, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case CMapManager::BLOCK_TYPE_3P_START:	//3P�X�^�[�g�ʒu
				{
			
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 2);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(2).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, TILE_POS_Y, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case CMapManager::BLOCK_TYPE_4P_START:	//4P�X�^�[�g�ʒu
				{
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(3).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, TILE_POS_Y, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case CMapManager::BLOCK_TYPE_BLOCK:	//���u���^�C��
				{
					CColorTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, ColorTileHeight, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					ColorTileHeight += COLOR_TILE_PLUS_HEIGHT;
					break;
				}
				default:
					break;
				}
			}
		}
	}
}

//=============================================================================
// �}�b�v�f�[�^�Z�b�^�[�֐�
//=============================================================================
void CMap::SetMapData(CMapManager::MAP_DATA MapData)
{
	m_MapData = MapData;
}

//=============================================================================
// �}�b�v�f�[�^�Q�b�^�[�֐�
//=============================================================================
CMapManager::MAP_DATA CMap::GetMapData(void)
{
	return m_MapData;
}

//=============================================================================
// �A�C�e���X�|�[�������֐�
//=============================================================================
void CMap::ItemSpawn(void)
{
	//�J�E���g�A�b�v
	m_nItemSpawnCount++;
	//�J�E���g�����ɂȂ�����
	if (m_nItemSpawnCount >= MAX_ITEM_SPAWN_COUNT)
	{
		//�A�C�e���̃X�|�[���ʒu
		D3DXVECTOR3 ItemPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		//�����_���֐��̏�����
		srand((unsigned int)time(NULL));
		int nPosY = rand() % m_MapData.nStageSizeY;
		int nPosX = rand()% m_MapData.BlockData[nPosY].nStageSizeX;
		//�����_���Ɍ��߂��}�X�ڂɈړ��ł��邩
		while (m_MapData.BlockData[nPosY].nBlockType[nPosX] != CMapManager::BLOCK_TYPE_BLOCK)
		{
			nPosY = rand() % m_MapData.nStageSizeY;
			nPosX = rand() % m_MapData.BlockData[nPosY].nStageSizeX;
		}
		
		//�A�C�e�������ʒu�ݒ�
		ItemPos = D3DXVECTOR3(TILE_ONE_SIDE*-nPosX, 3.0f, TILE_ONE_SIDE*nPosY);
		//�A�C�e������
		CItem::Create(ItemPos + m_MapData.m_pos);
		//�J�E���g������
		m_nItemSpawnCount = 0;
	}
}

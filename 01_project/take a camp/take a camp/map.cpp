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
#include "player.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CMap::CMap()
{
	memset(&m_MapData, 0, sizeof(CMapManager::MAP_DATA));
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
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 0);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_2P_START:	//2P�X�^�[�g�ʒu
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 1);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_3P_START:	//3P�X�^�[�g�ʒu
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 2);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_4P_START:	//4P�X�^�[�g�ʒu
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 3);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_BLOCK:	//���u���^�C��
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				}
			}
		}
	}
}

void CMap::SetMapData(CMapManager::MAP_DATA MapData)
{
	m_MapData = MapData;
}

CMapManager::MAP_DATA CMap::GetMapData(void)
{
	return m_MapData;
}

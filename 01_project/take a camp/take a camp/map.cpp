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
#include "needle_tile.h"
#include "item.h"
#include <time.h>
#include "chara_select.h"
#include "tile_factory.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define COLOR_TILE_PLUS_HEIGHT 0.0f				// �J���[�^�C���������ЂƂ������邽�тɐ����ʒu����������
#define COLOR_TILE_INIT_HEIGHT -TILE_SIZE_Y/2	// �J���[�^�C�����߂̍���
//#define COLOR_TILE_PLUS_HEIGHT 50.0f // �J���[�^�C���������ЂƂ������邽�тɐ����ʒu����������
//#define COLOR_TILE_INIT_HEIGHT 500.0f // �J���[�^�C�����߂̍���
#define MAX_ITEM_SPAWN_COUNT (60*10)	// �A�C�e���X�|�[���̍ő�J�E���g
#define MAX_ITEM (3)					// �}�b�v��̍ő��

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CMap::CMap() :CScene(OBJTYPE_SYSTEM)
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
	// �^�C�����X�g�̃��Z�b�g
	CTile::ResetTileList();

	//�}�b�v�f�[�^�����邩
	if (&m_MapData != NULL)
	{
		float ColorTileHeight = COLOR_TILE_INIT_HEIGHT;

		for (int nBlockY = 0; nBlockY < m_MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				CTileFactory* pTileFactory = CTileFactory::GetTileFactory();

				D3DXCOLOR tileCol = TILE_DEFAULT_COLOR;

				// �v���C���[�̐���
				switch (m_MapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case CMapManager::BLOCK_TYPE_1P_START:	//1P�X�^�[�g�ʒu

					if (CCharaSelect::GetEntryData(0).bEntry)
					{
						CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0);
						tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(0).iconColor;
					}

					break;
				case CMapManager::BLOCK_TYPE_2P_START:	//2P�X�^�[�g�ʒu
					if (CCharaSelect::GetEntryData(1).bEntry)
					{
						CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1);
						tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(1).iconColor;
					}

					break;
				case CMapManager::BLOCK_TYPE_3P_START:	//3P�X�^�[�g�ʒu
					if (CCharaSelect::GetEntryData(2).bEntry)
					{
						CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 2);
						tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(2).iconColor;
					}
					break;
				case CMapManager::BLOCK_TYPE_4P_START:	//4P�X�^�[�g�ʒu
					if (CCharaSelect::GetEntryData(3).bEntry)
					{
						CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3);
						tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(3).iconColor;
					}
					break;
				}

				// �^�C���̐���
				if (pTileFactory != NULL
					&&pTileFactory->GetCreateFunction(m_MapData.BlockData[nBlockY].nBlockType[nBlockX]) != NULL)
				{
					pTileFactory->GetCreateFunction(m_MapData.BlockData[nBlockY].nBlockType[nBlockX])(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, ColorTileHeight, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
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
		//�����̃A�C�e���ʒu
		D3DXVECTOR3 OtherItem[MAX_ITEM];
		memset(&OtherItem, 0, sizeof(OtherItem));
		//�A�C�e���|�C���^�擾
		CItem * pItem = (CItem*)GetTop(OBJTYPE_ITEM);
		//�A�C�e���̌��J�E���g�ϐ�
		int nItemCount = 0;
		
		//���̃A�C�e���̃|�C���^���擾
		while (pItem != NULL)
		{
			if (nItemCount<MAX_ITEM)
			{
				//���̃A�C�e���̈ʒu�擾
				OtherItem[nItemCount] = pItem->GetPos();
				//�A�C�e���J�E���g
				nItemCount++;
			}
			pItem = (CItem*)pItem->GetNext();
		}

		//�}�b�v��̃A�C�e�������E�𒴂��Ă��Ȃ���
		if (nItemCount < MAX_ITEM)
		{
			//�A�C�e���̃X�|�[���ʒu
			D3DXVECTOR3 ItemPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//�ʒu���ߗp�̕ϐ�
			int nPosY, nPosX;
			//�����ł��邩�̃t���O�ϐ�
			bool bItem = false;
			//�����_���֐��̏�����
			srand((unsigned int)time(NULL));

			while (!bItem)
			{
				//���[�v�p�Ƀt���O�𗧂Ă�
				bItem = true;

				//�����_���Ƀ}�b�v��̈ʒu�����߂�
				nPosY = rand() % m_MapData.nStageSizeY;
				nPosX = rand() % m_MapData.BlockData[nPosY].nStageSizeX;

				//�����_���Ɍ��߂��}�X�ڂ������ł���}�X�ڂ�
				if (m_MapData.BlockData[nPosY].nBlockType[nPosX] == CMapManager::BLOCK_TYPE_BLOCK)
				{
					//�����ʒu
					ItemPos = D3DXVECTOR3(TILE_ONE_SIDE*-nPosX, 3.0f, TILE_ONE_SIDE*nPosY) + m_MapData.m_pos;
					
					//���A�C�e���Ƃ��Ԃ�Ȃ��悤��
					for (int nOtherItem = 0; nOtherItem < nItemCount; nOtherItem++)
					{
						//�����ꏊ�ɃA�C�e�������邩
						if (ItemPos.x <= (OtherItem[nOtherItem].x + 5.0f)
							&& ItemPos.x >= (OtherItem[nOtherItem].x - 5.0f)
							&& ItemPos.z <= (OtherItem[nOtherItem].z + 5.0f)
							&& ItemPos.z >= (OtherItem[nOtherItem].z - 5.0f))
						{
							//���[�v�𑱂���
							bItem = false;
							break;
						}
					}
				}
				//�����_���Ɍ��߂��}�X�������ł��Ȃ���
				else
				{
					//���[�v�𑱂���
					bItem = false;
				}
			}
			//�A�C�e������
			CItem::Create(ItemPos, (CItem::ITEM_EFFECT)(rand() % CItem::ITEM_EFFECT_MAX));
		}
	
		//�J�E���g������
		m_nItemSpawnCount = 0;
	}
}

//=============================================================================
//
// �X�e�[�W [stage.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "stage.h"
#include "tile.h"
#include "color_tile.h"
#include "player.h"
#include "spawn_tile.h"
#include "color_manager.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define SQUARE_SIZE (20)	//�P�}�X�c���̃T�C�Y
#define COLOR_TILE_PLUS_HEIGHT 0.0f // �J���[�^�C���������ЂƂ������邽�тɐ����ʒu����������
#define COLOR_TILE_INIT_HEIGHT -TILE_SIZE_Y/2 // �J���[�^�C�����߂̍���
//#define COLOR_TILE_PLUS_HEIGHT 150.0f // �J���[�^�C���������ЂƂ������邽�тɐ����ʒu����������
//#define COLOR_TILE_INIT_HEIGHT 1000.0f // �J���[�^�C�����߂̍���

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
char* CStage::m_pFileName = "data/Text/stage02.csv";
CStage::MAP_DATA CStage::m_MapData = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CStage::CStage()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CStage::~CStage()
{
}

//=============================================================================
// ���[�h�֐�
//=============================================================================
void CStage::Load(void)
{
	//�t�@�C���|�C���^
	FILE*	pFile;
	//�ǂݍ��ݗp�f�[�^
	char cFileString[258];
	//�����F��
	int nFileText;
	//��A�s
	int nCol, nRow;
	//�u���b�N��
	int nBlock;
	//������
	pFile = NULL;
	nCol = 1;
	nRow = 0;
	nBlock = 0;
	memset(cFileString, 0, sizeof(cFileString));

	//�t�@�C���ǂݍ���
	fopen_s(&pFile, m_pFileName, "r");

	if (pFile != NULL)
	{
		//�w�b�_�[�ǂݔ�΂�
		while (fgetc(pFile) != '\n');

		while (1)
		{
			while (1)
			{
				nFileText = fgetc(pFile);

				//�����Ȃ烋�[�v�𔲂���B
				if (nFileText == EOF)
				{
					goto out;
				}
				//�J���}�����s�łȂ���΁A�����Ƃ��ĂȂ���
				if (nFileText != ',' && nFileText != '\n')
				{
					strcat_s(cFileString, (const char*)&nFileText);
				}
				//�J���}�����s�Ȃ烋�[�v������B
				else
				{
					break;
				}
			}
			//������ǂݍ���
			switch (atoi(cFileString))
			{
			case BLOCK_TYPE_NONE:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NONE;
				break;
			case BLOCK_TYPE_1P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_1P_START;
				break;
			case BLOCK_TYPE_2P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_2P_START;
				break;
			case BLOCK_TYPE_3P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_3P_START;
				break;
			case BLOCK_TYPE_4P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_4P_START;
				break;
			case BLOCK_TYPE_BLOCK:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_BLOCK;
				break;
			}
			//�o�b�t�@�̏�����
			memset(cFileString, 0, sizeof(cFileString));
			//�񐔂𑫂�
			nCol++;

			//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
			if (nFileText == '\n')
			{
				//�s���ۑ�
				m_MapData.BlockData[nRow].nStageSizeX = nCol;
				//�s��������
				nCol = 1;
				//��̐i�s
				nRow++;
			}

		}
	
	out:								//�����Ȃ炱���ɒ���
		m_MapData.nStageSizeY = nRow;	//�u���b�N����ۑ�
		fclose(pFile);					//�t�@�C�������
	
	}

}

//=============================================================================
// ���������֐�
//=============================================================================
CStage * CStage::Create(D3DXVECTOR3 pos)
{
	// �������̊m��
	CStage *pStage;
	pStage = new CStage;

	pStage->m_MapData.m_pos = pos;	//�ʒu�Z�b�g
	pStage->Init();

	return pStage;
}

//=============================================================================
// �������֐�
//=============================================================================
HRESULT CStage::Init(void)
{
	//�}�b�v����
	MapCreate();
	return S_OK;
}

//=============================================================================
// �I���֐�
//=============================================================================
void CStage::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//=============================================================================
// �`��֐�
//=============================================================================
void CStage::Draw(void)
{
}

//=============================================================================
// �X�V�֐�
//=============================================================================
void CStage::Update(void)
{
}

//=============================================================================
// �}�b�v�����֐�
//=============================================================================
void CStage::MapCreate(void)
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
				case BLOCK_TYPE::BLOCK_TYPE_NONE:	//�Ȃ�
					break;
				case BLOCK_TYPE::BLOCK_TYPE_1P_START:	//1P�X�^�[�g�ʒu
				{
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f,0.0f,0.0f), 0);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(0).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
				}
					break;
				case BLOCK_TYPE::BLOCK_TYPE_2P_START:	//2P�X�^�[�g�ʒu
				{
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(1).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case BLOCK_TYPE::BLOCK_TYPE_3P_START:	//3P�X�^�[�g�ʒu
				{
			
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 2);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(2).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case BLOCK_TYPE::BLOCK_TYPE_4P_START:	//4P�X�^�[�g�ʒu
				{
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3);
					D3DXCOLOR tileCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(3).iconColor;
					CSpawnTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, tileCol);
					break;
				}
				case BLOCK_TYPE::BLOCK_TYPE_BLOCK:	//���u���^�C��
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
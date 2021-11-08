//=============================================================================
//
// �}�b�v�ǂݍ��݃N���X[resource_map.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "resource_map.h"
#include "tile.h"
#include "player.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define SQUARE_SIZE (20)	//�P�}�X�c���̃T�C�Y

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
char* CMapManager::m_pFileName[MAP_TYPE_MAX] =
{
	
	"data/Text/stage/stage04.csv" ,
	"",
	"",
	""
};
CMapManager *CMapManager::m_pMapBasis = NULL;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CMapManager::CMapManager()
{
	memset(&m_MapData, 0, sizeof(m_MapData));
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CMapManager::~CMapManager()
{
}

//=============================================================================
// �N���X����
//=============================================================================
CMapManager * CMapManager::Create(void)
{
	// NULL�`�F�b�N
	if (m_pMapBasis == NULL)
	{
		//�������m��
		m_pMapBasis = new CMapManager;

		if (m_pMapBasis != NULL)
		{
			// �������m�ې���
			m_pMapBasis->Load();
		}
		else
		{
			// �������m�ێ��s
			return NULL;
		}
	}

	return m_pMapBasis;
}

//=============================================================================
// �N���X�j��
//=============================================================================
void CMapManager::Release(void)
{
	if (m_pMapBasis != NULL)
	{
		// �������̔j��
		delete m_pMapBasis;
		m_pMapBasis = NULL;
	}

}

//=============================================================================
// �}�b�v�f�[�^�Q�b�^�[����
//=============================================================================
CMapManager::MAP_DATA CMapManager::GetMapData(MAP_TYPE MapData)
{
	if (m_pMapBasis != NULL)
	{
		return m_pMapBasis->m_MapData[MapData];
	}
	else
	{
		return{};
	}
	
}

//=============================================================================
// ���[�h�֐�
//=============================================================================
void CMapManager::Load(void)
{
	for (int nMap = 0; nMap < MAP_TYPE_MAX; nMap++)
	{
		//�t�@�C���|�C���^
		FILE*	pFile = NULL;
		//�ǂݍ��ݗp�f�[�^
		char cFileString[258];
		//�����F��
		int nFileText;
		//��A�s
		int nCol, nRow;
		//�u���b�N��
		int nBlock;
		//������
		nCol = 1;
		nRow = 0;
		nBlock = 0;
		memset(cFileString, 0, sizeof(cFileString));

		//�t�@�C���ǂݍ���
		fopen_s(&pFile, m_pFileName[nMap], "r");

		if (pFile != NULL)
		{
			//���S�l�̎擾�p�ϐ�
			int nCneterX, nCneterY, nCneterZ;
			//�����ʒu�ǂݍ���
			fscanf_s(pFile, "CENTER_POS,%d,%d,%d", &nCneterX, &nCneterY, &nCneterZ);
			//�����ʒu�C��
			m_MapData[nMap].m_pos = D3DXVECTOR3(TILE_ONE_SIDE * nCneterX + TILE_ONE_SIDE/2.0f, TILE_ONE_SIDE * nCneterY, TILE_ONE_SIDE * -nCneterZ);
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
				// ������ǂݍ���
				//switch (atoi(cFileString))
				//{
				//case BLOCK_TYPE_NONE:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NONE;
				//	break;
				//case BLOCK_TYPE_1P_START:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_1P_START;
				//	break;
				//case BLOCK_TYPE_2P_START:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_2P_START;
				//	break;
				//case BLOCK_TYPE_3P_START:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_3P_START;
				//	break;
				//case BLOCK_TYPE_4P_START:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_4P_START;
				//	break;
				//case BLOCK_TYPE_BLOCK:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_BLOCK;
				//	break;
				//case BLOCK_TYPE_NEEDLE_BLOCK:
				//	m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NEEDLE_BLOCK;
				//	break;
				//}

				m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = atoi(cFileString);

				//�o�b�t�@�̏�����
				memset(cFileString, 0, sizeof(cFileString));
				//�񐔂𑫂�
				nCol++;

				//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
				if (nFileText == '\n')
				{
					//�s���ۑ�
					m_MapData[nMap].BlockData[nRow].nStageSizeX = nCol;
					//�s��������
					nCol = 1;
					//��̐i�s
					nRow++;
				}

			}

		out:								//�����Ȃ炱���ɒ���
			m_MapData[nMap].nStageSizeY = nRow;	//�u���b�N����ۑ�
			fclose(pFile);					//�t�@�C�������
		}
	}

}

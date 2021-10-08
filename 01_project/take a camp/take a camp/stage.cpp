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

//=============================================================================
// �}�N����`
//=============================================================================
#define SQUARE_SIZE (50)	//�P�}�X�c���̃T�C�Y

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
char* CStage::m_pFileName = "data/Text/stage.csv";
CStage::MAP_DATA CStage::m_pMapData = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CStage::CStage()
{
	m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
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
				m_pMapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NONE;
				break;
			case BLOCK_TYPE_:
				m_pMapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_;
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
				m_pMapData.BlockData[nRow].nStageSizeX = nCol;
				//�s��������
				nCol = 1;
				//��̐i�s
				nRow++;
			}

		}
	
	out:								//�����Ȃ炱���ɒ���
		m_pMapData.nStageSizeY = nRow;	//�u���b�N����ۑ�
		fclose(pFile);					//�t�@�C�������
	
	}

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
	if (&m_pMapData != NULL)
	{
		for (int nBlockY = 0; nBlockY < m_pMapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_pMapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				//�}�X�ڂ̃^�C�v�擾
				switch (m_pMapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case BLOCK_TYPE::BLOCK_TYPE_NONE:	//�Ȃ�

					break;
				case BLOCK_TYPE::BLOCK_TYPE_:		//���u���^�C��
					CModel::Create(D3DXVECTOR3((float)SQUARE_SIZE * -nBlockX, 0.0f, (float)SQUARE_SIZE * nBlockY) + m_pos, CResourceModel::MODEL_GENERAL_BOX, D3DXVECTOR3(50.0f, 50.0f, 50.0f));
					break;
				}
			}
		}
	}
}
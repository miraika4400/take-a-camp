////////////////////////////////////////////////////
//
//    tile_factory�N���X�̏���[tile_factory.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "tile_factory.h"
#include "tile.h"
#include "color_tile.h"
#include "needle_tile.h"
#include "spawn_tile.h"
//*****************************
// �}�N����`
//*****************************
#define TILE_DATA_TEXT ("data/Text/tile_data.csv")

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
std::vector<CTile::SENTENCE_FUNC> CTileFactory::m_CreateSentence = {};
CTileFactory* CTileFactory::m_pInstance = NULL;
const std::vector<CTileFactory::LabelData> CTileFactory::m_cLabelData = 
{
	{ "TILE_NONE"   , NULL},
	{ "TILE_"       , NULL },
	{ "TILE_NORMAL" , CColorTile::Create },
	{ "TILE_PLAYER" , CSpawnTile::Create },
	{ "TILE_NEEDLE" , CNeedleTile::Create },
};

//******************************
// �R���X�g���N�^
//******************************
CTileFactory::CTileFactory()
{
}

//******************************
// �f�X�g���N�^
//******************************
CTileFactory::~CTileFactory()
{
}

//******************************
// �N���X����
//******************************
CTileFactory* CTileFactory::Create(void)
{
	// �������̊m��
	if (m_pInstance == NULL)
	{
		m_pInstance = new CTileFactory;
		// ������
		m_pInstance->Init();
	}
	
	return m_pInstance;
}

//******************************
// ����������
//******************************
HRESULT CTileFactory::Init(void)
{
	// �f�[�^�̓ǂݍ���
	LoadTileData();

	return S_OK;
}

//******************************
// �I������
//******************************
void CTileFactory::Uninit(void)
{
	m_CreateSentence.clear();
}

//******************************
// �������
//******************************
void CTileFactory::Release(void)
{
	m_pInstance->Uninit();
	delete m_pInstance;
	m_pInstance = NULL;
}

//******************************
// �^�C���f�[�^�̃��[�h����
//******************************
void CTileFactory::LoadTileData(void)
{
	//�t�@�C���|�C���^
	FILE*	pFile = NULL;
	//�ǂݍ��ݗp�f�[�^
	char cFileString[256];
	ZeroMemory(cFileString, sizeof(cFileString));

	//�t�@�C���ǂݍ���
	fopen_s(&pFile, TILE_DATA_TEXT, "r");

	if (pFile != NULL)
	{
		// �f�[�^��
		int nDataNum = 0;
		fscanf(pFile, "Tile_Data_Num,,%d", &nDataNum);

		m_CreateSentence.resize(nDataNum);

		for (int nCntData = 0; nCntData < nDataNum; nCntData++)
		{
			// �z��ԍ��̓ǂݍ���
			int nIndex = 0;
			fscanf(pFile, "%d%s", &nIndex, cFileString);

			// �]�v�ȕ����������p�̃X�g�����O�^
			std::string str = cFileString;

			// "TILE_"�̈ʒu�̌���
			int nTileDatNum = str.find("TILE_");
			
			// �s���Ȓl������Ȃ��悤�ɂ���
			if (nTileDatNum < 0 || (int)str.length() < nTileDatNum)
			{
				continue;
			}

			// �]�v�ȕ���������
			sscanf(&str.c_str()[nTileDatNum], "%s", cFileString);

			for (int nCntLabelData = 0; nCntLabelData < (int)m_cLabelData.size(); nCntLabelData++)
			{
				// �ǂݍ��񂾕�����ƃ��x���f�[�^�̔�r
				if (strcmp(m_cLabelData.at(nCntLabelData).strLabelName.c_str(), cFileString) == 0)
				{
					// ��v���Ă���֐��|�C���^�z��Ɋi�[
					m_CreateSentence.at(nIndex) = m_cLabelData.at(nCntLabelData).createFunction;
				}
			}
		}
		
		// �t�@�C���N���[�Y
		fclose(pFile);
	}
}

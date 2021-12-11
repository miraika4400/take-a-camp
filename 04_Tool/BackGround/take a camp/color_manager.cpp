////////////////////////////////////////////////////
//
//    color_manager�N���X�̏���[color_manager.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "color_manager.h"

//*****************************
// �}�N����`
//*****************************
#define COLOR_DATA_PATH "data/Text/color_data.txt"

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
// �����o�ϐ�
CColorManager * CColorManager::m_pInstance = NULL;

//******************************
// �R���X�g���N�^
//******************************
CColorManager::CColorManager()
{
	m_aColorData.clear();
}

//******************************
// �f�X�g���N�^
//******************************
CColorManager::~CColorManager()
{
}

//******************************
// �N���X����
//******************************
CColorManager * CColorManager::Create(void)
{
	if (m_pInstance == NULL)
	{
		// �������̊m��
		m_pInstance = new CColorManager;

		// ������
		m_pInstance->Init();
	}

	return m_pInstance;
}

//******************************
// ����������
//******************************
HRESULT CColorManager::Init(void)
{
	// �x�N�^�[�̏�����
	m_aColorData.clear();

	// �J���[�f�[�^�̓ǂݍ���
	LoadText();

	return S_OK;
}

//******************************
// �I������
//******************************
void CColorManager::Uninit(void)
{
}

//******************************
// �j������
//******************************
void CColorManager::Release(void)
{
	m_pInstance->Uninit();
	delete m_pInstance;
}

//******************************
// �g���Ă���v���C���[�ԍ��̃��Z�b�g
//******************************
void CColorManager::UseNumReset(void)
{
	for (int nCnt = 0; nCnt < (int)m_aColorData.size(); nCnt++)
	{
		m_aColorData[nCnt].nUsePlayerNum = -1;
	}
}

CColorManager::ColorData CColorManager::GetColorDataByPlayerNumber(int nPlayerNum)
{
	for (int nCnt = 0; nCnt < (int)m_aColorData.size(); nCnt++)
	{
		if (m_aColorData[nCnt].nUsePlayerNum == nPlayerNum)
		{
			return m_aColorData[nCnt];
		}
	}

	// �Ώۂ��Ȃ������ꍇ�͔z��0�Ԗڂ�Ԃ�
	return m_aColorData[0];
}

//******************************
// �e�L�X�g�f�[�^�̓ǂݍ���
//******************************
void CColorManager::LoadText(void)
{
	// �t�@�C���I�[�v��
	FILE*pFile = NULL;
	pFile = fopen(COLOR_DATA_PATH, "r");

	if (pFile != NULL)
	{
		// �e�L�X�g�t�@�C���̉��

		// ����̕�������p
		char chChar[256] = {};
		fscanf(pFile, "%s", chChar);

		// "COLOR_NUM"�ǂݍ��ނ܂Ń��[�v
		while (strcmp(chChar, "COLOR_NUM") != 0)
		{
			fscanf(pFile, "%s", chChar);
		}

		int nColorElementNum;

		// = �J���[��
		fscanf(pFile, "%*s %d", &nColorElementNum);
		// �v�f�����m��
		m_aColorData.resize(nColorElementNum);

		// "END"�ǂݍ��ނ܂Ń��[�v
		while (strcmp(chChar, "END") != 0)
		{
			// "COLOR_DATA"�ǂݍ��ނ܂Ń��[�v
			while (strcmp(chChar, "COLOR_DATA") != 0)
			{
				fscanf(pFile, "%s", chChar);
			}

			int nIndex = 0;

			// �z��ԍ�
			fscanf(pFile, "%*s %*c %d", &nIndex);

			for (int nCnColStep = 0; nCnColStep < COLOR_STEP_NUM; nCnColStep++)
			{// �F�i�K�̊i�[
				fscanf(pFile, "%*s %*s %f %f %f %f", &m_aColorData[nIndex].aCol[nCnColStep].r, 
					                                 &m_aColorData[nIndex].aCol[nCnColStep].g, 
					                                 &m_aColorData[nIndex].aCol[nCnColStep].b, 
					                                 &m_aColorData[nIndex].aCol[nCnColStep].a);
			}
			// �A�C�R���J���[					  	 
			fscanf(pFile, "%*s %*s %f %f %f %f", &m_aColorData[nIndex].iconColor.r,
				                                 &m_aColorData[nIndex].iconColor.g,
				                                 &m_aColorData[nIndex].iconColor.b,
				                                 &m_aColorData[nIndex].iconColor.a);

			m_aColorData[nIndex].nUsePlayerNum = -1;
			fscanf(pFile, "%*s %s", chChar);
		}

		// �t�@�C���N���[�Y
		fclose(pFile);
	}
}

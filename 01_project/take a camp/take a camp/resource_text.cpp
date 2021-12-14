////////////////////////////////////////////////////
//
//    resource_model_hierarchy�N���X�̏���[resource_model_hierarchy.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "resource_text.h"
#include "renderer.h"
#include "manager.h"
#include <map>
#include "text.h"
#include <fstream>

//******************************
// �}�N����`
//******************************
#define TUTORIAL_FILENAME ("data/Text/tutorial.txt")

//******************************
// �ÓI�����o�ϐ��錾
//******************************
CResourceText *CResourceText::m_pSingle = nullptr; // �e�L�X�g�|�C���^*�V���O���g���p

//===================================
// �R���X�g���N�^
//===================================
CResourceText::CResourceText()
{
	memset(&m_pSingle, 0, sizeof(m_pSingle));
}

//===================================
// �f�X�g���N�^
//===================================
CResourceText::~CResourceText()
{
}

//=============================================================================
//���f���N���X�̃N���G�C�g����
//=============================================================================
CResourceText * CResourceText::Create(void)
{
	if (m_pSingle == NULL)
	{
		// �������m��
		m_pSingle = new CResourceText;

		if (m_pSingle != NULL)
		{
			// �������m�ۂɐ��������Ƃ�
			m_pSingle->Load();
		}
		else
		{
			// �������m�ۂɎ��s�����Ƃ�
			return NULL;
		}
	}

	return m_pSingle;
}

//===================================
// �N���X�̔j��
//===================================
void CResourceText::Release(void)
{
	if (m_pSingle != NULL)
	{
		// �e�N�X�`���j��
		m_pSingle->Unload();
		// �������̔j��
		delete m_pSingle;
		m_pSingle = NULL;
	}
}

//===================================
// �e�N�X�`���ǂݍ���
//===================================
void CResourceText::Load(void)
{
	// �t�@�C���|�C���g
	FILE *pFile = NULL;

	// �ϐ��錾
	char cReadText[256];	// �����Ƃ��ēǂݎ��p
	char cHeadText[256];	// �����̔��ʗp
	char cDie[256];			// �g��Ȃ�����
	int nTextNum = 0;		// �^�C�v�̃i���o�[
	std::map<int, std::string> Map;

	std::ifstream ifs(TUTORIAL_FILENAME);
	std::string str;
	if (ifs)
	{
		// SCRIPT�̕�����������܂�
		while (str.find("SCRIPT") != 0)
		{
			getline(ifs, str);
		}
		// str��SCRIPT�̎�
		if (str.find("SCRIPT") == 0)
		{
			// cHeadText��END_SCRIPT�ɂȂ�܂�
			while (str.find("END_SCRIPT") != 0)
			{
				getline(ifs, str);
				// cHeadText��EFFECT_DATASET�̎�
				if (str.find("TEXT_DATASET") == 0)
				{
					// cHeadText��END_EFFECT_DATASET�ɂȂ�܂�
					while (str.find("END_TEXT_DATASET") != 0)
					{
						getline(ifs, str);

						if (str.find("SS") == 0)
						{
							Map[nTextNum] = str;
						}

						if (str.find("ENTER") == 0)
						{
							Map[nTextNum] = str;
						}
						nTextNum++;
					}
				}
			}
		}

		// �t�@�C�������
		fclose(pFile);
	}

	//======================================================================================
	//// �`���[�g���A���e�L�X�g�t�@�C�����J��
	//pFile = fopen(TUTORIAL_FILENAME, "r");

	//// �J������
	//if (pFile != NULL)
	//{
	//	// SCRIPT�̕�����������܂�
	//	while (strcmp(cHeadText, "SCRIPT") != 0)
	//	{
	//		// �e�L�X�g����cReadText���������󂯎��
	//		fgets(cReadText, sizeof(cReadText), pFile);

	//		// cReedText��cHeadText�Ɋi�[
	//		sscanf(cReadText, "%s", &cHeadText);
	//	}
	//	// cHeadText��SCRIPT�̎�
	//	if (strcmp(cHeadText, "SCRIPT") == 0)
	//	{
	//		// cHeadText��END_SCRIPT�ɂȂ�܂�
	//		while (strcmp(cHeadText, "END_SCRIPT") != 0)
	//		{
	//			fgets(cReadText, sizeof(cReadText), pFile);
	//			sscanf(cReadText, "%s", &cHeadText);

	//			// cHeadText��EFFECT_DATASET�̎�
	//			if (strcmp(cHeadText, "TEXT_DATASET") == 0)
	//			{
	//				// cHeadText��END_EFFECT_DATASET�ɂȂ�܂�
	//				while (strcmp(cHeadText, "END_TEXT_DATASET") != 0)
	//				{
	//					fgets(cReadText, sizeof(cReadText), pFile);
	//					sscanf(cReadText, "%s", &cHeadText);

	//					if (strcmp(cHeadText, "SS") == 0)
	//					{
	//						sscanf(cReadText, "%s %s %s", &cDie, &cDie, Map[nTextNum].c_str());
	//					}

	//					if (strcmp(cHeadText, "ENTER") == 0)
	//					{
	//						sscanf(cReadText, "%s %s %s", &cDie, &cDie, Map[nTextNum].c_str());
	//					}


	//					nTextNum++;
	//				}
	//			}
	//		}
	//	}

	//	// �t�@�C�������
	//	fclose(pFile);
	//}
	//// �J���Ȃ�������
	//else
	//{
	//	printf("�J����܂���ł���\n");
	//}
	//======================================================================================



	//for (int nCount = 0; nCount < 100; nCount++)
	//{
	//	Map[0] = "aiueo";
	//}

	//CText::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f), 25.0f, 10.0f, Map[0].c_str(), CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

}

//===================================
// �j��
//===================================
void CResourceText::Unload(void)
{
}
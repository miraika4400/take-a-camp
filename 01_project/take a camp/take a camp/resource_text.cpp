//====================================================
//
// resource_text�̏���[resource_text.cpp]
// Author:�ɓ��@�z��
//
//====================================================

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
	int nTextNum = 0;		// �^�C�v�̃i���o�[

	// �t�@�C���ǂݍ���
	std::ifstream ifs(TUTORIAL_FILENAME);

	// ������ێ��p
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
			// str��END_SCRIPT�ɂȂ�܂�
			while (str.find("END_SCRIPT") != 0)
			{
				getline(ifs, str);

				// str��TEXT_DATASET�̎�
				if (str.find("TEXT_DATASET") == 0)
				{
					m_TextMap[nTextNum] = str;
					nTextNum++;

					// str��END_TEXT_DATASET�ɂȂ�܂�
					while (str.find("END_TEXT_DATASET") != 0)
					{
						getline(ifs, str);

						m_TextMap[nTextNum] = str;
						nTextNum++;
					}
				}
			}
		}
	}
}

//===================================
// �j��
//===================================
void CResourceText::Unload(void)
{
	// �}�b�v�̃N���A
	m_TextMap.clear();
}
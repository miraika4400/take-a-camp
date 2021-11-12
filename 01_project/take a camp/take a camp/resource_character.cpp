////////////////////////////////////////////////////
//
//    resource_character�N���X�̏���[resource_character.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "resource_character.h"

//******************************
// �}�N����`
//******************************

//******************************
// �ÓI�����o�ϐ��錾
//******************************
// �C���X�^���X
CResourceCharacter *CResourceCharacter::m_pInstance = NULL;
// �L�����N�^�[���x�����X�g
const std::vector<CResourceCharacter::LabelData> m_aLabelList =
{
	{ "KNIGHT", CResourceModelHierarchy::MODEL_HIERARCHY_KNIGHT },
	{ "LANCER", CResourceModelHierarchy::MODEL_HIERARCHY_LANCER },
	{ "WIZARD", CResourceModelHierarchy::MODEL_HIERARCHY_WIZARD },
}; 
// �L�����N�^�[�f�[�^�̃e�L�X�g�̃p�X
const std::string CResourceCharacter::m_aCharacterDataTxtPath[CResourceCharacter::CHARACTER_MAX] =
{
	"data/Text/caracter/CharacterData_Knight.txt",
	"data/Text/caracter/CharacterData_Knight.txt",
	"data/Text/caracter/CharacterData_Knight.txt",
};

//===================================
// �R���X�g���N�^
//===================================
CResourceCharacter::CResourceCharacter()
{
	m_aCharacterData.clear();
}

//===================================
// �f�X�g���N�^
//===================================
CResourceCharacter::~CResourceCharacter()
{
}

//=============================================================================
//���f���N���X�̃N���G�C�g����
//=============================================================================
CResourceCharacter * CResourceCharacter::Create(void)
{
	if (m_pInstance == NULL)
	{
		// �������m��
		m_pInstance = new CResourceCharacter;

		if (m_pInstance != NULL)
		{
			// �������m�ۂɐ��������Ƃ�
			m_pInstance->Load();
		}
		else
		{
			// �������m�ۂɎ��s�����Ƃ�
			return NULL;
		}
	}

	return m_pInstance;
}

//===================================
// �N���X�̔j��
//===================================
void CResourceCharacter::Release(void)
{
	if (m_pInstance != NULL)
	{
		// �������̔j��
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

//===================================
// �e�N�X�`���ǂݍ���
//===================================
void CResourceCharacter::Load(void)
{
	//�t�@�C���|�C���^
	FILE*	pFile = NULL;

	for (int nCntText = 0; nCntText < CHARACTER_MAX; nCntText++)
	{
		//�t�@�C���ǂݍ���
		pFile = fopen(m_aCharacterDataTxtPath[nCntText].c_str(), "r");

		if (pFile == NULL)
		{
			continue;
		}
		
		// �t�@�C���N���[�Y
		fclose(pFile);
	}
}

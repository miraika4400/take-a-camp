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
CResourceCharacter* CResourceCharacter::m_pInstance = NULL;
// �L�����N�^�[���x�����X�g
const std::vector<CResourceCharacter::LabelData> CResourceCharacter::m_aLabelList =
{
	{ "KNIGHT", CResourceModelHierarchy::MODEL_HIERARCHY_KNIGHT },
	{ "LANCER", CResourceModelHierarchy::MODEL_HIERARCHY_LANCER },
	{ "WIZARD", CResourceModelHierarchy::MODEL_HIERARCHY_WIZARD },
	{ "THIEF", CResourceModelHierarchy::MODEL_HIERARCHY_THIEF },
	{ "MAGICIAN", CResourceModelHierarchy::MODEL_HIERARCHY_MAGICIAN },
	{ "ARCHER", CResourceModelHierarchy::MODEL_HIERARCHY_ARCHER },
}; 
// �L�����N�^�[�f�[�^�̃e�L�X�g�̃p�X
const std::string CResourceCharacter::m_aCharacterDataTxtPath[CResourceCharacter::CHARACTER_MAX] =
{
	"data/Text/character/CharacterData_Knight.txt",
	"data/Text/character/CharacterData_Lancer.txt",
	"data/Text/character/CharacterData_Wizard.txt",
	"data/Text/character/CharacterData_Thief.txt",
	"data/Text/character/CharacterData_Magician.txt",
	"data/Text/character/CharacterData_Archer.txt",
};

//===================================
// �R���X�g���N�^
//===================================
CResourceCharacter::CResourceCharacter()
{
	//ZeroMemory(&m_aCharacterData, sizeof(m_aCharacterData));
	for (int nCnt = 0; nCnt < CHARACTER_MAX; nCnt++)
	{
		m_aCharacterData[nCnt].nFinalAttackTime = 0;
		m_aCharacterData[nCnt].nMoveFrame = 0;
		m_aCharacterData[nCnt].nMoveFrameDash = 0;
		m_aCharacterData[nCnt].modelType = CResourceModelHierarchy::MODEL_HIERARCHY_KNIGHT;
		ZeroMemory(&m_aCharacterData[nCnt].anChargeTime, sizeof(m_aCharacterData[nCnt].anChargeTime));
	}
	
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
	for (int nCntCharacter = 0; nCntCharacter < CHARACTER_MAX; nCntCharacter++)
	{
		//�t�@�C���|�C���^
		FILE*	pFile = NULL;
		//�t�@�C���ǂݍ���
		pFile = fopen(m_aCharacterDataTxtPath[nCntCharacter].c_str(), "r");
		if (pFile == NULL)
		{
			continue;
		}
		while (1)
		{
			char chInTextData[256] = {};
			// ������̎擾
			fscanf(pFile, "%s", chInTextData);

			// �������r
			auto JudgeStr = [&chInTextData](const char* pStr)
			{
				if (strcmp(pStr, chInTextData) == 0) return true;

				return false;
			};

			// ���[�v�I������
			if (JudgeStr("CHARACTER_DATA_END")) break;
			// ���x��
			else if (JudgeStr("LABEL"))
			{// ���x�����X�g���烂�f���^�C�v�̐ݒ�
				// ������̎擾
				fscanf(pFile, " %*c %s", chInTextData);
				// ���x�����X�[�v
				for (int nCntModel = 0; nCntModel < (int)m_aLabelList.size(); nCntModel++)
				{
					// ���x���f�[�^�̎Q��
					if (!JudgeStr(m_aLabelList[nCntModel].labelName.c_str())) continue;

					// ���f���^�C�v�̐ݒ�
					m_aCharacterData[nCntCharacter].modelType = m_aLabelList[nCntModel].modelType;
					break;
				}
			}
			// �ړ���
			else if (JudgeStr("MOVE_FRAME"))
			{
				int nMoveFrame = 0;
				fscanf(pFile, " %*c %d", &nMoveFrame);
				m_aCharacterData[nCntCharacter].nMoveFrame = nMoveFrame;
			}
			// �ړ���*�_�b�V����
			else if (JudgeStr("MOVE_FRAME_DASH"))
			{
				int nMoveFrame = 0;
				fscanf(pFile, " %*c %d", &nMoveFrame);
				m_aCharacterData[nCntCharacter].nMoveFrameDash = nMoveFrame;
			}
			// ������
			else if (JudgeStr("MOVE_FRAME_INITIAL"))
			{
				int nMoveFrame = 0;
				fscanf(pFile, " %*c %d", &nMoveFrame);
				m_aCharacterData[nCntCharacter].nMoveFrameInitial = nMoveFrame;
			}
			//�����܂ł̉�
			else if (JudgeStr("MOVE_COUNT"))
			{
				int nMoveFrame = 0;
				fscanf(pFile, " %*c %d", &nMoveFrame);
				m_aCharacterData[nCntCharacter].nMoveCount = nMoveFrame;
			}
			// �U���p�X
			else if (JudgeStr("ATTACK_PATH"))
			{
				// ������̎擾
				fscanf(pFile, " %*c %s", chInTextData);
				m_aCharacterData[nCntCharacter].attackTextPath = chInTextData;
			}
			// �K�E�Z��������
			else if (JudgeStr("FINAL_ATTACK_TIME"))
			{
				int nTime = 0;
				fscanf(pFile, " %*c %d", &nTime);
				m_aCharacterData[nCntCharacter].nFinalAttackTime = nTime;
			}
			// �U���̃`���[�W����
			else if (JudgeStr("CHARGE_TIME_LIST"))
			{
				int nIndex, nTime;
				for (int nCntCharge = 0; nCntCharge < ATTACK_PATTARN_NUM; nCntCharge++)
				{
					fscanf(pFile, "%d %*c %d", &nIndex, &nTime);
					m_aCharacterData[nCntCharacter].anChargeTime[nIndex] = nTime;
				}
			}
			// ���[�V�����e�L�X�g
			else if (JudgeStr("MOTION_LIST"))
			{
				char cMotionPath[128] = {};
				for (int nCntMotion = 0; nCntMotion < MOTION_MAX; nCntMotion++)
				{
					fscanf(pFile, "%s %*c %s", &chInTextData, &cMotionPath);

					if      (JudgeStr("IDLE"))   m_aCharacterData[nCntCharacter].aMotionTextPath[MOTION_IDLE]   = cMotionPath;
					else if (JudgeStr("CHARGE")) m_aCharacterData[nCntCharacter].aMotionTextPath[MOTION_CHARGE] = cMotionPath;
					else if (JudgeStr("ATTACK")) m_aCharacterData[nCntCharacter].aMotionTextPath[MOTION_ATTACK] = cMotionPath;
				}
			}
		}

		// �t�@�C���N���[�Y
		fclose(pFile);
	}
}

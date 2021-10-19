//=============================================================================
//
// �X�e�[�W [stage.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_manager.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define SQUARE_SIZE (20)	//�P�}�X�c���̃T�C�Y

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
char* CAttackManager::m_pFileName[ATTACK_TYPE_MAX] =
{
	"data/Text/attack_1.csv" ,
	"",
	"",
	""
};
CAttackManager* CAttackManager::m_pAttackBasis = NULL;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackManager::CAttackManager()
{
	memset(&m_AttackData, 0, sizeof(ATTACK_DATA[ATTACK_TYPE_MAX]));
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackManager::~CAttackManager()
{
}


//=============================================================================
// ���[�h�֐�
//=============================================================================
void CAttackManager::Load(void)
{
	for (int nAttack = 0; nAttack < ATTACK_TYPE_MAX; nAttack++)
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
		pFile = NULL;
		nCol = 1;
		nRow = 0;
		nBlock = 0;
		memset(cFileString, 0, sizeof(cFileString));

		//�t�@�C���ǂݍ���
		fopen_s(&pFile, m_pFileName[nAttack], "r");

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
				case ATTACK_RANGE_NONE:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_NONE;
					break;
				case ATTACK_RANGE_CENTER:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_CENTER;
					break;
				case ATTACK_RANGE_HIT:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT;
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
					m_AttackData[nAttack].RangeData[nRow].nAttackRangeX = nCol;
					//�s��������
					nCol = 1;
					//��̐i�s
					nRow++;
				}

			}

		out:								//�����Ȃ炱���ɒ���
			m_AttackData[nAttack].nAttackRangeY = nRow;	//�u���b�N����ۑ�
			fclose(pFile);					//�t�@�C�������
		}
	}

}

//=============================================================================
// �N���X����
//=============================================================================
CAttackManager * CAttackManager::Create(void)
{
	// NULL�`�F�b�N
	if (m_pAttackBasis == NULL)
	{
		//�������m��
		m_pAttackBasis = new CAttackManager;

		if (m_pAttackBasis != NULL)
		{
			// �������m�ې���
			m_pAttackBasis->Load();
		}
		else
		{
			// �������m�ێ��s
			return NULL;
		}
	}

	return m_pAttackBasis;
}

//=============================================================================
// �N���X�j��
//=============================================================================
void CAttackManager::Release(void)
{
	if (m_pAttackBasis != NULL)
	{
		// �������̔j��
		delete m_pAttackBasis;
		m_pAttackBasis = NULL;
	}
}

//=============================================================================
// �U���͈̓Q�b�^�[����
//=============================================================================
CAttackManager::ATTACK_DATA CAttackManager::GetAttackData(ATTACK_TYPE Attack)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackData[Attack];
	}
	else
	{
		return {};
	}
}


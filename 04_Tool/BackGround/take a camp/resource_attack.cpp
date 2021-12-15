//=============================================================================
//
// �U���͈͓ǂݍ��݃N���X [resource_attack.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "resource_attack.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define SQUARE_SIZE (20)	//�P�}�X�c���̃T�C�Y

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
//char* CAttackManager::m_pFileName[ATTACK_TYPE_MAX] =
//{
//	"data/Text/attack/attack_1.csv" ,
//	"",
//	"",
//	""
//};
CAttackManager* CAttackManager::m_pAttackBasis = NULL;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackManager::CAttackManager()
{
	memset(&m_AttackData, 0, sizeof(ATTACK_RANGE_DATA[CResourceCharacter::CHARACTER_MAX][MAX_ATTACK_LEVEL]));
	memset(&m_AttackSwuare, 0, sizeof(ATTACK_SQUARE_DATA[CResourceCharacter::CHARACTER_MAX][MAX_ATTACK_LEVEL]));

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
	for (int nAttack = 0; nAttack < CResourceCharacter::CHARACTER_MAX; nAttack++)
	{
		//�t�@�C���|�C���^
		FILE*	pFile = NULL;
		//�ǂݍ��ݗp�f�[�^
		char cFileString[258];
		//�����F��
		int nFileText;
		//��A�s
		int nCol, nRow;
		//���x��
		int nLveel = 0;
		//������
		pFile = NULL;
		nCol = 1;
		nRow = 0;

		//������
		memset(cFileString, 0, sizeof(cFileString));
		
		//�t�@�C���ǂݍ���
		fopen_s(&pFile, CResourceCharacter::GetResourceCharacter()->GetCharacterData((CResourceCharacter::CHARACTER_TYPE)nAttack).attackTextPath.c_str(), "r");

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
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_NONE;
					break;
				case ATTACK_RANGE_CENTER:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_CENTER;
					break;
				case ATTACK_RANGE_HIT_1:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_1;
					break;
				case ATTACK_RANGE_HIT_2:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_2;
					break;
				case ATTACK_RANGE_HIT_3:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_3;
					break;
				case ATTACK_RANGE_HIT_4:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_4;
					break;
				case ATTACK_RANGE_HIT_5:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_5;
					break;
				case ATTACK_RANGE_HIT_6:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_6;
					break;
				case ATTACK_RANGE_HIT_7:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_7;
					break;
				case ATTACK_RANGE_HIT_8:
					m_AttackData[nAttack][nLveel].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_8;
					break;

				}
				//�U���^�C�v���Ƃ̑��x
				if (strcmp(cFileString, "AttackFrame") == 0)
				{
					fscanf_s(pFile, "�T:%d,�U:%d,�V:%d,�W:%d,�X:%d,�Y:%d,�Z:%d,�[:%d", 
						&m_AttackData[nAttack][nLveel].nAttackFrame[0],
						&m_AttackData[nAttack][nLveel].nAttackFrame[1],
						&m_AttackData[nAttack][nLveel].nAttackFrame[2],
						&m_AttackData[nAttack][nLveel].nAttackFrame[3],
						&m_AttackData[nAttack][nLveel].nAttackFrame[4],
						&m_AttackData[nAttack][nLveel].nAttackFrame[5],
						&m_AttackData[nAttack][nLveel].nAttackFrame[6],
						&m_AttackData[nAttack][nLveel].nAttackFrame[7] );
				}

				//LevelUp�̕�����ǂݍ��񂾂�
				if (strcmp(cFileString, "LevelUp") == 0)
				{
					//�u���b�N����ۑ�
					m_AttackData[nAttack][nLveel].nAttackRangeY = nRow;
					nRow = 0;
					//���x���̒i�K���グ��
					nLveel++;
				}

				//�o�b�t�@�̏�����
				memset(cFileString, 0, sizeof(cFileString));
				//�񐔂𑫂�
				nCol++;


				//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
				if (nFileText == '\n')
				{
					//�s���ۑ�
					m_AttackData[nAttack][nLveel].RangeData[nRow].nAttackRangeX = nCol;
					//�s��������
					nCol = 1;
					//��̐i�s
					nRow++;
				}

			}

		out:								//�����Ȃ炱���ɒ���
			m_AttackData[nAttack][nLveel].nAttackRangeY = nRow;	//�u���b�N����ۑ�
			fclose(pFile);					//�t�@�C�������
		}
	}

}

//=============================================================================
// �ʒu�̌v�Z�֐�
//=============================================================================
void CAttackManager::PosCalc(void)
{
	for (int nAttack = 0; nAttack < CResourceCharacter::CHARACTER_MAX; nAttack++)
	{
		for (int nLevel=0; nLevel<MAX_ATTACK_LEVEL; nLevel++)
		{
			//�U���}�X�p�ϐ�
			D3DXVECTOR3 RangePos[MAX_ATTACK_SIZE_Y*MAX_ATTACK_SIZE_X] = {};
			//�v���C���[�����钆�S�}�X�p�ϐ�
			D3DXVECTOR3 Center = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

			//�}�b�v�f�[�^�����邩
			if (&m_AttackData[nAttack][nLevel] != NULL)
			{
				// �ʒu�擾
				for (int nBlockY = 0; nBlockY < m_AttackData[nAttack][nLevel].nAttackRangeY; nBlockY++)
				{
					for (int nBlockX = 0; nBlockX < m_AttackData[nAttack][nLevel].RangeData[nBlockY].nAttackRangeX; nBlockX++)
					{
						//�}�X�ڂ̃^�C�v�擾
						switch (m_AttackData[nAttack][nLevel].RangeData[nBlockY].nRangeType[nBlockX])
						{
						case CAttackManager::ATTACK_RANGE_NONE:		//�Ȃ�
							break;
						case CAttackManager::ATTACK_RANGE_CENTER:	//�v���C���[�����钆�S�܂�
							Center = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							break;
						case CAttackManager::ATTACK_RANGE_HIT_1:	//�U���͈�
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_1;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;
						case CAttackManager::ATTACK_RANGE_HIT_2:	//�U���͈�
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_2;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;

						case CAttackManager::ATTACK_RANGE_HIT_3:	//�U���͈�
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_3;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;

						case CAttackManager::ATTACK_RANGE_HIT_4:	//�U���͈�
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_4;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;
						case CAttackManager::ATTACK_RANGE_HIT_5:	/*�U���͈�*/
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_5;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;
						case CAttackManager::ATTACK_RANGE_HIT_6:	/*�U���͈�*/
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_6;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;
						case CAttackManager::ATTACK_RANGE_HIT_7:	/*�U���͈�*/
																	//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_7;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;
						case CAttackManager::ATTACK_RANGE_HIT_8:	/*�U���͈�*/
							//�ʒu�擾
							RangePos[m_AttackSwuare[nAttack][nLevel].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
							//�}�X�̃^�C�v�擾
							m_AttackSwuare[nAttack][nLevel].SquareData[m_AttackSwuare[nAttack][nLevel].nMaxHitRange].RangeType = ATTACK_RANGE_HIT_8;
							//�U���}�X�̍ő�𑝂₷
							m_AttackSwuare[nAttack][nLevel].nMaxHitRange++;
							break;
						default:
							break;
						}
					}
				}
				//�U�����x�̎擾
				for (int nAttackFrame = 0; nAttackFrame < MAX_HIT_TYPE; nAttackFrame++)
				{
					m_AttackSwuare[nAttack][nLevel].nAttackFrame[nAttackFrame] = m_AttackData[nAttack][nLevel].nAttackFrame[nAttackFrame];
				}

				// �ʒu�v�Z
				for (int nAttackPos = 0; nAttackPos < m_AttackSwuare[nAttack][nLevel].nMaxHitRange; nAttackPos++)
				{
					m_AttackSwuare[nAttack][nLevel].SquareData[nAttackPos].AttackPos = RangePos[nAttackPos] - Center;
				}
			}
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
			// �ʒu�v�Z
			m_pAttackBasis->PosCalc();
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
CAttackManager::ATTACK_RANGE_DATA CAttackManager::GetAttackData(CResourceCharacter::CHARACTER_TYPE type, int nLevel)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackData[type][nLevel];
	}
	else
	{
		return {};
	}
}

//=============================================================================
// �U���}�X���Q�b�^�[�֐�
//=============================================================================
CAttackManager::ATTACK_SQUARE_DATA CAttackManager::GetAttack(CResourceCharacter::CHARACTER_TYPE type, int nLevel)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackSwuare[type][nLevel];
	}
	else
	{
		return{};
	}
}

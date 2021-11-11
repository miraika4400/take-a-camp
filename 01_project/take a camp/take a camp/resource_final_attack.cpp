//=============================================================================
//
// �K�E�Z�͈͓ǂݍ��݃N���X [resource_final_attack.cpp]
// Author : �g�c�I�l
//
//=============================================================================
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "resource_final_attack.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define SQUARE_SIZE (20)	//�P�}�X�c���̃T�C�Y

//=============================================================================
// �ÓI�����o�[�ϐ�
//=============================================================================
char* CFinalAttackManager::m_pFileName[FINAL_ATTACK_TYPE_MAX] =
{
	"data/Text/final_attack_1.csv" ,
	"",
	"",
	""
};
CFinalAttackManager* CFinalAttackManager::m_pAttackBasis = NULL;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CFinalAttackManager::CFinalAttackManager()
{
	memset(&m_AttackData, 0, sizeof(m_AttackData));
	memset(&m_AttackSwuare, 0, sizeof(m_AttackSwuare));

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CFinalAttackManager::~CFinalAttackManager()
{
}


//=============================================================================
// ���[�h�֐�
//=============================================================================
void CFinalAttackManager::Load(void)
{
	for (int nAttack = 0; nAttack < FINAL_ATTACK_TYPE_MAX; nAttack++)
	{
		//�t�@�C���|�C���^
		FILE*	pFile = NULL;
		//�ǂݍ��ݗp�f�[�^
		char cFileString[258];
		//�����F��
		int nFileText;
		//��A�s
		int nCol, nRow;
		//������
		pFile = NULL;
		nCol = 1;
		nRow = 0;

		//������
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
				case FINAL_ATTACK_RANGE_NONE:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_NONE;
					break;
				case FINAL_ATTACK_RANGE_CENTER:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_CENTER;
					break;
				case FINAL_ATTACK_RANGE_HIT_1:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_1;
					break;
				case FINAL_ATTACK_RANGE_HIT_2:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_2;
					break;
				case FINAL_ATTACK_RANGE_HIT_3:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_3;
					break;
				case FINAL_ATTACK_RANGE_HIT_4:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_4;
					break;
				case FINAL_ATTACK_RANGE_HIT_5:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_5;
					break;
				case FINAL_ATTACK_RANGE_HIT_6:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_6;
					break;
				case FINAL_ATTACK_RANGE_HIT_7:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_7;
					break;
				case FINAL_ATTACK_RANGE_HIT_8:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_8;
					break;

				}
				//�U���^�C�v���Ƃ̑��x
				if (strcmp(cFileString, "AttackFrame") == 0)
				{
					fscanf_s(pFile, "�T:%d,�U:%d,�V:%d,�W:%d,�X:%d,�Y:%d,�Z:%d,�[:%d",
						&m_AttackData[nAttack].nAttackFrame[0],
						&m_AttackData[nAttack].nAttackFrame[1],
						&m_AttackData[nAttack].nAttackFrame[2],
						&m_AttackData[nAttack].nAttackFrame[3],
						&m_AttackData[nAttack].nAttackFrame[4],
						&m_AttackData[nAttack].nAttackFrame[5],
						&m_AttackData[nAttack].nAttackFrame[6],
						&m_AttackData[nAttack].nAttackFrame[7]);
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
// �ʒu�̌v�Z�֐�
//=============================================================================
void CFinalAttackManager::PosCalc(void)
{
	for (int nAttack = 0; nAttack < FINAL_ATTACK_TYPE_MAX; nAttack++)
	{
		//�U���}�X�p�ϐ�
		D3DXVECTOR3 RangePos[MAX_FINAL_ATTACK_SIZE_Y*MAX_FINAL_ATTACK_SIZE_X] = {};
		//�v���C���[�����钆�S�}�X�p�ϐ�
		D3DXVECTOR3 Center = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�}�b�v�f�[�^�����邩
		if (&m_AttackData[nAttack] != NULL)
		{
			// �ʒu�擾
			for (int nBlockY = 0; nBlockY < m_AttackData[nAttack].nAttackRangeY; nBlockY++)
			{
				for (int nBlockX = 0; nBlockX < m_AttackData[nAttack].RangeData[nBlockY].nAttackRangeX; nBlockX++)
				{
					//�}�X�ڂ̃^�C�v�擾
					switch (m_AttackData[nAttack].RangeData[nBlockY].nRangeType[nBlockX])
					{
					case CFinalAttackManager::FINAL_ATTACK_RANGE_NONE:		//�Ȃ�
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_CENTER:	//�v���C���[�����钆�S�܂�
						Center = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_1:	//�U���͈�
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_1;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_2:	//�U���͈�
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_2;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;

					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_3:	//�U���͈�
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_3;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;

					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_4:	//�U���͈�
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_4;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_5:	/*�U���͈�*/
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_5;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_6:	/*�U���͈�*/
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_6;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_7:	/*�U���͈�*/
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_7;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_8:	/*�U���͈�*/
																//�ʒu�擾
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//�}�X�̃^�C�v�擾
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_8;
						//�U���}�X�̍ő�𑝂₷
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					default:
						break;
					}
				}
			}
			//�U�����x�̎擾
			for (int nAttackFrame = 0; nAttackFrame < MAX_FINAL_HIT_TYPE; nAttackFrame++)
			{
				m_AttackSwuare[nAttack].nAttackFrame[nAttackFrame] = m_AttackData[nAttack].nAttackFrame[nAttackFrame];
			}

			// �ʒu�v�Z
			for (int nAttackPos = 0; nAttackPos < m_AttackSwuare[nAttack].nMaxHitRange; nAttackPos++)
			{
				m_AttackSwuare[nAttack].SquareData[nAttackPos].AttackPos = RangePos[nAttackPos] - Center;
			}
		}

	}

}

//=============================================================================
// �N���X����
//=============================================================================
CFinalAttackManager * CFinalAttackManager::Create(void)
{
	// NULL�`�F�b�N
	if (m_pAttackBasis == NULL)
	{
		//�������m��
		m_pAttackBasis = new CFinalAttackManager;

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
void CFinalAttackManager::Release(void)
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
CFinalAttackManager::FINAL_ATTACK_RANGE_DATA CFinalAttackManager::GetFinalAttackData(FINAL_ATTACK_TYPE Attack)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackData[Attack];
	}
	else
	{
		return{};
	}
}

//=============================================================================
// �U���}�X���Q�b�^�[�֐�
//=============================================================================
CFinalAttackManager::FINAL_ATTACK_SQUARE_DATA CFinalAttackManager::GetFinalAttack(FINAL_ATTACK_TYPE AttackType)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackSwuare[AttackType];
	}
	else
	{
		return{};
	}
}

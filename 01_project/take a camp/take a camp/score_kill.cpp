//===================================================
//
//    �L���X�R�A�N���X�̏���[score_kill.cpp]
//    Author : �g�c �I�l
//
//====================================================

//**********************************
//�C���N���[�h
//**********************************
#include "score_kill.h"
#include "number.h"
#include "chara_select.h"
#include "kill_count.h"

//**********************************
//�C���N���[�h
//**********************************
#define SCORE_SIZE		(D3DXVECTOR3(40.0f, 30.0f, 0.0f))
#define CREATE_POS_Y	(500.0f)
#define SCORE_SPACE		(150.0f)
//==================================
// �R���X�g���N�^
//==================================
CScoreKill::CScoreKill()
{
	//������
	memset(m_apNumber, 0, sizeof(m_apNumber));		// �i���o�[�̃N���A
	memset(m_nKillScore, 0, sizeof(m_nKillScore));	// �X�R�A
	memset(m_pos, 0, sizeof(m_pos));// �ʒu
	for (int nPlayer=0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		m_col[nPlayer] = D3DXCOLOR(0.8f, 0.3f, 0.8f, 1.0f);	// �J���[
	}
	m_nPlayerNum = 0;
}

//==================================
// �f�X�g���N�^
//==================================
CScoreKill::~CScoreKill()
{
}

//==================================
// �N���G�C�g
//==================================
CScoreKill * CScoreKill::Create(void)
{
	// �������̊m��
	CScoreKill *pScoreKill = NULL;
	pScoreKill = new CScoreKill;

	//NULL�`�F�b�N
	if (pScoreKill != NULL)
	{
		// ����������
		pScoreKill->Init();
		// �I�u�W�F�N�g�^�C�v�̐ݒ�
		pScoreKill->SetPriority(OBJTYPE_UI);
	}
	return pScoreKill;
}

//==================================
// ����������
//==================================
HRESULT CScoreKill::Init(void)
{	
	// �v���C���[�l���擾
	m_nPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// X�������p�ϐ�
	float fPosX = (SCREEN_WIDTH / 2) - (((float)(m_nPlayerNum - 1) * SCORE_SPACE) / 2) - ((SCORE_SIZE.x/2)*(MAX_KILL_SCORE_DIGIT-1));

	// �ő包�������[�v
	for (int nPlayer = 0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		//�v���C�l��������
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			for (int nCntDigit = 0; nCntDigit < MAX_KILL_SCORE_DIGIT; nCntDigit++)
			{
				m_apNumber[nPlayer][nCntDigit] = CNumber::Create(0,
					D3DXVECTOR3((float)(fPosX - nCntDigit * (SCORE_SIZE.x)), CREATE_POS_Y, 0.0f),
					SCORE_SIZE,
					m_col[nPlayer]);
			}
			fPosX += SCORE_SPACE;
		}
	}

	// �ő包�������[�v
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			SetKillScore(nPlayer, CKillCount::GetTotalKill(nPlayer));
		}
	}

	return S_OK;
}

//==================================
// �I������
//==================================
void CScoreKill::Uninit(void)
{
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		for (int nCntDigit = 0; nCntDigit < MAX_KILL_SCORE_DIGIT; nCntDigit++)
		{
			if (m_apNumber[nPlayer][nCntDigit] != NULL)
			{
				m_apNumber[nPlayer][nCntDigit]->Uninit();
				delete m_apNumber[nPlayer][nCntDigit];
				m_apNumber[nPlayer][nCntDigit] = NULL;
			}
		}
	}

	// �J������
	Release();
}

//==================================
// �X�V����
//==================================
void CScoreKill::Update(void)
{
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		for (int nCntDigit = 0; nCntDigit < MAX_KILL_SCORE_DIGIT; nCntDigit++)
		{
			//NULL�`�F�b�N
			if (m_apNumber[nPlayer][nCntDigit] != NULL)
			{
				m_apNumber[nPlayer][nCntDigit]->Update();

			}
		}
	}
}

//==================================
// �`�揈��
//==================================
void CScoreKill::Draw(void)
{
	for (int nPlayer = 0; nPlayer < MAX_PLAYER; nPlayer++)
	{
		for (int nCntDigit = 0; nCntDigit < MAX_KILL_SCORE_DIGIT; nCntDigit++)
		{
			//NULL�`�F�b�N
			if (m_apNumber[nPlayer][nCntDigit] != NULL)
			{
				m_apNumber[nPlayer][nCntDigit]->Draw();
			}
		}
	}
}

//=============================
// �X�R�A�v�Z����
//=============================
void CScoreKill::SetKillScore(int nPlayer, int nScore)
{
	int nInteger = 0;//�v�Z�p�ϐ�

	for (int nCntDigit = 0; nCntDigit < MAX_KILL_SCORE_DIGIT; nCntDigit++)
	{
		nInteger = int(nScore / pow(10, nCntDigit + 1)); //1�̈ʈȉ���؂�̂Ă�
		nInteger = int(nInteger * pow(10, nCntDigit + 1));
		m_apNumber[nPlayer][nCntDigit]->SetNumber(int((nScore - nInteger) / pow(10, nCntDigit)));
	}
}

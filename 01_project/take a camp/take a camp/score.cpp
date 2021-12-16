//===================================================
//
// �X�R�A�\������ [score.cpp]
//    Author : �g�c �I�l
//
//====================================================

//**********************************
//�C���N���[�h
//**********************************
#include "number.h"
#include "chara_select.h"
#include "score.h"
#include "color_tile.h"

//**********************************
//�C���N���[�h
//**********************************
#define SCORE_SIZE		(D3DXVECTOR3(40.0f, 30.0f, 0.0f))
#define CREATE_POS_Y	(400.0f)
#define SCORE_SPACE		(SCREEN_WIDTH/4)

//==================================
// �R���X�g���N�^
//==================================
CScore::CScore()
{
	//������
	memset(m_apNumber, 0, sizeof(m_apNumber));	// �i���o�[�̃N���A
	memset(m_pos, 0, sizeof(m_pos));			// �ʒu
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	// �J���[
	m_nPlayerNum = 0;
}

//==================================
// �f�X�g���N�^
//==================================
CScore::~CScore()
{
}

//==================================
// �N���G�C�g
//==================================
CScore * CScore::Create(D3DXVECTOR3 pos, D3DXCOLOR col, int nScore)
{
	// �������̊m��
	CScore *pScorePaint = NULL;
	pScorePaint = new CScore;

	//NULL�`�F�b�N
	if (pScorePaint != NULL)
	{
		// �ʒu�ݒ�
		pScorePaint->m_pos = pos;
		// �J���[�ݒ�
		pScorePaint->m_col = col;
		// ����������
		pScorePaint->Init();
		//�X�R�A�Z�b�g
		pScorePaint->SetPaintScore(nScore);
		// �I�u�W�F�N�g�^�C�v�̐ݒ�
		pScorePaint->SetPriority(OBJTYPE_UI_2);
	}
	return pScorePaint;
}

//==================================
// ����������
//==================================
HRESULT CScore::Init(void)
{
	//���l����
	for (int nCntDigit = 0; nCntDigit < MAX_SCORE_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit] = CNumber::Create(0,
			D3DXVECTOR3((float)(m_pos.x - (nCntDigit-1) * (SCORE_SIZE.x)), m_pos.y, 0.0f),
			SCORE_SIZE,
			m_col);
	}

	return S_OK;
}

//==================================
// �I������
//==================================
void CScore::Uninit(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_SCORE_DIGIT; nCntDigit++)
	{
		if (m_apNumber[nCntDigit] != NULL)
		{
			m_apNumber[nCntDigit]->Uninit();
			delete m_apNumber[nCntDigit];
			m_apNumber[nCntDigit] = NULL;
		}
	}

	// �J������
	Release();
}

//==================================
// �X�V����
//==================================
void CScore::Update(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_SCORE_DIGIT; nCntDigit++)
	{
		//NULL�`�F�b�N
		if (m_apNumber[nCntDigit] != NULL)
		{
			m_apNumber[nCntDigit]->Update();

		}
	}
}

//==================================
// �`�揈��
//==================================
void CScore::Draw(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_SCORE_DIGIT; nCntDigit++)
	{
		//NULL�`�F�b�N
		if (m_apNumber[nCntDigit] != NULL)
		{
			m_apNumber[nCntDigit]->Draw();
		}
	}
}

//=============================
// �X�R�A�v�Z����
//=============================
void CScore::SetPaintScore(int nScore)
{
	int nInteger = 0;//�v�Z�p�ϐ�

	for (int nCntDigit = 0; nCntDigit < MAX_SCORE_DIGIT; nCntDigit++)
	{
		nInteger = int(nScore / pow(10, nCntDigit + 1)); //1�̈ʈȉ���؂�̂Ă�
		nInteger = int(nInteger * pow(10, nCntDigit + 1));
		m_apNumber[nCntDigit]->SetNumber(int((nScore - nInteger) / pow(10, nCntDigit)));
	}
}

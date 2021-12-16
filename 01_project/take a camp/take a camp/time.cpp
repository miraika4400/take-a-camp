//===================================================
//
//    time�N���X�̏���[time.cpp]
//    Author:���� �x�ߑ�
//
//====================================================

//**********************************
//�C���N���[�h
//**********************************
#include "manager.h"
#include "fade.h"
#include "time.h"
#include "number.h"

//==================================
// �R���X�g���N�^
//==================================
CTime::CTime()
{
	//�������Ԃ̃N���A
	m_nTime = TIME_UP;
	m_nA = 0;
}

//==================================
// �f�X�g���N�^
//==================================
CTime::~CTime()
{
}

//==================================
// �N���G�C�g
//==================================
CTime * CTime::Create(void)
{
	//�������̊m��
	CTime *pTime = new CTime;

	// ����������
	pTime->Init();

	// �I�u�W�F�N�g�^�C�v�̐ݒ�
	pTime->SetPriority(OBJTYPE_UI_2);

	return pTime;
}

//==================================
// ����������
//==================================
HRESULT CTime::Init(void)
{
	// �ő包�������[�v
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit] = CNumber::Create(0,
			D3DXVECTOR3((float)(1000 + nCntDigit * 40), 50.0f, 0.0f),
			D3DXVECTOR3(20, 20, 0),
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
	return S_OK;
}

//==================================
// �I������
//==================================
void CTime::Uninit(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
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
void CTime::Update(void)
{
	m_nA++;
	if (m_nA % 60 <= 0)
	{
		m_nTime--;
	}
	//�����\��
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit]->Update();

		m_apNumber[nCntDigit]->SetNumber((int)((m_nTime % (int)(powf(10.0f, (MAX_TIME_DIGIT - nCntDigit)))) / (float)(powf(10, (MAX_TIME_DIGIT - nCntDigit - 1)))));
	}
	if (m_nTime <= 0)
	{
		// �f�o�b�O�p��ʑJ�ڃR�}���h
			CManager::GetFade()->SetFade(CManager::MODE_RESULT);
	}
}

//==================================
// �`�揈��
//==================================
void CTime::Draw(void)
{
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		m_apNumber[nCntDigit]->Draw();
	}
}

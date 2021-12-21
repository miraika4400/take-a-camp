//=============================================================================
//
// �c��^�C���̏��� [time_remaining.cpp]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "time_remaining.h"
#include "scene.h"
#include "number.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define REMAINING_TIME 60 

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTime_Remaining::CTime_Remaining() :CScene(OBJTYPE_UI_2)
{
	m_nTime = REMAINING_TIME;	// �c�莞��
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTime_Remaining::~CTime_Remaining()
{

}

//=============================================================================
// ��������
//=============================================================================
CTime_Remaining * CTime_Remaining::Create(void)
{
	CTime_Remaining *pRemaining = NULL;

	// �������̊m��
	pRemaining = new CTime_Remaining;

	// NULL�`�F�b�N
	if (pRemaining != NULL)
	{
		// ������
		pRemaining->Init();

		// �I�u�W�F�N�g�^�C�v
		pRemaining->SetPriority(OBJTYPE_UI_2);
	}

	return pRemaining;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTime_Remaining::Init(void)
{
	// ������
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// �i���o�[��������
		m_apNumber[nCntDigit] = CNumber::Create(0,
			D3DXVECTOR3((float)(SCREEN_WIDTH / 2 + nCntDigit * 75), 100.0f, 0.0f),
			D3DXVECTOR3(75, 75, 0),
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTime_Remaining::Uninit(void)
{
	// ������
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// NULL�`�F�b�N
		if (m_apNumber[nCntDigit] != NULL)
		{
			// �I������
			m_apNumber[nCntDigit]->Uninit();
			delete m_apNumber[nCntDigit];
			m_apNumber[nCntDigit] = NULL;
		}
	}

	// �J������
	Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CTime_Remaining::Update(void)
{
	// �񐔕���
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// �X�V����
		m_apNumber[nCntDigit]->Update();

		// �i���o�[�̔z�u
		m_apNumber[nCntDigit]->SetNumber((int)((m_nTime % (int)(powf(10.0f, (MAX_DIGIT - nCntDigit)))) / (float)(powf(10, (MAX_DIGIT - nCntDigit - 1)))));
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CTime_Remaining::Draw(void)
{
	// �񐔕���
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// �`�揈��
		m_apNumber[nCntDigit]->Draw();
	}
}
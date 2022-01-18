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
#include "game_finish.h"
#include "player.h"
#include "ingame_text.h"
//==================================
// �}�N����`
//==================================
#define REMAINING_POS_Y  (350.0f)	// �c��b��������Y�ʒu
#define REMAINING_SIZE_X (550.0f)	// �c��b��������X�T�C�Y
#define REMAINING_SIZE_Y (150.0f)	// �c��b��������Y�T�C�Y

//==================================
// �R���X�g���N�^
//==================================
CTime::CTime() :CScene(OBJTYPE_UI_2)
{
	//�������Ԃ̃N���A
	m_nTime = TIME_UP;
	m_nA = 0;
	m_bTime = true;
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
			D3DXVECTOR3((float)(590 + nCntDigit * 50), 680.0f, 0.0f),
			D3DXVECTOR3(30, 30, 0),
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
	// �^�C�����g�p���Ă�����
	if (m_bTime == true)
	{
		// ���t���[�����ƂɃJ�E���g�𑝂₵�Ă���
		m_nA++;
		if (m_nA % 60 <= 0)
		{
			// �^�C�������炵�Ă���
			m_nTime--;
		}
	}

	//�����\��
	for (int nCntDigit = 0; nCntDigit < MAX_TIME_DIGIT; nCntDigit++)
	{
		// �i���o�[�̍X�V
		m_apNumber[nCntDigit]->Update();

		// �i���o�[�̔z�u
		m_apNumber[nCntDigit]->SetNumber((int)((m_nTime % (int)(powf(10.0f, (MAX_TIME_DIGIT - nCntDigit)))) / (int)(powf(10, (MAX_TIME_DIGIT - nCntDigit - 1)))));
	}

	// �c�莞�ԕ\��
	RemainingSeconds();

	// ���Ԑ؂ꏈ��
	TimeUp();
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

//=============================================================================
// �v���C���[���~�߂�
// Akuthor: �����D�I
//=============================================================================
void CTime::FinishPlayer(void)
{
	// �v���C���[���̎擾
	CPlayer*pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	// �v���C���[��NULL�łȂ����
	while (pPlayer != NULL)
	{
		// �v���C���[�̃t���O��false��
		pPlayer->SetUpdateFlag(false);

		// ����
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//=============================================================================
// ���Ԑ؂�
// Akuthor: �����D�I
//=============================================================================
void CTime::TimeUp(void)
{
	// 0�ɂȂ�����
	if (m_nTime == 0 && m_nA % 60 <= 0)
	{
		// �J�E���g���~�߂�
		m_nA = 0;
		m_nTime = 0;

		// �v���C���[�̓������~�߂�
		FinishPlayer();

		// FINISH�̐���
		CGameFinish::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, FINISH_POS_Y, 0.0f), D3DXVECTOR3(FINISH_SIZE_X, FINISH_SIZE_Y, 0.0f));
	}
}


//=============================================================================
// �c�艽�b���o��
// Akuthor: �����D�I
//=============================================================================
void CTime::RemainingSeconds(void)
{
	// ��莞�ԂɂȂ�����
	if (m_nTime == 60 && m_nA % 60 <= 0)
	{
		CInGameText::Create(D3DXVECTOR3(1680, REMAINING_POS_Y, 0.0f));
	}
}
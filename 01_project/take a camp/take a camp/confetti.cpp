//===================================================
//
// �����Ꮘ�� [confetti.cpp]
//    Author : ���V ����
//
//====================================================

//**********************************
//�C���N���[�h
//**********************************
#include "confetti.h"

//**********************************
//�}�N����`
//**********************************
#define MIN_SIZE (5.0f)          // �ŏ��T�C�Y
#define RAND_SIZE_AMPLITUDE (10) // �����̂ӂ蕝
#define ADJUST_RAND 100.0f       // ���������������l


//==================================
// �R���X�g���N�^
//==================================
CConfetti::CConfetti() :CScene2d(OBJTYPE_EFFECT_2)
{
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_moveDist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);;
}

//==================================
// �f�X�g���N�^
//==================================
CConfetti::~CConfetti()
{
}

//==================================
// �N���G�C�g
//==================================
CConfetti * CConfetti::Create(void)
{
	// �������̊m��
	CConfetti *pConfetti = NULL;
	pConfetti = new CConfetti;

	//NULL�`�F�b�N
	if (pConfetti != NULL)
	{
		// ����������
		pConfetti->Init();
		// �I�u�W�F�N�g�^�C�v�̐ݒ�
		pConfetti->SetPriority(OBJTYPE_EFFECT_2);
	}
	return pConfetti;
}

//==================================
// ����������
//==================================
HRESULT CConfetti::Init(void)
{
	CScene2d::Create();

	float fRandSize = (float)(rand() % (RAND_SIZE_AMPLITUDE*(int)ADJUST_RAND));
	fRandSize = MIN_SIZE + (fRandSize / ADJUST_RAND);

	return S_OK;
}

//==================================
// �X�V����
//==================================
void CConfetti::Update(void)
{
}

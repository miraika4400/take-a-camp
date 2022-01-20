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
#define MIN_SIZE (10.0f)                // �ŏ��T�C�Y
#define RAND_SIZE_AMPLITUDE (20)       // �����̂ӂ蕝*�T�C�Y
#define ADJUST_RAND (100.0f)           // ���������������l*�����_���o������
#define MIN_LIFE (100)               // �ŏ����C�t
#define RAND_LIFE_AMPLITUDE (20)       // �����̂ӂ蕝*����
#define RAND_MOVE_ANGLE_AMPLITUDE (45) // �����̂ӂ蕝*��������΂��p�x
#define MIN_SPEED (8.0f)               // �ŏ��X�s�[�h
#define RAND_SPEED_AMPLITUDE (10)      // �����̂ӂ蕝*�X�s�[�h
#define ADD_ANGLE (1.0f)                 // �p�x���Z�l
#define MOVE_Y_DIST (5.0f)                      // �ړ���Y�̖ڕW�l
#define MOVE_RATE (0.02f)                       // �ړ��ʂ̌W��
#define SIZE_DIST D3DXVECTOR3(-2.0f,-2.0f,0.0f) // �T�C�Y�̖ڕW�l
#define SIZE_RATE (0.2f)                        // �T�C�Y�̌W��
#define RAND_COLOR_AMPLITUDE (5)                // �����̂ӂ蕝*�F

//==================================
// �R���X�g���N�^
//==================================
CConfetti::CConfetti() :CScene2d(OBJTYPE_EFFECT_2)
{
	m_nTile = 0;
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_fMoveAngle = 0.0f;
	m_fMoveRate = MOVE_RATE;
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
CConfetti * CConfetti::Create(D3DXVECTOR3 pos , D3DXCOLOR col,float fMoveAngle)
{
	// �������̊m��
	CConfetti *pConfetti = NULL;
	pConfetti = new CConfetti;

	//NULL�`�F�b�N
	if (pConfetti != NULL)
	{
		pConfetti->m_fMoveAngle = fMoveAngle;
		// ����������
		pConfetti->Init();
		pConfetti->SetPos(pos);
		
		float fRate = (float)(rand()%RAND_COLOR_AMPLITUDE)/10.0f;
		D3DXCOLOR polygonColor;
		D3DXColorLerp(&polygonColor, &col, &D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), fRate);
		pConfetti->SetColor(polygonColor);
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
	CScene2d::Init();

	// �T�C�Y�̐ݒ�
	float fRandSize = (float)(rand() % (RAND_SIZE_AMPLITUDE*(int)ADJUST_RAND));
	fRandSize = MIN_SIZE + (fRandSize / ADJUST_RAND);
	SetSize(D3DXVECTOR3(fRandSize, fRandSize, 0.0f));

	// �����̐ݒ�
	m_nTile = MIN_LIFE + rand() % RAND_LIFE_AMPLITUDE;
	
	// �����p�x�̐ݒ�
	float fAngle = D3DXToRadian(rand() % 360);
	SetAngle(fAngle);

	// �ړ��p�x�̐ݒ�
	m_fMoveAngle += D3DXToRadian((rand() % RAND_MOVE_ANGLE_AMPLITUDE) - (RAND_MOVE_ANGLE_AMPLITUDE / 2));

	// �X�s�[�h
	float fRandSpeed = (float)(rand() % (RAND_SPEED_AMPLITUDE*(int)ADJUST_RAND));
	fRandSpeed = MIN_SPEED + (fRandSpeed / ADJUST_RAND);

	// �ړ��ʂ̐ݒ�
	m_move = D3DXVECTOR3(cosf(m_fMoveAngle)*fRandSpeed, sinf(m_fMoveAngle)*fRandSpeed*2.0f, 0.0f);

	m_fMoveRate = (float)(rand() % (3 + 1));

	m_fMoveRate = m_fMoveRate / ADJUST_RAND + MOVE_RATE;

	SetAddMode(true);
	return S_OK;
}

//==================================
// �X�V����
//==================================
void CConfetti::Update(void)
{
	// ���W�Ɉړ��ʂ𑫂�
	SetPos(GetPos() + m_move);
	// �ړ��ʂ̕ψ�;
	m_move.y += (MOVE_Y_DIST - m_move.y)*m_fMoveRate;
	// �p�x
	if(m_move.x>=0)SetAngle(GetAngle() + ADD_ANGLE);
	else           SetAngle(GetAngle() + -ADD_ANGLE);

	// ��������
	m_nTile--;
	if (m_nTile < 0)
	{
		// �T�C�Y������������
		D3DXVECTOR3 size = GetSize();
		size += (SIZE_DIST - size)*SIZE_RATE;
		SetSize(size);
		// ����
		if (size.x <= 0)
		{
			Uninit();
		}
	}
}

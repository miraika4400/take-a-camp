//=============================================================================
//
// ���[�v�G�t�F�N�g [warp_effect.cpp]
// Author : �g�c �I�l
//
//=============================================================================

//*****************************
// �C���N���[�h
//*****************************
#include "warp_effect.h"
#include "glitter_effect.h"
#include <time.h>
//******************************
// �}�N����`
//******************************
#define EFFECT_RANGE (D3DXVECTOR3(10.0f,10.0f,10.0f))
#define EFFECT_SPEED (12.0f)

//******************************
// �R���X�g���N�^
//******************************
CWarpEffect::CWarpEffect()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_GoalPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	nCreateCount = 0;
}

//******************************
// �f�X�g���N�^
//******************************
CWarpEffect::~CWarpEffect()
{

}

//******************************
// �N���X����
//******************************
void CWarpEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 GoalPos, D3DXCOLOR col)
{
	//�������m��
	CWarpEffect* pWarpEffect = nullptr;
	pWarpEffect = new CWarpEffect;

	//NULL�`�F�b�N
	if (pWarpEffect != nullptr)
	{

		//�ʒu�ݒ�
		pWarpEffect->m_pos = pos;
		//�ړI�n�ݒ�
		pWarpEffect->m_GoalPos = GoalPos;
		//�F�ݒ�
		pWarpEffect->m_col = col;
		//����������
		pWarpEffect->Init();

	}
}

//******************************
// ����������
//******************************
HRESULT CWarpEffect::Init(void)
{
	//�����_���֐��̏�����
	srand((unsigned int)time(NULL));

	//�ړ��ʂ��v�Z
	D3DXVec3Normalize(&m_move, &(m_GoalPos - m_pos));
	m_move = m_move * EFFECT_SPEED;

	//�J�E���g����
	nCreateCount = rand() % 1;

	return S_OK;
}

//******************************
// �I������
//******************************
void CWarpEffect::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//******************************
// �X�V����
//******************************
void CWarpEffect::Update(void)
{
	//�ʒu�X�V
	m_pos = m_pos + m_move;

	//�G�t�F�N�g�̐���
	CreateEffect();

	//�ړI�n�ɂ�����
	if (pow(m_pos.x - m_GoalPos.x, 2) +
		pow(m_pos.y - m_GoalPos.y, 2) + 
		pow(m_pos.z - m_GoalPos.z, 2) <= pow(5 + 5, 2))
	{
		//�I������
		Uninit();
	}
}

//******************************
// �`�揈��
//******************************
void CWarpEffect::Draw(void)
{
}

//******************************
// �G�t�F�N�g��������
//******************************
void CWarpEffect::CreateEffect(void)
{
	nCreateCount--;

	if (nCreateCount<0)
	{

		int nXpos, nZpos;
		nXpos = (rand() % (int)(EFFECT_RANGE.x*2.0f))-(int)EFFECT_RANGE.x;
		nZpos = (rand() % (int)(EFFECT_RANGE.z*2.0f))-(int)EFFECT_RANGE.z;

		CGlitter::Create(D3DXVECTOR3(m_pos.x + nXpos, m_pos.y+15.0f, m_pos.z + nZpos), 40, m_col);

		nCreateCount = rand() % 2;
	}
}

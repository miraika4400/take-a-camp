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

//******************************
// �R���X�g���N�^
//******************************
CWarpEffect::CWarpEffect()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
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
		//����������
		pWarpEffect->Init();

		//�ʒu�ݒ�
		pWarpEffect->m_pos = pos;
		//�ړI�n�ݒ�
		pWarpEffect->m_GoalPos = GoalPos;
		//�F�ݒ�
		pWarpEffect->m_col = col;

	}
}

//******************************
// ����������
//******************************
HRESULT CWarpEffect::Init(void)
{
	return E_NOTIMPL;
}

//******************************
// �I������
//******************************
void CWarpEffect::Uninit(void)
{
}

//******************************
// �X�V����
//******************************
void CWarpEffect::Update(void)
{
}

//******************************
// �`�揈��
//******************************
void CWarpEffect::Draw(void)
{
}

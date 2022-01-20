//=============================================================================
//
// �X�L���g�����v�G�t�F�N�g ���� [skill_trump.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "skill_trump.h"
#include <time.h>
#include "resource_texture.h"

//*****************************
//�}�N����`
//*****************************
#define TRUMP_SPEED (0.5f)	//�G�t�F�N�g�̃X�s�[�h

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CSkillTrump::CSkillTrump(int nPliority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_ColCount = 0;
	m_MoveAngle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_bDeath = false;
}

//===================================
// �f�X�g���N�^
//===================================
CSkillTrump::~CSkillTrump()
{
}

//===================================
// ���������֐�
//===================================
CSkillTrump * CSkillTrump::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXVECTOR3 MoveAngle, const D3DXCOLOR col)
{
	CSkillTrump* pSkillTrump = nullptr;
	pSkillTrump = new CSkillTrump;

	//NULL�`�F�b�N
	if (pSkillTrump != nullptr)
	{
		//�ړ��p�x�ݒ�
		pSkillTrump->m_MoveAngle = MoveAngle;

		//����������
		pSkillTrump->Init();

		//�ʒu�ݒ�
		pSkillTrump->SetPos(pos);
		//�傫���ݒ�
		pSkillTrump->SetSize(size);
		//�F�ݒ�
		pSkillTrump->SetColor(col);
	}

	return pSkillTrump;
}

//===================================
// ����������
//===================================
HRESULT CSkillTrump::Init(void)
{
	//�r���{�[�h�̏���������
	CBillboard::Init();

	//�e�N�X�`���ݒ�
	BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_TRUMP));

	//�����_���Ɋp�x�����߂�(�}�b�N�X360�x)
	float fAngle = (float)(rand() % 360);
	SetAngle(D3DXToRadian(fAngle));

	//�����������߂�
	AnglePattern = (ANGLE_PATTERN)(rand() % MAX_ANGLE);

	//�ړ��ʐݒ�	
	float fMoveX = TRUMP_SPEED*cosf(m_MoveAngle.z)*cosf(m_MoveAngle.y);
	float fMoveY = TRUMP_SPEED*sinf(m_MoveAngle.z)*2.0f;
	float fMoveZ = TRUMP_SPEED*cosf(m_MoveAngle.z)*-sinf(m_MoveAngle.y);
	m_move = D3DXVECTOR3(fMoveX, fMoveY, fMoveZ);

	return S_OK;
}

//===================================
// �X�V����
//===================================
void CSkillTrump::Update(void)
{
	//�p�x�ύX����
	AngleChange();
	//�ʒu�ύX����
	PosChange();

	//���S�t���O�������Ă��邩
	if (m_bDeath)
	{
		//�I������
		Uninit();
	}
}


//===================================
// �����̕ω�����
//===================================
void CSkillTrump::AngleChange(void)
{
	//�p�x�擾
	float fAngle = GetAngle();
	if (AnglePattern== RIGHT_ANGLE)
	{
		//�������p�x��ς���
		fAngle--;
	}
	else if (AnglePattern == LEFT_ANGLE)
	{
		//�������p�x��ς���
		fAngle++;
	}
	//�p�x�Z�b�g
	SetAngle(fAngle);
}

//===================================
// �ʒu�̕ω�����
//===================================
void CSkillTrump::PosChange(void)
{
	SetPos(GetPos()+m_move);
	// �ړ��ʂ̕ψ�;
	m_move.y -= (2.0f - m_move.y)*0.035f;

	//���̈ʒu�ɗ����
	if (GetPos().y <= -5.0f)
	{
		//���S�t���O�𗧂Ă�
		m_bDeath = true;
	}
}

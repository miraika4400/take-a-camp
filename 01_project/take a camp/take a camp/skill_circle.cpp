//=============================================================================
//
// �X�L���T�[�N������ [skill_circle.cpp]
// Author : �V����s
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "skill_circle.h"
#include "base_Cylinder.h"
#include "resource_texture.h"
#include "manager.h"
#include "renderer.h"
//=============================================================================
//�ÓI�����o�[�ϐ�
//=============================================================================

//=============================================================================
// �}�N����`
//=============================================================================

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CSkill_circle::CSkill_circle(int nPliority)
{
	m_apTexture[EFFECTTYPE_MAX] = {};
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nTile = 50;
	m_fRotAngle = 0.0f;
	m_fFadeout = 0.0f;
	m_bFadeoutFlag = true;
	m_col = { 1.0f,0.0f,0.0f,1.0f };
	m_mtxWorld = {};
	m_bAddMode = false;
	m_type = EFFECTTYPE_SKIIL;
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CSkill_circle::~CSkill_circle()
{
}

//=============================================================================
//���������֐�
//=============================================================================
CSkill_circle * CSkill_circle::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col, const EFFECTTYPE type)
{
	//�C���X�^���X����
	CSkill_circle *pSkill_circle;
	pSkill_circle = new CSkill_circle;
	//����������
	pSkill_circle->Init();

	switch (type)
	{

	case EFFECTTYPE_SKIIL:
		pSkill_circle->SetAddMode(false);
		pSkill_circle->SetHighRot(NORMAL_SKIIL_HIGHROT);
		pSkill_circle->SetRowRot(NORMAL_SKIIL_ROWROT);
		break;

	case EFFECTTYPE_SKIILMINI:
		pSkill_circle->SetAddMode(false);
		pSkill_circle->SetHighRot(NORMAL_SKIIL_HIGHROT);
		pSkill_circle->SetRowRot(NORMAL_SKIIL_ROWROT);
		break;

	default:
		break;
	}

	//�ʒu�ݒ�
	pSkill_circle->SetPos(D3DXVECTOR3(pos.x, pos.y + size.y, pos.z));
	//�T�C�Y�ݒ�
	pSkill_circle->SetSize(size);
	//�T�C�Y���
	pSkill_circle->m_size = size;
	//�J���[�ݒ� 
	pSkill_circle->SetColor(col);
	pSkill_circle->m_col = col;
	//�^�C�vd���
	pSkill_circle->m_type = type;


	return pSkill_circle;
}

//=============================================================================
//�����������֐�
//=============================================================================
HRESULT CSkill_circle::Init(void)
{	
	if (FAILED(Cbase_Cylinder::Init()))
	{
		return E_FAIL;
	}
	//�e�N�X�`���̃Q�b�g
	m_apTexture[EFFECTTYPE_SKIIL] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_SKIILMINI] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	//�e�N�X�`�����蓖��
	BindTexture(m_apTexture[m_type]);

	return S_OK;
}

//=============================================================================
//�I�������֐�
//=============================================================================
void CSkill_circle::Uninit(void)
{
	Cbase_Cylinder::Uninit();
}

//=============================================================================
//�X�V�����֐�
//=============================================================================
void CSkill_circle::Update(void)
{
	bool bUse = true;

	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 size = GetSize();

	switch (m_type)
	{
	case EFFECTTYPE_SKIIL:
		
		m_col.a -= 0.02f;
		m_fRotAngle += 0.5f;
		m_rot.y += 0.05f;
		m_size.x += 0.1f;
		m_size.z += 0.1f;
		SetPos(pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetAddRotValue(m_fRotAngle);
		if (m_fRotAngle >= 5.0f)
		{
			m_fRotAngle = 5.0f;
		}
		break;
	case EFFECTTYPE_SKIILMINI:
		
		m_col.a -= 0.02f;
		m_fRotAngle += 0.075f;
		m_rot.y -= 0.05f;
		m_size.x += 0.1f;
		m_size.z += 0.1f;
		SetPos(pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetAddRotValue(m_fRotAngle);
		if (m_fRotAngle >= 5.0f)
		{
			m_fRotAngle = 5.0f;
		}
		break;
	default:
		break;
	}

	if (m_nTile <= 0 || m_col.a <= 0)
	{
		bUse = false;
	}
	if (!bUse)
	{
		Uninit();
	}
}

//=============================================================================
//�`�揈���֐�
//=============================================================================
void CSkill_circle::Draw(void)
{
	Cbase_Cylinder::Draw();
}
















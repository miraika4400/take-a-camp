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
#include "skill_effect.h"
#include "base_Cylinder.h"
#include "resource_texture.h"
#include "manager.h"
#include "renderer.h"
#include "player.h"
#include "color_manager.h"
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
	m_nLife = 50;
	m_fRotAngle = 0.0f;
	m_fFadeout = 0.0f;
	m_bFadeoutFlag = true;
	m_col = { 1.0f,0.0f,0.0f,1.0f };
	m_mtxWorld = {};
	m_bAddMode = false;
	m_type = EFFECTTYPE_SKIIL;
	m_bEffectTrigger = false;
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
CSkill_circle * CSkill_circle::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col,const int nlife, const EFFECTTYPE type, CPlayer * pPlayer)
{
	//�C���X�^���X����
	CSkill_circle *pSkill_circle;
	pSkill_circle = new CSkill_circle;

	//�^�C�v���
	pSkill_circle->m_type = type;
	pSkill_circle->SetPlayer(pPlayer);
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

	case EFFECTTYPE_METEOR:

		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_ROWROT);
		break;

	case EFFECTTYPE_METEOR_CENTER:
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_CENTER_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_CENTER_ROWROT);


		break;
	case EFFECTTYPE_METEOR_IMPACT:
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_IMPACT_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_IMPACT_ROWROT);
		break;


	case EFFECTTYPE_IMPACT:
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_CENTER_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_CENTER_ROWROT);
		pSkill_circle->SetTextureUV(EXPLOSION_SKIIL_METEOR_IMPACT_UV1, EXPLOSION_SKIIL_METEOR_IMPACT_UV2);
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
	//�ʒu���
	pSkill_circle->m_pos = pos;
	//�J���[�ݒ� 
	pSkill_circle->SetColor(col);
	pSkill_circle->m_col = col;
	pSkill_circle->m_nLife = nlife;


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
	m_apTexture[EFFECTTYPE_METEOR] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR_CENTER] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR_IMPACT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_IMPACT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	

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
	
	CPlayer *pPlaryer = GetPlayer();
	bool bUse = true;

	m_pos = GetPos();
	m_size = GetSize();
	m_col = GetColor();

	switch (m_type)
	{
	case EFFECTTYPE_SKIIL:
		
	
		m_col.a -= 0.009f;
		m_fRotAngle += 0.5f;
		m_rot.y += 0.05f;
		m_size.x += 0.1f;
		m_size.z += 0.1f;
	
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetColor(m_col);

		SetAddRotValue(m_fRotAngle);
		if (m_fRotAngle >= 5.0f)
		{
			m_fRotAngle = 5.0f;
		}
		break;
	case EFFECTTYPE_SKIILMINI:
		

		m_col.a -= 0.009f;
		m_fRotAngle += 0.1f;
		m_rot.y -= 0.05f;
		m_size.x += 0.1f;
		m_size.z += 0.1f;
	
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetColor(m_col);
		SetAddRotValue(m_fRotAngle);
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
		if (m_fRotAngle >= 5.0f)
		{
			m_fRotAngle = 5.0f;
		}
		break;

	case EFFECTTYPE_METEOR:

		m_col.a -= 0.01f;
		m_rot.y-= 0.05f;
		m_size.x += 0.05f;
		m_size.z += 0.05f;

		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetColor(m_col);
		break;

	case EFFECTTYPE_METEOR_CENTER:

		m_col.a -= 0.009f;
		m_rot.y -= 0.05f;
		m_size.x += 0.0001f;
		m_size.y += 1.0f;
		m_size.z += 0.0001f;
		m_pos.y += 1.0f;
		
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetColor(m_col);
		break;

	case EFFECTTYPE_METEOR_IMPACT:

		m_col.a -= 0.01f;
		m_rot.y -= 0.05f;
		m_size.x += 0.15f;
		m_size.z += 0.15f;

		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetColor(m_col);
		break;

	case EFFECTTYPE_IMPACT:

		m_col.a -= 0.03f;
		m_size.y += 0.25f;
		m_pos.y -= 1.25f;

		if (m_pos.y <= 6.0f)
		{
			m_pos.y = 6.0f;
			m_size = GetSize();

			m_bEffectTrigger = true;
			
		}

		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetColor(m_col);
		break;

	default:
		break;
	}
	

	if (m_bEffectTrigger)
	{
		SetTextureUV(EXPLOSION_SKIIL_METEOR_IMPACT_UV2, EXPLOSION_SKIIL_METEOR_IMPACT_UV1);
		CSkill_circle::Create(m_pos, WIZARD_EFFECT_SIZE + EXPLOSION_SKIIL_IMPACT_SIZE - EXPLOSION_SKIIL_IMPACT_SIZESHIFT, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 1), m_nLife, CSkill_circle::EFFECTTYPE_METEOR_IMPACT, pPlaryer);
		CSkill_circle::Create(m_pos, WIZARD_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlaryer->GetColorNumber(), 2), m_nLife, CSkill_circle::EFFECTTYPE_METEOR, pPlaryer);
		
		bUse = false;
	}

	if (m_nLife <= 0 || m_col.a <= 0)
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
















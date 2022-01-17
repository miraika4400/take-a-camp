//=============================================================================
//
// �K�E�X�L���A���[�G�t�F�N�g ���� [skill_arrow_rain.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "skill_arrow_rain.h"
#include "skill_circle.h"
#include "skill_arrow.h"
#include "resource_texture.h"
#include "player.h" 
#include "skill_effect.h"

//*****************************
//�}�N����`
//*****************************
#define ARROW_CIRCLE (D3DXVECTOR3(1.0f,1.5f,1.0f))
#define ARROW_RAIN_SPEED (2.0f)	//�G�t�F�N�g�̃X�s�[�h
#define ARROW_LIFE (2)

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CSkillArrowRain::CSkillArrowRain(int nPliority)
{
	m_pSkillArrow = nullptr;
	m_bDeath = false;
}

//===================================
// �f�X�g���N�^
//===================================
CSkillArrowRain::~CSkillArrowRain()
{
}

//===================================
// ���������֐�
//===================================
CSkillArrowRain * CSkillArrowRain::Create(const D3DXVECTOR3 pos, const D3DXCOLOR col, CPlayer* pPlayer)
{
	//�������m��
	CSkillArrowRain* pSkillArrowRain = nullptr;
	pSkillArrowRain = new CSkillArrowRain;

	//NULL�`�F�b�N
	if (pSkillArrowRain != nullptr)
	{
		//�ʒu�ݒ�
		pSkillArrowRain->m_pos = pos;
		//�J���[�ݒ�
		pSkillArrowRain->m_col = col;
		pSkillArrowRain->m_pPlayer = pPlayer;
		//����������
		pSkillArrowRain->Init();

	}
	return pSkillArrowRain;
}

//===================================
// ����������
//===================================
HRESULT CSkillArrowRain::Init(void)
{
	//��̃G�t�F�N�g����
	m_pSkillArrow = CSkillArrow::Create(m_pos, D3DXVECTOR3(0.0f,-ARROW_RAIN_SPEED,0.0f),0.0f, ARROW_LIFE,m_col);

	return S_OK;
}

//===================================
// �I������
//===================================
void CSkillArrowRain::Uninit(void)
{
	Release();
}

//===================================
// �X�V����
//===================================
void CSkillArrowRain::Update(void)
{
	//�ʒu�X�V����
	PosChange();

	//���S�t���O�������Ă��邩
	if (m_bDeath)
	{
		//�I������
		Uninit();
	}
}

//===================================
// �`�揈��
//===================================
void CSkillArrowRain::Draw(void)
{
}

//===================================
// �ʒu�̕ω�����
//===================================
void CSkillArrowRain::PosChange(void)
{
	D3DXVECTOR3 pos = m_pSkillArrow->GetPos();


	//���̈ʒu�ɗ����
	if (pos.y <= 0.0f)
	{
		//�Ռ��g���o��
		CSkill_circle::Create(D3DXVECTOR3(pos.x, ARROW_CIRCLE.y, pos.z), ARROW_CIRCLE, m_col, ARCHER_EFFECT_LIFE, CSkill_circle::EFFECTTYPE_SKIIL,m_pPlayer);
		//���S�t���O�𗧂Ă�
		m_pSkillArrow->SetDeath();
		//���S�t���O�𗧂Ă�
		m_bDeath = true;
	}
}

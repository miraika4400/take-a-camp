//===================================================
//
// all_skill_gauge����[all_skill_gauge.cpp]
// Author:�ɓ��z��
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "all_skill_gauge.h"
#include "skill_gauge.h"
#include "color_manager.h"

//==================================
// �}�N����`
//==================================
#define SKILLGAUGE_SIZE (D3DXVECTOR3(20.0f, 20.0f, 0.0f))		// �X�L���Q�[�W�̑傫��
#define DEFAULT_COLOR	(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))		// �F�̏����l

//==================================
// �R���X�g���N�^
//==================================
CAllskillgauge::CAllskillgauge()
{
	// ������
	m_pSkillgauge_Icon = nullptr;
	m_pSkillgauge_Stencil = nullptr;
}

//==================================
// �f�X�g���N�^
//==================================
CAllskillgauge::~CAllskillgauge()
{
	// ������
	m_pSkillgauge_Icon = nullptr;
	m_pSkillgauge_Stencil = nullptr;
}

//==================================
// �X�L���Q�[�W���ׂẴN���G�C�g
// nPlayerNum�F�v���C���[�̔ԍ�
//==================================
CAllskillgauge* CAllskillgauge::Create(const int nPlayerNum)
{
	// �������̊m��
	CAllskillgauge * pAllskillgauge = new CAllskillgauge;

	// �A�C�R���ƃX�e���V��
	pAllskillgauge->m_pSkillgauge_Icon = CSkillgauge::Create(SKILLGAUGE_SIZE, DEFAULT_COLOR, nPlayerNum, CSkillgauge::SKILLGAUGE_ICON);
	pAllskillgauge->m_pSkillgauge_Stencil = CSkillgauge::Create(SKILLGAUGE_SIZE, GET_COLORMANAGER->GetIconColor(nPlayerNum), nPlayerNum, CSkillgauge::SKILLGAUGE_STENCIL);

	return pAllskillgauge;
}
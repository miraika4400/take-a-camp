//=============================================================================
//
// all_skill_gauge�w�b�_ [all_skill_gauge.h]
// Author : �ɓ��z��
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _ALL_SKILL_GAUGE_H_
#define _ALL_SKILL_GAUGE_H_

//=============================================================================
// �O���錾
//=============================================================================
class CSkillgauge;

//=============================================================================
// �N���X��`
//=============================================================================

// �X�L���Q�[�W�N���X
class CAllskillgauge
{
public:
	//============
	// �����o�֐�
	//============
	CAllskillgauge();
	~CAllskillgauge();
	static CAllskillgauge* Create(const int nPlayerNum);

	//============
	// �Q�b�^�[
	//============
	CSkillgauge * GetSkillgaugeIcon() { return m_pSkillgauge_Icon; }
	CSkillgauge * GetSkillgaugeStencil() { return m_pSkillgauge_Stencil; }
private:
	//============
	// �����o�ϐ�
	//============
	CSkillgauge * m_pSkillgauge_Icon;		// �X�L���Q�[�W�̃A�C�R��
	CSkillgauge * m_pSkillgauge_Stencil;	// �X�L���Q�[�W�̃X�e���V��
};

#endif
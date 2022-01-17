//=============================================================================
//
// �K�E�X�L���A���[�G�t�F�N�g ���� [skill_arrow_rain.h]
// Author : �g�c�I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SKILL_ARROW_RAIN_
#define _SKILL_ARROW_RAIN_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "scene.h"
#include "billboard.h"
//*****************************
// �O���錾
//*****************************
class CSkillArrow;
class CPlayer;
//*****************************
//�}�N����`
//*****************************


//=============================================================================
// �N���X��`
//=============================================================================
class CSkillArrowRain : public CScene
{
public:
	//============
	//�����o�֐�
	//============
	CSkillArrowRain(int nPliority = OBJTYPE_PARTICLE);
	~CSkillArrowRain();
	static CSkillArrowRain *Create(const D3DXVECTOR3 pos, const D3DXCOLOR col ,CPlayer* pPlayer); // �N���X����
	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��

private:
	void PosChange(void);	//�ʒu�̕ω�����

	//============
	// �����o�ϐ�
	//============
	CSkillArrow*	m_pSkillArrow;
	CPlayer *		m_pPlayer;
	D3DXVECTOR3		m_pos;			// �ʒu
	D3DXCOLOR		m_col;			// �F
	bool			m_bDeath;		// ���S�t���O

};

#endif

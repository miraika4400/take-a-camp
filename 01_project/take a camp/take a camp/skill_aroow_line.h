//=============================================================================
//
// �X�L���A���[���C���G�t�F�N�g ���� [skill_arrow_line.h]
// Author : �g�c�I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SKILL_ARROW_LINE_
#define _SKILL_ARROW_LINE_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "billboard.h"
//*****************************
//�}�N����`
//*****************************


//=============================================================================
// �N���X��`
//=============================================================================
class CSkillArrowLine : public CBillboard
{
public:
	//============
	//�����o�֐�
	//============
	CSkillArrowLine(int nPliority = OBJTYPE_PARTICLE);
	~CSkillArrowLine();
	static CSkillArrowLine* Create(const D3DXVECTOR3 pos, const float fAngle, const D3DXCOLOR col); // �N���X����
	HRESULT Init(void);		// ������
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��

private:
	//============
	// �����o�ϐ�
	//============
	int		m_nTile;		// ���C�t
	bool	m_bDeath;		// ���S�t���O
};

#endif

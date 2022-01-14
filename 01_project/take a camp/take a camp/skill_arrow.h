//=============================================================================
//
// �X�L���A���[�G�t�F�N�g ���� [skill_arrow.h]
// Author : �g�c�I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SKILL_ARROW_
#define _SKILL_ARROW_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "billboard.h"
//*****************************
// �O���錾
//*****************************

//*****************************
//�}�N����`
//*****************************


//=============================================================================
// �N���X��`
//=============================================================================
class CSkillArrow : public CBillboard
{
public:
	//============
	//�����o�֐�
	//============
	CSkillArrow(int nPliority = OBJTYPE_PARTICLE);
	~CSkillArrow();
	static CSkillArrow *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const float fAngle, int nTile,const D3DXCOLOR col); // �N���X����
	HRESULT Init(void);		// ������
	void	Update(void);	// �X�V


	void	SetDeath(void) { m_bDeath = true; }
	void	SetLife(int nLife) { m_nTile = nLife; }		// ���C�t�Z�b�^�[
	void	AddLife(int nLife) { m_nTile += nLife; }	// ���C�t���Z
	int 	GetLife(void) { return m_nTile; }			// ���C�t�Q�b�^�[

private:
	void	PosChange(void);// �ʒu�X�V

	//============
	// �����o�ϐ�
	//============
	D3DXVECTOR3 m_StartPos;	// �X�^�[�g�ʒu
	D3DXVECTOR3	m_move;		// �ړ���
	bool		m_bDeath;	// ���S�t���O
	int			m_nTile;	// ���C�t
};

#endif

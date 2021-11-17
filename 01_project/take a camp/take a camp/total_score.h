//=============================================================================
//
// �g�[�^���X�R�A�\������ [total_score.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TOTAL_SCORE_H_
#define _TOTAL_SCORE_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"
#include "game.h"
//*****************************
// �O���錾
//*****************************
class CScene2d;

//*****************************
//�N���X��`
//*****************************
//�X�R�A�N���X
class CTotalScore : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CTotalScore();
	~CTotalScore();

	static CTotalScore *Create(void); // �N���X����

	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��

private:
	//============
	// �����o�ϐ�
	//============
	CScene2d* m_pBg;	// �w�i�p�|�C���^
	CScene2d* m_pKillUi;// �L��UI�p�|�C���^
	CScene2d* m_pTileUI;// �^�C��UI�p�|�C���^
};

#endif
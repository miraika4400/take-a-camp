//=============================================================================
//
// �h��X�R�A�\������ [score_paint.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SCORE_PAINT_H_
#define _SCORE_PAINT_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"
#include "game.h"

//*****************************
//�O���錾
//*****************************
class CNumber;

//*****************************
//�}�N����`
//*****************************
#define MAX_PAINT_SCORE_DIGIT (3)  // �X�R�A�̍ő包��

//*****************************
//�N���X��`
//*****************************

//�X�R�A�N���X
class CScorePaint : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CScorePaint();
	~CScorePaint();

	static CScorePaint *Create(void); // �N���X����

	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��
	void	SetPaintScore(int nPlayer, int nScore);	// �X�R�A

private:
	//============
	// �����o�ϐ�
	//============
	CNumber* m_apNumber[MAX_PLAYER][MAX_PAINT_SCORE_DIGIT];	// �i���o�[�|���S��
	int			m_nPaintScore[MAX_PLAYER];					// �X�R�A
	D3DXVECTOR3 m_pos[MAX_PLAYER];							// �ʒu
	D3DXCOLOR	m_col[MAX_PLAYER];							// �J���[
	int			m_nPlayerNum;								// �v���C���[�l���擾�p�ϐ�
};

#endif
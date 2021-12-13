//=============================================================================
//
// �h��X�R�A�\������ [score.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SCORE_H_
#define _SCORE_H_

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
#define MAX_SCORE_DIGIT (3)  // �X�R�A�̍ő包��

//*****************************
//�N���X��`
//*****************************

//�X�R�A�N���X
class CScore : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CScore();
	~CScore();

	static CScore *Create(D3DXVECTOR3 pos, D3DXCOLOR col, int nScore); // �N���X����

	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��
	void	SetPaintScore(int nScore);	// �X�R�A

private:
	//============
	// �����o�ϐ�
	//============
	CNumber* m_apNumber[MAX_SCORE_DIGIT];	// �i���o�[�|���S��
	int			m_nPaintScore;					// �X�R�A
	D3DXVECTOR3 m_pos;							// �ʒu
	D3DXCOLOR	m_col;							// �J���[
	int			m_nPlayerNum;					// �v���C���[�l���擾�p�ϐ�
};

#endif
//=============================================================================
//
// �L���X�R�A�\������ [score_kill.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SCORE_KILL_H_
#define _SCORE_KILL_H_

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
#define MAX_KILL_SCORE_DIGIT (3)  // �X�R�A�̍ő包��

//*****************************
//�N���X��`
//*****************************

//�X�R�A�N���X
class CScoreKill : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CScoreKill();
	~CScoreKill();

	static CScoreKill *Create(void); // �N���X����

	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��
	void	SetKillScore(int nPlayer, int nScore);	// �X�R�A

private:
	//============
	// �����o�ϐ�
	//============
	CNumber* m_apNumber[MAX_PLAYER][MAX_KILL_SCORE_DIGIT];	// �i���o�[�|���S��
	D3DXVECTOR3 m_pos[MAX_PLAYER];							// �ʒu
	D3DXCOLOR	m_col[MAX_PLAYER];							// �J���[
	int			m_nPlayerNum;								// �v���C���[�l���擾�p�ϐ�
};

#endif
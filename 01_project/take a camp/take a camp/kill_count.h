////////////////////////////////////////////////////
//
//    �L���J�E���g�w�b�_�[[kill_count.h]
//    Author : �g�c �I�l
//
////////////////////////////////////////////////////

//��d�C���N���[�h�h�~
#ifndef _KILL_COUNT_H_
#define _KILL_COUNT_H_

//=============================
// �C���N���[�h
//=============================
#include "main.h"
#include "scene.h"
#include "game.h"

//=============================
//�}�N����`
//=============================
#define MAX_KILL_NUMBER (3)

//=============================
// �O���錾
//=============================
class CNumber;

//=============================
// �N���X��`
//=============================

// �}�l�[�W���[�N���X
class CKillCount : public CScene
{
public:
	//============
	// ��ԗ�
	//============

	//============
	// �����o�֐�
	//============
	CKillCount();
	~CKillCount();
	static CKillCount *Create(int nPlayer); //�N���X����
	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��
	void	AddKill(void);	// �L�������Z
	void	SetKill(int nKill)		{ m_nKillCount = nKill; }	// �L�����Z�b�^�[
	int 	GetKill(void)			{ return m_nKillCount; }	// �L�����Q�b�^�[
	void	SetPlayer(int nPlayer)	{ m_nPlayer = nPlayer; }	// �v���C���[�ԍ��Z�b�^�[
	int		GetPlayer(void)			{ return m_nPlayer; }		// �v���C���[�ԍ��Q�b�^�[

	static void	AddTotalKill(void);		// �L�������Z
	static int GetTotalKill(int nPlayer) { return m_nTotalKill[nPlayer]; }	//�g�[�^���L�����̃Q�b�^�[
private:
	//============
	// �����o�ϐ�
	//============
	static int	m_nTotalKill[MAX_PLAYER];			// �v���C���[�S�̂̃L����
	int m_nKillCount;								// �L����
	int m_nPlayer;									// �v���C���[�ԍ�
};


#endif
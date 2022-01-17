//====================================================
//
// tutorial�w�b�_ [tutorial.h]
// Author : �ɓ��@�z��
//
//====================================================

//��d�C���N���[�h�h�~
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
// �O���錾
//*****************************
class CMap;
class CPolygon;
class CText;

//*****************************
//�N���X��`
//*****************************

//�`���[�g���A���N���X
class CTutorial : public CScene
{
public:
	enum TUTORIALPHASE
	{
		PHASE_PAINT = 0,
		PHASE_OVERPAINT,
		PHASE_ATTACK,
		PHASE_FINALATTACK,
		PHASE_FINISH,
	};

	//============
	// �����o�֐�
	//===========
	CTutorial();
	~CTutorial();
	static CTutorial *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	TUTORIALPHASE GetTutorialPhase(void) { return m_Tutorialphase; }	// �`���[�g���A���̏�Ԃ̎擾
private:
	//============
	// �����o�֐�
	//===========
	void CheckTaskClear(const int nCurTaskNum, const int nTargetNum, const int nPlayernum);
	void UpdateText(void);
	void NextPhase(void);
	void StartPlayer(bool bUpdate);
	void Max_Playergauge(void);
	void DummyCreate(void);
	void SetTextWindow(void);
	void SetTexInvisible(TUTORIALPHASE TutorialPhaze);

	//============
	// �����o�ϐ�
	//===========
	CMap *m_pMap;										// �}�b�v�̃|�C���^
	CPolygon *m_pTextWindow;							// �e�L�X�g�E�B���h�E�̃|���S���̃|�C���^
	CPolygon *m_pTaskTex[(int)PHASE_FINISH];			// �e�X�N�̃e�N�X�`���̃|���S���̃|�C���^
	CPolygon *m_pCheckTex[(int)PHASE_FINISH];			// �`�F�b�N�̃e�N�X�`���̃|���S���̃|�C���^
	CText *m_pText;										// �e�L�X�g�̃|�C���^
	TUTORIALPHASE m_Tutorialphase;						// �`���[�g���A���̏��
	bool m_bTask;										// �v���C���[���^�X�N������������
	int m_nTextNum;										// �e�L�X�g�̐�
	bool m_bNextText;									// ���̃e�L�X�g�ɍs���������Ȃ���
	bool m_bTextEnd;									// �e�L�X�g��\�����I�������
	int m_nCurTaskNum[MAX_PLAYER];						// ���݂̃^�X�N���Ƃ̐�
	int m_nOldCurTaskNum[MAX_PLAYER];					// 1�t���[���O�̃^�X�N���Ƃ̐�
	int m_nTextShowTime;								// �e�L�X�g��\�����鎞��
};

#endif
//=============================================================================
//
// tutorial�w�b�_ [tutorial.h]
// Author : ���V ����
//
//=============================================================================

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
// �}�N����`
//*****************************
#define TUTORIAL_NUM (1) // �`���[�g���A���y�[�W��

//*****************************
//�N���X��`
//*****************************

//�`���[�g���A���N���X
class CTutorial : public CScene
{
public:
	enum TUTORIALPHASE
	{
		PHASE_START = 0,
		PHASE_MOVE,
		PHASE_PAINT,
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
	//============
	// �����o�ϐ�
	//===========
	static LPDIRECT3DTEXTURE9 m_pTexture[TUTORIAL_NUM]; // �e�N�X�`���ւ̃|�C���^
	CMap *m_pMap;										// �}�b�v�̃|�C���^
	CPolygon *m_pPolygon;								// �|���S���̃|�C���^
	CText *m_pText;										// �e�L�X�g�̃|�C���^
	TUTORIALPHASE m_Tutorialphase;						// �`���[�g���A���̏��
	bool m_bTask[MAX_PLAYER];
	bool m_bEntry[MAX_PLAYER];
	int m_nTextNum;
	bool m_bNextText;
	bool m_bTextEnd;
};

#endif
//=============================================================================
//
// time�w�b�_ [time.h]
// Author : ���� �x�ߑ�
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TIME_H_
#define _TIME_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
//�O���錾
//*****************************
class CNumber;

//*****************************
//�}�N����`
//*****************************
#define MAX_TIME_DIGIT 3  // �^�C���̍ő包��
#define TIME_UP 5       // ���Ԑ���

//*****************************
//�N���X��`
//*****************************

//�X�R�A�N���X
class CTime : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CTime();
	~CTime();

	static CTime *Create(void); // �N���X����

	HRESULT Init(void);// ������
	void Uninit(void); // �I��
	void Update(void); // �X�V
	void Draw(void);   // �`��

	void SetTime(bool bTime)	{ m_bTime = bTime; }
	bool GetTime(void)			{ return m_bTime; }

private:
	//============
	// �����o�֐�
	//============
	void FinishPlayer(void);

	//============
	// �����o�ϐ�
	//============
	CNumber* m_apNumber[MAX_TIME_DIGIT]; // �i���o�[�|���S��
	int m_nTime;										//�^�C���ϐ�
	int m_nA;
	bool m_bTime;
};

#endif
//=============================================================================
//
// confetti�w�b�_ [confetti.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _CONFETTI_H_
#define _CONFETTI_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene2d.h"

//*****************************
//�N���X��`
//*****************************

// ������N���X
class CConfetti : public CScene2d
{
public:
	//============
	// �����o�֐�
	//============
	CConfetti();
	~CConfetti();

	static CConfetti *Create(void); // �N���X����

	virtual HRESULT Init(void); // ������
	virtual void Update(void);  // �X�V

private:
	//============
	// �����o�ϐ�
	//============
	D3DXVECTOR3 m_move, m_moveDist;
};

#endif
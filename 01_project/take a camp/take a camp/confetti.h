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

	static CConfetti *Create(D3DXVECTOR3 pos , D3DXCOLOR col,float fMoveAngle = 0.0f); // �N���X����

	HRESULT Init(void); // ������
	void Update(void);  // �X�V

private:
	//============
	// �����o�ϐ�
	//============
	int m_nTile;
	float m_fMoveAngle;
	float m_fMoveRate;
	D3DXVECTOR3 m_move;
};

#endif
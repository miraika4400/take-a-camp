//=============================================================================
//
// confetti_factory�w�b�_ [confetti_factory.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _CONFETTI_FACTORY_H_
#define _CONFETTI_FACTORY_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene.h"

//*****************************
//�N���X��`
//*****************************

// ������t�@�N�g���[�N���X
class CConfettiFactory : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CConfettiFactory();
	~CConfettiFactory();
	
	static CConfettiFactory *Create(D3DXCOLOR col ,int nLife = -1); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I������
	void Update(void);  // �X�V
	void Draw(void);    // �`��
private:
	//============
	// �����o�ϐ�
	//============
	int m_nLife;
	int m_nCntConfetti;
	D3DXCOLOR m_col;
};

#endif
//====================================================
//
// titleback_ui�w�b�_ [titleback_ui.h]
// Author : �ɓ��z��
//
//====================================================

//��d�C���N���[�h�h�~
#ifndef _TITLEBACK_UI_H_
#define _TITLEBACK_UI_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
// �O���錾
//*****************************
class CPolygon;

//*****************************
//�N���X��`
//*****************************

//�`���[�g���A���N���X
class CTitlebackui : public CScene
{
public:
	//============
	// �����o�֐�
	//===========
	CTitlebackui();
	~CTitlebackui();
	static CTitlebackui *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	//============
	// �����o�֐�
	//===========

	//============
	// �����o�ϐ�
	//===========
	CPolygon *m_pTitlebackTex;	// �^�C�g���߂�p�̃|���S���̃|�C���^
	float m_fAlpha;
	bool m_bAlphaChange;
};
#endif
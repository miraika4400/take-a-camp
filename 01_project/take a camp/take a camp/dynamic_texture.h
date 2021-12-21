//=============================================================================
//
// dynamic_tecture�w�b�_ [dynamic_tecture.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _DYNAMIC_TEXTURE_H_
#define _DYNAMIC_TEXTURE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"

//*****************************
// �N���X��`
//*****************************

//���I�e�N�X�`���N���X
class CDynamicTexture
{
public:
	//============
	// �����o�֐�
	//============
	CDynamicTexture();
	~CDynamicTexture();

	// static
	static CDynamicTexture *Create(D3DXVECTOR2 size);  // �N���X����

	virtual HRESULT Init(D3DXVECTOR2 size);   // ������
	virtual void Uninit(void);	  // �I��
	void Begin(void);     // �J�n
	void End(void);       // �I��

	LPDIRECT3DTEXTURE9 GetTexture(void) { return m_pTexture; } // �e�N�X�`���̎擾����

private:
	//============
	// �����o�ϐ�
	//============

	LPDIRECT3DTEXTURE9		m_pTexture;		//�e�N�X�`��
	LPDIRECT3DSURFACE9		m_pTexz;		//�e�N�X�`���̐[�x�o�b�t�@
	LPDIRECT3DSURFACE9		m_pTexSurface;	//�e�N�X�`���փA�N�Z�X����ׂ̃C���^�[�t�F�[�X
	LPDIRECT3DSURFACE9		m_pBackz;		//�o�b�N�o�b�t�@�̐[�x�o�b�t�@
	LPDIRECT3DSURFACE9		m_pBackSurface;	//�o�b�N�o�b�t�@�փA�N�Z�X����ׂ�
	D3DXMATRIX	m_proj;		// �ˉe�s��
	D3DXMATRIX	m_view;		// �s��
	D3DVIEWPORT9 m_saveViewport; // �ۑ��p�r���[�|�[�g
	D3DXVECTOR2 m_size;     // �T�C�Y

};

#endif
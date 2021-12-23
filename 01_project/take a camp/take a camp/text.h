//=============================================================================
//
// �e�L�X�g�w�b�_ [text.h]
// Author : �ɓ��z��
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TEXT_H_
#define _TEXT_H_

//=============================
// �C���N���[�h
//=============================
#include "main.h"
#include "scene.h"

//=============================
// �O���錾
//=============================
class CPolygon;


//=============================
// �N���X��`
//=============================

// �e�L�X�g�N���X
class CText : public CScene
{
public:
	enum FORMAT
	{
		ALIGN_LEFT = 0,
		ALIGN_CENTER,
		ALIGN_RIGHT
	};

	//============
	// �����o�֐�
	//===========
	CText();
	~CText();
	static CText *Create(const D3DXVECTOR2 pos, const D3DXVECTOR2 fontsize, const FORMAT format, const D3DCOLOR col); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	void AddText(std::string str_text);	// �e�L�X�g�̒ǉ�
	void ClearText(void);				// �\������Ă���e�L�X�g�̍폜

	//============
	// �Z�b�^�[
	//============
	void SetWindowRange(D3DXVECTOR2 WindowRange[2]);	// �����̕\���͈͂̐ݒ�
	void SetFontSize(D3DXVECTOR2 FontSize);				// �����̃T�C�Y�̐ݒ�
	void SetColor(D3DXCOLOR color);						// �F�̐ݒ�
	void SetPos(D3DXVECTOR2 pos);						// ���W�̐ݒ�

	//============
	// �Q�b�^�[
	//============
	bool GetAllShowText(void) { return m_bAllShow; }	// �e�L�X�g���S���\�����ꂽ���̎擾
	D3DXVECTOR2 *GetWindowRange(void) { return m_WindowRange; }
	D3DXVECTOR2 GetFontSize(void) { return m_Fontsize; }
	D3DXCOLOR GeColor(void) { return m_col; }
	D3DXVECTOR2 GetPos(void) { return m_pos; }

private:
	//============
	// �����o�ϐ�
	//===========
	LPD3DXFONT m_pFont;				// �t�H���g�ۑ��p�ϐ�
	D3DXVECTOR2 m_pos;				// ���W
	D3DXVECTOR2 m_Fontsize;			// �����̃T�C�Y
	D3DCOLOR m_col;					// �F
	DWORD m_format;					// ������@�ϊ��p�ϐ�
	D3DXVECTOR2 m_WindowRange[2];	// �����̕\���͈�
	std::string m_str;				// �\�����镶����
	int m_nCountBite;				// 1�o�C�g���̃J�E���g
	int m_nShowTime;				// �����������鎞��
	bool m_bAllShow;				// ���ׂĕ\�����ꂽ���ǂ���
};

#endif
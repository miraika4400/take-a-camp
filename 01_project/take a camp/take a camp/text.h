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
	static CText *Create(const D3DXVECTOR3 pos, const float fHeight, const float fWidth, const FORMAT format, const D3DCOLOR col); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	void AddText(std::string str_text);
	void ClearText(void);

	bool GetAllShowText(void) { return m_bAllShow; }
private:
	//============
	// �����o�֐�
	//===========


	//============
	// �����o�ϐ�
	//===========
	LPD3DXFONT m_pFont;		// �t�H���g�ۑ��p�ϐ�
	D3DXVECTOR3 m_pos;		// ���W
	float m_fHeight;		// �����̃T�C�Y
	float m_fWidth;			// ������̕��̏��
	D3DCOLOR m_col;			// �F
	DWORD m_format;			// ������@�ϊ��p�ϐ�
	char m_fontName[128];	// �t�H���g�̖��O
	std::string m_str;		// �\�����镶����
	int m_nCountBite;		// 1�o�C�g���̃J�E���g
	int m_nShowTime;		// �����������鎞��
	bool m_bAllShow;		// ���ׂĕ\�����ꂽ���ǂ���
};

#endif
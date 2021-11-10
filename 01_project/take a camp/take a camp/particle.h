//=============================================================================
//
// particle�w�b�_ [particle.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "billboard.h"

//*****************************
//�}�N����`
//*****************************
#define EFFECT_DEFAULT_FADE_OUT_RATE 0.006f                               // �t�F�[�h�A�E�g����



//*****************************
// �N���X��`
//*****************************

// �p�[�e�B�N���N���X
class CParticle : public CBillboard
{
public:
	//============
	// ��ԗ�
	//============
	// �p�[�e�B�N���^�C�v
	typedef enum
	{
		PARTICLE_SQUARE = 0, // �l�p
		PARTICLE_TEARS,   // ��
		PARTICLE_CIRCLE,  // ��
		PARTICLE_GURUGURU, // ���邮��
		PARTICLE_MAX,     // �^�C�v�̍ő吔
	}PARTICLE_TYPE;

	//============
	//�����o�֐�
	//============
	CParticle();
	~CParticle();

	// static
	static CParticle *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const D3DXVECTOR3 size, const int nLife,
		const D3DXCOLOR col,const float fadeout, const PARTICLE_TYPE type = PARTICLE_SQUARE); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	// �ړ��ʂ̎擾�E�Z�b�g
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }

	void SetAddRotValue(float fAdd) { m_fRotAngle = fAdd; }
private:
	//============
	// �����o�ϐ�
	//============
	LPDIRECT3DTEXTURE9 m_apTexture[PARTICLE_MAX]; // �e�N�X�`��
	D3DXVECTOR3   m_move;	 	  // �ړ���
	D3DXVECTOR3   m_size;		  // �傫��
	int           m_nLife;	  	  // ����
	float		  m_fRotAngle;	  // ��]�p�x
	float		  m_fFadeout;	  // �t�F�[�h�A�E�g�@
	bool		  m_bFadeoutFlag; // �t�F�[�h�A�E�g��7�t���O
	D3DXCOLOR	  m_col;		  // �F
	PARTICLE_TYPE m_type;		  // �p�[�e�B�N���̎��
};

#endif
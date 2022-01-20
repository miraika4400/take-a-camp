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
#define TEXTURE_ANIMA_PATTERN (20)

#define TEXTURE_ANIMA_LATE (1)
#define TEXTURE_ANIMA_THUKI_LATE (2)
#define TEXTURE_ANIMA_CREATE_POINT (8)
#define EFFECT_NUM_MAX (10)
#define EFFECT_MAX (8)


//*****************************
// �O���錾
//*****************************
class CPlayer;


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
		PARTICLE_SHOOT,  // ��݂̋N��
		PARTICLE_METEOR, // ����
		PARTICLE_METEOR_SHADOW, // �����̉e
		PARTICLE_GURUGURU,
		PARTICLE_SLASH,
		PARTICLE_THUKI,
		PARTICLE_MAX,     // �^�C�v�̍ő吔
	}PARTICLE_TYPE;

	//============
	//�����o�֐�
	//============
	CParticle();
	~CParticle();

	// static
	static CParticle *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const D3DXVECTOR3 size, const int nLife,
		const D3DXCOLOR col,const float fadeout, const float fAngle, CPlayer * pPlayer, const PARTICLE_TYPE type = PARTICLE_SQUARE); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	// �ړ��ʂ̎擾�E�Z�b�g
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	void SetAddRotValue(float fAdd) { m_fRotAngle = fAdd; }
	//�v���C���[�̃|�C���^�����E�Z�b�g
	void		SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
	CPlayer*	GetPlayer(void) { return m_pPlayer; }
private:
	//============
	// �����o�ϐ�
	//============
	LPDIRECT3DTEXTURE9 m_apTexture[PARTICLE_MAX]; // �e�N�X�`��
	D3DXVECTOR3   m_move;	 	  // �ړ���
	D3DXVECTOR3   m_size;		  // �傫��
	D3DXVECTOR3	  m_rot;		  // �ʒu
	D3DXVECTOR3	  m_posOld;		  // �����ʒu


	CPlayer*	  m_pPlayer;	  // �v���C���[�̃|�C���^
	int           m_nLife;        //����
	int			  m_nPattern;	  //�A�j���[�V�����̃p�^�[��
	int			  m_nEffectId;	  //�G�t�F�N�g��iD
	static int    m_nEffectIdAII; //�G�t�F�N�g�̑���
	int			  m_nAnimation;   //�A�j���[�V�����̎��ԃJ�E���g
	float		  m_fRotAngle;	  // ��]�p�x
	
	float		  m_fFadeout;	  // �t�F�[�h�A�E�g�@
	bool		  m_bFadeoutFlag; // �t�F�[�h�A�E�g�̃t���O
	bool          m_bAnimation;	  // �A�j���[�V�������Ă�����
	D3DXCOLOR	  m_col;		  // �F
	PARTICLE_TYPE m_type;		  // �p�[�e�B�N���̎��
};

#endif
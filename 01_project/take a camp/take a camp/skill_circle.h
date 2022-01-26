//=============================================================================
//

// �X�L���T�[�N�� [skill_circle.h]
// Author : �V����s
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SKILL_CIRCLE_
#define _SKILL_CIRCLE_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "scene.h"
#include "base_Cylinder.h"

//*****************************
//�}�N����`
//*****************************
#define NORMAL_SKIIL_HIGHROT (1.0f)
#define NORMAL_SKIIL_ROWROT (1.7f)

#define NORMAL_SKIIL_SIZE (D3DXVECTOR3(8.5f,6.5f,8.5f))
#define NORMAL_SKIIL_POS (D3DXVECTOR3(0.0f,0.0f,0.0f))
#define NORMAL_SKIIL_COL (D3DXCOLOR(0.0f,0.0f,0.0f))
#define NORMAL_SKIIL_SIZESHIFT D3DXVECTOR3(1.5f, 0.0f, 1.5f)

#define EXPLOSION_SKIIL_POSSHIFT D3DXVECTOR3(0.0f, 6.0f, 0.0f)
#define EXPLOSION_SKIIL_SHADOW_POSSHIFT D3DXVECTOR3(0.0f, 0.0f, 0.0f)
#define EXPLOSION_SKIIL_SIZESHIFT D3DXVECTOR3(2.5f, 2.5f, 2.5f)
#define EXPLOSION_SKIIL_MOVE D3DXVECTOR3(0.0f, 0.0f, 0.0f)
#define EXPLOSION_SKIIL_POS	 D3DXVECTOR3(0.0f,0.0f,0.0f)
#define EXPLOSION_SKIIL_SIZE D3DXVECTOR3(7.5f,4.5f,7.5f)
#define EXPLOSION_SKIIL_CENTER_SIZE D3DXVECTOR3(4.0f,0.0f,4.0f)
#define EXPLOSION_SKIIL_CENTER_SIZESHIFT D3DXVECTOR3(0.0f,3.0f,0.0f)
#define EXPLOSION_SKIIL_IMPACT_SIZE	D3DXVECTOR3(5.0f,0.0f,5.0f)
#define EXPLOSION_SKIIL_IMPACT_SIZESHIFT D3DXVECTOR3(0.0f,4.5f,0.0f)
#define EXPLOSION_SKIIL_METEOR_IMPACT_SIZE	D3DXVECTOR3(4.0f,0.0f,4.0f)
#define EXPLOSION_SKIIL_METEOR_IMPACT_SIZESHIFT D3DXVECTOR3(0.0f,3.0f,0.0f)
#define EXPLOSION_SKIIL_METEOR_IMPACT_POS D3DXVECTOR3(0.0f,25.0f,0.0f)
#define EXPLOSION_SKIIL_METEOR_IMPACT_UV1 (1.0f)
#define EXPLOSION_SKIIL_METEOR_IMPACT_UV2 (0.0f)

#define SLASH_SKIIL_POSSHIFT D3DXVECTOR3(0.0f, 6.0f, 0.0f)
#define SLASH_SKIIL_MOVE D3DXVECTOR3(0.0f, 0.0f, 0.0f)

#define THUKI_SKIIL_POSSHIFT D3DXVECTOR3(0.0f, 6.0f, 0.0f)
#define THUKI_SKIIL_MOVE D3DXVECTOR3(0.0f, 0.0f, 0.0f)

#define EXPLOSION_SKIIL_HIGHROT (3.5f)
#define EXPLOSION_SKIIL_ROWROT (0.5f)
#define EXPLOSION_SKIIL_CENTER_HIGHROT (1.0f)
#define EXPLOSION_SKIIL_CENTER_ROWROT (1.0f)
#define EXPLOSION_SKIIL_IMPACT_HIGHROT (2.0f)
#define EXPLOSION_SKIIL_IMPACT_ROWROT (0.5f)


//*****************************
// �O���錾
//*****************************
class CPlayer;

//=============================================================================
// �N���X��`
//=============================================================================
class CSkill_circle : public Cbase_Cylinder
{
public:
	//============
	//�����o�֐�
	//============
	CSkill_circle(int nPliority = OBJTYPE_PARTICLE);
	~CSkill_circle();



	//============
	// ��ԗ�
	//============
	// �G�t�F�N�g�^�C�v��
	
	typedef enum
	{
		EFFECTTYPE_SKIIL = 0,
		EFFECTTYPE_SKIILMINI,
		EFFECTTYPE_METEOR,
		EFFECTTYPE_METEOR_CENTER,
		EFFECTTYPE_METEOR_IMPACT,
		EFFECTTYPE_IMPACT,
		EFFECTTYPE_MAX
	}EFFECTTYPE;

	// static

	static CSkill_circle *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col , const int nlife ,const EFFECTTYPE type, CPlayer * pPlayer); // �N���X����

	virtual HRESULT Init(void); // ������
	virtual void Uninit(void);  // �I��
	virtual void Update(void);  // �X�V
	virtual	void Draw(void);    // �`��
	
	LPDIRECT3DTEXTURE9 GetTexture(int nIndex) { return m_apTexture[nIndex]; }//�e�N�X�`������
			
	void		SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }	//�v���C���[�̃|�C���^�ݒ�
	CPlayer*	GetPlayer(void) { return m_pPlayer; }					//�v���C���[�̃|�C���^����
private:
	//============
	// �����o�ϐ�
	//============
	CPlayer *		m_pPlayer;												// �v���C���[�N���X
	LPDIRECT3DTEXTURE9		m_apTexture[EFFECTTYPE_MAX];	    // �e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3			    m_pos;	 	    // �ʒu
	D3DXVECTOR3			    m_move;	 	    // �ړ���
	D3DXVECTOR3			    m_rot;	 	    // ����
	D3DXVECTOR3	            m_size;		    // �傫��
	int                     m_nLife;	    // ����
	float		            m_fRotAngle;    // ��]�p�x
	float		            m_fFadeout;	    // �t�F�[�h�A�E�g�@
	bool		            m_bFadeoutFlag; // �t�F�[�h�A�E�g�̃t���O
	bool					m_bAddMode;     // ���Z����
	bool					m_bEffectTrigger;	// �G�t�F�N�g�����g���K�[
	D3DXCOLOR	            m_col;		    // �F
	D3DXMATRIX				m_mtxWorld;     // ���[���h�}�g���b�N�X
	EFFECTTYPE				m_type;			// �G�t�F�N�g�̃^�C�v

};

#endif

//=============================================================================
//
// �X�L���G�t�F�N�g��` [skill_circle.h]
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
#define NORMAL_SKIIL_SIZE D3DXVECTOR3(8.5f,6.5f,8.5f)
#define NORMAL_SKIIL_POS D3DXVECTOR3(0.0f,0.0f,0.0f)
#define NORMAL_SKIIL_COL D3DXCOLOR(0.0f,0.0f,0.0f)


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
		EFFECTTYPE_MAX
	}EFFECTTYPE;

	// static
	static CSkill_circle *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col , const EFFECTTYPE type); // �N���X����

	virtual HRESULT Init(void); // ������
	virtual void Uninit(void);  // �I��
	virtual void Update(void);  // �X�V
	virtual	void Draw(void);    // �`��
	LPDIRECT3DTEXTURE9 GetTexture(int nIndex) { return m_apTexture[nIndex]; }


private:
	//============
	// �����o�ϐ�
	//============
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
	D3DXCOLOR	            m_col;		    // �F
	D3DXMATRIX				m_mtxWorld;     // ���[���h�}�g���b�N�X
	EFFECTTYPE				m_type;			// �G�t�F�N�g�̃^�C�v
};

#endif

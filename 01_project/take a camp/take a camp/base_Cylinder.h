//=============================================================================
//
// �ׁ[���̉~����` [base_Cylinder.h]
// Author : �V����s
//
//=============================================================================


//��d�C���N���[�h�h�~
#ifndef _BASE_CYLINDERH_
#define _BASE_CYLINDERH_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================

#include "main.h"
#include "scene.h"

//*****************************
//�}�N����`
//*****************************
#define NUM_CYL_VERTEX (20)


//=============================================================================
// �N���X��`
//=============================================================================
class Cbase_Cylinder : public CScene
{
public:
	//============
	//�����o�֐�
	//============
	Cbase_Cylinder(int nPliority = OBJTYPE_PARTICLE);
	~Cbase_Cylinder();

	// static
	static Cbase_Cylinder *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size ,const D3DXCOLOR col); // �N���X����

	virtual HRESULT Init(void); // ������
	virtual void Uninit(void);  // �I��
	virtual void Update(void);  // �X�V
	virtual void Draw(void);    // �`��

	 LPDIRECT3DTEXTURE9 GetTexture(void) { return m_apTexture; }
	 void BindTexture(const LPDIRECT3DTEXTURE9 pTexture) { m_apTexture = pTexture; }

	// ���S���W�̃Z�b�g�A�擾
	void SetPos(const D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	// �����̃Z�b�g�A�擾
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	D3DXVECTOR3 GetRot(void) { return m_rot; }
	// �ړ��ʂ̎擾�E�Z�b�g
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	// ��]�p�x�̃Z�b�g�A�擾
	void SetAddRotValue(const float fAdd) { m_fRotAngle = fAdd;}
	float GetAddRotValue(void) { return m_fRotAngle; }
	// �T�C�Y�̃Z�b�g�A�擾
	void SetSize(const D3DXVECTOR3 size);
	D3DXVECTOR3 GetSize(void) { return m_size; }
	// �J���[�̃Z�b�g�A�擾
	void SetColor(const D3DXCOLOR col);
	D3DXCOLOR GetColor(void) { return m_col; }

	void SetHighRot(const float rot) { m_fHighRot = rot; }
	void SetRowRot(const float rot) { m_fRowRot = rot; }

	void SetAddMode(bool bBool) { m_bAddMode = bBool; }
	void SetTextureUV(const float High, const float low); // �e�N�X�`����UV���W�̃Z�b�g
private:
	//============
	// �����o�ϐ�
	//============
	LPDIRECT3DTEXTURE9		m_apTexture;	    // �e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	    // ���_�o�b�t�@�ւ̃|�C���^
	D3DXVECTOR3			    m_pos;	 	    // �ʒu
	D3DXVECTOR3			    m_move;	 	    // �ړ���
	D3DXVECTOR3			    m_rot;	 	    // ����
	D3DXVECTOR3	            m_size;		    // �傫��
	
	int                     m_nLife;	    // ����
	float					m_fHighRot;		// ��ӊp�x
	float					m_fRowRot;		// ���ӊp�x
	float		            m_fRotAngle;    // ��]�p�x
	float		            m_fFadeout;	    // �t�F�[�h�A�E�g�@
	bool		            m_bFadeoutFlag; // �t�F�[�h�A�E�g�̃t���O
	D3DXCOLOR	            m_col;		    // �F
	D3DXMATRIX				m_mtxWorld;     // ���[���h�}�g���b�N�X
	bool					m_bAddMode;     // ���Z������
};										    

#endif

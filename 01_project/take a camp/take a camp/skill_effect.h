//=============================================================================
//
// �X�L���G�t�F�N�g��` [skill_effect.h]
// Author : �V����s
//
//=============================================================================


//��d�C���N���[�h�h�~
#ifndef _SKILL_EFFECT_
#define _SKILL_EFFECT_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================

#include "main.h"
#include "scene.h"
#include "base_Cylinder.h"
//*****************************
//�}�N����`
//*****************************
#define KNIGHT_SKIIL_HIGHROT (1.0f)
#define KNIGHT_SKIIL_ROWROT (1.7f)
#define KNIGHT_SKIIL_SIZE D3DXVECTOR3(10.5f,9.5f,10.5f)
#define KNIGHT_SKIIL_POS D3DXVECTOR3(0.0f,0.0f,0.0f)
#define KNIGHT_SKIIL_COL D3DXCOLOR(0.0f,0.0f,0.0f)

//=============================================================================
// �N���X��`
//=============================================================================
class CSkill_effect 
{
public:
	//============
	//�����o�֐�
	//============
	CSkill_effect();
	~CSkill_effect();



	//============
	// ��ԗ�
	//============
	// �X�L���^�C�v��

	typedef enum
	{
		SKILLTYPE_KNIGHT = 0,
		SKILLTYPE_ARCHER,
		SKILLTYPE_WIZARD,
		SKILLTYPE_LANCER,
		SKILLTYPE_MAGICIAN,
		SKILLTYPE_THIER,
		SKILLTYPE_MAX
	}SKILLTYPE;

	// static
	static void Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col1 ,const D3DXCOLOR col2 ,const D3DXCOLOR col3, const SKILLTYPE type); // �N���X����

	HRESULT Init(void); // ������

private:
	//============
	// �����o�ϐ�
	//============
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
	SKILLTYPE				m_type;			// �G�t�F�N�g�̃^�C�v
};

#endif

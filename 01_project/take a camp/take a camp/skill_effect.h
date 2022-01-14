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
#include "skill_circle.h"
//*****************************
//�}�N����`
//*****************************

#define THIEF_EFFECT_POS D3DXVECTOR3(0.0f, 6.0f, 0.0f)
#define THIEF_EFFECT_SIZE D3DXVECTOR3(15.0f, 15.0f, 0.0f)

#define WIZARD_EFFECT_POS D3DXVECTOR3(0.0f, 6.0f, 0.0f)
#define WIZARD_EFFECT_SIZE D3DXVECTOR3(7.5f, 4.5f, 7.5f)

#define KNIGHT_EFFECT_POS D3DXVECTOR3(0.0f, 6.0f, 0.0f)
#define KNIGHT_EFFECT_SIZE D3DXVECTOR3(4.5f,4.5f,4.5f)

#define KNIGHT_EFFECT_LIFE (50)
#define ARCHER_EFFECT_LIFE (50)
#define WIZARD_EFFECT_LIFE (500)
#define LANCER_EFFECT_LIFE (50)
#define MAGICIAN_EFFECT_LIFE (50)
#define THIER_EFFECT_LIFE (50)

//*****************************
// �O���錾
//*****************************
class CPlayer;

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
		SKILLTYPE_WIZARD_FINALATTACK,
		SKILLTYPE_LANCER,
		SKILLTYPE_MAGICIAN,
		SKILLTYPE_THIER,
		SKILLTYPE_MAX
	}SKILLTYPE;

	// static
	static void Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col1 ,const D3DXCOLOR col2 ,const D3DXCOLOR col3,const int nlife, const SKILLTYPE type, CPlayer * pPlayer); // �N���X����


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

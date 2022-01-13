//=============================================================================
//
// �X�L���g�����v�G�t�F�N�g ���� [skill_trump.h]
// Author : �g�c�I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SKILL_TRUMP_
#define _SKILL_TRUMP_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "scene.h"
#include "billboard.h"
//*****************************
// �O���錾
//*****************************
class CBillboard;
//*****************************
//�}�N����`
//*****************************


//=============================================================================
// �N���X��`
//=============================================================================
class CSkillTrump : public CBillboard
{
public:
	//============
	//�񋓌^
	//============
	typedef enum
	{
		NONE_ANGLE = 0,
		RIGHT_ANGLE,
		LEFT_ANGLE,
		MAX_ANGLE,
	}ANGLE_PATTERN;
	//============
	//�����o�֐�
	//============
	CSkillTrump(int nPliority = OBJTYPE_PARTICLE);
	~CSkillTrump();

	static CSkillTrump *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size,const D3DXVECTOR3 MoveAngle, const D3DXCOLOR col); // �N���X����

	HRESULT Init(void); // ������
	void Update(void);  // �X�V

private:
	void AngleChange(void);	//�����̕ω�����
	void PosChange(void);	//�ʒu�̕ω�����

	
	//============
	// �����o�ϐ�
	//============
	ANGLE_PATTERN	AnglePattern;	// ���p�x
	D3DXVECTOR3		m_move;			// �ړ���
	bool			m_bDeath;		// ���S�t���O
	D3DXVECTOR3		m_MoveAngle;	// �ړ�����p�x
	int	 			m_ColCount;		// �J���[�ω��J�E���g
};

#endif

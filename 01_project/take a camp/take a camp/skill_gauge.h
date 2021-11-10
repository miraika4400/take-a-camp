//=============================================================================
//
// �X�L���Q�[�W�̃w�b�_ [skill_gauge.h]
// Author : �ɓ��z��
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SKILL_GAUGE_H_
#define _SKILL_GAUGE_H_

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "main.h"
#include "billboard.h"

//=============================================================================
// �O���錾
//=============================================================================
class CPolygon;

//=============================================================================
// �N���X��`
//=============================================================================

// �X�L���Q�[�W�N���X
class CSkillgauge : public CBillboard
{
public:

	typedef enum
	{
		SKILLGAUGE_BG = 0,	// �Q�[�W�̔w�i
		SKILLGAUGE_STENCIL,	// �X�e���V��
		SKILLGAUGE_MAX,		// �^�C�v�̍ő吔
	}SKILLGAUGE_TYPE;

	//============
	// �����o�֐�
	//============
	CSkillgauge();
	~CSkillgauge();
	static CSkillgauge *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);	// �I��
	void Update(void);	// �X�V
	void Draw(void);	// �`��

private:
	//============
	// �����o�ϐ�
	//============
	SKILLGAUGE_TYPE m_SkillGaugeType;	// �X�L���Q�[�W�̃^�C�v
	D3DXVECTOR3 m_pos;		// ���W
	D3DXVECTOR3 m_size;		// �傫��
	D3DXCOLOR m_col;		// �F
	int m_nPlayerNum;		// �v���C���[�̔ԍ�
	float m_fGauge;

};

#endif
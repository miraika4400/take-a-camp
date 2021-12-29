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
class CPlayer;

//=============================================================================
// �N���X��`
//=============================================================================

// �X�L���Q�[�W�N���X
class CSkillgauge : public CBillboard
{
public:

	typedef enum
	{
		//SKILLGAUGE_BG = 0,	// �Q�[�W�̔w�i
		SKILLGAUGE_STENCIL = 0,	// �X�e���V��
		SKILLGAUGE_ICON,	// �X�L���Q�[�W�̃A�C�R��
		SKILLGAUGE_MAX,		// �^�C�v�̍ő吔
	}SKILLGAUGE_TYPE;

	//============
	// �����o�֐�
	//============
	CSkillgauge();
	~CSkillgauge();
	static CSkillgauge* AllCreate(const int nPlayerNum);

	HRESULT Init(void); // ������
	void Uninit(void);	// �I��
	void Update(void);	// �X�V
	void Draw(void);	// �`��

	void Repaint_AddSkillGauge(void);	// �K�E�Z�Q�[�W�����Z�����鏈��
	void SkillGauge_Max(void);			// �K�E�Z�Q�[�W�𖞃^���ɂ��鏈��
private:
	//============
	// �����o�֐�
	//============
	static CSkillgauge *Create(const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType); // �N���X����
	CPlayer *GetPlayerinfo(int nPlayerNum);
	void UpdateStencil(void); // �X�e���V���̍X�V����
	void SetPolygonPos(void); // �X�e���V����\��������W

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
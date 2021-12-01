//=============================================================================
//
// Player_Model�w�b�_ [Player_Model.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _PLAYER_MODEL_H_
#define _PLAYER_MODEL_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "model_hierarchy.h"
#include "resource_character.h"

//*****************************
// �O���錾
//*****************************
class CMotion;

//*****************************
// �}�N����`
//****************************
#define RIM_POWER				(2.5f)			// �������C�g�̋���

//*****************************
// �N���X��`
//*****************************

// �v���C���[�N���X
class CPlayerModel : public CModelHierarchy
{
public:

	//�����o�֐�
	CPlayerModel();
	~CPlayerModel();
	static CPlayerModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CResourceCharacter::CHARACTER_TYPE charaType);

	HRESULT Init(void);
	void Update(void);

	D3DXCOLOR GetRimColor(void) { return m_RimColor; }
	void SetRimColor(D3DXCOLOR col) { m_RimColor = col; }
	CResourceCharacter::CHARACTER_TYPE GetCharaType(void) { return m_charaType; }
	void SetCharaType(CResourceCharacter::CHARACTER_TYPE type) { m_charaType = type; }

private:
	void ManageMotion(void);// ���[�V�����Ǘ�
	void DrawModel(void);	                                                          // ���f���̕`�揈��
	void SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData); // �V�F�[�_�ɒl�𑗂�

	// ���[�V�����p�ϐ�
	CResourceCharacter::CHARACTER_TYPE m_charaType;
	CMotion *m_apMotion[CResourceCharacter::MOTION_MAX];  // �A�j���[�V�����|�C���^
	D3DXCOLOR m_RimColor;
};

#endif
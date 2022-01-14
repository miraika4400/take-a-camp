//=============================================================================
//
// �U���͈� �^�C�v���@�g�� [attack_wizard.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _ATTACK_WIZARD_H_
#define _ATTACK_WIZARD_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackWizard : public CAttackBased
{
public:
	//�֐���`
	CAttackWizard();
	~CAttackWizard();
	static CAttackWizard *Create(CPlayer* pPlayer);

	void PlaySE(void);

private:
	void CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state);
	//void	AttackCreate(void);	//�U����������

	//int		m_nAttackCount;		//�U���܂ł̃J�E���g
	//int		m_nType;			//�U���̊Ԋu�p�̃^�C�v
};
#endif
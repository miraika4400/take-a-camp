//=============================================================================
//
// �U���͈� �^�C�v���� [attack_lancer.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _ATTACK_LANCER_H_
#define _ATTACK_LANCER_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackLancer : public CAttackBased
{
public:
	//�֐���`
	CAttackLancer();
	~CAttackLancer();
	static CAttackLancer *Create(CPlayer* pPlayer);

private:
	void CreateEffect(D3DXVECTOR3 pos);
	//void	AttackCreate(void);	//�U����������

	//int		m_nAttackCount;		//�U���܂ł̃J�E���g
	//int		m_nType;			//�U���̊Ԋu�p�̃^�C�v
};
#endif
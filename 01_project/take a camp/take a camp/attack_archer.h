//=============================================================================
//
// �U���͈� �^�C�v�|�g��[attack_archer.h]
// Author : ���V ����
//
//=============================================================================
#ifndef _ATTACK_ARCHER_H_
#define _ATTACK_ARCHER_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack.h"
#include "scene.h"
//*****************************
// �O���錾
//*****************************
class CSkillArrow;

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackArcher : public CAttackBased
{
public:
	//�֐���`
	CAttackArcher();
	~CAttackArcher();

	static CAttackArcher *Create(CPlayer* pPlayer);

private:
	void CreateEffect(D3DXVECTOR3 pos); // �G�t�F�N�g����
	void OnceEffect(D3DXVECTOR3 pos);// ��񂾂��̃G�t�F�N�g

	CSkillArrow*	m_pSkillArrow;


};
#endif
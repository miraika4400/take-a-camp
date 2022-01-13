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

	void PlaySE(void);

private:
	void CreateEffect(D3DXVECTOR3 pos); // �G�t�F�N�g����

};
#endif
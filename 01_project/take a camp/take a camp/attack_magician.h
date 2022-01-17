//=============================================================================
//
// �U���͈� �^�C�v��p�t[attack_magician.h]
// Author : ���V ����
//
//=============================================================================
#ifndef _ATTACK_MAGICIAN_H_
#define _ATTACK_MAGICIAN_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackMagician : public CAttackBased
{
public:
	//�֐���`
	CAttackMagician();
	~CAttackMagician();

	static CAttackMagician *Create(CPlayer* pPlayer);

	void PlaySE(void);

private:
	void CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state); // �G�t�F�N�g����

};
#endif
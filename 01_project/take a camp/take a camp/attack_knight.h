//=============================================================================
//
// �U���͈� �^�C�v�R�m [attack_knight.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _ATTACK_KNIGHT_H_
#define _ATTACK_KNIGHT_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackKnight : public CAttackBased
{
public:
	//�֐���`
	CAttackKnight();
	~CAttackKnight();

	static CAttackKnight *Create(CPlayer* pPlayer);

	void PlaySE(void);

private:
	void CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state); // �G�t�F�N�g����
	//void	AttackCreate(void);	//�U����������

	//int		m_nAttackCount;		//�U���܂ł̃J�E���g
	//int		m_nType;			//�U���̊Ԋu�p�̃^�C�v
};
#endif
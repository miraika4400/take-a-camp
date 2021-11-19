//=============================================================================
//
// �i�C�g�̕K�E�Z�͈̓^�C�v�̏��� [attack_final_knight.h]
// Author : �����D�I
//
//=============================================================================
#ifndef _ATTACK_FINAL_KNIGHT_H_
#define _ATTACK_FINAL_KNIGHT_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_final.h"
#include "scene.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackFinalknight : public CAttackFinal
{
public:
	CAttackFinalknight();
	~CAttackFinalknight();
	static CAttackFinalknight *Create(CPlayer* pPlayer);
	HRESULT Init(void);

private:
	void AttackFinalCreate(void);	// �K�E��������
	int m_nAttackFinalCount;		// �K�E�܂ł̃J�E���g
	int m_nType;					// �K�E�̊Ԋu�p�̃^�C�v
};
#endif // !_ATTACK_FINAL_KNIGHT_H_

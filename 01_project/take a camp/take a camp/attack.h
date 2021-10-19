//=============================================================================
//
// �U���͈� [attack.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _ATTACK_H_
#define _ATTACK_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "scene.h"
#include "attack_manager.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackBased : public CScene
{
public:
	//�֐���`
	CAttackBased();
	~CAttackBased();
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
	void	SetAttackType(CAttackManager::ATTACK_TYPE AttackType);
	CAttackManager::ATTACK_TYPE GetAttackType(void);
	void	SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void);
private:
	CAttackManager::ATTACK_TYPE m_nAttackType;
	CAttackManager::ATTACK_DATA m_AttackData;
	D3DXVECTOR3 m_pos;
};
#endif
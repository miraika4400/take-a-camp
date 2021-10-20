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
#include "resource_attack.h"
//*****************************
// �O���錾
//*****************************
class CPlayer;
//*****************************
// �}�N����`
//*****************************
#define MAX_ATTACK (4)	//�U���̍ő��

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
	
	void	SetAttackType(CAttackManager::ATTACK_TYPE AttackType);			//�U���^�C�v�Z�b�^�[
	CAttackManager::ATTACK_TYPE GetAttackType(void);						//�U���^�C�v�Q�b�^�[
	void	SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare);	//�U���}�X�f�[�^�Z�b�^�[
	CAttackManager::ATTACK_SQUARE_DATA GetAttackSquare(void);					//�U���}�X�f�[�^�Q�b�^�[
	void		SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void);
	void		SetRot(D3DXVECTOR3 rot);
	D3DXVECTOR3 GetRot(void);
	void		SetAttackFlag(bool bAttack);	
	void		AttackSwitch(void);
	bool		GetAttackFlag(void);
	void		Attack(CAttackManager::ATTACK_RANGE_TYPE AttackType);
	void		SetPlayer(CPlayer* pPlayer);
	CPlayer*	GetPlayer(void);
	virtual void AttackCreate(void) = 0;//�U���������� 
private:
	CPlayer* m_pPlayer;	//�v���C���[�N���X
	CAttackManager::ATTACK_TYPE			m_nAttackType;		// �U���^�C�v
	CAttackManager::ATTACK_SQUARE_DATA	m_AttackSquare;	// �U���}�X�f�[�^
	D3DXVECTOR3 m_pos;								// �ʒu
	D3DXVECTOR3 m_rot;								// ����
	bool		m_bAttack;							// �U���t���O
};
#endif
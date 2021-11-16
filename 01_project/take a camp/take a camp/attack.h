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
class CAttackArea;
//*****************************
// �}�N����`
//*****************************
#define MAX_ATTACK (4)	//�U���̍ő��
#define MAX_ATTACK_AREA_NUM 128
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
	
	void	SetAttackType(CResourceCharacter::CHARACTER_TYPE AttackType);			//�U���^�C�v�Z�b�^�[
	CResourceCharacter::CHARACTER_TYPE GetAttackType(void);						//�U���^�C�v�Q�b�^�[
	void	SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare);	//�U���}�X�f�[�^�Z�b�^�[
	CAttackManager::ATTACK_SQUARE_DATA GetAttackSquare(void);							//�U���}�X�f�[�^�Q�b�^�[
	void		SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void);
	void		SetRot(D3DXVECTOR3 rot);
	D3DXVECTOR3 GetRot(void);
	void		SetAttackFlag(bool bAttack);	
	void		AttackSwitch(int nLevel);
	bool		GetAttackFlag(void);
	void		Attack(int AttackType);
	void		SetPlayer(CPlayer* pPlayer);
	CPlayer*	GetPlayer(void);
	virtual void AttackCreate(void) = 0;//�U���������� 
	void		VisualizationAttackArea(int nAttackType = 0); // �U���͈͂̉���
	void        ResetAttackArea(void);
private:
	CPlayer* m_pPlayer;	//�v���C���[�N���X
	CAttackArea * m_apAttackArea[MAX_ATTACK_AREA_NUM];
	CResourceCharacter::CHARACTER_TYPE			m_nAttackType;	// �U���^�C�v
	CAttackManager::ATTACK_SQUARE_DATA	m_AttackSquare[MAX_ATTACK_LEVEL];	// �U���}�X�f�[�^
	D3DXVECTOR3 m_pos;									// �ʒu
	D3DXVECTOR3 m_rot;									// ����
	bool		m_bAttack;								// �U���t���O
	int			m_nLevel;			//�U���̃��x��

};

#endif
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
class CColorTile;

//*****************************
// �}�N����`
//*****************************
#define MAX_ATTACK (4)	//�U���̍ő��
#define MAX_ATTACK_AREA_NUM (128)
//=============================================================================
// �N���X��`
//=============================================================================
class CAttackBased : public CScene
{
public:

	// �X�e�[�g
	typedef enum
	{
		ATTACK_STATE_NORMAL = 0,	// �ʏ���
		ATTACK_STATE_CHARGE,		// �`���[�W���
		ATTACK_STATE_ATTACK			// �U�����
	}ATTACK_STATE;


	//�֐���`
	CAttackBased();
	~CAttackBased();
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
	void	Attack(int AttackType);		// �U������
	void	ChargeFlag(int nMaxLevel);	// �`���[�W�J�n����
	void	AttackSwitch(void);			// �U���X�C�b�`�֐�
	void	SetAttackType(CAttackManager::ATTACK_TYPE AttackType) { m_nAttackType = AttackType; }	//�U���^�C�v�Z�b�^�[
	CAttackManager::ATTACK_TYPE GetAttackType(void) { return m_nAttackType; }						//�U���^�C�v�Q�b�^�[
	void	SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare);	//�U���}�X�f�[�^�Z�b�^�[
	CAttackManager::ATTACK_SQUARE_DATA GetAttackSquare(void);					//�U���}�X�f�[�^�Q�b�^�[

	void		SetLevel(int nLevel) { m_nLevel = nLevel; }				// ���x���Z�b�^�[
	void		SetPos(D3DXVECTOR3 pos) { m_pos = pos; }				// �ʒu�Z�b�^�[
	D3DXVECTOR3 GetPos(void) { return m_pos; }							// �ʒu�Q�b�^�[	
	void		SetRot(D3DXVECTOR3 rot) { m_rot = rot; }				// �����Z�b�^�[
	D3DXVECTOR3 GetRot(void) { return m_rot; }							// �����Q�b�^�[
	void		SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }	// �v���C���[�Z�b�^�[
	CPlayer*	GetPlayer(void) { return m_pPlayer; }					// �v���C���[�Q�b�^�[
	void		SetState(ATTACK_STATE State) { m_AttackState = State; }	// �X�e�[�g�Z�b�^�[
	ATTACK_STATE GetState(void) { return m_AttackState; }				// �X�e�[�g�Q�b�^�[
	
	virtual void AttackCreate(void) = 0;		// �U���������� 

	void		VisualizationAttackArea(int nAttackType = 0);	// �U���͈͂̉���
	void        ResetAttackArea(void);							// �U���͈̓|���S���̃��Z�b�g
private:
	void		Charge(void);					 // �U���̃`���[�W����

	CPlayer *		m_pPlayer;							// �v���C���[�N���X
	CAttackArea *	m_apAttackArea[MAX_ATTACK_AREA_NUM];// �U���͈̓|�C���^
	CAttackManager::ATTACK_TYPE			m_nAttackType;	// �U���^�C�v
	CAttackManager::ATTACK_SQUARE_DATA	m_AttackSquare[MAX_ATTACK_LEVEL];	// �U���}�X�f�[�^
	D3DXVECTOR3		m_pos;								// �ʒu
	D3DXVECTOR3		m_rot;								// ����
	ATTACK_STATE	m_AttackState;						// �U���X�e�[�g
	int				m_nLevel;							// �U���̃��x��
	int				m_nMaxLevel;						// �ő僌�x���ۑ��p
	int				m_nChargeCount;						// �`���[�W�p�̃J�E���g

};

#endif
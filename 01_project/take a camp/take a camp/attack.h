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
class CPeintCollision;

//*****************************
// �}�N����`
//*****************************
#define MAX_ATTACK (4)	//�U���̍ő��
#define MAX_ATTACK_AREA_NUM (128)
#define MAX_FINAL_PEINT	(128)

//=============================================================================
// �N���X��`
//=============================================================================
class CAttackBased : public CScene
{
public:

	// �X�e�[�g
	typedef enum
	{
		ATTACK_STATE_NORMAL = 0,			// �ʏ���
		ATTACK_STATE_CHARGE,				// �`���[�W���
		ATTACK_STATE_ATTACK,				// �U�����
		ATTACK_STATE_FINALATTACKWAITING,	// �K�E�Z�ҋ@
		ATTACK_STATE_FINALATTACK,			// �K�E�Z�g�p���
	}ATTACK_STATE;

	//�֐���`
	CAttackBased();
	~CAttackBased();
	static CAttackBased * Create(CPlayer* pPlayer, CResourceCharacter::CHARACTER_TYPE Type);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
	void	Attack(int AttackType);		// �U������
	void	ChargeFlag(void);			// �`���[�W�J�n����
	void	AttackSwitch(void);			// �U���X�C�b�`�֐�
	void	AttackFinalFlag(void);		// �K�E�ҋ@�t���O����
	void    AttackFinalSwitch(void);	// �K�E�X�C�b�`�֐�
	void	CancelSwitch(void);			// �U���L�����Z���X�C�b�`�֐�
	virtual void AttackCreate(void);						// �U���������� 
	void	VisualizationAttackArea(int nAttackType = 0);	// �U���͈͂̉���
	void	ResetAttackArea(void);							// �U���͈̓|���S���̃��Z�b�g
	void	ReleaseAttakcArea(void);                        // �U���͈͂̃����[�X

	//============================
	//�Z�b�^�[�E�Q�b�^�[
	//============================
	//�U���}�X�f�[�^
	CAttackManager::ATTACK_SQUARE_DATA GetAttackSquare(void);			
	// ���x��
	void		SetLevel(int nLevel) { m_nLevel = nLevel; }		
	int			GetLevel(void) { return m_nLevel; }
	// �v���C���[
	void		SetPlayer(CPlayer* pPlayer) { m_pPlayer = pPlayer; }	
	CPlayer*	GetPlayer(void) { return m_pPlayer; }					
	// �X�e�[�g
	void		SetState(ATTACK_STATE State) { m_AttackState = State; }	
	ATTACK_STATE GetState(void) { return m_AttackState; }				
	// �K�E�Z�t���O
	void		SetAttackFlag(bool bAttack) { m_bAttack = bAttack; }	
	bool		GetAttackFlag(void) { return m_bAttack; }				
	// �U���^�C�v
	void		SetType(CResourceCharacter::CHARACTER_TYPE type) { m_nAttackType = type; }
private:
	void		Charge(void);					// �U���̃`���[�W����
	virtual void CreateEffect(D3DXVECTOR3 pos);	// �G�t�F�N�g����
	virtual void OnceEffect(D3DXVECTOR3 pos);	//	��񂾂��̃G�t�F�N�g


	CPlayer *		m_pPlayer;												// �v���C���[�N���X
	CAttackArea *	m_apAttackArea[MAX_ATTACK_AREA_NUM];					// �U���͈̓|�C���^
	CResourceCharacter::CHARACTER_TYPE	m_nAttackType;						// �U���^�C�v
	CAttackManager::ATTACK_SQUARE_DATA	m_AttackSquare[MAX_ATTACK_LEVEL];	// �U���}�X�f�[�^
	CPeintCollision* m_pPeintCollision[MAX_FINAL_PEINT];					// �F
	ATTACK_STATE	m_AttackState;						// �U���X�e�[�g
	bool			m_bAttack;							// �K�E�t���O
	bool			m_bChargeTile;						// �`���[�W�^�C���t���O
	bool			m_bCancel;							// �L�����Z���t���O
	int				m_nLevel;							// �U���̃��x��
	int				m_nMaxLevel;						// �ő僌�x���ۑ��p
	int				m_nChargeCount;						// �`���[�W�p�̃J�E���g
	int				m_anChargeValue[MAX_ATTACK_LEVEL];  // �`���[�W�ڕW�l
	int				m_nCancelCount;						// �L�����Z���J�E���g
	int				m_nAttackCount;		//�U���܂ł̃J�E���g
	int				m_nType;			//�U���̊Ԋu�p�̃^�C�v

};

#endif
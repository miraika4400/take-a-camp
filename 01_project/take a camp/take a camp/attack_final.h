//=============================================================================
//
// �K�E�Z�̏��� [attack_final.h]
// Author : �����D�I
//
//=============================================================================

#ifndef _ATTACK_FINAL_H_
#define _ATTACK_FINAL_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "scene.h"
#include "resource_final_attack.h"

//=============================================================================
// �O���錾
//=============================================================================
class CPlayer;
class CAttackArea;
class CColorTile;
class CPeintCollision;

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_ATTACK_FINAL_AREA_NUM (128)
#define MAX_FINAL_PEINT	(128)
//=============================================================================
// �N���X��`
//=============================================================================
class CAttackFinal : public CScene
{
public:
	// ��
	typedef enum
	{
		FINAL_ATTACK_STATE_NONE = -1,
		FINAL_ATTACK_STATE_NOMAL,		// �ʏ���
		FINAL_ATTACK_STATE_ATTACK,		// �U�����
		FINAL_ATTACK_STATE_MAX
	}FINAL_ATTACK_STATE;

	CAttackFinal();		// �R���X�g���N�^
	~CAttackFinal();	// �f�X�g���N�^

	HRESULT Init(void);	// ����������
	void Uninit(void);	// �I������
	void Update(void);	// �X�V����
	void Draw(void);	// �`�揈��
	
	void AttackFinalSwitch(void);			// �K�E�X�C�b�`����
	void AttackFinal(int AttackFinalType);	// �K�E�֐�

	void SetAttackFinalType(CResourceCharacter::CHARACTER_TYPE AttackFinal) { m_FinalAttackType = AttackFinal; }						// �K�E�Z�^�C�v�ݒ�
	CResourceCharacter::CHARACTER_TYPE GetAttackFinalType(void) {return m_FinalAttackType;}												// �K�E�Z�^�C�v�̎擾

	void SetFinalAttackSquare(CFinalAttackManager::FINAL_ATTACK_SQUARE_DATA FinalAttackSquare) { m_FinalAttackSquare = FinalAttackSquare; }	// �K�E�Z�}�X�f�[�^�̐ݒ�
	CFinalAttackManager::FINAL_ATTACK_SQUARE_DATA GetFinalAttackSquare(void) { return m_FinalAttackSquare; }								// �K�E�Z�}�X�f�[�^�̎擾

	void		SetPos(D3DXVECTOR3 pos) { m_pos = pos; }		// �ʒu�ݒ�
	D3DXVECTOR3 GetPos(void)			{ return m_pos; }		// �ʒu�擾
	void		SetRot(D3DXVECTOR3 rot) { m_rot = rot; }		// �����ݒ�
	D3DXVECTOR3 GetRot(void)			{ return m_rot; }		// �����擾
	void		SetAttackFinalFlag(bool bAttackFinal)	{ m_bAttackFinal = bAttackFinal; }	// �K�E�Z�t���O�ݒ�
	bool		GetAttackFinalFlag(void)				{ return m_bAttackFinal; }			// �K�E�Z�t���O�擾
	void		SetPlayer(CPlayer* pPlayer)				{ m_pPlayer = pPlayer; }			// �v���C�����擾
	CPlayer*	GetPlayer(void)							{ return m_pPlayer; }				// �v���C���[���ݒ�
	void		SetState(FINAL_ATTACK_STATE State)		{ m_FinalAttackState = State; }		// ��Ԑݒ�
	FINAL_ATTACK_STATE GetState(void)					{ return m_FinalAttackState; }		// ��Ԏ擾
	virtual void AttackFinalCreate(void) = 0;						// �K�E�Z��������
	void		VisualizationAttackArea(int AttackFinalType = 0);	// �U���͈̔͂̃u���b�N�̘g�̐F��ς��鏈��
	void        ResetAttackArea(void);								// �U���͈̓|���S���̃��Z�b�g
private:
	CPlayer* m_pPlayer;		// �v���C���[�N���X
	CAttackArea *	m_apAttackArea[MAX_ATTACK_FINAL_AREA_NUM];			// �U���͈̓|�C���^
	D3DXVECTOR3 m_pos;						// �ʒu
	D3DXVECTOR3 m_rot;						// ����
	FINAL_ATTACK_STATE m_FinalAttackState;	// ���
	bool m_bAttackFinal;					// �U���t���O
	CResourceCharacter::CHARACTER_TYPE			m_FinalAttackType;		// �U���^�C�v
	CFinalAttackManager::FINAL_ATTACK_SQUARE_DATA m_FinalAttackSquare;	// �K�E�Z�}�X�f�[�^
	CPeintCollision* m_pPeintCollision[MAX_FINAL_PEINT];				// �F
};
#endif // !_ATTACK_FINAL_H_

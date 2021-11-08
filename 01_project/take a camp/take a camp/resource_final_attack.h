//=============================================================================
//
// �K�E�Z�͈͓ǂݍ��݃N���X�w�b�_�[ [resource_final_attack.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _RESOURCE_FINAL_ATTACK_H_
#define _RESOURCE_FINAL_ATTACK_H_
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_FINAL_ATTACK_SIZE_X	(20)	//�ő�u���b�N��
#define MAX_FINAL_ATTACK_SIZE_Y	(20)	//�ő�X�e�[�W�T�C�Y
#define MAX_FINAL_HIT_TYPE			(4)		//�q�b�g�}�X�^�C�v�̍ő吔
//=============================================================================
// �N���X��`
//=============================================================================
class CFinalAttackManager
{
public:
	typedef struct	//��s�̍U���͈͏��
	{
		int			nRangeType[MAX_FINAL_ATTACK_SIZE_X];	// �u���b�N�f�[�^
		int			nAttackRangeX;							// ���̍s�̃u���b�N��
	}RANGE_DATA;

	typedef struct	//�U�����
	{
		RANGE_DATA	RangeData[MAX_FINAL_ATTACK_SIZE_Y];	// �u���b�N
		int			nAttackRangeY;						// �u���b�N�̗�
		int			nAttackFrame[MAX_FINAL_HIT_TYPE];			// �t���[�����̕ۑ�
	}FINAL_ATTACK_RANGE_DATA;


	typedef enum	//�U���^�C���̎��
	{
		FINAL_ATTACK_RANGE_NONE = 0,//�Ȃ�
		FINAL_ATTACK_RANGE_CENTER,	//���S
		FINAL_ATTACK_RANGE_HIT_1,	//�U��(���l���オ��قǌ�ɍU������)
		FINAL_ATTACK_RANGE_HIT_2,
		FINAL_ATTACK_RANGE_HIT_3,
		FINAL_ATTACK_RANGE_HIT_4,
		FINAL_ATTACK_RANGE_HIT_5,
		FINAL_ATTACK_RANGE_HIT_6,
		FINAL_ATTACK_RANGE_HIT_7,
		FINAL_ATTACK_RANGE_HIT_8
	}FINAL_ATTACK_RANGE_TYPE;

	typedef struct	//�U���}�X�ڏ��
	{
		FINAL_ATTACK_RANGE_TYPE	RangeType;	//�U���}�X�^�C�v 
		D3DXVECTOR3				AttackPos;	//�U���̃}�X�ʒu
	}SQUARE_DATA;

	typedef struct	//�U���}�X�S�̂̏��
	{
		int			nMaxHitRange;													// �ő�q�b�g�}�X
		SQUARE_DATA SquareData[MAX_FINAL_ATTACK_SIZE_Y*MAX_FINAL_ATTACK_SIZE_X];	// �U���̃}�X�f�[�^[�ǂݍ��݌��E�̏c��]
		int			nAttackFrame[MAX_FINAL_HIT_TYPE];										// �U�����x
	}FINAL_ATTACK_SQUARE_DATA;

	typedef enum	//�U���̎��
	{
		FINAL_ATTACK_TYPE_1 = 0,	//�Ȃ�
		FINAL_ATTACK_TYPE_2,
		FINAL_ATTACK_TYPE_3,
		FINAL_ATTACK_TYPE_4,
		FINAL_ATTACK_TYPE_MAX
	}FINAL_ATTACK_TYPE;

	//�֐���`
	CFinalAttackManager();
	~CFinalAttackManager();
	static CFinalAttackManager * Create(void);	// �N���X����
	static void Release(void);					// �N���X�j��
	static FINAL_ATTACK_RANGE_DATA GetFinalAttackData(FINAL_ATTACK_TYPE Attack);
	static FINAL_ATTACK_SQUARE_DATA GetFinalAttack(FINAL_ATTACK_TYPE AttackType);

private:
	void	Load(void);		//�U���͈͓ǂݍ���
	void	PosCalc(void);	//�ʒu�v�Z

	static char*				m_pFileName[FINAL_ATTACK_TYPE_MAX];		// �t�@�C���l�[��
	static CFinalAttackManager*	m_pAttackBasis;							// �U���͈̓N���X�̃|�C���^
	FINAL_ATTACK_RANGE_DATA		m_AttackData[FINAL_ATTACK_TYPE_MAX];	// �U���̏��
	FINAL_ATTACK_SQUARE_DATA	m_AttackSwuare[FINAL_ATTACK_TYPE_MAX];	// �U���}�X�̏��

};
#endif
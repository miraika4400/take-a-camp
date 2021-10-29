//=============================================================================
//
// �U���͈͓ǂݍ��݃N���X [resource_attack.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _RESOURCE_ATTACK_H_
#define _RESOURCE_ATTACK_H_
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_ATTACK_SIZE_X	(10)	//�ő�u���b�N��
#define MAX_ATTACK_SIZE_Y	(10)	//�ő�X�e�[�W�T�C�Y
#define MAX_ATTACK_LEVEL	(3)		//�U���̍ő僌�x��
#define MAX_HIT_TYPE		(4)		//�q�b�g�}�X�^�C�v�̍ő吔
//=============================================================================
// �N���X��`
//=============================================================================
class CAttackManager
{
public:
	typedef struct	//��s�̍U���͈͏��
	{
		int			nRangeType[MAX_ATTACK_SIZE_X];	// �u���b�N�f�[�^
		int			nAttackRangeX;					// ���̍s�̃u���b�N��
	}RANGE_DATA;

	typedef struct	//�U�����
	{
		RANGE_DATA	RangeData[MAX_ATTACK_SIZE_Y];	// �u���b�N
		int			nAttackRangeY;					// �u���b�N�̗�
		int			nAttackFrame[MAX_HIT_TYPE];
	}ATTACK_RANGE_DATA;


	typedef enum	//�U���^�C���̎��
	{
		ATTACK_RANGE_NONE = 0,	//�Ȃ�
		ATTACK_RANGE_CENTER,	//���S
		ATTACK_RANGE_HIT_1,		//�U��(���l���オ��قǌ�ɍU������)
		ATTACK_RANGE_HIT_2,
		ATTACK_RANGE_HIT_3,
		ATTACK_RANGE_HIT_4,
		ATTACK_RANGE_HIT_5,
		ATTACK_RANGE_HIT_6,
		ATTACK_RANGE_HIT_7,
		ATTACK_RANGE_HIT_8
	}ATTACK_RANGE_TYPE;

	typedef struct	//�U���}�X�ڏ��
	{
		ATTACK_RANGE_TYPE	RangeType;	//�U���}�X�^�C�v 
		D3DXVECTOR3			AttackPos;	//�U���̃}�X�ʒu
	}SQUARE_DATA;

	typedef struct	//�U���}�X�S�̂̏��
	{
		int			nMaxHitRange;										// �ő�q�b�g�}�X
		SQUARE_DATA SquareData[MAX_ATTACK_SIZE_Y*MAX_ATTACK_SIZE_X];	// �U���̃}�X�f�[�^[�ǂݍ��݌��E�̏c��]
		int			nAttackFrame[MAX_HIT_TYPE];					// �U�����x
	}ATTACK_SQUARE_DATA;

	typedef enum	//�U���̎��
	{
		ATTACK_TYPE_1 = 0,	//�Ȃ�
		ATTACK_TYPE_2,
		ATTACK_TYPE_3,
		ATTACK_TYPE_4,
		ATTACK_TYPE_MAX
	}ATTACK_TYPE;

	//�֐���`
	CAttackManager();
	~CAttackManager();
	static CAttackManager * Create(void);	// �N���X����
	static void Release(void);				// �N���X�j��
	static ATTACK_RANGE_DATA GetAttackData(ATTACK_TYPE Attack,int nLevel);
	static ATTACK_SQUARE_DATA GetAttack(ATTACK_TYPE AttackType, int nLevel);

private:
	void	Load(void);		//�U���͈͓ǂݍ���
	void	PosCalc(void);	//�ʒu�v�Z

	static char*			m_pFileName[ATTACK_TYPE_MAX];		// �t�@�C���l�[��
	static CAttackManager*	m_pAttackBasis;						// �U���͈̓N���X�̃|�C���^
	ATTACK_RANGE_DATA		m_AttackData[ATTACK_TYPE_MAX][MAX_ATTACK_LEVEL];		// �U���̏��
	ATTACK_SQUARE_DATA		m_AttackSwuare[ATTACK_TYPE_MAX][MAX_ATTACK_LEVEL];	// �U���}�X�̏��

};
#endif
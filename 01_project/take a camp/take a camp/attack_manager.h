//=============================================================================
//
// �U���Ǘ��N���X [attack_manager.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _ATTACK_MANAGER_H_
#define _ATTACK_MANAGER_H_
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_ATTACK_SIZE_X	(5)	//�ő�u���b�N��
#define MAX_ATTACK_SIZE_Y	(5)	//�ő�X�e�[�W�T�C�Y

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
		D3DXVECTOR3	m_pos;							// �ʒu		
	}ATTACK_DATA;

	typedef enum	//�U���^�C���̎��
	{
		ATTACK_RANGE_NONE = 0,	//�Ȃ�
		ATTACK_RANGE_CENTER,	//���S
		ATTACK_RANGE_HIT,		//�U��
	}ATTACK_RANGE_TYPE;

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
	static ATTACK_DATA GetAttackData(ATTACK_TYPE Attack);

private:
	void	Load(void);		//�U���͈͓ǂݍ���

	static char*	m_pFileName[ATTACK_TYPE_MAX];	// �t�@�C���l�[��
	static CAttackManager* m_pAttackBasis;				// �U���͈̓N���X�̃|�C���^
	ATTACK_DATA	m_AttackData[ATTACK_TYPE_MAX];			// �U���̏��
};
#endif
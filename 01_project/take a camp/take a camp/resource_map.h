//=============================================================================
//
// �}�b�v�ǂݍ��݃N���X [resource_map.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _MAP_BASIS_H_
#define _MAP_BASIS_H_
//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_STAGE_SIZE_X	(50)	//�ő�u���b�N��
#define MAX_STAGE_SIZE_Y	(50)	//�ő�X�e�[�W�T�C�Y
#define MAX_STAGE_COUNT		(1)		//�ő�X�e�[�W��

//=============================================================================
// �N���X��`
//=============================================================================
class CMapManager 
{
public:
	typedef struct //��s�̃u���b�N���
	{
		int			nBlockType[MAX_STAGE_SIZE_X];	// �u���b�N�f�[�^
		int			nStageSizeX;					// ���̍s�̃u���b�N��
	}BLOCK_DATA;

	typedef struct	//�X�e�[�W���
	{
		BLOCK_DATA	BlockData[MAX_STAGE_SIZE_Y];	// �u���b�N
		int			nStageSizeY;					// �u���b�N�̗�
		D3DXVECTOR3	m_pos;							// �ʒu		
	}MAP_DATA;

	typedef enum	//�^�C���̎��
	{
		BLOCK_TYPE_NONE = 0,	// �Ȃ�
		BLOCK_TYPE_1P_START,	// 1P�X�^�[�g�ʒu
		BLOCK_TYPE_2P_START,	// 2P�X�^�[�g�ʒu
		BLOCK_TYPE_3P_START,	// 3P�X�^�[�g�ʒu
		BLOCK_TYPE_4P_START,	// 4P�X�^�[�g�ʒu
		BLOCK_TYPE_BLOCK,		// ���u���u���b�N
		BLOCK_TYPE_NEEDLE_BLOCK,// �Ƃ��u���b�N
		BLOCK_TYPE_MOVE_BLOCK,	// �ړ��u���b�N
	}BLOCK_TYPE;

	typedef enum	//�}�b�v�̎��
	{
		MAP_TYPE_1 = 0,	//�}�b�v1
		MAP_TYPE_2,
		MAP_TYPE_3,
		MAP_TYPE_4,
		MAP_TYPE_MAX
	}MAP_TYPE;

	//�֐���`
	CMapManager();
	~CMapManager();
	static CMapManager *Create(void);					// �N���X����
	static void			Release(void);					// �N���X�j��
	static MAP_DATA		GetMapData(MAP_TYPE MapData);

private:
	void	Load(void);

	static char*		m_pFileName[MAP_TYPE_MAX];	// �t�@�C���l�[��
	static CMapManager*	m_pMapBasis;				// �}�b�v�N���X�̃|�C���^
	MAP_DATA			m_MapData[MAP_TYPE_MAX];	// �X�e�[�W�̏��
};
#endif
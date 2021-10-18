//=============================================================================
//
// �X�e�[�W [stage.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _STAGE_H_
#define _STAGE_H_
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
#define MAX_STAGE_COUNT		(3)		//�ő�X�e�[�W��

//=============================================================================
// �N���X��`
//=============================================================================
class CStage : public CScene
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
		BLOCK_TYPE_NONE = 0,	//�Ȃ�
		BLOCK_TYPE_1P_START,	//1P�X�^�[�g�ʒu
		BLOCK_TYPE_2P_START,	//2P�X�^�[�g�ʒu
		BLOCK_TYPE_3P_START,	//3P�X�^�[�g�ʒu
		BLOCK_TYPE_4P_START,	//4P�X�^�[�g�ʒu
		BLOCK_TYPE_BLOCK,		//���u���u���b�N
		
	}BLOCK_TYPE;

	//�֐���`
	CStage();
	~CStage();
	static void	Load(void);
	static CStage *Create(D3DXVECTOR3 pos);
	HRESULT Init(void);
	void	Uninit(void);
	void	Draw(void);
	void	Update(void);
	void	MapCreate(void);						//�}�b�v�̐���
	MAP_DATA GetMapData(void) { return m_MapData; }	//�}�b�v���Q�b�^�[
private:
	static char*		m_pFileName;	// �t�@�C���l�[��
	static MAP_DATA		m_MapData;		// �X�e�[�W�̏��
};
#endif
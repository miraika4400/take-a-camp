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
		int			nBlockType[MAX_STAGE_SIZE_X];	//�u���b�N�f�[�^
		int			nStageSizeX;					//���̍s�̃u���b�N��
	}BLOCK_DATA;

	typedef struct	//�X�e�[�W���
	{
		BLOCK_DATA	BlockData[MAX_STAGE_SIZE_Y];	//�u���b�N
		int			nStageSizeY;					//�u���b�N�̗�
	}MAP_DATA;

	typedef enum	//�^�C���̎��
	{
		BLOCK_TYPE_NONE = 0,	//�Ȃ�
		BLOCK_TYPE_,			//���u��
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
	void	MapCreate(void);							//�}�b�v�̐���
	void	SetPos(D3DXVECTOR3 pos) { m_pos = pos; }	//�ʒu�Z�b�^�[
	MAP_DATA GetMapData(void) { return m_pMapData; }	//�}�b�v���Q�b�^�[
private:
	static char*		m_pFileName;	// �t�@�C���l�[��
	static MAP_DATA		m_pMapData;		// �X�e�[�W�̏��
	D3DXVECTOR3			m_pos;			// �ʒu		
};
#endif
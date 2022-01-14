//=============================================================================
//
// ���[�v���w�b�_�[ [warp_tile.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _WARP_TILE_H_
#define _WARP_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "tile.h"
#include "map.h"
#include <vector>
//*****************************
//�O���錾
//*****************************
class CModel;
class CPlayer;

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************
class CWarpTile : public CTile
{
public:
	//*****************************
	// ��
	//*****************************
	// �X�e�[�g
	typedef enum
	{
		WARP_TILE_NORMAL = 0,	//�ʏ���
		WARP_TILE_WARP,			//���[�v���
		WARP_TILE_WARP_AFTER,	//���[�v��̏��
	}WARP_TILE_STATE;

	//���ʗp�^�C�v
	typedef enum
	{
		WARP_TILE_TYPE_NONE = -1,//�Ȃ�
		WARP_TILE_TYPE_1,		//�^�C�v1
		WARP_TILE_TYPE_2,		//�^�C�v2
		WARP_TILE_TYPE_3,		//�^�C�v3
		WARP_TILE_TYPE_4,		//�^�C�v4
		WARP_TILE_TYPE_5,		//�^�C�v5
		WARP_TILE_TYPE_6,		//�^�C�v6
		WARP_TILE_TYPE_MAX
	}WARP_TILE_TYPE;

	//*****************************
	//�����o�֐�
	//*****************************
	CWarpTile();
	~CWarpTile();

	static void Create_1(D3DXVECTOR3 pos, D3DXCOLOR col);	//���������i���ʔԍ�1�j
	static void Create_2(D3DXVECTOR3 pos, D3DXCOLOR col);	//���������i���ʔԍ�2�j
	static void Create_3(D3DXVECTOR3 pos, D3DXCOLOR col);	//���������i���ʔԍ�3�j
	static void Create_4(D3DXVECTOR3 pos, D3DXCOLOR col);	//���������i���ʔԍ�4�j
	static void Create_5(D3DXVECTOR3 pos, D3DXCOLOR col);	//���������i���ʔԍ�5�j
	static void Create_6(D3DXVECTOR3 pos, D3DXCOLOR col);	//���������i���ʔԍ�6�j

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

private:
	void HitPlayerAction(CPlayer*pPlayer);			// �v���C���[������Ă��邩
	void HitPlayerActionRelease(CPlayer*pPlayer);	// �v���C���[���~�肽��
	D3DXVECTOR3 RandTileSelect(void);				// ���̃��[�v��������_���Ŏ擾
	//*****************************
	// �����o�ϐ�
	//*****************************
	int				m_nLyncTile;								// �Ȃ����Ă���^�C��
	int				m_nPlayerCount[MAX_PLAYER];					// �s���ł���܂ł̃J�E���g
	WARP_TILE_STATE m_WarpState[MAX_PLAYER];					// ��ԕϐ�
	WARP_TILE_TYPE	m_WarpType;									// ���[�v���̎��ʗp�ϐ�
	static std::vector<std::vector<CWarpTile*>> m_pWarpTile;	// ���[�v���̃|�C���^���I�z��
	static int m_nTotalWarpTile;								// ����
};

#endif
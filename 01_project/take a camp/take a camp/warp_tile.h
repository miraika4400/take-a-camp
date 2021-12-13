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
		WARP_TILE_STOP			//��~���
	}WARP_TILE_STATE;

	//���ʗp�^�C�v
	typedef enum
	{
		WARP_TILE_TYPE_NONE = 0,//�Ȃ�
		WARP_TILE_TYPE_1,		//�^�C�v1
		WARP_TILE_TYPE_2,		//�^�C�v2
	}WARP_TILE_TYPE;

	//*****************************
	//�����o�֐�
	//*****************************
	CWarpTile();
	~CWarpTile();
	static CWarpTile *Create(D3DXVECTOR3 pos, WARP_TILE_TYPE nWarpTile);	//���������i�ʒu�Ǝ��ʔԍ��j
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

private:
	void HitPlayerAction(CPlayer*pPlayer);	// �v���C���[������Ă��邩
	
	//*****************************
	// �����o�ϐ�
	//*****************************
	WARP_TILE_TYPE	m_WarpType;					// ���[�v���̎��ʗp�ϐ�
		static std::vector<CWarpTile*> m_pWarpTile;	// ���[�v���̃|�C���^���I�z��
	static int m_nTotalWarpTile;				// ����
};

#endif
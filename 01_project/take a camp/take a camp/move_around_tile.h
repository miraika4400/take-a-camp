//=============================================================================
//
// �O��ɓ����� �w�b�_�[ [move_around_tile.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _MOVE_TILE_AROUND_H_
#define _MOVE_TILE_AROUND_H_

//*****************************
// �C���N���[�h
//*****************************
#include "move_tile.h"

//*****************************
//�O���錾
//*****************************
class CScene3d;

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************
class CAroundTile : public CMoveTile
{
public:

	//�����o�֐�
	CAroundTile();
	~CAroundTile();

	static void	Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	HRESULT		Init(void);
	void		Update(void);

	void		MoveRot(bool bReversal);
	void		TileCheck(void);

private:
	// �����o�ϐ�
	CScene3d*	m_Texture;

};

#endif
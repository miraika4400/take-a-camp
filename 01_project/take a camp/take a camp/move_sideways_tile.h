//=============================================================================
//
// ���ړ��ɓ����� �w�b�_�[ [move_sideways_tile.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _MOVE_SIDEWAYS_TILE_H_
#define _MOVE_SIDEWAYS_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "move_tile.h"

//*****************************
//�O���錾
//*****************************
class CModel;
class CScene3d;
//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************
class CSidewaysTile : public CMoveTile
{
public:

	//�����o�֐�
	CSidewaysTile();
	~CSidewaysTile();

	static void	Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	HRESULT		Init(void);
	void		Update(void);

	void		MoveRot(bool bReversal);
	void		TileCheck(void);
private:
	CScene3d*	m_Texture;
};

#endif
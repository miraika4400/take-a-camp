//====================================================
//
// titletransition_tile�w�b�_ [titletransition_tile.h]
// Author : �ɓ��@�z��
//
//====================================================

//��d�C���N���[�h�h�~
#ifndef _TITLETRANSITION_TILE_H_
#define _TITLETRANSITION_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "tile.h"

//*****************************
//�O���錾
//*****************************
class CScene3d;

//*****************************
// �N���X��`
//*****************************

// �_�~�[�^�C���N���X
class CTitleTransitionTile : public CTile
{
public:
	//============
	// �����o�֐�
	//===========
	CTitleTransitionTile();
	~CTitleTransitionTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);

	HRESULT Init(void);
	void Uninit(void);
private:

	//============
	// �����o�ϐ�
	//===========
	CScene3d *m_pCrossPolygon;        // �}�[�N
};

#endif
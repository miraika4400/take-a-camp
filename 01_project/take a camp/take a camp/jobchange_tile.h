//====================================================
//
// jobchange_tile�w�b�_ [jobchange_tile.h]
// Author : �ɓ��@�z��
//
//====================================================

//��d�C���N���[�h�h�~
#ifndef _JOBCHANGE_TILE_H_
#define _JOBCHANGE_TILE_H_

//====================================================
// �C���N���[�h
//====================================================
#include "tile.h"

//====================================================
//�O���錾
//====================================================
class CScene3d;

//====================================================
// �N���X��`
//====================================================

// �_�~�[�^�C���N���X
class CJobchangeTile : public CTile
{
public:
	//============
	// �����o�֐�
	//===========
	CJobchangeTile();
	~CJobchangeTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
private:

	//============
	// �����o�ϐ�
	//===========
	CScene3d *m_pCrossPolygon;	// �}�[�N
};

#endif
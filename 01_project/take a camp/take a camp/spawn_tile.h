//=============================================================================
//
// spawn_tile�w�b�_ [spawn_tile.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _SPAWN_TILE_H_
#define _SPAWN_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "tile.h"

//*****************************
//�O���錾
//*****************************
class CScene3d;
class CBullet;
//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************

// �X�|�[���^�C���N���X
class CSpawnTile : public CTile
{
public:
	//�����o�֐�
	CSpawnTile();
	~CSpawnTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);

	HRESULT Init(void);
	void Uninit(void);
private:

	// �����o�ϐ�
	CScene3d *m_pCrossPolygon;        // �}�[�N

};

#endif
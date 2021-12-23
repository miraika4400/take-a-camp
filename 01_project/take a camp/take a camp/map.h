//=============================================================================
//
// �}�b�v�N���X [map.h]
// Author : �g�c�I�l
//
//=============================================================================
#ifndef _MAP_1_H_
#define _MAP_1_H_

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "model.h"
#include "scene.h"
#include "resource_map.h"
//=============================================================================
// �O���錾
//=============================================================================
class CItem;
//=============================================================================
// �N���X��`
//=============================================================================
class CMap : public CScene
{
public:
	//�֐���`
	CMap();
	~CMap();
	static CMap *Create(CMapManager::MAP_TYPE MapType);
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
	void	MapCreate(void);									// �}�b�v�̐���

	void SetMapData(CMapManager::MAP_DATA MapData);
	CMapManager::MAP_DATA GetMapData(void);

private:
	void	ItemSpawn(void);		// �A�C�e���̐�������
	int		m_nItemSpawnCount;		// �A�C�e���X�|�[���܂ł̃J�E���g
	//CItem * m_pItem;				// �A�C�e���̃|�C���^
	CMapManager::MAP_DATA m_MapData;
	CMapManager::MAP_TYPE m_MapType;
};
#endif
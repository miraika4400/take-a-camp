////////////////////////////////////////////////////
//
//    tile�N���X�̏���[tile.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "spawn_tile.h"
#include "scene3d.h"
#include "resource_texture.h"
#include "bullet.h"

//*****************************
// �}�N����`

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CSpawnTile::CSpawnTile()
{
	m_pCrossPolygon = NULL;

}

//******************************
// �f�X�g���N�^
//******************************
CSpawnTile::~CSpawnTile()
{
}

//******************************
// �N���X����
//******************************
CSpawnTile * CSpawnTile::Create(D3DXVECTOR3 pos , D3DXCOLOR col)
{
	// �������̊m��
	CSpawnTile *pTile;
	pTile = new CSpawnTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v

	 // �~�}�[�N�̐���
	pTile->m_pCrossPolygon = CScene3d::Create(D3DXVECTOR3(pos.x, pos.y + (TILE_SIZE_Y / 2) + 1.0f, pos.z), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	pTile->m_pCrossPolygon->SetColor(col);
	pTile->m_pCrossPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CROSS_MARK));
	pTile->m_pCrossPolygon->SetPriority(OBJTYPE_UI);

	return pTile;
}

//******************************
// ����������
//******************************
HRESULT CSpawnTile::Init(void)
{
	if (FAILED(CTile::Init()))
	{
		return E_FAIL;
	}



	SetColor(TILE_DEFAULT_COLOR);

	return S_OK;
}

//******************************
// �I������
//******************************
void CSpawnTile::Uninit(void)
{
	CTile::Uninit();
}
//====================================================
//
// dummy_tile�N���X�̏���[dummy_tile.cpp]
// Author:�ɓ��z��
//
//====================================================

//====================================================
// �C���N���[�h
//====================================================
#include "dummy_tile.h"
#include "scene3d.h"
#include "resource_texture.h"

//====================================================
// �R���X�g���N�^
//====================================================
CDummyTile::CDummyTile()
{
	m_pCrossPolygon = NULL;
}

//====================================================
// �f�X�g���N�^
//====================================================
CDummyTile::~CDummyTile()
{
}

//====================================================
// �N���X����
//====================================================
void CDummyTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// �������̊m��
	CDummyTile *pDummyTile;
	pDummyTile = new CDummyTile;

	// ������
	pDummyTile->Init();

	// �e�l�̑���E�Z�b�g
	pDummyTile->SetPos(pos);
	pDummyTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v
	pDummyTile->SetRide(true);			  // �ڂ�Ȃ��悤�Ƀt���O�𗧂Ă�

	// �~�}�[�N�̐���
	pDummyTile->m_pCrossPolygon = CScene3d::Create(D3DXVECTOR3(pos.x, pos.y + (TILE_SIZE_Y / 2) + 1.0f, pos.z), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	pDummyTile->m_pCrossPolygon->SetColor(col);
	pDummyTile->m_pCrossPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CROSS_MARK));
	pDummyTile->m_pCrossPolygon->SetPriority(OBJTYPE_MAP);
}

//====================================================
// ����������
//====================================================
HRESULT CDummyTile::Init(void)
{
	// �^�C���̏�����
	if (FAILED(CTile::Init()))
	{
		return E_FAIL;
	}

	// �^�C���̐F�̃Z�b�g
	SetColor(TILE_DEFAULT_COLOR);

	return S_OK;
}

//====================================================
// �I������
//====================================================
void CDummyTile::Uninit(void)
{
	// �^�C���̏I��
	CTile::Uninit();
}
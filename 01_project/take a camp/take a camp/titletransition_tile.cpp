//====================================================
//
//    dummy_tile�N���X�̏���[dummy_tile.cpp]
//    Author:�ɓ��@�z��
//
//====================================================

//====================================================
// �C���N���[�h
//====================================================
#include "titletransition_tile.h"
#include "scene3d.h"
#include "resource_texture.h"

//====================================================
// �R���X�g���N�^
//====================================================
CTitleTransitionTile::CTitleTransitionTile()
{
	m_pCrossPolygon = NULL;
}

//====================================================
// �f�X�g���N�^
//====================================================
CTitleTransitionTile::~CTitleTransitionTile()
{
}

//====================================================
// �N���X����
//====================================================
void CTitleTransitionTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// �������̊m��
	CTitleTransitionTile *pTile;
	pTile = new CTitleTransitionTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v
	pTile->SetRide(true);			  // �ڂ�Ȃ��悤�Ƀt���O�𗧂Ă�

	// �~�}�[�N�̐���
	//pTile->m_pCrossPolygon = CScene3d::Create(D3DXVECTOR3(pos.x, pos.y + (TILE_SIZE_Y / 2) + 1.0f, pos.z), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	//pTile->m_pCrossPolygon->SetColor(col);
	//pTile->m_pCrossPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CROSS_MARK));
	//pTile->m_pCrossPolygon->SetPriority(OBJTYPE_MAP);
}

//====================================================
// ����������
//====================================================
HRESULT CTitleTransitionTile::Init(void)
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
void CTitleTransitionTile::Uninit(void)
{
	// �^�C���̏I��
	CTile::Uninit();
}
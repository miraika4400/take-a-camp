//====================================================
//
//    titletransition_tile�N���X�̏���[titletransition_tile.cpp]
//    Author:�ɓ��@�z��
//
//====================================================

//====================================================
// �C���N���[�h
//====================================================
#include "titletransition_tile.h"
#include "scene3d.h"
#include "resource_texture.h"
#include "tutorial.h"
#include "collision.h"
#include "player.h"
#include "chara_select.h"
#include "fade.h"

//*****************************
//�}�N����`
//*****************************
#define TILE_COLOR	(D3DXCOLOR(0.1f, 0.1f, 0.6f, 1.0f))

//====================================================
// �R���X�g���N�^
//====================================================
CTitleTransitionTile::CTitleTransitionTile()
{
	m_pCrossPolygon = NULL;
	m_nPlayerCount = 0;
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
	SetColor(TILE_COLOR);

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

//====================================================
// �X�V����
//====================================================
void CTitleTransitionTile::Update(void)
{
	// �^�C���̍X�V
	CTile::Update();

	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		// ���̃^�C���ɍڂ�����
		if (CCollision::CollisionSphere(GetCollision(), pPlayer->GetCollision()))
		{
			m_nPlayerCount++;

			// �F�𓧖��ɂ��Ĉړ��ł��Ȃ��悤�ɂ���
			pPlayer->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
			pPlayer->SetUpdateFlag(false);
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	//// ���̃^�C���ɍڂ�����
	//if (GetHitPlayerFlag())
	//{
	//	m_nPlayerCount++;
	//}

	// �`���[�g���A���̃|�C���^�̎擾
	CTutorial * pTutrial = CManager::GetTutorial();

	// �`���[�g���A������������
	if (pTutrial)
	{
		// �t�F�[�Y�����ׂďI�������Ƃ�
		if (CManager::GetTutorial()->GetTutorialPhase() == CTutorial::PHASE_FINISH)
		{
			// �ڂ��悤�ɂ���
			SetRide(false);
		}
	}

	//// �S�����̃^�C���ɏ������
	//if (CCharaSelect::GetEntryPlayerNum() == m_nPlayerCount)
	//{
	//	CManager::GetFade()->SetFade(CManager::MODE_TITLE);
	//}
}
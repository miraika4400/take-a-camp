////////////////////////////////////////////////////
//
//    �g�Q�^�C���̏���[needle_tile.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "needle_tile.h"
#include "model.h"
#include "resource_model.h"
#include "resource_texture.h"
#include "player.h"
#include "collision.h"
#include "scene3d.h"

//*****************************
// �}�N����`
//*****************************
#define NEEDLE_POS_Y	(0)					// 
#define NEEDLE_POS_Y_UP (TILE_SIZE_Y / 2)	// 
#define NEEDLE_POS_RATE	(0.2f)				// 
#define DEATH_FRAME		(10.0f)				// �G��Ă��玀�ʂ܂ł̃t���[����
#define UP_FRAME		(80)				// �Ƃ����オ���Ă���Ԃ̃J�E���g
#define DOWN_FRAME		(180)				// �Ƃ����������Ă���Ԃ̃J�E���g

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CNeedleTile::CNeedleTile()
{
	m_pNeedleModel = NULL;
	m_nCntHit = 0;
	m_bUp = false;
	m_nUpCnt = 0;
}

//******************************
// �f�X�g���N�^
//******************************
CNeedleTile::~CNeedleTile()
{
}

//******************************
// �N���X����
//******************************
void CNeedleTile::Create(D3DXVECTOR3 pos , D3DXCOLOR col )
{
	// �������̊m��
	CNeedleTile *pTile;
	pTile = new CNeedleTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);

	// �Ƃ��u���b�N�̐���
	pTile->m_pNeedleModel = CModel::Create(D3DXVECTOR3(pos.x, pos.y + (TILE_SIZE_Y / 4), pos.z), CResourceModel::MODEL_NEEDLE);
	pTile->m_pNeedleModel->SetPriority(OBJTYPE_MAP);
 
	// ��
	pTile->m_pHole = CScene3d::Create(pTile->GetPos(), D3DXVECTOR3(TILE_ONE_SIDE-1, 0.0f, TILE_ONE_SIDE-1));
	pTile->m_pHole->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NEEDLE));
	pTile->m_pHole->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	pTile->m_pHole->SetPriority(OBJTYPE_MAP);

}

//******************************
// �X�V����
//******************************
void CNeedleTile::Update(void)
{
	CColorTile::Update();

	ManageNeedle();

	// ���ʒu�̒���
	D3DXVECTOR3 pos = m_pHole->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.2f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.2f, GetPos().z);

		m_pHole->SetPos(pos);
	}

}

//******************************
// �v���C���[�ƃq�b�g���̏���
//******************************
void CNeedleTile:: HitPlayerAction(CPlayer*pPlayer)
{
	if (m_bUp)
	{
		m_nCntHit++;
		if (m_nCntHit > DEATH_FRAME)
		{
			pPlayer->Death();
			m_nCntHit = 0;
		}
	}
}

//******************************
// �Ƃ��̊Ǘ�
//******************************
void CNeedleTile::ManageNeedle(void)
{
	// �Ƃ��̍����̏���
	D3DXVECTOR3 needlePos = m_pNeedleModel->GetPos();
	float fDistPosY;

	if (m_bUp)
	{
		fDistPosY = GetPos().y + NEEDLE_POS_Y_UP;

		m_nUpCnt++;
		if (m_nUpCnt > UP_FRAME)
		{
			m_bUp = false;
			m_nUpCnt = 0;
		}
	}
	else
	{
		fDistPosY = GetPos().y + NEEDLE_POS_Y;

		// �J�E���g�̏�����
		m_nCntHit = 0;

		m_nUpCnt++;
		if (m_nUpCnt > DOWN_FRAME)
		{
			m_bUp = true;
			m_nUpCnt = 0;
		}
	}
	needlePos.y += (fDistPosY - needlePos.y)*NEEDLE_POS_RATE;
	m_pNeedleModel->SetPos(needlePos);
}
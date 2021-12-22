//=============================================================================
//
// ���[�v���w�b�_�[ [warp_tile.cpp]
// Author : �g�c �I�l
//
//=============================================================================

//*****************************
// �C���N���[�h
//*****************************
#include "warp_tile.h"
#include "player.h"
#include <vector>
#include <time.h>

//******************************
// �ÓI�����o�ϐ��錾
//******************************
int CWarpTile::m_nTotalWarpTile = 0;
std::vector<CWarpTile*> CWarpTile::m_pWarpTile;
//******************************
// �R���X�g���N�^
//******************************
CWarpTile::CWarpTile()
{
	m_WarpState = WARP_TILE_NORMAL;
	m_WarpType  = WARP_TILE_TYPE_NONE;
}

//******************************
// �f�X�g���N�^
//******************************
CWarpTile::~CWarpTile()
{
}

//******************************
// ��������(�^�C�v1)
//******************************
void CWarpTile::Create_1(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//���I�z��Ƀ������m��
	m_pWarpTile.emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(m_nTotalWarpTile)!=NULL)
	{
		//���ʗp���l�ݒ�
		m_pWarpTile.at(m_nTotalWarpTile)->m_WarpType = WARP_TILE_TYPE_1;
		//����������
		m_pWarpTile.at(m_nTotalWarpTile)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(m_nTotalWarpTile)->SetPos(pos);
		//���[�v�^�C���̑����ǉ�
		m_nTotalWarpTile++;
	}
}

//******************************
// ��������(�^�C�v2)
//******************************
void CWarpTile::Create_2(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//���I�z��Ƀ������m��
	m_pWarpTile.emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(m_nTotalWarpTile) != NULL)
	{
		//���ʗp���l�ݒ�
		m_pWarpTile.at(m_nTotalWarpTile)->m_WarpType = WARP_TILE_TYPE_2;
		//����������
		m_pWarpTile.at(m_nTotalWarpTile)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(m_nTotalWarpTile)->SetPos(pos);
		m_pWarpTile.at(m_nTotalWarpTile)->SetPriority(OBJTYPE_TILE); 	// �I�u�W�F�N�g�^�C�v

		//���[�v�^�C���̑����ǉ�
		m_nTotalWarpTile++;
	}
}



//******************************
// ����������
//******************************
HRESULT CWarpTile::Init(void)
{
	//�^�C������������
	CTile::Init();
	//�^�C�v���Ƃ̌����ڕω�
	switch (m_WarpType)
	{
	case WARP_TILE_TYPE_1:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_2:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(1.0f,0.0f,1.0f,1.0f));
		break;
	}
	return S_OK;
}

//******************************
// �I������
//******************************
void CWarpTile::Uninit(void)
{
	//���I�z��̍폜
	for (int nWarpCount=0; nWarpCount<m_nTotalWarpTile; nWarpCount++)
	{
		if (m_pWarpTile.at(nWarpCount) == this)
		{
			m_nTotalWarpTile--;
			m_pWarpTile.erase(m_pWarpTile.begin() + (nWarpCount));
			break;
		}
	}

	//�I������
	CTile::Uninit();
}

//******************************
// �X�V����
//******************************
void CWarpTile::Update(void)
{
	switch (m_WarpState)
	{
		//�ʏ���
	case WARP_TILE_NORMAL:
		break;
		//���[�v���
	case WARP_TILE_WARP:
		break;
		//�@�\��~���
	case WARP_TILE_STOP:
		break;

	}

	// �^�C���X�V����
	CTile::Update();
}

//******************************
// �v���C���[������Ă��邩
//******************************
void CWarpTile::HitPlayerAction(CPlayer * pPlayer)
{
	switch (m_WarpState)
	{
	
	case WARP_TILE_NORMAL:	//�ʏ���
	{
		//�^�C���ɏ��Ȃ��Ȃ�t���O�𗧂Ă�
		SetRide(true);
		//�v���C���[���X�g�b�v��ԂɕύX
		pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);

		//���^�C�v�̃N���X�ۑ��p�ϐ�
		CWarpTile ** pWarpTile = nullptr;
		//���ۑ�
		int nArray = 0;
		//�����^�C�v���烏�[�v������߂�
		for (int nWarpCount = 0; nWarpCount<m_nTotalWarpTile; nWarpCount++)
		{
			//�����^�C�v��&&�����ȊO�̃|�C���^
			if (m_WarpType == m_pWarpTile.at(nWarpCount)->m_WarpType
				&&m_pWarpTile.at(nWarpCount) != this)
			{
				//���^�C�v�̃|�C���^�擾
				pWarpTile[nArray] = m_pWarpTile.at(nWarpCount);
				//�v���X
				nArray++;
			}
		}

		//�����_���֐��̏�����
		srand((unsigned int)time(NULL));
		//�����_���ɔ�΂��^�C��
		int nRandTile = rand() % nArray;

		//NULL�`�F�b�N
		if (pWarpTile[nRandTile] != nullptr)
		{
			//���[�v��Ԃ̕ύX
			m_WarpState = WARP_TILE_WARP;
			//���[�v��̃X�e�[�g�ω�
			pWarpTile[nRandTile]->m_WarpState = WARP_TILE_STOP;
			//�����_���Ƀ^�C���̈ʒu�ɔ�΂�
			pPlayer->SetPos(pWarpTile[nRandTile]->GetPos());
		}
	}
		break;
	case WARP_TILE_WARP:	//���[�v���

		break;
	case WARP_TILE_STOP:	//��~���
		//�v���C���[���X�g�b�v��ԂɕύX
		pPlayer->SetState(CPlayer::PLAYER_STATE_NORMAL);
		break;

	}
}

//******************************
// �v���C���[���~�肽����
//******************************
void CWarpTile::HitPlayerActionRelease(void)
{
	if (m_WarpState == WARP_TILE_STOP)
	{
		//�^�C���̃X�e�[�g��ω�
		m_WarpState = WARP_TILE_NORMAL;
		//�^�C���ɏ���t���O�𗧂Ă�
		SetRide(false);
	}
}

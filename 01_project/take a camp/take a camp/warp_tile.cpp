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
#include "collision.h"
#include <vector>
#include <time.h>

//******************************
// �ÓI�����o�ϐ��錾
//******************************
int CWarpTile::m_nTotalWarpTile = 0;
std::vector<std::vector<CWarpTile*>> CWarpTile::m_pWarpTile(WARP_TILE_TYPE_MAX, std::vector<CWarpTile*>(0));
//******************************
// �R���X�g���N�^
//******************************
CWarpTile::CWarpTile()
{
	m_nLyncTile = 0;
	m_WarpType = WARP_TILE_TYPE_NONE;
	m_WarpState = WARP_TILE_NORMAL;
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
	m_pWarpTile.at(WARP_TILE_TYPE_1).emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1)->m_WarpType = WARP_TILE_TYPE_1;
		//����������
		m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(WARP_TILE_TYPE_1).at(m_pWarpTile.at(WARP_TILE_TYPE_1).size() - 1)->SetPos(pos);
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
	m_pWarpTile.at(WARP_TILE_TYPE_2).emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1)->m_WarpType = WARP_TILE_TYPE_2;
		//����������
		m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(WARP_TILE_TYPE_2).at(m_pWarpTile.at(WARP_TILE_TYPE_2).size() - 1)->SetPos(pos);
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
	for (int nWarpType=0; nWarpType<WARP_TILE_TYPE_MAX; nWarpType++)
	{
		//�z��̍ő吔�擾
		int nMaxArray = m_pWarpTile.at(nWarpType).size();

		//�z�񕪉�
		for (int nWarpCount = 0; nWarpCount<nMaxArray; nWarpCount++)
		{
			if (m_pWarpTile.at(nWarpType).at(nWarpCount) == this)
			{
				m_pWarpTile.at(nWarpType).erase(m_pWarpTile.at(nWarpType).begin() + (nWarpCount));
				break;
			}
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
		//�z��̍ő吔�擾
		int nMaxArray = m_pWarpTile.at(m_WarpType).size();

		for (int nWarpCount = 0; nWarpCount < nMaxArray; nWarpCount++)
		{
			//�^�C���ɏ�Ȃ��t���O�𗧂Ă�
			m_pWarpTile.at(m_WarpType).at(nWarpCount)->SetRide(true);

		}
			//���[�v��Ԃ̕ύX
			m_WarpState = WARP_TILE_WARP;
			break;
		}
	case WARP_TILE_WARP:	//���[�v���
		{
		//�v���C���[�̏󋵊m�F
		if (pPlayer->GetState() != CPlayer::PLAYER_STATE_STOP
			&&pPlayer->GetState() != CPlayer::PLAYER_STATE_DEATH)
		{
			//�v���C���[�������ĂȂ��Ƃ��ɃX�e�[�g���~��ԂɕύX
			if (pPlayer->GetMoveFlag())
			{
				pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);
			}

		}
		else if (pPlayer->GetState() == CPlayer::PLAYER_STATE_STOP)
		{
			bool bLync = false;
			//�����_���̍ő�l
			int nMaxRand = m_pWarpTile.at(m_WarpType).size();
			//�����_���֐��̏�����
			srand((unsigned int)time(NULL));
			//�����^�C����I�΂Ȃ��悤�ɐݒ�
			while (!bLync)
			{
				//�����_���ɔ�΂��^�C��
				m_nLyncTile = rand() % nMaxRand;
				if (m_pWarpTile.at(m_WarpType).at(m_nLyncTile) != this)
				{
					//���[�v�𔲂���
					bLync = true;
				}
			}
			//�����_���ɒ��ԃ^�C���ʒu�擾
			D3DXVECTOR3 Tile = m_pWarpTile.at(m_WarpType).at(m_nLyncTile)->GetPos();
	
			//�z��̍ő吔�擾
			int nMaxArray = m_pWarpTile.at(m_WarpType).size();
			//�^�C�v�ݒ�
			for (int nWarpCount = 0; nWarpCount < nMaxArray; nWarpCount++)
			{
				if (m_nLyncTile != nWarpCount)
				{
					m_pWarpTile.at(m_WarpType).at(nWarpCount)->m_WarpState = WARP_TILE_STOP;
				}
				else
				{
					m_pWarpTile.at(m_WarpType).at(nWarpCount)->m_WarpState = WARP_TILE_WARP_AFTER;
				}
			}

			//�v���C���[�̈ʒu�ݒ�
			pPlayer->SetPos(D3DXVECTOR3(Tile.x, pPlayer->GetPos().y, Tile.z));
			pPlayer->GetCollision()->SetPos(D3DXVECTOR3(Tile.x, pPlayer->GetPos().y, Tile.z));
		}
			break;
		}
	case WARP_TILE_WARP_AFTER:	//���[�v����
	{
		//�v���C���[���m�[�}����ԂɕύX
		pPlayer->SetState(CPlayer::PLAYER_STATE_NORMAL);
		break;
	}

	case WARP_TILE_STOP:	//��~���
		{
			break;
		}
	}
}

//******************************
// �v���C���[���~�肽����
//******************************
void CWarpTile::HitPlayerActionRelease(void)
{
	if (m_WarpState == WARP_TILE_WARP_AFTER)
	{
		//�z��̍ő吔�擾
		int nMaxArray = m_pWarpTile.at(m_WarpType).size();

		for (int nWarpCount = 0; nWarpCount < nMaxArray; nWarpCount++)
		{
			//�^�C���̃X�e�[�g��ω�
			m_pWarpTile.at(m_WarpType).at(nWarpCount)->m_WarpState = WARP_TILE_NORMAL;

			//�^�C���ɏ���t���O�𗧂Ă�
			m_pWarpTile.at(m_WarpType).at(nWarpCount)->SetRide(false);

		}
	}
}

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
#include "sound.h"
#include <vector>
#include <time.h>

//*****************************
//�}�N����`
//*****************************
#define MAX_RESTRAINT (20)
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
	memset(&m_nPlayerCount, 0, sizeof(m_nPlayerCount));
	m_nLyncTile = 0;
	memset(&m_WarpState, WARP_TILE_NORMAL, sizeof(m_WarpState));
	m_WarpType = WARP_TILE_TYPE_NONE;
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
// ��������(�^�C�v3)
//******************************
void CWarpTile::Create_3(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//���I�z��Ƀ������m��
	m_pWarpTile.at(WARP_TILE_TYPE_3).emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1)->m_WarpType = WARP_TILE_TYPE_3;
		//����������
		m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(WARP_TILE_TYPE_3).at(m_pWarpTile.at(WARP_TILE_TYPE_3).size() - 1)->SetPos(pos);
		//���[�v�^�C���̑����ǉ�
		m_nTotalWarpTile++;
	}

}

//******************************
// ��������(�^�C�v4)
//******************************
void CWarpTile::Create_4(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//���I�z��Ƀ������m��
	m_pWarpTile.at(WARP_TILE_TYPE_4).emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1)->m_WarpType = WARP_TILE_TYPE_4;
		//����������
		m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(WARP_TILE_TYPE_4).at(m_pWarpTile.at(WARP_TILE_TYPE_4).size() - 1)->SetPos(pos);
		//���[�v�^�C���̑����ǉ�
		m_nTotalWarpTile++;
	}

}

//******************************
// ��������(�^�C�v5)
//******************************
void CWarpTile::Create_5(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//���I�z��Ƀ������m��
	m_pWarpTile.at(WARP_TILE_TYPE_5).emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1)->m_WarpType = WARP_TILE_TYPE_5;
		//����������
		m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(WARP_TILE_TYPE_5).at(m_pWarpTile.at(WARP_TILE_TYPE_5).size() - 1)->SetPos(pos);
		//���[�v�^�C���̑����ǉ�
		m_nTotalWarpTile++;
	}

}

//******************************
// ��������(�^�C�v6)
//******************************
void CWarpTile::Create_6(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	//���I�z��Ƀ������m��
	m_pWarpTile.at(WARP_TILE_TYPE_6).emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1) != NULL)
	{
		m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1)->m_WarpType = WARP_TILE_TYPE_6;
		//����������
		m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1)->Init();
		//�ʒu�ݒ�
		m_pWarpTile.at(WARP_TILE_TYPE_6).at(m_pWarpTile.at(WARP_TILE_TYPE_6).size() - 1)->SetPos(pos);
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
	case WARP_TILE_TYPE_3:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_4:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_5:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_6:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));
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

	// �^�C���X�V����
	CTile::Update();
}

//******************************
// �v���C���[������Ă��邩
//******************************
void CWarpTile::HitPlayerAction(CPlayer * pPlayer)
{
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	switch (m_WarpState[pPlayer->GetPlayerNumber()])
	{
	case WARP_TILE_NORMAL:	//�ʏ���
		{
			//�v���C���[�̏󋵊m�F
			if (pPlayer->GetState() != CPlayer::PLAYER_STATE_STOP
				&&pPlayer->GetState() != CPlayer::PLAYER_STATE_DEATH)
			{
				//�v���C���[�������ĂȂ��Ƃ��ɃX�e�[�g���~��ԂɕύX
				if (pPlayer->GetMoveFlag())
				{
					pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);
					m_WarpState[pPlayer->GetPlayerNumber()] = WARP_TILE_WARP;

					// SE�Đ�
					pSound->Play(CSound::LABEL_SE_WARP);
				}
			}
			break;
		}
	case WARP_TILE_WARP:	//���[�v���
		{
			//���[�v��̐ݒ�
			D3DXVECTOR3 Tile = RandTileSelect();
			//�v���C���[�̈ʒu�ݒ�
			pPlayer->SetPos(D3DXVECTOR3(Tile.x, pPlayer->GetPos().y, Tile.z));
			
			m_pWarpTile.at(m_WarpType).at(m_nLyncTile)->m_WarpState[pPlayer->GetPlayerNumber()] = WARP_TILE_WARP_AFTER;
			break;
		}
	case WARP_TILE_WARP_AFTER:	//���[�v����
		{
			m_nPlayerCount[pPlayer->GetPlayerNumber()]++;
			if (m_nPlayerCount[pPlayer->GetPlayerNumber()]>MAX_RESTRAINT)
			{
				//�v���C���[���m�[�}����ԂɕύX
				pPlayer->SetState(CPlayer::PLAYER_STATE_NORMAL);
			}
			break;
		}
	}
}

//******************************
// �v���C���[���~�肽����
//******************************
void CWarpTile::HitPlayerActionRelease(CPlayer*pPlayer)
{
	if (m_WarpState[pPlayer->GetPlayerNumber()] == WARP_TILE_WARP_AFTER)
	{
		//�z��̍ő吔�擾
		int nMaxArray = m_pWarpTile.at(m_WarpType).size();

		for (int nWarpCount = 0; nWarpCount < nMaxArray; nWarpCount++)
		{
			//�^�C���̃X�e�[�g��ω�
			m_pWarpTile.at(m_WarpType).at(nWarpCount)->m_WarpState[pPlayer->GetPlayerNumber()] = WARP_TILE_NORMAL;
			m_nPlayerCount[pPlayer->GetPlayerNumber()] = 0;
		}
	}

}

//******************************
// ���̃��[�v��������_���Ŏ擾
//******************************
D3DXVECTOR3 CWarpTile::RandTileSelect(void)
{
	//���[�v�𑱂��邩
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
	return m_pWarpTile.at(m_WarpType).at(m_nLyncTile)->GetPos();

}


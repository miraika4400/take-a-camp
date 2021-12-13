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
#include <vector>
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
	m_WarpType = WARP_TILE_TYPE_NONE;
}

//******************************
// �f�X�g���N�^
//******************************
CWarpTile::~CWarpTile()
{
}

//******************************
// ��������
//******************************
CWarpTile * CWarpTile::Create(D3DXVECTOR3 pos, WARP_TILE_TYPE nWarpTile)
{
	//
	//if (m_nTotalWarpTile == 0)
	//{

	//}
	//else
	//{
	//}

	//���I�z��Ƀ������m��
	m_pWarpTile.emplace_back(new CWarpTile);

	//NULL�`�F�b�N
	if (m_pWarpTile.at(m_nTotalWarpTile)!=NULL)
	{
		//�ʒu�ݒ�
		m_pWarpTile.at(m_nTotalWarpTile)->SetPos(pos);
		//���ʗp���l�ݒ�
		m_pWarpTile.at(m_nTotalWarpTile)->m_WarpType = nWarpTile;
		//����������
		m_pWarpTile.at(m_nTotalWarpTile)->Init();
		//���[�v�^�C���̑����ǉ�
		m_nTotalWarpTile++;
	}
	

	return m_pWarpTile.at(m_nTotalWarpTile-1);
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
		SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		break;
	case WARP_TILE_TYPE_2:
		//�e�N�X�`���̐ݒ�

		//�J���[�̐ݒ�
		SetColor(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
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
		if (m_pWarpTile.at(nWarpCount) = this)
		{
			m_nTotalWarpTile--;
			m_pWarpTile.erase(m_pWarpTile.begin() + (nWarpCount - 1));
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

}

//******************************
// �v���C���[������Ă��邩
//******************************
void CWarpTile::HitPlayerAction(CPlayer * pPlayer)
{

}

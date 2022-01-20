////////////////////////////////////////////////////
//
//    �O��ɓ����^�C���̏���[move_around_tile.cpp]
//    Author:�g�c �I�l
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "move_around_tile.h"
#include "scene3d.h"
#include "resource_texture.h"

//******************************
// �R���X�g���N�^
//******************************
CAroundTile::CAroundTile()
{
	m_Texture = nullptr;
}

//******************************
// �f�X�g���N�^
//******************************
CAroundTile::~CAroundTile()
{
}

//******************************
// �N���X����
//******************************
void CAroundTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// �������̊m��
	CAroundTile *pTile;
	pTile = new CAroundTile;

	//NULL�`�F�b�N
	if (pTile != NULL)
	{
		// ������
		pTile->Init();

		// �e�l�̑���E�Z�b�g
		pTile->SetPos(pos);					// �ʒu
		pTile->SetMove(pos);				// �ړ���
		pTile->SetPriority(OBJTYPE_TILE); 	// �I�u�W�F�N�g�^�C�v
	}
}

//******************************
// ����������
//******************************
HRESULT CAroundTile::Init(void)
{
	//����������
	CMoveTile::Init();

	//�e�N�X�`���p�|���S��
	m_Texture = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	m_Texture->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_MOVE_TILE));
	D3DXVECTOR2 uv[NUM_VERTEX];
	uv[0] = D3DXVECTOR2(0,1);
	uv[1] = D3DXVECTOR2(0,0);
	uv[2] = D3DXVECTOR2(1,1);
	uv[3] = D3DXVECTOR2(1,0);
	m_Texture->SetTextureUV(uv);
	m_Texture->SetColor(TILE_DEFAULT_COLOR);
	m_Texture->SetPriority(OBJTYPE_MAP);

	return S_OK;
}

//******************************
// �X�V����
//******************************
void CAroundTile::Update(void)
{
	//�ړ����̏���
	CMoveTile::Update();

	//�e�N�X�`���̈ʒu
	D3DXVECTOR3 effectPos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z);
	m_Texture->SetPos(effectPos);
}

//******************************
// �ړ���������
//******************************
void CAroundTile::MoveRot(bool bReversal)
{
	//���݈ʒu
	D3DXVECTOR3 pos = GetPos();
	//�ړ���
	D3DXVECTOR3 move = GetMove();

	//���]���Ă��邩
	if (!bReversal)
	{
		//�ړ��ʌv�Z
		move.z += TILE_ONE_SIDE;
	}
	else
	{
		move.z -= TILE_ONE_SIDE;
	}

	//�ړ��ʃZ�b�g
	SetMove(move);
}

//******************************
// ���͂̃u���b�N�m�F����
//******************************
void CAroundTile::TileCheck(void)
{
	//���݈ʒu
	D3DXVECTOR3 pos = GetPos();

	if (CTile::GetHitTile(D3DXVECTOR3(pos.x , pos.y, pos.z - TILE_ONE_SIDE)) != nullptr)
	{
		//�ړ��������]
		SetReversal(false);
	}
	else
	{
		//�ړ��������]
		SetReversal(true);
	}
}

////////////////////////////////////////////////////
//
//    ���ɓ����^�C���̏���[move_sideways_tile.cpp]
//    Author:�g�c �I�l
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "move_sideways_tile.h"
#include "scene3d.h"
#include "resource_texture.h"

//******************************
// �R���X�g���N�^
//******************************
CSidewaysTile::CSidewaysTile()
{

}

//******************************
// �f�X�g���N�^
//******************************
CSidewaysTile::~CSidewaysTile()
{
}

//******************************
// �N���X����
//******************************
void CSidewaysTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// �������̊m��
	CSidewaysTile *pTile;
	pTile = new CSidewaysTile;

	//NULL�`�F�b�N
	if (pTile != NULL)
	{
		// ������
		pTile->Init();
		// �e�l�̑���E�Z�b�g
		pTile->SetPos(pos);		// �ʒu
		pTile->SetMove(pos);	// �ړ���
		pTile->SetPriority(OBJTYPE_TILE); 	// �I�u�W�F�N�g�^�C�v
	}
}

//******************************
// ����������
//******************************
HRESULT CSidewaysTile::Init(void)
{
	//����������
	CMoveTile::Init();
	//�e�N�X�`���p�|���S��
	m_Texture = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	m_Texture->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_MOVE_TILE));
	m_Texture->SetColor(TILE_DEFAULT_COLOR);
	m_Texture->SetPriority(OBJTYPE_MAP);

	return S_OK;
}

//******************************
// �X�V����
//******************************
void CSidewaysTile::Update(void)
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
void CSidewaysTile::MoveRot(bool bReversal)
{
	//���݈ʒu
	D3DXVECTOR3 pos = GetPos();
	//�ړ���
	D3DXVECTOR3 move = GetMove();
	m_Texture->SetPos(pos);

	//���]���Ă��邩
	if (!bReversal)
	{
		//�ړ��ʌv�Z
		move.x += TILE_ONE_SIDE;
	}
	else
	{
		move.x -= TILE_ONE_SIDE;
	}

	//�ړ��ʃZ�b�g
	SetMove(move);
}

//******************************
// ���͂̃u���b�N�m�F����
//******************************
void CSidewaysTile::TileCheck(void)
{
	//���݈ʒu
	D3DXVECTOR3 pos = GetPos();

	if (CTile::GetHitTile(D3DXVECTOR3(pos.x - TILE_ONE_SIDE, pos.y, pos.z)) != nullptr)
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

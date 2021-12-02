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
		pTile->SetPos(pos);					// �ʒu
		pTile->SetMove(pos);				// �ړ���
		pTile->SetPriority(OBJTYPE_TILE); 	// �I�u�W�F�N�g�^�C�v
	}
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

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

//******************************
// �R���X�g���N�^
//******************************
CAroundTile::CAroundTile()
{

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

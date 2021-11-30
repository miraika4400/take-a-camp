////////////////////////////////////////////////////
//
//    �����^�C���̏���[move_tile.cpp]
//    Author:�g�c �I�l
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "move_tile.h"
#include "game.h"
#include "player.h"
#include "collision.h"

//*****************************
// �}�N����`
//*****************************
#define MOVE_SPEED (20)				// �ړ����I���܂ł̃t���[��
#define MOVE_DIST  (TILE_ONE_SIDE)	// �ړ�����

//******************************
// �R���X�g���N�^
//******************************
CMoveTile::CMoveTile()
{
	m_bReversal = false;
	m_bStep = false;
	m_nMoveCount = 0;
	m_MoveState = MOVE_STATE_NORMAL;
	ZeroMemory(&m_Move, sizeof(m_Move));
}

//******************************
// �f�X�g���N�^
//******************************
CMoveTile::~CMoveTile()
{
}

////******************************
//// �N���X����
////******************************
//void CMoveTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
//{
//	// �������̊m��
//	CMoveTile *pTile;
//	pTile = new CMoveTile;
//	
//	//NULL�`�F�b�N
//	if (pTile != NULL)
//	{
//		// ������
//		pTile->Init();
//
//		// �e�l�̑���E�Z�b�g
//		pTile->m_Move = D3DXVECTOR3(0.0f, 0.0f, -20.0f) + pos;
//		pTile->SetPos(pos);
//		pTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v
//
//	}
//}

//******************************
// �������֐�
//******************************
HRESULT CMoveTile::Init(void)
{

	//�^�C���̏���������
	CTile::Init();
	//�F�̐ݒ�
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	//�ړ������̔���
	HitTile();

	return S_OK;
}

//******************************
// �X�V����
//******************************
void CMoveTile::Update(void)
{
	CTile::Update();
	switch (m_MoveState)
	{
	case MOVE_STATE_NORMAL:
		
		break;
	case MOVE_STATE_MOVE:

		//�ړ�����
		Move();
		//�����蔻��
		HitTile();
		
		break;
	default:
		
		break;
	}
}

//******************************
// �v���C���[�ƃq�b�g���̏���
//******************************
void CMoveTile::HitPlayerAction(CPlayer * pPlayer)
{
	//�ʏ��Ԃ̎�
	if (m_MoveState == MOVE_STATE_NORMAL)
	{
		//�^�C���̃X�e�[�g��ω�
		m_MoveState = MOVE_STATE_MOVE;
	}

	//�v���C���[�̓������~�߂�
	if (pPlayer->GetState() != CPlayer::PLAYER_STATE_STOP
		&&pPlayer->GetState() != CPlayer::PLAYER_STATE_DEATH)
	{
		pPlayer->SetState(CPlayer::PLAYER_STATE_STOP);
	}


	//���݈ʒu
	D3DXVECTOR3 pos = GetPos();


	//�v���C���[���ړ������鏈��
	pPlayer->SetPos(D3DXVECTOR3(pos.x, pPlayer->GetPos().y, pos.z));

}

//******************************
// �^�C���̈ړ�����
//******************************
void CMoveTile::Move(void)
{

	//���݈ʒu
	D3DXVECTOR3 pos = GetPos();
	//�ʒu�v�Z
	pos += (m_Move - pos) / (float)(MOVE_SPEED - m_nMoveCount);
	//�ʒu�ݒ�
	SetPos(pos);

	//�J�E���g�A�b�v
	m_nMoveCount++;

	//�J�E���g�����ɒB������
	if (MOVE_SPEED <= m_nMoveCount)
	{
		// �J�E���g������
		m_nMoveCount = 0;
		// ���]���Ă��邩
		MoveRot(m_bReversal);
	}
}

//******************************
// ���̃^�C���Ƃ̓����蔻��
//******************************
void CMoveTile::HitTile(void)
{
	//���݈ʒu
	D3DXVECTOR3 Hitpos = D3DXVECTOR3((m_Move.x), GetPos().y, (m_Move.z));
	//���X�g�̃g�b�v�擾
	CTile * pTile = CTile::GetHitTile(Hitpos);
	
	//NULL�`�F�b�N
	if (pTile != NULL
		&&pTile != this)
	{
		//�ړ��������]
		if (!m_bReversal)m_bReversal = true;
		else m_bReversal = false;
		// ���]���Ă��邩
		MoveRot(m_bReversal);
		//�X�e�[�g��ʏ��ԂɕύX
		m_MoveState = MOVE_STATE_NORMAL;
	}
}


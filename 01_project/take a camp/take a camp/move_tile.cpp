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

//******************************
// �������֐�
//******************************
HRESULT CMoveTile::Init(void)
{
	//�^�C���̏���������
	CTile::Init();
	//�F�̐ݒ�
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	m_MoveState = MOVE_STATE_NORMAL;

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
	case MOVE_STATE_STOP:
		//�v���C���[�����炩�̍U���Ŏ���ł��鎞
		if (!GetHitPlayerFlag())
		{
			//�^�C���̃X�e�[�g��ω�
			m_MoveState = MOVE_STATE_REVERSE;
		}
		break;
	case MOVE_STATE_REVERSE:
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
	switch (m_MoveState)
	{

	case MOVE_STATE_NORMAL:
		//�^�C���̃X�e�[�g��ω�
		m_MoveState = MOVE_STATE_MOVE;
		TileCheck();
		//�^�C���ɏ��Ȃ��Ȃ�t���O�𗧂Ă�
		SetRide(true);
		break;
	case MOVE_STATE_MOVE:
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
		//�v���C���[���X�g�b�v��Ԃ̎�
		else if (pPlayer->GetState() == CPlayer::PLAYER_STATE_STOP)
		{
			//���݈ʒu
			D3DXVECTOR3 pos = GetPos();
			//�v���C���[�̖��G�m�F
			if (!pPlayer->GetInvincible())
			{
				//���G�ɂ���
				pPlayer->SetInvincible(true);
			}
			//�v���C���[���ړ������鏈��
			pPlayer->SetPos(D3DXVECTOR3(pos.x, pPlayer->GetPos().y, pos.z));
		}
		break;

	case MOVE_STATE_STOP:
		//�v���C���[�̃X�e�[�g���~��ԂɕύX
		pPlayer->SetState(CPlayer::PLAYER_STATE_NORMAL);

		//�v���C���[�̖��G������
		pPlayer->SetInvincible(false);
		break;
	case MOVE_STATE_REVERSE:
	
		break;
	default:
		//�^�C���̃X�e�[�g��ω�
		m_MoveState = MOVE_STATE_NORMAL;
		break;

	}
}

//******************************
// �v���C���[���~�肽����
//******************************
void CMoveTile::HitPlayerActionRelease(CPlayer*pPlayer)
{
	if (m_MoveState == MOVE_STATE_STOP)
	{
		//�^�C���̃X�e�[�g��ω�
		//m_MoveState = MOVE_STATE_NORMAL;
		m_MoveState = MOVE_STATE_REVERSE;
	}
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
	//�^�C���|�C���^�擾
	CTile * pTile = CTile::GetHitTile(Hitpos);
	
	//NULL�`�F�b�N
	if (pTile != NULL
		&&pTile != (CTile*)this)
	{
		//�ړ��������]
		if (!m_bReversal)m_bReversal = true;
		else m_bReversal = false;
		// ���]���Ă��邩
		MoveRot(m_bReversal);
		//�X�e�[�g��ʏ��ԂɕύX
		if (m_MoveState == MOVE_STATE_MOVE)
		{
			m_MoveState = MOVE_STATE_STOP;
		}
		else if (m_MoveState == MOVE_STATE_REVERSE)
		{
			m_MoveState = MOVE_STATE_NORMAL;

			//�^�C���ɏ���t���O�𗧂Ă�
			SetRide(false);

		}
	}
}


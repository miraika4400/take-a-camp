////////////////////////////////////////////////////
//
//    player�N���X�̏���[player.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "player.h"
#include "manager.h"
#include "keyboard.h"
#include "joypad.h"
#include "collision.h"
#include "debug_log.h"
#include "act_range.h"
#include "tile.h"
#include "bullet.h"

//*****************************
// �}�N����`
//*****************************
#define MOVE_DIST (TILE_ONE_SIDE)	// �ړ�����
#define MOVE_FRAME 8				// �ړ����x
#define COLLISION_RADIUS 20.0f
#define MODEL_SIZE D3DXVECTOR3( 1.0f, 1.0f, 1.0f)
#define ROTDEST_PREVIOUS 270.0f		// �O������
#define ROTDEST_AFTER 90.0f			// �������
#define ROTDEST_LEFT 180.0f			// ������
#define ROTDEST_RIGHT 0.0f			// �E����
#define ROT_SPEED 0.3f				// ��]���x
#define ROT_FACING_01 180			// ��]�̊
#define ROT_FACING_02 360			// ��]����

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CPlayer::m_anControllKey[5][CPlayer::KEY_MAX] =
{
	{ DIK_W,DIK_S,DIK_A,DIK_D,DIK_E },
	{ DIK_UP,DIK_DOWN,DIK_LEFT,DIK_RIGHT,DIK_NUMPAD1 },
	{ DIK_U,DIK_J,DIK_H,DIK_K,DIK_I },
	{ DIK_NUMPAD8,DIK_NUMPAD5,DIK_NUMPAD4,DIK_NUMPAD6,DIK_NUMPAD9 }
};

//******************************
// �R���X�g���N�^
//******************************
CPlayer::CPlayer() :CModel(OBJTYPE_PLAYER)
{
	m_nPlayerNumber = 0;
	m_bMove = false;
	m_pCollison = NULL;
	m_nColor = 0;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	m_MoveCoutn = 0;

}

//******************************
// �f�X�g���N�^
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// �N���X����
//******************************
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber)
{
	// �������̊m��
	CPlayer *pPlayer;
	pPlayer = new CPlayer;

	// init�Ŏg�������ɑ��
	pPlayer->m_nPlayerNumber = nPlayerNumber;

	// ������
	pPlayer->Init();

	// �e�l�̑���E�Z�b�g
	pPlayer->SetPos(pos);
	pPlayer->SetRot(rot);
	pPlayer->SetPriority(OBJTYPE_PLAYER); // �I�u�W�F�N�g�^�C�v
	pPlayer->m_Move = pos;

	//�ړ��͈̓N���X�̐���
	pPlayer->m_pActRange = CActRange::Create(pPlayer);

	return pPlayer;
}

//******************************
// ����������
//******************************
HRESULT CPlayer::Init(void)
{
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// ���f�����蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_PLAYER01));

	// �ړ��t���O�̏�����
	m_bMove = true;

	m_nColor = m_nPlayerNumber;

	// ���f���̃T�C�Y�̐ݒ�
	SetSize(MODEL_SIZE);

	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);

	return S_OK;
}

//******************************
// �I������
//******************************
void CPlayer::Uninit(void)
{
	CModel::Uninit();
}

//******************************
// �X�V����
//******************************
void CPlayer::Update(void)
{
	// �ړ�����
	Move();
	// �����蔻��̈ʒu
	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS/2);
	}
	else
	{
		m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
	}

	// �e�̏���
	Bullet();

	// �����̎擾
	D3DXVECTOR3 rot = GetRot();

	while (m_rotDest.y - rot.y > D3DXToRadian(ROT_FACING_01))
	{
		m_rotDest.y -= D3DXToRadian(ROT_FACING_02);
	}

	while (m_rotDest.y - rot.y < D3DXToRadian(-ROT_FACING_01))
	{
		m_rotDest.y += D3DXToRadian(ROT_FACING_02);
	}

	// �ڕW�̌����ɕς���
	rot += (m_rotDest - rot)*ROT_SPEED;

	// �����ݒ�
	SetRot(rot);

	// 
#ifdef _DEBUG
	// �L�[�{�[�h�̎擾
	if (m_nPlayerNumber == 0)
	{
		CInputKeyboard * pKey = CManager::GetKeyboard();

		/*if (pKey->GetKeyPress(DIK_NUMPAD1))
		{
			m_nColor = 0;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD2))
		{
			m_nColor = 1;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD3))
		{
			m_nColor = 2;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD4))
		{
			m_nColor = 3;
		}
		}*/
	}

#endif // _DEBUG

}

//******************************
// �`�揈��
//******************************
void CPlayer::Draw(void)
{
	CModel::Draw();
}

//******************************
// �ړ�����
//******************************
void CPlayer::Move(void)
{
	if (m_bMove)
	{
		// �L�[�{�[�h�̎擾
		CInputKeyboard * pKey = CManager::GetKeyboard();

		if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_PROGRESS])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// �O�i
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, -1);

			m_rotDest.y= D3DXToRadian(ROTDEST_PREVIOUS);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RECESSION])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// ���
			m_Move.z += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, 1);

			m_rotDest.y = D3DXToRadian(ROTDEST_AFTER);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_LEFT])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// ��
			m_Move.x += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(-1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_LEFT);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RIGHT])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_RIGHT))
		{// �E
			m_Move.x -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_RIGHT);
		}
	}
	else
	{
		// ���W�̎擾
		D3DXVECTOR3 pos = GetPos();

		//�ړ��v�Z
		pos += (m_Move - pos) / (float)(MOVE_FRAME - m_MoveCoutn);

		//�ʒu�ݒ�
		SetPos(pos);

		//�J�E���g�A�b�v
		m_MoveCoutn++;

		//�J�E���g�����ɒB����
		if (m_MoveCoutn >= MOVE_FRAME)
		{
			//�J�E���g������
			m_MoveCoutn = 0;
			//�ړ��ł���悤��
			m_bMove = true;
		}
	}
}

//******************************
// �e�̏���
//******************************
void CPlayer::Bullet(void)
{
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CPlayer *pPlayer;

	// ���W�̎擾
	D3DXVECTOR3 pos = GetPos();

	// �X�y�[�X�{�^������������
	if (pKey->GetKeyTrigger(m_anControllKey[m_nPlayerNumber][KEY_BULLET]))
	{
		CBullet::Create(D3DXVECTOR3(pos.x, pos.y, pos.z));
	}

	//�ʒu�ݒ�
	SetPos(pos);
}
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

//*****************************
// �}�N����`
//*****************************
#define MOVE_DIST (TILE_ONE_SIDE)	// �ړ�����
#define MOVE_FRAME 5				// �ړ����x
#define COLLISION_RADIUS 20.0f

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CPlayer::CPlayer() :CModel(OBJTYPE_PLAYER)
{
	m_nPlayerNumber = 0;
	m_bMove = false;
	m_pCollison = NULL;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	m_MoveCoutn = 0;
	///////////////////////////////////////////////
	//��
	m_color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	///////////////////////////////////////////////
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
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, int nPlayerNumber)
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
	pPlayer->SetPriority(OBJTYPE_PLAYER); // �I�u�W�F�N�g�^�C�v

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

	//�ړ��͈̓N���X�̐���
	m_pActRange = CActRange::Create(this);

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
	m_pActRange->PlayerPos();
	// �����蔻��̈ʒu
	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS/2);
	}
	else
	{
		m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
	}

	// 
#ifdef _DEBUG
	// �L�[�{�[�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();

	if (pKey->GetKeyPress(DIK_NUMPAD1))
	{
		m_color = D3DXCOLOR(0.8f, 0.8f, 1.0f, 1.0f);
	}
	if (pKey->GetKeyPress(DIK_NUMPAD2))
	{
		m_color = D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f);
	}
	if (pKey->GetKeyPress(DIK_NUMPAD3))
	{
		m_color = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (pKey->GetKeyPress(DIK_NUMPAD4))
	{
		m_color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
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

		if (pKey->GetKeyPress(DIK_W)
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// �O�i
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
		}
		else if (pKey->GetKeyPress(DIK_S)
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// ���
			m_Move.z += MOVE_DIST;
			m_bMove = false;
		}
		else if (pKey->GetKeyPress(DIK_A)
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// ��
			m_Move.x += MOVE_DIST;
			m_bMove = false;
		}
		else if (pKey->GetKeyPress(DIK_D) 
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_RIGHT))
		{// �E
			m_Move.x -= MOVE_DIST;
			m_bMove = false;
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
		if (m_MoveCoutn>=MOVE_FRAME)
		{
			//�J�E���g������
			m_MoveCoutn = 0;
			//�ړ��ł���悤��
			m_bMove = true;
		}
	}
}

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

//*****************************
// �}�N����`
//*****************************
#define MOVE_SPEED 3 

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
}

//******************************
// �f�X�g���N�^
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// �N���G�C�g(��)
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
		// ���W�̎擾
		D3DXVECTOR3 pos = GetPos();

		// �L�[�{�[�h�̎擾
		CInputKeyboard * pKey = CManager::GetKeyboard();

		if (pKey->GetKeyPress(DIK_W))
		{// �O�i
			pos.z -= MOVE_SPEED;
		}
		if (pKey->GetKeyPress(DIK_S))
		{// ���
			pos.z += MOVE_SPEED;
		}
		if (pKey->GetKeyPress(DIK_A))
		{// ��
			pos.x += MOVE_SPEED;
		}
		if (pKey->GetKeyPress(DIK_D))
		{// �E
			pos.x -= MOVE_SPEED;
		}

		SetPos(pos);
	}
}

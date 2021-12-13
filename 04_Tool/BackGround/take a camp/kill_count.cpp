////////////////////////////////////////////////////
//
//    �L���J�E���g[kill_count.cpp]
//    Author : �g�c �I�l
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "kill_count.h"
#include "number.h"
#include "player.h"

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CKillCount::m_nTotalKill[MAX_PLAYER] = {};

//=============================
// �R���X�g���N�^
//=============================
CKillCount::CKillCount()
{
	memset(&pNumber,0,sizeof(pNumber));
	memset(&m_nKillCount, 0, sizeof(m_nKillCount));
	m_nKillCount = 0;

}

//=============================
// �f�X�g���N�^
//=============================
CKillCount::~CKillCount()
{
}

//=============================
// �N���G�C�g
//=============================
CKillCount * CKillCount::Create(int nPlayer)
{
	// �������̊m��
	CKillCount *pKillCount = NULL;
	pKillCount = new CKillCount;
	
	//NULL�`�F�b�N
	if (pKillCount != NULL)
	{
		//�v���C���[�ԍ��擾
		pKillCount->SetPlayer(nPlayer);
		// ������
		pKillCount->Init();
	}
	return pKillCount;
}

//=============================
// ����������
//=============================
HRESULT CKillCount::Init(void)
{
	m_nKillCount = 0;

	return S_OK;
}

//=============================
// �I������
//=============================
void CKillCount::Uninit(void)
{
	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CKillCount::Update(void)
{

}

//=============================
// �`�揈��
//=============================
void CKillCount::Draw(void)
{

}

//=============================
// �L�������Z����
//=============================
void CKillCount::AddKill(void)
{
	m_nKillCount++;
}

//=============================
// �L�������Z����
//=============================
void CKillCount::AddTotalKill(void)
{
	//���l�̏�����
	ZeroMemory(&m_nTotalKill,sizeof(m_nTotalKill));
	
	//���X�g�擾
	CPlayer* pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	//NULL�`�F�b�N
	while (pPlayer != NULL)
	{
		//�J�E���g�̃|�C���^�擾
		CKillCount *pKillCount = pPlayer->GetKillCount();
		
		if (pKillCount != NULL)
		{
			m_nTotalKill[pKillCount->GetPlayer()] = pKillCount->GetKill();
		}
		// ���X�g��i�߂�
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

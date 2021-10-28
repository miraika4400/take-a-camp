//=============================================================================
//
// �h�菈�� [peint_collision.cpp]
// Author : �g�c �I�l
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "peint_collision.h"
#include "collision.h"
#include "player.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPeintCollision::CPeintCollision()
{
	m_nPlayerNum	= 0;
	m_nColorNumber  = 0;
	m_bDeath		= false;
	m_pCollision	= NULL;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPeintCollision::~CPeintCollision()
{
}

//=============================================================================
// ��������
//=============================================================================
CPeintCollision * CPeintCollision::Create(D3DXVECTOR3 pos, int nPlayerNum)
{
	//�������m��
	CPeintCollision * pPeintCollision = NULL;
	pPeintCollision = new CPeintCollision;

	//NULL�`�F�b�N
	if (pPeintCollision != NULL)
	{
		//����������
		pPeintCollision->Init();
		//�ʒu�ݒ�
		pPeintCollision->SetPos(pos);
		//�T�C�Y�ݒ�
		pPeintCollision->SetSize(D3DXVECTOR3(0.5f, 0.5f, 0.5f));
		//�v���C���[�i���o�[�擾
		pPeintCollision->m_nPlayerNum = nPlayerNum;
		//�J���[�ԍ��擾(�i���o�[���擾��ɂ���)
		pPeintCollision->ColorLoad();

		// �I�u�W�F�N�g�^�C�v
		pPeintCollision->SetPriority(OBJTYPE_PEINT);
	}
	return pPeintCollision;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPeintCollision::Init(void)
{	
	// ����������
	CModel::Init();

	// ���f�����蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_BULLET01));

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CPeintCollision::Uninit(void)
{
	if (m_pCollision != NULL)
	{
		m_pCollision->ReConnection();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}
	// �I������
	CModel::Uninit();

}

//=============================================================================
// �X�V����
//=============================================================================
void CPeintCollision::Update(void)
{
	// �ʒu�̎擾
	D3DXVECTOR3 Pos = GetPos();

	if (m_pCollision == NULL)
	{
		m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(Pos.x, Pos.y + 20.0f / 2, Pos.z), 10 / 2);
	}
	else
	{
		m_pCollision->SetPos(D3DXVECTOR3(Pos.x, Pos.y + 20.0f / 2, Pos.z));
	}

	//���S�t���O
	if (m_bDeath)
	{
		Uninit();
	}

}

//=============================================================================
// �`�揈��
//=============================================================================
void CPeintCollision::Draw(void)
{
	// �`�揈��
	CModel::Draw();
}

//=============================================================================
// �J���[�ԍ��ǂݍ���
//=============================================================================
void CPeintCollision::ColorLoad(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (m_nPlayerNum == pPlayer->GetPlayerNumber())
		{
			//�v���C���[�̃J���[�擾
			m_nColorNumber = pPlayer->GetColorNumber();
			return;
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//=============================================================================
// ���S�t���O�I��
//=============================================================================
void CPeintCollision::Death()
{
	m_bDeath = true;
}


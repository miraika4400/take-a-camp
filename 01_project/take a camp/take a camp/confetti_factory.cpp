////////////////////////////////////////////////////
//
//    ������t�@�N�g���[�N���X�̏���[confetti_factory.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "confetti_factory.h"
#include "confetti.h"

//**********************************
// �}�N����`
//**********************************
#define CONFETTI_INTERVAL (2)

//=============================
// �R���X�g���N�^
//=============================
CConfettiFactory::CConfettiFactory() : CScene(OBJTYPE_SYSTEM)
{
	m_nTile = 0;
	m_nCntConfetti = 0;
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

//=============================
// �f�X�g���N�^
//=============================
CConfettiFactory::~CConfettiFactory()
{
}

//=============================
// �N���G�C�g
//=============================
CConfettiFactory * CConfettiFactory::Create(D3DXCOLOR col, int nLife)
{
	// �������̊m��
	CConfettiFactory *pConfettiFactory = new CConfettiFactory;
	// ������
	pConfettiFactory->Init();
	pConfettiFactory->m_nTile = nLife;
	pConfettiFactory->m_col = col;

	return pConfettiFactory;
}

//=============================
// ����������
//=============================
HRESULT CConfettiFactory::Init(void)
{
	
	m_nCntConfetti = 0;
	return S_OK;
}

//=============================
// �I������
//=============================
void CConfettiFactory::Uninit(void)
{
	// �J������
	Release();
}


//=============================
// �X�V����
//=============================
void CConfettiFactory::Update(void)
{
	m_nCntConfetti++;

	if (m_nCntConfetti % CONFETTI_INTERVAL == 0)
	{
		CConfetti::Create(D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f), m_col, D3DXToRadian(-60));
		CConfetti::Create(D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f), m_col, D3DXToRadian(-60 - 60));
	}

	if (m_nTile >= 0)
	{
		m_nTile--;
		if (m_nTile < 0)
		{
			Uninit();
		}
	}
}

//=============================
// �`�揈��
//=============================
void CConfettiFactory::Draw(void)
{
}
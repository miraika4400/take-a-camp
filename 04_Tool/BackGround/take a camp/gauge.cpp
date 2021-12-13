//===================================================
//
//    �Q�[�W�N���X�̏���[gage.cpp]
//    Author:���V ����
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "gauge.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "player.h"
#include "game.h"

//**********************************
// �}�N����`
//**********************************

//**********************************
// �ÓI�����o�ϐ��錾
//**********************************

//==================================
// �R���X�g���N�^
//==================================
CGauge::CGauge() :CScene(OBJTYPE_UI)
{
	// �ϐ��̃N���A
	m_pPolygon = NULL;
	m_fBarWidht = 0.0f;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pfData = NULL;
	m_frontCol = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
}

//==================================
// �f�X�g���N�^
//==================================
CGauge::~CGauge()
{
}

//==================================
// �N���G�C�g
//==================================
CGauge * CGauge::Create(float * pData, D3DXVECTOR3 leftPos, float fBarWidht, float fBarHeight, float fMaxNum, D3DXCOLOR frontCol)
{
	// �������̊m��
	CGauge *pGage;
	pGage = new CGauge;

	// �����̑��
	pGage->m_pos = leftPos;             // ���[
	pGage->m_fBarWidht = fBarWidht;     // ��
	pGage->m_fBarHeight = fBarHeight;   // ����
	pGage->m_fMaxNum = fMaxNum;         // �ő吔
	pGage->m_pfData = pData;            // �Q�[�W�ƕR�Â��鐔�l�̃|�C���^
	pGage->m_frontCol = frontCol;       // �t�����g�J���[

	// ������
	pGage->Init();
	// �I�u�W�F�N�g�^�C�v�̐ݒ�
	pGage->SetPriority(OBJTYPE_UI);

	return pGage;
}

//==================================
// ����������
//==================================
HRESULT CGauge::Init(void)
{

	// �|���S���̐���
	m_pPolygon = CPolygon::Create(
		m_pos,
		D3DXVECTOR3(m_fBarWidht, 0.0f, 0.0f),
		m_frontCol);

	// ���_���W�̐ݒ�
	D3DXVECTOR3 vtxPos[NUM_VERTEX];

	vtxPos[0] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y - *m_pfData, 0.0f);
	vtxPos[1] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y - *m_pfData, 0.0f);
	vtxPos[2] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y            , 0.0f);
	vtxPos[3] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y            , 0.0f);

	m_pPolygon->SetVertexPos(vtxPos);

	return S_OK;
}

//==================================
// �I������
//==================================
void CGauge::Uninit(void)
{
	// ���C�t�̍ő吔���|���S���̏I������
	if (m_pPolygon != NULL)
	{
		// �I������
		m_pPolygon->Uninit();
		// �������̉��
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	// �J������
	Release();
}

//==================================
// �X�V����
//==================================
void CGauge::Update(void)
{
	// ���̌v�Z
	float fHeight = 0.0f;
	// ���̌v�Z
	fHeight = m_fBarHeight * *m_pfData / m_fMaxNum;

	// ���_���W�̐ݒ�
	D3DXVECTOR3 vtxPos[NUM_VERTEX];

	vtxPos[0] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y - fHeight, 0.0f);
	vtxPos[1] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y - fHeight, 0.0f);
	vtxPos[2] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y          , 0.0f);
	vtxPos[3] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y          , 0.0f);

	m_pPolygon->SetVertexPos(vtxPos);

	// �|���S���̍ő吔���X�V����
	if (m_pPolygon != NULL)
	{
		m_pPolygon->Update();
	}
}

//==================================
// �`�揈��
//==================================
void CGauge::Draw(void)
{
	// �O�p�[�c���`��
	if (m_pPolygon != NULL)
	{
		m_pPolygon->Draw();
	}
}
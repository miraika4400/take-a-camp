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
CGauge::CGauge() :CScene(OBJTYPE_UI_2)
{
	// �ϐ��̃N���A
	m_pPolygon = NULL;
	m_fBarWidht = 0.0f;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fValue = 0.0f;
	m_frontCol = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	m_mode = MODE_VALUE_AUTO;
	m_fHeightDist = 0.0f;
	m_fHeight = 0.0f;
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
CGauge * CGauge::Create( D3DXVECTOR3 leftPos, float fBarWidht, float fBarHeight, float fMaxNum, D3DXCOLOR frontCol)
{
	// �������̊m��
	CGauge *pGage;
	pGage = new CGauge;

	// �����̑��
	pGage->m_pos = leftPos;             // ���[
	pGage->m_fBarWidht = fBarWidht;     // ��
	pGage->m_fBarHeight = fBarHeight;   // ����
	pGage->m_fMaxNum = fMaxNum;         // �ő吔
	pGage->m_frontCol = frontCol;       // �t�����g�J���[

	// ������
	pGage->Init();
	// �I�u�W�F�N�g�^�C�v�̐ݒ�
	pGage->SetPriority(OBJTYPE_UI_2);

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

	// �l�̏�����
	m_fValue = 0.0f;
	m_fValueDist = 0.0f;
	m_fGaugeRate = DEFAULT_GAUGE_RATE;
	m_mode = MODE_VALUE_AUTO;
	m_fHeightDist = 0.0f;
	m_fHeight = 0.0f;

	// ���_���W�̐ݒ�
	D3DXVECTOR3 vtxPos[NUM_VERTEX];

	vtxPos[0] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y - m_fHeight, 0.0f);
	vtxPos[1] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y - m_fHeight, 0.0f);
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
	// �Q�[�W�����̌v�Z
	UpdateValue();

	// ���_���W�̐ݒ�
	D3DXVECTOR3 vtxPos[NUM_VERTEX];

	vtxPos[0] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y - m_fHeight, 0.0f);
	vtxPos[1] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y - m_fHeight, 0.0f);
	vtxPos[2] = D3DXVECTOR3(m_pos.x - m_fBarWidht / 2.0f, m_pos.y          , 0.0f);
	vtxPos[3] = D3DXVECTOR3(m_pos.x + m_fBarWidht / 2.0f, m_pos.y          , 0.0f);

	m_pPolygon->SetVertexPos(vtxPos);

	// �|���S���̍X�V����
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

//==================================
// ���[�h�̃Z�b�g
//==================================
void CGauge::SetMode(MODE mode)
{
	if (m_mode == mode) return;

	switch (m_mode)
	{
	case CGauge::MODE_VALUE_AUTO:

		if (mode == MODE_HEIGHT_AUTO)
		{
			// �ő�l����̊���
			m_fHeight = m_fBarHeight*(m_fValue / m_fMaxNum);
		}
		break;
	case CGauge::MODE_HEIGHT_AUTO:

		if (mode == MODE_VALUE_AUTO)
		{
			// �ő�l����̊���
			m_fValue = m_fMaxNum*(m_fHeight / m_fBarHeight);
		}
		break;
	default:
		break;
	}

	m_mode = mode;
}

//==================================
// �Q�[�W�����̌v�Z
//==================================
void CGauge::UpdateValue(void)
{
	switch (m_mode)
	{
	case CGauge::MODE_VALUE_AUTO:
		m_fValue += (m_fValueDist - m_fValue)*m_fGaugeRate;
	case CGauge::MODE_VALUE_SELF:
		// ���̌v�Z
		m_fHeight = m_fBarHeight * (m_fValue) / m_fMaxNum;
	break;

	case CGauge::MODE_HEIGHT_AUTO:
		m_fHeight += (m_fHeightDist - m_fHeight)*m_fGaugeRate;
		break;
	default:
		break;
	}
}

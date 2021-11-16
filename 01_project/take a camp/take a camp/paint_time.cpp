////////////////////////////////////////////////////
//
//    �h���ԃN���X�̏���[paint_time.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "paint_time.h"
#include "scene3d.h"
#include "tile.h"
#include "resource_texture.h"

//******************************
// �}�N����`
//******************************
#define COLOR D3DXCOLOR(0.8f,0.8f,0.8f,m_fAlpha)
#define ALPHA_RATE 0.1f

//******************************
// �R���X�g���N�^
//******************************
CPaintTime::CPaintTime():CScene(OBJTYPE_EFFECT)
{
	m_bDraw = false;
	m_nCntFrame = 0;
	m_nFrame = 0;
	m_fAlpha = 0.0f;
}

//******************************
// �f�X�g���N�^
//******************************
CPaintTime::~CPaintTime()
{
}

//******************************
// �N���X����
//******************************
CPaintTime * CPaintTime::Create(void)
{
	// �N���X����
	CPaintTime * pInstace = new CPaintTime;

	// ����������
	pInstace->Init();

	return pInstace;
}

//******************************
// ����������
//******************************
HRESULT CPaintTime::Init(void)
{
	// ������
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		m_apPolygon[nCntPolygon] = CScene3d::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(TILE_ONE_SIDE-5.0f, 0.0, TILE_ONE_SIDE - 5.0f));
		m_apPolygon[nCntPolygon]->SetColor(COLOR);
		m_apPolygon[nCntPolygon]->ReConnection();
	}

	// �e�N�X�`���̊��蓖��
	m_apPolygon[PARTS_FRAME]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CLOCK_FRAME));
	m_apPolygon[PARTS_HANDS]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CLOCK_HANDS));

	// �J�E���g�̏�����
	m_nCntFrame = 0;
	m_nFrame = 0;
	m_bDraw = false;
	m_fAlpha = 0.0f;

	return S_OK;
}

//******************************
// �I������
//******************************
void CPaintTime::Uninit(void)
{
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->Uninit();
			delete m_apPolygon[nCntPolygon];
			m_apPolygon[nCntPolygon] = NULL;
		}
	}

	Release();
}

//******************************
// �X�V����
//******************************
void CPaintTime::Update(void)
{
	if (m_bDraw)
	{
		m_nCntFrame++;
		// �j����
		float fRotY = D3DXToRadian(((float)m_nCntFrame / (float)m_nFrame)*360.0f);
		m_apPolygon[PARTS_HANDS]->SetRot(D3DXVECTOR3(0.0f, fRotY, 0.0f));

		if (m_nCntFrame > m_nFrame)
		{
			m_bDraw = false;
		}
	}
	else
	{
		m_fAlpha += (0.0f - m_fAlpha)*ALPHA_RATE;
	}

	// �J���[�̐ݒ�
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		m_apPolygon[nCntPolygon]->SetColor(COLOR);
	}
}

//******************************
// �`�揈��
//******************************
void CPaintTime::Draw(void)
{
	// �`��
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->Draw();
		}
	}
}

//******************************
// ���W�̃Z�b�g
//******************************
void CPaintTime::SetPos(D3DXVECTOR3 pos)
{
	// �`��
	for (int nCntPolygon = 0; nCntPolygon < PAINT_TIME_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->SetPos(pos);
		}
	}
}

//******************************
// �Z�b�g
//******************************
void CPaintTime::SetPaintTime(int nFrame)
{
	m_bDraw = true;
	m_apPolygon[PARTS_HANDS]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_nCntFrame = 0;
	m_nFrame = nFrame;
	m_fAlpha = 1.0f;
}

//******************************
// �`��t���O�̃Z�b�g
//******************************
void CPaintTime::SetDrawFlag(bool bFlag)
{
	m_bDraw = bFlag;

	if (!m_bDraw)
	{
		m_fAlpha = 0.0f;
	}
}

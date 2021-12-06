//=============================================================================
//
// �Q�[���J�n�̏��� [game_start.h]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "game_start.h"
#include "polygon.h"
#include "resource_texture.h"
#include "game.h"

//=============================================================================
// �}�N����`
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGame_Start::CGame_Start()
{
	m_pPolygon = NULL;
	m_pos = VEC3_ZERO;
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_nCount = 0;
	m_bStart = false;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGame_Start::~CGame_Start()
{

}

//=============================================================================
// ��������
//=============================================================================
CGame_Start * CGame_Start::Create(D3DXVECTOR3 pos , D3DXVECTOR3 size,TYPE_START type)
{
	CGame_Start *pStart = NULL;

	// �������̊m��
	pStart = new CGame_Start;

	// NULL�`�F�b�N
	if (pStart != NULL)
	{
		// �ʒu�ݒ�
		pStart->m_pos = pos;
		// �T�C�Y�ݒ�
		pStart->m_size = size;
		// �^�C�v�ݒ�
		pStart->m_type = type;
		// �����������Ăяo��
		pStart->Init();

		// �I�u�W�F�N�g�^�C�v
		pStart->SetPriority(OBJTYPE_UI);
	}

	return pStart;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CGame_Start::Init(void)
{
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// �|���S���̐���
	m_pPolygon = CPolygon::Create(
		m_pos,
		m_size,
		m_col);

	// ready�Ȃ�
	if (m_type == TYPE_START_READEY)
	{
		m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TITLE));
	}

	// GO�Ȃ�
	if (m_type == TYPE_START_GO)
	{
		m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTYRE_BUTTON_TUTORIAL));
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGame_Start::Uninit(void)
{
	if (m_pPolygon != NULL)
	{
		// �|���S���̏I������
		m_pPolygon->Uninit();

		// �������̉��
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	// �J������
	Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CGame_Start::Update(void)
{
	// �|���S���̍X�V����
	m_pPolygon->Update();

	// ���t���[�����ƂɃJ�E���g�𑝂₵�Ă���
	m_nCount++;

	if (m_type == TYPE_START_READEY)
	{
		// �\��������
		if (m_nCount == 10)
		{
			m_bStart = true;

			m_col.a = 0.0f;
		}
	}

	if (m_bStart == true)
	{
		Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 200.0f, 0.0f), D3DXVECTOR3(750.0f, 200.0f, 0.0f), CGame_Start::TYPE_START_GO);
	}

	if (m_type == TYPE_START_GO)
	{
		// �\��������
		if (m_nCount == 10)
		{
			// �I������
			Uninit();
			return;
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CGame_Start::Draw(void)
{
	// �|���S���̕`�揈��
	m_pPolygon->Draw();
}


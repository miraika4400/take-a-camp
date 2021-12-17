//=============================================================================
//
// �Q�[���J�n�̏��� [game_start.cpp]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "game_start.h"
#include "polygon.h"
#include "resource_texture.h"
#include "player.h"
#include "time.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define SIZE_X		(325.0f)
#define SIZE_Y_UP	(100.0f)
#define SIZE_Y_DOWN (300.0f)
#define COUNT		(60)
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGameStart::CGameStart()
{
	m_pPolygon = NULL;							// �|���S�����
	m_pos = VEC3_ZERO;							// �ʒu���
	m_size = VEC3_ZERO;
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	// �F���
	m_nCount = 0;								// �J�E���^�[
	m_type = START_TYPE_READEY;					// �^�C�v
	m_bStart = false;							// �X�^�[�g�g�p���Ă邩���ĂȂ���
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGameStart::~CGameStart()
{

}

//=============================================================================
// ��������
//=============================================================================
CGameStart * CGameStart::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CGameStart *pStart = NULL;

	// �������̊m��
	pStart = new CGameStart;

	// NULL�`�F�b�N
	if (pStart != NULL)
	{
		// �ʒu�ݒ�
		pStart->m_pos = pos;
		// �T�C�Y�ݒ�
		pStart->m_size = size;
		// �����������Ăяo��
		pStart->Init();

		// �I�u�W�F�N�g�^�C�v
		pStart->SetPriority(OBJTYPE_UI_2);
	}

	return pStart;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CGameStart::Init(void)
{
	// �F�ݒ�
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// �|���S���̐���
	m_pPolygon = CPolygon::Create(
		m_pos,
		m_size,
		m_col);

	// ready�Ȃ�
	if (m_type == START_TYPE_READEY)
	{
		// �e�N�X�`���[�̐ݒ�
		m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_READEY));
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGameStart::Uninit(void)
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
void CGameStart::Update(void)
{
	// �|���S���̍X�V����
	m_pPolygon->Update();

	// ���t���[�����ƂɃJ�E���g�𑝂₵�Ă���
	m_nCount++;

	switch (m_type)
	{
	case START_TYPE_READEY:
		// ready�Ȃ�
		GoChange();
		break;
	case START_TYPE_GO:
		// GO�Ȃ�
		PlayChange();
		break;

	case START_TYPE_PLAY:
		// �v���C��Ԃɂ͂�������
		Uninit();
		return;
		break;
	default:
		break;
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CGameStart::Draw(void)
{
	// �|���S���̕`�揈��
	m_pPolygon->Draw();
}

//=============================================================================
// �摜��傫���ύX����
//=============================================================================
void CGameStart::GoChange(void)
{
	// �J�E���g�����l�ɂȂ�����
	if (m_nCount == COUNT)
	{
		// go��
		m_type = START_TYPE_GO;
		// �e�N�X�`���[�ύX
		m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_GO));

		// ���_���W�̐ݒ�
		D3DXVECTOR3 vtxPos[NUM_VERTEX];

		vtxPos[0] = D3DXVECTOR3(SCREEN_WIDTH / 2.0f - SIZE_X, SIZE_Y_UP, 0.0f);
		vtxPos[1] = D3DXVECTOR3(SCREEN_WIDTH / 2.0f + SIZE_X, SIZE_Y_UP, 0.0f);
		vtxPos[2] = D3DXVECTOR3(SCREEN_WIDTH / 2.0f - SIZE_X, SIZE_Y_DOWN, 0.0f);
		vtxPos[3] = D3DXVECTOR3(SCREEN_WIDTH / 2.0f + SIZE_X, SIZE_Y_DOWN, 0.0f);

		// ���_���W�̐ݒ�
		m_pPolygon->SetVertexPos(vtxPos);

		// �^�C�����g�p��Ԃɂ���
		CTime::Create();

		// �J�E���g�̏�����
		m_nCount = 0;
	}
}

//=============================================================================
// �v���C���[�h�ɏ�ԕύX
//=============================================================================
void CGameStart::PlayChange(void)
{
	// �J�E���g�����l�ɂȂ�����
	if (m_nCount == COUNT)
	{
		// �v���C���[�̏�Ԃ�ʏ��Ԃ�
		StartPlayer();
		// �v���C�^�C�v��
		m_type = START_TYPE_PLAY;
	}
}

//=============================================================================
// �v���C���[��S������悤�ɂ���
//=============================================================================
void CGameStart::StartPlayer(void)
{
	CPlayer*pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		pPlayer->SetUpdateFlag(true);

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

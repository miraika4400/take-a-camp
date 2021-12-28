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
#define SIZE_X		(360.0f)
#define SIZE_Y		(180.0f)
#define COUNT		(60)
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGameStart::CGameStart() :CScene2d(OBJTYPE_UI_2)
{
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
		// �����������Ăяo��
		pStart->Init();
		// �ʒu�ݒ�
		pStart->SetPos(pos);
		// �T�C�Y�ݒ�
		pStart->SetSize(size);

		pStart->SetColor(pStart->m_col);

		// ready�Ȃ�
		if (pStart->m_type == START_TYPE_READEY)
		{
			pStart->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_READEY));
		}
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
	// ����������
	CScene2d::Init();

	// �F�ݒ�
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGameStart::Uninit(void)
{
	// �I������
	CScene2d::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CGameStart::Update(void)
{
	// �X�V����
	CScene2d::Update();

	// �T�C�Y���̎擾
	D3DXVECTOR3 size = GetSize();
	D3DXCOLOR col = GetColor();

	if (m_type == START_TYPE_READEY)
	{
		size.x += -4;
		size.y += 0.25 * -4;

		col.a += -0.01;
	}

	if (m_type == START_TYPE_GO)
	{
		size.x += 6;
		size.y += 0.25 * 6;

		col.a += 0.03;
	}

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
		col.a = 1.0f;
		// �v���C��Ԃɂ͂�������
		if (m_nCount == 100)
		{
			Uninit();
			return;
		}
		break;
	default:
		break;
	}

	// �T�C�Y�ݒ�
	SetSize(size);

	// �J���[�ݒ�
	SetColor(col);
}

//=============================================================================
// �`�揈��
//=============================================================================
void CGameStart::Draw(void)
{
	// �`�揈��
	CScene2d::Draw();
}

//=============================================================================
// �摜��傫���ύX����
//=============================================================================
void CGameStart::GoChange(void)
{
	// �T�C�Y���̎擾
	D3DXVECTOR3 size = GetSize();

	// �J�E���g�����l�ɂȂ�����
	if (size.x <= 0)
	{
		// go��
		m_type = START_TYPE_GO;

		// �e�N�X�`���[�ύX
		BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_GO));

		// �^�C�����g�p��Ԃɂ���
		CTime::Create();

		// �J�E���g�̏�����
		m_nCount = 0;
	}

	// �T�C�Y�ݒ�
	SetSize(size);
}

//=============================================================================
// �v���C���[�h�ɏ�ԕύX
//=============================================================================
void CGameStart::PlayChange(void)
{
	// �T�C�Y���̎擾
	D3DXVECTOR3 size = GetSize();
	D3DXCOLOR col = GetColor();

	// �J�E���g�����l�ɂȂ�����
	if (col.a >= 1.0)
	{
		// �v���C���[�̏�Ԃ�ʏ��Ԃ�
		StartPlayer();

		// �v���C�^�C�v��
		m_type = START_TYPE_PLAY;

		m_nCount = 0;
	}

	// �T�C�Y�ݒ�
	SetSize(size);
	// �J���[�ݒ�
	SetColor(col);
}

//=============================================================================
// �v���C���[�𓮂���悤�ɂ���
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

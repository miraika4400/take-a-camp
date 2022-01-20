////////////////////////////////////////////////////
//
//    �U���͈͉����N���X�̏���[attack_area.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "attack_area.h"
#include "tile.h"
#include "resource_texture.h"

//******************************
// �}�N����`
//******************************
#define POLYGON_SIZE_MAX (D3DXVECTOR3(TILE_ONE_SIDE - 5.0f, 0.0f, TILE_ONE_SIDE - 5.0f))   // �T�C�Y�ő�
#define POLYGON_SIZE_MIN (D3DXVECTOR3(TILE_ONE_SIDE - 15.0f, 0.0f, TILE_ONE_SIDE - 15.0f)) // �T�C�Y�ŏ�
#define SIZE_RATE 0.03f // �T�C�Y�W��
#define ADD_ROT (D3DXVECTOR3( 0.0f, 0.05f, 0.0f)) // ��]��
#define ALPHA_RATE 0.1f

//******************************
// �R���X�g���N�^
//******************************
CAttackArea::CAttackArea()
{
	m_bDraw = false;
	m_bExpansion = false;
}

//******************************
// �f�X�g���N�^
//******************************
CAttackArea::~CAttackArea()
{
}

//******************************
// �N���X����
//******************************
CAttackArea * CAttackArea::Create(void)
{
	// �N���X����
	CAttackArea * pInstace = new CAttackArea;
	// ����������
	pInstace->Init();

	return pInstace;
}

//******************************
// ����������
//******************************
HRESULT CAttackArea::Init(void)
{
	// ������
	CScene3d::Init();

	// �e�N�X�`���̊��蓖��
	BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA));

	// �T�C�Y�̐ݒ�
	SetSize(POLYGON_SIZE_MAX);

	// �`��t���O
	m_bDraw = false;
	// �g��t���O
	m_bExpansion = false;

	// �v���C�I���e�B
	SetPriority(OBJTYPE_EFFECT);

	return S_OK;
}

//******************************
// �X�V����
//******************************
void CAttackArea::Update(void)
{
	SetRot(GetRot() + ADD_ROT);

	// �T�C�Y�̒���
	D3DXVECTOR3 size = GetSize();
	if(m_bExpansion)
	{ 
		size += (POLYGON_SIZE_MAX - size)*SIZE_RATE;

		if (size.x >= POLYGON_SIZE_MAX.x - 2.0f)
		{
			m_bExpansion = false;
		}
	}
	else
	{
		size += (POLYGON_SIZE_MIN - size)*(SIZE_RATE*1.5f);

		if (size.x <= POLYGON_SIZE_MIN.x + 2.0f)
		{
			m_bExpansion = true;
		}
	}
	SetSize(size);

	D3DXCOLOR col = GetColor();
	if (m_bDraw)
	{
		col.a += (1.0f - col.a)*ALPHA_RATE;
	}
	else
	{
		col.a += (0.0f - col.a)*ALPHA_RATE;
	}
	SetColor(col);
}

//******************************
// �`�揈��
//******************************
void CAttackArea::Draw(void)
{
	CScene3d::Draw();
}

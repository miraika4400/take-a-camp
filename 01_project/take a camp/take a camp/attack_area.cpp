////////////////////////////////////////////////////
//
//    �U���͈̓N���X�̏���[attack_area.cpp]
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
#define SIZE (D3DXVECTOR3(TILE_ONE_SIDE -2, 0.0f, TILE_ONE_SIDE - 2))

//******************************
// �R���X�g���N�^
//******************************
CAttackArea::CAttackArea()
{
	m_bDraw = false;
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
CAttackArea * CAttackArea::Create(D3DXVECTOR3 pos)
{
	// �N���X����
	CAttackArea * pInstace = new CAttackArea;
	// ����������
	pInstace->Init();
	// ���W�̐ݒ�
	pInstace->SetPos(pos);

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
	BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_FRAME));

	// �T�C�Y�̐ݒ�
	SetSize(SIZE);

	// �`��t���O
	m_bDraw = false;

	SetPriority(OBJTYPE_EFFECT);
	return S_OK;
}

//******************************
// �`�揈��
//******************************
void CAttackArea::Draw(void)
{
	if (!m_bDraw)
	{
		return;
	}

	CScene3d::Draw();
}

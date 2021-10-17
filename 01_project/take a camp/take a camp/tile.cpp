////////////////////////////////////////////////////
//
//    tile�N���X�̏���[tile.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "tile.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// �}�N����`
//*****************************
#define PEINT_COUNT 60  // �ēx�h���悤�ɂȂ�܂ł̃J�E���g

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CTile::CTile() :CModel(OBJTYPE_TILE)
{                       
	m_color = TILE_DEFAULT_COLOR;
}

//******************************
// �f�X�g���N�^
//******************************
CTile::~CTile()
{
}

//******************************
// �N���X����
//******************************
CTile * CTile::Create(D3DXVECTOR3 pos)
{
	// �������̊m��
	CTile *pTile;
	pTile = new CTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v

	return pTile;
}

//******************************
// ����������
//******************************
HRESULT CTile::Init(void)
{
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// ���f�����蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_GENERAL_BOX));

	// �T�C�Y�̐ݒ�
	SetSize(TILE_SIZE);

	// �F�̐ݒ�
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	return S_OK;
}

//******************************
// �I������
//******************************
void CTile::Uninit(void)
{
	CModel::Uninit();
}

//******************************
// �X�V����
//******************************
void CTile::Update(void)
{
}

//******************************
// �`�揈��
//******************************
void CTile::Draw(void)
{
	/////////////////////////////�@
	//��
	// �F�̐ݒ�
	D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
	mat->MatD3D.Ambient = m_color;
	mat->MatD3D.Diffuse = m_color;
	mat->MatD3D.Specular = m_color;
	mat->MatD3D.Emissive = m_color;

	////////////////////////////
	
	CModel::Draw();
}
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
#include "collision.h"
#include "player.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// �}�N����`
//*****************************

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CTile::CTile() :CModel(OBJTYPE_TILE)
{
	m_pCollison = NULL;
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
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

	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y+ TILE_ONE_SIDE/2, GetPos().z), TILE_ONE_SIDE/2);
	}
	else
	{

	}

	// �v���C���[�Ƃ̓����蔻��
	CollisionPlayer();

#ifdef _DEBUG
	// �f�o�b�O�L�[

	// �L�[�{�[�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();

	if (pKey->GetKeyPress(DIK_NUMPADENTER))
	{// �O�i
		m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
#endif // _DEBUG
}

//******************************
// �`�揈��
//******************************
void CTile::Draw(void)
{
	/////////////////////////////
	//��;
	// �F�̐ݒ�
	D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
	mat->MatD3D.Ambient = m_color;
	mat->MatD3D.Diffuse = m_color;
	mat->MatD3D.Specular = m_color;
	mat->MatD3D.Emissive = m_color;

	////////////////////////////
	
	CModel::Draw();
}

//******************************
// �v���C���[�Ƃ̓����蔻��
//******************************
void CTile::CollisionPlayer(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (CCollision::CollisionSphere(m_pCollison, pPlayer->GetCollision()))
		{
			m_color = pPlayer->GetColor();
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

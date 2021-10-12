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
#include "color_manager.h"
#include "scene3d.h"
#include "resource_texture.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// �}�N����`
//*****************************
#define DEFAULT_COLOR D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)
#define PEINT_COUNT 60  // �ēx�h���悤�ɂȂ�܂ł̃J�E���g

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CTile::CTile() :CModel(OBJTYPE_TILE)
{
	m_pCollison = NULL;                          
	m_color = DEFAULT_COLOR;
	m_nPrevNum = -1;                             // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	m_nStep = 0;                                 // ���̓h�i�K
	m_nCntStep = 0;                              // �ēx�h��\�J�E���g
	m_nLastHitPlayerNum = -1;
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

	// �A�C�R��
	m_pIcon = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE, 0.0f, TILE_ONE_SIDE));
	m_pIcon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CROSS_MARK));
	m_pIcon->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pIcon->SetPriority(OBJTYPE_UI);

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


	// �v���C���[�Ƃ̓����蔻��
	CollisionPlayer();
	
	// �A�C�R���̊Ǘ�
	ManageIcon();

	if (m_nCntStep > 0)
	{
		m_nCntStep--;
	}
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
			Peint(pPlayer->GetColorNumber(), pPlayer->GetPlayerNumber());
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//******************************
// �A�C�R���̊Ǘ�
//******************************
void CTile::ManageIcon(void)
{
	// �ʒu�̒���
	D3DXVECTOR3 pos = m_pIcon->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) +1.0f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 1.0f, GetPos().z);

		m_pIcon->SetPos(pos);
	}
}

//******************************
// �h����
//******************************
void CTile::Peint(int nColorNumber , int nPlayerNum)
{
	if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum )
	{
		m_nLastHitPlayerNum = nPlayerNum;

		if (m_nPrevNum == -1)
		{// �������h���Ă��Ȃ�
			m_nPrevNum = nColorNumber;
			m_color = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep);
			m_nStep++;
			m_nCntStep = PEINT_COUNT;
		}
		else if (m_nPrevNum == nColorNumber)
		{// ���h���Ă���̂Ƃ���h��ԍ��̔�r
			if (m_nStep < COLOR_STEP_NUM)
			{
				m_nStep++;
				m_color = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep-1);
				
				m_nCntStep = PEINT_COUNT;
			}
		}
		else
		{
			if (m_nStep == 1)
			{
				m_nPrevNum = -1;
				m_color = DEFAULT_COLOR;
				m_nStep = 0;
				m_nCntStep = PEINT_COUNT;
			}
			else
			{
				m_nStep--;
				m_color = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep-1);
				m_nCntStep = PEINT_COUNT;
			}
		}
	}

}

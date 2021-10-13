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
	m_bHitOld = false;           // ��O�̃t���[���œ������Ă������ۑ�����悤 
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
	m_pFrame = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE-2, 0.0f, TILE_ONE_SIDE-2));
	m_pFrame->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_FRAME));
	m_pFrame->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	m_pFrame->SetPriority(OBJTYPE_UI);

	// �t���O�̏�����
	m_bHitOld = false;
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
	ManageFrame();
	

	if (m_nCntStep > 0)
	{
		m_nCntStep--;
	}

#ifdef _DEBUG
	// �f�o�b�O�L�[

	// �L�[�{�[�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();

	if (pKey->GetKeyPress(DIK_NUMPADENTER))
	{// �Ֆʃ��Z�b�g
		m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		
		// �ϐ��̏�����
		m_nPrevNum = -1;                             // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
		m_nStep = 0;                                 // ���̓h�i�K
		m_nCntStep = 0;                              // �ēx�h��\�J�E���g
		m_nLastHitPlayerNum = -1;                    // �Ō�ɓ��������v���C���[�ԍ�
		m_bHitOld = false;
	}
#endif // _DEBUG
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
			if (!m_bHitOld)
			{
				Peint(pPlayer->GetColorNumber(), pPlayer->GetPlayerNumber());
			}

			// �q�b�g�t���O�̕ۑ�*�������ĂȂ�
			m_bHitOld = true;
			
			return;
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	// �q�b�g�t���O�̕ۑ�*�������Ă�
	m_bHitOld = false;
}

//******************************
// �A�C�R���̊Ǘ�
//******************************
void CTile::ManageFrame(void)//�����ɂ����͂���񂩁H
{
	// �ʒu�̒���
	D3DXVECTOR3 pos = m_pFrame->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) +1.0f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 1.0f, GetPos().z);

		m_pFrame->SetPos(pos);
	}

	// �F�̐ݒ�
	if (m_nStep != 0)
	{
		m_pFrame->SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, 2));
	}
	else
	{
		m_pFrame->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}
}

//******************************
// �h����
//******************************
void CTile::Peint(int nColorNumber , int nPlayerNum)
{
	if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum )
	{
		// �J�E���g�̏�����
		m_nCntStep = PEINT_COUNT;

		// �Ō�ɓ��������v���C���[�̕ۑ�
		m_nLastHitPlayerNum = nPlayerNum;

		if (m_nPrevNum == -1)
		{// �������h���Ă��Ȃ�

			// �J���[�ԍ��̕ۑ�
			m_nPrevNum = nColorNumber;
			// �F�̎擾
			m_color = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep);
			// �F�i�K��i�߂�
			m_nStep++;
			
		}
		else if (m_nPrevNum == nColorNumber)
		{// ���h���Ă���̂Ƃ���h��ԍ�����v

			if (m_nStep < COLOR_STEP_NUM)
			{
				// �i�K��i�߂�
				m_nStep++;
				// �F�̎擾
				m_color = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep-1);
			}
		}
		else
		{// ���h���Ă�F�Ɠh��F���Ⴄ

			if (m_nStep == 1)
			{// �i�K����̎�
				// �J���[�ԍ��̕ۑ�
				m_nPrevNum = nColorNumber;
				// �J���[�̎擾
				m_color = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1);
			}
			else
			{// �i�K��2�ȏ�̎�

				// �i�K�����炷
				m_nStep--;
				// �F�̎擾
				m_color = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep-1);
			}
		}
	}

}

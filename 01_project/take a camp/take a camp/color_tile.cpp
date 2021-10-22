////////////////////////////////////////////////////
//
//    tile�N���X�̏���[tile.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "color_tile.h"
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
#define TILE_DEFAULT_COLOR D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)
#define PEINT_COUNT 60  // �ēx�h���悤�ɂȂ�܂ł̃J�E���g
#define PLAYER_HIT_POS_Y TILE_POS_Y - 3.0f

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CColorTile::m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1] = {};

//******************************
// �R���X�g���N�^
//******************************
CColorTile::CColorTile()
{
	m_pFrame = NULL;
	m_nPrevNum = -1;                             // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	m_nStep = 0;                                 // ���̓h�i�K
	m_nCntStep = 0;                              // �ēx�h��\�J�E���g
	m_nLastHitPlayerNum = -1;                    // ���݂̓h���Ă���ԍ�
}

//******************************
// �f�X�g���N�^
//******************************
CColorTile::~CColorTile()
{
}

//******************************
// �N���X����
//******************************
CColorTile * CColorTile::Create(D3DXVECTOR3 pos)
{
	// �������̊m��
	CColorTile *pTile;
	pTile = new CColorTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_COLOR_TILE); // �I�u�W�F�N�g�^�C�v

	return pTile;
}

//******************************
// �F�̐��𐔂���
//******************************
void CColorTile::CountColorTile(void)
{
	// �^�C�����̏�����
	ZeroMemory(&m_anTileNum, sizeof(m_anTileNum));

	CColorTile*pTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

	while (pTile != NULL)
	{
		// �y�C���g�ԍ��̎擾
		int nPeintNum = pTile->GetPeintNum();

		if (nPeintNum >= 0)
		{
			// �^�C�����̎擾
			m_anTileNum[nPeintNum][0] += pTile->GetStepNum();
			m_anTileNum[nPeintNum][pTile->GetStepNum()]++;
		}
		
		// ���X�g��i�߂�
		pTile = (CColorTile*)pTile->GetNext();
	}
}

//******************************
// ����������
//******************************
HRESULT CColorTile::Init(void)
{
	if (FAILED(CTile::Init()))
	{
		return E_FAIL;
	}

	// �A�C�R��
	m_pFrame = CScene3d::Create(GetPos(), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	m_pFrame->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_FRAME));
	m_pFrame->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	m_pFrame->SetPriority(OBJTYPE_UI);

	// �ϐ��̏�����
	m_nPrevNum = -1;                             // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	m_nStep = 0;                                 // ���̓h�i�K
	m_nCntStep = 0;                              // �ēx�h��\�J�E���g
	m_nLastHitPlayerNum = -1;                    // ���݂̓h���Ă���ԍ�

	return S_OK;
}

//******************************
// �I������
//******************************
void CColorTile::Uninit(void)
{
	CTile::Uninit();
}

//******************************
// �X�V����
//******************************
void CColorTile::Update(void)
{

	// �^�C���̃A�b�v�f�[�g
	CTile::Update();

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
		ResetTile();
	}
#endif // _DEBUG
}

//******************************
// �^�C���̃��Z�b�g����
//******************************
void CColorTile::ResetTile(void)
{
	SetColor(TILE_DEFAULT_COLOR);

	// �ϐ��̏�����
	m_nPrevNum = -1;                             // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	m_nStep = 0;                                 // ���̓h�i�K
	m_nCntStep = 0;                              // �ēx�h��\�J�E���g
	m_nLastHitPlayerNum = -1;                    // �Ō�ɓ��������v���C���[�ԍ�
	
}

//******************************
// �e�Ɠ��������Ƃ��̃A�N�V����*�g���K�[
//******************************
void CColorTile::HitPlayerActionTrigger(CPlayer * pPlayer)
{
	Peint(pPlayer->GetColorNumber(), pPlayer->GetPlayerNumber());

	D3DXVECTOR3 pos = GetPos();
	pos.y = PLAYER_HIT_POS_Y;
	SetPos(pos);
}

//******************************
// �A�C�R���̊Ǘ�
//******************************
void CColorTile::ManageFrame(void)
{
	// �ʒu�̒���
	D3DXVECTOR3 pos = m_pFrame->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 1.0f, GetPos().z))
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
		m_pFrame->SetColor(TILE_DEFAULT_COLOR);
	}
}

//******************************
// �h����
//******************************
void CColorTile::Peint(int nColorNumber, int nPlayerNum)
{
	if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum)
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
			SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep));
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
				SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
			}
		}
		else
		{// ���h���Ă�F�Ɠh��F���Ⴄ

			if (m_nStep == 1)
			{// �i�K����̎�
			 // �J���[�ԍ��̕ۑ�
				m_nPrevNum = nColorNumber;
				// �J���[�̎擾
				SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1));
			}
			else
			{// �i�K��2�ȏ�̎�

			 // �i�K�����炷
				m_nStep--;
				// �F�̎擾
				SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
			}
		}
	}

}

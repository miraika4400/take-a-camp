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
#include "particle.h"
#include "peint_collision.h"
#include "max_color_effect.h"
#include "paint_time.h"

#ifdef _DEBUG
#include "manager.h"
#include "keyboard.h"
#endif

//*****************************
// �}�N����`
//*****************************
#define PEINT_COUNT (60)		// �ēx�h���悤�ɂȂ�܂ł̃J�E���g
#define PLAYER_HIT_POS_Y (TILE_POS_Y - 3.0f)

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CColorTile::m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1] = {};

//******************************
// �R���X�g���N�^
//******************************
CColorTile::CColorTile()
{
	m_ColorTileState = COLOR_TILE_NORMAL;
	m_pFrame	= NULL;
	m_nPrevNum	= -1;					// ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	m_nStep		= 0;					// ���̓h�i�K
	m_nCntStep	= 0;					// �ēx�h��\�J�E���g
	m_nLastHitPlayerNum = -1;			// ���݂̓h���Ă���ԍ�4
	m_nCntFrem	= 0;
	m_distColor	= TILE_DEFAULT_COLOR;
	m_pPaintTime = NULL;
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
void CColorTile::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// �������̊m��
	CColorTile *pTile;
	pTile = new CColorTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
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
// �w����W�ƂԂ����Ă���^�C���̎擾����
//******************************
CColorTile * CColorTile::GetHitColorTile(D3DXVECTOR3 pos)
{
	CCollision*pCollision = CCollision::CreateSphere(pos, TILE_ONE_SIDE / 4);

	CColorTile*pTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

	while (pTile != NULL)
	{
		if (CCollision::CollisionSphere(pCollision,pTile->GetCollision()))
		{
			if (pCollision != NULL)
			{
				pCollision->ReConnection();
				pCollision->Uninit();
				delete pCollision;
				pCollision = NULL;
			}

			return pTile;
		}
		// ���X�g��i�߂�
		pTile = (CColorTile*)pTile->GetNext();
	}

	if (pCollision != NULL)
	{
		pCollision->ReConnection();
		pCollision->Uninit();
		delete pCollision;
		pCollision = NULL;
	}

	return NULL;
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
	m_pFrame->SetColor(TILE_DEFAULT_COLOR);
	m_pFrame->SetPriority(OBJTYPE_UI);

	// �ϐ��̏�����
	m_nPrevNum = -1;                             // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	m_nStep = 0;                                 // ���̓h�i�K
	m_nCntStep = 0;                              // �ēx�h��\�J�E���g
	m_nLastHitPlayerNum = -1;                    // ���݂̓h���Ă���ԍ�
	
	SetPriority(OBJTYPE_COLOR_TILE); // �I�u�W�F�N�g�^�C�v

	m_pPaintTime = CPaintTime::Create();
	

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

		// �F�̊Ǘ�
		ManageColor();
	}

	if (m_nStep == 3)
	{
		m_nCntFrem++;

		if(m_nCntFrem % 10 <= 0)
		{
			D3DXVECTOR3 pos = m_pFrame->GetPos();
			CParticle::Create(D3DXVECTOR3(pos.x + (float)(rand() % 16 -8), pos.y, pos.z + (float)(rand() % 16 - 8)), D3DXVECTOR3(0.0f, 0.25f, 0.0f), D3DXVECTOR3(3.0f, 3.0f, 3.0f), 500, GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1), EFFECT_DEFAULT_FADE_OUT_RATE, CParticle::PARTICLE_SQUARE);
		}
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
// �^�C���̓h��i�K����
//******************************
void CColorTile::ColorDown(int nCount)
{
	//�h��i�K������
	m_nStep = m_nStep - nCount;

	//0��菬�����ꍇ
	if (m_nStep <= 0)
	{
		//�^�C�����Z�b�g
		ResetTile();
	}
	//�[���ȏ�̏ꍇ
	else
	{
		// �F�̎擾
		m_distColor = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1);

		//�J���[�ύX
		m_distColor.r = (m_distColor.r);
		m_distColor.g = (m_distColor.g);
		m_distColor.b = (m_distColor.b);

		//�J���[�Z�b�g
		SetColor(m_distColor);
	}
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
// �h�蔻��Ɠ����������̃A�N�V����
//******************************
void CColorTile::HItPeint(CPeintCollision * pPeint)
{
	//�h�菈��
	Peint(pPeint->GetColorNumber(), pPeint->GetPlayerNum());
	//���S�t���O
	pPeint->Death();
}

//******************************
// �A�C�R���̊Ǘ�
//******************************
void CColorTile::ManageFrame(void)
{
	// �ʒu�̒���
	D3DXVECTOR3 pos = m_pFrame->GetPos();
	if (pos != D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z))
	{
		pos = D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z);

		m_pFrame->SetPos(pos);
	}

	// �h���Ԉʒu
	m_pPaintTime->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + (TILE_SIZE_Y / 2) + 0.1f, GetPos().z));

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
// �F�̊Ǘ�
//******************************
void CColorTile::ManageColor(void)
{
	D3DXCOLOR col = GetColor();

	float fRate = 1.0f / PEINT_COUNT;
	
	col.r += (m_distColor.r) * fRate;
	col.g += (m_distColor.g) * fRate;
	col.b += (m_distColor.b) * fRate;

	SetColor(col);
}

//******************************
// �h����
//******************************
void CColorTile::Peint(int nColorNumber, int nPlayerNum)
{
	//�X�e�[�g���ʏ킩
	if (m_ColorTileState == COLOR_TILE_NORMAL)
	{
		if (m_nCntStep <= 0 || nPlayerNum != m_nLastHitPlayerNum)
		{
			// �J�E���g�̏�����
			m_nCntStep = PEINT_COUNT;
		//	m_pPaintTime->SetPaintTime(PEINT_COUNT);

			// �Ō�ɓ��������v���C���[�̕ۑ�
			m_nLastHitPlayerNum = nPlayerNum;

			if (m_nPrevNum == -1)
			{// �������h���Ă��Ȃ�

			 // �J���[�ԍ��̕ۑ�
				m_nPrevNum = nColorNumber;
				// �F�̎擾
				//SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep));
				m_distColor = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep);

				m_distColor.r = (m_distColor.r - TILE_DEFAULT_COLOR.r);
				m_distColor.g = (m_distColor.g - TILE_DEFAULT_COLOR.g);
				m_distColor.b = (m_distColor.b - TILE_DEFAULT_COLOR.b);
				// �F�i�K��i�߂�
				m_nStep++;
			}
			else if (m_nPrevNum == nColorNumber)
			{// ���h���Ă���Ƃ���h��ԍ�����v

				if (m_nStep < COLOR_STEP_NUM)
				{
					// �i�K��i�߂�
					m_nStep++;
					// �F�̎擾
					//SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
					m_distColor = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1);

					m_distColor.r = (m_distColor.r - GetColor().r);
					m_distColor.g = (m_distColor.g - GetColor().g);
					m_distColor.b = (m_distColor.b - GetColor().b);

					if (m_nStep == COLOR_STEP_NUM)
					{
						// �h�ő�
						CMaxColorEffect::Create(GetPos(), GET_COLORMANAGER->GetIconColor(m_nPrevNum));
						// �y�C���g�^�C���͏o���Ȃ�
						m_pPaintTime->SetDrawFlag(false);
					}
				}
				else
				{
					// �y�C���g�^�C���͏o���Ȃ�
					m_pPaintTime->SetDrawFlag(false);
					m_nCntStep = 0;
				}
			}
			else
			{// ���h���Ă�F�Ɠh��F���Ⴄ

				if (m_nStep == 1)
				{// �i�K����̎�
				 // �J���[�ԍ��̕ۑ�
					m_nPrevNum = nColorNumber;
					// �J���[�̎擾
					//SetColor(GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1));
					m_distColor = GET_COLORMANAGER->GetStepColor(nColorNumber, m_nStep - 1);
					m_distColor.r = (m_distColor.r - GetColor().r);
					m_distColor.g = (m_distColor.g - GetColor().g);
					m_distColor.b = (m_distColor.b - GetColor().b);
				}
				else
				{// �i�K��2�ȏ�̎�

				 // �i�K�����炷
					m_nStep--;
					// �F�̎擾
					//SetColor(GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1));
					m_distColor = GET_COLORMANAGER->GetStepColor(m_nPrevNum, m_nStep - 1);
					m_distColor.r = (m_distColor.r - GetColor().r);
					m_distColor.g = (m_distColor.g - GetColor().g);
					m_distColor.b = (m_distColor.b - GetColor().b);
				}
			}
		}

	}
}

//******************************
// �`���[�W�t���O����
//******************************
bool CColorTile::ChargeFlag(int nPlayerNum)
{
	//�X�e�[�g���ʏ��Ԃ�
	if (m_ColorTileState == COLOR_TILE_NORMAL)
	{
		//�v���C���[���h�����^�C����
		if (nPlayerNum == m_nLastHitPlayerNum&&m_nStep > 0)
		{
			//�X�e�[�g���`���[�W��ԂɈڍs
			m_ColorTileState = COLOR_TILE_CHARGE;
			return true;
		}
	}
	return false;
}

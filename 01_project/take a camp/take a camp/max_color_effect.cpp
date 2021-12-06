////////////////////////////////////////////////////
//
//    max_color_effect�̏���[max_color_effect.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "max_color_effect.h"
#include "scene3d.h"
#include "tile.h"
#include "manager.h"
#include "renderer.h"
#include "resource_texture.h"

//=============================
// �}�N����`
//=============================

//=============================
// �ÓI�����o�ϐ��錾
//=============================
#define LIFE_FRAME 60
#define ALPHA_RATE 0.05f

//=============================
// �R���X�g���N�^
//=============================
CMaxColorEffect::CMaxColorEffect() : CScene(OBJTYPE_EFFECT)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_polygonColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
	ZeroMemory(&m_apPolygon, sizeof(m_apPolygon));
	m_nCntLife = 0;
	m_fTexV = -1.0f;
	m_distColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

//=============================
// �f�X�g���N�^
//=============================
CMaxColorEffect::~CMaxColorEffect()
{
}

//=============================
// �N���G�C�g
//=============================
CMaxColorEffect * CMaxColorEffect::Create(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	// �������̊m��
	CMaxColorEffect *pEffect = new CMaxColorEffect;
	// ���W
	pEffect->m_pos = pos;
	// �J���[
	pEffect->m_polygonColor = col;
	// ������
	pEffect->Init();

	return pEffect;
}

//=============================
// ����������
//=============================
HRESULT CMaxColorEffect::Init(void)
{
	// �����̏�����
	m_nCntLife = 0;
	m_polygonColor.a = 0.0f;
	m_fTexV = -1.0f;

	const D3DXVECTOR3 polygonPos[MAX_COLOR_EFFECT_POLYGON_NUM] =
	{
		D3DXVECTOR3(m_pos.x                    ,m_pos.y + TILE_SIZE_Y*1.5f,m_pos.z - TILE_ONE_SIDE / 2),
		D3DXVECTOR3(m_pos.x - TILE_ONE_SIDE / 2,m_pos.y + TILE_SIZE_Y*1.5f,m_pos.z),
		D3DXVECTOR3(m_pos.x + TILE_ONE_SIDE / 2,m_pos.y + TILE_SIZE_Y*1.5f,m_pos.z),
		D3DXVECTOR3(m_pos.x                    ,m_pos.y + TILE_SIZE_Y*1.5f,m_pos.z + TILE_ONE_SIDE / 2),
	};
	const D3DXVECTOR3 polygonSize[MAX_COLOR_EFFECT_POLYGON_NUM] =
	{
		D3DXVECTOR3(TILE_ONE_SIDE ,TILE_ONE_SIDE, 0.0f),
		D3DXVECTOR3(0.0f          ,TILE_ONE_SIDE, TILE_ONE_SIDE),
		D3DXVECTOR3(0.0f          ,TILE_ONE_SIDE, TILE_ONE_SIDE),
		D3DXVECTOR3(TILE_ONE_SIDE ,TILE_ONE_SIDE, 0.0f) ,
	};

	D3DXVECTOR2 uv[4];
	// �e�N�X�`��UV���W�̐ݒ�
	uv[0] = D3DXVECTOR2(0.0f, m_fTexV + 0.0f);
	uv[1] = D3DXVECTOR2(1.0f, m_fTexV + 0.0f);
	uv[2] = D3DXVECTOR2(0.0f, m_fTexV + 1.0f);
	uv[3] = D3DXVECTOR2(1.0f, m_fTexV + 1.0f);

	for (int nCntPolygon = 0; nCntPolygon < MAX_COLOR_EFFECT_POLYGON_NUM; nCntPolygon++)
	{
		m_apPolygon[nCntPolygon] = CScene3d::Create(polygonPos[nCntPolygon] ,D3DXVECTOR3(TILE_ONE_SIDE, TILE_ONE_SIDE, 0.0f));
		if (nCntPolygon == 1 ||nCntPolygon  == 2)
		{
			m_apPolygon[nCntPolygon]->SetRot(D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f));
		}
		m_apPolygon[nCntPolygon]->SetColor(m_polygonColor);
		m_apPolygon[nCntPolygon]->OutList();
		m_apPolygon[nCntPolygon]->SetTextureUV(uv);
		m_apPolygon[nCntPolygon]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_MAX_COLOR_EFFECT));
	}

	

	return S_OK;
}

//=============================
// �I������
//=============================
void CMaxColorEffect::Uninit(void)
{
	for (int nCntPolygon = 0; nCntPolygon < MAX_COLOR_EFFECT_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->Uninit();
			delete m_apPolygon[nCntPolygon];
			m_apPolygon[nCntPolygon] = NULL;
		}
	}

	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CMaxColorEffect::Update(void)
{
	// �A���t�@�l�̏���
	if (m_nCntLife < LIFE_FRAME / 2.0f)
	{// �ڕW�l1.0f
		m_polygonColor.a += (1.0f - m_polygonColor.a)*ALPHA_RATE;
	}
	else
	{//�ڕW�l0.0f
		m_polygonColor.a += (0.0f - m_polygonColor.a)*ALPHA_RATE;
	}

	m_fTexV +=(0.0f - m_fTexV)*ALPHA_RATE;
	D3DXVECTOR2 uv[4];
	// �e�N�X�`��UV���W�̐ݒ�
	uv[0] = D3DXVECTOR2(0.0f, m_fTexV + 0.0f);
	uv[1] = D3DXVECTOR2(1.0f, m_fTexV + 0.0f);
	uv[2] = D3DXVECTOR2(0.0f, m_fTexV + 1.0f);
	uv[3] = D3DXVECTOR2(1.0f, m_fTexV + 1.0f);

	// �J���[�EUV�̐ݒ�
	for (int nCntPolygon = 0; nCntPolygon < MAX_COLOR_EFFECT_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->SetColor(m_polygonColor);
			m_apPolygon[nCntPolygon]->SetTextureUV(uv);
		}
	}

	// �����̏���
	m_nCntLife++;
	if (m_nCntLife > LIFE_FRAME)
	{
		Uninit();
	}
}

//=============================
// �`�揈��
//=============================
void CMaxColorEffect::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	DWORD save;
	pDevice->GetRenderState(D3DRS_CULLMODE, &save); // �J�����O�̕ۑ�
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // �J�����O �I�t
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER); // �e�N�X�`��V�l�̌J��Ԃ��ݒ�

	for (int nCntPolygon = 0; nCntPolygon < MAX_COLOR_EFFECT_POLYGON_NUM; nCntPolygon++)
	{
		if (m_apPolygon[nCntPolygon] != NULL)
		{
			m_apPolygon[nCntPolygon]->Draw();
		}
	}

	pDevice->SetRenderState(D3DRS_CULLMODE, save); // �J�����O�߂�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP); // �e�N�X�`��V�l�̌J��Ԃ��ݒ�
}
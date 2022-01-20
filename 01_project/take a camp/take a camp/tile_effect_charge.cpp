////////////////////////////////////////////////////
//
//    �h���ԃN���X�̏���[paint_time.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "tile_effect_charge.h"
#include "scene3d.h"
#include "tile.h"
#include "resource_texture.h"
//******************************
// �}�N����`
//******************************
#define COLOR (D3DXCOLOR(0.0f,0.0f,0.0f,GetAlpha()))

//******************************
// �R���X�g���N�^
//******************************
CTileEffectCharge::CTileEffectCharge()
{
	m_pPolygon = NULL;
}

//******************************
// �f�X�g���N�^
//******************************
CTileEffectCharge::~CTileEffectCharge()
{
}

//******************************
// �N���X����
//******************************
CTileEffectCharge * CTileEffectCharge::Create(void)
{
	// �N���X����
	CTileEffectCharge * pInstace = new CTileEffectCharge;

	// ����������
	pInstace->Init();

	return pInstace;
}

//******************************
// ����������
//******************************
HRESULT CTileEffectCharge::Init(void)
{
	CTileEffect::Init();

	// ������
	m_pPolygon = CScene3d::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(TILE_ONE_SIDE - 5.0f, 0.0, TILE_ONE_SIDE - 5.0f));
	m_pPolygon->SetColor(COLOR);
	m_pPolygon->OutList();
	
	// �e�N�X�`���̊��蓖��
	m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TILE_CHARGE));

	return S_OK;
}


//******************************
// �X�V����
//******************************
void CTileEffectCharge::Update(void)
{
	m_pPolygon->SetColor(COLOR);
	CTileEffect::Update();
}

//******************************
// �I������
//******************************
void CTileEffectCharge::Uninit(void)
{
	if (m_pPolygon != NULL)
	{
		m_pPolygon->Uninit();
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	CTileEffect::Uninit();
}

//******************************
// �`�揈��
//******************************
void CTileEffectCharge::Draw(void)
{
	// �`��
	if (m_pPolygon != NULL)
	{
		m_pPolygon->Draw();
	}
}

//******************************
// ���W�̃Z�b�g
//******************************
void CTileEffectCharge::SetPos(D3DXVECTOR3 pos)
{
	m_pPolygon->SetPos(pos);
}

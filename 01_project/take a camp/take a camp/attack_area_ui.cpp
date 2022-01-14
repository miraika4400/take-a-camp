//=============================================================================
//
// �U���͈�UI�̏��� [attack_area_ui.cpp]
// Author : ���V����
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "attack_area_ui.h"
#include "resource_texture.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define LEVEL_CHANGE_COUNT (100)
#define SIZE (D3DXVECTOR3(1260.0f,1944,0.0f)/5.0f)
#define COLOR (D3DXCOLOR(1.0f,1.0f,1.0f,0.9f))
#define TEX_ANIM_MAX_U 3                        // ���ʃe�N�X�`��������*�c

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackAreaUi::CAttackAreaUi() :CScene2d(OBJTYPE_UI_2)
{
	m_nLevel = 0;
	m_nCharaType = CResourceCharacter::CHARACTER_KNIGHT;
	m_bDraw = false;
	m_nCntLevel = 0;
	ZeroMemory(&m_apTex, sizeof(m_apTex));
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackAreaUi::~CAttackAreaUi()
{

}

//=============================================================================
// ��������
//=============================================================================
CAttackAreaUi * CAttackAreaUi::Create(D3DXVECTOR3 pos)
{
	// �������̊m��
	CAttackAreaUi *pPointa;
	pPointa = new CAttackAreaUi;
	// ������
	pPointa->Init();

	// �e�l�̑��
	pPointa->SetPos(pos);

	return pPointa;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CAttackAreaUi::Init(void)
{
	// ����������
	CScene2d::Init();

	// ������
	m_nLevel = 0;
	m_nCharaType = CResourceCharacter::CHARACTER_KNIGHT;
	m_bDraw = false;
	m_nCntLevel = 0;

	// �R�m
    m_apTex[CResourceCharacter::CHARACTER_KNIGHT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT);
	// ��
    m_apTex[CResourceCharacter::CHARACTER_LANCER] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER);
	// ���@
    m_apTex[CResourceCharacter::CHARACTER_WIZARD] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD);
	// ����
    m_apTex[CResourceCharacter::CHARACTER_THIEF] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF);
	// ��p�t
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN);
	// �|
    m_apTex[CResourceCharacter::CHARACTER_ARCHER] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER);

    float fU = 1.0f / TEX_ANIM_MAX_U;

    D3DXVECTOR2 uv[NUM_VERTEX];
    uv[0] = D3DXVECTOR2(fU*0.0f, 0.0f);
    uv[1] = D3DXVECTOR2(fU*0.0f + fU, 0.0f);
    uv[2] = D3DXVECTOR2(fU*0.0f, 1.0f);
    uv[3] = D3DXVECTOR2(fU*0.0f + fU, 1.0f);

    SetTextureUV(uv);

	SetSize(SIZE);
	SetColor(COLOR);
	return S_OK;
}

//=============================================================================
// �X�V����
//=============================================================================
void CAttackAreaUi::Update(void)
{
	// �J�E���g��i�߂�
	m_nCntLevel++;
	if (m_nCntLevel > LEVEL_CHANGE_COUNT)
	{
		// �J�E���g�̏�����
		m_nCntLevel = 0;
		// ���x����i�߂�
		m_nLevel++;
		if (m_nLevel >= (MAX_ATTACK_LEVEL - 1))
		{
			m_nLevel = 0;
		}

        // �e�N�X�`���A�j���[�V����
        float fU = 1.0f / TEX_ANIM_MAX_U;
        D3DXVECTOR2 uv[NUM_VERTEX];
        uv[0] = D3DXVECTOR2(fU*m_nLevel, 0.0f);
        uv[1] = D3DXVECTOR2(fU*m_nLevel + fU, 0.0f);
        uv[2] = D3DXVECTOR2(fU*m_nLevel, 1.0f);
        uv[3] = D3DXVECTOR2(fU*m_nLevel + fU, 1.0f);
        SetTextureUV(uv);

        if (m_nCharaType == CResourceCharacter::CHARACTER_NONE) return;

	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CAttackAreaUi::Draw(void)
{
	// �`�揈��
	if(m_bDraw) CScene2d::Draw();
}

//=============================================================================
// ���Z�b�g
//=============================================================================
void CAttackAreaUi::Reset(void)
{
	// �J�E���g�̏�����
	m_nLevel = 0;
    // �e�N�X�`���̐؂�ւ�
    BindTexture(m_apTex[m_nCharaType]);
}

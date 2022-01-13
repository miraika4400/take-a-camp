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
    m_apTex[CResourceCharacter::CHARACTER_KNIGHT][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT1);
	m_apTex[CResourceCharacter::CHARACTER_KNIGHT][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT2);
	m_apTex[CResourceCharacter::CHARACTER_KNIGHT][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT3);
	// ��
    m_apTex[CResourceCharacter::CHARACTER_LANCER][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER1);
    m_apTex[CResourceCharacter::CHARACTER_LANCER][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER2);
    m_apTex[CResourceCharacter::CHARACTER_LANCER][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER3);
	// ���@
    m_apTex[CResourceCharacter::CHARACTER_WIZARD][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD1);
    m_apTex[CResourceCharacter::CHARACTER_WIZARD][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD2);
    m_apTex[CResourceCharacter::CHARACTER_WIZARD][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD3);
	// ����
    m_apTex[CResourceCharacter::CHARACTER_THIEF][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF1);
    m_apTex[CResourceCharacter::CHARACTER_THIEF][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF2);
    m_apTex[CResourceCharacter::CHARACTER_THIEF][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF3);
	// ��p�t
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN1);
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN2);
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN3);
	// �|
    m_apTex[CResourceCharacter::CHARACTER_ARCHER][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER1);
    m_apTex[CResourceCharacter::CHARACTER_ARCHER][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER2);
    m_apTex[CResourceCharacter::CHARACTER_ARCHER][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER3);

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

        if (m_nCharaType == CResourceCharacter::CHARACTER_NONE) return;
		// �e�N�X�`���̐؂�ւ�
		BindTexture(m_apTex[m_nCharaType][m_nLevel]);
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
    BindTexture(m_apTex[m_nCharaType][m_nLevel]);
}

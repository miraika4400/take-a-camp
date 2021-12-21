//=============================================================================
//
// �L�����N�^�[�|���S���̏��� [character_polygon.cpp]
// Author : ���V����
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "character_polygon.h"
#include "dynamic_texture.h"
#include "player_model.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define CHARACTER_POS (D3DXVECTOR3(0.0f,-8.8f,0.0f))
#define CHARACTER_ROT (D3DXVECTOR3(0.0f,D3DXToRadian(180.0f),0.0f))
#define CHARACTER_ADD_ROT (D3DXVECTOR3(0.0f, 0.01f, 0.0f))

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCharacterPolygon::CCharacterPolygon() :CScene2d(OBJTYPE_UI_2)
{
	m_pDynamicTex = NULL;
	m_pCharacterModel = NULL;
	m_charaType = CResourceCharacter::CHARACTER_NONE;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCharacterPolygon::~CCharacterPolygon()
{

}

//=============================================================================
// ��������
//=============================================================================
CCharacterPolygon * CCharacterPolygon::Create(D3DXVECTOR3 pos, CharaPolygonMode mode)
{
	// �������̊m��
	CCharacterPolygon *pCharacterPolygon;
	pCharacterPolygon = new CCharacterPolygon;

	// ������
	pCharacterPolygon->Init();

	// �e�l�̑��
	pCharacterPolygon->SetPos(pos);
	pCharacterPolygon->SetPriority(OBJTYPE_UI_2);
	pCharacterPolygon->m_mode = mode;

	return pCharacterPolygon;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCharacterPolygon::Init(void)
{
	// ����������
	CScene2d::Init();
	// �T�C�Y�̐ݒ�
	SetSize(DEFAULT_CHARACTER_POLYGON_SIZE);
	// ���I�e�N�X�`���̐���
	m_pDynamicTex = CDynamicTexture::Create(D3DXVECTOR2(DEFAULT_CHARACTER_POLYGON_SIZE.x, DEFAULT_CHARACTER_POLYGON_SIZE.y));
	// �L�����N�^�[���f���̐���*NONE���ƃ��f����񂪂Ȃ��̂łƂ肠�����R�m�Ő���
	m_pCharacterModel = CPlayerModel::Create(CHARACTER_POS, CHARACTER_ROT, CResourceCharacter::CHARACTER_KNIGHT);
	// ���X�g�\������O��
	m_pCharacterModel->OutList();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCharacterPolygon::Uninit(void)
{
	// ���f���̉��
	if (m_pCharacterModel != NULL)
	{
		m_pCharacterModel->Uninit();
		delete m_pCharacterModel;
		m_pCharacterModel = NULL;
	}
	// ���I�e�N�X�`���̉��
	if (m_pDynamicTex != NULL)
	{
		m_pDynamicTex->Uninit();
		delete m_pDynamicTex;
		m_pDynamicTex = NULL;
	}

	// �I������
	CScene2d::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CCharacterPolygon::Update(void)
{
	switch (m_mode)
	{
	case CCharacterPolygon::MODE_NONE:
		break;
	case CCharacterPolygon::MODE_ROTATION:
		// ���f���̍X�V����
		if (m_pCharacterModel != NULL)
		{
			m_pCharacterModel->Update();
			m_pCharacterModel->SetRot(m_pCharacterModel->GetRot() + CHARACTER_ADD_ROT);
		}
		break;
	default:
		break;
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CCharacterPolygon::Draw(void)
{
	// �L�����N�^�[�^�C�v��NONE�̎��͕`�悵�Ȃ�
	if (m_charaType == CResourceCharacter::CHARACTER_NONE) return;

	
	if (m_pCharacterModel != NULL)
	{
		// �e�N�X�`���̃��f������������
		m_pDynamicTex->Begin();
		m_pCharacterModel->Draw();
		// �����_�����O�^�[�Q�b�g��߂�
		m_pDynamicTex->End();
	}
	// �e�N�X�`���̊��蓖��
	BindTexture(m_pDynamicTex->GetTexture());

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �T���v���[�X�e�[�g�̐ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_BORDER); // �e�N�X�`��U�l�̌J��Ԃ��ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER); // �e�N�X�`��V�l�̌J��Ԃ��ݒ�

	// �`�揈��
	CScene2d::Draw();

	// �T���v���[�X�e�[�g�̐ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP); // �e�N�X�`��U�l�̌J��Ԃ��ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP); // �e�N�X�`��V�l�̌J��Ԃ��ݒ�
}

//=============================================================================
// �L�����^�C�v�̃Z�b�g
//=============================================================================
void CCharacterPolygon::SetCharaType(CResourceCharacter::CHARACTER_TYPE type)
{
	if (m_charaType == type) return;
	// �^�C�v�Z�b�g
	m_charaType = type;

	// ���f���̃^�C�v�Z�b�g
	if (type != CResourceCharacter::CHARACTER_NONE)
	{
		m_pCharacterModel->SetCharacterType(m_charaType);
		m_pCharacterModel->SetRot(CHARACTER_ROT);
	}
}

//=============================================================================
// �����J���[�̃Z�b�g
//=============================================================================
void CCharacterPolygon::SetRimColor(D3DXCOLOR col)
{
	m_pCharacterModel->SetRimColor(col);
}

//=============================================================================
// Tex�J���[�̃Z�b�g
//=============================================================================
void CCharacterPolygon::SetTexColor(D3DXCOLOR col)
{
	m_pCharacterModel->SetTexColor(col);
}

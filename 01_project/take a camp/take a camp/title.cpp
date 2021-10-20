////////////////////////////////////////////////////
//
//    �^�C�g���N���X�̏���[title.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////


//=============================
// �C���N���[�h
//=============================
#include "title.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "keyboard.h"
#include "mouse.h"
#include "joypad.h"
#include "fade.h"
#include "sound.h"
#include "resource_texture.h"
#include "camera_base.h"
#include "bg.h"
#include "light.h"
//**********************************
// �ÓI�����o�ϐ��錾
//**********************************

//**********************************
// �}�N����`
//**********************************
#define OBJ_BACE_POS_Y 2000.0f
#define STAGE_SPACE 150.0f

//=============================
// �R���X�g���N�^
//=============================
CTitle::CTitle()
{
	m_pPolygon = NULL;
}

//=============================
// �f�X�g���N�^
//=============================
CTitle::~CTitle()
{
}

//=============================
// �N���G�C�g
//=============================
CTitle * CTitle::Create(void)
{
	// �������̊m��
	CTitle *pTitle = new CTitle;
	// ������
	pTitle->Init();
	return pTitle;
}

//=============================
// ����������
//=============================
HRESULT CTitle::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_pPolygon = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 200.0f, 0.0f),
		D3DXVECTOR3(800.0f, 400.0f, 0.0f),
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TITLE));
	
	// �J��������
	CManager::SetCamera(CCamera::Create());

	// �w�i�̐ݒ�
	CBg::Create();

	// ���C�g�N���X�̐���
	CManager::SetLight();

	return S_OK;
}

//=============================
// �I������
//=============================
void CTitle::Uninit(void)
{
	// �J�����N���X�̉������
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
		pCamera = NULL;
	}

	if (m_pPolygon != NULL)
	{
		// �|���S���̏I������
		m_pPolygon->Uninit();

		// �������̉��
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	// ���C�g�N���X�̉������
	CLight * pLight = CManager::GetLight();
	if (pLight != NULL)
	{
		// ���C�g�̏I������
		pLight->Uninit();

		// �������̉��
		delete pLight;
		pLight = NULL;
	}

	// �J������
	Release();
}


//=============================
// �X�V����
//=============================
void CTitle::Update(void)
{
	// �J�����N���X�̉������
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}


	// �|���S���̍X�V����
	m_pPolygon->Update();

	if( CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN) || 
		CManager::GetMouse()->GetMouseTrigger(0) /*|| 
		CManager::GetJoypad()->GetJoystickTrigger(3, 0)||
		CManager::GetJoypad()->GetJoystickTrigger(11, 0)*/)
	{
		CManager::GetFade()->SetFade(CManager::MODE_TUTORIAL);
	}
}


//=============================
// �`�揈��
//=============================
void CTitle::Draw(void)
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}

	// �|���S���̕`�揈��
	m_pPolygon->Draw();
}

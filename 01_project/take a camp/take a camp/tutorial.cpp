////////////////////////////////////////////////////
//
//    tutorial�̏���[tutorial.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "tutorial.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "keyboard.h"
#include "mouse.h"
#include "joypad.h"
#include "fade.h"
#include "resource_texture.h"
#include "sound.h"
#include "camera_base.h"
#include "map.h"
#include "light.h"
#include "bg.h"
#include "text.h"

//**********************************
// �ÓI�����o�ϐ��錾
//**********************************
LPDIRECT3DTEXTURE9 CTutorial::m_pTexture[TUTORIAL_NUM] = {};

//**********************************
// �}�N����`
//**********************************

//=============================
// �R���X�g���N�^
//=============================
CTutorial::CTutorial()
{
	m_pPolygon = NULL;
	m_nNumTutorial = 0;
}

//=============================
// �f�X�g���N�^
//=============================
CTutorial::~CTutorial()
{
}

//=============================
// �N���G�C�g
//=============================
CTutorial * CTutorial::Create(void)
{
	// �������̊m��
	CTutorial *pTitle = new CTutorial;

	// ������
	pTitle->Init();
	return pTitle;
}

//=============================
// ����������
//=============================
HRESULT CTutorial::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	//// �e�N�X�`���̐���
	//m_pTexture[0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SPEECHBUBBLE);

	m_pPolygon = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f),
		D3DXVECTOR3(512.0f, 256.0f, 0.0f),
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	m_pPolygon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SPEECHBUBBLE));

	// �w�i�̐ݒ�
	CBg::Create();

	// �J��������
	CManager::SetCamera(CCamera::Create());
	CMap::Create(CMapManager::MAP_TYPE_1);

	// ���C�g�N���X�̐���
	CManager::SetLight();

	CText::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f), 25.0f, 10.0f, "�D���ȐH�ו��̓������Ɣ~�����ƃT�[�����Ɛ��n���ŁA�����ȐH�ו��͖�ؑS�ʂƂ݂��݂������H�ו��ł��B", CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	return S_OK;
}

//=============================
// �I������
//=============================
void CTutorial::Uninit(void)
{
	if (m_pPolygon != NULL)
	{
		// �|���S���̏I������
		m_pPolygon->Uninit();

		// �������̉��
		delete m_pPolygon;
		m_pPolygon = NULL;
	}

	// �J�����N���X�̉������
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
		pCamera = NULL;
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
void CTutorial::Update(void)
{
	//// �|���S���̍X�V����
	//m_pPolygon->Update();

	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN) ||
		CManager::GetMouse()->GetMouseTrigger(0) /*||
		CManager::GetJoypad()->GetJoystickTrigger(3, 0)*/)
	{
		m_nNumTutorial++;
		if (m_nNumTutorial >= TUTORIAL_NUM)
		{
			CManager::GetFade()->SetFade(CManager::MODE_TITLE);
		}
		//else
		//{
		//	m_pPolygon->BindTexture(m_pTexture[m_nNumTutorial]);
		//}
	}
	//if (CManager::GetKeyboard()->GetKeyTrigger(DIK_BACKSPACE) /*||
	//	CManager::GetJoypad()->GetJoystickTrigger(2, 0)*/)
	//{
	//	m_nNumTutorial--;
	//	if (m_nNumTutorial < 0)
	//	{
	//		m_nNumTutorial = 0;
	//	}

	//	m_pPolygon->BindTexture(m_pTexture[m_nNumTutorial]);
	//}

	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}
}

//=============================
// �`�揈��
//=============================
void CTutorial::Draw(void)
{
	// �|���S���̕`�揈��
	m_pPolygon->Draw();

	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}
}

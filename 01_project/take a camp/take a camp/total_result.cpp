////////////////////////////////////////////////////
//
//    �g�[�^�����U���g�N���X�̏���[total_result.cpp]
//    Author : �g�c �I�l
//
////////////////////////////////////////////////////


//=============================
// �C���N���[�h
//=============================
#include "manager.h"
#include "total_result.h"
#include "total_score.h"
#include "keyboard.h"
#include "mouse.h"
#include "fade.h"
#include "scene2d.h"
#include "camera_charaselect.h"
#include "polygon.h"
#include "stage_texture.h"

//**********************************
// �}�N����`
//**********************************
#define BG_COLOR D3DXCOLOR(0.4f,0.4f,0.4f,0.6f)

//**********************************
// �ÓI�����o�ϐ��錾
//**********************************

//=============================
// �R���X�g���N�^
//=============================
CTotalResult::CTotalResult()
{
	m_pBg			= NULL;
	m_pScoreKill	= NULL;
}

//=============================
// �f�X�g���N�^
//=============================
CTotalResult::~CTotalResult()
{
}

//=============================
// �N���G�C�g
//=============================
CTotalResult * CTotalResult::Create(void)
{
	// �������̊m��
	CTotalResult *pTotalResult = NULL;
	pTotalResult = new CTotalResult;
	
	//NULL�`�F�b�N
	if (pTotalResult != NULL)
	{
		// ������
		pTotalResult->Init();

	}
	return pTotalResult;
}

//=============================
// ����������
//=============================
HRESULT CTotalResult::Init(void)
{
	// �w�i�̐���
	m_pBg = CScene2d::Create();
	m_pBg->SetSize(D3DXVECTOR3(SCREEN_WIDTH - 15.0f, SCREEN_HEIGHT - 20.0f, 0.0f));
	m_pBg->SetColor(BG_COLOR);
	m_pBg->SetPriority(OBJTYPE_BG);

	// �J��������
	CManager::SetCamera(CCharaSelectCamera::Create());

	//�X�R�A����
	CTotalScore::Create();

	m_pBackGroundPolygon = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f));
	m_pBackGroundPolygon->BindTexture(CStageTexture::GetStateTexturePointa()->GetTexture());
	return S_OK;
}

//=============================
// �I������
//=============================
void CTotalResult::Uninit(void)
{
	if (m_pBackGroundPolygon != NULL)
	{
		m_pBackGroundPolygon->Uninit();
		delete m_pBackGroundPolygon;
		m_pBackGroundPolygon = NULL;
	}

	// �J�����N���X�̉������
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
		pCamera = NULL;
	}

	// �J������
	Release();
}


//=============================
// �X�V����
//=============================
void CTotalResult::Update(void)
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN) ||
		CManager::GetMouse()->GetMouseTrigger(0) /*||
												 CManager::GetJoypad()->GetJoystickTrigger(3, 0) ||
												 CManager::GetJoypad()->GetJoystickTrigger(11, 0)*/)
	{
		// �f�o�b�O�p��ʑJ�ڃR�}���h
		CManager::GetFade()->SetFade(CManager::MODE_TITLE);
	}

}

//=============================
// �`�揈��
//=============================
void CTotalResult::Draw(void)
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}

	m_pBackGroundPolygon->Draw();
}


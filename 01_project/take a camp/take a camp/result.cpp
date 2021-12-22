////////////////////////////////////////////////////
//
//    ���U���g�N���X�̏���[result.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////


//=============================
// �C���N���[�h
//=============================
#include "result.h"
#include "manager.h"
#include "renderer.h"
#include "keyboard.h"
#include "mouse.h"
#include "joypad.h"
#include "fade.h"
#include "result_graph.h"
#include "effect_result_explosion.h"
#include "stage_texture.h"
#include "polygon.h"
#include "camera_charaselect.h"
#include "confetti.h"

//**********************************
// �}�N����`
//**********************************
#define PLAYER_SPACE (150.0f) //�@�v���C���[�ʒu�̊Ԋu
#define PLAYER_POS_Z (100.0f) // �v���C���[��Z�ʒu
#define PLAYER_FALL_COUNT (300) // �v���C���[��������J�E���g��
#define RANK_UI_HEGHT (-50) // �����L���O��UI�v���C���[����̈ʒu
#define RESULT_BOARD_SPACE (320.0f)

#define LOGO_POS (D3DXVECTOR3(SCREEN_WIDTH/2, 100.0f, 0.0f))
#define LOGO_SIZE (D3DXVECTOR3(300.0f,75.0f,0.0f))
#define OBJ_BASE_POS_Y (2000.0f)
#define CAMERA_POS_V D3DXVECTOR3(0.0f, 0.0f, 30.0f)
#define CAMERA_POS_R D3DXVECTOR3(0.0f, 2.0f, 0.0f)

//**********************************
// �ÓI�����o�ϐ��錾
//**********************************

//=============================
// �R���X�g���N�^
//=============================
CResult::CResult()
{
	m_fFloat = 0.0f;
	m_pGraph = NULL;
	m_pBackGroundPolygon = NULL;
}

//=============================
// �f�X�g���N�^
//=============================
CResult::~CResult()
{
}

//=============================
// �N���G�C�g
//=============================
CResult * CResult::Create(void)
{
	// �������̊m��
	CResult *pResult = new CResult;
	// ������
	pResult->Init();
	return pResult;
}

//=============================
// ����������
//=============================
HRESULT CResult::Init(void)
{
	//�@�O���t�̐���
	m_pBackGroundPolygon = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f), D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f));
	m_pBackGroundPolygon->BindTexture(CStageTexture::GetStateTexturePointa()->GetTexture());

	m_pGraph = CResultGraph::Create();

	CManager::SetCamera(CCharaSelectCamera::Create());
	CManager::GetCamera()->SetPosV(CAMERA_POS_V);
	CManager::GetCamera()->SetPosR(CAMERA_POS_R);

	return S_OK;
}

//=============================
// �I������
//=============================
void CResult::Uninit(void)
{
	if (m_pBackGroundPolygon != NULL)
	{
		m_pBackGroundPolygon->Uninit();
		delete m_pBackGroundPolygon;
		m_pBackGroundPolygon = NULL;
	}
	CManager::SetCamera(NULL);

	// �J������
	Release();
}


//=============================
// �X�V����
//=============================
void CResult::Update(void)
{
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN) ||
		CManager::GetMouse()->GetMouseTrigger(0) /*||
		CManager::GetJoypad()->GetJoystickTrigger(3, 0) ||
		CManager::GetJoypad()->GetJoystickTrigger(11, 0)*/)
	{
		// �f�o�b�O�p��ʑJ�ڃR�}���h
		CManager::GetFade()->SetFade(CManager::MODE_TOTAL_RESULT);
	}
}

//=============================
// �`�揈��
//=============================
void CResult::Draw(void)
{
	CManager::GetCamera()->SetCamera();
	m_pBackGroundPolygon->Draw();
}
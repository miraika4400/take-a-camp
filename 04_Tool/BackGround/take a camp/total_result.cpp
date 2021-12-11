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

//**********************************
// �}�N����`
//**********************************

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
	m_pBg->SetSize(D3DXVECTOR3(SCREEN_WIDTH - 15, SCREEN_HEIGHT - 20, 0.0f));
	m_pBg->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.6f));
	m_pBg->SetPriority(OBJTYPE_BG);

	//�X�R�A����
	CTotalScore::Create();
	return S_OK;
}

//=============================
// �I������
//=============================
void CTotalResult::Uninit(void)
{
	// �J������
	Release();
}


//=============================
// �X�V����
//=============================
void CTotalResult::Update(void)
{
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

}


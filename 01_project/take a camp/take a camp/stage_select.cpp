////////////////////////////////////////////////////
//
//    �L�����I���N���X�̏���[chara_select.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "stage_select.h"
#include "keyboard.h"
#include "joypad.h"
#include "manager.h"
#include "fade.h"
#include "stage_name_ui.h"
#include "chara_select.h"
#include "player.h"
#include "camera_base.h"
#include "light.h"
#include "bg.h"
#include "map.h"
#include "resource_map.h"
#include "stage_select_polygon.h"

//=============================
// �}�N����`
//=============================
#define WAIT_TIME 20

//=============================
// �ÓI�����o�ϐ��錾
//=============================
CMapManager::MAP_TYPE CStageSelect::m_selectStageType = CMapManager::MAP_TYPE_1;

//=============================
// �R���X�g���N�^
//=============================
CStageSelect::CStageSelect()
{
	m_pStageName = NULL;
	m_pStagePolygon = NULL;
	m_selectStageType = CMapManager::MAP_TYPE_1;
	m_nWaitCnt = 0;
}

//=============================
// �f�X�g���N�^
//=============================
CStageSelect::~CStageSelect()
{
}

//=============================
// �N���G�C�g
//=============================
CStageSelect * CStageSelect::Create(void)
{
	// �������̊m��
	CStageSelect *pMode = new CStageSelect;
	// ������
	pMode->Init();

	return pMode;
}

//=============================
// ����������
//=============================
HRESULT CStageSelect::Init(void)
{
	// �J�����N���X�̐���
	CManager::SetCamera(CCamera::Create());

	// �X�e�[�W���|���S���̐���
	m_pStageName = CStageNameUi::Create(m_selectStageType);

	SetObject();

	return S_OK;
}

//=============================
// �I������
//=============================
void CStageSelect::Uninit(void)
{
	// �J�����N���X�̉������
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		CManager::SetCamera(NULL);
	}

	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CStageSelect::Update(void)
{
	SelectStageType();

	if (m_pStageName != NULL) m_pStageName->SetSelectNum(m_selectStageType);

	if (m_nWaitCnt > 0) m_nWaitCnt--;

	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

#ifdef _DEBUG

	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F1) || CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
	{
		CGame::SetMapType(m_selectStageType);
		CManager::GetFade()->SetFade(CManager::MODE_GAME);
	}

#endif
}

//=============================
// �`�揈��
//=============================
void CStageSelect::Draw(void)
{
	CCamera * pCamera = CManager::GetCamera();
	// �J�����̃Z�b�g
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}
}

//=============================
// �I�u�W�F�N�g�̐ݒu
//=============================
void CStageSelect::SetObject(void)
{
	// �ޔ�
	OutList();

	m_pStageName->OutList();

	// �ޔ��������̈ȊO�S�I�u�W�F�N�g�̍폜
	ReleaseAll();

	// �X�e�[�W�Z���N�g�̐���
	m_pStagePolygon = CStageSelectPolygon::Create();
	// �v���C�I���e�B�̍Đݒ�
	SetPriority(OBJTYPE_NONE);
	m_pStageName->SetPriority(OBJTYPE_UI_2);

	// �w�i�̐���
	CBg::Create();
	CModel::Create(D3DXVECTOR3(0.0f, -13.0f, 0.0f), CResourceModel::MODEL_DESK, D3DXVECTOR3(0.4f, 0.4f, 0.4f))->SetPriority(OBJTYPE_MAP);

	CCharaSelect::Entry_Data noneData = {};
	CCharaSelect::Entry_Data aSaveData[MAX_PLAYER] = {};
	// �L�����f�[�^�̖�����
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		aSaveData[nCnt] = CCharaSelect::GetEntryData(nCnt);
		CCharaSelect::SetEntryData(nCnt, noneData);
	}

	// �}�b�v�̐���
	CMap::Create(m_selectStageType);

	// �L�����f�[�^��߂�
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++) CCharaSelect::SetEntryData(nCnt, aSaveData[nCnt]);
}

//=============================
// �X�e�[�W�^�C�v�̑I������
//=============================
void CStageSelect::SelectStageType(void)
{
	if (m_nWaitCnt > 0) return;

	CCharaSelect::Entry_Data entryData = {};
	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		entryData = CCharaSelect::GetEntryData(nCntPlayer);
		// �G���g���[���Ă���v���C���[(1P)�f�[�^�̎擾
		if (entryData.bEntry) break;
		else if (nCntPlayer == (MAX_PLAYER - 1))
		{
			CManager::GetFade()->SetFade(CManager::MODE_GAME); 
			return;
		}
	}

	CInputJoypad * pJoy = CManager::GetJoypad();
	CInputKeyboard *pKey = CManager::GetKeyboard();
	// �X�e�B�b�N�̍��W
	D3DXVECTOR2 StickPos = pJoy->GetStickState(pJoy->PAD_LEFT_STICK, entryData.nControllNum);

	int nStageType = m_selectStageType;
	// �L�����̑I������
	if (!entryData.bController && pKey->GetKeyPress(CPlayer::GetPlayerControllKey(entryData.nControllNum, CPlayer::KEY_LEFT))
		|| entryData.bController && ((StickPos.x < 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoy->GetButtonState(XINPUT_GAMEPAD_DPAD_LEFT, pJoy->BUTTON_PRESS, entryData.nControllNum)))
	{// �i��
		nStageType--;
		if (nStageType < 0) nStageType = SELECT_STAGE_NUM - 1;
		m_selectStageType = (CMapManager::MAP_TYPE)nStageType;

		SetObject();

		m_nWaitCnt = WAIT_TIME;
		return;
	}
	if (!entryData.bController && pKey->GetKeyPress(CPlayer::GetPlayerControllKey(entryData.nControllNum, CPlayer::KEY_RIGHT))
		|| entryData.bController && ((StickPos.x > 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoy->GetButtonState(XINPUT_GAMEPAD_DPAD_RIGHT, pJoy->BUTTON_PRESS, entryData.nControllNum)))
	{// �߂�

		nStageType++;
		if (nStageType >= SELECT_STAGE_NUM) nStageType = 0;
		m_selectStageType = (CMapManager::MAP_TYPE)nStageType;

		SetObject();

		m_nWaitCnt = WAIT_TIME;

		return;
	}

	m_nWaitCnt = 0;
}

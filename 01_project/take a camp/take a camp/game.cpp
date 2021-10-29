////////////////////////////////////////////////////
//
//    �Q�[���N���X�̏���[game.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "game.h"
#include "number.h"
#include "score.h" 
#include "mouse.h"
#include "camera_tps.h"
#include "light.h"
#include "fade.h"
#include "keyboard.h"
#include "particle.h"
#include "time.h"
#include "joypad.h"
#include "result.h"
#include "bg.h"
#include "player.h"
#include "map.h"
#include "tile.h"
#include "debug_log.h"
#include "color_manager.h"
#include "color_tile.h"

//=============================
// �}�N����`
//=============================

//=============================
// �ÓI�����o�ϐ��錾
//=============================
CRuleManager* CGame::m_pRuleManager = NULL;                       // ���[���}�l�[�W���[�N���X
CMap* CGame::m_pMap = NULL;			                              // �X�e�[�W�N���X�|�C���^
CMapManager::MAP_TYPE CGame::m_MapType = CMapManager::MAP_TYPE_1; // �}�b�v�^�C�v

//=============================
// �R���X�g���N�^
//=============================
CGame::CGame()
{
	// �ϐ��̃N���A
}

//=============================
// �f�X�g���N�^
//=============================
CGame::~CGame()
{
}

//=============================
// �N���G�C�g
//=============================
CGame * CGame::Create(void)
{
	// �������̊m��
	CGame *pGame = new CGame;
	// ������
	pGame->Init();
	return pGame;
}

//=============================
// ����������
//=============================
HRESULT CGame::Init(void)
{
	// �|�[�Y�̏�����
	CManager::SetActivePause(false);

	// �}�l�[�W���[�̔ԍ��̃��Z�b�g
	GET_COLORMANAGER->UseNumReset();

	CManager::SetCamera(CTpsCamera::Create());

	// �w�i�̐���
	CBg::Create();
	
	//�X�e�[�W����
	m_pMap = CMap::Create(m_MapType);
	
	// ���C�g�N���X�̐���
	CManager::SetLight();

	CTime::Create();

	return S_OK;
}

//=============================
// �I������
//=============================
void CGame::Uninit(void)
{
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
void CGame::Update(void)
{

	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

#ifdef _DEBUG
	// �f�o�b�O�p��ʑJ�ڃR�}���h
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F1))
	{
		CManager::GetFade()->SetFade(CManager::MODE_RESULT);
	}
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F2))
	{
		CManager::SetCamera(CTpsCamera::Create());
	}
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F3))
	{
		CManager::SetCamera(CCamera::Create());
	}

	CColorTile::CountColorTile();
	CDebugLog::Init();
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(0), CColorTile::GetTileNum(0, 1), CColorTile::GetTileNum(0, 2), CColorTile::GetTileNum(0, 3));
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(1), CColorTile::GetTileNum(1, 1), CColorTile::GetTileNum(1, 2), CColorTile::GetTileNum(1, 3));
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(2), CColorTile::GetTileNum(2, 1), CColorTile::GetTileNum(2, 2), CColorTile::GetTileNum(2, 3));
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(3), CColorTile::GetTileNum(3, 1), CColorTile::GetTileNum(3, 2), CColorTile::GetTileNum(3, 3));
#endif // _DEBUG

}

//=============================
// �`�揈��
//=============================
void CGame::Draw(void)
{
	CCamera * pCamera = CManager::GetCamera();
    // �J�����̃Z�b�g
    if (pCamera != NULL)
    {
		pCamera->SetCamera();
    }
}
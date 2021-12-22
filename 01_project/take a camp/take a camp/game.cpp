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
#include "kill_count.h"
#include "paintnum.h"
#include "player_model.h"
#include "building.h"
#include "game_start.h"
#include "stage_texture.h"

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
	m_pGameStart = NULL;
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

	CManager::SetCamera(CCamera::Create());

	// �w�i�̐���
	CBg::Create();
	CModel::Create(D3DXVECTOR3(0.0f, -13.0f, 0.0f), CResourceModel::MODEL_DESK,D3DXVECTOR3(0.4f, 0.4f, 0.4f))->SetPriority(OBJTYPE_MAP);
	//�X�e�[�W����
	m_pMap = CMap::Create(m_MapType);
	
	// �v���C���[���Ƃ̐F�̊����̕\��
	CPaintnum::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 25.0f, 0.0f), D3DXVECTOR3(SCREEN_WIDTH, 50.0f, 0.0f));
	// �������ԃN���X
	//CTime::Create();
	CBuilding::Load();
	// ���C�g�̌����̐ݒ�
	CManager::GetLight()->SetDir(LIGHT_DIR_BASE);
	// ready go�̐���
	m_pGameStart=CGameStart::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, START_UI_POS_Y, 0.0f), START_UI_SIZE);

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
	CKillCount::AddTotalKill();
	CColorTile::CountColorTile();

	CDebugLog::Init();
	CDebugLog::Print("1P:Kill:%d\n", CKillCount::GetTotalKill(0));
	CDebugLog::Print("2P:Kill:%d\n", CKillCount::GetTotalKill(1));
	CDebugLog::Print("3P:Kill:%d\n", CKillCount::GetTotalKill(2));
	CDebugLog::Print("4P:Kill:%d\n", CKillCount::GetTotalKill(3));

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

	// �X�e�[�W�̏�������
	CStageTexture::GetStateTexturePointa()->DrawStageInTex();
}
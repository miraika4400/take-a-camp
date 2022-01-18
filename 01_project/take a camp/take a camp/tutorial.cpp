//====================================================
//
// tutorial�̏���[tutorial.cpp]
// Author:�ɓ��@�z��
//
//====================================================

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
#include "light.h"
#include "bg.h"
#include "text.h"
#include "color_tile.h"
#include "chara_select.h"
#include "player.h"
#include "debug_log.h"
#include "kill_count.h"
#include "resource_text.h"
#include "paintnum.h"
#include "skill_gauge.h"
#include "all_skill_gauge.h"
#include "map.h"
#include "resource_map.h"
#include "dummy.h"

//=============================
// �}�N����`
//=============================
#define TARGET_PAINT (10)															// �h�閇��
#define TARGET_OVERPAINT (10)														// �d�˓h�肷�閇��
#define TARGET_KILL (3)																// �X�L���œ|���l��
#define ADD_TEXTWINDOWRANGE (10.0f)													// �e�L�X�g�E�B���h�E�͈̔͂����Z����l
#define TEXTWINDOW_COLOR (D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.2f))						// �e�L�X�g�E�B���h�E�̐F
#define TEXTSHOWTIME (90)															// �e�L�X�g��\�����鎞��
#define TEXTTEXTURE_SIZE (D3DXVECTOR3(640.0f, 60.0f, 0.0f))							// �e�L�X�g�̃e�N�X�`���̃T�C�Y
#define TEXT_POS (D3DXVECTOR3(TEXTTEXTURE_SIZE.x / 4.0f, 100.0f, 0.0f))				// �e�L�X�g�̃e�N�X�`���̍��W
#define TEXT_ADD_POS (D3DXVECTOR3(0.0f, TEXTTEXTURE_SIZE.y / 2.0f, 0.0f))			// �e�L�X�g�̃e�N�X�`���̉��Z������W
#define CHECKTEXTURE_SIZE (D3DXVECTOR3(158.0f, 122.0f, 0.0f))						// �`�F�b�N�}�[�N�̃T�C�Y
#define CHECK_POS (D3DXVECTOR3(TEXTTEXTURE_SIZE.x / 2.0f - 17.0f, 100.0f, 0.0f))	// �`�F�b�N�}�[�N�̍��W
#define CHECK_ADD_POS (D3DXVECTOR3(0.0f, 7.0f, 0.0f))								// �`�F�b�N�}�[�N�̂̉��Z����l

//=============================
// �R���X�g���N�^
//=============================
CTutorial::CTutorial()
{
	m_pMap = nullptr;
	m_pTextWindow = nullptr;
	ZeroMemory(&m_pTaskTex, sizeof(m_pTaskTex));
	ZeroMemory(&m_pCheckTex, sizeof(m_pCheckTex));
	m_pText = nullptr;
	m_bTask = false;
	m_Tutorialphase = PHASE_PAINT;
	m_nTextNum = 0;
	m_bNextText = false;
	m_bTextEnd = false;
	ZeroMemory(&m_nCurTaskNum, sizeof(m_nCurTaskNum));
	ZeroMemory(&m_nOldCurTaskNum, sizeof(m_nOldCurTaskNum));
	m_nTextShowTime = 0;
}

//=============================
// �f�X�g���N�^
//=============================
CTutorial::~CTutorial()
{
	if (m_pTextWindow)
	{
		// �|���S���̏I������
		m_pTextWindow->Uninit();

		// �������̉��
		delete m_pTextWindow;
		m_pTextWindow = NULL;
	}

	for (int nCount = 0; nCount < (int)PHASE_FINISH; nCount++)
	{
		// �|���S���̏I������
		m_pTaskTex[nCount]->Uninit();

		// �������̉��
		delete m_pTaskTex[nCount];
		m_pTaskTex[nCount] = NULL;


		m_pCheckTex[nCount]->Uninit();
		delete m_pCheckTex[nCount];
		m_pCheckTex[nCount] = NULL;
	}
}

//=============================
// �N���G�C�g
//=============================
CTutorial * CTutorial::Create()
{
	// �������̊m��
	CTutorial *pTitle = new CTutorial;

	// ������
	pTitle->Init();

	// �ꎞ�I�Ƀv���C�I���e�B�[��UI�ɂ���
	pTitle->SetPriority(OBJTYPE_UI_2);
	return pTitle;
}

//=============================
// ����������
//=============================
HRESULT CTutorial::Init()
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �w�i�̐ݒ�
	CBg::Create();

	// �J��������
	CManager::SetCamera(CCamera::Create());

	// �}�b�v����
	m_pMap = CMap::Create(CMapManager::MAP_TYPE_TUTORIAL);

	// �e�L�X�g�\������Ƃ��̔w�i�����
	if (!m_pTextWindow)
	{
		m_pTextWindow = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f),
			TEXTWINDOW_COLOR);
	}

	// �_�~�[�����
	DummyCreate();

	// �v���C���[�������Ȃ��������瓮����悤�ɂ���
	StartPlayer(true);

	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();
	// BGM��~
	pSound->Stop(CSound::LABEL_BGM_SELECT);
	// BGM�Đ�
	pSound->Play(CSound::LABEL_BGM_GAME);

	for (int nCount = 0; nCount < (int)PHASE_FINISH; nCount++)
	{
		// �^�X�N�̃e�L�X�g����
		m_pTaskTex[nCount] = CPolygon::Create(TEXT_POS + TEXT_ADD_POS * (float)nCount, TEXTTEXTURE_SIZE / 2.0f, D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
		m_pTaskTex[nCount]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TUTRIAL_TEXT));

		D3DXVECTOR2 uv[NUM_VERTEX];
		uv[1] = D3DXVECTOR2(1.0f, nCount * 0.25f);
		uv[0] = D3DXVECTOR2(0.0f, nCount * 0.25f);
		uv[2] = D3DXVECTOR2(0.0f, 0.25f + nCount * 0.25f);
		uv[3] = D3DXVECTOR2(1.0f, 0.25f + nCount * 0.25f);
		m_pTaskTex[nCount]->SetTextureUV(uv);

		// �`�F�b�N�}�[�N�̐���
		m_pCheckTex[nCount] = CPolygon::Create(CHECK_POS - CHECK_ADD_POS + TEXT_ADD_POS * (float)nCount, CHECKTEXTURE_SIZE / 5.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		m_pCheckTex[nCount]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CHECK));
	}
	return S_OK;
}

//=============================
// �I������
//=============================
void CTutorial::Uninit()
{
	// �J�����N���X�̉������
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera)
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
void CTutorial::Update()
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->Update();
	}

	// �e�L�X�g�\������Ƃ��̔w�i�̃Z�b�g
	SetTextWindow();

	// �e�L�X�g�\�����I�������
	if (m_bTextEnd)
	{
		// �v���C���[��������悤�ɂ���
		StartPlayer(true);

		// �e�L�X�g�E�B���h�E�̐F�𖳐F��
		m_pTextWindow->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));

		// �t�F�[�Y���Ƃɏ�����ς���
		switch (m_Tutorialphase)
		{
		case PHASE_PAINT: // �h��t�F�[�Y
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CColorTile::GetTileNum(nCount, 1), TARGET_PAINT, nCount);
			}
			m_pTaskTex[PHASE_PAINT]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			break;

		case PHASE_OVERPAINT: // �d�˓h�肷��t�F�[�Y
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CColorTile::GetTileNum(nCount, 3), TARGET_OVERPAINT, nCount);
			}
			m_pTaskTex[PHASE_OVERPAINT]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

			// �O�̃^�X�N�̃e�L�X�g�ƃ`�F�b�N�}�[�N������������
			SetTexInvisible(PHASE_OVERPAINT);
			break;

		case PHASE_ATTACK: // ���������U������t�F�[�Y
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CKillCount::GetTotalKill(nCount), TARGET_KILL, nCount);
			}
			m_pTaskTex[PHASE_ATTACK]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

			// �O�̃^�X�N�̃e�L�X�g�ƃ`�F�b�N�}�[�N������������
			SetTexInvisible(PHASE_ATTACK);
			break;

		case PHASE_FINALATTACK: // ��������K�E�Z�ōU������t�F�[�Y
			for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
			{
				CheckTaskClear(CKillCount::GetTotalKill(nCount), TARGET_KILL, nCount);
			}
			m_pTaskTex[PHASE_FINALATTACK]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

			// �O�̃^�X�N�̃e�L�X�g�ƃ`�F�b�N�}�[�N������������
			SetTexInvisible(PHASE_FINALATTACK);

			// �K�E�Z�t�F�[�Y�̓Q�[�W���펞�ő��
			Max_Playergauge();
			break;

		case PHASE_FINISH: // ���R�t�F�[�Y
			// �O�̃^�X�N�̃e�L�X�g�ƃ`�F�b�N�}�[�N������������
			SetTexInvisible(PHASE_FINISH);
			break;

		default:
			break;
		}

	}

	// �e�L�X�g�\��
	if (!m_bNextText)
	{
		// �e�L�X�g�̍X�V
		UpdateText();

		// �E�C���h�E�̔w�i�̐F�̐ݒ�
		m_pTextWindow->SetColor(TEXTWINDOW_COLOR);

		// �\�����鎞�Ԃ̐ݒ�
		m_nTextShowTime = TEXTSHOWTIME;

		// �v���C���[���s���s�\�ɂ���
		StartPlayer(false);
	}
	// �ꕶ�\���I������
	else if (m_pText->GetAllShowText() && !m_bTextEnd)
	{
		// �\�����鎞�Ԃ̌��Z
		m_nTextShowTime--;

		// �e�L�X�g��\�����鎞�Ԃ�0�ɂȂ�����
		if (m_nTextShowTime <= 0)
		{
			// �e�L�X�g�̃N���A�Ǝ��̃e�L�X�g�\��
			m_pText->ClearText();
			m_bNextText = false;
		}
	}

	// �^�C���̐F�̃J�E���g
	CKillCount::AddTotalKill();
	CColorTile::CountColorTile();

#ifdef _DEBUG
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_F1))
	{
		CManager::GetFade()->SetFade(CManager::MODE_TITLE);
	}

	CDebugLog::Init();
	CDebugLog::Print("1P:Kill:%d\n", CKillCount::GetTotalKill(0));
	CDebugLog::Print("2P:Kill:%d\n", CKillCount::GetTotalKill(1));
	CDebugLog::Print("3P:Kill:%d\n", CKillCount::GetTotalKill(2));
	CDebugLog::Print("4P:Kill:%d\n", CKillCount::GetTotalKill(3));

	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(0), CColorTile::GetTileNum(0, 1), CColorTile::GetTileNum(0, 2), CColorTile::GetTileNum(0, 3));
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(1), CColorTile::GetTileNum(1, 1), CColorTile::GetTileNum(1, 2), CColorTile::GetTileNum(1, 3));
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(2), CColorTile::GetTileNum(2, 1), CColorTile::GetTileNum(2, 2), CColorTile::GetTileNum(2, 3));
	CDebugLog::Print("��:%d(��:%d,��:%d,�O:%d)\n", CColorTile::GetTileNum(3), CColorTile::GetTileNum(3, 1), CColorTile::GetTileNum(3, 2), CColorTile::GetTileNum(3, 3));

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		CDebugLog::Print("���݂̃^�X�N���Ƃ̐�:%d\n", m_nCurTaskNum[nCount]);
	}
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		CDebugLog::Print("1�t���[���O�̃^�X�N���Ƃ̐�:%d\n", m_nOldCurTaskNum[nCount]);
	}
	CDebugLog::Print("�`���[�g���A��:%d\n", m_Tutorialphase);
#endif // _DEBUG
}

//=============================
// �`�揈��
//=============================
void CTutorial::Draw()
{
	// �J�����N���X�X�V����
	CCamera * pCamera = CManager::GetCamera();
	if (pCamera != NULL)
	{
		pCamera->SetCamera();
	}

	if (m_pTextWindow != NULL)
	{
		// �|���S���̕`�揈��
		m_pTextWindow->Draw();
	}

	for (int nCount = 0; nCount < (int)PHASE_FINISH; nCount++)
	{
		if (m_pTaskTex[nCount] != NULL)
		{
			m_pTaskTex[nCount]->Draw();
		}

		if (m_pCheckTex[nCount] != NULL)
		{
			m_pCheckTex[nCount]->Draw();
		}
	}
}

//=============================
// �^�X�N�����������̂��`�F�b�N���鏈��
//=============================
void CTutorial::CheckTaskClear(const int nCurTaskNum, const int nTargetNum, const int nPlayernum)
{
	// ���݂̃^�X�N���Ƃ̐���1�t���[���O�̐����ׂ�
	if (nCurTaskNum > m_nOldCurTaskNum[nPlayernum])
	{
		m_nCurTaskNum[nPlayernum] += nCurTaskNum - m_nOldCurTaskNum[nPlayernum];
	}

	int nAllTaskNum = 0;

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		nAllTaskNum += m_nCurTaskNum[nCount];
	}

	// �^�X�N���Ƃ̏����Ŏ󂯎�������Ƃ��̖ڕW�����ׂ�
	if (nAllTaskNum >= nTargetNum)
	{
		m_bTask = true;
	}

	// ���݂̃^�X�N���Ƃ̐���1�t���[���O�̐��ɂ���
	m_nOldCurTaskNum[nPlayernum] = nCurTaskNum;

	// �^�X�N����������������v���Ă���
	if (m_bTask)
	{
		// �`�F�b�N�}�[�N�̕\��
		if (m_pCheckTex[m_Tutorialphase])
		{
			m_pCheckTex[m_Tutorialphase]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}

		// ���̃e�L�X�g��\������
		m_bNextText = false;

		// ���̃t�F�[�Y�Ɉڍs����
		NextPhase();

		// �^�X�N�̏�����
		m_bTask = nullptr;
		ZeroMemory(&m_nCurTaskNum, sizeof(m_nCurTaskNum));

		// �|���������K�E�Z�ƍU���œ������Ă���̂�
		// �K�E�Z�t�F�[�Y�ȊO��1�t���[���O�̐���������
		if (m_Tutorialphase != PHASE_FINALATTACK)
		{
			ZeroMemory(&m_nOldCurTaskNum, sizeof(m_nOldCurTaskNum));
		}
	}
}

//============================================
// �e�L�X�g�̕\��
//============================================
void CTutorial::UpdateText(void)
{
	if (!m_pText)
	{
		m_pText = CText::Create(D3DXVECTOR2(SCREEN_WIDTH / 2.0f, 600.0f), D3DXVECTOR2(50.0f, 20.0f), CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	}
	else
	{
		// ���\�[�X�e�L�X�g�̃|�C���^�擾
		CResourceText * pResourceText = CResourceText::GetResourceText();

		while (!pResourceText->GetMapString(m_nTextNum).empty()
			|| !pResourceText->GetMapString(m_nTextNum + 1).empty())
		{
			if (pResourceText->GetMapString(m_nTextNum).find("TEXT_DATASET") == 0)
			{
				m_bTextEnd = false;
			}

			if (!m_bTextEnd)
			{
				while (pResourceText->GetMapString(m_nTextNum).find("END_TEXT_DATASET") != 0)
				{
					std::string str = CResourceText::GetResourceText()->GetMapString(m_nTextNum);

					if (pResourceText->GetMapString(m_nTextNum).find("POS") == 0)
					{
						str = str.substr(6);

						D3DXVECTOR2 Pos;
						ZeroMemory(&Pos, sizeof(Pos));
						sscanf(str.c_str(), "%f %f", &Pos.x, &Pos.y);
						m_pText->SetPos(Pos);
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("WINDOWRANGE") == 0)
					{
						str = str.substr(14);

						D3DXVECTOR2 Windowrange[2];
						ZeroMemory(&Windowrange, sizeof(Windowrange));
						sscanf(str.c_str(), "%f %f %f %f", &Windowrange[0].x, &Windowrange[0].y, &Windowrange[1].x, &Windowrange[1].y);
						m_pText->SetWindowRange(Windowrange);
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("FONTSIZE") == 0)
					{
						str = str.substr(11);

						D3DXVECTOR2 FontSize;
						ZeroMemory(&FontSize, sizeof(FontSize));
						sscanf(str.c_str(), "%f %f", &FontSize.x, &FontSize.y);
						m_pText->SetFontSize(FontSize);
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("COLOR") == 0)
					{
						str = str.substr(8);

						D3DXCOLOR color;
						ZeroMemory(&color, sizeof(color));
						sscanf(str.c_str(), "%f %f %f %f", &color.r, &color.g, &color.b, &color.a);
						m_pText->SetColor(color);
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("SAY") == 0)
					{
						str = str.substr(6);
						m_pText->AddText(str);
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("NR") == 0)
					{
						m_pText->AddText("\n");
					}
					else if (pResourceText->GetMapString(m_nTextNum).find("ENTER") == 0)
					{
						m_nTextNum++;
						m_bNextText = true;
						return;
					}
					m_nTextNum++;
				}
				m_bTextEnd = true;
				m_bNextText = true;
				m_nTextNum++;
				return;
			}
			m_nTextNum++;
		}
	}
}

//============================================
// ���̃t�F�[�Y�ւ̈ڍs
//============================================
void CTutorial::NextPhase(void)
{
	int nTutorialphase = (int)m_Tutorialphase;
	nTutorialphase++;
	m_Tutorialphase = (TUTORIALPHASE)nTutorialphase;
}

//============================================
// �v���C���[�X�V�̃t���O��ς���
//============================================
void CTutorial::StartPlayer(bool bUpdate)
{
	CPlayer*pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		pPlayer->SetUpdateFlag(bUpdate);
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//============================================
// �v���C���[�̃Q�[�W���ő�ɂ���
//============================================
void CTutorial::Max_Playergauge(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer)
	{
		pPlayer->GetAllSkillgauge()->GetSkillgaugeStencil()->SkillGauge_Max();
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//============================================
// �_�~�[����鏈��
//============================================
void CTutorial::DummyCreate(void)
{
	CMapManager::MAP_DATA MapData = m_pMap->GetMapData();

	//�}�b�v�f�[�^�����邩
	if (&MapData != NULL)
	{
		for (int nBlockY = 0; nBlockY < MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				// �v���C���[�̐���
				switch (MapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case CMapManager::BLOCK_TYPE_DUMMY:	//1P�X�^�[�g�ʒu
					CDummy::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
					break;

				default:
					break;
				}
			}
		}
	}
}

//============================================
// �e�L�X�g�\������Ƃ��̔w�i�̃Z�b�g
//============================================
void CTutorial::SetTextWindow(void)
{
	// ���_���W�̐ݒ�
	D3DXVECTOR3 Pos[NUM_VERTEX];

	if (m_pText)
	{
		// ���_���W�̐ݒ�
		Pos[0] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[0].x - ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[0].y - ADD_TEXTWINDOWRANGE, 0.0f);
		Pos[1] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[1].x + ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[0].y - ADD_TEXTWINDOWRANGE, 0.0f);
		Pos[2] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[0].x - ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[1].y + ADD_TEXTWINDOWRANGE, 0.0f);
		Pos[3] = D3DXVECTOR3(m_pText->GetPos().x + m_pText->GetWindowRange()[1].x + ADD_TEXTWINDOWRANGE, m_pText->GetPos().y + m_pText->GetWindowRange()[1].y + ADD_TEXTWINDOWRANGE, 0.0f);
	}

	if (m_pTextWindow)
	{
		// ���_���Ƃ̏����Z�b�g
		m_pTextWindow->SetVertexPos(Pos);
	}
}

//======================================================
// �O�̃^�X�N�̃e�L�X�g�ƃ`�F�b�N�}�[�N������������
//======================================================
void CTutorial::SetTexInvisible(TUTORIALPHASE TutorialPhaze)
{
	m_pTaskTex[TutorialPhaze - 1]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.8f));
	m_pCheckTex[TutorialPhaze - 1]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.8f));
}
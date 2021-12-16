//===================================================
//
// �h��X�R�A�\������ [score_paint.cpp]
//    Author : �g�c �I�l
//
//====================================================

//**********************************
//�C���N���[�h
//**********************************
#include "total_score.h"
#include "color_manager.h"
#include "chara_select.h"
#include "score.h"
#include "color_tile.h"
#include "kill_count.h"
#include "scene2d.h"
#include "resource_texture.h"
#include "character_polygon.h"

//**********************************
//�C���N���[�h
//**********************************
#define PAINT_POS_Y		(500.0f)
#define KILL_POS_Y		(600.0f)
#define SCORE_SPACE		(SCREEN_WIDTH/4)
#define TOTAL_BG_SIZE	(D3DXVECTOR3(320.0f,650.0f,0.0f))
#define CHARACTER_POLYGON_POS_Y 320.0f
//==================================
// �R���X�g���N�^
//==================================
CTotalScore::CTotalScore()
{
	m_pBg		= NULL;
	m_pKillUi	= NULL;
	m_pTileUI	= NULL;
}

//==================================
// �f�X�g���N�^
//==================================
CTotalScore::~CTotalScore()
{
}

//==================================
// �N���G�C�g
//==================================
CTotalScore * CTotalScore::Create(void)
{
	// �������̊m��
	CTotalScore *pTotalScore = NULL;
	pTotalScore = new CTotalScore;

	//NULL�`�F�b�N
	if (pTotalScore != NULL)
	{
		// ����������
		pTotalScore->Init();
		// �I�u�W�F�N�g�^�C�v�̐ݒ�
		pTotalScore->SetPriority(OBJTYPE_UI_2);
	}
	return pTotalScore;
}

//==================================
// ����������
//==================================
HRESULT CTotalScore::Init(void)
{
	//�J���[�f�[�^�擾
	CColorManager* pColor = CColorManager::GetColorManager();

	// �v���C���[�l���擾
	int nPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// X�������p�ϐ�
	float fPosX = (SCREEN_WIDTH / 2) - (((float)(nPlayerNum - 1) * SCORE_SPACE) / 2);
	
	//�e�N�X�`���ԍ�
	CResourceTexture::TEXTURE_TYPE nTexture[CResourceCharacter::CHARACTER_MAX] =
	{
		CResourceTexture::TEXTURE_RESULT_KNIGHT,
		CResourceTexture::TEXTURE_RESULT_LANCER,
		CResourceTexture::TEXTURE_RESULT_WIZARD,
	};

	// �ő包�������[�v
	for (int nPlayer = 0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		//�v���C�l��������
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			//���ꂼ�ꐶ��
			
			//�w�i
			m_pBg = CScene2d::Create();
			m_pBg->SetPos(D3DXVECTOR3(fPosX, SCREEN_HEIGHT / 2.0f, 0.0f));
			m_pBg->SetSize(TOTAL_BG_SIZE);
			m_pBg->SetColor(pColor->GetIconColor(CCharaSelect::GetEntryData(nPlayer).nColorNum));
			m_pBg->BindTexture(CResourceTexture::GetTexture(nTexture[(int)CCharaSelect::GetEntryData(nPlayer).charaType]));
			m_pBg->SetPriority(OBJTYPE_BG);

			// �L�����|���S���̐���
			CCharacterPolygon*pCharaPolygon = CCharacterPolygon::Create(D3DXVECTOR3(fPosX, CHARACTER_POLYGON_POS_Y, 0.0f));
			pCharaPolygon->SetCharaType(CCharaSelect::GetEntryData(nPlayer).charaType);
			pCharaPolygon->SetRimColor(pColor->GetStepColor(CCharaSelect::GetEntryData(nPlayer).nColorNum, 1));

			//�L���pUI
			m_pTileUI = CScene2d::Create();
			m_pTileUI->SetPos(D3DXVECTOR3(fPosX - 80.0f, PAINT_POS_Y, 0.0f));
			m_pTileUI->SetSize(D3DXVECTOR3(80.0f, 80.0f, 0.0f));
			m_pTileUI->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_RESULT_TILE));
			m_pTileUI->SetPriority(OBJTYPE_UI_2);

			//�h��X�R�A
			CScore::Create(D3DXVECTOR3(fPosX+50.0f, PAINT_POS_Y, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CColorTile::GetTileNum(nPlayer));
			
			//�L���pUI
			m_pKillUi = CScene2d::Create();
			m_pKillUi->SetPos(D3DXVECTOR3(fPosX - 80.0f, KILL_POS_Y, 0.0f));
			m_pKillUi->SetSize(D3DXVECTOR3(80.0f, 80.0f, 0.0f));
			m_pKillUi->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_RESULT_KILL));
			m_pKillUi->SetPriority(OBJTYPE_UI_2);

			//�L���X�R�A
			CScore::Create(D3DXVECTOR3(fPosX+50.0f, KILL_POS_Y, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CKillCount::GetTotalKill(nPlayer));

			fPosX += SCORE_SPACE;
		}
	}


	return S_OK;
}

//==================================
// �I������
//==================================
void CTotalScore::Uninit(void)
{

	// �J������
	Release();
}

//==================================
// �X�V����
//==================================
void CTotalScore::Update(void)
{
}

//==================================
// �`�揈��
//==================================
void CTotalScore::Draw(void)
{
}

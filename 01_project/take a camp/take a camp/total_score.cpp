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
#include "chara_select.h"
#include "score.h"
#include "color_tile.h"
#include "kill_count.h"
#include "scene2d.h"

//**********************************
//�C���N���[�h
//**********************************
#define PAINT_POS_Y		(400.0f)
#define KILL_POS_Y		(500.0f)
#define SCORE_SPACE		(SCREEN_WIDTH/4)
#define TOTAL_BG_SIZE	(D3DXVECTOR3(150.0f,300.0f,0.0f))

//==================================
// �R���X�g���N�^
//==================================
CTotalScore::CTotalScore()
{
	m_pBg = NULL;
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
		pTotalScore->SetPriority(OBJTYPE_UI);
	}
	return pTotalScore;
}

//==================================
// ����������
//==================================
HRESULT CTotalScore::Init(void)
{
	// �v���C���[�l���擾
	int nPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// X�������p�ϐ�
	float fPosX = (SCREEN_WIDTH / 2) - (((float)(nPlayerNum - 1) * SCORE_SPACE) / 2);

	// �ő包�������[�v
	for (int nPlayer = 0; nPlayer<MAX_PLAYER; nPlayer++)
	{
		//�v���C�l��������
		if (CCharaSelect::GetEntryData(nPlayer).bEntry)
		{
			//���ꂼ�ꐶ��
			//�w�i
			m_pBg = CScene2d::Create();
			m_pBg->SetPos(D3DXVECTOR3(fPosX, SCREEN_HEIGHT / 2, 0.0f));
			m_pBg->SetSize(TOTAL_BG_SIZE);
			m_pBg->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f));
			m_pBg->SetPriority(OBJTYPE_BG);

			//�h��X�R�A
			CScore::Create(D3DXVECTOR3(fPosX, PAINT_POS_Y, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CColorTile::GetTileNum(nPlayer));
			//�L���X�R�A
			CScore::Create(D3DXVECTOR3(fPosX, KILL_POS_Y, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), CKillCount::GetTotalKill(nPlayer));

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

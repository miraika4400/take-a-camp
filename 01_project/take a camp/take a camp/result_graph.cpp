//===================================================
//
//    �Q�[�W�N���X�̏���[gage.cpp]
//    Author:���V ����
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "result_graph.h"
#include "gauge.h"
#include "scene2d.h"
#include "color_tile.h"
#include "color_manager.h"
#include "chara_select.h"
#include "keyboard.h"
#include "manager.h"
#include "effect_result_explosion.h"
#include "character_polygon.h"
#include "confetti_factory.h"
#include "kill_count.h"
#include "player_model.h"
#include "motion.h"
#include "sound.h"
#include "fade.h"

//**********************************
// �}�N����`
//**********************************
#define GAUGE_WIDTH  (180.0f)   // �Q�[�W�̕�
#define GAUGE_HEIGHT (575.0f)  // �Q�[�W�̍���*�ő�l
#define GAUGE_SPACE  (275.0f)  // �e�Q�[�W�̊Ԋu
#define BG_SIZE		(D3DXVECTOR3(SCREEN_WIDTH-15,SCREEN_HEIGHT-20,0.0f)) // �w�i�T�C�Y
#define BG_COLOR	(D3DXCOLOR(0.4f,0.4f,0.4f,0.6f))                     // �w�i�F
#define BACK_GAUGE_SIZE (40)                                             // �o�b�N�Q�[�W�T�C�Y
#define BACK_GAUGE_COLOR (D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))                // �o�b�N�Q�[�W�J���[
#define GAUGE_POS_Y (710.0f)                                             // �Q�[�W���WY
#define MIN_POINT (1.0f)                                                   // 0�_�ł��Q�[�W���o�����ߍŒ�l�̉��Z
#define START_RATE (0.0008f)                                                // �X�^�[�g���̃Q�[�W�W��
#define ANNOUNCEMENT_RATE (0.1f)                                           // ���ʔ��\���̃Q�[�W�W��
#define RANK_ANNOUNCEMENT_COUNT (100)                                      // ���ʔ��\�J�E���g
#define EXPLOSION_POS_1 (D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f))
#define EXPLOSION_POS_2 (D3DXVECTOR3(0.0f,SCREEN_HEIGHT,0.0f))
#define CHARACTER_POLYGON_SIZE (DEFAULT_CHARACTER_POLYGON_SIZE*0.7f)
#define CHARACTER_HEIGHT_DIST ((SCREEN_HEIGHT - CHARACTER_POLYGON_SIZE.y / 2.0f)-20.0f/2.0f)
#define CHARACTER_HEIGHT_ADD (15.0f)
#define CHARACTER_CREATE_ADD_HEIGHT (-202.0f) //�L�����N�^�[�𐶐�����ʒu��ς���
#define CONFETTI_TIME (120)

//**********************************
// �ÓI�����o�ϐ��錾
//**********************************

//==================================
// �R���X�g���N�^
//==================================
CResultGraph::CResultGraph() :CScene(OBJTYPE_UI_2)
{
	// �ϐ��̃N���A
	m_pBg = NULL;                // �w�i�|���S��
	ZeroMemory(&m_aGauge,sizeof(m_aGauge));  // �Q�[�W�N���X
    m_fMaxNum = 0.0f;
	m_nActionRank = 0;
	m_nActionCnt = 0;
	m_bEnd = false;
}

//==================================
// �f�X�g���N�^
//==================================
CResultGraph::~CResultGraph()
{
}

//==================================
// �N���G�C�g
//==================================
CResultGraph * CResultGraph::Create(void)
{
	// �������̊m��
	CResultGraph *pGraph;
	pGraph = new CResultGraph;
	pGraph->Init();

	return pGraph;
}

//==================================
// ����������
//==================================
HRESULT CResultGraph::Init(void)
{
	// �O���t�w�i�̐���
	m_pBg = CScene2d::Create();
	m_pBg->SetSize(BG_SIZE);
	m_pBg->SetColor(BG_COLOR);
	m_pBg->SetPriority(OBJTYPE_BG);

	// �O���t�������l�ő吔�̃Z�b�g
	SetMaxNum();

	// �|���S���̐���
	CreatePolygon();

	// �����N�\�[�g����
	// �L����
	std::sort(m_aRankData.begin(), m_aRankData.end(), [](Rank const& rank1, Rank const& rank2) {return (rank1.nKillNum > rank2.nKillNum); });
	// �h��
	std::sort(m_aRankData.begin(), m_aRankData.end(), [](Rank const& rank1, Rank const& rank2) {return (rank1.nPaintNum > rank2.nPaintNum); });

	for (int nCnt = 0; nCnt < (int)m_aRankData.size(); nCnt++)
	{
		m_aRankData[nCnt].nRank = nCnt;

		if (nCnt > 0)
		{
			if (m_aRankData[nCnt].nPaintNum == m_aRankData[nCnt - 1].nPaintNum&&
				m_aRankData[nCnt].nKillNum == m_aRankData[nCnt - 1].nKillNum)
			{
				m_aRankData[nCnt].nRank = m_aRankData[nCnt - 1].nRank;
			}
		}
	}

	// �A�N�V�������ʂ̏�����
	if (m_aRankData.size() >= 1) m_nActionRank = m_aRankData[m_aRankData.size() - 1].nRank;
	
	// �A�N�V�����J�E���g�̏�����
	m_nActionCnt = -RANK_ANNOUNCEMENT_COUNT;
	
	// �G���h�t���O�̏�����
	m_bEnd = false;

	return S_OK;
}

//==================================
// �I������
//==================================
void CResultGraph::Uninit(void)
{
	// �J������
	Release();
}

//==================================
// �X�V����
//==================================
void CResultGraph::Update(void)
{
	// �O���t
	ManageGraph();

	// �L�����̍��WY�̊Ǘ�
	ManageCharacterHeight();
}

//==================================
// �`�揈��
//==================================
void CResultGraph::Draw(void)
{
}

//==================================
// �O���t�ő吔�̃Z�b�g
//==================================
void CResultGraph::SetMaxNum(void)
{
	m_fMaxNum = 0.0f; // �O��̃Q�[������ԍ����X�R�A

	for (int nCntColor = 0; nCntColor < GET_COLORMANAGER->GetColorNum(); nCntColor++)
	{
		// �v���C���[�ԍ��̎擾
		int nPlayerNum = GET_COLORMANAGER->GetUsePlayerNum(nCntColor);
		if (nPlayerNum == -1) continue;

		for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
		{
			// [�v���C���[�ԍ�]���g���Ă���J���[�ԍ��̕ۊ�
			m_aGauge[nPlayerNum][nCntGauge].m_nColorNum = nCntColor;
		}

		int nTileNum = CColorTile::GetTileNum(nPlayerNum) + (int)MIN_POINT;
		Rank rank = { nPlayerNum ,nTileNum ,CKillCount::GetTotalKill(nPlayerNum) };
		m_aRankData.push_back(rank);

		// �ő吔�̕ۊ�
		if (m_fMaxNum < nTileNum)
		{
			m_fMaxNum = (float)nTileNum;
		}
	}
}

//==================================
// �|���S���̐�������
//==================================
void CResultGraph::CreatePolygon(void)
{
	// �v���C���[���̎擾
	int nEntryPlayerNum = CCharaSelect::GetEntryPlayerNum();

	// �����ʒuX���̒���
	float posX = (SCREEN_WIDTH / 2.0f) - ((float)(nEntryPlayerNum - 1) * GAUGE_SPACE) / 2.0f;

	float fCreateCharaHeight = CHARACTER_CREATE_ADD_HEIGHT;
	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		if (!CCharaSelect::GetEntryData(nCntPlayer).bEntry) continue;

		for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
		{
			// �Q�[�W�Ŏg���l�̐ݒ�
			float fWight = GAUGE_WIDTH;
			float fHeight = GAUGE_HEIGHT;
			D3DXCOLOR col = GET_COLORMANAGER->GetIconColor(m_aGauge[nCntPlayer][nCntGauge].m_nColorNum);

			if (nCntGauge == 0)
			{
				fWight = GAUGE_WIDTH + BACK_GAUGE_SIZE;
				fHeight = GAUGE_HEIGHT + BACK_GAUGE_SIZE / 2.0f;
				col = BACK_GAUGE_COLOR;
			}
			// �Q�[�W�̐���
			m_aGauge[nCntPlayer][nCntGauge].pGauge = CGauge::Create(D3DXVECTOR3(posX, GAUGE_POS_Y, 0.0f), fWight, fHeight, m_fMaxNum, col);
			// �ڕW�l�̐ݒ�
			m_aGauge[nCntPlayer][nCntGauge].pGauge->SetValueDist(CColorTile::GetTileNum(m_aGauge[nCntPlayer][nCntGauge].m_nColorNum) + MIN_POINT);
		}

		// �L�����N�^�[�|���S���̐���
		CCharacterPolygon * pCharaPolygon = CCharacterPolygon::Create(D3DXVECTOR3(posX, fCreateCharaHeight, 0.0f));
		pCharaPolygon->SetSize(CHARACTER_POLYGON_SIZE);
		pCharaPolygon->SetCharaType(CCharaSelect::GetEntryData(nCntPlayer).charaType);
		pCharaPolygon->SetRimColor(GET_COLORMANAGER->GetStepColor(CCharaSelect::GetEntryData(nCntPlayer).nColorNum, 1));
		pCharaPolygon->SetTexColor(GET_COLORMANAGER->GetIconColor(CCharaSelect::GetEntryData(nCntPlayer).nColorNum));

		// �L�����N�^�[�f�[�^�̕ۑ�
		m_apCharaPolygon.push_back(pCharaPolygon);
		
		fCreateCharaHeight += CHARACTER_CREATE_ADD_HEIGHT;

		// �Q�[�W�̐ݒ�
		m_aGauge[nCntPlayer][GAUGE_BACK].pGauge->SetMode(CGauge::MODE_HEIGHT_SELF);
		m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetMode(CGauge::MODE_HEIGHT_AUTO);
		m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetHeightDist(GAUGE_HEIGHT / 2.0f);
		m_aGauge[nCntPlayer][GAUGE_FRONT].pGauge->SetRate(START_RATE);
		posX += GAUGE_SPACE;
	}
}

//==================================
// �O���t�Ǘ�
//==================================
void CResultGraph::ManageGraph(void)
{
    if (!m_nActionCnt && m_nActionRank > 0)
    {
        // SE�̍Đ�
        CManager::GetSound()->Play(CSound::LABEL_SE_GAUGE);
    }

    // �J�E���g��i�߂�
	m_nActionCnt++;

	if (m_nActionCnt >= RANK_ANNOUNCEMENT_COUNT && (int)m_aRankData.size() == m_nActionRank)
	{
		m_nActionCnt = 0;
        // ���A�N�V�������N��������
		m_nActionRank--;
	}
    else if(m_nActionCnt >= RANK_ANNOUNCEMENT_COUNT*3)
    {
        // �f�o�b�O�p��ʑJ�ڃR�}���h
        CManager::GetFade()->SetFade(CManager::MODE_TOTAL_RESULT);
    }

	if (m_nActionRank >= 0)
	{
		if (m_nActionCnt > RANK_ANNOUNCEMENT_COUNT)
		{
			bool bAnnouncement = false;
			for (int nCntRankData = (int)m_aRankData.size() - 1; nCntRankData >= 0; nCntRankData--)
			{
				// �A�N�V�������N�������ʂ̔�r
				if (m_aRankData[nCntRankData].nRank != m_nActionRank)    continue;

				// �v���C���[�ԍ�
				int nPlayerNum = m_aRankData[nCntRankData].nPlayerNum;
				// �Q�[�W�̃��[�h��؂�ւ���
				m_aGauge[nPlayerNum][GAUGE_FRONT].pGauge->SetMode(CGauge::MODE_VALUE_AUTO);
				m_aGauge[nPlayerNum][GAUGE_FRONT].pGauge->SetRate(ANNOUNCEMENT_RATE);

				// �����G�t�F�N�g�̐���
				D3DXCOLOR iconCol = GET_COLORMANAGER->GetIconColor(m_aGauge[nPlayerNum][GAUGE_FRONT].m_nColorNum);
				CResultExplosion::Create(EXPLOSION_POS_1, iconCol);
				CResultExplosion::Create(EXPLOSION_POS_2, iconCol);
                
                // SE�̍Đ�
                CManager::GetSound()->Play(CSound::LABEL_SE_RANKING);
				if (m_nActionRank == 0)
				{// ��ʔ��\��
					CConfettiFactory::Create(iconCol, CONFETTI_TIME);
					m_bEnd = true;
                    // SE�̍Đ�
                    CManager::GetSound()->Play(CSound::LABEL_SE_KAMIHUBUKI);
				}
				bAnnouncement = true;

				// ���̏��ʂ���ʂ̎��̓f�B���C�Ȃ����\����
				if (nCntRankData > 0 && m_aRankData[nCntRankData - 1].nRank == 0)
				{
					bAnnouncement = false;
				}
			}
			// �A�N�V���������N�����̃����N�ɂ���
			m_nActionRank--;
			// �J�E���g�̏�����*���ʂ��������������Ƃ��̓J�E���g�����������Ȃ�
			m_nActionCnt = 0;
			if (!bAnnouncement|| m_nActionRank == 0) m_nActionCnt = RANK_ANNOUNCEMENT_COUNT;
		}
	}

	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		// NULL�`�F�b�N
		if (m_aGauge[nCntPlayer][GAUGE_BACK].pGauge == NULL || m_aGauge[nCntPlayer][1].pGauge == NULL) continue;

		// �o�b�N�Q�[�W�̒l�̐ݒ�
		m_aGauge[nCntPlayer][GAUGE_BACK].pGauge->SetHeight(m_aGauge[nCntPlayer][1].pGauge->GetHeight() + (BACK_GAUGE_SIZE / 2.0f));
	}

}

//==================================
// �L�����̍��WY�̊Ǘ�
//==================================
void CResultGraph::ManageCharacterHeight(void)
{
	for (int nCnt = 0; nCnt < (int)m_apCharaPolygon.size(); nCnt++)
	{
		// ���W�̎擾
		D3DXVECTOR3 pos = m_apCharaPolygon[nCnt]->GetPos();
		if (pos.y < CHARACTER_HEIGHT_DIST)
		{
			// �����̉��Z
			pos.y += CHARACTER_HEIGHT_ADD;
			if (pos.y > CHARACTER_HEIGHT_DIST)
			{// �s���߂��Ȃ��悤����
				pos.y = CHARACTER_HEIGHT_DIST;
				m_apCharaPolygon[nCnt]->GetCharaModel()->GetMotion(CResourceCharacter::MOTION_ROLL)->SetActiveMotion(true);
			}
			// ���W�̃Z�b�g
			m_apCharaPolygon[nCnt]->SetPos(pos);
		}
	}
}

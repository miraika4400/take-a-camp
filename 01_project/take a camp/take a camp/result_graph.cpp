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

//**********************************
// �}�N����`
//**********************************
#define GAUGE_WIDTH  50.0f   // �Q�[�W�̕�
#define GAUGE_HEIGHT 500.0f  // �Q�[�W�̍���*�ő�l
#define GAUGE_SPACE  150.0f  // �e�Q�[�W�̊Ԋu
#define BG_SIZE    D3DXVECTOR3(SCREEN_WIDTH-15,SCREEN_HEIGHT-20,0.0f)
#define BG_COLOR D3DXCOLOR(0.0f,0.0f,0.0f,0.6f)
#define GAUGE_RATE 0.03f
#define BACK_GAUGE_SIZE 16
#define BACK_GAUGE_COLOR D3DXCOLOR(1.0f,1.0f,1.0f,1.0f)
//**********************************
// �ÓI�����o�ϐ��錾
//**********************************

//==================================
// �R���X�g���N�^
//==================================
CResultGraph::CResultGraph() :CScene(OBJTYPE_UI)
{
	// �ϐ��̃N���A
	m_pBg = NULL;                // �w�i�|���S��
	ZeroMemory(&m_aGauge,sizeof(m_aGauge));  // �Q�[�W�N���X
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

	float fMaxNum = 0.0f; // �O��̃Q�[������ԍ����X�R�A

	for (int nCntColor = 0; nCntColor < GET_COLORMANAGER->GetColorNum(); nCntColor++)
	{
		int nPlayerNum = GET_COLORMANAGER->GetUsePlayerNum(nCntColor);
		if (nPlayerNum != -1)
		{
			for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
			{
				// [�v���C���[�ԍ�]���g���Ă���J���[�ԍ��̕ۊ�
				m_aGauge[nPlayerNum][nCntGauge].m_nColorNum = nCntColor;
			}
			// �ő吔�̕ۊ�
			if (fMaxNum < CColorTile::GetTileNum(nPlayerNum))
			{
				fMaxNum = (float)CColorTile::GetTileNum(nPlayerNum);
			}
		}
	}
	// �v���C���[�̐���
	// �����ʒuX���̒���
	float posX = (SCREEN_WIDTH/2) - ((float)(MAX_PLAYER - 1) * GAUGE_SPACE) / 2;

	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
		{
			if (nCntGauge == 0)
			{
				m_aGauge[nCntPlayer][nCntGauge].pGauge = CGauge::Create(&m_aGauge[nCntPlayer][nCntGauge].fGraphData,
					D3DXVECTOR3(posX, 700.0f, 0.0f),
					GAUGE_WIDTH + BACK_GAUGE_SIZE,
					GAUGE_HEIGHT + BACK_GAUGE_SIZE /2,
					fMaxNum,
					BACK_GAUGE_COLOR);
				      
			}
			else
			{
				m_aGauge[nCntPlayer][nCntGauge].pGauge = CGauge::Create(&m_aGauge[nCntPlayer][nCntGauge].fGraphData,
					D3DXVECTOR3(posX, 700.0f, 0.0f),
					GAUGE_WIDTH,
					GAUGE_HEIGHT,
					fMaxNum,
					GET_COLORMANAGER->GetIconColor(m_aGauge[nCntPlayer][nCntGauge].m_nColorNum));
			}

			m_aGauge[nCntPlayer][nCntGauge].fGraphData = 0;
		}
		posX += GAUGE_SPACE;
	}

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
	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		for (int nCntGauge = 0; nCntGauge < GAUGE_NUM; nCntGauge++)
		{
			m_aGauge[nCntPlayer][nCntGauge].fGraphData += ((CColorTile::GetTileNum(m_aGauge[nCntPlayer][nCntGauge].m_nColorNum)) - m_aGauge[nCntPlayer][nCntGauge].fGraphData)*GAUGE_RATE;
		}
	}
}

//==================================
// �`�揈��
//==================================
void CResultGraph::Draw(void)
{

}
////////////////////////////////////////////////////
//
//    �X�e�[�W�I���|���S���N���X�̏���[stage_select_polygon.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "stage_select_polygon.h"
#include "scene2d.h"
#include "dynamic_texture.h"

//=============================
// �}�N����`
//=============================
#define POS  (D3DXVECTOR3( SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f, 0.0f))  // Y���W
#define SIZE  (D3DXVECTOR3( SCREEN_WIDTH,SCREEN_HEIGHT, 0.0f)) // �T�C�Y
#define SIZE_MIN_RATE 0.5f

//=============================
// �ÓI�����o�ϐ��錾
//=============================
const std::vector<int> CStageSelectPolygon::m_anDrawObjNum =
{
	CScene::OBJTYPE_BG,
	CScene::OBJTYPE_TILE,
	CScene::OBJTYPE_COLOR_TILE,
	CScene::OBJTYPE_MAP,
};

//=============================
// �R���X�g���N�^
//=============================
CStageSelectPolygon::CStageSelectPolygon()
{
	// �ϐ��̃N���A
	ZeroMemory(&m_apPolygon, sizeof(m_apPolygon));
	m_pDynamicTex = NULL;
}

//=============================
// �f�X�g���N�^
//=============================
CStageSelectPolygon::~CStageSelectPolygon()
{
}

//=============================
// �N���G�C�g
//=============================
CStageSelectPolygon * CStageSelectPolygon::Create(void)
{
	// �������̊m��
	CStageSelectPolygon *pPointa = new CStageSelectPolygon;
	// ������
	pPointa->Init();

	return pPointa;
}

//=============================
// ����������
//=============================
HRESULT CStageSelectPolygon::Init(void)
{
	D3DXVECTOR3 size = SIZE;
	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		// �|���S������
		m_apPolygon[nCntUi] = CScene2d::Create();
		m_apPolygon[nCntUi]->SetPos(POS);
		m_apPolygon[nCntUi]->SetSize(size);
		m_apPolygon[nCntUi]->OutList();

		size *= SIZE_MIN_RATE;
	}

	SetPriority(OBJTYPE_UI);

	m_pDynamicTex = CDynamicTexture::Create(D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	return S_OK;
}

//=============================
// �I������
//=============================
void CStageSelectPolygon::Uninit(void)
{
	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		if (m_apPolygon[nCntUi] != NULL)
		{
			m_apPolygon[nCntUi]->Uninit();
			delete m_apPolygon[nCntUi];
			m_apPolygon[nCntUi] = NULL;
		}
	}

	// �e�N�X�`���N���X�̔j��
	if (m_pDynamicTex != NULL)
	{
		m_pDynamicTex->Uninit();
		delete m_pDynamicTex;
		m_pDynamicTex = NULL;
	}

	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CStageSelectPolygon::Update(void)
{
}

//=============================
// �`�揈��
//=============================
void CStageSelectPolygon::Draw(void)
{
	if (m_pDynamicTex == NULL) return;

	
	// �e�N�X�`���ɃI�u�W�F�N�g����������
	m_pDynamicTex->Begin();
	for (int nCntObj = 0; nCntObj < (int)m_anDrawObjNum.size(); nCntObj++)
	{
		CScene*pScene = GetTop(m_anDrawObjNum[nCntObj]);
		while (pScene != NULL)
		{
			// �`��
			pScene->Draw();

			// �l�N�X�g
			pScene = pScene->GetNext();
		}
	}
	// �����_�[�^�[�Q�b�g��߂�
	m_pDynamicTex->End();

	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		if (m_apPolygon[nCntUi] != NULL)
		{
			m_apPolygon[nCntUi]->BindTexture(m_pDynamicTex->GetTexture());
			m_apPolygon[nCntUi]->Draw();
		}
	}
}
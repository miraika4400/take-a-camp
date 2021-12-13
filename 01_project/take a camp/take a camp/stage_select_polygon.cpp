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
#include "resource_texture.h"
#include "resource_shader.h"

//=============================
// �}�N����`
//=============================
#define POS  (D3DXVECTOR3( SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f, 0.0f))  // Y���W
#define SIZE_0  (D3DXVECTOR3( SCREEN_WIDTH*1.3f,SCREEN_HEIGHT*1.3f, 0.0f)) // �T�C�Y
#define SIZE_1 SIZE_2*1.2f
#define SIZE_2 (D3DXVECTOR3( SCREEN_WIDTH*0.6f,SCREEN_HEIGHT*0.6f, 0.0f)) // �T�C�Y
#define MAP_WIDTH  600
#define MAP_HEIGHT 600
#define BLUR_WEIGHT 5.0f

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
	ZeroMemory(&m_afWeight, sizeof(m_afWeight));
	m_pDynamicTex = NULL;
	m_weightHandle = NULL;
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

	for (int nCntUi = 0; nCntUi < STAGE_SELECT_POLYGON_NUM; nCntUi++)
	{
		// �|���S������
		m_apPolygon[nCntUi] = CScene2d::Create();
		m_apPolygon[nCntUi]->SetPos(POS);
		
		m_apPolygon[nCntUi]->OutList();
	}

	// �T�C�Y�̐ݒ�
	m_apPolygon[0]->SetSize(SIZE_0);
	m_apPolygon[1]->SetSize(SIZE_1);
	m_apPolygon[2]->SetSize(SIZE_2);

	m_apPolygon[1]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_STAGE_SELECT_BG));
	SetPriority(OBJTYPE_UI_1);

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
			if (nCntUi != 1)m_apPolygon[nCntUi]->BindTexture(m_pDynamicTex->GetTexture());

			if (nCntUi == 0) DrawBlur();
			else             m_apPolygon[nCntUi]->Draw();
		}
	}
}

//=============================
// �`�揈��*�u���[
//=============================
void CStageSelectPolygon::DrawBlur(void)
{
	// �V�F�[�_�[���̎擾
	CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_BLUR);

	if (shader.pEffect != NULL)
	{
		if (m_weightHandle == NULL)
		{
			m_weightHandle = shader.pEffect->GetParameterByName(NULL, "weight");
			UpdateWeight(BLUR_WEIGHT);
		}

		// �p�X���̎擾
		UINT numPass = 0;
		shader.pEffect->Begin(&numPass, 0);

		shader.pEffect->SetFloat("MAP_WIDTH", MAP_WIDTH);
		shader.pEffect->SetFloat("MAP_HEIGHT", MAP_HEIGHT);
		// �p�X�����`�揈���̃��[�v
		for (int nCntPass = 0; nCntPass < (int)numPass; nCntPass++)
		{
			// �V�F�[�_�p�X�̕`��J�n
			shader.pEffect->BeginPass(nCntPass);

			m_apPolygon[0]->Draw();

			shader.pEffect->EndPass();
		}
		shader.pEffect->End();
	}
}

void CStageSelectPolygon::UpdateWeight(float fDispersion)
{
	float fTotal = 0;
	for (int nCntWeight = 0; nCntWeight<WEIGHT_MUN; nCntWeight++)
	{
		m_afWeight[nCntWeight] = expf(-0.5f*(FLOAT)(nCntWeight*nCntWeight) / fDispersion);
		if (0 == nCntWeight)
		{
			fTotal += m_afWeight[nCntWeight];
		}
		else
		{
			// ���S�ȊO�́A�Q�񓯂��W�����g���̂łQ�{
			fTotal += 2.0f*m_afWeight[nCntWeight];
		}
	}
	// �K�i��
	for (int nCntWeight = 0; nCntWeight < WEIGHT_MUN; nCntWeight++)
	{
		m_afWeight[nCntWeight] /= fTotal;
	}

	CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_BLUR);

	if (shader.pEffect)
	{
		shader.pEffect->SetFloatArray(m_weightHandle, m_afWeight, WEIGHT_MUN);
	}
}

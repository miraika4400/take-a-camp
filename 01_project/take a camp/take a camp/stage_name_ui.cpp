////////////////////////////////////////////////////
//
//    �X�e�[�W���N���X�̏���[chara_select.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "stage_name_ui.h"
#include "scene2d.h"
#include "keyboard.h"
#include "manager.h"
#include "resource_texture.h"

//=============================
// �}�N����`
//=============================
#define UI_SPACE (500.0f) // UI�Ԃ̊Ԋu
#define UI_POS_Y (80.0f)  // Y���W
#define UI_SIZE_MAX  (D3DXVECTOR3( 300.0f, 300.0f/SELECT_STAGE_NUM, 0.0f)) // �T�C�Y
#define UI_SIZE_MIN  (D3DXVECTOR3( 200.0f, 200.0f/SELECT_STAGE_NUM, 0.0f)) // �T�C�Y
#define RATE (0.2f)

//=============================
// �R���X�g���N�^
//=============================
CStageNameUi::CStageNameUi()
{
	// �ϐ��̃N���A
	ZeroMemory(&m_apNamePolygon, sizeof(m_apNamePolygon));
	m_nSelectNum = 0;
}

//=============================
// �f�X�g���N�^
//=============================
CStageNameUi::~CStageNameUi()
{
}

//=============================
// �N���G�C�g
//=============================
CStageNameUi * CStageNameUi::Create(int nSelectNum)
{
	// �������̊m��
	CStageNameUi *pPointa = new CStageNameUi;
	// ������
	pPointa->Init();

	return pPointa;
}

//=============================
// ����������
//=============================
HRESULT CStageNameUi::Init(void)
{
	float fPosX = SCREEN_WIDTH / 2.0f - (UI_SPACE*m_nSelectNum);
	for (int nCntUi = 0; nCntUi < SELECT_STAGE_NUM; nCntUi++)
	{
		// �|���S������
		m_apNamePolygon[nCntUi] = CScene2d::Create();
		m_apNamePolygon[nCntUi]->SetPos(D3DXVECTOR3(fPosX, UI_POS_Y, 0.0f));
		m_apNamePolygon[nCntUi]->SetSize(UI_SIZE_MIN);
		m_apNamePolygon[nCntUi]->OutList();

		m_apNamePolygon[nCntUi]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_STAGE_NAME_UI));

		D3DXVECTOR2 uv[NUM_VERTEX];
		float fv = 1.0f / SELECT_STAGE_NUM;
		uv[0] = D3DXVECTOR2(0.0f, fv*nCntUi);
		uv[1] = D3DXVECTOR2(1.0f, fv*nCntUi);
		uv[2] = D3DXVECTOR2(0.0f, fv*nCntUi + fv);
		uv[3] = D3DXVECTOR2(1.0f, fv*nCntUi + fv);

		m_apNamePolygon[nCntUi]->SetTextureUV(uv);

		fPosX += UI_SPACE;
	}
	m_apNamePolygon[0]->SetSize(UI_SIZE_MAX);

	SetPriority(OBJTYPE_UI_2);
	return S_OK;
}

//=============================
// �I������
//=============================
void CStageNameUi::Uninit(void)
{
	for (int nCntUi = 0; nCntUi < SELECT_STAGE_NUM; nCntUi++)
	{
		if (m_apNamePolygon[nCntUi] != NULL)
		{
			m_apNamePolygon[nCntUi]->Uninit();
			delete m_apNamePolygon[nCntUi];
			m_apNamePolygon[nCntUi] = NULL;
		}
	}

	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CStageNameUi::Update(void)
{
	// �ʒu�̒���
	float fPosX = (SCREEN_WIDTH / 2.0f) - (UI_SPACE*m_nSelectNum);
	for (int nCntUi = 0; nCntUi < SELECT_STAGE_NUM; nCntUi++)
	{
		// �ʒu�̒���
		D3DXVECTOR3 pos = m_apNamePolygon[nCntUi]->GetPos();
		pos += (D3DXVECTOR3(fPosX, UI_POS_Y, 0.0f) - pos)*RATE;
		m_apNamePolygon[nCntUi]->SetPos(pos);
		fPosX += UI_SPACE;

		// �T�C�Y�̒���
		D3DXVECTOR3 size = m_apNamePolygon[nCntUi]->GetSize();
		if (m_nSelectNum == nCntUi) size += (UI_SIZE_MAX - size)*RATE;
		else                        size += (UI_SIZE_MIN - size)*RATE;
		m_apNamePolygon[nCntUi]->SetSize(size);
		
	}
}

//=============================
// �`�揈��
//=============================
void CStageNameUi::Draw(void)
{
	for (int nCntUi = 0; nCntUi < SELECT_STAGE_NUM; nCntUi++)
	{
		if (m_apNamePolygon[nCntUi] != NULL)
		{
			m_apNamePolygon[nCntUi]->Draw();
		}
	}
}
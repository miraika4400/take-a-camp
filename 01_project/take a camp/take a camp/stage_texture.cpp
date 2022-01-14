//===================================================
//
//    �X�e�[�W�e�N�X�`���N���X�̏���[stage_tecture.cpp]
//    Author:���V ����
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "stage_texture.h"
#include "scene.h"

//**********************************
// �ÓI�����o�ϐ��錾
//**********************************
const std::vector<int> CStageTexture::m_anDrawObjNum =
{
	CScene::OBJTYPE_BG,
	CScene::OBJTYPE_TILE,
	CScene::OBJTYPE_COLOR_TILE,
	CScene::OBJTYPE_MAP,

};
CStageTexture*CStageTexture::m_pInstance = NULL;
//**********************************
// �R���X�g���N�^
//**********************************
CStageTexture::CStageTexture()
{
}

//**********************************
// �f�X�g���N�^
//**********************************
CStageTexture::~CStageTexture()
{
}

//**********************************
// �N���X����
//**********************************
CStageTexture * CStageTexture::Create(D3DXVECTOR2 size)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CStageTexture;
		m_pInstance->Init(size);
	}
	return m_pInstance;
}

//**********************************
// �������
//**********************************
void CStageTexture::Release(void)
{
	if (m_pInstance != NULL)
	{
		m_pInstance->Uninit();
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

//**********************************
// �e�N�X�`���ɃX�e�[�W�̕`��
//**********************************
void CStageTexture::DrawStageInTex(void)
{
	// �e�N�X�`���ɃI�u�W�F�N�g����������
	Begin();
	for (int nCntObj = 0; nCntObj < (int)m_anDrawObjNum.size(); nCntObj++)
	{
		CScene*pScene = CScene::GetTop(m_anDrawObjNum[nCntObj]);
		while (pScene != NULL)
		{
			// �`��
			pScene->Draw();

			// �l�N�X�g
			pScene = pScene->GetNext();
		}
	}
	// �����_�[�^�[�Q�b�g��߂�
	End();
}


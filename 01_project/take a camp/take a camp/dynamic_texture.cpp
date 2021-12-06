////////////////////////////////////////////////////
//
//    dynamic_tecture�̏���[dynamic_tecture.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "dynamic_texture.h"
#include "manager.h"
#include "renderer.h"

//******************************
// �}�N����`
//******************************

//******************************
// �R���X�g���N�^
//******************************
CDynamicTexture::CDynamicTexture()
{
	// �ϐ��̃N���A
	m_pTexture = NULL;		//�e�N�X�`��
	m_pTexz = NULL;			//�e�N�X�`���̐[�x�o�b�t�@
	m_pTexSurface = NULL;	//�e�N�X�`���փA�N�Z�X����ׂ̃C���^�[�t�F�[�X
	m_pBackz = NULL;		//�o�b�N�o�b�t�@�̐[�x�o�b�t�@
	m_pBackSurface = NULL;	//�o�b�N�o�b�t�@�փA�N�Z�X����ׂ�
	ZeroMemory( &m_proj, sizeof(m_proj));		// �ˉe�s��
	ZeroMemory( &m_view, sizeof(m_view));		// �r���[�s��
	ZeroMemory(&m_saveViewport, sizeof(m_saveViewport)); // �ۑ��p�r���[�|�[�g
	m_size = { 0.0f,0.0f };
}

//******************************
// �f�X�g���N�^
//******************************
CDynamicTexture::~CDynamicTexture()
{
}

//******************************
// �N���G�C�g
//******************************
CDynamicTexture * CDynamicTexture::Create(D3DXVECTOR2 size)
{

	CDynamicTexture *pMulltipath = new CDynamicTexture;
	pMulltipath->Init(size);

	return pMulltipath;
}


//******************************
// ����������
//******************************
HRESULT CDynamicTexture::Init(D3DXVECTOR2 size)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_size = size;
	//�V�K�e�N�X�`���쐬*****************************
	pDevice->CreateTexture(m_size.x, m_size.y,
		8,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&m_pTexture,
		NULL);

	//�V�K�e�N�X�`���̐[�x�o�b�t�@�쐬***************
	pDevice->CreateDepthStencilSurface(
		m_size.x, m_size.y,
		D3DFMT_D16,
		D3DMULTISAMPLE_NONE,
		0,
		TRUE,
		&m_pTexz,
		NULL);

	//�V�K�e�N�X�`���ւ̃C���^�[�t�F�[�X�擾*********
	m_pTexture->GetSurfaceLevel(0, &m_pTexSurface);

	//�o�b�N�o�b�t�@�̏���ۑ�*********************
	pDevice->GetViewport(&m_saveViewport);
	pDevice->GetRenderTarget(0, &m_pBackSurface);
	pDevice->GetDepthStencilSurface(&m_pBackz);

	//�����_�����O�^�[�Q�b�g�ύX*******************************
	pDevice->SetRenderTarget(0, m_pTexSurface);
	pDevice->GetDepthStencilSurface(&m_pTexz);

	//�ύX���������_�����O�^�[�Q�b�g�̃o�b�t�@�Ȃǂ��N���A*****
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_RGBA(255, 255, 255, 0), 1.0f, 0);


	//�����_�����O�^�[�Q�b�g�����i�o�b�N�o�b�t�@�j�ɖ߂�****
	pDevice->SetRenderTarget(0, m_pBackSurface);
	pDevice->SetDepthStencilSurface(m_pBackz);

	return S_OK;
}

//******************************
// �I������
//******************************
void CDynamicTexture::Uninit(void)
{
	if (m_pBackSurface != NULL)
	{
		m_pBackSurface->Release();
		m_pBackSurface = NULL;
	}
	if (m_pBackz != NULL)
	{
		m_pBackz->Release();
		m_pBackz = NULL;
	}
	if (m_pTexSurface != NULL)
	{
		m_pTexSurface->Release();
		m_pTexSurface = NULL;
	}
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
	if (m_pTexz != NULL)
	{
		m_pTexz->Release();
		m_pTexz = NULL;
	}
}

//******************************
// �e�N�X�`���ɕ`��J�n
//******************************
void CDynamicTexture::Begin(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�o�b�N�o�b�t�@�̏���ۑ�*******************************
	pDevice->GetRenderTarget(0, &m_pBackSurface);
	pDevice->GetDepthStencilSurface(&m_pBackz);

	//�r���[�|�[�g��ۑ�***************************************
	pDevice->GetViewport(&m_saveViewport);

	// �r���[�A�v���W�F�N�V�����}�g���b�N�X�̕ۑ�**************
	pDevice->GetTransform(D3DTS_PROJECTION, &m_proj);
	pDevice->GetTransform(D3DTS_VIEW, &m_view);

	//�����_�����O�^�[�Q�b�g�ύX*******************************
	pDevice->SetRenderTarget(0, m_pTexSurface);
	pDevice->SetDepthStencilSurface(m_pTexz);

	//�ύX���������_�����O�^�[�Q�b�g�̃o�b�t�@�Ȃǂ��N���A*****
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_RGBA(255, 255, 255, 0), 1.0f, 0);

	//�r���[�|�[�g���Z�b�g*************************************
	D3DVIEWPORT9 viewport2 = { 0, 0, m_size.x, m_size.y, 0.0f, 1.0f };
	pDevice->SetViewport(&viewport2);
}

//******************************
// �e�N�X�`���ɕ`��I��
//******************************
void CDynamicTexture::End(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�����_�����O�^�[�Q�b�g�����i�o�b�N�o�b�t�@�j�ɖ߂�*******
	pDevice->SetRenderTarget(0, m_pBackSurface);
	pDevice->SetDepthStencilSurface(m_pBackz);

	//�r���[�|�[�g��߂�***************************************
	pDevice->SetViewport(&m_saveViewport);

	// �r���[�A�v���W�F�N�V�����}�g���b�N�X��߂�**************
	pDevice->SetTransform(D3DTS_PROJECTION, &m_proj);
	pDevice->SetTransform(D3DTS_VIEW, &m_view);
}

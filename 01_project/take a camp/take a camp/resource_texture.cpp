////////////////////////////////////////////////////
//
//    scene3d�N���X�̏���[scene3d.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "resource_texture.h"
#include "renderer.h"
#include "manager.h"
#include <assert.h>
//******************************
// �}�N����`
//******************************

//******************************
// �ÓI�����o�ϐ��錾
//******************************
CResourceTexture *CResourceTexture::m_pSingleTex = NULL; // �e�N�X�`���N���X�̃|�C���^*�V���O���g���p
// �e�N�X�`���̃p�X
const std::string CResourceTexture::m_aTexPath[CResourceTexture::TEXTURE_MAX]
{
	"./data/Textures/title.png",        // �^�C�g���w�i
	"./data/Textures/tutorial_0.png",   // �`���[�g���A��
    "./data/Textures/tutorial_1.png",   // �`���[�g���A��
    "./data/Textures/tutorial_2.png",   // �`���[�g���A��
    "./data/Textures/tutorial_3.png",   // �`���[�g���A��
	"./data/Textures/effect/kirakira.png",		// �p�[�e�B�N��*�l�p
	"./data/Textures/Tears.png",              // �p�[�e�B�N��*��
	"./data/Textures/particle004.png",        // �p�[�e�B�N��*�~
	"./data/Textures/number.png",             // �i���o�[
	"./data/Textures/frame.png",              // �g
	"./data/Textures/cross_mark.png",         // �o�c�}�[�N
	"./data/Textures/needle_hole.png",        // �Ƃ���
	"./data/Textures/shadow.png",		      // �e
	"./data/Textures/player_number.png",      // �v���C���[�ԍ�
	"./data/Textures/none_logo.png",	      // NONE
	"./data/Textures/joypad.png",		      // �R���g���[���[�A�C�R��
	"./data/Textures/keyboars.png",		      // �L�[�{�[�h�A�C�R��
	"./data/Textures/chara_select_frame.png", // �L�����I��w�i
	"./data/Textures/suma.png",				  // �^�C�g���̃{�^��(�X�^�[�g)
	"./data/Textures/ka-bi-.jpg",			  // �^�C�g���̃{�^��(�`���[�g���A��)
	"./data/Textures/taile_effect_00.png",	  // �ő�h�i�K���̃G�t�F�N�g
};
// �e�N�X�`���̃p�X
const std::string CResourceTexture::m_aCubeTexPath[CResourceTexture::TEXTURE_CUBE_MAX]
{
	"./data/Textures/cube_sky.dds",     // �L���[�u�e�N�X�`����
};

//===================================
// �R���X�g���N�^
//===================================
CResourceTexture::CResourceTexture()
{
	memset(&m_apTexture, 0, sizeof(m_apTexture));
}

//===================================
// �f�X�g���N�^
//===================================
CResourceTexture::~CResourceTexture()
{
}

//=============================================================================
//���f���N���X�̃N���G�C�g����
//=============================================================================
CResourceTexture * CResourceTexture::Create(void)
{
	if (m_pSingleTex == NULL)
	{
		// �������m��
		m_pSingleTex = new CResourceTexture;

		if (m_pSingleTex != NULL)
		{
			// �������m�ۂɐ��������Ƃ�
			m_pSingleTex->Load();
		}
		else
		{
			// �������m�ۂɎ��s�����Ƃ�
			return NULL;
		}
	}
	
	return m_pSingleTex;
}

//===================================
// �N���X�̔j��
//===================================
void CResourceTexture::Release(void)
{
	if (m_pSingleTex != NULL)
	{
		// �e�N�X�`���j��
		m_pSingleTex->Unload();
		// �������̔j��
		delete m_pSingleTex;
		m_pSingleTex = NULL;
	}
}

//===================================
// �e�N�X�`���擾
//===================================
LPDIRECT3DTEXTURE9 CResourceTexture::GetTexture(TEXTURE_TYPE type)
{
	if (m_pSingleTex != NULL)
	{
		return m_pSingleTex->m_apTexture[type];
	}
	else
	{
		return NULL;
	}
}

LPDIRECT3DCUBETEXTURE9 CResourceTexture::GetCubeTexture(TEXTURE_CUBE_TYPE type)
{
	if (m_pSingleTex != NULL)
	{
		return m_pSingleTex->m_apCubeTexture[type];
	}
	else
	{
		return NULL;
	}
}

//===================================
// �e�N�X�`���ǂݍ���
//===================================
void CResourceTexture::Load(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �e�N�X�`���������[�v
	for (int nCnt = 0; nCnt < TEXTURE_MAX; nCnt++)
	{
		// �e�N�X�`���̐���
		D3DXCreateTextureFromFile(pDevice, m_aTexPath[nCnt].c_str(), &m_apTexture[nCnt]);
	}

	// �e�N�X�`���������[�v
	for (int nCnt = 0; nCnt < TEXTURE_CUBE_MAX; nCnt++)
	{
		// �e�N�X�`���̐���
		D3DXCreateCubeTextureFromFile(pDevice, m_aCubeTexPath[nCnt].c_str(), &m_apCubeTexture[nCnt]);
	}
	int n = 0;
}

//===================================
// �e�N�X�`���j��
//===================================
void CResourceTexture::Unload(void)
{
	// �e�N�X�`���������[�v
	for (int nCnt = 0; nCnt < TEXTURE_MAX; nCnt++)
	{
		if (m_apTexture[nCnt] != NULL)
		{
			// �e�N�X�`���̔j��
			m_apTexture[nCnt]->Release();
			m_apTexture[nCnt] = NULL;
		}
	}
}

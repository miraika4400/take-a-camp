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
	"./data/Textures/00_title.png",     // �^�C�g���w�i
	"./data/Textures/tutorial_0.png",   // �`���[�g���A��
    "./data/Textures/tutorial_1.png",   // �`���[�g���A��
    "./data/Textures/tutorial_2.png",   // �`���[�g���A��
    "./data/Textures/tutorial_3.png",   // �`���[�g���A��
	"./data/Textures/frame/knight_flame.png",	   // ���U���g(�i�C�g�̔w�i)
	"./data/Textures/frame/lancer_flame.png",	   // ���U���g(�����T�[�̔w�i)
	"./data/Textures/frame/wizard_flame.png",	   // ���U���g(�E�B�U�[�h�̔w�i)
	"./data/Textures/frame/thief_flame.png",	   // ���U���g(�V�[�t�̔w�i)
	"./data/Textures/frame/magician_flame.png.png",// ���U���g(��p�t�̔w�i)
	"./data/Textures/frame/archer_flame.png",	   // ���U���g(�A�[�`���[�̔w�i)
	"./data/Textures/kill.png",			// ���U���g�̃L��UI
	"./data/Textures/tile.png",			// ���U���g�̃^�C��UI
	"./data/Textures/effect/kirakira.png",	// �p�[�e�B�N��*�l�p
	"./data/Textures/effect/00_wave.png",	// �p�[�e�B�N��*�g��
	"./data/Textures/effect/shoot.png",		// �p�[�e�B�N��*�~
	"./data/Textures/effect/meteor.png",			// �p�[�e�B�N��*�~
	"./data/Textures/number.png",			// �i���o�[
	"./data/Textures/frame.png",              // �g
	"./data/Textures/cross_mark.png",         // �o�c�}�[�N
	"./data/Textures/needle_hole.png",        // �Ƃ���
	"./data/Textures/shadow.png",		      // �e
	"./data/Textures/player_number.png",      // �v���C���[�ԍ�
	"./data/Textures/none_logo.png",	      // NONE
	"./data/Textures/joypad.png",		      // �R���g���[���[�A�C�R��
	"./data/Textures/keyboars.png",		      // �L�[�{�[�h�A�C�R��
	"./data/Textures/chara_select_frame.png", // �L�����I��w�i
	"./data/Textures/00_gamestart.png",		  // �^�C�g���̃{�^��(�X�^�[�g)
	"./data/Textures/00_tutorial.png",		  // �^�C�g���̃{�^��(�`���[�g���A��)
	"./data/Textures/tile_effect_00.png",	  // �ő�h�i�K���̃G�t�F�N�g
	"./data/Textures/attack_area.png",	      // �U���͈�
	"./data/Textures/clock_frame.png",	      // ���v�̘g
	"./data/Textures/clock_hands.png",	      // ���v�̐j
	"./data/Textures/Toon_Shadow.png",	      // �g�D�[���V���h�E
	"./data/Textures/tile_effect_charge.png", // �^�C���̃`���[�W
	"./data/Textures/icon_bg.png",	          // �A�C�R���̔w�i
	"./data/Textures/sword_icon.png",	      // ���A�C�R��
	"./data/Textures/stage_name.png",	      // �X�e�[�W��
	"./data/Textures/stage_polygon_bg.png",	      // �X�e�[�W�I��w�i
	"./data/Textures/00_ready.png",	          // ready
	"./data/Textures/01_go.png",			  // go
	"./data/Textures/00_finish.png",		  // finish
	"./data/Textures/00_nanbyou.png",		  // �c�艽�b
	"./data/Textures/lance_icon.png",         // ���A�C�R��
	"./data/Textures/arrow_icon.png",         // ��A�C�R��
	"./data/Textures/magicstick_icon.png",    // ���@��A�C�R��
	"./data/Textures/knife_icon.png",         // �i�C�t�A�C�R��
	"./data/Textures/stick_icon.png",         // ��A�C�R��
	"./data/Textures/effect_explosion.png",   // ���U���g�G�N�X�v���[�W����
	"./data/Textures/color_gauge_ui.png",	  // �F�̃Q�[�W�̘g
    "./data/Textures/attack_area/00_knight/knight_lv1_attack.png",     // �U���͈�
	"./data/Textures/attack_area/00_knight/knight_lv2_attack.png",     // �U���͈�
	"./data/Textures/attack_area/00_knight/knight_lv3_attack.png",     // �U���͈�
    "./data/Textures/attack_area/01_lancer/lancer_lv1_attack.png",     // �U���͈�
	"./data/Textures/attack_area/01_lancer/lancer_lv2_attack.png",     // �U���͈�
	"./data/Textures/attack_area/01_lancer/lancer_lv3_attack.png",     // �U���͈�
    "./data/Textures/attack_area/02_wizard/wizard_lv1_attack.png",     // �U���͈�
	"./data/Textures/attack_area/02_wizard/wizard_lv2_attack.png",     // �U���͈�
	"./data/Textures/attack_area/02_wizard/wizard_lv3_attack.png",     // �U���͈�
    "./data/Textures/attack_area/03_thief/thief_lv1_attack.png",       // �U���͈�
	"./data/Textures/attack_area/03_thief/thief_lv2_attack.png",       // �U���͈�
	"./data/Textures/attack_area/03_thief/thief_lv3_attack.png",       // �U���͈�
    "./data/Textures/attack_area/04_magician/magician_lv1_attack.png", // �U���͈�
	"./data/Textures/attack_area/04_magician/magician_lv2_attack.png", // �U���͈�
	"./data/Textures/attack_area/04_magician/magician_lv3_attack.png", // �U���͈�
    "./data/Textures/attack_area/05_archer/archer_lv1_attack.png",     // �U���͈�
	"./data/Textures/attack_area/05_archer/archer_lv2_attack.png",     // �U���͈�
	"./data/Textures/attack_area/05_archer/archer_lv3_attack.png",     // �U���͈�
    "./data/Textures/status/00_beginner.png",      // ���S��
    "./data/Textures/status/01_intermediate.png",  // ������
    "./data/Textures/status/02_advanced.png",      // �㋉��
    "./data/Textures/status/03_short.png",         // �ߋ���
    "./data/Textures/status/04_medium.png",        // ������
    "./data/Textures/status/05_long.png",          // ������
    "./data/Textures/navi_attack_area.png", // �U���͈͗U��UI
    
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

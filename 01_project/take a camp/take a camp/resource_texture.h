//=============================================================================
//
// texture�w�b�_ [texture.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"

//*****************************
//�N���X��`
//*****************************

//�e�N�X�`���N���X
class CResourceTexture
{
public:
	// ��
	// �e�N�X�`�����
	typedef enum
	{
		TEXTURE_TITLE = 0,			// �^�C�g��
		TEXTURE_TUTORIAL,			// �`���[�g���A��
		TEXTURE_TUTORIAL_FLAG,		// �`���[�g���A��(�͂�����)
		TEXTURE_TUTORIAL_FRY,		// �`���[�g���A��(�A��)
		TEXTURE_TUTORIAL_REMEMBER,	// �`���[�g���A��(�L��)
		TEXTURE_RESULT_KNIGHT,		// ���U���g(�i�C�g�̔w�i)
		TEXTURE_RESULT_LANCER,		// ���U���g(�����T�[�̔w�i)
		TEXTURE_RESULT_WIZARD,		// ���U���g(�E�B�U�[�h�̔w�i)
		TEXTURE_RESULT_THIEF,		// ���U���g(�V�[�t�̔w�i)
		TEXTURE_RESULT_MAGICIAN,	// ���U���g(��p�t�̔w�i)
		TEXTURE_RESULT_ARCHER,		// ���U���g(�A�[�`���[�̔w�i)
		TEXTURE_RESULT_KILL,		// ���U���g�̃L��UI
		TEXTURE_RESULT_TILE,		// ���U���g�̃^�C��UI
		TEXTURE_PARTICLE_SQUARE,    // �p�[�e�B�N��*�_�C��
		TEXTURE_PARTICLE_SKILL,		// �p�[�e�B�N��*��
		TEXTURE_PARTICLE_CIRCLE,	// �p�[�e�B�N��*�~
		TEXTURE_PARTICLE_GURUGURU,	// ���邮��
		TEXTURE_NUMBER,				// �i���o�[
		TEXTURE_FRAME,				// �g
		TEXTURE_CROSS_MARK,			// �~�}�[�N
		TEXTURE_NEEDLE,				// �Ƃ���
		TEXTURE_SHADOW,				// �e
		TEXTURE_PLAYERNUMBER,		// �v���C���[�ԍ�
		TEXTURE_NONE_UI,				// NONE
		TEXTURE_CONTROLLER,			// �R���g���[���[�A�C�R��
		TEXTURE_KEYBOARD,			// �L�[�{�[�h�A�C�R��
		TEXTURE_CHARASELECT_BACK,	// �L�����I��w�i
		TEXTURE_BUTTON_START,		// �^�C�g���̃{�^��(�X�^�[�g)
		TEXTYRE_BUTTON_TUTORIAL,	// �^�C�g���̃{�^��(�`���[�g���A��)
		TEXTURE_MAX_COLOR_EFFECT,	// �ő�h�i�K���̃G�t�F�N�g
		TEXTURE_ATTACK_AREA,		// �U���͈�
		TEXTURE_CLOCK_FRAME,		// ���v�̘g
		TEXTURE_CLOCK_HANDS,		// ���v�̐j
		TEXTURE_TOON_SHADOW,		// �g�D�[���V���h�E
		TEXTURE_TILE_CHARGE,		// �^�C���̃`���[�W
		TEXTURE_ICON_BG,			// �A�C�R���̔w�i
		TEXTURE_SWORD_ICON,		 	// ���A�C�R��
		TEXTURE_STAGE_NAME_UI,		// �X�e�[�W��
		TEXTURE_STAGE_SELECT_BG,
		TEXTURE_READEY,				// ready
		TEXTURE_GO,					// go
		TEXTURE_FINISH,				// finish
		TEXTURE_SECONDS,			// �c�艽�b
		TEXTURE_LANCE_ICON,		 	// ���A�C�R��
		TEXTURE_ARROW_ICON,		 	// ��A�C�R��
		TEXTURE_MAGICSTICK_ICON,	// ���@��A�C�R��
		TEXTURE_KNIFE_ICON,		 	// �i�C�t�A�C�R��
		TEXTURE_STICK_ICON,		 	// ��A�C�R��
		TEXTURE_RESULT_EXPLOSION,   // ���U���g*�G�N�X�v���\�W����
		TEXTURE_MAX					// �e�N�X�`����
	}TEXTURE_TYPE;
	// �e�N�X�`�����
	typedef enum
	{
		TEXTURE_CUBE_SLY,        // �L���[�u�e�N�X�`��(��)
		TEXTURE_CUBE_MAX              // �e�N�X�`����
	}TEXTURE_CUBE_TYPE;

	// �����o�֐�
	static CResourceTexture * Create(void);                  // �N���X����
	static void Release(void);                               // �N���X�j��
	static LPDIRECT3DTEXTURE9 GetTexture(TEXTURE_TYPE type); // �e�N�X�`���̎擾����*�����F�擾�������e�N�X�`��
	static LPDIRECT3DCUBETEXTURE9 GetCubeTexture(TEXTURE_CUBE_TYPE type); // �e�N�X�`���̎擾����*�����F�擾�������e�N�X�`��
private:
	CResourceTexture();//�B���R���X�g���N�^
public:
	~CResourceTexture();

private:
	void Load(void); // �e�N�X�`���ǂݍ���
	void Unload(void); // �e�N�X�`���j��

	// �����o�ϐ�
	static const std::string m_aTexPath[TEXTURE_MAX]; // �e�N�X�`���̃p�X
	static const std::string m_aCubeTexPath[TEXTURE_CUBE_MAX]; // �e�N�X�`���̃p�X
	static CResourceTexture *m_pSingleTex;			  // �e�N�X�`���N���X�̃|�C���^*�V���O���g���p
	LPDIRECT3DTEXTURE9 m_apTexture[TEXTURE_MAX];      // �e�N�X�`���̃|�C���^
	LPDIRECT3DCUBETEXTURE9 m_apCubeTexture[TEXTURE_CUBE_MAX];      // �e�N�X�`���̃|�C���^
};

#endif
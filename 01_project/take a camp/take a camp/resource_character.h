//=============================================================================
//
// resource_character�w�b�_ [resource_character.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _RESOURCE_CHARACTER_H_
#define _RESOURCE_CHARACTER_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "resource_model_hierarchy.h"

//*****************************
// �}�N����`
//*****************************
#define ATTACK_PATTARN_NUM (8) // �U���p�^�[����

//*****************************
//�N���X��`
//*****************************

//�e�N�X�`���N���X
class CResourceCharacter
{
public:

	// ��
	// �L�����N�^�[�̎��
	typedef enum
	{
		CHARACTER_NONE = -1,	// NONE
		CHARACTER_KNIGHT,		// �R�m
		CHARACTER_LANCER,		// ����
		CHARACTER_WIZARD,		// ���p�t
		CHARACTER_ROBBER,		// ����
		CHARACTER_ARCHER,		// �|��
		CHARACTER_MAGICIAN,		// ��p�t
		CHARACTER_MAX			// �L�����N�^�[��
	}CHARACTER_TYPE;
	//���[�V����
	typedef enum
	{
		MOTION_IDLE = 0,     // �j���[�g����
		MOTION_CHARGE,       // �`���[�W
		MOTION_ATTACK,       // �U��
		MOTION_MAX
	}MOTION_TYPE;

	// �\���̒�`
	//character�f�[�^
	typedef struct
	{
		CResourceModelHierarchy::MODEL_HIERARCHY_TYPE modelType; // ���f���^�C�v�ԍ�
		int nMoveFrame;                        // �ړ��t���[����
		int nMoveFrameDash;                    // �ړ��t���[����*�_�b�V����
		std::string attackTextPath;            // �U���e�L�X�g�̃p�X
		std::string finalAttackPath;           // �K�E�Z�e�L�X�g�̃p�X
		int nFinalAttackTime;                  // �K�E�Z�����\����
		int anChargeTime[ATTACK_PATTARN_NUM];  // �e�U���̃`���[�W�^�C���̃��X�g
		std::string aMotionTextPath[MOTION_MAX]; // ���[�V�����t�@�C���p�X���X�g
	}CharacterData;

	// �L�����N�^�[���x���f�[�^
	typedef struct
	{
		std::string labelName; // ���x���l�[��
		CResourceModelHierarchy::MODEL_HIERARCHY_TYPE modelType; // ���f���^�C�v
	}LabelData;

private:
	CResourceCharacter();  //�B���R���X�g���N�^
public:
	~CResourceCharacter(); // �f�X�g���N�^
	// �����o�֐�
	static CResourceCharacter * Create(void); // �N���X����
	static void Release(void);                // �N���X�j��
	static CResourceCharacter*GetResourceCharacter(void) { return m_pInstance; } // �C���X�^���X�̎擾����
	CharacterData GetCharacterData(CHARACTER_TYPE type) { return m_aCharacterData[type]; }// �L�����N�^�[�f�[�^�̎擾����

private:
	void Load(void); // �e�N�X�`���ǂݍ���

	// �����o�ϐ�
	static CResourceCharacter* m_pInstance;           // �C���X�^���X�̕ێ�
	static const std::vector<LabelData> m_aLabelList; // �L�����N�^�[���x�����X�g
	static const std::string m_aCharacterDataTxtPath[CHARACTER_MAX]; // �L�����N�^�[�f�[�^�̃e�L�X�g�̃p�X
	CharacterData m_aCharacterData[CHARACTER_MAX];    // �L�����N�^�[�f�[�^
};

#endif
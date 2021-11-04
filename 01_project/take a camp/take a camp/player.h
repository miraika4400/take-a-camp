//=============================================================================
//
// player�w�b�_ [player.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "model_hierarchy.h"

//*****************************
// �O���錾
//*****************************
class CCollision;
class CActRange;
class CAttackBased;
class CMotion;
class CKillCount;

//*****************************
// �N���X��`
//*****************************

// �v���C���[�N���X
class CPlayer : public CModelHierarchy
{
public:
	// ��
	//���[�V����
	typedef enum
	{
		MOTION_WALK = 0,     // �A�C�h��
		MOTION_MAX
	}MOTION_TYPE;
	// �L�[
	typedef enum
	{
		KEY_PROGRESS = 0,
		KEY_RECESSION,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_BULLET,
		KEY_MAX
	}CONTROLL_KEY;
	// �X�e�[�g
	typedef enum
	{
		PLAYER_STATE_NORMAL = 0,	//�ʏ���
		PLAYER_STATE_DEATH			//���S���
	}PLAYER_STATE;
	// �A�C�e���X�e�[�g
	typedef enum
	{
		ITEM_STATE_NONE = 0,	//�ʏ�
		ITEM_STATE_DASH,		//����
		ITEM_STATE_MAX
	}ITEM_STATE;
	// �L�����^�C�v
	typedef enum
	{
		CHARA_TYPE_FIGHTER = 0, // ��m
		CHARA_TYPE_LANCER,      // ���g��
		CHARA_TYPE_WIZARD,      // ���@�g��
		CHARA_TYPE_MAX
	}CHARA_TYPE;

	//�����o�֐�
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber);
	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);		// ���S�����֐�
	void SkillDeath(void);	// �X�L���ł̎��S�����֐�

	int GetColorNumber(void) { return m_nColor; }
	CCollision * GetCollision(void) { return  m_pCollision; }
	int GetPlayerNumber(void) { return m_nPlayerNumber; }

	void Attack(void);	//�e�̏���

	void SetState(PLAYER_STATE PlayerState) {m_PlayerState = PlayerState;}
	PLAYER_STATE GetState(void) { return m_PlayerState; }

	D3DXVECTOR3 GetRotDest(void) { return m_rotDest; }
	void SetItemState(ITEM_STATE ItemState) { m_ItemState = ItemState; }
	ITEM_STATE GetItemState(void) { return m_ItemState; }

	CKillCount * GetKillCount(void) { return m_pKillCount; }

	static int GetPlayerControllKey(int nPlayerNum, CONTROLL_KEY keyEnum) { return m_anControllKey[nPlayerNum][keyEnum]; }
private:
	void Move(void);		// �ړ�����
	void Respawn(void);		// ���X�|�[������
	void Invincible(void);	// ���G����

	void DrawModel(void);
	void SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData);// �V�F�[�_�ɒl�𑗂�

	// �����o�ϐ�
	static int m_anControllKey[4][KEY_MAX];
	static CResourceModel::Model m_model[MAX_PARTS_NUM]; // ���f���\����
	static int m_nPartsNum;                              // ���f���p�[�c��

	CKillCount * m_pKillCount;	// �v���C���[�̃L���J�E���g�|�C���^
	ITEM_STATE m_ItemState;		// �A�C�e���X�e�[�^�X
	int m_nMoveframe;			// �ړ����x
	int m_nDashCnt;				// ���x�A�b�v�J�E���g
	CAttackBased* m_pAttack;	// �U���p�N���X
	int m_nPlayerNumber;		// �v���C���[�ԍ�
	int m_nColor;				// �F�i���o�[
	int m_nControllNum;         // �R���g���[���ԍ�
	bool m_bController;         // �R���g���[���[�{���ۃL�[�{�[�h���삩
	bool m_bMove;				// �ړ��ۃt���O
	bool m_bInvincible;			// ���G�t���O
	PLAYER_STATE m_PlayerState;	// �v���C���[�X�e�[�^�X
	int	m_nRespawnCount;		// ���X�|�[���܂ł̃J�E���g
	int m_nInvincibleCount;		// ���G���Ԃ̃J�E���g
	D3DXVECTOR3	 m_Move;		// �ړ���
	int			 m_MoveCount;	// �ړ����̃J�E���g
	D3DXCOLOR	 m_color;		// �F
	CCollision * m_pCollision;	// �����蔻��
	CActRange *	 m_pActRange;	// �s������
	D3DXVECTOR3  m_rotDest;		// ��](�ڕW�̒l)
	D3DXVECTOR3  m_RespawnPos;	// ���X�|�[���ʒu
	// ���[�V�����p�ϐ�
	static char m_achAnimPath[MOTION_MAX][64];   // �A�j���[�V�����e�L�X�g�̃p�X�i�[�p
	CMotion *m_apMotion[MOTION_MAX];  // �A�j���[�V�����|�C���^

};

#endif
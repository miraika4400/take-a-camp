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
#include "player_model.h"
#include "resource_character.h"

//*****************************
// �O���錾
//*****************************
class CCollision;
class CActRange;
class CAttackBased;
class CMotion;
class CKillCount;
class CSkillgauge;

//*****************************
// �}�N����`
//*****************************
#define STICK_DECISION_RANGE	(32768.0f / 1.001f)				// �X�e�B�b�N�̏㉺���E�̔��肷��͈�

//*****************************
// �N���X��`
//*****************************

// �v���C���[�N���X
class CPlayer : public CPlayerModel
{
public:
	// ��

	// �L�[
	typedef enum
	{
		KEY_PROGRESS = 0,
		KEY_RECESSION,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_BULLET,
		KEY_ATTCK_FINAL,
		KEY_MAX
	}CONTROLL_KEY;

	// �X�e�[�g
	typedef enum
	{
		PLAYER_STATE_NORMAL = 0,	//�ʏ���
		PLAYER_STATE_STOP,			//��~���
		PLAYER_STATE_DEATH			//���S���
	}PLAYER_STATE;

	// �A�C�e���X�e�[�g
	typedef enum
	{
		ITEM_STATE_NONE = 0,	//�ʏ�
		ITEM_STATE_DASH,		//����
		ITEM_STATE_REVERSE,		//����t�]
		ITEM_STATE_MAX
	}ITEM_STATE;

	//�����o�֐�
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber);
	static CPlayer*GetPlayerByPlayerNumber(int nPlayerNum);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);		// ���S�����֐�
	void Attack(void);		// �U������
	void AttackFinal(void); // �K�E�Z����

	//�Z�b�^�[�E�Q�b�^�[
	// �J���[�ԍ��擾
	int GetColorNumber(void) { return m_nColor; }		
	// �����蔻��擾
	CCollision * GetCollision(void) { return  m_pCollision; }	
	// �v���C���[�ԍ��擾
	int GetPlayerNumber(void) { return m_nPlayerNumber; }		
	// �v���C���[���
	void SetState(PLAYER_STATE PlayerState) { m_PlayerState = PlayerState; }	
	PLAYER_STATE GetState(void) { return m_PlayerState; }			
	// ���G��Ԏ擾
	bool GetInvincible(void) { return m_bInvincible; }		
	//�����ƈʒu�̈ړ���
	D3DXVECTOR3 GetRotDest(void) { return m_rotDest; }					
	D3DXVECTOR3 GetPosDest(void) { return m_Move; }
	// �A�C�e�����
	void SetItemState(ITEM_STATE ItemState) { m_ItemState = ItemState; }	
	ITEM_STATE GetItemState(void) { return m_ItemState; }		
	// �L���J�E���g�|�C���^
	CKillCount * GetKillCount(void) { return m_pKillCount; }
	// �ړ��t���O
	bool GetMoveFlag(void) { return m_bMove; }
	// �U���֌W�t���O
	void SetAttack(bool bAttack) { m_bAttack = bAttack; }				
	void SetFinalAttack(bool bFinalAttack) { m_bFinalAttack = bFinalAttack; }	
	// �U���|�C���^
	CAttackBased * GetAttack(void) { return m_pAttack; }		
	//�v���C���[
	static int GetPlayerControllKey(int nPlayerNum, CONTROLL_KEY keyEnum) { return m_anControllKey[nPlayerNum][keyEnum]; }
	// �K�E�Z�Q�[�W�|�C���^
	CSkillgauge *GetSkillgauge(void) { return m_pSkillgauge; }
private:
	void InitCharacterData(void); // �L�����f�[�^�̏�����
	void Move(void);			// �ړ�����
	void ControlMove(void);		// �R���g���[������
	void ManageRot(void);		// �����̊Ǘ�
	void Respawn(void);			// ���X�|�[������
	void Invincible(void);		// ���G����
	void ManageItemState(void); // �A�C�e���X�e�[�g�̊Ǘ�

	// �����o�ϐ�
	static int m_anControllKey[MAX_PLAYER][KEY_MAX];

	CKillCount * m_pKillCount;	// �v���C���[�̃L���J�E���g�|�C���^
	CAttackBased* m_pAttack;	// �U���p�N���X
	int m_nPlayerNumber;		// �v���C���[�ԍ�
	D3DXCOLOR	 m_color;		// �F
	int m_nColor;				// �F�i���o�[
	int m_nControllNum;         // �R���g���[���ԍ�
	bool m_bController;         // �R���g���[���[���삩�L�[�{�[�h���삩
	bool m_bMove;				// �ړ��ۃt���O
	bool m_bOldMove;			// �O��̈ړ��ۃt���O�̏��
	bool m_bAttack;				// �U���ۃt���O
	bool m_bFinalAttack;		// �K�E�ۃt���O
	bool m_bInvincible;			// ���G�t���O
	int m_nInvincibleCount;		// ���G���Ԃ̃J�E���g
	PLAYER_STATE m_PlayerState;	// �v���C���[�X�e�[�^�X
	int	m_nRespawnCount;		// ���X�|�[���܂ł̃J�E���g
	D3DXVECTOR3	m_Move;					// �ړ���
	int			m_nMoveCount;			// �ړ���
	int			m_nMoveFrame;			// �ړ����x
	int			m_nMoveCountData;		// �����܂ł̈ړ��񐔕ۑ�
	int			m_nMoveFrameInitialData;// �ړ��������t���[�����ۑ�
	int			m_nMoveFrameData;		// �ړ����t���[�����ۑ�
	int			m_nMoveFrameDataDash;	// �ړ����t���[����*�_�b�V�����ۑ�
	int			m_nMoveFrameCount;		// �ړ����J�E���g
	ITEM_STATE m_ItemState;		// �A�C�e���X�e�[�^�X
	int	m_ReverseCount;			// �A�C�e������ ���씽�]�J�E���g
	int m_nDashCnt;				// �A�C�e������ ���x�A�b�v�J�E���g
	CCollision * m_pCollision;	// �����蔻��
	CActRange *	 m_pActRange;	// �s������
	D3DXVECTOR3  m_rotDest;		// ��](�ڕW�̒l)
	D3DXVECTOR3  m_RespawnPos;	// ���X�|�[���ʒu
	CSkillgauge * m_pSkillgauge;// �K�E�Z�Q�[�W
	int m_nChargeTilelevel;			// �`���[�W�J�n�^�C���̓h��i�K

	// ���[�V�����p�ϐ�
	CMotion *m_apMotion[CResourceCharacter::MOTION_MAX];  // �A�j���[�V�����|�C���^

};

#endif
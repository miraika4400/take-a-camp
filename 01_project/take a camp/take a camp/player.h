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
#include "model.h"

//*****************************
// �O���錾
//*****************************
class CCollision;
class CActRange;
//*****************************
// �N���X��`
//*****************************

// �v���C���[�N���X
class CPlayer : public CModel
{
public:
	typedef enum
	{
		KEY_PROGRESS = 0,
		KEY_RECESSION,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_MAX
	}CONTROLL_KEY;

	typedef enum
	{
		PLAYER_STATE_NORMAL = 0,	//�ʏ���
		PLAYER_STATE_DEATH			//���S���
	}PLAYER_STATE;

	//�����o�֐�
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, int nPlayerNumber);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);	// ���S�����֐�

	int GetColorNumber(void) { return m_nColor; }
	CCollision * GetCollision(void) { return  m_pCollison; }
	int GetPlayerNumber(void) { return m_nPlayerNumber; }
	void SetState(PLAYER_STATE PlayerState) {m_PlayerState = PlayerState;}
	PLAYER_STATE GetState(void) { return m_PlayerState; }
private:
	void Move(void);		// �ړ�����
	void Respawn(void);		// ���X�|�[������
	void Invincible(void);	// ���G����
	// �����o�ϐ�
	static int m_anControllKey[4][KEY_MAX];

	int m_nPlayerNumber;		// �v���C���[�ԍ�
	int m_nColor;				// �F�i���o�[
	bool m_bMove;				// �ړ��ۃt���O
	bool m_bInvincible;			// ���G�t���O
	PLAYER_STATE m_PlayerState;	// �v���C���[�X�e�[�^�X
	int	m_nRespawnCount;		// ���X�|�[���܂ł̃J�E���g
	int m_nInvincibleCount;		// ���G���Ԃ̃J�E���g
	D3DXVECTOR3	 m_Move;		// �ړ���
	int			 m_MoveCount;	// �ړ����̃J�E���g
	D3DXCOLOR	 m_color;		// �F
	CCollision * m_pCollison;	// �����蔻��
	CActRange *	 m_pActRange;	// �s������
	D3DXVECTOR3  m_RespawnPoa;	// ���X�|�[���ʒu
};

#endif
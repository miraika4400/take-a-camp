//=============================================================================
//
// �������̃w�b�_�[ [move_tile.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _MOVE_TILE_H_
#define _MOVE_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "tile.h"
#include "map.h"

//*****************************
//�O���錾
//*****************************
class CModel;

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************
class CMoveTile : public CTile
{
public:
	// �X�e�[�g
	typedef enum
	{
		MOVE_STATE_NORMAL = 0,	//�ʏ���
		MOVE_STATE_MOVE,		//�ړ����
		MOVE_STATE_STOP,		//��~���
	}MOVE_STATE;

	//�����o�֐�
	CMoveTile();
	~CMoveTile();

	HRESULT Init(void);
	void Update(void);

	//�ϐ��̎擾�ݒ�
	
	// �X�e�[�g
	void SetState(MOVE_STATE state) { m_MoveState = state; }
	MOVE_STATE GetState(void) { return m_MoveState; }
	// �ړ���
	void SetMove(D3DXVECTOR3 move) { m_Move = move; }
	D3DXVECTOR3 GetMove(void) { return m_Move; }
	//�ړ�����
	bool GetReversal(void) { return m_bReversal; }
	void SetReversal(bool Reversal) { m_bReversal = Reversal; }
	virtual void MoveRot(bool bReversal) = 0;
	virtual void TileCheck(void) = 0;
	void HitTile(void);						// ���̃^�C���Ƃ̓����蔻��

private:
	void HitPlayerAction(CPlayer*pPlayer);	// �v���C���[������Ă��邩
	void HitPlayerActionRelease(void);		// �v���C���[���~�肽��

	void Move(void);						// �ړ�����

	// �����o�ϐ�
	bool			m_bStep;		// �ڂ��Ă���t���O
	MOVE_STATE		m_MoveState;	// �^�C���̃X�e�[�g
	D3DXVECTOR3		m_Move;			// �ړ���
	int				m_nMoveCount;	// �ړ��J�E���g
	bool			m_bReversal;	// ���]�t���O(true�Ȃ�-)
};

#endif
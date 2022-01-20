//=============================================================================
//
// �s���͈̓w�b�_ [act_range.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _ACT_RAGE_H_
#define _ACT_RAGE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"
#include "map.h"
#include "game.h"

//*****************************
// �O���錾
//*****************************
class CPlayer;

//*****************************
// �N���X��`
//*****************************
// �s���͈̓N���X
class CActRange : public CScene
{
public:
	//*****************************
	// ��
	//*****************************

	typedef enum	//�ړ��ł������
	{
		PLAYER_MOVE_UP = 0,	//��
		PLAYER_MOVE_DOWN,	//��
		PLAYER_MOVE_LEFT,	//��
		PLAYER_MOVE_RIGHT,	//�E
		PLAYER_MOVE_MAX
	}PLAYER_MOVE;
		
	typedef struct
	{
		D3DXVECTOR3 OtherActPos;	// �ʒu
		D3DXVECTOR3 OtherNewActPos;	// �ړ��ʒu
		bool		bMove;			// �ړ��t���O
		bool		bDeath;			// ���S�t���O
	}OTHER_ACT;

	//*****************************
	// �����o�֐�
	//*****************************

	CActRange();
	~CActRange();
	void PlayerPos(void);					// �v���C���[���ǂ̈ʒu�ɂ��邩
	bool ActMove(int nMoveX, int nMoveZ);	// �v���C���[�����̕����Ɉړ��ł��邩
	void OtherPlayer(void);					// ���̃v���C���[�ɂԂ���~�܂锻��
	void ActRange(void);					// �v���C���[�̈ړ��͈�
	static CActRange *Create(CPlayer* pPlayer);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//*****************************
	// �Z�b�^�[���Q�b�^�[����
	//*****************************
	bool GetPlayerMove(int nPlayerMove) { return m_bPlayerMove[nPlayerMove]; }	// �v���C���[�̈ړ��ł�������Q�b�^�[
	D3DXVECTOR3 GetActPos(void) { return m_ActPos; }							// �}�b�v��̃v���C���[�̈ʒu�Q�b�^�[
	D3DXVECTOR3 GetNewActPos(void) { return m_NewActPos; }						// �}�b�v��̃v���C���[�̈ړ��ʒu�Q�b�^�[
	void SetDeath(bool bDeath) { m_bDeath = bDeath; }							// �v���C���[�̎��S�t���O�̃Z�b�^�[
	bool GetDeath(void) { return m_bDeath; }									// �v���C���[�̎��S�t���O�̃Q�b�^�[
	void SetMove(bool bMove) { m_bMove = bMove; }								// �v���C���[�̈ړ��ʃZ�b�^�[
	bool GetMove(void) { return m_bMove; }										// �v���C���[�̈ړ��ʃQ�b�^�[

private:

	//*****************************
	// �����o�ϐ�
	//*****************************
	CPlayer*		 m_pPlayer;							// �v���C���[�|�C���^
	CMapManager::MAP_DATA m_MapData;					// �}�b�v�f�[�^
	D3DXVECTOR3		 m_ActPos;							// �}�b�v��̃v���C���[�̈ʒu
	D3DXVECTOR3		 m_NewActPos;						// �}�b�v��̃v���C���[�̈ړ���̈ʒu
	OTHER_ACT		 m_OtherAct[PLAYER_MOVE_MAX - 1];	// ���v���C���[�̏��
	bool			 m_bPlayerMove[PLAYER_MOVE_MAX];	// �v���C���[���ړ��ł��邩
	bool			 m_bDeath;							// ���S�t���O
	bool			 m_bMove;							// �ړ��t���O
	
};

#endif
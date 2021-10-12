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
#include "stage.h"

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
	typedef enum	//�ړ��ł������
	{
		PLAYER_MOVE_UP = 0,	//��
		PLAYER_MOVE_LEFT,	//��
		PLAYER_MOVE_RIGHT,	//�E
		PLAYER_MOVE_DOWN,	//��
		PLAYER_MOVE_MAX
	}PLAYER_MOVE;

	//�����o�֐�
	CActRange();
	~CActRange();
	void PlayerPos(void);					// �v���C���[���ǂ̈ʒu�ɂ��邩
	void ActRange(void);	// �v���C���[�̈ړ��͈�
	static CActRange *Create(CPlayer* pPlayer);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	bool GetPlayerMove(int nPlayerMove) { return m_bPlayerMove[nPlayerMove]; }
private:
	CPlayer*		 m_pPlayer;		// �v���C���[�|�C���^
	CStage::MAP_DATA m_MapData;		// �}�b�v�f�[�^
	D3DXVECTOR3		 m_PlayerPos;	// �}�b�v��̃v���C���[�̈ʒu
	bool			 m_bPlayerMove[PLAYER_MOVE_MAX]; // �v���C���[���ړ��ł��邩
};

#endif
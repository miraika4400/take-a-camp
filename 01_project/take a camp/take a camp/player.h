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
	//�����o�֐�
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, int nPlayerNumber);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetColorNumber(void) { return m_nColor; }
	CCollision * GetCollision(void) { return  m_pCollison; }
	int GetPlayerNumber(void) { return m_nPlayerNumber; }
private:
	void Move(void); // �ړ�����

	// �����o�ϐ�
	int m_nPlayerNumber;      // �v���C���[�ԍ�
	int m_nColor;             // �F�i���o�[
	bool m_bMove;            // �ړ��ۃt���O
	
	D3DXVECTOR3	 m_Move;		// �ړ���
	int			 m_MoveCoutn;	// �ړ����̃J�E���g
	D3DXCOLOR	 m_color;		// �F
	CCollision * m_pCollison;	// �����蔻��
	CActRange *	 m_pActRange;	// �s������
};

#endif
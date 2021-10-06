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
// �N���X��`
//*****************************

// �����蔻��N���X
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

private:
	void Move(void); // �ړ�����

	// �����o�ϐ�
	int m_nPlayerNumber; // �v���C���[�ԍ�
	bool m_bMove;        // �ړ��ۃt���O
};

#endif
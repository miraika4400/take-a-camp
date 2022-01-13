//=============================================================================
//
// dummy�w�b�_ [dummy.h]
// Author:�ɓ��@�z��
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _DUMMY_H_
#define _DUMMY_H_

//=============================
// �C���N���[�h
//=============================
#include "main.h"
#include "model.h"

//=============================
// �O���錾
//=============================
class CCollision;

//=============================
// �N���X��`
//=============================

// �v���C���[�N���X
class CDummy : public CModel
{
public:
	//*****************************
	// ��
	//*****************************

	// �X�e�[�g
	typedef enum
	{
		DUMMY_STATE_NORMAL = 0,	//�ʏ���
		DUMMY_STATE_DEATH			//���S���
	}DUMMY_STATE;


	//============
	// �����o�֐�
	//===========
	CDummy();
	~CDummy();
	static CDummy *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);		// ���S�����֐�

	//====================
	// �Z�b�^�[�E�Q�b�^�[
	//===================
	// �v���C���[���
	void SetState(DUMMY_STATE PlayerState) { m_DummyState = PlayerState; }
	DUMMY_STATE GetState(void) { return m_DummyState; }

	// �����蔻��擾
	CCollision * GetCollision(void) { return  m_pCollision; }
private:
	void Respawn(void);			// ���X�|�[������

	//============
	// �����o�ϐ�
	//===========
	DUMMY_STATE m_DummyState;	// �_�~�[�X�e�[�^�X
	D3DXCOLOR m_color;			// �F
	int	m_nRespawnCount;		// ���X�|�[���܂ł̃J�E���g
	D3DXVECTOR3  m_RespawnPos;	// ���X�|�[���ʒu
	CCollision * m_pCollision;	// �����蔻��
};

#endif
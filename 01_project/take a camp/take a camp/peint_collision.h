//=============================================================================
//
// �h�菈�� [peint_collision.h]
// Author : �g�c �I�l
//
//=============================================================================
#ifndef _PEINT_COLLISION_
#define _PEINT_COLLISION_
//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "model.h"
//=============================================================================
// �O���錾
//=============================================================================
class CCollision;

//=============================================================================
// �N���X�錾
//=============================================================================
class CPeintCollision :public CModel
{
public:
	CPeintCollision();	// �R���X�g���N�^
	~CPeintCollision();	// �f�X�g���N�^
	static CPeintCollision * Create(D3DXVECTOR3 pos, int nPlayerNum);	// ��������

	HRESULT Init(void);		// ����������
	void	Uninit(void);	// �I������
	void	Update(void);	// �X�V����
	void	Draw(void);		// �`�揈��
	void	ColorLoad(void);// �J���[�ԍ��ǂݍ���

	int		GetPlayerNum(void) { return m_nPlayerNum; }//�v���C���[�i���o�[�Q�b�^�[
	int		GetColorNumber(void) { return m_nColorNumber; }
	CCollision* GetCollision(void) { return m_pCollision; }
	void	Death();
private:
	//==============1===============================================================
	// �����o�ϐ��錾
	//=============================================================================
	CCollision * m_pCollision;		// �����蔻��
	int m_nPlayerNum;				// �v���C���[�̔ԍ�
	int m_nColorNumber;				// �J���[�ݒ�
	bool m_bDeath;					// ���S�t���O
};

#endif
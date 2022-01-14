//=============================================================================
//
// �e�̏��� [Bullet.h]
// Author : �����D�I
//
//=============================================================================
#ifndef _BULLET_H_
#define _BULLET_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "model.h"

//=============================================================================
// �O���錾
//=============================================================================
class CPlayer;
class CCollision;
class CPeintCollision;
//=============================================================================
// �}�N����`
//=============================================================================
#define BULLET_MOVE 5		// �e�̈ړ���
#define MAX_PEINT 5			// �U���łʂ��ő�}�X

//=============================================================================
// �N���X�錾
//=============================================================================
class CBullet : public CModel
{
public:
	CBullet();	// �R���X�g���N�^
	~CBullet();	// �f�X�g���N�^

	static CBullet * Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nPlayerNum);	// ��������

	HRESULT Init(void);		// ����������

	void Uninit(void);		// �I������
	void Update(void);		// �X�V����
	void Draw(void);		// �`�揈��

	void CollisionPlayer(void);	// �����蔻��
	void CollisionDummy(void);	// �����蔻��
	void KillCount(void);

	CCollision* GetCollision(void) { return m_pCollision; }
private:
	//=============================================================================
	// �����o�ϐ��錾
	//=============================================================================
	D3DXVECTOR3 m_move;			// �ړ���
	D3DXVECTOR3 m_size;			// �傫��
	D3DXCOLOR	m_color;		// �F
	int m_nTile;				// ���C�t
	float m_fSpeed;				// ����
	CCollision * m_pCollision;	// �����蔻��
	CPeintCollision* m_pPeintCollision[MAX_PEINT];	//�}�X�ڂ̓����蔻��
	int m_nPlayerNum;			// �v���C���[�i���o�[
	static D3DXVECTOR3 m_PeintPos[MAX_PEINT];	//�h��p�̓����蔻��ʒu
};

#endif // !_BULLET_H_

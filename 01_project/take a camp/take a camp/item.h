//=============================================================================
//
// �A�C�e���̏��� [Item.h]
// Author : �����x�ߑ�
//
//=============================================================================
#ifndef _ITEM_H_
#define _ITEM_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "model.h"

//=============================================================================
// �O���錾
//=============================================================================
class CCollision;
class CPlayer;
class CShadow;

//=============================================================================
// �}�N����`
//=============================================================================

//=============================================================================
// �N���X�錾
//=============================================================================
class CItem : public CModel
{
public:
	//�A�C�e������
	typedef enum
	{
		ITEM_EFFECT_DASH = 0,	//����
		ITEM_EFFECT_REVERSE,	//����t�]
		ITEM_EFFECT_MAX
	}ITEM_EFFECT;

	CItem();	// �R���X�g���N�^
	~CItem();	// �f�X�g���N�^

	static CItem * Create(D3DXVECTOR3 pos, ITEM_EFFECT effect);	// ��������

	HRESULT Init(void);		// ����������
	void Uninit(void);		// �I������
	void Update(void);		// �X�V����
	void Draw(void);		// �`�揈��

	void MoveUpdate(void);	//�ړ��X�V
	void RotUpdate(void);	//�p�x�X�V

	void CollisionItem(void);		// �����蔻��
	virtual void ItemEffect(CPlayer*pPlayer);	// �A�C�e������

	void SetItemEffect(ITEM_EFFECT ItemState) { m_ItemEffect = ItemState; }
	ITEM_EFFECT GetItemState(void) { return m_ItemEffect; }
private:
	//=============================================================================
	// �����o�ϐ��錾
	//=============================================================================
	D3DXVECTOR3 m_size;		//�傫��
	D3DXVECTOR3 m_rot;		//�p�x
	D3DXVECTOR3 m_move;		//�ړ�

	ITEM_EFFECT m_ItemEffect;	//�A�C�e���X�e�[�^�X
	CCollision *m_pCollision;	//�R���W�����̃|�C���^
	CPlayer *m_pPlayer;			//�v���C���[�̃|�C���^
	CShadow *m_pShadow;			//�e�̃|�C���^
	int m_nItemCnt;				//�擾��̃^�C�}�[

	bool m_bUp;				//�������
	bool m_bGet;			//�擾�t���O
	bool m_bDeath;			//���S�t���O
};

#endif // !_ITEM_H_

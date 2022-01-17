////////////////////////////////////////////////////
//
//    �A�C�e���N���X�̏���[item.cpp]
//    Author:�����x�ߑ�
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "item.h"
#include "dash_item.h"
#include "reverse_item.h"
#include "manager.h"
#include "player.h"
#include "collision.h"
#include "shadow.h"

//*****************************
// �}�N����`
//*****************************
#define MODEL_SIZE		(D3DXVECTOR3( 0.6f, 0.6f, 0.6f))
#define ITEM_ONE_SIDE	(10.0f)

//******************************
// �R���X�g���N�^
//******************************
CItem::CItem() : CModel(OBJTYPE_ITEM)
{
	m_rot = D3DXVECTOR3(0.0f, 0.05f, 0.0f);//�p�x
	m_move = D3DXVECTOR3(0.0f, 0.1f, 0.0f);//�ړ�

	m_pCollision = NULL;	//�R���W�����̃|�C���^
	m_pPlayer = NULL;		//�v���C���[�̃|�C���^
	m_pShadow = NULL;		//�e�̃|�C���^

	m_bUp = false;			//�������
	m_bDeath = false;		//���S�t���O
}

//******************************
// �f�X�g���N�^
//******************************
CItem::~CItem()
{
}

//******************************
// �N���X����
//******************************
CItem * CItem::Create(D3DXVECTOR3 pos,ITEM_EFFECT effect)
{
	//�������̊m��
	CItem *pItem;
	switch (effect)
	{
	case ITEM_EFFECT_DASH:
		pItem = CDashItem::Create(pos);
		break;
	case ITEM_EFFECT_REVERSE:
		pItem = CReverseItem::Create(pos);
		break;
	}

	//�e����
	pItem->m_pShadow = CShadow::Create(D3DXVECTOR3(pos.x, 0.2f, pos.z), D3DXVECTOR3(8.0f, 0.0f, 8.0f));

	return pItem;
}

//******************************
// ����������
//******************************
HRESULT CItem::Init(void)
{
	//���f��������
	CModel::Init();
	
	// ���f���̃T�C�Y�̐ݒ�
	SetSize(MODEL_SIZE);

	return E_NOTIMPL;
}

//******************************
// �I������
//******************************
void CItem::Uninit(void)
{
	//�R���W�����̏I������
	if (m_pCollision != NULL)
	{
		m_pCollision->OutList();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}

	//���f���̏I������
	CModel::Uninit();
}

//******************************
// �X�V����
//******************************
void CItem::Update(void)
{
	//�ʒu�̎擾
	D3DXVECTOR3 ItemPos = GetPos();

	if (m_pCollision == NULL)
	{
		m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(ItemPos.x, ItemPos.y + ITEM_ONE_SIDE / 2, ItemPos.z), ITEM_ONE_SIDE / 2);
	}
	else
	{
		m_pCollision->SetPos(D3DXVECTOR3(ItemPos.x, ItemPos.y + ITEM_ONE_SIDE / 2, ItemPos.z));
	}
	// �v���C���[�Ƃ̓����蔻��
	CollisionItem();

	//�㉺�̈ړ�
	MoveUpdate();
	//��]
	RotUpdate();

	if (m_bDeath == true)
	{
		CItem::Uninit();
	}
}

//******************************
// �`�揈��
//******************************
void CItem::Draw(void)
{
	CModel::Draw();
}

//******************************
// �ړ��̍X�V����
//******************************
void CItem::MoveUpdate(void)
{
	//�ʒu�̎擾
	D3DXVECTOR3 ItemPos = GetPos();

	if (m_bUp == false)//����ɓ��B���Ă��Ȃ��Ȃ�
	{
		//�ʒu�Ɉړ��ʂ����Z
		ItemPos += m_move;
	}
	else
	{
		//�ʒu�Ɉړ��ʂ����Z
		ItemPos -= m_move;
	}

	//�ʒu�̍Đݒ�
	SetPos(ItemPos);

	//������B
	if (ItemPos.y >= 10.0f)
	{
		m_bUp = true;
	}
	//�������B
	else if (ItemPos.y <= 3.0f)
	{
		m_bUp = false;
	}
}

//******************************
// ��]�̍X�V����
//******************************
void CItem::RotUpdate(void)
{
	//�p�x�̎擾
	D3DXVECTOR3 ItemRot = GetRot();

	//�p�x�̉��Z
	ItemRot += m_rot;

	//�p�x�̐ݒ�
	SetRot(ItemRot);
}

//******************************
// �A�C�e�������蔻�菈��
//******************************
void CItem::CollisionItem(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (CCollision::CollisionSphere(m_pCollision, pPlayer->GetCollision()))
		{
			//���Ńt���O
			m_bDeath = true;
			//�A�C�e�����ʏ���
			ItemEffect(pPlayer);
			//�e�̏I������
			if (m_pShadow != NULL)
			{
				m_pShadow->Uninit();
				m_pShadow = NULL;
			}
			return;
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

//******************************
// �A�C�e�����ʏ���
// Akuthor: �g�c�I�l
//******************************
void CItem::ItemEffect(CPlayer*pPlayer)
{

}

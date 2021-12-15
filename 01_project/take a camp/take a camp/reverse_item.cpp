//=============================================================================
//
// ���o�[�X�A�C�e���̏��� [reverse_item.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//******************************
// �C���N���[�h
//******************************
#include "reverse_item.h"
#include "player.h"

//******************************
// �R���X�g���N�^
//******************************
CReverseItem::CReverseItem()
{
}

//******************************
// �f�X�g���N�^
//******************************
CReverseItem::~CReverseItem()
{
}

//******************************
// �N���X����
//******************************
CReverseItem * CReverseItem::Create(D3DXVECTOR3 pos)
{
	//�������̊m��
	CReverseItem *pItem = nullptr;
	pItem = new CReverseItem;

	if (pItem != nullptr)
	{
		//����������
		pItem->Init();
		//�ʒu�Z�b�g
		pItem->SetPos(pos);

	}
	return pItem;
}

//******************************
// ����������
//******************************
HRESULT CReverseItem::Init(void)
{
	// �A�C�e���̏���������
	CItem::Init();
	// ���f���̊��蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ITEM_REVERSE));

	return S_OK;
}

//******************************
// �A�C�e�����ʏ���
//******************************
void CReverseItem::ItemEffect(CPlayer*pPlayer)
{
	//���̃v���C���[�p�̃|�C���^
	CPlayer * pOthersPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pOthersPlayer != NULL)
	{
		//�����ȊO
		if (pOthersPlayer != pPlayer)
		{
			//���v���C���[�����S��Ԃ���Ȃ���
			if (pOthersPlayer->GetState() != CPlayer::PLAYER_STATE_DEATH)
			{
				//���o�[�X��Ԃɂ���
				pOthersPlayer->SetItemState(CPlayer::ITEM_STATE_REVERSE);
			}
		}
		pOthersPlayer = (CPlayer*)pOthersPlayer->GetNext();
	}
}

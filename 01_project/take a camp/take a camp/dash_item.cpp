//=============================================================================
//
// �_�b�V���A�C�e���̏��� [dash_item.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//******************************
// �C���N���[�h
//******************************
#include "dash_item.h"
#include "player.h"

//******************************
// �R���X�g���N�^
//******************************
CDashItem::CDashItem()
{
}

//******************************
// �f�X�g���N�^
//******************************
CDashItem::~CDashItem()
{
}

//******************************
// �N���X����
//******************************
CDashItem * CDashItem::Create(D3DXVECTOR3 pos)
{
	//�������̊m��
	CDashItem *pItem = nullptr;
	pItem = new CDashItem;

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
HRESULT CDashItem::Init(void)
{
	// �A�C�e���̏���������
	CItem::Init();
	// ���f���̊��蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ITEM_DASH));

	return S_OK;
}

//******************************
// �A�C�e�����ʏ���
//******************************
void CDashItem::ItemEffect(CPlayer*pPlayer)
{
	// �v���C���[�̃A�C�e���X�e�[�g�ω�
	pPlayer->SetItemState(CPlayer::ITEM_STATE_DASH);
}

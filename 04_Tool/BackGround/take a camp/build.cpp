////////////////////////////////////////////////////
//
//    �A�C�e���N���X�̏���[item.cpp]
//    Author:�����x�ߑ�
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "build.h"
#include "manager.h"
#include "keyboard.h"
#include "shadow.h"

//*****************************
// �}�N����`
//*****************************
#define MODEL_SIZE		(D3DXVECTOR3( 0.6f, 0.6f, 0.6f))
#define ITEM_ONE_SIDE	(10.0f)

//******************************
// �R���X�g���N�^
//******************************
CBuild::CBuild() : CModel(OBJTYPE_ITEM)
{
	m_rot = D3DXVECTOR3(0.5f, 0.5f, 0.5f);//�p�x
	m_move = D3DXVECTOR3(0.5f, 0.5f, 0.5f);//�ړ�

	m_pShadow = NULL;		//�e�̃|�C���^

	m_bUp = false;			//�������
}

//******************************
// �f�X�g���N�^
//******************************
CBuild::~CBuild()
{
}

//******************************
// �N���X����
//******************************
CBuild * CBuild::Create(D3DXVECTOR3 pos, BUILD_TYPE type, BUILD_BOOL bBuild)
{
	//�������̊m��
	CBuild *pBuild;
	pBuild = new CBuild;

	//���ʏ����Z�b�g
	pBuild->SetBuildType(type);

	//����������
	pBuild->Init();

	pBuild->SetBuildBool(bBuild);
	//�ʒu�Z�b�g
	pBuild->SetPos(pos);

	//�e����
	pBuild->m_pShadow = CShadow::Create(D3DXVECTOR3(pos.x, 0.2f, pos.z), D3DXVECTOR3(8.0f, 0.0f, 8.0f));

	return pBuild;
}

//******************************
// ����������
//******************************
HRESULT CBuild::Init(void)
{
	//���f��������
	CModel::Init();

	// ���f�����蓖��
	switch (m_BuildType)
	{
	case BUILD_TYPE_0:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ITEM_DASH));
		break;
	case BUILD_TYPE_1:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ITEM_REVERSE));
		break;
	default:
		break;
	}

	// ���f���̃T�C�Y�̐ݒ�
	SetSize(MODEL_SIZE);

	return E_NOTIMPL;
}

//******************************
// �I������
//******************************
void CBuild::Uninit(void)
{
	//���f���̏I������
	CModel::Uninit();
}

//******************************
// �X�V����
//******************************
void CBuild::Update(void)
{
	if (m_BuildBool == BUILD_TRUE)
	{
		//�㉺�̈ړ�
		MoveUpdate();
		//��]
		RotUpdate();
	}
}

//******************************
// �`�揈��
//******************************
void CBuild::Draw(void)
{
	//���f���̕`��
	CModel::Draw();
}

//******************************
// �ړ��̍X�V����
//******************************
void CBuild::MoveUpdate(void)
{
	//�ʒu�̎擾
	D3DXVECTOR3 BuildPos = GetPos();

	if (CManager::GetKeyboard()->GetKeyPress(DIK_W))
	{
		//
		BuildPos.z -= m_move.z;
	}
	if (CManager::GetKeyboard()->GetKeyPress(DIK_S))//
	{
		//
		BuildPos.z += m_move.z;
	}	
	if (CManager::GetKeyboard()->GetKeyPress(DIK_D))//
	{
		//
		BuildPos.x -= m_move.x;
	}	
	if (CManager::GetKeyboard()->GetKeyPress(DIK_A))//
	{
		//
		BuildPos.x += m_move.x;
	}
	if (CManager::GetKeyboard()->GetKeyPress(DIK_SPACE))//
	{
		//
		BuildPos.y += m_move.y;
	}
	if (CManager::GetKeyboard()->GetKeyPress(DIK_LSHIFT))//
	{
		//
		BuildPos.y -= m_move.y;
	}
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
	{
		Save();
		m_BuildBool = BUILD_FALSE;
	}
	//�ʒu�̍Đݒ�
	SetPos(BuildPos);
}

//******************************
// ��]�̍X�V����
//******************************
void CBuild::RotUpdate(void)
{
	//�p�x�̎擾
	D3DXVECTOR3 BuildRot = GetRot();
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_Q))
	{
		BuildRot.y += m_rot.y;
	}
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_E))
	{
		BuildRot.y -= m_rot.y;
	}
	//�p�x�̐ݒ�
	SetRot(BuildRot);
}

void CBuild::Save(void)
{
	FILE* pFile = NULL;
	D3DXVECTOR3 buildPos = GetPos();

	pFile = fopen("data/BuildingInfo.txt", "a");
	if (pFile != NULL)
	{
		fprintf(pFile, "%d\n", m_BuildType);
		fprintf(pFile, "%d %d %d\n", (int)buildPos.x, (int)buildPos.y, (int)buildPos.z);
		fclose(pFile);
	}

}

void CBuild::Load(void)
{
	FILE* pFile = NULL;
	D3DXVECTOR3 buildPos = {};
	BUILD_TYPE type = BUILD_TYPE_0;
	BUILD_BOOL bBuild = BUILD_FALSE;

	pFile = fopen("data/BuildingInfo.txt", "r");

	if (pFile != NULL)
	{
		while (fscanf(pFile, "%d", &type) != EOF)
		{

			fscanf(pFile, "%f %f %f", &buildPos.x, &buildPos.y, &buildPos.z);
			CBuild::Create(buildPos, type, bBuild);
		}

	}
	fclose(pFile);
}


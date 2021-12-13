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
CBuild * CBuild::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, BUILD_TYPE type, BUILD_BOOL bBuild)
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
	pBuild->SetRot(rot);
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
	case BUILD_TYPE_TREE:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_TREE));
		break;
	case BUILD_TYPE_MATO:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_MATO));
		break;
	case BUILD_TYPE_BUKIKAKE:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_BUKITATE));
		break;
	case BUILD_TYPE_CHEST:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_CHEST));
		break;
	case BUILD_TYPE_TARU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODLE_TARU));
		break;
	case BUILD_TYPE_GAITOU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_GAITOU));
		break;
	case BUILD_TYPE_HATA:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_HATA));
		break;
	case BUILD_TYPE_SAKU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_SAKU));
		break;
	case BUILD_TYPE_ENOGU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ENOGU));
		break;
	case BUILD_TYPE_ENPITU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ENPITU));
		break;
	case BUILD_TYPE_MAGCUP:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_MAGCUP));
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
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_DELETE))
	{
		Uninit();
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
	D3DXVECTOR3 buildRot = GetRot();

	pFile = fopen("data/BuildingInfo.txt", "a");
	if (pFile != NULL)
	{
		fprintf(pFile, "%d\n", m_BuildType);
		fprintf(pFile, "%d %d %d\n", (int)buildPos.x, (int)buildPos.y, (int)buildPos.z);
		fprintf(pFile, "%d %d %d\n", (int)buildRot.x, (int)buildRot.y, (int)buildRot.z);
		fclose(pFile);
	}

}

void CBuild::Load(void)
{
	FILE* pFile = NULL;
	D3DXVECTOR3 buildPos = {};
	D3DXVECTOR3 buildRot = {};
	BUILD_TYPE type = BUILD_TYPE_TREE;
	BUILD_BOOL bBuild = BUILD_FALSE;

	pFile = fopen("data/BuildingInfo.txt", "r");

	if (pFile != NULL)
	{
		while (fscanf(pFile, "%d", &type) != EOF)
		{
			fscanf(pFile, "%f %f %f", &buildPos.x, &buildPos.y, &buildPos.z);
			fscanf(pFile, "%f %f %f", &buildRot.x, &buildRot.y, &buildRot.z);
			CBuild::Create(buildPos, buildRot, type, bBuild);
		}

	}
	fclose(pFile);
}


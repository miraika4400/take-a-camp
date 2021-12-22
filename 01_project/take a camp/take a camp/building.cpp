////////////////////////////////////////////////////
//
//    �A�C�e���N���X�̏���[item.cpp]
//    Author:�����x�ߑ�
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "building.h"
#include "manager.h"
#include "keyboard.h"
#include "game.h"

//*****************************
// �}�N����`
//*****************************
#define MODEL_SIZE		(D3DXVECTOR3( 0.6f, 0.6f, 0.6f))
#define ITEM_ONE_SIDE	(10.0f)

//******************************
// �R���X�g���N�^
//******************************
CBuilding::CBuilding() : CModel(OBJTYPE_BULDING)
{
	m_rot = D3DXVECTOR3(0.5f, 0.5f, 0.5f);//�p�x
	m_move = D3DXVECTOR3(0.5f, 0.5f, 0.5f);//�ړ�
}

//******************************
// �f�X�g���N�^
//******************************
CBuilding::~CBuilding()
{
}

//******************************
// �N���X����
//******************************
CBuilding * CBuilding::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, BUILDING_TYPE type)
{
	//�������̊m��
	CBuilding *pBuilding;
	pBuilding = new CBuilding;

	//�I�u�W�F�N�g�^�C�v�Z�b�g
	pBuilding->SetBuildType(type);

	//����������
	pBuilding->Init();

	//�ʒu,�p�x�Z�b�g
	pBuilding->SetPos(pos);
	pBuilding->SetRot(rot);
	return pBuilding;
}

//******************************
// ����������
//******************************
HRESULT CBuilding::Init(void)
{
	//���f��������
	CModel::Init();

	// ���f�����蓖��
	switch (m_BuildingType)
	{
	case BUILDING_TYPE_TREE:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_TREE));
		break;
	case BUILDING_TYPE_MATO:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_MATO));
		break;
	case BUILDING_TYPE_BUKIKAKE:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_BUKITATE));
		break;
	case BUILDING_TYPE_CHEST:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_CHEST));
		break;
	case BUILDING_TYPE_TARU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODLE_TARU));
		break;
	case BUILDING_TYPE_GAITOU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_GAITOU));
		break;
	case BUILDING_TYPE_HATA:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_HATA));
		break;
	case BUILDING_TYPE_SAKU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_SAKU));
		break;
	case BUILDING_TYPE_ENOGU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ENOGU));
		break;
	case BUILDING_TYPE_ENPITU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ENPITU));
		break;
	case BUILDING_TYPE_MAGCUP:
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
void CBuilding::Uninit(void)
{
	//���f���̏I������
	CModel::Uninit();
}

//******************************
// �X�V����
//******************************
void CBuilding::Update(void)
{

}

//******************************
// �`�揈��
//******************************
void CBuilding::Draw(void)
{
	//���f���̕`��
	CModel::Draw();
}

//******************************
//�w�i�I�u�W�F�N�g�ǂݍ��ݏ���
//******************************
void CBuilding::Load(void)
{
	FILE* pFile = NULL;
	D3DXVECTOR3 buildPos = {};
	D3DXVECTOR3 buildRot = {};
	BUILDING_TYPE type = BUILDING_TYPE_TREE;

	if (CGame::GetMapType() == CMapManager::MAP_TYPE_1)pFile = fopen("data/Text/stage/bgObj/BuildingInfo_1.txt", "r");
	else if (CGame::GetMapType() == CMapManager::MAP_TYPE_2)pFile = fopen("data/Text/stage/bgObj/BuildingInfo_2.txt", "r");
	else if (CGame::GetMapType() == CMapManager::MAP_TYPE_3)pFile = fopen("data/Text/stage/bgObj/BuildingInfo_3.txt", "r");

	if (pFile != NULL)
	{
		//�^�C�v���擾�ł��Ȃ��Ȃ�܂Ń��[�v
		while (fscanf(pFile, "%d", &type) != EOF)
		{
			//���W�擾
			fscanf(pFile, "%f %f %f", &buildPos.x, &buildPos.y, &buildPos.z);
			//�p�x�擾
			fscanf(pFile, "%f %f %f", &buildRot.x, &buildRot.y, &buildRot.z);
			CBuilding::Create(buildPos, buildRot, type);
		}
	}
	fclose(pFile);
}
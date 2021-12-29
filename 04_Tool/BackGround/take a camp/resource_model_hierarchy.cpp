////////////////////////////////////////////////////
//
//    resource_model_hierarchy�N���X�̏���[resource_model_hierarchy.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "resource_model_hierarchy.h"
#include "renderer.h"
#include "manager.h"

//******************************
// �}�N����`
//******************************

//******************************
// �ÓI�����o�ϐ��錾
//******************************
CResourceModelHierarchy *CResourceModelHierarchy::m_pSingle = NULL; //���f���N���X�̃|�C���^*�V���O���g���p
// ���f���̃p�X
const std::string CResourceModelHierarchy::m_aModelPath[CResourceModelHierarchy::MODEL_HIERARCHY_MAX]
{
	"data/Text/hierarchy/Knight.txt",
	"data/Text/hierarchy/Lancer.txt",
	"data/Text/hierarchy/wizard.txt",
};

//===================================
// �R���X�g���N�^
//===================================
CResourceModelHierarchy::CResourceModelHierarchy()
{
	memset(&m_aModelHierarchy, 0, sizeof(m_aModelHierarchy));
}

//===================================
// �f�X�g���N�^
//===================================
CResourceModelHierarchy::~CResourceModelHierarchy()
{
}

//=============================================================================
//���f���N���X�̃N���G�C�g����
//=============================================================================
CResourceModelHierarchy * CResourceModelHierarchy::Create(void)
{
	if (m_pSingle == NULL)
	{
		// �������m��
		m_pSingle = new CResourceModelHierarchy;

		if (m_pSingle != NULL)
		{
			// �������m�ۂɐ��������Ƃ�
			m_pSingle->Load();
		}
		else
		{
			// �������m�ۂɎ��s�����Ƃ�
			return NULL;
		}
	}

	return m_pSingle;
}

//===================================
// �N���X�̔j��
//===================================
void CResourceModelHierarchy::Release(void)
{
	if (m_pSingle != NULL)
	{
		// �e�N�X�`���j��
		m_pSingle->Unload();
		// �������̔j��
		delete m_pSingle;
		m_pSingle = NULL;
	}
}

//===================================
// ���f���擾
//===================================
CResourceModelHierarchy::ModelHierarchy CResourceModelHierarchy::GetModel(CResourceModelHierarchy::MODEL_HIERARCHY_TYPE type)
{
	if (m_pSingle != NULL)
	{
		return m_pSingle->m_aModelHierarchy[type];
	}
	else
	{
		return ModelHierarchy();
	}
}

//===================================
// �e�N�X�`���ǂݍ���
//===================================
void CResourceModelHierarchy::Load(void)
{
	for (int nCntHierarchy = 0; nCntHierarchy < MODEL_HIERARCHY_MAX; nCntHierarchy++)
	{
		LoadModels(m_aModelPath[nCntHierarchy].c_str(), &m_aModelHierarchy[nCntHierarchy]);
		LoadHierarchy(m_aModelHierarchy[nCntHierarchy].aModelData, m_aModelPath[nCntHierarchy].c_str());
	}
}

//===================================
// �e�L�X�g�t�@�C���ǂݍ���
//===================================
void CResourceModelHierarchy::LoadModels(const char * pPath, ModelHierarchy *data)
{
	// �t�@�C���I�[�v��
	FILE*pFile = NULL;
	pFile = fopen(pPath, "r");

	if (pFile != NULL)
	{
		// �e�L�X�g�t�@�C���̉��

		char chChar[256] = {};
		fscanf(pFile, "%s", chChar);

		// "NUM_MODEL"�ǂݍ��ނ܂Ń��[�v
		while (strcmp(chChar, "NUM_MODEL") != 0)
		{
			fscanf(pFile, "%s", chChar);
		}

		// �ǂݍ��ރ��f���̐�
		fscanf(pFile, "%*s %d # %*s", &data->nPartsNum);

		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

		for (int nCnt = 0; nCnt < data->nPartsNum; nCnt++)
		{
			// �ǂݍ��񂾕����i�[�p
			char chPath[64] = {};
			// "MODEL_FILENAME"��ǂݍ��ނ܂Ń��[�v
			while (strcmp(chChar, "MODEL_FILENAME") != 0)
			{
				fscanf(pFile, "%s", chChar);
			}
			// �t�@�C���p�X�̓ǂݍ���
			fscanf(pFile, "%*s %s", chPath);

			// X�t�@�C���̓ǂݍ���
			D3DXLoadMeshFromX(chPath,
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&data->aModelData[nCnt].pBuffMat,
				NULL,
				&data->aModelData[nCnt].nNumMat,
				&data->aModelData[nCnt].pMesh);

			// �e�N�X�`���ǂݍ���
			if (data->aModelData[nCnt].nNumMat != 0)
			{
				D3DXMATERIAL*pMat = (D3DXMATERIAL*)data->aModelData[nCnt].pBuffMat->GetBufferPointer();

				for (int nCntMat = 0; nCntMat < (int)data->aModelData[nCnt].nNumMat; nCntMat++)
				{
					data->aModelData[nCnt].defMat[nCntMat] = pMat[nCntMat];
					if (pMat[nCntMat].pTextureFilename != NULL)
					{
						char cPath[128] = {};
						sprintf(cPath, "./data/Textures/%s", pMat[nCntMat].pTextureFilename);
						// �e�N�X�`���̐���
						D3DXCreateTextureFromFile(pDevice, cPath, &data->aModelData[nCnt].apTexture[nCntMat]);
					}
				}
			}

			// ���̕�����ǂݍ���
			fscanf(pFile, "%s", chChar);
		}

		fclose(pFile);
	}
}

//===================================
// �K�w�\���̓ǂݍ���
//===================================
void CResourceModelHierarchy::LoadHierarchy(CResourceModel::Model * model, const char * pPath)
{
	// �t�@�C���I�[�v��
	FILE*pFile = NULL;
	pFile = fopen(pPath, "r");

	// �p�[�c��
	int nPartsNum = 0;

	if (pFile != NULL)
	{
		// �e�L�X�g�t�@�C���̉��

		char chChar[256] = {};
		fscanf(pFile, "%s", chChar);

		// "SCRIPT"�ǂݍ��ނ܂Ń��[�v
		while (strcmp(chChar, "CHARACTERSET") != 0)
		{
			fscanf(pFile, "%s", chChar);
		}

		// �����r���p
		char cString[32] = {};

		fscanf(pFile, "%s %s %d", &cString, &cString, &nPartsNum);

		// "END_PARTSSET"�ǂݍ��ނ܂Ń��[�v
		while (strcmp(chChar, "END_CHARACTERSET") != 0)
		{
			fscanf(pFile, "%s", chChar);
			if (strcmp(chChar, "PARTSSET") == 0)
			{
				// �C���f�b�N�X�ꎞ�ۊǗp
				int nIndex = 0;
				// �C���f�b�N�X�̓ǂݍ���
				fscanf(pFile, "%*s %*s %d # %*s", &nIndex);
				// �e�ԍ��̓ǂݍ���
				fscanf(pFile, "%*s %*s %d # %*s", &model[nIndex].nParent);
				// ���W�̓ǂݍ���
				fscanf(pFile, "%*s %*s %f %f %f", &model[nIndex].pos.x, &model[nIndex].pos.y, &model[nIndex].pos.z);
				// ��]�̓ǂݍ���
				fscanf(pFile, "%*s %*s %f %f %f", &model[nIndex].rot.x, &model[nIndex].rot.y, &model[nIndex].rot.z);

				fscanf(pFile, "%*s");
			}

		}
		fclose(pFile);
	}
}

//===================================
// �j��
//===================================
void CResourceModelHierarchy::Unload(void)
{
	for (int nCnt = 0; nCnt < MODEL_HIERARCHY_MAX; nCnt++)
	{
		for (int nCntParts = 0; nCntParts < m_aModelHierarchy[nCnt].nPartsNum; nCntParts++)
		{
			// ���b�V���̉��
			if (m_aModelHierarchy[nCnt].aModelData[nCntParts].pMesh != NULL)
			{
				m_aModelHierarchy[nCnt].aModelData[nCntParts].pMesh->Release();
				m_aModelHierarchy[nCnt].aModelData[nCntParts].pMesh = NULL;
			}
			// �o�b�t�@�̉��
			if (m_aModelHierarchy[nCnt].aModelData[nCntParts].pBuffMat != NULL)
			{
				m_aModelHierarchy[nCnt].aModelData[nCntParts].pBuffMat->Release();
				m_aModelHierarchy[nCnt].aModelData[nCntParts].pBuffMat = NULL;
			}

			// �}�e���A���������[�v
			for (int nCntTex = 0; nCntTex < (int)m_aModelHierarchy[nCnt].aModelData[nCnt].nNumMat; nCntTex++)
			{
				// �e�N�X�`���̉��
				if (m_aModelHierarchy[nCnt].aModelData[nCntParts].apTexture[nCntTex] != NULL)
				{
					m_aModelHierarchy[nCnt].aModelData[nCntParts].apTexture[nCntTex]->Release();
					m_aModelHierarchy[nCnt].aModelData[nCntParts].apTexture[nCntTex] = NULL;
				}
			}
		}
	}
}

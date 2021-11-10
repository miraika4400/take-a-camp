//=============================================================================
//
// resource_model_hierarchy�w�b�_ [resource_model_hierarchy.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _RESOURCEMODEL_HIERARCHY_H_
#define _RESOURCEMODEL_HIERARCHY_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "resource_model.h"

//=============================================================================
//�}�N����`
//=============================================================================
#define MAX_PARTS_NUM 32 // �p�[�c�̍ő吔

//*****************************
//�N���X��`
//*****************************

// �K�w�\�����f�����\�[�X�N���X
class CResourceModelHierarchy
{
public:

	//============
	//�\����
	//============
	// ���f���f�[�^
	typedef struct
	{
		CResourceModel::Model aModelData[MAX_PARTS_NUM];
		int nPartsNum;
	}ModelHierarchy;

	// ��
	// ���f�����
	typedef enum
	{
		MODEL_HIERARCHY_KNIGHT = 0, // �v���C���[
		MODEL_HIERARCHY_MAX        // �S�̐�
	}MODEL_HIERARCHY_TYPE;

	// �����o�֐�
	static CResourceModelHierarchy * Create(void);                  // �N���X����
	static void Release(void);                               // �N���X�j��
	static ModelHierarchy GetModel(MODEL_HIERARCHY_TYPE type); // ���f���̎擾����*�����F�擾���������f��

private:
	CResourceModelHierarchy();//�B���R���X�g���N�^
public:
	~CResourceModelHierarchy();

private:
	void Load(void);     // ���f���ǂݍ���
	void LoadModels(const char * pPath, ModelHierarchy *data);    // �e�L�X�g�t�@�C���̓ǂݍ���
	void LoadHierarchy(CResourceModel::Model *model, const char*pPath); // �K�w�\���̓ǂݍ���
	void Unload(void); // ���f���j��

					   // �����o�ϐ�
	static const std::string m_aModelPath[MODEL_HIERARCHY_MAX]; // ���f���̃p�X
	static CResourceModelHierarchy *m_pSingle;              // ���f���N���X�̃|�C���^*�V���O���g���p
	ModelHierarchy m_aModelHierarchy[MODEL_HIERARCHY_MAX];               // ���f���̃|�C���^
};

#endif
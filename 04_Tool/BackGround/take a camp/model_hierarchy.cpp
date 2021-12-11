//=============================================================================
//
// ���f������ [ModelHirarchy.cpp]
// Author : ���V����
//
//=============================================================================
#include "model_hierarchy.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CModelHierarchy::CModelHierarchy(int nPriority) :CScene(nPriority)
{
	// �ϐ��̃N���A
	memset(&m_model, 0, sizeof(m_model));
	m_nNumParts = 0;
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	for (int nCnt = 0; nCnt < MAX_PARTS_NUM; nCnt++)
	{
		m_model[nCnt].size = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	}
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CModelHierarchy::~CModelHierarchy()
{
}

//=============================================================================
//����������
//=============================================================================
HRESULT CModelHierarchy::Init(void)
{

	return S_OK;
}

HRESULT CModelHierarchy::Init(CResourceModelHierarchy::MODEL_HIERARCHY_TYPE modelType)
{
	//LoadHierarchy(model, pPath);
	//// �����̑��
	//m_nNumParts = nNumParts;
	CResourceModelHierarchy::ModelHierarchy modelData = CResourceModelHierarchy::GetModel (modelType);
	m_nNumParts = modelData.nPartsNum;

	for (int nCnt = 0; nCnt < m_nNumParts; nCnt++)
	{
		m_model[nCnt] = modelData.aModelData[nCnt];

		for (int nCntMat = 0; nCntMat < (int)m_model[nCnt].nNumMat; nCntMat++)
		{
			m_model[nCnt].defMat[nCntMat] = ((D3DXMATERIAL*)m_model[nCnt].pBuffMat->GetBufferPointer())[nCntMat];
		}
	}

	return S_OK;
}

//=============================================================================
//�I������
//=============================================================================
void CModelHierarchy::Uninit(void)
{
	//�I�u�W�F�N�g�̔j��
	Release();
}

//=============================================================================
//�X�V����
//=============================================================================
void CModelHierarchy::Update(void)
{
}

//=============================================================================
//�`�揈��
//=============================================================================
void CModelHierarchy::Draw(void)
{
	// ���W�A�T�C�Y�A��]�̐ݒ�
	SetWorldmtx();
	// ���f���̕`�揈��
	DrawModel();
}

//=============================================================================
//���f���f�[�^�̃Z�b�g
//=============================================================================
void CModelHierarchy::SetModelData(CResourceModel::Model *pModel)
{
	for (int nCnt = 0; nCnt < m_nNumParts; nCnt++)
	{
		m_model[nCnt].pos = pModel[nCnt].pos;
		m_model[nCnt].rot = pModel[nCnt].rot;
	}
}

//=============================================================================
//���[���h�}�g���b�N�X�̐ݒ�
//=============================================================================
void CModelHierarchy::SetWorldmtx(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	// ��]�A�ʒu�A�T�C�Y�s��
	D3DXMATRIX mtxRot, mtxTrans, mtxScail;

	for (int nCntParts = 0; nCntParts < m_nNumParts; nCntParts++)
	{

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_model[nCntParts].mtxWorld);

		if (m_model[nCntParts].nParent == -1)
		{// ��������Ԃ̐e�̂Ƃ�
		
			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, m_model[nCntParts].rot.y, m_model[nCntParts].rot.x, m_model[nCntParts].rot.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxRot, m_model[nCntParts].pos.x, m_model[nCntParts].pos.y, m_model[nCntParts].pos.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxRot);

			//�X�P�[���̔��f�i�X�P�[�����W�̕ϊ��s��j
			D3DXMatrixScaling(&mtxScail, m_size.x, m_size.y, m_size.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxScail);

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxTrans);

		}
		else
		{// ��������Ԃ̐e����Ȃ��Ƃ�

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, m_model[nCntParts].rot.y, m_model[nCntParts].rot.x, m_model[nCntParts].rot.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, m_model[nCntParts].pos.x, m_model[nCntParts].pos.y, m_model[nCntParts].pos.z);
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &mtxTrans);

			// �e�̃��[���h�}�g���b�N�X���|�����킹��
			D3DXMatrixMultiply(&m_model[nCntParts].mtxWorld, &m_model[nCntParts].mtxWorld, &m_model[m_model[nCntParts].nParent].mtxWorld);
		}
	}
}

//=============================================================================
//���f���̕`�揈��
//=============================================================================
void CModelHierarchy::DrawModel(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DMATERIAL9 matDef;	//���݂̃}�e���A���ێ��p
	D3DXMATERIAL*pMat;	//�}�e���A���f�[�^�ւ̃|�C���^

	for (int nCntParts = 0; nCntParts < m_nNumParts; nCntParts++)
	{
		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &m_model[nCntParts].mtxWorld);

		//���݂̃}�e���A�����擾����
		pDevice->GetMaterial(&matDef);

		//�}�e���A���f�[�^�ւ̃|�C���^���擾

		pMat = (D3DXMATERIAL*)m_model[nCntParts].pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_model[nCntParts].nNumMat; nCntMat++)
		{
			//�}�e���A���̃A���r�G���g�Ƀf�B�t���[�Y�J���[��ݒ�
			pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

			//�}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
			// �e�N�X�`��
			pDevice->SetTexture(0, m_model[nCntParts].apTexture[nCntMat]);
			//���f���p�[�c�̕`��
			m_model[nCntParts].pMesh->DrawSubset(nCntMat);

			pMat[nCntMat] = m_model[nCntParts].defMat[nCntMat];
		}

		//�ێ����Ă����}�e���A����߂�
		pDevice->SetMaterial(&matDef);
		// �e�N�X�`���̏�����
		pDevice->SetTexture(0, 0);
	}
}

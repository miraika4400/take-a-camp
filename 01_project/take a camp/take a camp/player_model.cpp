////////////////////////////////////////////////////
//
//    player�N���X�̏���[player.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "player_model.h"
#include "motion.h"
#include "chara_select.h"
#include "manager.h"
#include "renderer.h"
#include "resource_shader.h"
#include "resource_texture.h"
#include "color_manager.h"
#include "camera_base.h"
#include "light.h"

//******************************
// �R���X�g���N�^
//******************************
CPlayerModel::CPlayerModel() :CModelHierarchy(OBJTYPE_BG)
{
	m_charaType = CResourceCharacter::CHARACTER_NONE;
	memset(&m_apMotion, 0, sizeof(m_apMotion));	// �A�j���[�V�����|�C���^
	m_RimColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

//******************************
// �f�X�g���N�^
//******************************
CPlayerModel::~CPlayerModel()
{
}

//******************************
// �N���X����
//******************************
CPlayerModel * CPlayerModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CResourceCharacter::CHARACTER_TYPE charaType)
{
	// �������̊m��
	CPlayerModel *pPlayerModel;
	pPlayerModel = new CPlayerModel;

	// ������
	pPlayerModel->Init();
	// init�Ŏg�������ɑ��
	pPlayerModel->SetCharacterType(charaType);

	// �e�l�̑���E�Z�b�g
	pPlayerModel->SetPos(pos);
	pPlayerModel->SetRot(rot);
	pPlayerModel->SetPriority(OBJTYPE_BG); // �I�u�W�F�N�g�^�C�v

	return pPlayerModel;
}

//******************************
// ����������
//******************************
HRESULT CPlayerModel::Init(void)
{
	// �L�����f�[�^�̎擾
	SetCharacterType(m_charaType);

	return S_OK;
}

//******************************
// �X�V����
//******************************
void CPlayerModel::Update(void)
{
	ManageMotion();
}

//******************************
// �L�����^�C�v�̃Z�b�g
//******************************
void CPlayerModel::SetCharacterType(CResourceCharacter::CHARACTER_TYPE type)
{
	// �L�����^�C�v�̎擾
	if (m_charaType == type)
	{
		return;
	}
	// �^�C�v�̐؂�ւ�
	m_charaType = type;
	// �L�����f�[�^�̎擾
	CResourceCharacter::CharacterData charaData = CResourceCharacter::GetResourceCharacter()->GetCharacterData(m_charaType);
	// ���f���̏�����
	CModelHierarchy::Init(charaData.modelType);

	for (int nCntAnim = 0; nCntAnim < CResourceCharacter::MOTION_MAX; nCntAnim++)
	{
		if (m_apMotion[nCntAnim] != NULL)
		{// �����̃��[�V�����̍폜
			m_apMotion[nCntAnim]->OutList();
			m_apMotion[nCntAnim]->Uninit();
			delete m_apMotion[nCntAnim];
			m_apMotion[nCntAnim] = NULL;
		}
		// �V�������[�V�����̐���
		m_apMotion[nCntAnim] = CMotion::Create(GetPartsNum(), charaData.aMotionTextPath[nCntAnim].c_str(), GetModelData());
	}
	// �A�C�h�����[�V�����̍Đ�
	m_apMotion[CResourceCharacter::MOTION_IDLE]->SetActiveMotion(true);
}

//******************************
// ���[�V�����Ǘ�
//******************************
void CPlayerModel::ManageMotion(void)
{
	for (int nCntMotion = 0; nCntMotion < CResourceCharacter::MOTION_MAX; nCntMotion++)
	{
		if (m_apMotion[CResourceCharacter::MOTION_IDLE]->GetActiveMotion())
		{
			if (nCntMotion == CResourceCharacter::MOTION_IDLE)
			{
				continue;
			}

			if (m_apMotion[nCntMotion]->GetActiveMotion())
			{
				m_apMotion[CResourceCharacter::MOTION_IDLE]->SetActiveMotion(false);
			}
		}
		else
		{
			if (nCntMotion == CResourceCharacter::MOTION_IDLE)
			{
				continue;
			}
			if (m_apMotion[nCntMotion]->GetActiveMotion())
			{
				break;
			}
			m_apMotion[CResourceCharacter::MOTION_IDLE]->SetActiveMotion(true);
		}
	}
}

//******************************
// ���f���`�揈��
//******************************
void CPlayerModel::DrawModel(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DMATERIAL9 matDef;	//���݂̃}�e���A���ێ��p
	D3DXMATERIAL*pMat;	//�}�e���A���f�[�^�ւ̃|�C���^

	CResourceModel::Model *pModelData = GetModelData();

	for (int nCntParts = 0; nCntParts < GetPartsNum(); nCntParts++)
	{
		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &pModelData[nCntParts].mtxWorld);

		//���݂̃}�e���A�����擾����
		pDevice->GetMaterial(&matDef);

		// �V�F�[�_�[���̎擾
		CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_PLAYER);

		if (shader.pEffect != NULL)
		{
			// �V�F�[�_�[�v���O�����ɒl�𑗂�
			SetShaderVariable(shader.pEffect, &pModelData[nCntParts]);

			//�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)pModelData[nCntParts].pBuffMat->GetBufferPointer();

			// �p�X���̎擾
			UINT numPass = 0;
			shader.pEffect->Begin(&numPass, 0);

			// �p�X�����`�揈���̃��[�v
			for (int nCntMat = 0; nCntMat < (int)pModelData[nCntParts].nNumMat; nCntMat++)
			{
				//�}�e���A���̃A���r�G���g�Ƀf�B�t���[�Y�J���[��ݒ�
				pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

				//�}�e���A���̐ݒ�
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
				// �e�N�X�`��
				pDevice->SetTexture(0, pModelData[nCntParts].apTexture[nCntMat]);
				// �e�N�X�`�����V�F�[�_�[�ɑ���
				shader.pEffect->SetTexture("Tex", pModelData[nCntParts].apTexture[nCntMat]);
				// �F
				shader.pEffect->SetFloatArray("DiffuseColor", (float*)&pMat[nCntMat].MatD3D.Diffuse, 4);

				if (pModelData[nCntParts].apTexture[nCntMat] == NULL)
				{
					// �V�F�[�_�p�X�̕`��J�n
					shader.pEffect->BeginPass(0);
				}
				else
				{
					// �V�F�[�_�p�X�̕`��J�n
					shader.pEffect->BeginPass(1);
				}

				// ���f���p�[�c�̕`��
				pModelData[nCntParts].pMesh->DrawSubset(nCntMat);
				// �V�F�[�_�p�X�̏I��
				shader.pEffect->EndPass();

				pMat[nCntMat] = pModelData[nCntParts].defMat[nCntMat];

			}
			// �V�F�[�_�[�I��
			shader.pEffect->End();
		}

		//�ێ����Ă����}�e���A����߂�
		pDevice->SetMaterial(&matDef);
		// �e�N�X�`���̏�����
		pDevice->SetTexture(0, 0);
	}
}


//=============================
// �V�F�[�_�[�ɒl�𑗂�
//=============================
void CPlayerModel::SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData)
{
	if (pEffect != NULL)
	{
		// �V�F�[�_�[�ɏ���n��
		D3DXMATRIX mat;
		D3DXMatrixIdentity(&mat);
		mat = pModelData->mtxWorld * (*CManager::GetCamera()->GetViewMtx())* (*CManager::GetCamera()->GetProjectionMtx());
		// ���[���h�v���W�F�N�V����
		pEffect->SetMatrix("WorldViewProj", &mat);
		// ���[���h���W
		pEffect->SetMatrix("World", &pModelData->mtxWorld);
		// ���C�g�f�B���N�V����
		D3DXVECTOR3 lightDir = CManager::GetLight()->GetDir();
		pEffect->SetFloatArray("LightDirection", (float*)&D3DXVECTOR3(lightDir.x, -lightDir.y, -lightDir.z), 3);
		// ���_�ʒu
		D3DXVECTOR3 eye = CManager::GetCamera()->GetPosV();
		pEffect->SetFloatArray("Eye", (float*)&D3DXVECTOR3(eye.x, eye.y, eye.z), 3);
		// �X�y�L�����̏��𑗂�
		pEffect->SetFloatArray("SpecularColor", (float*)&D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 4);
		// �����J���[�̏��𑗂�
		pEffect->SetFloatArray("RimColor", (float*)&m_RimColor, 4);
		pEffect->SetFloat("RimPower", RIM_POWER);
		// �L���[�u�e�N�X�`��
		pEffect->SetTexture("CubeTex", CResourceTexture::GetCubeTexture(CResourceTexture::TECTURE_CUBE_SLY));
		// �g�D�[���V���h�E�e�N�X�`�����V�F�[�_�[�ɑ���
		pEffect->SetTexture("ToonTex", CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TOON_SHADOW));
	}
}

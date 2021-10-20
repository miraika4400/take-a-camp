////////////////////////////////////////////////////
//
//    tile�N���X�̏���[tile.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "tile.h"
#include "manager.h"
#include "renderer.h"
#include "resource_shader.h"
#include "camera_base.h"
#include "light.h"
#include "collision.h"
#include "bullet.h"
#ifdef _DEBUG
#include "keyboard.h"
#endif

//*****************************
// �}�N����`
//*****************************
#define PEINT_COUNT 60  // �ēx�h���悤�ɂȂ�܂ł̃J�E���g

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CTile::CTile() :CModel(OBJTYPE_TILE)
{                       
	m_color = TILE_DEFAULT_COLOR;
	m_pCollison = NULL;
}

//******************************
// �f�X�g���N�^
//******************************
CTile::~CTile()
{
}

//******************************
// �N���X����
//******************************
CTile * CTile::Create(D3DXVECTOR3 pos)
{
	// �������̊m��
	CTile *pTile;
	pTile = new CTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v

	return pTile;
}

//******************************
// ����������
//******************************
HRESULT CTile::Init(void)
{
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// ���f�����蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_GENERAL_BOX));

	// �T�C�Y�̐ݒ�
	SetSize(TILE_SIZE);

	// �F�̐ݒ�
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	return S_OK;
}

//******************************
// �I������
//******************************
void CTile::Uninit(void)
{
	CModel::Uninit();
}

//******************************
// �X�V����
//******************************
void CTile::Update(void)
{
	if (m_pCollison == NULL)
	{
		m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + TILE_ONE_SIDE / 2, GetPos().z), TILE_ONE_SIDE / 2);
	}
	else
	{
		if (m_pCollison->GetPos() != D3DXVECTOR3(GetPos().x, GetPos().y + TILE_ONE_SIDE / 2, GetPos().z))
		{
			m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + TILE_ONE_SIDE / 2, GetPos().z));
		}
	}

	// �e�Ƃ̓����蔻��
	CollisionBullet();
}

//******************************
// �`�揈��
//******************************
void CTile::Draw(void)
{
	/////////////////////////////�@
	//��
	// �F�̐ݒ�
	D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
	mat->MatD3D.Ambient = m_color;
	mat->MatD3D.Diffuse = m_color;
	mat->MatD3D.Specular = m_color;
	mat->MatD3D.Emissive = m_color;

	////////////////////////////

	CModel::Draw();
}

//******************************
// ���f���`�揈��
//******************************
void CTile::DrawModel(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DMATERIAL9 matDef; //���݂̃}�e���A���ێ��p
	D3DXMATERIAL*pMat;   //�}�e���A���f�[�^�ւ̃|�C���^

	// ���f���f�[�^�̎擾
	CResourceModel::Model * pModelData = GetModelData();

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &pModelData->mtxWorld);

	//���݂̃}�e���A�����擾����
	pDevice->GetMaterial(&matDef);

	// �V�F�[�_�[���̎擾
	CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_TILE);
	if (shader.pEffect != NULL)
	{
		// �V�F�[�_�[�v���O�����ɒl�𑗂�
		SetShaderVariable(shader.pEffect, pModelData);
		if (pModelData->pBuffMat != NULL)
		{
			//�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)pModelData->pBuffMat->GetBufferPointer();

			// �p�X���̎擾
			UINT numPass = 0;
			shader.pEffect->Begin(&numPass, 0);

			// �p�X�����`�揈���̃��[�v
			for (int nCntEffect = 0; nCntEffect < (int)numPass; nCntEffect++)
			{
				for (int nCntMat = 0; nCntMat < (int)pModelData->nNumMat; nCntMat++)
				{
					//�}�e���A���̃A���r�G���g�Ƀf�B�t���[�Y�J���[��ݒ�
					pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

					//�}�e���A���̐ݒ�
					pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
					// �e�N�X�`��
					pDevice->SetTexture(0, pModelData->apTexture[nCntMat]);

					// �F�̏��𑗂�
					shader.pEffect->SetFloatArray("DiffuseColor", (float*)&m_color, 4);

					// �V�F�[�_�p�X�̕`��J�n
					shader.pEffect->BeginPass(nCntEffect);
					//���f���p�[�c�̕`��
					pModelData->pMesh->DrawSubset(nCntMat);
					// �V�F�[�_�p�X�̏I��
					shader.pEffect->EndPass();

					pMat[nCntMat] = pModelData->defMat[nCntMat];
				}
			}
			// �V�F�[�_�[�I��
			shader.pEffect->End();
		}
	}
	//�ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
	// �e�N�X�`�����̏�����
	pDevice->SetTexture(0, 0);
}


//=============================
// �V�F�[�_�[�ɒl�𑗂�
//=============================
void CTile::SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData)
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
		D3DXVECTOR3 lightDir = LIGHT_DIR_BASE;
		pEffect->SetFloatArray("LightDirection", (float*)&D3DXVECTOR3(lightDir.x, lightDir.y, lightDir.z), 3);

		// ���_�ʒu
		D3DXVECTOR3 eye = CManager::GetCamera()->GetPos();
		pEffect->SetFloatArray("Eye", (float*)&D3DXVECTOR3(eye.x, eye.y, eye.z), 3);

		// �X�y�L�����̏��𑗂�
		pEffect->SetFloatArray("SpecularColor", (float*)&D3DXCOLOR(1.0f,1.0f,1.0f,1.0f), 4);
	}
}

//******************************
// �e�Ƃ̓����蔻��
//******************************
void CTile::CollisionBullet(void)
{
	CBullet * pBullet = (CBullet*)GetTop(OBJTYPE_BULLET);

	while (pBullet != NULL)
	{
		if (CCollision::CollisionSphere(GetCollision(), pBullet->GetCollision()))
		{

			return;
		}
		pBullet = (CBullet*)pBullet->GetNext();
	}
}
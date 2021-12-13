//=============================================================================
//
// �X�L���T�[�N������ [skill_circle.cpp]
// Author : �V����s
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "base_Cylinder.h"
#include "manager.h"
#include "renderer.h"
#include "resource_texture.h"
#include "particle.h"
//=============================================================================
//�ÓI�����o�[�ϐ�
//=============================================================================

//=============================================================================
//�R���X�g���N�^
//=============================================================================
Cbase_Cylinder::Cbase_Cylinder(int nPriority) :CScene(nPriority)
{
	m_apTexture = NULL;
	m_pVtxBuff = NULL;									  
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				  
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				  
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				  
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			  
	m_nLife = 500;										  
	m_fRotAngle = 0.0f;									  
	m_fFadeout = 0.0f;									  
	m_bFadeoutFlag = true;								  
	m_col = { 1.0f,0.0f,0.0f,1.0f };				  
	m_mtxWorld = {};									  
	m_bAddMode = false;
	m_fHighRot = 0.0f;
	m_fRowRot = 0.0f;
}


//=============================================================================
//�f�X�g���N�^
//=============================================================================
Cbase_Cylinder::~Cbase_Cylinder()
{
}

//=============================================================================
//���������֐�
//=============================================================================
Cbase_Cylinder * Cbase_Cylinder::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col)
{
	// �������̊m��
	Cbase_Cylinder *pbase_Cylinder;
	pbase_Cylinder = new Cbase_Cylinder;
	

	// �����̑��
	pbase_Cylinder->m_pos = D3DXVECTOR3(pos.x,pos.y + size.y,pos.z);
	pbase_Cylinder->m_size = size;
	pbase_Cylinder->m_col = col;
	// ������
	pbase_Cylinder->Init();
	
	return pbase_Cylinder;
}


//=============================================================================
//�����������֐�
//=============================================================================
HRESULT Cbase_Cylinder::Init(void)
{
	VERTEX_3D *pVtx;// ���_���|�C���^

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D)*NUM_CYL_VERTEX * 2, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);

	// �����o�ϐ��̏�����

	m_rot = { 0.0f,0.0f,0.0f };

	//���b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_CYL_VERTEX; nCnt++)
	{	// ���_���W�̐ݒ�
		FLOAT theta = (2 * D3DX_PI * nCnt) / (NUM_CYL_VERTEX - 1);
		
		pVtx[2 * nCnt + 0].pos = D3DXVECTOR3(sinf(theta), -1.0f, cosf(theta));
		pVtx[2 * nCnt + 1].pos = D3DXVECTOR3(sinf(theta),  1.0f, cosf(theta));
		// �e�N�X�`��UV���W�̐ݒ�
		pVtx[2 * nCnt + 0].tex = D3DXVECTOR2(((FLOAT)nCnt) / (NUM_CYL_VERTEX - 1), 0.0f);
		pVtx[2 * nCnt + 1].tex = D3DXVECTOR2(((FLOAT)nCnt) / (NUM_CYL_VERTEX - 1), 1.0f);
	}

	for (int nCnt = 0; nCnt < NUM_CYL_VERTEX * 2; nCnt++)
	{
		// �F�̐ݒ�
		pVtx[nCnt].col = m_col;
		// �@��
		pVtx[nCnt].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	}

	// �A�����b�N
	m_pVtxBuff->Unlock();

	

	return S_OK;
}


//=============================================================================
//�I�������֐�
//=============================================================================
void Cbase_Cylinder::Uninit(void)
{
	// ���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	Release();
}

//=============================================================================
//�X�V�����֐�
//=============================================================================
void Cbase_Cylinder::Update(void)
{
}

//=============================================================================
//�`�揈���֐�
//=============================================================================
void Cbase_Cylinder::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans, mtxScail;//�s��v�Z�p�}�g���N�X
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);// �J�����O

	//�A���t�@�e�X�g��l�̐ݒ�
	pDevice->SetRenderState(D3DRS_ALPHAREF, 20);

	// ���Z���[�h�̎�
	if (m_bAddMode)
	{
		// ���Z����
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	}

	// �}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);
	D3DXMatrixIdentity(&mtxRot);
	D3DXMatrixIdentity(&mtxTrans);
	D3DXMatrixIdentity(&mtxScail);

	////�T�C�Y
	D3DXMatrixScaling(&mtxScail, 1.0f, 1.0f, 1.0f);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScail);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x , m_pos.y , m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���Ƀo�C���h
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	pDevice->SetTexture(0, m_apTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0,  2 * NUM_CYL_VERTEX - 2);
	
	// �e�N�X�`���̏�����
	pDevice->SetTexture(0, 0);

	//�A���t�@�e�X�g��l�̐ݒ�
	pDevice->SetRenderState(D3DRS_ALPHAREF, 1);

	// ���Z���[�h�̎�
	if (m_bAddMode)
	{
		// �ʏ퍇���ɖ߂�
		pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
		pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	}

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);           // �J�����O
  
}

//=============================================================================
// ���W�̃Z�b�g
//=============================================================================
void Cbase_Cylinder::SetPos(const D3DXVECTOR3 pos)
{

	VERTEX_3D *pVtx;// ���_���|�C���^

	//pos�̑��
	m_pos = pos;

	// ���b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_CYL_VERTEX; nCnt++)
	{	// ���_���W�̐ݒ�
		FLOAT theta = (2 * D3DX_PI * nCnt) / (NUM_CYL_VERTEX - 2);

		pVtx[2 * nCnt + 0].pos = D3DXVECTOR3(sinf(theta) * (float)+(m_size.x / 2.0f) * (m_fHighRot + m_fRotAngle), + m_size.y , cosf(theta) * ((float)m_size.z / 2.0f)* (m_fHighRot + m_fRotAngle));
		pVtx[2 * nCnt + 1].pos = D3DXVECTOR3(sinf(theta) * (float)+(m_size.x / 2.0f) *  m_fRowRot, - m_size.y , cosf(theta) * ((float)m_size.z / 2.0f)* m_fRowRot);
    }

	// �A�����b�N
	m_pVtxBuff->Unlock();
}

//=============================================================================
// �T�C�Y�̃Z�b�g
//=============================================================================
void Cbase_Cylinder::SetSize(const D3DXVECTOR3 size)
{
	m_size = size;

	// ���_���W�̍Đݒ�
	SetPos(m_pos);
}
//=============================================================================
// �F�̃Z�b�g
//=============================================================================
void Cbase_Cylinder::SetColor(const D3DXCOLOR col)
{
	VERTEX_3D *pVtx;// ���_���|�C���^

	//�F�̑��
	m_col = col;

	// ���b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_CYL_VERTEX * 2; nCnt++)
	{	// �F�̐ݒ�
		pVtx[nCnt].col = m_col;
	}
	// �A�����b�N
	m_pVtxBuff->Unlock();
}
//=============================================================================
// ���W�̃Z�b�g
//=============================================================================
void Cbase_Cylinder::SetTextureUV(const float pos)
{
	VERTEX_3D *pVtx;// ���_���|�C���^

	// ���b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < NUM_CYL_VERTEX * 2; nCnt++)
	{
		pVtx[2 * nCnt + 0].tex = D3DXVECTOR2(((FLOAT)nCnt) / (NUM_CYL_VERTEX - 1) + pos, 0.0f);
		pVtx[2 * nCnt + 1].tex = D3DXVECTOR2(((FLOAT)nCnt) / (NUM_CYL_VERTEX - 1) + pos, 1.0f);
	}
	// �A�����b�N
	m_pVtxBuff->Unlock();

}











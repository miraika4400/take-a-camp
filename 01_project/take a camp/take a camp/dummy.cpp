//=============================================================================
//
// dummy�N���X�̏���[dummy.cpp]
// Author:�ɓ��@�z��
//
//=============================================================================

//=============================
// �C���N���[�h
//=============================
#include "dummy.h"
#include "manager.h"
#include "collision.h"
#include "light.h"
#include "camera_base.h"
#include "motion.h"
#include "tutorial.h"

//=============================
// �}�N����`
//=============================
#define COLLISION_RADIUS		(18.0f)								 // �����蔻��̑傫��
#define MODEL_COLOR				(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))	 // ���f���J���[
#define MODEL_SIZE				(D3DXVECTOR3(1.4f,1.4f,1.4f))		 // ���f���T�C�Y
#define RESPAWN_MAX_COUNT		(120)								 // ���X�|�[���܂ł̍ő�J�E���g

//=============================
// �R���X�g���N�^
//=============================
CDummy::CDummy() : CModel(OBJTYPE_DUMMY)
{
	m_color = MODEL_COLOR;
	m_nRespawnCount = 0;
	m_pCollision = nullptr;
	m_nColor = 0;
	memset(&m_RespawnPos, 0, sizeof(D3DXVECTOR3));
	m_DummyState = DUMMY_STATE_NORMAL;
}

//=============================
// �f�X�g���N�^
//=============================
CDummy::~CDummy()
{
}

//=============================
// �N���X����
//=============================
CDummy * CDummy::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	// �������̊m��
	CDummy *pDummy;
	pDummy = new CDummy;

	// �I�u�W�F�N�g�^�C�v
	pDummy->SetPriority(OBJTYPE_DUMMY);

	// ������
	pDummy->Init();

	// �e�l�̑���E�Z�b�g
	pDummy->SetPos(pos);
	pDummy->SetRot(rot);
	pDummy->m_RespawnPos = pos;

	return pDummy;
}

//=============================
// ����������
//=============================
HRESULT CDummy::Init(void)
{
	// ���f���̏�����
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// ���f���̊��蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_DUMMY));

	// ���f���̃T�C�Y�̐ݒ�
	//SetSize(MODEL_SIZE);

	// �F�ݒ�
	m_color = MODEL_COLOR;
	return S_OK;
}

//=============================
// �I������
//=============================
void CDummy::Uninit(void)
{
	// �����蔻��̏I������
	if (m_pCollision != NULL)
	{
		m_pCollision->OutList();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}

	// ���f���̏I��
	CModel::Uninit();
}

//=============================
// �X�V����
//=============================
void CDummy::Update(void)
{
	// �X�e�[�g���Ƃ̏���
	switch (m_DummyState)
	{
	case DUMMY_STATE_NORMAL: //�ʏ���
		// �����蔻��̈ʒu
		if (m_pCollision == NULL)
		{
			m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS / 2);
		}
		break;

	case DUMMY_STATE_DEATH: //���S���
		//���X�|�[������
		Respawn();
		break;

	default:
		break;
	}

	// �����蔻��̈ʒu�X�V����
	if (m_pCollision != NULL) m_pCollision->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));

	// ���f���̍X�V
	CModel::Update();
}

//=============================
// �`�揈��
//=============================
void CDummy::Draw(void)
{
	// �F�̐ݒ�
	for (int nCntMat = 0; nCntMat < (int)GetModelData()->nNumMat; nCntMat++)
	{
		D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
		mat[nCntMat].MatD3D.Ambient.a = m_color.a;
		mat[nCntMat].MatD3D.Diffuse.a = m_color.a;
		mat[nCntMat].MatD3D.Specular.a = m_color.a;
		mat[nCntMat].MatD3D.Emissive.a = m_color.a;
	}

	// ���f���̕`��
	CModel::Draw();
}

//=============================
// ���S����
//=============================
void CDummy::Death(void)
{
	// ���S��ԂɈڍs
	SetState(DUMMY_STATE_DEATH);

	// �����蔻�������
	if (m_pCollision != NULL)
	{
		m_pCollision->OutList();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}

	// �����ɂ���
	m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

	// �ʒu�Z�b�g
	SetPos(m_RespawnPos);
}

//=============================
// ���X�|�[������
//=============================
void CDummy::Respawn(void)
{
	// �_�~�[�X�e�[�g�����S��Ԃ̎�
	if (m_DummyState == DUMMY_STATE_DEATH)
	{
		//�J�E���g�A�b�v
		m_nRespawnCount++;

		//�J�E���g�����܂łɒB�����Ƃ�
		if (m_nRespawnCount >= RESPAWN_MAX_COUNT)
		{
			// �X�e�[�g��߂�
			m_DummyState = DUMMY_STATE_NORMAL;

			// �F��߂�
			m_color = MODEL_COLOR;

			// �ʒu�Z�b�g
			SetPos(m_RespawnPos);

			// �J�E���g������
			m_nRespawnCount = 0;
		}
	}
}
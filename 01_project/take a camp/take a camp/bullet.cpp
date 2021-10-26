//=============================================================================
//
// �e�̏��� [Bullet.cpp]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "Bullet.h"
#include "manager.h"
#include "player.h"
#include "collision.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define MODEL_SIZE D3DXVECTOR3(0.5f, 0.5f, 0.5f)	// �T�C�Y
#define BULLET_LIFE		(20)	// �e�̃��C�t
#define COLLISION_SIZE (D3DXVECTOR3(10.0f,10.0f,10.0f))	// �����蔻��̑傫��
#define BULLET_COLOR D3DXCOLOR(0.0f,0.0f,0.0f,0.0f)
#define BULLET_ONE_SIDE 20.0f
#define BULLET_COLLISION_SIZE 10.0f

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBullet::CBullet() :CModel(OBJTYPE_BULLET)
{
	m_move = VEC3_ZERO;		// �ړ���
	m_size = VEC3_ZERO;		// �T�C�Y
	m_nLife = 0;			// ���C�t
	m_fSpeed = 0.0f;		// ����
	m_pCollision = NULL;	// �����蔻��
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBullet::~CBullet()
{

}
//=============================================================================
// ��������
//=============================================================================
CBullet * CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nPlayerNum)
{
	CBullet *pBullet = NULL;

	// �������̊m��
	pBullet = new CBullet;

	// �����������Ăяo��
	pBullet->Init();

	pBullet->SetPos(pos);

	pBullet->m_move = move;

	pBullet->m_nPlayerNum = nPlayerNum;

	// �I�u�W�F�N�g�^�C�v
	pBullet->SetPriority(OBJTYPE_BULLET);

	return pBullet;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CBullet::Init(void)
{
	// ����������
	CModel::Init();

	// �T�C�Y�̐ݒ�
	SetSize(MODEL_SIZE);

	// �J���[�̐ݒ�
	m_color = BULLET_COLOR;

	// ���f�����蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_BULLET01));
	
	// ���C�t
	m_nLife = BULLET_LIFE;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CBullet::Uninit()
{
	if (m_pCollision != NULL)
	{
		m_pCollision->ReConnection();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}
	// �I������
	CModel::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CBullet::Update()
{
	// �ʒu�̎擾
	D3DXVECTOR3 BulletPos = GetPos();

	if (m_pCollision == NULL)
	{
		m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(BulletPos.x, BulletPos.y + BULLET_ONE_SIDE / 2, BulletPos.z), BULLET_COLLISION_SIZE / 2);
	}
	else
	{
		m_pCollision->SetPos(D3DXVECTOR3(BulletPos.x, BulletPos.y + BULLET_ONE_SIDE / 2, BulletPos.z));
	}
	// �v���C���[�Ƃ̓����蔻��
	CollisionPlayer();

	// �ʒu�Ɉړ��ʂ����Z����
	BulletPos += m_move;

	// ���C�t�𖈃t���[�����ƌ��炵�Ă���
	m_nLife--;

	// �ʒu�̐ݒ�
	SetPos(BulletPos);

	// ���C�t���O�ɂȂ�����
	if (m_nLife == 0)
	{
		// �I������
		Uninit();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CBullet::Draw()
{
	// �F�̐ݒ�
	D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
	mat->MatD3D.Ambient = m_color;
	mat->MatD3D.Diffuse = m_color;
	mat->MatD3D.Specular = m_color;
	mat->MatD3D.Emissive = m_color;

	// �`�揈��
	CModel::Draw();
}

//=============================================================================
// �����蔻��̏���
//=============================================================================
void CBullet::CollisionPlayer(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() != m_nPlayerNum)
		{
			if (CCollision::CollisionSphere(m_pCollision, pPlayer->GetCollision()))
			{
				// ���S��Ԃɂ���
				pPlayer->Death();

				return;
			}
		}
			pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}
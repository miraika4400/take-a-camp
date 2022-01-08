////////////////////////////////////////////////////
//
//    particle�N���X�̏���[particle.cpp]
//    Author:�V����s
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "particle.h"
#include "manager.h"
#include "renderer.h"
#include "resource_texture.h"

//*****************************
// �}�N����`
//*****************************

//******************************
// �ÓI�����o�ϐ��錾
//*****************************

//******************************
// �R���X�g���N�^
//******************************
CParticle::CParticle()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	m_nLife = 0;
	m_type = PARTICLE_SQUARE;
	m_bFadeoutFlag = true;
	m_fRotAngle = 0.0f;
	m_fFadeout = 0.0f; 
	

}

//******************************
// �f�X�g���N�^
//******************************
CParticle::~CParticle()
{
}

//******************************
// �N���G�C�g
//******************************
CParticle * CParticle::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const D3DXVECTOR3 size, const int nLife, const D3DXCOLOR col,const float fadeout, const PARTICLE_TYPE type)
{
	// �������̊m��
	CParticle *pParticle;
	pParticle = new CParticle;

	// �^�C�v�̐ݒ�
	pParticle->m_type = type;

	// ������
	pParticle->Init();

	// �e�l�̑���E�Z�b�g
	pParticle->SetPos(pos);                  // ���W
	pParticle->m_move = move;                // �ړ���
	pParticle->m_size = size;				 // �T�C�Y���
	pParticle->SetSize(size);                // �T�C�Y
	pParticle->m_nLife = nLife;				 // ����
	pParticle->m_col = col;					 // ���
	pParticle->m_fFadeout = fadeout;		 // �t�F�[�h�A�E�g
	pParticle->m_fRotAngle = 0.0f;           // ��]�p�x
	pParticle->SetColor(col);                // �J���[�ݒ�
	//pParticle->SetAngle((float)(rand() % 360));       // ��]�p�x�������_��
	pParticle->SetAddMode(false);             // ���Z����
	

	switch (type)
	{
	case PARTICLE_SQUARE:
		pParticle->SetAngle((float)(rand() % 360));       // ��]�p�x�������_��

		break;

	case PARTICLE_TEARS:
		break;

	case PARTICLE_SHOOT:
		break;

	case PARTICLE_METEOR:
		pParticle->SetAddMode(true); 
	
		break;
	case PARTICLE_METEOR_SHADOW:
		pParticle->SetAddMode(false);
		break;

	case PARTICLE_GURUGURU:
		pParticle->SetAngle((float)(rand() % 360));       // ��]�p�x�������_��
		break;

	default:
		break;
	}
	
	return pParticle;
}

//******************************
// ����������
//******************************
HRESULT CParticle::Init(void)
{
	if (FAILED(CBillboard::Init()))
	{
		return E_FAIL;
	}

	m_apTexture[PARTICLE_SQUARE] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SQUARE);
	m_apTexture[PARTICLE_TEARS] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[PARTICLE_SHOOT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SHOOT);
	m_apTexture[PARTICLE_METEOR] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_METEOR);
	m_apTexture[PARTICLE_METEOR_SHADOW] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_METEOR_SHADOW);
	m_apTexture[PARTICLE_GURUGURU] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_GURUGURU);
	// �e�N�X�`�����蓖��
	BindTexture(m_apTexture[m_type]);

	SetPriority(OBJTYPE_PARTICLE);
	return S_OK;
}

//******************************
// �I������
//******************************
void CParticle::Uninit(void)
{
	CBillboard::Uninit();
}

//******************************
// �X�V����
//******************************
void CParticle::Update(void)
{
	// �ړ�
	SetPos(GetPos() + m_move);

	switch (m_type)
	{
	case PARTICLE_SQUARE:
		m_col.a -= m_fFadeout;
		SetColor(m_col);

		break;

	case PARTICLE_TEARS:
		break;

	case PARTICLE_SHOOT:
		break;

	case PARTICLE_METEOR:
		m_col.r += m_fFadeout;
		SetColor(m_col);
		break;

	case PARTICLE_METEOR_SHADOW:
		break;

	case PARTICLE_GURUGURU:
		m_col.a -= m_fFadeout;
		SetColor(m_col);
		break;
	
	default:
		break;
	}

	SetAngle(GetAngle() + m_fRotAngle);

	if (m_col.a <= 0)
	{
		m_bFadeoutFlag = false;
	}

	if (!m_bFadeoutFlag)
	{
		Uninit();
	}

	// ����
	/*m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
	}*/
}

//******************************
// �`�揈��
//******************************
void CParticle::Draw(void)
{
	CBillboard::Draw();
}

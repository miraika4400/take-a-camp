//===================================================
//
// �X�L���Q�[�W�̏���[skill_gauge.cpp]
// Author:�ɓ��z��
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "skill_gauge.h"
#include "manager.h"
#include "billboard.h"
#include "resource_texture.h"
#include "renderer.h"
#include "polygon.h"
#include "keyboard.h"
#include "player.h"

//==================================
// �}�N����`
//==================================

//==================================
// �R���X�g���N�^
//==================================
CSkillgauge::CSkillgauge()
{
	m_SkillGaugeType = SKILLGAUGE_BG;
	memset(&m_pos, 0, sizeof(m_pos));
	memset(&m_size, 0, sizeof(m_size));
	memset(&m_col, 0, sizeof(m_col));
	m_fGauge = 0.0f;
}

//==================================
// �f�X�g���N�^
//==================================
CSkillgauge::~CSkillgauge()
{
}

//==================================
// �N���G�C�g
//==================================
CSkillgauge * CSkillgauge::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType)
{
	// �������̊m��
	CSkillgauge * pSkillgauge = new CSkillgauge;

	pSkillgauge->m_pos = pos;
	pSkillgauge->m_size = size;
	pSkillgauge->m_col = col;
	pSkillgauge->m_SkillGaugeType = SkillGaugeType;
	pSkillgauge->m_nPlayerNum = nPlayerNum;

	// ����������
	pSkillgauge->Init();

	return pSkillgauge;
}

//==================================
// ����������
//==================================
HRESULT CSkillgauge::Init()
{
	// ����������
	CBillboard::Init();

	// ���_���W�̐ݒ�
	D3DXVECTOR3 Pos[NUM_VERTEX];

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));

		SetPos(m_pos);
		SetSize(m_size);
		SetColor(m_col);
		break;

	case SKILLGAUGE_STENCIL:

		//BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));

		SetPos(m_pos);
		SetSize(m_size);
		SetColor(m_col);

		Pos[0] = D3DXVECTOR3(m_pos.x - m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[1] = D3DXVECTOR3(m_pos.x + m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[2] = D3DXVECTOR3(m_pos.x - m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f, 0.0f);
		Pos[3] = D3DXVECTOR3(m_pos.x + m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f, 0.0f);

		SetVertexPos(Pos);
		break;

	default:
		break;
	}

	return S_OK;
}

//==================================
// �I������
//==================================
void CSkillgauge::Uninit(void)
{
	// �I������
	CBillboard::Uninit();
}

//==================================
// �X�V����
//==================================
void CSkillgauge::Update(void)
{
	CInputKeyboard* pInputKeyboard = CManager::GetKeyboard();

	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() == m_nPlayerNum)
		{
			m_pos = pPlayer->GetPos();
		}

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	// ���_���W�̐ݒ�
	D3DXVECTOR3 Pos[NUM_VERTEX];

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		SetPos(m_pos);
		break;

	case SKILLGAUGE_STENCIL:
		if (pInputKeyboard->GetKeyPress(DIK_UP))
		{
			m_fGauge++;
		}
		if (pInputKeyboard->GetKeyPress(DIK_DOWN))
		{
			m_fGauge--;
		}

		if (m_fGauge > m_size.y)
		{
			m_fGauge = m_size.y;
		}

		Pos[0] = D3DXVECTOR3(m_pos.x - m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[1] = D3DXVECTOR3(m_pos.x + m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[2] = D3DXVECTOR3(m_pos.x - m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f, 0.0f);
		Pos[3] = D3DXVECTOR3(m_pos.x + m_size.x / 2.0f, m_pos.y + m_size.y / 2.0f, 0.0f);

		SetVertexPos(Pos);
		break;

	default:
		break;
	}

	// �X�V����
	CBillboard::Update();
}

//==================================
// �`�揈��
//==================================
void CSkillgauge::Draw(void)
{
	// �X�e���V���o�b�t�@���g��
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);

	// �X�e���V���e�X�g��L����
	pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);

		// �X�e���V���e�X�g�Ɣ�r����Q�ƒl�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILREF, 0x01);

		// �X�e���V���e�X�g�̒l�ɑ΂��Ẵ}�X�N�ݒ� 0xff(�S�Đ^)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// �Q�ƒl
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);

		// �X�e���V���e�X�g�̌��ʂɑ΂��Ă̔��f�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);


		break;

	case SKILLGAUGE_STENCIL:
		// �X�e���V���e�X�g�Ɣ�r����Q�ƒl�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILREF, 0x01);

		// �X�e���V���e�X�g�̒l�ɑ΂��Ẵ}�X�N�ݒ� 0xff(�S�Đ^)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// ���̕`��ł̎Q�ƒl == �X�e���V���o�b�t�@�̎Q�ƒl�Ȃ獇�i
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);

		// �X�e���V���e�X�g�̌��ʂɑ΂��Ă̔��f�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);

		break;
	default:
		break;
	}

	// ZBUFFER��r�ݒ�ύX => (�Q�ƒl <= �o�b�t�@�l)(�߂�)
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// �`�揈��
	CBillboard::Draw();

	//// Z�o�b�t�@�ݒ� => �L��
	//pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	//// ZBUFFER��r�ݒ�ύX => (�Q�ƒl <= �o�b�t�@�l)
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// �X�e���V���e�X�g�𖳌���
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);

}
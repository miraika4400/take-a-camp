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
#include "player.h"
#include "color_manager.h"
#include "keyboard.h"
#include "joypad.h"
#include "attack.h"

//==================================
// �}�N����`
//==================================
#define SKILLGAUGE_ADDPOS (D3DXVECTOR3(0.0f, 35.0f, 0.0f)) // �X�L���Q�[�W�̍��W
#define SKILLGAUGE_SIZE (D3DXVECTOR3(20.0f, 20.0f, 0.0f))  // �X�L���Q�[�W�̑傫��
#define DEFAULT_COLOR (D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))  // �F�̏����l
#define SKILLGAUGE_FLAME (60.0f)                           // �t���[����
#define REPAINT_RATE (5.0f)                                // �h�ւ������ۂ̔{��
//#define REPAINT_RATE (0.5f)                              // �h�ւ������ۂ̔{��
#define MINORADJUSSTMENT_POS (D3DXVECTOR3(0.5f,1.0f,0.0f)) // �������p�̍��W
#define DEFAULT_ANGLE (D3DXToRadian(-40.0f))               // �|���S������]������p�x

//==================================
// �R���X�g���N�^
//==================================
CSkillgauge::CSkillgauge()
{
	m_SkillGaugeType = SKILLGAUGE_STENCIL;
	memset(&m_pos, 0, sizeof(m_pos));
	memset(&m_size, 0, sizeof(m_size));
	memset(&m_col, 0, sizeof(m_col));
	m_nPlayerNum = 0;
	m_fGauge = 0.0f;
}

//==================================
// �f�X�g���N�^
//==================================
CSkillgauge::~CSkillgauge()
{
}

//==================================
// �X�L���Q�[�W���ׂẴN���G�C�g
// nPlayerNum�F�v���C���[�̔ԍ�
//==================================
CSkillgauge* CSkillgauge::AllCreate(const int nPlayerNum)
{
	// �A�C�R���ƃX�e���V��
	CSkillgauge::Create(SKILLGAUGE_SIZE, DEFAULT_COLOR, nPlayerNum, CSkillgauge::SKILLGAUGE_ICON);
	CSkillgauge * pSkillgauge = CSkillgauge::Create(SKILLGAUGE_SIZE, GET_COLORMANAGER->GetIconColor(nPlayerNum), nPlayerNum, CSkillgauge::SKILLGAUGE_STENCIL);

	return pSkillgauge;
}

//==================================
// �N���G�C�g
// size�F�X�L���Q�[�W�̑傫��
// col�F�X�L���Q�[�W�̐F
// nPlayerNum�F�v���C���[�̔ԍ�
// SkillGaugeType�F�X�L���Q�[�W�̃^�C�v
//==================================
CSkillgauge * CSkillgauge::Create(const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType)
{
	// �������̊m��
	CSkillgauge * pSkillgauge = new CSkillgauge;

	pSkillgauge->m_size = size;
	pSkillgauge->m_col = col;
	pSkillgauge->m_nPlayerNum = nPlayerNum;
	pSkillgauge->m_SkillGaugeType = SkillGaugeType;
	pSkillgauge->SetPriority(OBJTYPE_UI_2);

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

	// ���W�A�T�C�Y�A�F�̃Z�b�g
	SetPos(m_pos);
	SetSize(m_size);
	SetColor(m_col);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_STENCIL:
		// �X�e���V����\��������W
		SetPolygonPos();
		break;

	case SKILLGAUGE_ICON:
		// �L�����N�^�[�̃^�C�v���ƂɃe�N�X�`����ς���
		switch (GetPlayerinfo(m_nPlayerNum)->GetCharacterType())
		{
		case CResourceCharacter::CHARACTER_TYPE::CHARACTER_KNIGHT:
			BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
			break;
		//case CResourceCharacter::CHARACTER_TYPE::CHARACTER_LANCER:
		//	BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
		//	break;
		//case CResourceCharacter::CHARACTER_TYPE::CHARACTER_WIZARD:
		//	BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
			break;
		default:
			break;
		}

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
	// �X�V����
	CBillboard::Update();

	// �v���C���[�̍��W���擾
	CPlayer * pPlayer = GetPlayerinfo(m_nPlayerNum);
	m_pos = pPlayer->GetPos();

	// ���W�̃Z�b�g
	SetPos(m_pos + SKILLGAUGE_ADDPOS);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_STENCIL:
		// �X�e���V���̍X�V
		UpdateStencil();
		break;

	default:
		break;
	}
}

//==================================
// �`�揈��
//==================================
void CSkillgauge::Draw(void)
{
	// �X�e���V���o�b�t�@���g��
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// �X�e���V���e�X�g��L����
	pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_ICON:
		// �X�e���V���e�X�g�Ɣ�r����Q�ƒl�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILREF, m_nPlayerNum + 0x01);

		// �X�e���V���e�X�g�̒l�ɑ΂��Ẵ}�X�N�ݒ� 0xff(�S�Đ^)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// ���̕`��ł̎Q�ƒl == �X�e���V���o�b�t�@�̎Q�ƒl�Ȃ獇�i
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_GREATEREQUAL);

		// �X�e���V���e�X�g�̌��ʂɑ΂��Ă̔��f�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
		break;

	case SKILLGAUGE_STENCIL:
		// �X�e���V���e�X�g�Ɣ�r����Q�ƒl�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILREF, m_nPlayerNum + 0x01);

		// �X�e���V���e�X�g�̒l�ɑ΂��Ẵ}�X�N�ݒ� 0xff(�S�Đ^)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// ���̕`��ł̎Q�ƒl == �X�e���V���o�b�t�@�̎Q�ƒl�Ȃ獇�i
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);

		// �X�e���V���e�X�g�̌��ʂɑ΂��Ă̔��f�ݒ�
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
		break;

	default:
		break;
	}

	// �`�揈��
	CBillboard::Draw();

	// �X�e���V���e�X�g�𖳌���
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
}

//==================================
// �v���C���[�̏��擾����
//==================================
CPlayer * CSkillgauge::GetPlayerinfo(int nPlayerNum)
{
	// �v���C���[�̃|�C���^���擾
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() == m_nPlayerNum)
		{
			break;
		}

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	return pPlayer;
}

//==================================
// �X�e���V���̍X�V����
//==================================
void CSkillgauge::UpdateStencil(void)
{
	// �L�����f�[�^�̎擾
	CResourceCharacter::CharacterData charaData =
		CResourceCharacter::GetResourceCharacter()->GetCharacterData(GetPlayerinfo(m_nPlayerNum)->GetCharacterType());

	// �L�����N�^�[���Ƃ̕K�E�Z�b��*1�b�Ԃ̃t���[����
	m_fGauge += m_size.y / ((float)charaData.nFinalAttackTime * SKILLGAUGE_FLAME);

	// �T�C�Y���𒴂��Ȃ��悤��
	if (m_fGauge > m_size.y)
	{
		m_fGauge = m_size.y;
	}
	
#ifdef _DEBUG
	// �Q�[�W���^���R�}���h
	// �L�[�{�[�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();
	if (pKey->GetKeyTrigger(DIK_F4))
	{
		m_fGauge = m_size.y;
	}
#endif // _DEBUG

	// �Q�[�W�����܂�����
	if(m_fGauge == m_size.y)
	{
		// �K�E�Z�̃t���O����
		GetPlayerinfo(m_nPlayerNum)->SetFinalAttack(true);

		// �K�E�Z��ł�����
		if (GetPlayerinfo(m_nPlayerNum)->GetAttack()->GetState() == CAttackBased:: ATTACK_STATE_FINALATTACK)
		{
			GetPlayerinfo(m_nPlayerNum)->SetFinalAttack(false);
			m_fGauge = 0.0f;
		}
	}

	// �X�e���V����\��������W
	SetPolygonPos();
}

//==================================
// �X�e���V����\��������W
//==================================
void CSkillgauge::SetPolygonPos(void)
{
	// ���_���W�̐ݒ�
	D3DXVECTOR3 Pos[NUM_VERTEX];
	ZeroMemory(&Pos, sizeof(Pos));

	// ���S����̊Ԋu
	float fDistance = sqrtf(powf(m_size.x / sqrtf(2.0f), 2) + powf(m_size.y / sqrtf(2.0f), 2));
	// �E��ƍ���̒��_
	float fAngle = atan2f(m_size.y / 2.0f, m_size.x / 2.0f);
	float fAngle2 = atan2f(m_size.y / 2.0f, -m_size.x / 2.0f);

	// �e���_�̍��W
	Pos[0] = D3DXVECTOR3(cosf(-fAngle2 + DEFAULT_ANGLE) * fDistance + m_fGauge - MINORADJUSSTMENT_POS.x,
		sinf(-fAngle2 + DEFAULT_ANGLE) * fDistance + m_fGauge + MINORADJUSSTMENT_POS.y, 0.0f);
	Pos[1] = D3DXVECTOR3(cosf(-fAngle + DEFAULT_ANGLE) * fDistance + m_fGauge - MINORADJUSSTMENT_POS.x,
		sinf(-fAngle + DEFAULT_ANGLE) * fDistance + m_fGauge + MINORADJUSSTMENT_POS.y, 0.0f);
	Pos[2] = D3DXVECTOR3(cosf(-fAngle2 + DEFAULT_ANGLE) * fDistance - MINORADJUSSTMENT_POS.x,
		sinf(-fAngle2 + DEFAULT_ANGLE) * fDistance + MINORADJUSSTMENT_POS.y, 0.0f);
	Pos[3] = D3DXVECTOR3(cosf(-fAngle + DEFAULT_ANGLE) * fDistance - MINORADJUSSTMENT_POS.x,
		sinf(-fAngle + DEFAULT_ANGLE) * fDistance + MINORADJUSSTMENT_POS.y, 0.0f);

	// ���_���Ƃ̍��W�ݒ�
	SetVertexPos(Pos);
}

//==================================
// �h�ւ������Ƃ��Q�[�W�����Z���鏈��
//==================================
void CSkillgauge::Repaint_AddSkillGauge(void)
{
	// �{���ɂ���ĉ��Z�l��ς���
	m_fGauge += REPAINT_RATE * (m_size.y / SKILLGAUGE_FLAME);
}
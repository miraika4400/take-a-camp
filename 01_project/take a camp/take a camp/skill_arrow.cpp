//=============================================================================
//
// �X�L���A���[�G�t�F�N�g ���� [skill_arrow.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "resource_texture.h"
#include "skill_arrow.h"
#include "skill_aroow_line.h"
#include "tile.h"
//******************************
// �}�N����`
//******************************
#define ARROW_SIZE	(D3DXVECTOR3(3.0f,4.0f,0.0f))	// �G�t�F�N�g�̃T�C�Y
#define ARROW_SPPED (10.0f)							// �G�t�F�N�g�X�s�[�h

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CSkillArrow::CSkillArrow(int nPliority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_bDeath = false;
	m_nTile = 0;
}

//===================================
// �f�X�g���N�^
//===================================
CSkillArrow::~CSkillArrow()
{
}

//===================================
// ���������֐�
//===================================
CSkillArrow * CSkillArrow::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const float fAngle, int nTile, const D3DXCOLOR col )
{
	CSkillArrow* pSkillArrow = nullptr;
	pSkillArrow = new CSkillArrow;
	
	//NULL�`�F�b�N
	if (pSkillArrow != nullptr)
	{
		//����������
		pSkillArrow->Init();
		//�ʒu�ݒ�
		pSkillArrow->SetPos(pos);
		pSkillArrow->m_StartPos = pos;
		//�����ݒ�
		pSkillArrow->SetAngle(fAngle);
		//�J���[�ݒ�
		pSkillArrow->SetColor(col);
		//���C�t�ݒ�
		pSkillArrow->m_nTile = nTile;
		//�ړ��ʐݒ�
		pSkillArrow->m_move = move;
	}

	return pSkillArrow;
}

//===================================
// ����������
//===================================
HRESULT CSkillArrow::Init(void)
{
	//�r���{�[�h�̏���������
	CBillboard::Init();
	//�T�C�Y�ݒ�
	SetSize(ARROW_SIZE);
	return S_OK;
}

//===================================
// �X�V����
//===================================
void CSkillArrow::Update(void)
{
	CSkillArrowLine::Create(GetPos(), GetAngle(),GetColor());

	PosChange();
	//�ړ��������������߂�
	D3DXVECTOR3 move = GetPos() - m_StartPos;
	//�x�N�g���̑傫���̎擾
	float fdistance = hypotf(move.x, move.z);

	//�ǂꂾ���ړ�������
	if ((int)fdistance>m_nTile * TILE_ONE_SIDE)
	{
		//���C�t�̏�����
		m_nTile = 0;
		//�I������
		Uninit();
	}

	//���S�t���O�������Ă��邩
	if (m_bDeath)
	{
		//�I������
		Uninit();
	}

}

//===================================
// �ʒu�̕ω�����
//===================================
void CSkillArrow::PosChange(void)
{
	D3DXVECTOR3 pos = GetPos();
	//�ʒu�ύX
	SetPos(pos + m_move);
}

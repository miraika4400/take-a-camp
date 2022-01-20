//=============================================================================
//
// �X�L���A���[���C���G�t�F�N�g ���� [skill_arrow_line.cpp]
// Author : �g�c�I�l
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "skill_aroow_line.h"
//*****************************
//�}�N����`
//*****************************
#define ARROW_LINE_SIZE (D3DXVECTOR3(3.0f,3.0f,0.0f))
#define ARROW_LINE_LIFE (30)

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CSkillArrowLine::CSkillArrowLine(int nPliority)
{
	m_nTile = 0;
	m_bDeath = false;
}

//===================================
// �f�X�g���N�^
//===================================
CSkillArrowLine::~CSkillArrowLine()
{
}

//===================================
// ���������֐�
//===================================
CSkillArrowLine * CSkillArrowLine::Create(const D3DXVECTOR3 pos, const float fAngle,const D3DXCOLOR col)
{
	//�������m��
	CSkillArrowLine* pSkillArrowLine = nullptr;
	pSkillArrowLine = new CSkillArrowLine;

	//NULL�`�F�b�N
	if (pSkillArrowLine != nullptr)
	{
		//����������
		pSkillArrowLine->Init();
		//�ʒu�ݒ�
		pSkillArrowLine->SetPos(pos);
		//�����ݒ�
		pSkillArrowLine->SetAngle(fAngle);
		//�F�ݒ�
		pSkillArrowLine->SetColor(col);
	}

	return pSkillArrowLine;
}

//===================================
// ����������
//===================================
HRESULT CSkillArrowLine::Init(void)
{
	//�r���{�[�h�̏���������
	CBillboard::Init();
	//�T�C�Y�ݒ�
	SetSize(ARROW_LINE_SIZE);
	//���C�t�ݒ�
	m_nTile = ARROW_LINE_LIFE;
	return S_OK;
}


//===================================
// �X�V����
//===================================
void CSkillArrowLine::Update(void)
{
	D3DXVECTOR3 size = GetSize();
	D3DXCOLOR col = GetColor();
	col.a -= 0.02f;	
	size.x -= 0.01f;
	SetColor(col);
	SetSize(size);

	m_nTile--;

	//0���Ⴍ�Ȃ�����
	if (m_nTile <= 0)
	{
		Uninit();
	}

}

//===================================
// �`�揈��
//===================================
void CSkillArrowLine::Draw(void)
{
	//�r���{�[�h�̕`�揈��
	CBillboard::Draw();;
}


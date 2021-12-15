//===================================================
//
// �h��������UI�̏���[paintnum.cpp]
// Author:�ɓ��z��
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "paintnum.h"
#include "manager.h"
#include "renderer.h"
#include "player.h"
#include "color_manager.h"
#include "polygon.h"
#include "color_tile.h"
#include "chara_select.h"

//==================================
// �}�N����`
//==================================
#define SIZE_CHANGE_RATE (0.05f)

//==================================
// �R���X�g���N�^
//==================================
CPaintnum::CPaintnum()
{
	m_pVtxBuff = nullptr;
	ZeroMemory(&m_pPolygon, sizeof(m_pPolygon));
	ZeroMemory(&m_pos, sizeof(m_pos));
	ZeroMemory(&m_size, sizeof(m_size));
	ZeroMemory(&m_PaintInfo, sizeof(m_nRank));
	ZeroMemory(&m_nRank, sizeof(m_fChangeSize));
	ZeroMemory(&m_fChangeSize, sizeof(m_fChangeSize));
}

//==================================
// �f�X�g���N�^
//==================================
CPaintnum::~CPaintnum()
{
}

//==================================
// �N���G�C�g
// pos�F���W
// size�F�傫��
//==================================
CPaintnum * CPaintnum::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size)
{
	// �������̊m��
	CPaintnum * pPaintnum = new CPaintnum;

	pPaintnum->m_pos = pos;
	pPaintnum->m_size = size;
	pPaintnum->SetPriority(OBJTYPE_UI_2);

	// ����������
	pPaintnum->Init();

	return pPaintnum;
}

//==================================
// ����������
//==================================
HRESULT CPaintnum::Init()
{
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		if (CCharaSelect::GetEntryData(nCount).bEntry)
		{
			// �|���S���̊e���̐ݒ�
			m_PaintInfo[nCount].size = D3DXVECTOR3(m_size.x / (float)CCharaSelect::GetEntryPlayerNum(), m_size.y / 2.0f, m_size.z);
			m_PaintInfo[nCount].pos = D3DXVECTOR3(m_PaintInfo[nCount].size.x + ShiftSize(nCount), m_pos.y, 0.0f);
			m_PaintInfo[nCount].col = GET_COLORMANAGER->GetIconColor(nCount);

			if (!m_pPolygon[nCount])
			{
				// �|���S���̐���
				m_pPolygon[nCount] = CPolygon::Create(
					m_PaintInfo[nCount].pos,
					m_PaintInfo[nCount].size,
					m_PaintInfo[nCount].col);
			}

			// ���X�ɕς�����������
			m_fChangeSize[nCount] = m_PaintInfo[nCount].size.x;

			// �|���S���̍��W���Z�b�g
			SetPolygonPos(nCount);
		}
	}
	return S_OK;
}

//==================================
// �I������
//==================================
void CPaintnum::Uninit()
{
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		if (m_pPolygon[nCount])
		{
			// �I������
			m_pPolygon[nCount]->Uninit();

			// �������̉��
			delete m_pPolygon[nCount];
			m_pPolygon[nCount] = nullptr;
		}
	}

	// �I�u�W�F�N�g�̔j��
	Release();
}

//==================================
// �X�V����
//==================================
void CPaintnum::Update()
{
	// �^�C���̑���
	int nAllTileNum = 0;

	// �^�C���̑������o��
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		nAllTileNum += CColorTile::GetTileNum(nCount);
	}

	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		// �L�����N�^�[�������ƃG���g���[���Ă��邩
		if (CCharaSelect::GetEntryData(nCount).bEntry)
		{
			// �v���C���[���Ƃ̃^�C���̐��̊���
			if (nAllTileNum > 0)
			{
				float fRatio = (float)CColorTile::GetTileNum(nCount) / (float)nAllTileNum;
				m_PaintInfo[nCount].size = D3DXVECTOR3(m_size.x * fRatio, m_size.y / 2.0f, m_size.z);
			}

			// �{���̑傫���Ə��X�ɕς��Ă����傫���̍�
			float fDist = m_PaintInfo[nCount].size.x - m_fChangeSize[nCount];
			// �{�����|���ĉ��Z����
			m_fChangeSize[nCount] += fDist * SIZE_CHANGE_RATE;

			// ���W�����炷����
			m_PaintInfo[nCount].pos = D3DXVECTOR3(m_fChangeSize[nCount] + ShiftSize(nCount), m_pos.y, 0.0f);

			// �|���S���̍��W���Z�b�g
			SetPolygonPos(nCount);
		}
	}

	// �v���C���[���Ƃ̏���
	PlayerRank();
}

//==================================
// �`�揈��
//==================================
void CPaintnum::Draw()
{
	// �`��
	for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		if (m_pPolygon[nCount])
		{
			m_pPolygon[nCount]->Draw();
		}
	}
}

//==================================
// ���炷�傫���̌v�Z
//==================================
float CPaintnum::ShiftSize(int nCount)
{
	float fSize = 0.0f;

	// �傫���̉��Z
	for (int nPlayerCount = 0; nPlayerCount < nCount; nPlayerCount++)
	{
		fSize += m_fChangeSize[nPlayerCount];
	}

	// �傫���̔�����������������
	fSize -= m_fChangeSize[nCount] / 2.0f;

	return fSize;
}

//==================================
// �v���C���[���Ƃ̏���
//==================================
void CPaintnum::PlayerRank(void)
{
	for (int nCompare = 0; nCompare < MAX_PLAYER; nCompare++)
	{
		int nRank = 0;
		for (int nCount = 0; nCount < MAX_PLAYER; nCount++)
		{
			// ��ׂ�����������Ȃ���Z
			if (CColorTile::GetTileNum(nCompare) < CColorTile::GetTileNum(nCount)
				&& nCompare != nCount)
			{
				nRank++;
			}
		}

		// ���ʂ�����
		m_nRank[nCompare] = nRank + 1;
	}
}

//==================================
// �|���S���̍��W
//==================================
void CPaintnum::SetPolygonPos(int nCount)
{
	// ���_���W�̐ݒ�
	D3DXVECTOR3 Pos[NUM_VERTEX];

	// ���_���W�̐ݒ�
	Pos[0] = D3DXVECTOR3(m_PaintInfo[nCount].pos.x - m_fChangeSize[nCount] / 2.0f, m_PaintInfo[nCount].pos.y - m_PaintInfo[nCount].size.y, 0.0f);
	Pos[1] = D3DXVECTOR3(m_PaintInfo[nCount].pos.x + m_fChangeSize[nCount] / 2.0f, m_PaintInfo[nCount].pos.y - m_PaintInfo[nCount].size.y, 0.0f);
	Pos[2] = D3DXVECTOR3(m_PaintInfo[nCount].pos.x - m_fChangeSize[nCount] / 2.0f, m_PaintInfo[nCount].pos.y + m_PaintInfo[nCount].size.y, 0.0f);
	Pos[3] = D3DXVECTOR3(m_PaintInfo[nCount].pos.x + m_fChangeSize[nCount] / 2.0f, m_PaintInfo[nCount].pos.y + m_PaintInfo[nCount].size.y, 0.0f);

	if (m_pPolygon[nCount])
	{
		// ���_���Ƃ̏����Z�b�g
		m_pPolygon[nCount]->SetVertexPos(Pos);
	}
}

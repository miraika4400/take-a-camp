//===================================================
//
// �i���o�[�N���X�̏���[number_array.cpp]
// Author:�ɓ��z��
//
//====================================================

//**********************************
// �C���N���[�h
//**********************************
#include "number_array.h"
#include "manager.h"
#include "number.h"
#include "billboard.h"
#include "keyboard.h"
#include "resource_texture.h"
#include "renderer.h"
#include "player.h" 
#include "tile.h"

//==================================
// �}�N����`
//==================================
#define MAX_TEXTURE_PATTARN (10)
#define KERNING_DIVISION (3.6f)								// �Ԋu�����鐔(�Ԋu��������Ƃ��͌X�̐��l��ς���)
#define ODD_NUMBER_DIVISION (2.0f * KERNING_DIVISION)		// ������鐔
#define EVEN_NUMBER_DIVISION (20.0f * KERNING_DIVISION)	// ���������鐔

//==================================
// �R���X�g���N�^
//==================================
CNumberArray::CNumberArray():CScene(OBJTYPE_UI)
{
	memset(&m_apNumber, NULL, sizeof(m_apNumber));
	m_nNumber = 0;
	memset(&m_pos, 0, sizeof(m_pos));
	memset(&m_size, 0, sizeof(m_size));
	memset(&m_col, 0, sizeof(m_col));
	m_bZeroCheck = false;
}

//==================================
// �f�X�g���N�^
//==================================
CNumberArray::~CNumberArray()
{
}

//==================================
// �N���G�C�g
//==================================
CNumberArray * CNumberArray::Create(const int nNum, const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col, const int nColorNum)
{
	// �������̊m��
	CNumberArray * pNumberArray = new CNumberArray;

	pNumberArray->m_nNumber = nNum;
	pNumberArray->m_pos = pos;
	pNumberArray->m_size = size;
	pNumberArray->m_col = col;
	pNumberArray->m_nPlayerNum = nColorNum;

	// ����������
	pNumberArray->Init();

	return pNumberArray;
}

//==================================
// ����������
//==================================
HRESULT CNumberArray::Init()
{
	// �\�����鐔���̐ݒ�
	SetNumber();

	return S_OK;
}

//==================================
// �I������
//==================================
void CNumberArray::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_ARRAY_NUM; nCount++)
	{
		// ���g�������Ă������
		if (m_apNumber[nCount] != NULL)
		{
			m_apNumber[nCount]->Uninit();

			delete m_apNumber[nCount];
			m_apNumber[nCount] = NULL;
		}
	}
}

//==================================
// �X�V����
//==================================
void CNumberArray::Update(void)
{
	// �L�[�{�[�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();

	/*if (pKey->GetKeyPress(DIK_UP))
	{
		m_nNumber += 1;
	}
	if (pKey->GetKeyPress(DIK_DOWN))
	{
		m_nNumber -= 1;
	}

	if (m_nNumber < 0)
	{
		m_nNumber = 0;
	}
	if (m_nNumber > 99999)
	{
		m_nNumber = 99999;
	}*/

	m_nNumber = CTile::GetTileNum(m_nPlayerNum);

	for (int nCount = 0; nCount < MAX_ARRAY_NUM; nCount++)
	{
		// ���g�������Ă���X�V
		if (m_apNumber[nCount] != NULL)
		{
			m_apNumber[nCount]->Update();
		}
	}

	// �\�����鐔���̐ݒ�
	SetNumber();
}

//==================================
// �`�揈��
//==================================
void CNumberArray::Draw(void)
{
	for (int nCount = 0; nCount < MAX_ARRAY_NUM; nCount++)
	{
		// ���g�������Ă���`��
		if (m_apNumber[nCount] != NULL)
		{
			m_apNumber[nCount]->Draw();
		}
	}
}

//==================================
// �����̊Ԋu�̐ݒ�
//==================================
float CNumberArray::Kerning(void)
{
	int nDigitNum = 0;		// ����
	float fKerning = 0.0f;	// �Ԋu

	// �����𐔂���
	nDigitNum = std::to_string(m_nNumber).length() - 1;
	
	// ��Ƌ����Œl��ς���
	if (nDigitNum % 2 == 0)
	{
		fKerning = -((((float)nDigitNum) * m_size.x / EVEN_NUMBER_DIVISION) * m_size.x);
	}
	else
	{
		fKerning = -(((float)nDigitNum) * m_size.x / ODD_NUMBER_DIVISION);
	}

	return fKerning;
}

//==================================
// �\�����鐔���̐ݒ�
//==================================
void CNumberArray::SetNumber(void)
{
	int nIndex = 0;				// �w���@(�X�R�A�\���p)
	const float fRadix = 10.0f;		// ��@(�X�R�A�\���p)
	float fKerning = Kerning();	// �����̊Ԋu

	m_bZeroCheck = false; // �t���O�̏�����

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();	// �f�o�C�X�̎擾
	D3DXMATRIX mtxRot;													// �s��v�Z�p�}�g���N�X

	D3DXVECTOR3 Getpos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() == m_nPlayerNum)
		{
			Getpos = pPlayer->GetPos();
		}

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}



	// �����̐ݒ�
	for (nIndex = 0; nIndex < MAX_ARRAY_NUM; nIndex++)
	{
		// 1�����Ƃɐ������o��
		int nScore = (int)powf(fRadix, MAX_ARRAY_NUM - (float)nIndex - 1);
		int nScore2 = (int)powf(fRadix, MAX_ARRAY_NUM - (float)nIndex);
		int nAnswer = (m_nNumber % nScore2) / nScore;

		// �l�������ĂȂ��Ȃ琶�����ăe�N�X�`���̃o�C���h
		if (m_apNumber[nIndex] == NULL)
		{
			m_apNumber[nIndex] = CBillboard::Create(D3DXVECTOR3(m_pos.x + fKerning, m_pos.y, m_pos.z), m_size);
			m_apNumber[nIndex]->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NUMBER));
		}

		// �l�������Ă���
		if (m_apNumber[nIndex] != NULL)
		{
			// �e�i���o�[�̃Z�b�g
			m_apNumber[nIndex]->SetTextureManualUV(MAX_TEXTURE_PATTARN, nAnswer);

			// �J�����̌������擾
			pDevice->GetTransform(D3DTS_VIEW, &mtxRot);

			// �s�񂩂�p�x���擾
			const float fAngle = atan2f(mtxRot._31, mtxRot._33);
			const float fAngle2 = atan2f(mtxRot._11, mtxRot._13);

			//// ���W�̐ݒ�
			//m_apNumber[nIndex]->SetPos(D3DXVECTOR3(/*cosf(fAngle) * */(m_pos.x + fKerning), m_pos.y, /*sinf(fAngle) * */(m_pos.z + fKerning)));

			// ���W�̐ݒ�
			m_apNumber[nIndex]->SetPos(Getpos +
			D3DXVECTOR3(cosf(fAngle) * (fKerning) + sinf(fAngle2) * (fKerning),
				25.0f,
				-cosf(fAngle2) * (fKerning) + sinf(fAngle) * (fKerning)));
		}

		// 1���ڈȊO��0�Ń`�F�b�N�������ĂȂ������瓧���ɁA�ق��͊Ԋu�����炵�ĐF�t��
		if (nAnswer == 0 && m_bZeroCheck == false && nIndex != MAX_ARRAY_NUM - 1)
		{
			m_apNumber[nIndex]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		}
		else
		{
			// �F�Â��ƊԊu�̌v�Z
			m_apNumber[nIndex]->SetColor(m_col);
			fKerning += m_size.x / KERNING_DIVISION;

			// ���̕��̌���0�������Ȃ��悤�Ƀt���O����
			m_bZeroCheck = true;
		}
	}
}
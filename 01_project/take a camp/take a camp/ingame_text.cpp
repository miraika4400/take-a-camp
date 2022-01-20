//=============================================================================
//
// �C���Q�[���̃e�L�X�g���� [ingame_text.cpp]
// Author : �����D�I
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "ingame_text.h"
#include "manager.h"
#include "polygon.h"
#include "resource_texture.h"
#include "number.h"
#include "sound.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define REMAINING_TEXT_SIZE D3DXVECTOR3(460.0f,120.0f,0.0f)	// �T�C�Y
#define REMAINING_TIME (60)		// �\���^�C��
#define NUMBER_SIZE (D3DXVECTOR3(60, 60, 0))				// ���l�T�C�Y
#define TEXT_MOVE_BASIC (D3DXVECTOR3(20.0f, 0.0f, 0.0f))	// ��{�ړ���
#define TEXT_MOVE_SLOW	(D3DXVECTOR3(3.0f, 0.0f, 0.0f))		// �x���Ƃ��̈ړ���
#define SLOW_POS		(740)								// �x��������ꏊ
#define SPEED_POS		(640)								// ����������ꏊ

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CInGameText::CInGameText() :CScene2d(OBJTYPE_UI_2)
{
	memset(&m_apNumber,0,sizeof(m_apNumber));
	m_pos = VEC3_ZERO;							// �ʒu���
	m_size = VEC3_ZERO;							// �T�C�Y
	m_move = VEC3_ZERO;
	m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	// �F���
	m_nCount = 0;								// �J�E���^�[
	m_nTime = REMAINING_TIME;	// �c�莞��
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CInGameText::~CInGameText()
{

}

//=============================================================================
// ��������
//=============================================================================
CInGameText * CInGameText::Create(D3DXVECTOR3 pos)
{
	CInGameText *pInGameText = NULL;

	// �������̊m��
	pInGameText = new CInGameText; 
	
	// NULL�`�F�b�N
	if (pInGameText != NULL)
	{
		// �����������Ăяo��
		pInGameText->Init();
		// �ʒu�ݒ�
		pInGameText->SetPos(pos);
		// �e�N�X�`���̐ݒ�
		pInGameText->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SECONDS));
		// �I�u�W�F�N�g�^�C�v
		pInGameText->SetPriority(OBJTYPE_UI_2);
	}

	return pInGameText;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CInGameText::Init(void)
{
	// ����������
	CScene2d::Init();

	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// �F�ݒ�
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// �T�C�Y�ݒ�
	SetSize(REMAINING_TEXT_SIZE);

	// �ړ���
	m_move = TEXT_MOVE_BASIC;

	// SE�Đ�
	pSound->Play(CSound::LABEL_SE_LIMIT);

	// ���ݗ����Ă�BGM�̒�~
	pSound->Stop(CSound::LABEL_BGM_GAME);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CInGameText::Uninit(void)
{
	// �I������
	CScene2d::Uninit();
	
	// ������
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// NULL�`�F�b�N
		if (m_apNumber[nCntDigit] != NULL)
		{
			// �I������
			m_apNumber[nCntDigit]->Uninit();
			delete m_apNumber[nCntDigit];
			m_apNumber[nCntDigit] = NULL;
		}
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CInGameText::Update(void)
{
	// �X�V����
	CScene2d::Update();
	// �T�E���h���̎擾
	CSound *pSound = CManager::GetSound();

	// �ʒu���̎擾
	D3DXVECTOR3 TextPos = GetPos();

	// BGM�Đ�
	pSound->Play(CSound::LABEL_BGM_GAME_LIMIT);

	// ������
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		//null�`�F�b�N
		if (m_apNumber[nCntDigit] == nullptr)
		{
			// �i���o�[��������
			m_apNumber[nCntDigit] = CNumber::Create(0,
				D3DXVECTOR3((float)(GetPos().x + nCntDigit * NUMBER_SIZE.x), GetPos().y, 0.0f),
				NUMBER_SIZE,
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			// �i���o�[�̔z�u
			m_apNumber[nCntDigit]->SetNumber((int)((m_nTime % (int)(powf(10.0f, (float)(MAX_DIGIT - nCntDigit)))) / (float)(powf((float)10, (float)(MAX_DIGIT - nCntDigit - 1)))));
		}

	}


	// �ʒu���Ɉړ��ʂ����Z����
	TextPos.x -= m_move.x;

	// ���l�ɒB����ƌ���������
	if (TextPos.x <= SLOW_POS&& TextPos.x > SPEED_POS)
	{
		m_move.x = TEXT_MOVE_SLOW.x;
	}

	// ���l�ɒB����Ɖ���������
	if (TextPos.x <= SPEED_POS&&TextPos.x > 0.0f)
	{
		m_move.x = TEXT_MOVE_BASIC.x;
	}

	// �J�E���g����萔�ɂȂ�����
	if (TextPos.x <= -REMAINING_TEXT_SIZE.x / 2)
	{
		// �I������
		Uninit();
		return;
	}

	// �ʒu���ݒ�
	SetPos(TextPos);


	// �񐔕���
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		// �X�V����
		m_apNumber[nCntDigit]->Update();

		// �ʒu�̐ݒ�
		m_apNumber[nCntDigit]->SetPos(D3DXVECTOR3((float)( GetPos().x+ nCntDigit * 75), GetPos().y, 0.0f));
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CInGameText::Draw(void)
{
	// �`�揈��
	CScene2d::Draw();

	// �񐔕���
	for (int nCntDigit = 0; nCntDigit < MAX_DIGIT; nCntDigit++)
	{
		//NULL�`�F�b�N
		if (m_apNumber[nCntDigit] != nullptr)
		{
			// �`�揈��
			m_apNumber[nCntDigit]->Draw();
	
		}
	}
}
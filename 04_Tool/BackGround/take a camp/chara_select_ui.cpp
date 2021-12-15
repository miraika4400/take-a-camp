////////////////////////////////////////////////////
//
//    �L�����I��UI�N���X�̏���[chara_select_ui.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//=============================
// �C���N���[�h
//=============================
#include "chara_select_ui.h"
#include "chara_select.h"
#include "scene2d.h"
#include "resource_texture.h"
#include "color_manager.h"

//=============================
// �}�N����`
//=============================
#define BACK_SIZE D3DXVECTOR3(320.0f,720.0f,0.0f)            // �{�[�h�T�C�Y
#define CONTOROll_ICON_SIZE D3DXVECTOR3(180.0f,180.0f,0.0f)  // �R���g���[���[�A�C�R���̃T�C�Y
#define PLAYERNUMBER_SIZE D3DXVECTOR3(240.0f,60.0f,0.0f)     // �v���C���[�ԍ��̃T�C�Y
#define PLAYERNUMBER_TEX_ANIM_MAX_X 1                        // ���ʃe�N�X�`��������*��
#define PLAYERNUMBER_TEX_ANIM_MAX_Y 4                        // ���ʃe�N�X�`��������*�c
#define ANIMATION_INTERVAL 15                                // �A�j���[�V�����ڍs�t���[����
#define UI_SPACE 320.0f                                      // UI�Ԃ̍��E�̃X�y�[�X
#define BACK_DEFAULT_COLOR D3DXCOLOR(0.7f,0.7f,0.7f,1.0f)    // �f�t�H���g�̃J���[
#define ICON_COLOR_ON      D3DXCOLOR(1.0f,1.0f,1.0f,0.7f)    // �A�C�R���̃J���[
#define ICON_COLOR_OFF     D3DXCOLOR(1.0f,1.0f,1.0f,0.0f)    // �A�C�R���̃J���[
#define PLAYER_NUMBER_POS_Y 60.0f

//=============================
// �ÓI�����o�ϐ��錾
//=============================

//=============================
// �R���X�g���N�^
//=============================
CCharaSelectUi::CCharaSelectUi()
{
	// �ϐ��̃N���A
	ZeroMemory(&m_aPolygon, sizeof(m_aPolygon));
	m_nCntAnim = 0;       // �A�j���[�V�����J�E���g
	m_nAnimY = 0;         // �A�j���[�V����Y��
}

//=============================
// �f�X�g���N�^
//=============================
CCharaSelectUi::~CCharaSelectUi()
{
}

//=============================
// �N���G�C�g
//=============================
CCharaSelectUi * CCharaSelectUi::Create(void)
{
	// �������̊m��
	CCharaSelectUi *pUi= new CCharaSelectUi;
	// ������
	pUi->Init();

	return pUi;
}

//=============================
// ����������
//=============================
HRESULT CCharaSelectUi::Init(void)
{
	D3DXVECTOR3 boardPos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	boardPos.x = boardPos.x - (UI_SPACE*(MAX_PLAYER - 1)) / 2;

	D3DXVECTOR2 uv[NUM_VERTEX];
	float fu = 1.0f / PLAYERNUMBER_TEX_ANIM_MAX_X;
	float fv = 1.0f / PLAYERNUMBER_TEX_ANIM_MAX_Y;

	uv[0] = D3DXVECTOR2(fu*0.0f     , fv*m_nAnimY);
	uv[1] = D3DXVECTOR2(fu*0.0f + fu, fv*m_nAnimY);
	uv[2] = D3DXVECTOR2(fu*0.0f     , fv*m_nAnimY + fv);
	uv[3] = D3DXVECTOR2(fu*0.0f + fu, fv*m_nAnimY + fv);

	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		// �w�i�̐���
		m_aPolygon[nCntPlayer].pBack = CScene2d::Create();
		m_aPolygon[nCntPlayer].pBack->SetSize(BACK_SIZE);
		m_aPolygon[nCntPlayer].pBack->SetPos(boardPos);
		m_aPolygon[nCntPlayer].pBack->SetColor(BACK_DEFAULT_COLOR);
		m_aPolygon[nCntPlayer].pBack->SetPriority(OBJTYPE_UI);
		m_aPolygon[nCntPlayer].pBack->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CHARASELECT_BACK));
		
		// �A�C�R���̐���
		m_aPolygon[nCntPlayer].pControllIcon = CScene2d::Create();
		m_aPolygon[nCntPlayer].pControllIcon->SetSize(CONTOROll_ICON_SIZE);
		m_aPolygon[nCntPlayer].pControllIcon->SetPos(boardPos);
		m_aPolygon[nCntPlayer].pControllIcon->SetColor(ICON_COLOR_OFF);
		m_aPolygon[nCntPlayer].pControllIcon->SetPriority(OBJTYPE_UI);

		// �v���C���[�ԍ��̐���
		m_aPolygon[nCntPlayer].pPlayerNumber = CScene2d::Create();
		m_aPolygon[nCntPlayer].pPlayerNumber->SetSize(PLAYERNUMBER_SIZE);
		m_aPolygon[nCntPlayer].pPlayerNumber->SetPos(D3DXVECTOR3(boardPos.x, PLAYER_NUMBER_POS_Y, boardPos.z));
		m_aPolygon[nCntPlayer].pPlayerNumber->SetPriority(OBJTYPE_UI);
		m_aPolygon[nCntPlayer].pPlayerNumber->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NONE));
		m_aPolygon[nCntPlayer].pPlayerNumber->SetTextureUV(uv);
		boardPos.x += UI_SPACE;
	}

	// �ϐ��̏�����
	m_nCntAnim = 0;       // �A�j���[�V�����J�E���g
	m_nAnimY = 0;         // �A�j���[�V����Y��

	return S_OK;
}

//=============================
// �I������
//=============================
void CCharaSelectUi::Uninit(void)
{
	// �J������
	Release();
}

//=============================
// �X�V����
//=============================
void CCharaSelectUi::Update(void)
{
	// �A�j���[�V����
	m_nCntAnim++;
	if (m_nCntAnim%ANIMATION_INTERVAL == 0)
	{
		m_nAnimY++;
	}

	D3DXVECTOR2 uv[NUM_VERTEX];
	float fu = 1.0f / PLAYERNUMBER_TEX_ANIM_MAX_X;
	float fv = 1.0f / PLAYERNUMBER_TEX_ANIM_MAX_Y;

	uv[0] = D3DXVECTOR2(fu*0.0f     , fv*m_nAnimY);
	uv[1] = D3DXVECTOR2(fu*0.0f + fu, fv*m_nAnimY);
	uv[2] = D3DXVECTOR2(fu*0.0f     , fv*m_nAnimY + fv);
	uv[3] = D3DXVECTOR2(fu*0.0f + fu, fv*m_nAnimY + fv);


	for (int nCntPlayer = 0; nCntPlayer < MAX_PLAYER; nCntPlayer++)
	{
		// �G���g���[�f�[�^�̎擾
		CCharaSelect::Entry_Data entryData = CCharaSelect::GetEntryData(nCntPlayer);
		if (entryData.bEntry)
		{// �G���g���[��
			m_aPolygon[nCntPlayer].pBack->SetColor(GET_COLORMANAGER->GetIconColor(entryData.nColorNum));
			m_aPolygon[nCntPlayer].pControllIcon->SetColor(ICON_COLOR_ON);
			if (entryData.bController)
			{
				m_aPolygon[nCntPlayer].pControllIcon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CONTROLLER));
			}
			else
			{
				m_aPolygon[nCntPlayer].pControllIcon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_KEYBOARD));
			}

			D3DXVECTOR2 uv[NUM_VERTEX];
			float fu = 1.0f / PLAYERNUMBER_TEX_ANIM_MAX_X;
			float fv = 1.0f / PLAYERNUMBER_TEX_ANIM_MAX_Y;

			uv[0] = D3DXVECTOR2(fu*0.0f     , fv*nCntPlayer);
			uv[1] = D3DXVECTOR2(fu*0.0f + fu, fv*nCntPlayer);
			uv[2] = D3DXVECTOR2(fu*0.0f     , fv*nCntPlayer + fv);
			uv[3] = D3DXVECTOR2(fu*0.0f + fu, fv*nCntPlayer + fv);
			m_aPolygon[nCntPlayer].pPlayerNumber->SetTextureUV(uv);
			m_aPolygon[nCntPlayer].pPlayerNumber->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PLAYERNUMBER));

		}
		else
		{// ��G���g���[��
			m_aPolygon[nCntPlayer].pBack->SetColor(BACK_DEFAULT_COLOR);
			m_aPolygon[nCntPlayer].pControllIcon->SetColor(ICON_COLOR_OFF);
			m_aPolygon[nCntPlayer].pPlayerNumber->SetTextureUV(uv);
			m_aPolygon[nCntPlayer].pPlayerNumber->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NONE));
		}
	}

}

//=============================
// �`�揈��
//=============================
void CCharaSelectUi::Draw(void)
{
}

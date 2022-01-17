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
#include "color_manager.h"
#include "character_polygon.h"
#include "attack_area_ui.h"
#include "player.h"
#include "keyboard.h"
#include "joypad.h"

//=============================
// �}�N����`
//=============================
#define BACK_SIZE D3DXVECTOR3(320.0f,720.0f,0.0f)            // �{�[�h�T�C�Y
#define CONTOROll_ICON_SIZE D3DXVECTOR3(180.0f,180.0f,0.0f)  // �R���g���[���[�A�C�R���̃T�C�Y
#define PLAYERNUMBER_SIZE D3DXVECTOR3(240.0f,60.0f,0.0f)     // �v���C���[�ԍ��̃T�C�Y
#define READY_SIZE D3DXVECTOR3(48.0f*5.0f,18.6f*5.0f,0.0f)            // �{�[�h�T�C�Y
#define PLAYERNUMBER_TEX_ANIM_MAX_X 1                        // ���ʃe�N�X�`��������*��
#define PLAYERNUMBER_TEX_ANIM_MAX_Y 4                        // ���ʃe�N�X�`��������*�c
#define ANIMATION_INTERVAL 15                                // �A�j���[�V�����ڍs�t���[����
#define UI_SPACE 320.0f                                      // UI�Ԃ̍��E�̃X�y�[�X
#define BACK_DEFAULT_COLOR D3DXCOLOR(0.7f,0.7f,0.7f,1.0f)    // �f�t�H���g�̃J���[
#define PLAYER_NUMBER_POS_Y 60.0f                            // 
#define CHARACTER_MODEL_POS_Y 350.0f                         // 
#define READY_ICON_POS_Y  450.0f                             // 
#define STATUS_SIZE (D3DXVECTOR3(1089.0f,192.0f,0.0f)*0.26f) // 
#define STATUS_POS_Y (570.0f)                                // 
#define STATUS_POS_Y_OFFSET (STATUS_SIZE.y*1.1f)             // 
#define ON_COLOR  (D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))           // 
#define OFF_COLOR (D3DXCOLOR(1.0f,1.0f,1.0f,0.0f))           // 
#define NAVI_SIZE (D3DXVECTOR3(732.0f,150.0f,0.0f)*0.2f)     // 
#define NAVI_POS_Y (670.0f)                                  // 
#define NAVI_POS_X_OFFSET (50.0f)                            // 
#define CHARANAME_SIZE (D3DXVECTOR3(1042.0f,184.0f,0.0f)*0.286f) // 
#define CHARANAME_POS_Y (130.0f)                                //

//=============================
// �ÓI�����o�ϐ��錾
//=============================
const CCharaSelectUi::CharaStatus CCharaSelectUi::m_aStatusTexNum[CResourceCharacter::CHARACTER_MAX] = 
{
    { CResourceTexture::TEXTURE_DIFFECULT_BEGINNER    ,CResourceTexture::TEXTURE_RANGE_SHORT },  // �R�m
    { CResourceTexture::TEXTURE_DIFFECULT_INTERMEDIATE,CResourceTexture::TEXTURE_RANGE_MEDIAM }, // ��
    { CResourceTexture::TEXTURE_DIFFECULT_INTERMEDIATE,CResourceTexture::TEXTURE_RANGE_LONG },   // �|
    { CResourceTexture::TEXTURE_DIFFECULT_BEGINNER    ,CResourceTexture::TEXTURE_RANGE_SHORT },  // ����
    { CResourceTexture::TEXTURE_DIFFECULT_ADVANCED    ,CResourceTexture::TEXTURE_RANGE_MEDIAM }, // ��p
    { CResourceTexture::TEXTURE_DIFFECULT_ADVANCED    ,CResourceTexture::TEXTURE_RANGE_LONG },   // ���@
};

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
		m_aPolygon[nCntPlayer].pBack->SetPriority(OBJTYPE_UI_2);
		m_aPolygon[nCntPlayer].pBack->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CHARASELECT_BACK));
        
		// �A�C�R���̐���
		m_aPolygon[nCntPlayer].pControllIcon = CScene2d::Create();
		m_aPolygon[nCntPlayer].pControllIcon->SetSize(CONTOROll_ICON_SIZE);
		m_aPolygon[nCntPlayer].pControllIcon->SetPos(boardPos);
		m_aPolygon[nCntPlayer].pControllIcon->SetColor(OFF_COLOR);
		m_aPolygon[nCntPlayer].pControllIcon->SetPriority(OBJTYPE_UI_2);

		// �v���C���[�ԍ��̐���
		m_aPolygon[nCntPlayer].pPlayerNumber = CScene2d::Create();
		m_aPolygon[nCntPlayer].pPlayerNumber->SetSize(PLAYERNUMBER_SIZE);
		m_aPolygon[nCntPlayer].pPlayerNumber->SetPos(D3DXVECTOR3(boardPos.x, PLAYER_NUMBER_POS_Y, boardPos.z));
		m_aPolygon[nCntPlayer].pPlayerNumber->SetPriority(OBJTYPE_UI_2);
		m_aPolygon[nCntPlayer].pPlayerNumber->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NONE_UI));
		m_aPolygon[nCntPlayer].pPlayerNumber->SetTextureUV(uv);
        
        // �L�����N�^�[���̐���
        m_aPolygon[nCntPlayer].pCharaName = CScene2d::Create();
        m_aPolygon[nCntPlayer].pCharaName->SetSize(CHARANAME_SIZE);
        m_aPolygon[nCntPlayer].pCharaName->SetPos(D3DXVECTOR3(boardPos.x, CHARANAME_POS_Y, boardPos.z));
        m_aPolygon[nCntPlayer].pCharaName->SetColor(OFF_COLOR);
        m_aPolygon[nCntPlayer].pCharaName->SetPriority(OBJTYPE_UI_2);
        m_aPolygon[nCntPlayer].pCharaName->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_CHARACTER_NAME_KNIGHT));

        // ���f���|���S���̐���
		m_aPolygon[nCntPlayer].pCharaPolygon = CCharacterPolygon::Create(D3DXVECTOR3(boardPos.x, CHARACTER_MODEL_POS_Y, boardPos.z),CCharacterPolygon::MODE_ROTATION);

		// �A�C�R���̐���
		m_aPolygon[nCntPlayer].pReadyIcon = CScene2d::Create();
		m_aPolygon[nCntPlayer].pReadyIcon->SetSize(READY_SIZE);
		m_aPolygon[nCntPlayer].pReadyIcon->SetPos(D3DXVECTOR3(boardPos.x, READY_ICON_POS_Y, boardPos.z));
		m_aPolygon[nCntPlayer].pReadyIcon->SetColor(OFF_COLOR);
		m_aPolygon[nCntPlayer].pReadyIcon->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_READEY));
		m_aPolygon[nCntPlayer].pReadyIcon->SetPriority(OBJTYPE_UI_2);

        for (int nCntStatus = 0; nCntStatus < STATUS_NUM; nCntStatus++)
        {
            m_aPolygon[nCntPlayer].apStatus[nCntStatus] = CScene2d::Create();
            m_aPolygon[nCntPlayer].apStatus[nCntStatus]->SetSize(STATUS_SIZE);
            m_aPolygon[nCntPlayer].apStatus[nCntStatus]->SetPos(D3DXVECTOR3(boardPos.x, STATUS_POS_Y + (nCntStatus*STATUS_POS_Y_OFFSET), boardPos.z));
            m_aPolygon[nCntPlayer].apStatus[nCntStatus]->SetPriority(OBJTYPE_UI_2);
        }
        
        // �X�e�[�^�X�e�N�X�`��
        m_aPolygon[nCntPlayer].apStatus[0]->BindTexture(CResourceTexture::GetTexture(m_aStatusTexNum[CResourceCharacter::CHARACTER_KNIGHT].nDifficult));
        m_aPolygon[nCntPlayer].apStatus[1]->BindTexture(CResourceTexture::GetTexture(m_aStatusTexNum[CResourceCharacter::CHARACTER_KNIGHT].nRange));

        // �U���͈͗U��UI
        m_aPolygon[nCntPlayer].pNaviAttackArea = CScene2d::Create();
        m_aPolygon[nCntPlayer].pNaviAttackArea->SetSize(NAVI_SIZE);
        m_aPolygon[nCntPlayer].pNaviAttackArea->SetPos(D3DXVECTOR3(boardPos.x+ NAVI_POS_X_OFFSET, NAVI_POS_Y, boardPos.z));
        m_aPolygon[nCntPlayer].pNaviAttackArea->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NAVI_ATTACK_AREA));
        m_aPolygon[nCntPlayer].pNaviAttackArea->SetPriority(OBJTYPE_UI_2);

        // �U���͈̓e�N�X�`��
		m_aPolygon[nCntPlayer].pAttackUiPolygon = CAttackAreaUi::Create(boardPos);
		m_aPolygon[nCntPlayer].pAttackUiPolygon->SetDrawFlag(true);

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
			m_aPolygon[nCntPlayer].pCharaPolygon->SetRimColor(GET_COLORMANAGER->GetStepColor(entryData.nColorNum,1));
			m_aPolygon[nCntPlayer].pCharaPolygon->SetTexColor(GET_COLORMANAGER->GetIconColor(entryData.nColorNum));
			m_aPolygon[nCntPlayer].pControllIcon->SetColor(ON_COLOR);
            m_aPolygon[nCntPlayer].pCharaName->SetColor(ON_COLOR);

            // ���f�B�J���[
			if (entryData.bReady) m_aPolygon[nCntPlayer].pReadyIcon->SetColor(ON_COLOR);
			else m_aPolygon[nCntPlayer].pReadyIcon->SetColor(OFF_COLOR);
            
            // �U���͈͕\��UI
            m_aPolygon[nCntPlayer].pNaviAttackArea->SetColor(ON_COLOR);
            
            // �X�e�[�^�X�J���[
            for (int nCntStatus = 0; nCntStatus < STATUS_NUM; nCntStatus++) m_aPolygon[nCntPlayer].apStatus[nCntStatus]->SetColor(ON_COLOR);
			
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

			// �L�[�{�[�h�ƃW���C�p�b�h�̎擾
			CInputKeyboard * pKey = CManager::GetKeyboard();
			CInputJoypad* pJoypad = CManager::GetJoypad();
			// �U���{�^������������
			if (!entryData.bController && pKey->GetKeyTrigger(CPlayer::GetPlayerControllKey(entryData.nControllNum,CPlayer::KEY_ATTCK_FINAL))
				|| entryData.bController &&pJoypad->GetButtonState(XINPUT_GAMEPAD_Y, CInputJoypad::BUTTON_TRIGGER, entryData.nControllNum))
			{
				// �U���͈͂ɃL�����^�C�v�̓K�p
				m_aPolygon[nCntPlayer].pAttackUiPolygon->SetCharaType(entryData.charaType);
				// �U���͈͕\���̐؂�ւ�
				m_aPolygon[nCntPlayer].pAttackUiPolygon->SwitchDrawFlag();
			}
		}
		else
		{// ��G���g���[��
			m_aPolygon[nCntPlayer].pBack->SetColor(BACK_DEFAULT_COLOR);
			m_aPolygon[nCntPlayer].pControllIcon->SetColor(OFF_COLOR);
			m_aPolygon[nCntPlayer].pReadyIcon->SetColor(OFF_COLOR);
            for (int nCntStatus = 0; nCntStatus < STATUS_NUM; nCntStatus++) m_aPolygon[nCntPlayer].apStatus[nCntStatus]->SetColor(OFF_COLOR);
			m_aPolygon[nCntPlayer].pPlayerNumber->SetTextureUV(uv);
			m_aPolygon[nCntPlayer].pPlayerNumber->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_NONE_UI));
			m_aPolygon[nCntPlayer].pAttackUiPolygon->SetDrawFlag(false);
            m_aPolygon[nCntPlayer].pNaviAttackArea->SetColor(OFF_COLOR);
            m_aPolygon[nCntPlayer].pCharaName->SetColor(OFF_COLOR);
		}

		if (m_aPolygon[nCntPlayer].pCharaPolygon->GetCharaType() != entryData.charaType)
		{// �L�����N�^�[���ς�����Ƃ�
           
            m_aPolygon[nCntPlayer].pAttackUiPolygon->SetCharaType(entryData.charaType);
			m_aPolygon[nCntPlayer].pAttackUiPolygon->Reset();

			m_aPolygon[nCntPlayer].pCharaPolygon->SetCharaType(entryData.charaType);

            if (entryData.charaType == -1) continue;
            m_aPolygon[nCntPlayer].pCharaName->BindTexture(CResourceTexture::GetTexture((CResourceTexture::TEXTURE_TYPE)(CResourceTexture::TEXTURE_CHARACTER_NAME_KNIGHT+ entryData.charaType)));
            m_aPolygon[nCntPlayer].apStatus[0]->BindTexture(CResourceTexture::GetTexture(m_aStatusTexNum[entryData.charaType].nDifficult));
            m_aPolygon[nCntPlayer].apStatus[1]->BindTexture(CResourceTexture::GetTexture(m_aStatusTexNum[entryData.charaType].nRange));
		}
		
	}
}

//=============================
// �`�揈��
//=============================
void CCharaSelectUi::Draw(void)
{
}

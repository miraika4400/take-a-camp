////////////////////////////////////////////////////
//
//    player�N���X�̏���[player.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "player.h"
#include "manager.h"
#include "renderer.h"
#include "keyboard.h"
#include "joypad.h"
#include "collision.h"
#include "debug_log.h"
#include "act_range.h"
#include "tile.h"
#include "number_array.h"
#include "color_manager.h"
#include "bullet.h"
#include "attack.h"
#include "attack_knight.h"
#include "resource_shader.h"
#include "light.h"
#include "camera_base.h"
#include "motion.h"
#include "resource_texture.h"
#include "color_tile.h"
#include "chara_select.h"
#include "kill_count.h"
#include "particle.h"
#include "resource_model_hierarchy.h"
#include "attack_final.h"
#include "attack_final_knight.h"
#include "skill_gauge.h"

//*****************************
// �}�N����`
//*****************************
#define MOVE_DIST				(TILE_ONE_SIDE)	// �ړ�����
#define COLLISION_RADIUS		(18.0f)			// �����蔻��̑傫��
#define MODL_COLOR				(D3DXCOLOR(0.3f,0.3f,0.3f,1.0f))	// ���f���J���[
#define MODEL_SIZE				(D3DXVECTOR3(1.4f,1.4f,1.4f))		// ���f���T�C�Y
#define RESPAWN_MAX_COUNT		(60*5)			// ���X�|�[���܂ł̍ő�J�E���g
#define INVINCIBLE_COUNT		(60*2)			// ���G����
#define ROTDEST_PREVIOUS		(0.0f)			// �O������
#define ROTDEST_AFTER 			(180.0f)		// �������
#define ROTDEST_LEFT			(270.0f)		// ������
#define ROTDEST_RIGHT			(90.0f)			// �E����
#define ROT_SPEED				(0.3f)			// ��]���x
#define ROT_FACING_01			(180)			// ��]�̊
#define ROT_FACING_02			(360)			// ��]����
#define RIM_POWER				(2.5f)			// �������C�g�̋���
#define DASH_FRAME				(300)			// �_�b�V�����L���t���[����
#define STICK_DECISION_RANGE	(32768.0f / 1.001f)	// �X�e�B�b�N�̏㉺���E�̔��肷��͈�

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CPlayer::m_anControllKey[MAX_PLAYER][CPlayer::KEY_MAX] =
{
	{ DIK_W,DIK_S,DIK_A,DIK_D,DIK_E,DIK_Q },
	{ DIK_UP,DIK_DOWN,DIK_LEFT,DIK_RIGHT,DIK_NUMPAD1,DIK_RSHIFT },
	{ DIK_U,DIK_J,DIK_H,DIK_K,DIK_I,DIK_Y },
	{ DIK_NUMPAD8,DIK_NUMPAD5,DIK_NUMPAD4,DIK_NUMPAD6,DIK_NUMPAD9,DIK_NUMPAD7 }
};

//******************************
// �R���X�g���N�^
//******************************
CPlayer::CPlayer() :CModelHierarchy(OBJTYPE_PLAYER)
{
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_ReverseCount = 0;
	m_nRespawnCount = 0;
	m_nPlayerNumber = 0;
	m_nInvincibleCount = 0;
	m_nControllNum = 0;
	m_bMove = false;
	m_bInvincible = false;
	m_PlayerState = PLAYER_STATE_NORMAL;
	m_pCollision = NULL;
	m_nColor = 0;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	memset(&m_RespawnPos, 0, sizeof(D3DXVECTOR3));
	m_MoveCount = 0;
	m_pAttack = NULL;
	memset(&m_apMotion, 0, sizeof(m_apMotion));	// �A�j���[�V�����|�C���^
	m_ItemState = ITEM_STATE_NONE;	// �A�C�e���p�X�e�[�g
	m_nDashCnt = 1;					// ���x�A�b�v�J�E���g
	m_bController = false;
	m_bAttack = false;
	m_bFinalAttack = false;
	m_pKillCount = NULL;
	m_characterType = CResourceCharacter::CHARACTER_KNIGHT;
	m_nMoveFrameData = 0;
	m_nMoveFrameDataDash = 0;
}

//******************************
// �f�X�g���N�^
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// �N���X����
//******************************
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber)
{
	// �������̊m��
	CPlayer *pPlayer;
	pPlayer = new CPlayer;

	// init�Ŏg�������ɑ��
	pPlayer->m_nPlayerNumber = nPlayerNumber;

	// ������
	pPlayer->Init();

	// �e�l�̑���E�Z�b�g
	pPlayer->SetPos(pos);
	pPlayer->SetRot(rot);
	pPlayer->SetPriority(OBJTYPE_PLAYER); // �I�u�W�F�N�g�^�C�v
	pPlayer->m_Move = pos;
	pPlayer->m_RespawnPos = pos;

	//�U���p�N���X����(����E�Ƃ��Ƃ�create����U��������ς���)
	pPlayer->m_pAttack = CAttackKnight::Create(pPlayer);

	// �K�E�p�N���X����
	pPlayer->m_pAttackFinal = CAttackFinalknight::Create(pPlayer);

	//�ړ��͈̓N���X�̐���
	pPlayer->m_pActRange = CActRange::Create(pPlayer);

	return pPlayer;
}

//******************************
// ����������
//******************************
HRESULT CPlayer::Init(void)
{
	// �L�����f�[�^�̎擾
	//m_characterType = CCharaSelect::GetEntryData(m_nPlayerNumber).charaType;
	CResourceCharacter::CharacterData charaData = CResourceCharacter::GetResourceCharacter()->GetCharacterData(m_characterType);

	if (FAILED(CModelHierarchy::Init(charaData.modelType)))
	{
		return E_FAIL;
	}

	// �L�����f�[�^�̔��f
	m_nMoveFrameData = charaData.nMoveFrame; // �ړ����t���[����
	m_nMoveFrameDataDash = charaData.nMoveFrameDash;// �ړ����t���[����*�_�b�V����

	// �ړ��t���O�̏�����
	m_bMove = true;
	// ���G�t���O�̏�����
	m_bInvincible = false;
	//�v���C���[�X�e�[�^�X������
	m_PlayerState = PLAYER_STATE_NORMAL;
	//�F�ݒ�
	m_color = MODL_COLOR;
	// �R���g���[���ԍ�
	m_nControllNum = CCharaSelect::GetEntryData(m_nPlayerNumber).nControllNum;
	m_bController = CCharaSelect::GetEntryData(m_nPlayerNumber).bController;
	// �J���[�ԍ��̎擾
	m_nColor = CCharaSelect::GetEntryData(m_nPlayerNumber).nColorNum;
	CColorManager::GetColorManager()->SetUsePlayerNum(m_nPlayerNumber, m_nColor);

	// �L���J�E���g�p�̃N���X
	m_pKillCount = CKillCount::Create(m_nPlayerNumber);
	// ���f���̃T�C�Y�̐ݒ�
	SetSize(MODEL_SIZE);

	// �X�L���Q�[�W�̐���(��X�����ɐE�����ăA�C�R���ς���)
	CSkillgauge::AllCreate(m_nColor);

	// �v���C���[�̓���ɏo���X�R�A����
	CNumberArray::Create(0, GetPos(), D3DXVECTOR3(10.0f, 10.0f, 0.0f), GET_COLORMANAGER->GetIconColor(m_nColor), m_nColor);

	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);	

	for (int nCntAnim = 0; nCntAnim < CResourceCharacter::MOTION_MAX; nCntAnim++)
	{
		m_apMotion[nCntAnim] = CMotion::Create(GetPartsNum(), charaData.aMotionTextPath[nCntAnim].c_str(), GetModelData());
	}

	m_apMotion[CResourceCharacter::MOTION_IDLE]->SetActiveMotion(true);

	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);

	// �A�C�e���X�e�[�g
	m_ItemState = ITEM_STATE_NONE;

	m_nMoveFrame = m_nMoveFrameData;
	m_nDashCnt = 1;		//���x�A�b�v�J�E���g
	return S_OK;
}

//******************************
// �I������
//******************************
void CPlayer::Uninit(void)
{
	//�����蔻��̏I������
	if (m_pCollision != NULL)
	{
		m_pCollision->ReConnection();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}

	CModelHierarchy::Uninit();
}

//******************************
// �X�V����
//******************************
void CPlayer::Update(void)
{
	//�X�e�[�g���Ƃ̏���
	switch (m_PlayerState)
	{
	case PLAYER_STATE_REVERSE:
	{
		m_ReverseCount++;
		if (m_ReverseCount % 180 == 0)
		{
			m_ReverseCount = 0;
			SetState(PLAYER_STATE_NORMAL);
		}

		if (m_ReverseCount % 15 == 0)
		{
			D3DXVECTOR3 pos = GetPos();
			pos.y += 10.0f;
			CParticle::Create(pos, D3DXVECTOR3((float)(rand() % 16 - 8)/100.0f, 0.25f, (float)(rand() % 16 - 8) / 100.0f), D3DXVECTOR3(7.0f, 7.0f, 7.0f), 500, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), EFFECT_DEFAULT_FADE_OUT_RATE, CParticle::PARTICLE_GURUGURU)->SetAddRotValue(1.2f);
		}
	}
	case PLAYER_STATE_NORMAL:	//�ʏ���

		//�U���ۃt���O�������Ă��邩
		if (m_pAttack->GetState() != CAttackBased::ATTACK_STATE_ATTACK
			&&m_pAttackFinal->GetState() != CAttackFinal::FINAL_ATTACK_STATE_ATTACK)
		{
			// �����̊Ǘ�
			ManageRot();
			// �ړ�����
			Move();

			//�U��
			if (m_pAttack->GetState() != CAttackBased::ATTACK_STATE_CHARGE)
			{
				// �K�E�̏���
				AttackFinal();
			}
			
			// �U������
			Attack();
		}

		//���G����
		Invincible();


		// �����蔻��̈ʒu
		if (m_pCollision == NULL)
		{
			m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS / 2);
		}
		else
		{
			m_pCollision->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
		}
		break;
	case PLAYER_STATE_DEATH:	//���S���
		//���X�|�[������
		Respawn();
		// �U���͈͂�����
		m_pAttack->ResetAttackArea();
		break;
	}

	// �A�C�e���X�e�[�g�̊Ǘ�
	ManageItemState();

	// ���[�V�����Ǘ�
	ManageMotion();

	// 
#ifdef _DEBUG
	// �L�[�{�[�h�̎擾
	if (m_nPlayerNumber == 0)
	{
		CInputKeyboard * pKey = CManager::GetKeyboard();
		if (pKey->GetKeyPress(DIK_1))
		{
			Death();
		}
		if (pKey->GetKeyPress(DIK_2))
		{
			m_pAttack->AttackSwitch();
		}
		if (pKey->GetKeyPress(DIK_3))
		{
			m_pAttack->AttackSwitch();
		}
	}

#endif // _DEBUG

}

//******************************
// �`�揈��
//******************************
void CPlayer::Draw(void)
{
	// �F�̐ݒ�
	for (int nCntParts = 0; nCntParts < GetPartsNum(); nCntParts++)
	{
		for (int nCntMat = 0; nCntMat < (int)GetModelData()[nCntParts].nNumMat; nCntMat++)
		{
			D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()[nCntParts].pBuffMat->GetBufferPointer();
			mat[nCntMat].MatD3D.Ambient .a = m_color.a;
			mat[nCntMat].MatD3D.Diffuse .a = m_color.a;
			mat[nCntMat].MatD3D.Specular.a = m_color.a;
			mat[nCntMat].MatD3D.Emissive.a = m_color.a;
		}
	}

	CModelHierarchy::Draw();
}

//******************************
// ���S����
//******************************
void CPlayer::Death(void)
{
	if (!m_bInvincible)
	{
		//���S��ԂɈڍs
		SetState(PLAYER_STATE_DEATH);

		//�����蔻�������
		if (m_pCollision != NULL)
		{
			m_pCollision->ReConnection();
			m_pCollision->Uninit();
			delete m_pCollision;
			m_pCollision = NULL;
		}

		//�s���N���X�Ɏ��S��ԂɂȂ����t���O�𑗂�
		m_pActRange->SetDeath(true);
		//�U����Ԃ̏�����
		m_pAttack->SetState(CAttackBased::ATTACK_STATE_NORMAL);
		//�����ɂ���
		m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

		//�ʒu�Z�b�g
		SetPos(m_RespawnPos);
	}

}

//******************************
// �X�L���ł̎��S����
//******************************
void CPlayer::SkillDeath(void)
{
	if (!m_bInvincible)
	{
		//���S��ԂɈڍs
		SetState(PLAYER_STATE_DEATH);

		//�����蔻�������
		if (m_pCollision != NULL)
		{
			m_pCollision->ReConnection();
			m_pCollision->Uninit();
			delete m_pCollision;
			m_pCollision = NULL;
		}

		//�s���N���X�Ɏ��S��ԂɂȂ����t���O�𑗂�
		m_pActRange->SetDeath(true);
		//�U����Ԃ̏�����
		m_pAttack->SetState(CAttackBased::ATTACK_STATE_NORMAL);
		//�����ɂ���
		m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

		//�ʒu�Z�b�g
		SetPos(m_RespawnPos);

	}
}

//******************************
// �ړ�����
//******************************
void CPlayer::Move(void)
{
	if (m_bMove)
	{
		// �L�[�{�[�h�ƃW���C�p�b�h�̎擾
		CInputKeyboard * pKey = CManager::GetKeyboard();
		CInputJoypad* pJoypad = CManager::GetJoypad();

		// �X�e�B�b�N�̍��W
		D3DXVECTOR2 StickPos = pJoypad->GetStickState(pJoypad->PAD_LEFT_STICK, m_nControllNum);

		// �ړ��l
		auto MoveValue = [&](D3DXVECTOR3 move, D3DXVECTOR2 actMove, float fRotDistY)
		{
			//�v���C���[�̈ړ������擾�ϐ�
			D3DXVECTOR2 ActMove;

			//����t�]��Ԃ���Ȃ���
			if (m_PlayerState != PLAYER_STATE_REVERSE)
			{
				ActMove = actMove;
				if (m_pActRange->ActMove(((int)ActMove.x),((int) ActMove.y)))
				{
					m_Move += move;
					m_bMove = false;
					m_rotDest.y = fRotDistY;
				}
			}
			//����t�]��Ԃ̎�
			else
			{
				ActMove = actMove*-1;
				if (m_pActRange->ActMove(((int)ActMove.x), ((int)ActMove.y)))
				{
					m_Move += move*-1;
					m_bMove = false;
					m_rotDest.y = fRotDistY - D3DXToRadian(180);
				}
			}
			m_pActRange->SetMove(m_bMove);

		};

		if (!m_bController && pKey->GetKeyPress(m_anControllKey[m_nControllNum][KEY_PROGRESS])
			|| m_bController && ((StickPos.y > 0.0f && StickPos.x < STICK_DECISION_RANGE && StickPos.x > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_UP, pJoypad->BUTTON_PRESS, m_nControllNum)))
		{
			MoveValue(D3DXVECTOR3(0.0f, 0.0f, -MOVE_DIST), D3DXVECTOR2(0, -1), D3DXToRadian(ROTDEST_PREVIOUS));
		}
		else if (!m_bController && pKey->GetKeyPress(m_anControllKey[m_nControllNum][KEY_RECESSION])
			|| m_bController && ((StickPos.y < 0.0f && StickPos.x < STICK_DECISION_RANGE && StickPos.x > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_DOWN, pJoypad->BUTTON_PRESS, m_nControllNum)))
		{
			MoveValue(D3DXVECTOR3(0.0f, 0.0f, MOVE_DIST), D3DXVECTOR2(0, 1), D3DXToRadian(ROTDEST_AFTER));
		}
		else if (!m_bController && pKey->GetKeyPress(m_anControllKey[m_nControllNum][KEY_LEFT])
			|| m_bController && ((StickPos.x < 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_LEFT, pJoypad->BUTTON_PRESS, m_nControllNum)))
		{
			MoveValue(D3DXVECTOR3(MOVE_DIST, 0.0f, 0.0f), D3DXVECTOR2(-1, 0), D3DXToRadian(ROTDEST_LEFT));
		}
		else if (!m_bController && pKey->GetKeyPress(m_anControllKey[m_nControllNum][KEY_RIGHT])
			|| m_bController && ((StickPos.x > 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_RIGHT, pJoypad->BUTTON_PRESS, m_nControllNum)))
		{
			MoveValue(D3DXVECTOR3(-MOVE_DIST, 0.0f, 0.0f), D3DXVECTOR2(1, 0), D3DXToRadian(ROTDEST_RIGHT));
		}

	}
	else
	{
		// ���W�̎擾
		D3DXVECTOR3 pos = GetPos();

		//�ړ��v�Z
		pos += (m_Move - pos) / (float)(m_nMoveFrame - m_MoveCount);

		//�ʒu�ݒ�
		SetPos(pos);

		//�J�E���g�A�b�v
		m_MoveCount++;

		//�J�E���g�����ɒB����
		if (m_MoveCount >= m_nMoveFrame)
		{
			//�J�E���g������
			m_MoveCount = 0;
			//�ړ��ł���悤��
			m_bMove = true;

			m_pActRange->SetMove(m_bMove);
		}
	}
}

//******************************
// �����̊Ǘ�����
//******************************
void CPlayer::ManageRot(void)
{
	// �����̎擾
	D3DXVECTOR3 rot = GetRot();

	while (m_rotDest.y - rot.y > D3DXToRadian(ROT_FACING_01))
	{
		m_rotDest.y -= D3DXToRadian(ROT_FACING_02);
	}

	while (m_rotDest.y - rot.y < D3DXToRadian(-ROT_FACING_01))
	{
		m_rotDest.y += D3DXToRadian(ROT_FACING_02);
	}

	// �ڕW�̌����ɕς���
	rot += (m_rotDest - rot)*ROT_SPEED;

	// �����ݒ�
	SetRot(rot);
}

//******************************
// �U������
//******************************
void CPlayer::Attack(void)
{
	// �L�[�{�[�h�ƃW���C�p�b�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CInputJoypad* pJoypad = CManager::GetJoypad();

	// �������Ă���^�C���̎擾
	CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPos());
	
	//�G��Ă���^�C���̎��ʁ��U���̏󋵂��U�����ɂȂ��Ă��Ȃ���
	if (pHitTile != NULL&&pHitTile->GetPeintNum() == m_nColor 
		&& m_pAttack->GetState() == CAttackBased::ATTACK_STATE_NORMAL)
	{
		// �U���{�^������������
		if (!m_bController && pKey->GetKeyPress(m_anControllKey[m_nControllNum][KEY_BULLET])
			|| m_bController &&pJoypad->GetButtonState(XINPUT_GAMEPAD_X, pJoypad->BUTTON_PRESS, m_nControllNum))
		{
			//�^�C�����`���[�W�o���邩�擾
			if (pHitTile->ChargeFlag(m_nPlayerNumber))
			{
				//�U���`���[�W���J�n
				m_pAttack->ChargeFlag(pHitTile->GetStepNum()-1);

			}
			//�`���[�W�ł����ԂɂȂ�t���O������
			else
			{
				//�U���͈͂̉���
				m_pAttack->VisualizationAttackArea();
			}
		}
	
	}

	//�`���[�W��Ԃ�
	if (m_pAttack->GetState() == CAttackBased::ATTACK_STATE_CHARGE)
	{
		//�U���͈̘͂g�̐F��ς���
		m_pAttack->VisualizationAttackArea();

		// ��������U�����ł�悤��
		if (!m_bController && pKey->GetKeyRelease(m_anControllKey[m_nControllNum][KEY_BULLET])
			|| m_bController && pJoypad->GetButtonState(XINPUT_GAMEPAD_X, pJoypad->BUTTON_RELEASE, m_nControllNum))
		{
			//�U���t���O�𗧂Ă�
			m_bAttack = true;
		}

	}
	//�U���t���O�������Ă��邩���ړ��t���O�������Ă��Ȃ���Ԃ�
	if (m_bAttack&&m_bMove)
	{
		//�t���O�����
		m_bAttack = false;
		//�U���X�C�b�`����
		m_pAttack->AttackSwitch();
		//�A�j���[�V��������
		m_apMotion[CResourceCharacter::MOTION_ATTACK]->SetActiveMotion(true);
	}
}

//******************************
// �K�E����
//******************************
void CPlayer::AttackFinal(void)
{
	// �L�[�{�[�h�ƃW���C�p�b�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CInputJoypad* pJoypad = CManager::GetJoypad();

	// �������Ă���^�C���̎擾
	CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPos());

	if (m_pAttack->GetState() == CAttackFinal::FINAL_ATTACK_STATE_NOMAL)
	{
		if (m_pAttackFinal->GetState() == CAttackFinal::FINAL_ATTACK_STATE_NOMAL)
		{
			// �U���{�^������������
			if (!m_bController && pKey->GetKeyPress(m_anControllKey[m_nControllNum][KEY_ATTCK_FINAL])
				|| m_bController &&pJoypad->GetButtonState(XINPUT_GAMEPAD_Y, pJoypad->BUTTON_PRESS, m_nControllNum))
			{
				//�U���͈̘͂g�̐F��ς���
				m_pAttackFinal->VisualizationAttackArea();
			}
		}
	}

	// ��������e���ł�悤��
	if (!m_bController && pKey->GetKeyRelease(m_anControllKey[m_nControllNum][KEY_ATTCK_FINAL])
		|| m_bController && pJoypad->GetButtonState(XINPUT_GAMEPAD_Y, pJoypad->BUTTON_RELEASE, m_nControllNum))
	{
		//�K�E�X�C�b�`����
		m_pAttackFinal->AttackFinalSwitch();
		m_apMotion[CResourceCharacter::MOTION_ATTACK]->SetActiveMotion(true);

		//�U���t���O�𗧂Ă�
		//m_bFinalAttacl = true;
	}
}

//******************************
// ���X�|�[������
//******************************
void CPlayer::Respawn(void)
{
	//�v���C���[�X�e�[�g�����S��Ԃ̎�
	if (m_PlayerState == PLAYER_STATE_DEATH)
	{
		//�J�E���g�A�b�v
		m_nRespawnCount++;
		
		//�J�E���g�����܂łɒB�����Ƃ�
		if (m_nRespawnCount >= RESPAWN_MAX_COUNT)
		{
			//�ʒu�Z�b�g
			SetPos(m_RespawnPos);
			m_Move = m_RespawnPos;
			//�s���N���X�ɒʏ��ԂɂȂ����t���O�𑗂�
			m_pActRange->SetDeath(false);
			//�s���N���X�Ɉʒu�ݒ������悤�ɑ���
			m_pActRange->PlayerPos();
			//���G����
			m_bInvincible = true;
			//�F�ݒ�
			m_color = MODL_COLOR;
			//�ʏ��ԂɈڍs
			SetState(PLAYER_STATE_NORMAL);
			//�J�E���g������
			m_nRespawnCount = 0;
		}
	}
}

//******************************
// ���G����
//******************************
void CPlayer::Invincible(void)
{
	//���G�t���O�������Ă��邩
	if (m_bInvincible)
	{
		//���G�J�E���g�A�b�v
		m_nInvincibleCount++;

		//5�̔{���ŃJ���[��ύX�i�_�ł���悤�Ɂj
		if ((m_nInvincibleCount % 5) == 0)
		{
			//�_��
			if (m_color.a <= 0.0f)
			{
				m_color.a = 1.0f;
			}
			else
			{
				m_color.a = 0.0f;
			}
		}

		//�J�E���g�����ɂȂ�����
		if (m_nInvincibleCount >= INVINCIBLE_COUNT)
		{
			//������
			m_nInvincibleCount = 0;
			m_color.a = 1.0f;
			m_bInvincible = false;
		}
	}
}

//******************************
// ���[�V�����Ǘ�
//******************************
void CPlayer::ManageMotion(void)
{
	for (int nCntMotion = 0; nCntMotion < CResourceCharacter::MOTION_MAX; nCntMotion++)
	{
		if (m_apMotion[CResourceCharacter::MOTION_IDLE]->GetActiveMotion())
		{
			if (nCntMotion == CResourceCharacter::MOTION_IDLE)
			{
				continue;
			}

			if (m_apMotion[nCntMotion]->GetActiveMotion())
			{
				m_apMotion[CResourceCharacter::MOTION_IDLE]->SetActiveMotion(false);
			}
		}
		else
		{
			if (nCntMotion == CResourceCharacter::MOTION_IDLE)
			{
				continue;
			}
			if (m_apMotion[nCntMotion]->GetActiveMotion())
			{
				break;
			}
			m_apMotion[CResourceCharacter::MOTION_IDLE]->SetActiveMotion(true);
		}
	}
}

//******************************
// �A�C�e���X�e�[�g�̊Ǘ�
//******************************
void CPlayer::ManageItemState(void)
{
	switch (m_ItemState)
	{
	case ITEM_STATE_NONE:
		break;
	case ITEM_STATE_DASH:

		//�_�b�V���^�C�����J�E���g
		m_nDashCnt++;

		m_nMoveFrame = (int)(m_nMoveFrameDataDash);

		if (m_nDashCnt % DASH_FRAME == 0)
		{
			m_nDashCnt = 0;
			m_nMoveFrame = m_nMoveFrameData;
			m_ItemState = ITEM_STATE_NONE;
		}
		break;
	case ITEM_STATE_REVERSE:
		CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

		while (pPlayer != NULL)
		{
			if (pPlayer->m_PlayerState != PLAYER_STATE_DEATH)
			{
				if (pPlayer->GetPlayerNumber() != m_nPlayerNumber)
				{
					pPlayer->SetState(PLAYER_STATE_REVERSE);
					m_ItemState = ITEM_STATE_NONE;
					//return;
				}
			}
			pPlayer = (CPlayer*)pPlayer->GetNext();
		}
		break;
	}
}

//******************************
// ���f���`�揈��
//******************************
void CPlayer::DrawModel(void)
{
	//�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DMATERIAL9 matDef;	//���݂̃}�e���A���ێ��p
	D3DXMATERIAL*pMat;	//�}�e���A���f�[�^�ւ̃|�C���^

	CResourceModel::Model *pModelData = GetModelData();

	for (int nCntParts = 0; nCntParts < GetPartsNum(); nCntParts++)
	{
		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &pModelData[nCntParts].mtxWorld);

		//���݂̃}�e���A�����擾����
		pDevice->GetMaterial(&matDef);

		// �V�F�[�_�[���̎擾
		CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_PLAYER);

		if (shader.pEffect != NULL)
		{
			// �V�F�[�_�[�v���O�����ɒl�𑗂�
			SetShaderVariable(shader.pEffect, &pModelData[nCntParts]);

			//�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)pModelData[nCntParts].pBuffMat->GetBufferPointer();

			// �p�X���̎擾
			UINT numPass = 0;
			shader.pEffect->Begin(&numPass, 0);

			// �p�X�����`�揈���̃��[�v
			for (int nCntMat = 0; nCntMat < (int)pModelData[nCntParts].nNumMat; nCntMat++)
			{
				//�}�e���A���̃A���r�G���g�Ƀf�B�t���[�Y�J���[��ݒ�
				pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

				//�}�e���A���̐ݒ�
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
				// �e�N�X�`��
				pDevice->SetTexture(0, pModelData[nCntParts].apTexture[nCntMat]);
				// �e�N�X�`�����V�F�[�_�[�ɑ���
				shader.pEffect->SetTexture("Tex", pModelData[nCntParts].apTexture[nCntMat]);
				// �F
				shader.pEffect->SetFloatArray("DiffuseColor", (float*)&pMat[nCntMat].MatD3D.Diffuse, 4);

				if (pModelData[nCntParts].apTexture[nCntMat] == NULL)
				{
					// �V�F�[�_�p�X�̕`��J�n
					shader.pEffect->BeginPass(0);
				}
				else
				{
					// �V�F�[�_�p�X�̕`��J�n
					shader.pEffect->BeginPass(1);
				}

				// ���f���p�[�c�̕`��
				pModelData[nCntParts].pMesh->DrawSubset(nCntMat);
				// �V�F�[�_�p�X�̏I��
				shader.pEffect->EndPass();

				pMat[nCntMat] = pModelData[nCntParts].defMat[nCntMat];

			}
			// �V�F�[�_�[�I��
			shader.pEffect->End();
		}

		//�ێ����Ă����}�e���A����߂�
		pDevice->SetMaterial(&matDef);
		// �e�N�X�`���̏�����
		pDevice->SetTexture(0, 0);
	}
}


//=============================
// �V�F�[�_�[�ɒl�𑗂�
//=============================
void CPlayer::SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData)
{
	if (pEffect != NULL)
	{
		// �V�F�[�_�[�ɏ���n��
		D3DXMATRIX mat;
		D3DXMatrixIdentity(&mat);
		mat = pModelData->mtxWorld * (*CManager::GetCamera()->GetViewMtx())* (*CManager::GetCamera()->GetProjectionMtx());
		// ���[���h�v���W�F�N�V����
		pEffect->SetMatrix("WorldViewProj", &mat);
		// ���[���h���W
		pEffect->SetMatrix("World", &pModelData->mtxWorld);
		// ���C�g�f�B���N�V����
		D3DXVECTOR3 lightDir = LIGHT_DIR_BASE;
		pEffect->SetFloatArray("LightDirection", (float*)&D3DXVECTOR3(lightDir.x, -lightDir.y, -lightDir.z), 3);
		// ���_�ʒu
		D3DXVECTOR3 eye = CManager::GetCamera()->GetPos();
		pEffect->SetFloatArray("Eye", (float*)&D3DXVECTOR3(eye.x, eye.y, eye.z), 3);
		// �X�y�L�����̏��𑗂�
		pEffect->SetFloatArray("SpecularColor", (float*)&D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 4);
		// ��������\�̏��𑗂�
		D3DXCOLOR iconCol = GET_COLORMANAGER->GetColorDataByPlayerNumber(m_nColor).iconColor;
		pEffect->SetFloatArray("RimColor", (float*)&iconCol, 4);
		pEffect->SetFloat("RimPower", RIM_POWER);
		// �L���[�u�e�N�X�`��
		pEffect->SetTexture("CubeTex", CResourceTexture::GetCubeTexture(CResourceTexture::TECTURE_CUBE_SLY));
		// �g�D�[���V���h�E�e�N�X�`�����V�F�[�_�[�ɑ���
		pEffect->SetTexture("ToonTex", CResourceTexture::GetTexture(CResourceTexture::TEXTURE_TOON_SHADOW));
	}
}

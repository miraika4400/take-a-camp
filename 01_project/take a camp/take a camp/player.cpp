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
#include "attack_1.h"
#include "resource_shader.h"
#include "light.h"
#include "camera_base.h"
#include "motion.h"
#include "resource_texture.h"

//*****************************
// �}�N����`
//*****************************
#define HIERARCHY_TEXT_PATH1 "data/Text/hierarchy/knight.txt"   // �K�w�\���e�L�X�g�̃p�X
#define MOVE_DIST (TILE_ONE_SIDE)	// �ړ�����
#define MOVE_FRAME 15				// �ړ����x
#define COLLISION_RADIUS 18.0f
#define MODL_COLOR D3DXCOLOR(0.3f,0.3f,0.3f,1.0f)
//#define MODEL_SIZE D3DXVECTOR3( 0.3f, 0.3f, 0.3f)
#define MODEL_SIZE D3DXVECTOR3( 1.0f, 1.0f, 1.0f)
#define RESPAWN_MAX_COUNT (60*5)	// ���X�|�[���܂ł̍ő�J�E���g
#define INVINCIBLE_COUNT (60*2)		// ���G����
#define ROTDEST_PREVIOUS 0.0f		// �O������
#define ROTDEST_AFTER 	180.0f		// �������
#define ROTDEST_LEFT 270.0f			// ������
#define ROTDEST_RIGHT 90.0f			// �E����
#define ROT_SPEED 0.3f				// ��]���x
#define ROT_FACING_01 180			// ��]�̊
#define ROT_FACING_02 360			// ��]����
#define RIM_POWER     0.5f          // �������C�g�̋���
#define DASH_FRAME      300
#define DASH_MOVE_FRAME  MOVE_FRAME*0.8f
#define STICK_DECISION_RANGE (32768.0f / 1.001f)	// �X�e�B�b�N�̏㉺���E�̔��肷��͈�

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CPlayer::m_anControllKey[4][CPlayer::KEY_MAX] =
{
	{ DIK_W,DIK_S,DIK_A,DIK_D,DIK_E },
	{ DIK_UP,DIK_DOWN,DIK_LEFT,DIK_RIGHT,DIK_NUMPAD1 },
	{ DIK_U,DIK_J,DIK_H,DIK_K,DIK_I },
	{ DIK_NUMPAD8,DIK_NUMPAD5,DIK_NUMPAD4,DIK_NUMPAD6,DIK_NUMPAD9 }
};
CResourceModel::Model CPlayer::m_model[MAX_PARTS_NUM] = {};
int CPlayer::m_nPartsNum = 0;
char CPlayer::m_achAnimPath[MOTION_MAX][64]
{
	{ "data/Text/motion/run.txt" },         // �����A�j���[�V����
};

//******************************
// �R���X�g���N�^
//******************************
CPlayer::CPlayer() :CModelHierarchy(OBJTYPE_PLAYER)
{
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_nRespawnCount = 0;
	m_nPlayerNumber = 0;
	m_nInvincibleCount = 0;
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
	memset(&m_apMotion, 0, sizeof(m_apMotion));
	m_ItemState = ITEM_STATE_NONE;
	m_nMoveframe = 0;				// �ړ����x
	m_nDashCnt = 1;		//���x�A�b�v�J�E���g
}

//******************************
// �f�X�g���N�^
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// �e�N�X�`���̃��[�h
//******************************
HRESULT CPlayer::Load(void)
{
	// ���f���̓ǂݍ���
	LoadModels(HIERARCHY_TEXT_PATH1, &m_model[0], &m_nPartsNum);

	return S_OK;
}

//******************************
// �e�N�X�`���̃A�����[�h
//******************************
void CPlayer::Unload(void)
{
	for (int nCnt = 0; nCnt < m_nPartsNum; nCnt++)
	{
		//���b�V���̔j��
		if (m_model[nCnt].pMesh != NULL)
		{
			m_model[nCnt].pMesh->Release();
			m_model[nCnt].pMesh = NULL;
		}
		//�}�e���A���̔j��
		if (m_model[nCnt].pBuffMat != NULL)
		{
			m_model[nCnt].pBuffMat->Release();
			m_model[nCnt].pBuffMat = NULL;
		}
	}
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
	CNumberArray::Create(0, pos, D3DXVECTOR3(10.0f, 10.0f, 0.0f), GET_COLORMANAGER->GetIconColor(pPlayer->m_nColor), pPlayer->m_nColor);

	//�U���p�N���X����
	pPlayer->m_pAttack = CAttack1::Create(pPlayer);

	//�ړ��͈̓N���X�̐���
	pPlayer->m_pActRange = CActRange::Create(pPlayer);

	return pPlayer;
}

//******************************
// ����������
//******************************
HRESULT CPlayer::Init(void)
{
	if (FAILED(CModelHierarchy::Init(m_nPartsNum, &m_model[0], HIERARCHY_TEXT_PATH1)))
	{
		return E_FAIL;
	}

	// �ړ��t���O�̏�����
	m_bMove = true;
	// ���G�t���O�̏�����
	m_bInvincible = false;
	//�v���C���[�X�e�[�^�X������
	m_PlayerState = PLAYER_STATE_NORMAL;
	//�F�ݒ�
	m_color = MODL_COLOR;

	////////////////////////////////////////
	// ��	
	m_nColor = m_nPlayerNumber;
	CColorManager::GetColorManager()->SetUsePlayerNum(m_nPlayerNumber, m_nColor);
	////////////////////////////////////////

	// ���f���̃T�C�Y�̐ݒ�
	SetSize(MODEL_SIZE);

	//CNumberArray::Create(10, GetPos() + D3DXVECTOR3(0.0f, 100.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);	

	//for (int nCntAnim = 0; nCntAnim < MOTION_MAX; nCntAnim++)
	//{
	//	m_apMotion[nCntAnim] = CMotion::Create(GetPartsNum(), m_achAnimPath[nCntAnim], GetModelData());
	//}

	//m_apMotion[MOTION_WALK]->SetActiveMotion(true);


	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);

	// �A�C�e���X�e�[�g
	m_ItemState = ITEM_STATE_NONE;

	m_nMoveframe = MOVE_FRAME;				// �ړ����x
	m_nDashCnt = 1;		//���x�A�b�v�J�E���g
	return S_OK;
}

//******************************
// �I������
//******************************
void CPlayer::Uninit(void)
{
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
	switch (m_PlayerState)
	{
	case PLAYER_STATE_NORMAL:	//�ʏ���
		// �ړ�����
		Move();
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
		break;
	}

	// �e�̏���
	Bullet();

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
			m_pAttack->AttackSwitch(0);
		}
		if (pKey->GetKeyPress(DIK_3))
		{
			m_pAttack->AttackSwitch(1);
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
		for (int nCntMat = 0; nCntMat < GetModelData()[nCntParts].nNumMat; nCntMat++)
		{
			D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()[nCntParts].pBuffMat->GetBufferPointer();
			mat[nCntMat].MatD3D.Ambient = m_color;
			mat[nCntMat].MatD3D.Diffuse = m_color;
			mat[nCntMat].MatD3D.Specular = m_color;
			mat[nCntMat].MatD3D.Emissive = m_color;
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
		D3DXVECTOR2 StickPos = pJoypad->GetStickState(pJoypad->PAD_LEFT_STICK, m_nPlayerNumber);

		if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_PROGRESS])
			|| (StickPos.y > 0.0f && StickPos.x < STICK_DECISION_RANGE && StickPos.x > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_UP, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// �O�i
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, -1);

			m_rotDest.y= D3DXToRadian(ROTDEST_PREVIOUS);
		}
		else if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RECESSION])
			|| (StickPos.y < 0.0f && StickPos.x < STICK_DECISION_RANGE && StickPos.x > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_DOWN, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// ���
			m_Move.z += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, 1);

			m_rotDest.y = D3DXToRadian(ROTDEST_AFTER);
		}
		else if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_LEFT])
			|| (StickPos.x < 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_LEFT, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// ��
			m_Move.x += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(-1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_LEFT);
		}
		else if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RIGHT])
			|| (StickPos.x > 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_RIGHT, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_RIGHT))
		{// �E
			m_Move.x -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_RIGHT);
		}
	}
	else
	{
		// ���W�̎擾
		D3DXVECTOR3 pos = GetPos();

		//�ړ��v�Z
		pos += (m_Move - pos) / (float)(m_nMoveframe - m_MoveCount);

		//�ʒu�ݒ�
		SetPos(pos);

		//�J�E���g�A�b�v
		m_MoveCount++;

		//�J�E���g�����ɒB����
		if (m_MoveCount >= m_nMoveframe)
		{
			//�J�E���g������
			m_MoveCount = 0;
			//�ړ��ł���悤��
			m_bMove = true;
		}

		switch (m_ItemState)
		{
		case ITEM_STATE_NONE:

			//�J�E���g�����ɒB����
			if (m_MoveCount >= m_nMoveframe)
			{
				//�J�E���g������
				m_MoveCount = 0;
				//�ړ��ł���悤��
				m_bMove = true;
			}
			break;
		case ITEM_STATE_DASH:
			//�J�E���g�����ɒB����
			//if (m_MoveCount >= m_nMoveframe / 2)
			//{
			//	//�_�b�V���^�C�����J�E���g
			//	m_nDashCnt++;
			//	//�J�E���g������
			//	m_MoveCount = 0;
			//	//�ړ��ł���悤��
			//	m_bMove = true;
			//}

			//�_�b�V���^�C�����J�E���g
			m_nDashCnt++;

			m_nMoveframe = (int)DASH_MOVE_FRAME;

			if (m_nDashCnt % DASH_FRAME == 0)
			{
				m_nDashCnt = 0;
				m_nMoveframe = MOVE_FRAME;
				m_ItemState = ITEM_STATE_NONE;
			}
			break;
		}
	}
}//******************************
// �e�̏���
//******************************
void CPlayer::Bullet(void)
{
	// �L�[�{�[�h�ƃW���C�p�b�h�̎擾
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CInputJoypad* pJoypad = CManager::GetJoypad();

	// ���W�̎擾
	D3DXVECTOR3 pos = GetPos();

	// �U���{�^������������
	if (pKey->GetKeyTrigger(m_anControllKey[m_nPlayerNumber][KEY_BULLET])
		|| pJoypad->GetButtonState(XINPUT_GAMEPAD_X, pJoypad->BUTTON_TRIGGER, m_nPlayerNumber))
	{
		//// �����w��
		//D3DXVECTOR3 bulletMove;
		//bulletMove.x = cosf(GetRot().y)*-BULLET_MOVE;
		//bulletMove.y = 0.0f;
		//bulletMove.z = sinf(GetRot().y)*BULLET_MOVE;
		//// �e�̐���
		//CBullet::Create(D3DXVECTOR3(pos.x, pos.y, pos.z), bulletMove, m_nPlayerNumber);

		m_pAttack->AttackSwitch(0);
	}

	//�ʒu�ݒ�
	SetPos(pos);
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
		pEffect->SetFloatArray("RimColor", (float*)&GET_COLORMANAGER->GetColorDataByPlayerNumber(m_nColor).iconColor, 4);
		pEffect->SetFloat("RimPower", RIM_POWER);
		// �L���[�u�e�N�X�`��
		pEffect->SetTexture("CubeTex", CResourceTexture::GetCubeTexture(CResourceTexture::TECTURE_CUBE_SLY));
	}
}

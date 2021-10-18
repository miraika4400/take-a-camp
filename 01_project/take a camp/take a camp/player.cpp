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
#include "resource_shader.h"
#include "light.h"
#include "camera_base.h"

//*****************************
// �}�N����`
//*****************************
#define MOVE_DIST (TILE_ONE_SIDE)	// �ړ�����
#define MOVE_FRAME 15				// �ړ����x
#define COLLISION_RADIUS 20.0f
#define MODL_COLOR D3DXCOLOR(0.3f,0.3f,0.3f,1.0f)
#define MODEL_SIZE D3DXVECTOR3( 1.0f, 1.0f, 1.0f)
#define RESPAWN_MAX_COUNT (60*5)	// ���X�|�[���܂ł̍ő�J�E���g
#define INVINCIBLE_COUNT (60*2)		// ���G����
#define ROTDEST_PREVIOUS 270.0f		// �O������
#define ROTDEST_AFTER 90.0f			// �������
#define ROTDEST_LEFT 180.0f			// ������
#define ROTDEST_RIGHT 0.0f			// �E����
#define ROT_SPEED 0.3f				// ��]���x
#define ROT_FACING_01 180			// ��]�̊
#define ROT_FACING_02 360			// ��]����

//*****************************
// �ÓI�����o�ϐ��錾
//*****************************
int CPlayer::m_anControllKey[5][CPlayer::KEY_MAX] =
{
	{ DIK_W,DIK_S,DIK_A,DIK_D,DIK_E },
	{ DIK_UP,DIK_DOWN,DIK_LEFT,DIK_RIGHT,DIK_NUMPAD1 },
	{ DIK_U,DIK_J,DIK_H,DIK_K,DIK_I },
	{ DIK_NUMPAD8,DIK_NUMPAD5,DIK_NUMPAD4,DIK_NUMPAD6,DIK_NUMPAD9 }
};

//******************************
// �R���X�g���N�^
//******************************
CPlayer::CPlayer() :CModel(OBJTYPE_PLAYER)
{
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_nRespawnCount = 0;
	m_nPlayerNumber = 0;
	m_nInvincibleCount = 0;
	m_bMove = false;
	m_bInvincible = false;
	m_PlayerState = PLAYER_STATE_NORMAL;
	m_pCollison = NULL;
	m_nColor = 0;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	memset(&m_RespawnPos, 0, sizeof(D3DXVECTOR3));
	m_MoveCount = 0;
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
	CNumberArray::Create(0, pos, D3DXVECTOR3(10.0f, 10.0f, 0.0f), GET_COLORMANAGER->GetIconColor(pPlayer->m_nColor), pPlayer->m_nColor);


	//�ړ��͈̓N���X�̐���
	pPlayer->m_pActRange = CActRange::Create(pPlayer);

	return pPlayer;
}

//******************************
// ����������
//******************************
HRESULT CPlayer::Init(void)
{
	if (FAILED(CModel::Init()))
	{
		return E_FAIL;
	}

	// ���f�����蓖��
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_PLAYER01));

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
	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);	return S_OK;
}

//******************************
// �I������
//******************************
void CPlayer::Uninit(void)
{
	CModel::Uninit();
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
		if (m_pCollison == NULL)
		{
			m_pCollison = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS / 2);
		}
		else
		{
			m_pCollison->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
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

		/*if (pKey->GetKeyPress(DIK_NUMPAD1))
		{
			m_nColor = 0;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD2))
		{
			m_nColor = 1;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD3))
		{
			m_nColor = 2;
		}
		if (pKey->GetKeyPress(DIK_NUMPAD4))
		{
			m_nColor = 3;
		}
		}*/
	}

#endif // _DEBUG

}

//******************************
// �`�揈��
//******************************
void CPlayer::Draw(void)
{
	// �F�̐ݒ�
	D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()->pBuffMat->GetBufferPointer();
	mat->MatD3D.Ambient = m_color;
	mat->MatD3D.Diffuse = m_color;
	mat->MatD3D.Specular = m_color;
	mat->MatD3D.Emissive = m_color;

	CModel::Draw();
}

//******************************
// ���S����
//******************************
void CPlayer::Death(void)
{
	//���S��ԂɈڍs
	SetState(PLAYER_STATE_DEATH);

	//�����蔻�������
	if (m_pCollison != NULL)
	{
		m_pCollison->Uninit();
		m_pCollison = NULL;
	}
	//�s���N���X�Ɏ��S��ԂɂȂ����t���O�𑗂�
	m_pActRange->SetDeath(true);
	//�����ɂ���
	m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);


}

//******************************
// �ړ�����
//******************************
void CPlayer::Move(void)
{
	if (m_bMove)
	{
		// �L�[�{�[�h�̎擾
		CInputKeyboard * pKey = CManager::GetKeyboard();

		if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_PROGRESS])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// �O�i
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, -1);

			m_rotDest.y= D3DXToRadian(ROTDEST_PREVIOUS);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RECESSION])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// ���
			m_Move.z += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, 1);

			m_rotDest.y = D3DXToRadian(ROTDEST_AFTER);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_LEFT])
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// ��
			m_Move.x += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(-1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_LEFT);
		}
		else if (pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RIGHT])
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
		pos += (m_Move - pos) / (float)(MOVE_FRAME - m_MoveCount);

		//�ʒu�ݒ�
		SetPos(pos);

		//�J�E���g�A�b�v
		m_MoveCount++;

		//�J�E���g�����ɒB����
		if (m_MoveCount >= MOVE_FRAME)
		{
			//�J�E���g������
			m_MoveCount = 0;
			//�ړ��ł���悤��
			m_bMove = true;
		}
	}
}//******************************
// �e�̏���
//******************************
void CPlayer::Bullet(void)
{
	CInputKeyboard * pKey = CManager::GetKeyboard();

	// ���W�̎擾
	D3DXVECTOR3 pos = GetPos();

	// �X�y�[�X�{�^������������
	if (pKey->GetKeyTrigger(m_anControllKey[m_nPlayerNumber][KEY_BULLET]))
	{
		CBullet::Create(D3DXVECTOR3(pos.x, pos.y, pos.z));
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

	D3DMATERIAL9 matDef; //���݂̃}�e���A���ێ��p
	D3DXMATERIAL*pMat;   //�}�e���A���f�[�^�ւ̃|�C���^

	// ���f���f�[�^�̎擾
	CResourceModel::Model * pModelData = GetModelData();

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &pModelData->mtxWorld);

	//���݂̃}�e���A�����擾����
	pDevice->GetMaterial(&matDef);

	// �V�F�[�_�[���̎擾
	CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_PLAYER);
	if (shader.pEffect != NULL)
	{
		// �V�F�[�_�[�v���O�����ɒl�𑗂�
		SetShaderVariable(shader.pEffect, pModelData);
		if (pModelData->pBuffMat != NULL)
		{
			//�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)pModelData->pBuffMat->GetBufferPointer();

			// �p�X���̎擾
			UINT numPass = 0;
			shader.pEffect->Begin(&numPass, 0);

			// �p�X�����`�揈���̃��[�v
			for (int nCntEffect = 0; nCntEffect < (int)numPass; nCntEffect++)
			{
				for (int nCntMat = 0; nCntMat < (int)pModelData->nNumMat; nCntMat++)
				{
					//�}�e���A���̃A���r�G���g�Ƀf�B�t���[�Y�J���[��ݒ�
					pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

					//�}�e���A���̐ݒ�
					pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
					// �e�N�X�`��
					pDevice->SetTexture(0, pModelData->apTexture[nCntMat]);

					// �F�̏��𑗂�
					shader.pEffect->SetFloatArray("DiffuseColor", (float*)&m_color, 4);

					// �V�F�[�_�p�X�̕`��J�n
					shader.pEffect->BeginPass(nCntEffect);
					//���f���p�[�c�̕`��
					pModelData->pMesh->DrawSubset(nCntMat);
					// �V�F�[�_�p�X�̏I��
					shader.pEffect->EndPass();

					pMat[nCntMat] = pModelData->defMat[nCntMat];
				}
			}
			// �V�F�[�_�[�I��
			shader.pEffect->End();
		}
	}
	//�ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
	// �e�N�X�`�����̏�����
	pDevice->SetTexture(0, 0);
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

		
	}
}

//====================================================
//
// jobchange_tile�N���X�̏���[jobchange_tile.cpp]
// Author:�ɓ��@�z��
//
//====================================================

//====================================================
// �C���N���[�h
//====================================================
#include "jobchange_tile.h"
#include "scene3d.h"
#include "resource_texture.h"
#include "tutorial.h"
#include "collision.h"
#include "player.h"
#include "chara_select.h"
#include "fade.h"
#include "chara_select.h"
#include "skill_gauge.h"

//====================================================
// �}�N����`
//====================================================
#define TILE_COLOR	(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))

//====================================================
// �R���X�g���N�^
//====================================================
CJobchangeTile::CJobchangeTile()
{
	m_pCrossPolygon = NULL;
	m_CharacterType = CResourceCharacter::CHARACTER_NONE;
}

//====================================================
// �f�X�g���N�^
//====================================================
CJobchangeTile::~CJobchangeTile()
{
}

//====================================================
// ��������^�C�����Ƃɏ����𕪂���
//====================================================
void CJobchangeTile::CreateKnight(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	Create(pos, CResourceTexture::TEXTURE_SWORD_ICON, CResourceCharacter::CHARACTER_KNIGHT);
}
void CJobchangeTile::CreateLancer(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	Create(pos, CResourceTexture::TEXTURE_LANCE_ICON, CResourceCharacter::CHARACTER_LANCER);
}
void CJobchangeTile::CreateWizard(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	Create(pos, CResourceTexture::TEXTURE_MAGICSTICK_ICON, CResourceCharacter::CHARACTER_WIZARD);
}
void CJobchangeTile::CreateThief(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	Create(pos, CResourceTexture::TEXTURE_KNIFE_ICON, CResourceCharacter::CHARACTER_THIEF);
}
void CJobchangeTile::CreateMagician(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	Create(pos, CResourceTexture::TEXTURE_STICK_ICON, CResourceCharacter::CHARACTER_MAGICIAN);
}
void CJobchangeTile::CreateArcher(D3DXVECTOR3 pos, D3DXCOLOR col)
{
	Create(pos, CResourceTexture::TEXTURE_ARROW_ICON, CResourceCharacter::CHARACTER_ARCHER);
}

//====================================================
// �N���X����
//====================================================
void CJobchangeTile::Create(D3DXVECTOR3 pos, CResourceTexture::TEXTURE_TYPE type, CResourceCharacter::CHARACTER_TYPE Char_type)
{
	// �������̊m��
	CJobchangeTile *pTile;
	pTile = new CJobchangeTile;

	// ������
	pTile->Init();

	// �e�l�̑���E�Z�b�g
	pTile->SetPos(pos);
	pTile->SetPriority(OBJTYPE_TILE); // �I�u�W�F�N�g�^�C�v
	pTile->SetRide(true);			  // �ڂ�Ȃ��悤�Ƀt���O�𗧂Ă�
	pTile->m_CharacterType = Char_type;

	// �~�}�[�N�̐���
	pTile->m_pCrossPolygon = CScene3d::Create(D3DXVECTOR3(pos.x, pos.y + (TILE_SIZE_Y / 2) + 1.0f, pos.z), D3DXVECTOR3(TILE_ONE_SIDE - 2, 0.0f, TILE_ONE_SIDE - 2));
	pTile->m_pCrossPolygon->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	pTile->m_pCrossPolygon->BindTexture(CResourceTexture::GetTexture(type));
	pTile->m_pCrossPolygon->SetPriority(OBJTYPE_MAP);
}

//====================================================
// ����������
//====================================================
HRESULT CJobchangeTile::Init(void)
{
	// �^�C���̏�����
	if (FAILED(CTile::Init()))
	{
		return E_FAIL;
	}

	// �^�C���̐F�̃Z�b�g
	SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));

	return S_OK;
}

//====================================================
// �I������
//====================================================
void CJobchangeTile::Uninit(void)
{
	// �^�C���̏I��
	CTile::Uninit();
}

//====================================================
// �X�V����
//====================================================
void CJobchangeTile::Update(void)
{
	// �^�C���̍X�V
	CTile::Update();

	CTutorial * pTutorial = CManager::GetTutorial();
	if (pTutorial &&
		pTutorial->GetTutorialPhase() == CTutorial::PHASE_FINISH)
	{
		// �^�C���̐F�̃Z�b�g
		SetColor(TILE_COLOR);
		m_pCrossPolygon->SetColor(TILE_COLOR);

		// �v���C���[�̃i���o�[
		int nPlayerNum = 0;

		// ���̃^�C���̓����蔻��
		CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
		while (pPlayer != NULL)
		{
			// ���̃^�C���ɍڂ�����w��̐E��ɕς���
			if (CCollision::CollisionSphere(GetCollision(), pPlayer->GetCollision()))
			{
				// �^�C���ɕێ����Ă���L�����^�C�v�ɃZ�b�g
				pPlayer->SetCharacterType(m_CharacterType);

				// �U���͈͂�ς��邽�߃L�����Z���N�g�̃L�����^�C�v��ς���
				CCharaSelect::Entry_Data EntryData = CCharaSelect::GetEntryData(nPlayerNum);
				EntryData.charaType = m_CharacterType;
				CCharaSelect::SetEntryData(nPlayerNum, EntryData);

				// �U���̏�����
				pPlayer->InitCharacterData();

				// �L�����N�^�[�̃^�C�v���ƂɃe�N�X�`����ς���
				switch (m_CharacterType)
				{
				case CResourceCharacter::CHARACTER_TYPE::CHARACTER_KNIGHT:
					pPlayer->GetSkillgauge()->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
					break;

				case CResourceCharacter::CHARACTER_TYPE::CHARACTER_LANCER:
					pPlayer->GetSkillgauge()->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_LANCE_ICON));
					break;

				case CResourceCharacter::CHARACTER_TYPE::CHARACTER_WIZARD:
					pPlayer->GetSkillgauge()->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_MAGICSTICK_ICON));
					break;

				case CResourceCharacter::CHARACTER_TYPE::CHARACTER_THIEF:
					pPlayer->GetSkillgauge()->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_KNIFE_ICON));
					break;

				case CResourceCharacter::CHARACTER_TYPE::CHARACTER_MAGICIAN:
					pPlayer->GetSkillgauge()->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_STICK_ICON));
					break;

				case CResourceCharacter::CHARACTER_TYPE::CHARACTER_ARCHER:
					pPlayer->GetSkillgauge()->BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ARROW_ICON));
					break;

				default:
					break;
				}
			}
			pPlayer = (CPlayer*)pPlayer->GetNext();
			nPlayerNum++;
		}

		// �`���[�g���A������������
		CTutorial * pTutrial = CManager::GetTutorial();
		if (pTutrial)
		{
			// �t�F�[�Y�����ׂďI�������Ƃ�
			if (pTutrial->GetTutorialPhase() == CTutorial::PHASE_FINISH)
			{
				// �ڂ��悤�ɂ���
				SetRide(false);
			}
		}
	}
}
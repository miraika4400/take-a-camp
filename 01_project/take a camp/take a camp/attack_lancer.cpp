//=============================================================================
//
// �U���͈̓^�C�v�R�m [attack_knight.cpp]
// Author : �V����s
//
//=============================================================================

//=============================================================================
// �w�b�_�t�@�C���̃C���N���[�h
//=============================================================================
#include "attack_lancer.h"
#include "tile.h"
#include "player.h"
#include "attack.h"
#include "skill_effect.h"
#include "skill_circle.h"
#include "color_manager.h"
#include "sound.h"
#include "particle.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CAttackLancer::CAttackLancer()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CAttackLancer::~CAttackLancer()
{
}

//=============================================================================
// ��������
//=============================================================================
CAttackLancer * CAttackLancer::Create(CPlayer* pPlayer)
{
    //�������m��
    CAttackLancer* pAttackLancer = NULL;
    pAttackLancer = new CAttackLancer;

    if (pAttackLancer != NULL)
    {
        pAttackLancer->SetType(CResourceCharacter::CHARACTER_LANCER);
        pAttackLancer->SetPlayer(pPlayer);	// �v���C���[�N���X�擾
        pAttackLancer->Init();				// ����������
    }
    return pAttackLancer;
}

//=============================================================================
// �G�t�F�N�g����
//=============================================================================
void CAttackLancer::CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state)
{
	CPlayer *pPlayer = GetPlayer();
	//�G�t�F�N�g����
	if (state == CAttackBased::ATTACK_STATE_FINALATTACK)
	{
		D3DXVECTOR3 rot = pPlayer->GetRotDest();
		float fAngle = D3DXToDegree(rot.y);
		if ((int)fAngle / 90 % 2 == 0)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);
		}
		else if ((int)fAngle / 90 % 2 == 1 || (int)fAngle / 90 % 2 == -1)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y) + 180.0f, pPlayer, CParticle::PARTICLE_THUKI);
		}
		else
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);
		}
	}
	if (state == CAttackBased::ATTACK_STATE_ATTACK)
	{
		D3DXVECTOR3 rot = pPlayer->GetRotDest();
		float fAngle = D3DXToDegree(rot.y);
		if ((int)fAngle / 90 % 2 == 0)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);

		}
		else if ((int)fAngle / 90 % 2 == 1 || (int)fAngle / 90 % 2 == -1)
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y) + 180.0f, pPlayer, CParticle::PARTICLE_THUKI);
		}
		else
		{
			CParticle::Create(pPlayer->GetPos() + pos + LANCER_EFFECT_POS, THUKI_SKIIL_MOVE, LANCER_EFFECT_SIZE, LANCER_EFFECT_LIFE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), 0.05f, D3DXToDegree(rot.y), pPlayer, CParticle::PARTICLE_THUKI);

		}
	}

}

//=============================================================================
// SE�Đ�
// Author:�����D�I
//=============================================================================
void CAttackLancer::PlaySE(void)
{
    // �T�E���h���̎擾
    CSound *pSound = CManager::GetSound();

    // ���x�����̎擾
    int nLevel = GetLevel();

    // �ʏ�U���Ȃ�
    if (nLevel < MAX_LEVEL)
    {
        // SE�Đ�
        pSound->Play(CSound::LABEL_SE_YARI_ATTACK);
    }
    //�@�K�E�Ȃ�
    else
    {
        // SE�Đ�
        pSound->Play(CSound::LABEL_SE_YARI_FINALATTACK);
    }
}
//=============================================================================
//
// effect_explosion�w�b�_ [effect_explosion.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _EFFECT_EXPLOSION_H_
#define _EFFECT_EXPLOSION_H_

//*****************************
// �C���N���[�h
//*****************************
#include "scene.h"
#include "resource_map.h"
#include "stage_select.h"

//*****************************
// �O���錾
//*****************************
class CScene2d;

//=============================
// �}�N����`
//=============================
#define EFFECT_EXPLOSION_TEX_NUM 1
#define EFFECT_EXPLOSION_DEFAULT_SIZE D3DXVECTOR3(700.0f,700.0f,0.0f)
//*****************************
//�N���X��`
//*****************************

//�Q�[�W�N���X
class CResultExplosion : public CScene
{
public:

	//============
	// �����o�֐�
	//============
	CResultExplosion();
	~CResultExplosion();

	// static
	static CResultExplosion *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size = EFFECT_EXPLOSION_DEFAULT_SIZE); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	// �����o�ϐ�
	CScene2d * m_apPolygon[EFFECT_EXPLOSION_TEX_NUM]; // ���O�|���S��
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_size;
	bool m_bReCreate;
	int m_nCntAnim; // �e�N�X�`���A�j���[�V�����J�E���g
	int m_nTexU;    // �e�N�X�`������U

};

#endif
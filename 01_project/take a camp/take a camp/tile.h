//=============================================================================
//
// tile�w�b�_ [tile.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TILE_H_
#define _TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "model.h"
#include "color_manager.h"

//*****************************
//�O���錾
//*****************************
class CCollision;
class CScene3d;
class CBullet;
class CPlayer;
class CPeintCollision;
class CAttackArea;

//*****************************
//�}�N����`
//*****************************
#define TILE_ONE_SIDE		(20.0f)			// �^�C���̃T�C�Y*���
#define TILE_SIZE_Y			(TILE_ONE_SIDE/2)
#define TILE_SIZE			(D3DXVECTOR3(TILE_ONE_SIDE,TILE_SIZE_Y,TILE_ONE_SIDE))  // �^�C���̃T�C�Y
#define MAX_TILE_COLOR_NUM	(16)
#define TILE_DEFAULT_COLOR	(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
#define TILE_POS_Y			(-TILE_SIZE_Y/2)

//*****************************
// �N���X��`
//*****************************

// �^�C���N���X
class CTile : public CModel
{
public:

	// �֐��|�C���^
	typedef void(*CTile::SENTENCE_FUNC)(D3DXVECTOR3, D3DXCOLOR);

	//�����o�֐�
	CTile();
	~CTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static CTile*GetHitTile(D3DXVECTOR3 pos);

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	//�Z�b�g�E�擾
	// �F
	void SetColor(D3DXCOLOR col) { m_color = col; }
	D3DXCOLOR GetColor(void) { return m_color; }
	// Y���W�̖ڕW�l
	void SetDistPosY(float fDistY) { m_fDistPosY = fDistY; }
	float GetDistPosY(void) { return m_fDistPosY; }
	// Y���W�̌W��
	void SetDistPosYRate(float fDistYRate) { m_fDistPosYRate = fDistYRate; }
	float GetDistPosYRate(void) { return m_fDistPosYRate; }
	// �R���W�����̎擾
	CCollision*GetCollision(void) { return m_pCollison; }
	static void CreateSentence0() { return ; }
	// �q�b�g�t���O
	bool GetHitPlayerFlag(void) { return m_bHitPlayer; }
	bool GetHitBulletFlag(void) { return m_bHitBullet; }
	// �^�C�����X�g�̎擾
	static std::vector<CTile*>GetTileList(void) { return m_aTileList; }
	// �^�C�����X�g�̃N���A
	static void ResetTileList(void) { m_aTileList.clear(); }
	// �^�C�����g���邩�̃t���O�擾
	void SetRide(bool bRide) { m_bRide = bRide; }
	bool GetRide(void) { return m_bRide; }

private:
	void DrawModel(void);
	void SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData); // �V�F�[�_�ɒl�𑗂�

	bool CollisionPlayer(void);								// �v���C���[�Ƃ̓����蔻��
	virtual void HitPlayerAction(CPlayer * pPlayer);        // �e�Ɠ��������Ƃ��̃A�N�V����*�v���X
	virtual void HitPlayerActionTrigger(CPlayer * pPlayer); // �e�Ɠ��������Ƃ��̃A�N�V����*�g���K�[
	bool CollisionBullet(void);								// �e�Ƃ̓����蔻��
	virtual void HitBulletAction(CBullet * pBullet);		// �e�Ɠ��������Ƃ��̃A�N�V����
	bool CollisionPeint(void);								// �h�蔻��ɓ���������
	virtual void HItPeint(CPeintCollision * pPeint);		// �h�蔻��Ɠ����������̃A�N�V����

	// �����o�ϐ�
	static std::vector<CTile*> m_aTileList;
	D3DXCOLOR m_color;			// �J���[
	CCollision * m_pCollison;	// �����蔻��
	float m_fDistPosY;			// ���WY�̖ڕW�l
	float m_fDistPosYRate;		// ���WY�̕ύX���̌W��
	bool m_bHitOld;				// ��O�̃t���[���œ������Ă������ۑ�����悤
	bool m_bHitPlayer;			// �v���C���[���������Ă���t���O
	bool m_bHitBullet;			// �e���������Ă���t���O
	bool m_bRide;				// ��ꂩ�̃t���O
};



#endif
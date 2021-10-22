//=============================================================================
//
// needle_tile�w�b�_ [needle_tile.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _NEEDLE_TILE_H_
#define _NEEDLE_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "color_tile.h"

//*****************************
//�O���錾
//*****************************
class CModel;

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************

// �Ƃ��^�C���N���X
class CNeedleTile : public CColorTile
{
public:
	//�����o�֐�
	CNeedleTile();
	~CNeedleTile();

	static CNeedleTile *Create(D3DXVECTOR3 pos);
	void Update(void);
private:
	void HitPlayerAction(CPlayer*pPlayer);
	void ManageNeedle(void); // �Ƃ��̊Ǘ�
	// �����o�ϐ�
	CModel *m_pNeedleModel;        // �}�[�N
	int m_nCntHit;                 // hit���Ă���t���[�����̃J�E���g
	bool m_bUp;                    // �Ƃ����グ��
	int m_nUpCnt;                  // �オ���Ă���Ԃ̃J�E���g
	CScene3d *m_pHole;             // ��
};

#endif
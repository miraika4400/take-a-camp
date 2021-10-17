//=============================================================================
//
// color_tile�w�b�_ [color_tile.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _COLOR_TILE_H_
#define _COLOR_TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "tile.h"

//*****************************
//�O���錾
//*****************************
class CCollision;
class CScene3d;

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************

// �F�t���^�C���N���X
class CColorTile : public CTile
{
public:
	//�����o�֐�
	CColorTile();
	~CColorTile();

	static CColorTile *Create(D3DXVECTOR3 pos);
	static void CountColorTile(void); // �^�C���̐����̐��𐔂���


	static int GetTileNum(int nIndex) { return m_anTileNum[nIndex][0]; } // ����J���[�̃^�C����
	static int GetTileNum(int nIndex, int nStep) { return m_anTileNum[nIndex][nStep]; } // ����J���[�̓���i�K�̃^�C����

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	int GetPeintNum(void) { return m_nPrevNum; } // �h���Ă���F�̎擾
	int GetStepNum(void) { return m_nStep; }     // �X�e�b�v�̎擾

	void ResetTile(void);

private:
	void CollisionPlayer(void);    // �v���C���[�Ƃ̓����蔻��
	void ManageFrame(void);        // �A�C�R���Ǘ�
	void Peint(int nColorNumber, int nPlayerNum); // �h����

	// �����o�ϐ�
	static int m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1];
	CCollision * m_pCollison; // �����蔻��
	CScene3d *m_pFrame;        // �g
	int m_nPrevNum;           // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	int m_nStep;              // ���̓h�i�K
	int m_nCntStep;           // �ēx�h��\�J�E���g
	int m_nLastHitPlayerNum;  // �Ō�ɓ��������v���C���[�ԍ�
	bool m_bHitOld;           // ��O�̃t���[���œ������Ă������ۑ�����悤
};

#endif
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

//*****************************
//�}�N����`
//*****************************
#define TILE_ONE_SIDE 20.0f			// �^�C���̃T�C�Y*���
#define TILE_SIZE_Y TILE_ONE_SIDE/2
#define TILE_SIZE D3DXVECTOR3(TILE_ONE_SIDE,TILE_SIZE_Y,TILE_ONE_SIDE)  // �^�C���̃T�C�Y
#define MAX_TILE_COLOR_NUM 16

//*****************************
// �N���X��`
//*****************************

// �^�C���N���X
class CTile : public CModel
{
public:
	//�����o�֐�
	CTile();
	~CTile();

	static CTile *Create(D3DXVECTOR3 pos);
	static void CountColorTile(void); // �^�C���̐����̐��𐔂���
	static int GetTileNum(int nIndex) { return m_anTileNum[nIndex][0]; } // ����J���[�̃^�C����
	static int GetTileNum(int nIndex, int nStep) { return m_anTileNum[nIndex][nStep]; } // ����J���[�̓���i�K�̃^�C����
	
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetPeintNum(void) { return m_nPrevNum; } // �h���Ă���F�̎擾
	int GetStepNum(void) { return m_nStep; }     // �X�e�b�v�̎擾

	void ResetTile(void);
private:
	void CollisionPlayer(void);   // �v���C���[�Ƃ̓����蔻��
	void ManageFrame(void);        // �A�C�R���Ǘ�
	void Peint(int nColorNumber, int nPlayerNum); // �h����

	// �����o�ϐ�
	static int m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM +1];
	CCollision * m_pCollison; // �����蔻��
	D3DXCOLOR m_color;        // �J���[
	CScene3d *m_pFrame;        // �g
	int m_nPrevNum;           // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	int m_nStep;              // ���̓h�i�K
	int m_nCntStep;           // �ēx�h��\�J�E���g
	int m_nLastHitPlayerNum;  // �Ō�ɓ��������v���C���[�ԍ�
	bool m_bHitOld;           // ��O�̃t���[���œ������Ă������ۑ�����悤
};

#endif
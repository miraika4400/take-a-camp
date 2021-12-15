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
class CPaintTime;
class CTileEffectCharge;
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

	// �X�e�[�g
	typedef enum
	{
		COLOR_TILE_NORMAL = 0,	//�ʏ���
		COLOR_TILE_CHARGE		//�`���[�W���
	}COLOR_TILE_STATE;


	//�����o�֐�
	CColorTile();
	~CColorTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CountColorTile(void); // �^�C���̐����̐��𐔂���

	static int GetTileNum(int nIndex) { return m_anTileNum[nIndex][0]; } // ����J���[�̃^�C����
	static int GetTileNum(int nIndex, int nStep) { return m_anTileNum[nIndex][nStep]; } // ����J���[�̓���i�K�̃^�C����

	static CColorTile*GetHitColorTile(D3DXVECTOR3 pos); // �w����W�ƂԂ����Ă���^�C���̎擾����

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	int GetPeintNum(void) { return m_nPrevNum; } // �h���Ă���F�̎擾
	int GetStepNum(void) { return m_nStep; }     // �X�e�b�v�̎擾
	int GetLasthitPlayerNum(void) { return m_nLastHitPlayerNum; }
	COLOR_TILE_STATE GetColorTileState(void) { return m_ColorTileState; }	//�X�e�[�g�Q�b�^�[
	void			 SetColorTileState(COLOR_TILE_STATE ColorTileState) { m_ColorTileState = ColorTileState; }
	void ResetTile(void);		// �^�C���̃��Z�b�g
	void ColorDown(int nCount);	// �^�C���̓h��i�K����

	void Peint(int nColorNumber, int nPlayerNum); // �h����
	
	bool ChargeFlag(int nPlayerNum);	// �`���[�W�t���O����
	CScene3d *GetFrame(void) { return m_pFrame; }
private:
	void HitPlayerActionTrigger(CPlayer * pPlayer);  // �e�Ɠ��������Ƃ��̃A�N�V����*�g���K�[
	void HItPeint(CPeintCollision * pPeint);		 // �h�蔻��Ɠ����������̃A�N�V����
	void ManageEffect(void);			// �G�t�F�N�g�ނ̊Ǘ�
	void ManageColor(void);			// �F�̊Ǘ�

	// �����o�ϐ�
	static int m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1];
	COLOR_TILE_STATE m_ColorTileState;	//�^�C���̃X�e�[�g
	D3DXCOLOR m_distColor;    // �ڕW�J���[
	D3DXCOLOR m_oldColor;     // �F�ړ����̈ړ��O�̃J���[
	CScene3d *m_pFrame;       // �g
	CPaintTime * m_pPaintTime;// �ēx�h��\����
	CTileEffectCharge*m_pCharge; // �`���[�W�G�t�F�N�g
	int m_nPrevNum;           // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	int m_nStep;              // ���̓h�i�K
	int m_nCntStep;           // �ēx�h��\�J�E���g
	int m_nLastHitPlayerNum;  // �Ō�ɓ��������v���C���[�ԍ�
	int	m_nCntFrem;			  // �C���^�[�o���p�J�E���g
	int m_nBlinking;          // �_�Ŏ��̃J�E���g
	bool m_bBlinkingColor;    // �_�ł̃J���[�t���O
};

#endif
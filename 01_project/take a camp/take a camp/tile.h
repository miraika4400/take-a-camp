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

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	void CollisionPlayer(void);   // �v���C���[�Ƃ̓����蔻��
	void ManageFrame(void);        // �A�C�R���Ǘ�
	void Peint(int nColorNumber, int nPlayerNum); // �h����

	// �����o�ϐ�
	CCollision * m_pCollison; // �����蔻��
	D3DXCOLOR m_color;        // �J���[
	CScene3d *m_pFrame;        // �A�C�R��
	int m_nPrevNum;           // ���h���Ă���J���[�̔ԍ�*�f�t�H���g��-1
	int m_nStep;              // ���̓h�i�K
	int m_nCntStep;           // �ēx�h��\�J�E���g
	int m_nLastHitPlayerNum;  // �Ō�ɓ��������v���C���[�ԍ�
	bool m_bHitOld;           // ��O�̃t���[���œ������Ă������ۑ�����悤
};

#endif
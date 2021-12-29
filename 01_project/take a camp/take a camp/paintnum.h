//=============================================================================
//
// �h��������UI [paintnum.h]
// Author : �ɓ��z��
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _PAINTNUM_H_
#define _PAINTNUM_H_

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "main.h"
#include "scene.h"

//==================================
// �}�N����`
//==================================
#define SUBTRACT_GAUGE_SIZE (D3DXVECTOR3(40.0f, 10.0f, 0.0f))	// �Q�[�W��g�Ɏ��߂邽�߂̔������p

//=============================================================================
// �N���X��`
//=============================================================================
class CPolygon;

// �h��������UI�N���X
class CPaintnum : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CPaintnum();
	~CPaintnum();
	static CPaintnum *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);	// �I��
	void Update(void);	// �X�V
	void Draw(void);	// �`��

	//============
	// �Q�b�^�[
	//============
	int GetRank(int nPlayer) { return m_nRank[nPlayer]; } // �v���C���[�̏��ʊl������
private:
	//============
	// �F���Ƃ̏��
	//============
	struct PaintInfo
	{
		D3DXVECTOR3 pos;	// ���W
		D3DXVECTOR3 size;	// �傫��
		D3DXCOLOR col;		// �F
	};

	//============
	// �����o�֐�
	//============
	float ShiftSize(int nCount); // ���炷�傫���̌v�Z
	void PlayerRank(void);       // �v���C���[���Ƃ̏���
	void SetPolygonPos(int nCount); // �|���S���̍��W�̃Z�b�g

	//============
	// �����o�ϐ�
	//============
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	// ���_�o�b�t�@�ւ̃|�C���^
	CPolygon * m_apPolygon[MAX_PLAYER];	// �F�̊������킩��₷������|���S��
	CPolygon * m_pColorGauge;			// �Q�[�W�̘g�`��p�̃|���S��
	D3DXVECTOR3 m_pos;					// ���W
	D3DXVECTOR3 m_size;					// �傫��
	PaintInfo m_PaintInfo[MAX_PLAYER];	// �v���C���[���Ƃ̓h����
	int m_nRank[MAX_PLAYER];			// �v���C���[�̏���
	float m_fChangeSize[MAX_PLAYER];	// ���X�ɕς��Ă����傫��
};

#endif
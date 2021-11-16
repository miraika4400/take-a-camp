//=============================================================================
//
// paint_time�w�b�_ [paint_time.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _PAINT_TIME_H_
#define _PAINT_TIME_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene3d.h"

//*****************************
//�}�N����`
//*****************************
#define PAINT_TIME_POLYGON_NUM 2 //�g���|���̐�

//*****************************
//�O���錾
//*****************************
class CScene3d;

//*****************************
//�N���X��`
//*****************************

// �ēh�\���Ԃ̉���
class CPaintTime : public CScene
{
public:
	// ��
	// �p�[�c
	typedef enum
	{
		PARTS_FRAME = 0, // �g
		PARTS_HANDS,     // �j
		PARTSMAX
	}PARTS;

	// �����o�֐�
	CPaintTime();
	~CPaintTime();
	static CPaintTime *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetPos(D3DXVECTOR3 pos);
	void SetPaintTime(int nFrame);

	bool GetDrawFlag(void) { return m_bDraw; }
	void SetDrawFlag(bool bFlag);
private:
	// �����o�ϐ�
	bool m_bDraw;// �`��t���O
	CScene3d* m_apPolygon[PAINT_TIME_POLYGON_NUM];
	int m_nFrame; // �t���[����
	int m_nCntFrame;
	float m_fAlpha; // �A���t�@�l
};


#endif
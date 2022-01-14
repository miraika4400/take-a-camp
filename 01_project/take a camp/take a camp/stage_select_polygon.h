//=============================================================================
//
// stage_select_polygon�w�b�_ [stage_select_polygon.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _STAGE_SELECT_POLYGON_H_
#define _STAGE_SELECT_POLYGON_H_

//*****************************
// �C���N���[�h
//*****************************
#include "scene.h"

//*****************************
// �O���錾
//*****************************
class CScene2d;

//=============================
// �}�N����`
//=============================
#define STAGE_SELECT_POLYGON_NUM 3
#define WEIGHT_MUN  8	   // �d�݂��v�Z�����

//*****************************
//�N���X��`
//*****************************

//�Q�[�W�N���X
class CStageSelectPolygon : public CScene
{
public:

	//============
	// �����o�֐�
	//============
	CStageSelectPolygon();
	~CStageSelectPolygon();

	// static
	static CStageSelectPolygon *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	void DrawBlur(void);
	void UpdateWeight(float fDispersion);
	// �����o�ϐ�
	CScene2d * m_apPolygon[STAGE_SELECT_POLYGON_NUM]; // ���O�|���S��
	D3DXHANDLE	m_weightHandle;	// �d�݂̔z��V�F�[�_�[�ɑ���悤
	float		m_afWeight[WEIGHT_MUN];// �d�݂̔z��
};

#endif
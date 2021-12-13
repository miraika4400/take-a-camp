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
class CDynamicTexture;

//=============================
// �}�N����`
//=============================
#define STAGE_SELECT_POLYGON_NUM 2

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
	// �����o�ϐ�
	const static std::vector<int> m_anDrawObjNum;         // �`�悷��I�u�W�F�N�g�ԍ�
	CScene2d * m_apPolygon[STAGE_SELECT_POLYGON_NUM]; // ���O�|���S��
	CDynamicTexture *m_pDynamicTex; // ���I�e�N�X�`��
};

#endif
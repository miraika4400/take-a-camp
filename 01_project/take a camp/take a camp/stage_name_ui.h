//=============================================================================
//
// stage_name_ui�w�b�_ [stage_name_ui.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _STAGE_NAME_UI_H_
#define _STAGE_NAME_UI_H_

//*****************************
// �C���N���[�h
//*****************************
#include "scene.h"
#include "resource_map.h"
#include "stage_select.h"

//*****************************
// �O���錾
//*****************************
class CScene2d;

//=============================
// �}�N����`
//=============================

//*****************************
//�N���X��`
//*****************************

//�Q�[�W�N���X
class CStageNameUi : public CScene
{
public:

	//============
	// �����o�֐�
	//============
	CStageNameUi();
	~CStageNameUi();

	// static
	static CStageNameUi *Create(int nSelectNum = 0); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	void SetSelectNum(int nNum) { m_nSelectNum = nNum; } // �Z���N�g�ԍ��̃Z�b�g
private:
	// �����o�ϐ�
	CScene2d * m_apNamePolygon[SELECT_STAGE_NUM]; // ���O�|���S��
	int m_nSelectNum; // �I��ł���X�e�[�W�i���o�[
};

#endif
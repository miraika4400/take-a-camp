//=============================================================================
//
// stage_slect�w�b�_ [stage_slect.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

//*****************************
// �C���N���[�h
//*****************************
#include "scene.h"
#include "resource_map.h"

//*****************************
// �O���錾
//*****************************
class CStageNameUi;

//*****************************
// �}�N����`
//*****************************
#define SELECT_STAGE_NUM (CMapManager::MAP_TYPE_MAX - 1)

//*****************************
//�N���X��`
//*****************************

//�X�e�[�W�Z���N�g�N���X
class CStageSelect : public CScene
{
public:
	//*****************************
	// �����o�֐�
	//*****************************
	CStageSelect();
	~CStageSelect();

	static CStageSelect *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	void SetObject(void);  // �I�u�W�F�N�g�̐ݒu
	void SelectStageType(void);// �X�e�[�W�^�C�v�̑I������

	// �����o�ϐ�
	static CMapManager::MAP_TYPE m_selectStageType; // �I�����Ă���X�e�[�W�̃^�C�v
	CStageNameUi* m_pStageName;                      // �X�e�[�W���N���X
	int m_nWaitCnt;
};

#endif
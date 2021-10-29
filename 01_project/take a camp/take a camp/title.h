//=============================================================================
//
// title�w�b�_ [title.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TITLE_H_
#define _TITLE_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"
#include "map.h"

//=============================
// �O���錾
//=============================
class CPolygon;
class CMapManager;
class CButton_Title;
//*****************************
//�N���X��`
//*****************************

//�^�C�g���N���X
class CTitle : public CScene
{
public:
	//============
	// �����o�֐�
	//============
	CTitle();
	~CTitle();

	static CTitle *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	//============
	// �����o�ϐ�
	//============
	CPolygon *m_pPolygon;					// �|���S��
	static CMap *m_pMap;					// �X�e�[�W�̃|�C���^
	static CMapManager::MAP_TYPE m_MapType;	// �}�b�v�̃^�C�v
	static CButton_Title *m_pButton;		// �{�^���̃|�C���^
};

#endif
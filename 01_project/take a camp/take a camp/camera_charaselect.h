//=============================================================================
//
// camera_charaselect�w�b�_ [camera_charaselect.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _CAMERA_CHARA_SELECT_H_
#define _CAMERA_CHARA_SELECT_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "camera_base.h"

//*****************************
// �N���X��`
//*****************************

// �O�l�̃J�����N���X
class CCharaSelectCamera : public CCamera
{
public:
	//============
	// �����o�֐�
	//============
	CCharaSelectCamera();
	~CCharaSelectCamera();

	// static
	static CCharaSelectCamera *Create(void);  // �N���X����

	HRESULT Init(void);   // ������
	void SetCamera(void);

private:
};

#endif
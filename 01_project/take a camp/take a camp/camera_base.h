//=============================================================================
//
// camera�w�b�_ [camera.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _CAMERA_H_
#define _CAMERA_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "scene2d.h"

//*****************************
// �}�N����`
//*****************************
#define CAMERA_VIEW_MAX 100000.0f                           // �J�����̕`�拗��(��)
#define CAMERA_VIEW_MIN 10.0f                                // �J�����̕`�拗��(��)

//*****************************
// �N���X��`
//*****************************

//�J�����N���X
class CCamera
{
public:
	//============
	// �����o�֐�
	//============
	CCamera();
	~CCamera();

	// static
	static CCamera *Create(void);  // �N���X����

	virtual HRESULT Init(void);   // ������
	virtual void Uninit(void);	  // �I��
	virtual void Update(void);	  // �X�V
	virtual void SetCamera(void); // �J�����̃Z�b�g

	// �擾
	D3DXMATRIX *GetViewMtx(void) { return &m_mtxView; }              // �r���[�}�g���b�N�X�̎擾
	D3DXMATRIX *GetProjectionMtx(void) { return &m_mtxProjection; }  // �v���W�F�N�V�����}�g���b�N�X�̎擾

	float GetFov(void) { return m_fFov; }
	void SetFov(float fFov) { m_fFov = fFov; } // ����p�̃Z�b�g

	D3DXVECTOR3 GetPosV(void) { return m_posV; }
	void SetPosV(D3DXVECTOR3 posV) { m_posV = posV; }
	D3DXVECTOR3 GetPosR(void) { return m_posR; }
	void SetPosR(D3DXVECTOR3 posR) { m_posR = posR; }
	D3DXVECTOR3 GetVecU(void) { return m_vecU; }
	void SetVecU(D3DXVECTOR3 vecU) { m_vecU = vecU; }
private:
	//============
	// �����o�ϐ�
	//============
	D3DXVECTOR3 m_posV;          // �J�����̍��W
	D3DXVECTOR3 m_posR;          // �����_
	D3DXVECTOR3 m_vecU;          // ������x�N�g��
	D3DXMATRIX  m_mtxProjection; // �v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX  m_mtxView;       // �r���[�}�g���b�N�X
	float m_fFov;                // ����p
};

#endif
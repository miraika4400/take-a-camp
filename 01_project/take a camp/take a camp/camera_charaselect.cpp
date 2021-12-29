////////////////////////////////////////////////////
//
//    �J�����N���X�̏���[camera.cpp]
//    Author:���V ����
//
////////////////////////////////////////////////////

//******************************
// �C���N���[�h
//******************************
#include "camera_charaselect.h"
#include "manager.h"
#include "renderer.h"
#include "character_polygon.h"

//******************************
// �}�N����`
//******************************
#define CAMERA_POS   D3DXVECTOR3(0.0f,0.0f,25.0f)
#define CAMERA_POS_R D3DXVECTOR3(0.0f,0.0f,0.0f) 

//******************************
// �ÓI�����o�ϐ��錾
//******************************

//******************************
// �R���X�g���N�^
//******************************
CCharaSelectCamera::CCharaSelectCamera()
{

}

//******************************
// �f�X�g���N�^
//******************************
CCharaSelectCamera::~CCharaSelectCamera()
{
}

//******************************
// �N���G�C�g
//******************************
CCharaSelectCamera * CCharaSelectCamera::Create(void)
{
	CCharaSelectCamera * pCamera = new CCharaSelectCamera;
	pCamera->Init();

	return pCamera;
}

//******************************
// ����������
//******************************
HRESULT CCharaSelectCamera::Init(void)
{
	// �J�����N���X�̏�����
	CCamera::Init();
	// ���W�̏�����
	SetPosV(CAMERA_POS);
	// �����_�̏�����
	SetPosR(CAMERA_POS_R);

	return S_OK;
}

//******************************
// �J�����Z�b�g
//******************************
void CCharaSelectCamera::SetCamera(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	D3DXMATRIXA16 matWorld;
	D3DXMATRIX *mtxView = GetViewMtx();
	D3DXMATRIX *mtxProjection = GetProjectionMtx();
	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(mtxView);
	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(mtxView, &GetPosV(), &GetPosR(), &GetVecU());
	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, mtxView);

	//�v���W�F�N�g�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(mtxProjection);

	D3DXMatrixPerspectiveFovLH(mtxProjection,
		GetFov(), (float)DEFAULT_CHARACTER_POLYGON_SIZE.x / (float)DEFAULT_CHARACTER_POLYGON_SIZE.y, CAMERA_VIEW_MIN, CAMERA_VIEW_MAX);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, mtxProjection);
}

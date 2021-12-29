//=============================================================================
//
// stage_tecture�w�b�_ [stage_tecture.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _STAGE_TEXTURE_H_
#define _STAGE_TEXTURE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "dynamic_texture.h"

//*****************************
// �N���X��`
//*****************************

//�X�e�[�W�N���X
class CStageTexture : public CDynamicTexture
{

	//============
	// �����o�֐�
	//============
private:
	CStageTexture(); // �B���R���X�g���N�^
public:
	~CStageTexture();

	// static
	static CStageTexture *Create(D3DXVECTOR2 size);  // �N���X����
	static void Release(void);

	void DrawStageInTex(void);
	static CStageTexture*GetStateTexturePointa(void) { return m_pInstance; }
	
private:
	// �����o�ϐ�
	const static std::vector<int> m_anDrawObjNum;         // �`�悷��I�u�W�F�N�g�ԍ�
	static CStageTexture*m_pInstance;

};

#endif
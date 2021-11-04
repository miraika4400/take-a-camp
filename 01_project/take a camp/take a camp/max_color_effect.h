//=============================================================================
//
// max_color_effect�w�b�_ [max_color_effect.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _MAX_EFFECT_COLOR_H_
#define _MAX_EFFECT_COLOR_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene.h"

//*****************************
// �O���錾
//*****************************
class CScene3d;

//*****************************
//�}�N����`
//*****************************
#define MAX_COLOR_EFFECT_POLYGON_NUM 4 // �G�t�F�N�g�Ɏg���^�C���̐�

//*****************************
//�N���X��`
//*****************************

// �h�i�K�ő厞�̃G�t�F�N�g�N���X
class CMaxColorEffect : public CScene
{
public:
	//*****************************
	// �񋓒�`
	//*****************************

	//*****************************
	// �\���̒�`
	//*****************************

	//*****************************
	// �����o�֐�
	//*****************************
	CMaxColorEffect();
	~CMaxColorEffect();

	static CMaxColorEffect *Create(D3DXVECTOR3 pos, D3DXCOLOR col); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	CScene3d *m_apPolygon[MAX_COLOR_EFFECT_POLYGON_NUM]; // �|���S��
	D3DXCOLOR m_polygonColor; // �|���S���J���[
	D3DXVECTOR3 m_pos;        // ���W
	int m_nCntLife;           // �����J�E���g
	float m_fTexV;            // �e�N�X�`��V���W
};

#endif
//=============================================================================
//
// tile_effect_charge�w�b�_ [tile_effect_charge.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TILE_EFFECT_H_
#define _TILE_EFFECT_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene.h"

//*****************************
//�N���X��`
//*****************************

//�U���͈͂̉���
class CTileEffect : public CScene
{
public:
	// �����o�֐�
	CTileEffect();
	~CTileEffect();

	HRESULT Init(void);
	void Uninit(void);
	virtual void Update(void);
	void Draw(void) = 0;

	bool GetDrawFlag(void) { return m_bDraw; }
	void SetDrawFlag(bool bFlag) { m_bDraw = bFlag; }

	float GetAlpha(void) { return m_fAlpha; }
private:
	// �����o�ϐ�
	bool m_bDraw;
	float m_fAlpha;
};


#endif
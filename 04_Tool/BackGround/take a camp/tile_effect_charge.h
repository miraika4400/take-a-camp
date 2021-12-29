//=============================================================================
//
// tile_effect_charge�w�b�_ [tile_effect_charge.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TILE_EFFECT_CHARGE_H_
#define _TILE_EFFECT_CHARGE_H_

//*****************************
//�C���N���[�h
//*****************************
#include "tile_effect.h"

//*****************************
//�O���錾
//*****************************
class CScene3d;

//*****************************
//�N���X��`
//*****************************

//�U���͈͂̉���
class CTileEffectCharge : public CTileEffect
{
public:
	// �����o�֐�
	CTileEffectCharge();
	~CTileEffectCharge();
	static CTileEffectCharge *Create(void);
	HRESULT Init(void);
	void Update(void);
	void Uninit(void);
	void Draw(void);

	void SetPos(D3DXVECTOR3 pos);
private:
	CScene3d* m_pPolygon;
};


#endif
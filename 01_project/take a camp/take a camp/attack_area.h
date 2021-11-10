//=============================================================================
//
// attack_area�w�b�_ [attack_area.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _ATTACK_AREA_H_
#define _ATTACK_AREA_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene3d.h"

//*****************************
//�N���X��`
//*****************************

//�U���͈͂̉���
class CAttackArea : public CScene3d
{
public:
	// �����o�֐�
	CAttackArea();
	~CAttackArea();
	static CAttackArea *Create(D3DXVECTOR3 pos);
	HRESULT Init(void);
	void Draw(void);

	bool GetDrawFlag(void) { return m_bDraw; }
	void SetDrawFlag(bool bFlag) { m_bDraw = bFlag; }
private:
	// �����o�ϐ�
	bool m_bDraw;// �`��t���O
};


#endif
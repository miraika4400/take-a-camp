//=============================================================================
//
// �s���͈̓w�b�_ [act_range.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _ACT_RAGE_H_
#define _ACT_RAGE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
// �O���錾
//*****************************
class CPlayer;

//*****************************
// �N���X��`
//*****************************
// �s���͈̓N���X
class CActRange : public CScene
{
public:
	//�����o�֐�
	CActRange();
	~CActRange();
	static CActRange *Create(CPlayer* pPlayer);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	D3DXVECTOR3		m_size;
};

#endif
//=============================================================================
//
// tile�w�b�_ [tile.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TILE_H_
#define _TILE_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"
#include "model.h"

//*****************************
// �N���X��`
//*****************************

// �^�C���N���X
class CTile : public CModel
{
public:
	//�����o�֐�
	CTile();
	~CTile();
	static CTile *Create(D3DXVECTOR3 pos);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:

	// �����o�ϐ�

};

#endif
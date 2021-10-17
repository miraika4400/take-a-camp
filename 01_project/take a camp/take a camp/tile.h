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
#include "color_manager.h"
//*****************************
//�O���錾
//*****************************
class CCollision;
class CScene3d;

//*****************************
//�}�N����`
//*****************************
#define TILE_ONE_SIDE 20.0f			// �^�C���̃T�C�Y*���
#define TILE_SIZE_Y TILE_ONE_SIDE/2
#define TILE_SIZE D3DXVECTOR3(TILE_ONE_SIDE,TILE_SIZE_Y,TILE_ONE_SIDE)  // �^�C���̃T�C�Y
#define MAX_TILE_COLOR_NUM 16
#define TILE_DEFAULT_COLOR D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)

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
	virtual void Update(void);
	virtual void Draw(void);

	// �F�̃Z�b�g/�擾
	void SetColor(D3DXCOLOR col) { m_color = col; }
	D3DXCOLOR GetColor(void) { return m_color; }

private:

	// �����o�ϐ�
	D3DXCOLOR m_color;        // �J���[
};

#endif
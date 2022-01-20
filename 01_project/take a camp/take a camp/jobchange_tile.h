//====================================================
//
// jobchange_tile�w�b�_ [jobchange_tile.h]
// Author : �ɓ��z��
//
//====================================================

//��d�C���N���[�h�h�~
#ifndef _JOBCHANGE_TILE_H_
#define _JOBCHANGE_TILE_H_

//====================================================
// �C���N���[�h
//====================================================
#include "tile.h"
#include "resource_texture.h"
#include "resource_character.h"

//====================================================
//�O���錾
//====================================================
class CScene3d;

//====================================================
// �N���X��`
//====================================================

// �_�~�[�^�C���N���X
class CJobchangeTile : public CTile
{
public:
	//============
	// �����o�֐�
	//===========
	CJobchangeTile();
	~CJobchangeTile();

	// ��������^�C�����Ƃ̏���
	static void CreateKnight(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CreateLancer(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CreateWizard(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CreateThief(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CreateMagician(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CreateArcher(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);

	// �N���X����
	static void Create(D3DXVECTOR3 pos, CResourceTexture::TEXTURE_TYPE Tex_type, CResourceCharacter::CHARACTER_TYPE Char_type);

	HRESULT Init(void);	// ������
	void Uninit(void);	// �I��
	void Update(void);	// �X�V
private:

	//============
	// �����o�ϐ�
	//===========
	CScene3d *m_pCrossPolygon;	// �}�[�N
	CResourceCharacter::CHARACTER_TYPE m_CharacterType;
};

#endif
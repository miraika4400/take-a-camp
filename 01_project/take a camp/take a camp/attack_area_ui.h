//===================================================
//
// �U���͈�UI�̏��� [attack_area_ui.h]
// Author : ���V����
//
//===================================================
#ifndef  _ATTACK_AREA_UI_H_
#define  _ATTACK_AREA_UI_H_

//===================================================
// �C���N���[�h�t�@�C��
//===================================================
#include "scene2d.h"
#include "resource_character.h"
#include "resource_attack.h"

//===================================================
// �}�N����`
//===================================================

//===================================================
// �N���X�錾
//===================================================
class CAttackAreaUi : public CScene2d
{
public:

	//===============================================
	// �����o�֐�
	//===============================================
	CAttackAreaUi();
	~CAttackAreaUi();

	static CAttackAreaUi *Create(D3DXVECTOR3 pos);    // ��������

	HRESULT Init(void);
	void Update(void);
	void Draw(void);

	void SetDrawFlag(bool bDraw) { m_bDraw = bDraw; }
	void SwitchDrawFlag(void) { m_bDraw ^= true; }
	void SetCharaType(CResourceCharacter::CHARACTER_TYPE type) { m_nCharaType = type; }

	void Reset(void);
private:
	//===============================================
	// �����o�ϐ��錾
	//===============================================
	int m_nLevel;
	CResourceCharacter::CHARACTER_TYPE m_nCharaType;
	bool m_bDraw;
	int m_nCntLevel;
	LPDIRECT3DTEXTURE9 m_apTex[CResourceCharacter::CHARACTER_MAX][MAX_ATTACK_LEVEL - 2];

};
#endif

//===================================================
//
// �L�����̃|���S���̏��� [caharacter_polygon.h]
// Author : ���V����
//
//===================================================
#ifndef  _CHARACTER_POLYGON_H_
#define  _CHARACTER_POLYGON_H_

//===================================================
// �C���N���[�h�t�@�C��
//===================================================
#include "scene2d.h"
#include "resource_character.h"

//===================================================
// �O���錾
//===================================================
class CDynamicTexture;
class CPlayerModel;

//===================================================
// �}�N����`
//===================================================
#define CHARACTER_POLYGON_SIZE (D3DXVECTOR3(300.0f,400.0f,0.0f))

//===================================================
// �N���X�錾
//===================================================
class CCharacterPolygon : public CScene2d
{
public:
    CCharacterPolygon();
    ~CCharacterPolygon();

    static CCharacterPolygon *Create(D3DXVECTOR3 pos);    // ��������
    HRESULT Init(void);             // ����������
    void Uninit(void);              // �I������
    void Update(void);              // �X�V����
    void Draw(void);                // �`�揈��

	// �L�����^�C�v�̃Z�b�g�E�擾
	void SetCharaType(CResourceCharacter::CHARACTER_TYPE type);
	CResourceCharacter::CHARACTER_TYPE GetCharaType(void) { return m_charaType; }
	void SetRimColor(D3DXCOLOR col);
private:
    //===============================================
    // �����o�ϐ��錾
    //===============================================
    CDynamicTexture *m_pDynamicTex;          // ���I�e�N�X�`���N���X
    CPlayerModel    *m_pCharacterModel;      // �L�����N�^�[���o��
    CResourceCharacter::CHARACTER_TYPE m_charaType; // �L�����N�^�[�^�C�v

};
#endif

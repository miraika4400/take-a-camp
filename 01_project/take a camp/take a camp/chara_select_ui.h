//=============================================================================
//
// chara_slect_ui�w�b�_ [chara_slect_ui.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _CHARA_SELECT_UI_H_
#define _CHARA_SELECT_UI_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene.h"
#include "game.h"
#include "resource_character.h"
#include "resource_texture.h"

//=============================
// �O���錾
//=============================
class CScene2d;
class CCharacterPolygon;
class CAttackAreaUi;

//*****************************
//�}�N����`
//*****************************
#define STATUS_NUM (2)

//*****************************
//�N���X��`
//*****************************

//�Q�[���N���X
class CCharaSelectUi : public CScene
{
public:
	//*****************************
	// �񋓒�`
	//*****************************

	//*****************************
	// �\���̒�`
	//*****************************
	struct CharaSelectUI
	{
		CScene2d * pBack;                   // �w�i
		CScene2d * pPlayerNumber;           // �v���C���[�ԍ�
        CScene2d * pCharaName;              // �L�����N�^�[��
		CScene2d * pControllIcon;           // �R���g���[���[�^�C�v�A�C�R��
		CScene2d * pReadyIcon;              // ���f�B�A�C�R��
        CScene2d * pNaviAttackArea;         // �U���͈͕\���U��
        CScene2d * apStatus[STATUS_NUM];    // �X�e�[�^�X
		CCharacterPolygon * pCharaPolygon;  // 
		CAttackAreaUi*pAttackUiPolygon;     // 
		D3DXVECTOR3 pos;                    // ���W
	};

    // �L�������\
    struct CharaStatus
    {
        CResourceTexture::TEXTURE_TYPE nDifficult; // �ނ�������
        CResourceTexture::TEXTURE_TYPE nRange;      // �͈�
    };

	//*****************************
	// �����o�֐�
	//*****************************
	CCharaSelectUi();
	~CCharaSelectUi();

	static CCharaSelectUi *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��
private:

	//*****************************
	// �����o�ϐ�
	//*****************************
    const static CharaStatus m_aStatusTexNum[CResourceCharacter::CHARACTER_MAX];

	CharaSelectUI m_aPolygon[MAX_PLAYER];

	int m_nCntAnim;       // �A�j���[�V�����J�E���g
	int m_nAnimY;         // �A�j���[�V����Y��
};

#endif
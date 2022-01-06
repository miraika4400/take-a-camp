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

//=============================
// �O���錾
//=============================
class CScene2d;
class CCharacterPolygon;

//*****************************
//�}�N����`
//*****************************

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
	struct CharaSelect_UI
	{
		CScene2d * pBack;         // �w�i
		CScene2d * pPlayerNumber; // �v���C���[�ԍ�
		CScene2d * pControllIcon; // �R���g���[���[�^�C�v�A�C�R��
		CScene2d * pReadyIcon;    // �R���g���[���[�^�C�v�A�C�R��
		CCharacterPolygon * pCharaPolygon;
		D3DXVECTOR3 pos;          // ���W
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
	CharaSelect_UI m_aPolygon[MAX_PLAYER];

	int m_nCntAnim;       // �A�j���[�V�����J�E���g
	int m_nAnimY;         // �A�j���[�V����Y��
};

#endif
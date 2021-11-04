//=============================================================================
//
// chara_slect�w�b�_ [chara_slect.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _CHARA_SELECT_H_
#define _CHARA_SELECT_H_

//*****************************
//�C���N���[�h
//*****************************
#include "scene.h"
#include "game.h"
#include "player.h"

//=============================
// �O���錾
//=============================

//*****************************
//�}�N����`
//*****************************

//*****************************
//�N���X��`
//*****************************

//�Q�[���N���X
class CCharaSelect : public CScene
{
public:
	//*****************************
	// �񋓒�`
	//*****************************

	//*****************************
	// �\���̒�`
	//*****************************
	struct Entry_Data
	{
		int nControllNum; // �R���g���[���[�ԍ�
		bool bController; // �R���g���[���[�t���O*true�Ȃ�R���g���[���[false�Ȃ�L�[�{�[�h
		int nColorNum;    // �J���[�ԍ�
		CPlayer::CHARA_TYPE charaType; // �L�����^�C�v
		bool bEntry;      // �G���g���[���
	};

	//*****************************
	// �����o�֐�
	//*****************************
	CCharaSelect();
	~CCharaSelect();

	static CCharaSelect *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��
	static Entry_Data GetEntryData(int nIndex) { return m_aEntryData[nIndex]; }
	static int GetEntryPlayerNum(void) { return m_nEntryPlayerNum; }
	static void ResetEntryPlayer(void);
private:
	void EntryPlayer(void);
	void CountEntryPlayerNum(void);
	//*****************************
	// �����o�ϐ�
	//*****************************
	static Entry_Data m_aEntryData[MAX_PLAYER]; // �G���g���[�f�[�^
	static int m_nEntryPlayerNum;               // �G���g���[�l��
	bool m_abUseJoy[MAX_PLAYER];           // �g���Ă���R���g���[���[�̃t���O
	bool m_abUseKey[MAX_PLAYER];           // �g���Ă���R���g���[���[�̃t���O
};

#endif
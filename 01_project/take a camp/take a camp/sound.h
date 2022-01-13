//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : ���V ����
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//*****************************************************************************
// �N���X�錾
//*****************************************************************************

// �T�E���h�N���X
class CSound
{
public:
	//============
	// ��ԗ�
	//============
	typedef enum
	{
		LABEL_BGM_TITLE = 0,			// �^�C�g��BGM
		LABEL_BGM_SELECT,				// �L�����N�^�[�Z���N�gBGM
		LABEL_BGM_GAME,					// �Q�[����BGM
		LABEL_BGM_RESULT,				// ���U���g��BGM
		LABEL_SE_KENSI_ATTACK,			// ���m�̍U��SE
		LABEL_SE_KENSI_FINALATTACK,		// ���m�̕K�ESE
		LABEL_SE_YARI_ATTACK,			// ���̍U��SE
		LABEL_SE_YARI_FINALATTACK,		// ���̕K�ESE
		LABEL_SE_MAHOU_ATTACK,			// ���@�̍U��SE
		LABEL_SE_MAHOU_FINALATTACK,		// ���@�̕K�ESE
		LABEL_SE_YUMI_ATTACK,			// �|�̍U��SE
		LABEL_SE_YUMI_FINALATTACK,		// �|�̕K�ESE
		LABEL_SE_TOZOKU_ATTACK,			// �����̍U��SE
		LABEL_SE_TOZOKU_FINALATTACK,	// �����̕K�ESE
		LABEL_SE_KIJUTUSI_ATTACK,		// ��p�t�̍U��SE
		SOUND_LABEL_MAX,				// �T�E���h�ő吔
	}LABEL;

	typedef enum
	{
		SOUND_LOOP_ON = -1,	//���[�v����
		SOUND_LOOP_OFF,		//���[�v���Ȃ�
	}SOUND_LOOP;


	//============
	// �����o�֐�
	//============
	CSound();
	~CSound();

	HRESULT Init(HWND hWnd);   // ������
	void Uninit(void);         // �I��
	HRESULT Play(LABEL label); // �Đ�
	void Stop(LABEL label);    // ��~
	void Stop(void);           // �Đ����̉��̂��ׂĒ�~
private:
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	//============
	// �\���̒�`
	//============
	// �p�����[�^
	typedef struct
	{
		char *pFilename; // �t�@�C����
		int nCntLoop;    // ���[�v�J�E���g
	} SOUNDPARAM;

	//============
	// �����o�ϐ�
	//============
	static SOUNDPARAM m_aParam[SOUND_LABEL_MAX];             // �p�����[�^

	IXAudio2 *m_pXAudio2;                                    // XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice;              // �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX];   // �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX];                    // �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX];                     // �I�[�f�B�I�f�[�^�T�C�Y
};
#endif
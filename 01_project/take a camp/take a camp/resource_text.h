//====================================================
//
// resource_text�w�b�_ [resource_text.h]
// Author : �ɓ��z��
//
//====================================================

//��d�C���N���[�h�h�~
#ifndef _RESOURCE_TEXT_H_
#define _RESOURCE_TEXT_H_

//====================================================
//�C���N���[�h
//====================================================
#include "main.h"
#include <map>

//====================================================
//�}�N����`
//====================================================

//*****************************
//�N���X��`
//*****************************

// �e�L�X�g���\�[�X�N���X
class CResourceText
{
public:

	// �����o�֐�
	static CResourceText * Create(void);	// �N���X����
	static void Release(void);				// �N���X�j��

	CResourceText();
	~CResourceText();

	static CResourceText *GetResourceText(void) { return m_pSingle; };	// ���\�[�X�e�L�X�g�|�C���^�̎擾
	std::string GetMapString(int nCountLine) { return m_TextMap[nCountLine]; };	// �}�b�v�ɓ����Ă�e�L�X�g�̏��擾
private:
	void Load(void);     // ���f���ǂݍ���
	void Unload(void); // ���f���j��

	static CResourceText *m_pSingle;		// ���f���N���X�̃|�C���^*�V���O���g���p
	std::map<int, std::string> m_TextMap;	// �e�L�X�g���ێ��p�̃}�b�v
};

#endif
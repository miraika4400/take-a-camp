//=============================================================================
//
// color_manager�w�b�_ [color_manager.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _COLOR_MANAGER_H_
#define _COLOR_MANAGER_H_

//*****************************
// �C���N���[�h
//*****************************
#include "manager.h"

//*****************************
//�O���錾
//*****************************

//*****************************
//�}�N����`
//*****************************
#define COLOR_STEP_NUM 3
#define GET_COLORMANAGER CColorManager::GetColorManager()

//*****************************
// �N���X��`
//*****************************

// �F�Ǘ��N���X
class CColorManager
{
private:
	//�R���X�g���N�^
	CColorManager();
public:
	typedef struct
	{
		D3DXCOLOR aCol[COLOR_STEP_NUM];
		D3DXCOLOR iconColor;
		int       nUsePlayerNum;
	}ColorData;

	//�����o�֐�
	~CColorManager();
	static CColorManager *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	static void Release(void);

	void UseNumReset(void);

	// �擾����
	static CColorManager*GetColorManager(void) { return m_pInstance; }
	ColorData GetColorData(int nIndex) { m_aColorData[nIndex]; }
	ColorData GetColorDataByPlayerNumber(int nPlayerNum); // �v���C���[���g���Ă���J���[�f�[�^�̎擾
	D3DXCOLOR GetStepColor(int nIndex, int nStep) { return m_aColorData[nIndex].aCol[nStep]; }
	D3DXCOLOR GetIconColor(int nIndex) { return m_aColorData[nIndex].iconColor; }
	int GetColorNum(void) { return (int)m_aColorData.size(); }
	void SetUsePlayerNum(int nIndex, int nPlayerNum) { m_aColorData[nIndex].nUsePlayerNum = nPlayerNum; }
	int GetUsePlayerNum(int nIndex) { return m_aColorData[nIndex].nUsePlayerNum; }

private:
	void LoadText(void); // �e�L�X�g�f�[�^�̓ǂݍ���

	// �����o�ϐ�
	static CColorManager * m_pInstance;  // �C���X�^���X
	std::vector<ColorData> m_aColorData; // �J���[�f�[�^
};

#endif
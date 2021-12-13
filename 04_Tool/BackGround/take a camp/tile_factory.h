//=============================================================================
//
// tile_factory�w�b�_ [tile_factory.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _TILE_FACTORY_H_
#define _TILE_FACTORY_H_

//*****************************
// �C���N���[�h
//*****************************
#include "main.h"

//*****************************
//�O���錾
//*****************************
class CTile;

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************

// �^�C���N���X
class CTileFactory
{
private:
	// �B���R���X�g���N�^
	CTileFactory();
public:
	// �֐��|�C���^
	typedef void(*CTileFactory::SENTENCE_FUNC)(D3DXVECTOR3, D3DXCOLOR);

	typedef struct
	{
		std::string strLabelName;
		SENTENCE_FUNC createFunction;
	}LabelData;

	//�����o�֐�
	~CTileFactory();

	static CTileFactory* Create(void);
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	static void Release(void);

	static CTileFactory * GetTileFactory(void) { return m_pInstance; }

	SENTENCE_FUNC GetCreateFunction(int nIndex) { return m_CreateSentence[nIndex]; }
private:
	void LoadTileData(void);
	// �����o�ϐ�
	static std::vector<SENTENCE_FUNC>m_CreateSentence;// �֐��|�C���^
	static CTileFactory*m_pInstance;
	static const std::vector<LabelData> m_cLabelData;
};

#endif
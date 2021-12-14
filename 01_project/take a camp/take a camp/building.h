//=============================================================================
//
// �w�i�I�u�W�F�N�g�̏��� [building.h]
// Author : �����x�ߑ�
//
//=============================================================================
#ifndef _BUILDING_H_
#define _BUILDING_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "model.h"

//=============================================================================
// �O���錾
//=============================================================================

//=============================================================================
// �}�N����`
//=============================================================================

//=============================================================================
// �N���X�錾
//=============================================================================
class CBuilding : public CModel
{
public:
	//�����^�C�v
	typedef enum
	{
		BUILDING_TYPE_TREE = 0,//
		BUILDING_TYPE_MATO,		//
		BUILDING_TYPE_BUKIKAKE,
		BUILDING_TYPE_CHEST,
		BUILDING_TYPE_TARU,
		BUILDING_TYPE_GAITOU,
		BUILDING_TYPE_HATA,
		BUILDING_TYPE_SAKU,
		BUILDING_TYPE_ENOGU,
		BUILDING_TYPE_ENPITU,
		BUILDING_TYPE_MAGCUP,
		BUILDING_TYPE_MAX
	}BUILDING_TYPE;

	CBuilding();	// �R���X�g���N�^
	~CBuilding();	// �f�X�g���N�^

	static CBuilding * Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, BUILDING_TYPE type);	// ��������

	HRESULT Init(void);		// ����������
	void Uninit(void);		// �I������
	void Update(void);		// �X�V����
	void Draw(void);		// �`�揈��

	static void Load(void);

	void SetBuildType(BUILDING_TYPE BuildType) { m_BuildingType = BuildType; }
	BUILDING_TYPE GetBuildTypel(void) { return m_BuildingType; }

private:
	//=============================================================================
	// �����o�ϐ��錾
	//=============================================================================
	D3DXVECTOR3 m_size;		//�傫��
	D3DXVECTOR3 m_rot;		//�p�x
	D3DXVECTOR3 m_move;		//�ړ�

	BUILDING_TYPE m_BuildingType;
};

#endif // !_ITEM_H_

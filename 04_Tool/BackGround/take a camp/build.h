//=============================================================================
//
// �w�i�I�u�W�F�N�g�̏��� [building.h]
// Author : �����x�ߑ�
//
//=============================================================================
#ifndef _BUILD_H_
#define _BUILD_H_

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
class CBuild : public CModel
{
public:
	//�����^�C�v
	typedef enum
	{
		BUILD_TYPE_TREE = 0,//
		BUILD_TYPE_MATO,		//
		BUILD_TYPE_BUKIKAKE,
		BUILD_TYPE_CHEST,
		BUILD_TYPE_TARU,
		BUILD_TYPE_GAITOU,
		BUILD_TYPE_HATA,
		BUILD_TYPE_SAKU,
		BUILD_TYPE_ENOGU,
		BUILD_TYPE_ENPITU,
		BUILD_TYPE_MAGCUP,
		BUILD_TYPE_MAX
	}BUILD_TYPE;
	
	typedef enum
	{
		BUILD_TRUE=0,
		BUILD_FALSE
	}BUILD_BOOL;

	CBuild();	// �R���X�g���N�^
	~CBuild();	// �f�X�g���N�^

	static CBuild * Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, BUILD_TYPE type, BUILD_BOOL bBuild);	// ��������

	HRESULT Init(void);		// ����������
	void Uninit(void);		// �I������
	void Update(void);		// �X�V����
	void Draw(void);		// �`�揈��

	void MoveUpdate(void);	//�ړ��X�V
	void RotUpdate(void);	//�p�x�X�V

	void Save(void);
	static void Load(void);

	void SetBuildType(BUILD_TYPE BuildType) { m_BuildType = BuildType; }
	BUILD_TYPE GetBuildTypel(void) { return m_BuildType; }
	void SetBuildBool(BUILD_BOOL bBuild) { m_BuildBool = bBuild; }
	BUILD_BOOL GetBuildBool(void) { return m_BuildBool; }
private:
	//=============================================================================
	// �����o�ϐ��錾
	//=============================================================================
	D3DXVECTOR3 m_size;		//�傫��
	D3DXVECTOR3 m_rot;		//�p�x
	D3DXVECTOR3 m_move;		//�ړ�

	BUILD_TYPE m_BuildType;			//
	BUILD_BOOL m_BuildBool;			

	bool m_bUp;				//�������
	bool m_bGet;			//�擾�t���O

};

#endif // !_ITEM_H_

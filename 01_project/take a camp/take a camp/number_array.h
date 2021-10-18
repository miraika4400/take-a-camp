//=============================================================================
//
// number_array�w�b�_ [number_array.h]
// Author : �ɓ��z��
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _NUMBER�QARRAY_H_
#define _NUMBER�QARRAY_H_

//=============================================================================
//�C���N���[�h
//=============================================================================
#include "main.h"
#include "scene.h"

//=============================================================================
// �O���錾
//=============================================================================
class CBillboard;

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_ARRAY_NUM (5)

//=============================================================================
//�N���X��`
//=============================================================================

//�i���o�[�N���X
class CNumberArray : public CScene
{
public:
	//============
	// �����o�֐�
	//============

	CNumberArray();
	~CNumberArray();
	static CNumberArray *Create(const int nNum, const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col, const int nColorNum); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);	// �I��
	void Update(void);	// �X�V
	void Draw(void);	// �`��

	float Kerning(void);	// �\�����鐔���̊Ԋu
	void SetNumber(void);	// �i���o�[�̃Z�b�g
private:
	//============
	// �����o�ϐ�
	//============
	CBillboard *m_apNumber[MAX_ARRAY_NUM];	// �\�����鐔��
	int m_nNumber;					// �i���o�[
	D3DXVECTOR3 m_pos;				// ���W
	D3DXVECTOR3 m_size;				// �傫��
	D3DXCOLOR m_col;				// �F
	bool m_bZeroCheck;				// 0���ǂ����̃`�F�b�N
	int m_nPlayerNum;				// 0���ǂ����̃`�F�b�N
};

#endif
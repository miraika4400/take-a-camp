//=============================================================================
//
// ���[�v�G�t�F�N�g [warp_effect.h]
// Author : �g�c �I�l
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _WARP_EFFECT_H_
#define _WARP_EFFECT_H_

//*****************************
// �C���N���[�h
//*****************************
#include "scene.h"
//*****************************
//�O���錾
//*****************************

//*****************************
//�}�N����`
//*****************************

//*****************************
// �N���X��`
//*****************************
class CWarpEffect : public CScene
{
public:
	//*****************************
	//�����o�֐�
	//*****************************
	CWarpEffect();
	~CWarpEffect();

	static void Create(D3DXVECTOR3 pos, D3DXVECTOR3 GoalPos, D3DXCOLOR col);	//��������

	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);

private:

	void	CreateEffect(void);

	//*****************************
	// �����o�ϐ�
	//*****************************
	D3DXVECTOR3 m_pos;		//�ʒu
	D3DXVECTOR3 m_GoalPos;	//�ړI�̈ʒu
	D3DXVECTOR3 m_move;		//�ړ���
	D3DXCOLOR   m_col;		//�F
	int nCreateCount;		//�G�t�F�N�g�����܂ł̃J�E���g
};
#endif
//=============================================================================
//
// �g�[�^�����U���g�w�b�_�[ [total_result.h]
// Author : �g�c �I�l
//
//=============================================================================
//��d�C���N���[�h�h�~
#ifndef _TOTAL_MANAGER_H_
#define _TOTAL_MANAGER_H_

//=============================
// �C���N���[�h
//=============================
#include "main.h"
#include "scene.h"
#include "game.h"

//=============================
// �O���錾
//=============================
class CScene2d;
class CScoreKill;
class CPolygon;

//=============================
// �N���X��`
//=============================

// �}�l�[�W���[�N���X
class CTotalResult : public CScene
{
public:
	//============
	// ��ԗ�
	//============

	//============
	// �����o�֐�
	//============
	CTotalResult();
	~CTotalResult();
	static CTotalResult *Create(void); //�N���X����
	HRESULT Init(void);		// ������
	void	Uninit(void);	// �I��
	void	Update(void);	// �X�V
	void	Draw(void);		// �`��

private:
	//============
	// �����o�ϐ�
	//============
	CScene2d * m_pBg;						// �w�i�|���S��
	CScoreKill* m_pScoreKill;	// �L���X�R�A
	D3DXVECTOR3 m_ScorePos[MAX_PLAYER];
	CPolygon * m_pBackGroundPolygon;

};


#endif
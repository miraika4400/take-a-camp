//=============================================================================
//
// gauge�w�b�_ [gauge.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _GAUGE_H_
#define _GAUGE_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
//�O���錾
//*****************************
class CPolygon;

//*****************************
// �}�N����`
//*****************************

//*****************************
//�N���X��`
//*****************************

//�Q�[�W�N���X
class CGauge : public CScene
{
public:

	//============
	// �񋓒�`
	//============

	//============
	// �����o�֐�
	//============

	CGauge();
	~CGauge();

	// static
	static CGauge *Create(float* pData, D3DXVECTOR3 leftPos, float fBarWidht, float fBarHeight, float fMaxNum, D3DXCOLOR frontCol); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

private:
	// �����o�ϐ�
	CPolygon*   m_pPolygon;  // ���C�t�`��p�̃|���S��
	D3DXVECTOR3 m_pos;       // �Q�[�W�̈ʒu(��)
	float       m_fBarWidht; // ��
	float       m_fBarHeight; // ����
	float       m_fMaxNum;   // �ő吔
	float *     m_pfData;    // �Q�[�W�ƕR�Â��鐔�l�̃|�C���^
	D3DXCOLOR   m_frontCol;  // �t�����g�̃J���[
};

#endif
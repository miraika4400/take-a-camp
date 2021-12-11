//=============================================================================
//
// result_graph�w�b�_ [result_graph.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _RESULT_GRAPH_H_
#define _RESULT_GRAPH_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"
#include "game.h"

//*****************************
//�O���錾
//*****************************
class CScene2d;
class CGauge;

//*****************************
// �}�N����`
//*****************************
#define GAUGE_NUM (2)
//*****************************
//�N���X��`
//*****************************

//�Q�[�W�N���X
class CResultGraph : public CScene
{
public:

	//============
	// �񋓒�`
	//============

	//============
	// �\���̒�`
	//============
	struct GraphParts
	{
		CGauge   * pGauge;    // �Q�[�W
		float    fGraphData;  // �Q�[�W���l
		int      m_nColorNum; // �J���[�ԍ�
	};

	//============
	// �����o�֐�
	//============

	CResultGraph();
	~CResultGraph();

	// static
	static CResultGraph *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��
private:
	// �����o�ϐ�
	CScene2d * m_pBg;                  // �w�i�|���S��
	GraphParts m_aGauge[MAX_PLAYER][GAUGE_NUM];  // �Q�[�W
};

#endif
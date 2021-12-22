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
class CCharacterPolygon;

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
	enum
	{
		GAUGE_BACK = 0,
		GAUGE_FRONT,
	};

	//============
	// �\���̒�`
	//============
	struct GraphParts
	{
		CGauge   * pGauge;    // �Q�[�W
		int      m_nColorNum; // �J���[�ԍ�
	};

	struct Rank
	{
		int nPlayerNum;
		int nPaintNum;
	};

	struct CharaPolygonData
	{
		CCharacterPolygon* pCharaPolygon;
		float fMoveY;
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
	void SetMaxNum(void);
	void CreatePolygon(void);
	void ManageGraph(void);
	void ManageCharacterHeight(void);
	// �����o�ϐ�
	CScene2d * m_pBg;                  // �w�i�|���S��
	GraphParts m_aGauge[MAX_PLAYER][GAUGE_NUM];  // �Q�[�W
    float m_fMaxNum; // �Q�[�W�������l�ő�l
	std::vector<Rank> m_aRankData;
	int m_nActionRank; // �A�N�V�������N��������
	int m_nActionCnt;
	std::vector<CCharacterPolygon*> m_apCharaPolygon;
};

#endif
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
#define DEFAULT_GAUGE_RATE (0.03f)
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
	enum MODE
	{
		MODE_VALUE_AUTO = 0, // �������l���Ǘ�*����
		MODE_VALUE_SELF,	 // �������l���Ǘ�*�蓮
		MODE_HEIGHT_AUTO,	 // �Q�[�W�̍����𒼐ڂ��Ǘ�*����
		MODE_HEIGHT_SELF,	 // �Q�[�W�̍����𒼐ڂ��Ǘ�*�蓮
	};

	//============
	// �����o�֐�
	//============

	CGauge();
	~CGauge();

	// static
	static CGauge *Create(D3DXVECTOR3 leftPos, float fBarWidht, float fBarHeight, float fMaxNum, D3DXCOLOR frontCol); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	// �Q�[�W�������l
	void SetValue(float fValue) { m_fValue = fValue; }
	float GetValue(void) { return m_fValue; }
	// �Q�[�W�������l�̖ڕW�l
	void SetValueDist(float fValueDist) { m_fValueDist = fValueDist; }
	float GetValueDist(void) { return m_fValueDist; }
	// �Q�[�W����
	void SetHeight(float fHeight) { m_fHeight = fHeight; }
	float GetHeight(void) { return m_fHeight; }
	// �Q�[�W�����̖ڕW�l
	void SetHeightDist(float fHeightDist) { m_fHeightDist = fHeightDist; }
	float GetHeightDist(void) { return m_fHeightDist; }
	// �W��
	void SetRate(float fRate) { m_fGaugeRate = fRate; }
	float GetRate(void) { return m_fGaugeRate; }
	// �Q�[�W���[�h
	MODE GetMode(void) { return m_mode; }
	void SetMode(MODE mode);

private:
	void UpdateValue(void);
	// �����o�ϐ�
	CPolygon*   m_pPolygon;   // ���C�t�`��p�̃|���S��
	D3DXVECTOR3 m_pos;        // �Q�[�W�̈ʒu(��)
	float       m_fBarWidht;  // ��
	float       m_fBarHeight; // �����ő�
	float       m_fHeightDist;// �����ڕW
	float       m_fHeight;    // ����
	float       m_fMaxNum;    // �ő吔
	float       m_fValue;     // �Q�[�W�������l
	float       m_fValueDist; // �Q�[�W�������l�ڕW�l
	float       m_fGaugeRate; // �Q�[�W�Έڎ��̌W��
	D3DXCOLOR   m_frontCol;   // �t�����g�̃J���[
	MODE        m_mode;       // �Q�[�W�̃��[�h
};

#endif
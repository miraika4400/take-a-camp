//=============================================================================
//
// �Q�[���J�n�̏��� [game_start.h]
// Author : �����D�I
//
//=============================================================================
#ifndef _GAME_START_H_
#define _GAME_START_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "scene.h"

//=============================================================================
// �O���錾
//=============================================================================
class CPolygon;
class CPlayer;
class CTime;
//=============================================================================
// �}�N����`
//=============================================================================
#define START_UI_SIZE_X (750.0f)
#define START_UI_SIZE_Y	(200.0f)
#define START_UI_POS_Y	(200.0f)

//=============================================================================
// �N���X�錾
//=============================================================================
class CGameStart :public CScene
{
public:
	// UI�̎��
	typedef enum
	{
		START_TYPE_READEY = 0,
		START_TYPE_GO,
		START_TYPE_PLAY,
		START_TYPE_MAX
	}START_TYPE;

	CGameStart();						// �R���X�g���N�^
	~CGameStart();						// �f�X�g���N�^

	static CGameStart*Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);	// ��������

	HRESULT Init(void);					// ����������
	void Uninit(void);					// �I������
	void Update(void);					// �X�V����
	void Draw(void);					// �`�揈��	

	void SetStartType(START_TYPE type) { m_type = type; }
	START_TYPE GetType(void) { return m_type; }

private:
	void GoChange(void);
	void PlayChange(void);
	void StartPlayer(void);

	// �����o�ϐ�
	CPolygon*   m_pPolygon;		// ���C�t�`��p�̃|���S��
	D3DXVECTOR3 m_pos;			// �ʒu
	D3DXVECTOR3 m_size;			// �T�C�Y
	D3DXCOLOR   m_col;			// �J���[
	int			m_nCount;		// �J�E���g
	START_TYPE  m_type;			// UI�̃^�C�v
	bool m_bStart;
};
#endif // !_GAME_START_H_

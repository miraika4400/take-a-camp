//=============================================================================
//
// game�w�b�_ [game.h]
// Author : ���V ����
//
//=============================================================================

//��d�C���N���[�h�h�~
#ifndef _GAME_H_
#define _GAME_H_

//*****************************
//�C���N���[�h
//*****************************
#include "main.h"
#include "scene.h"
#include "map.h"

//=============================
// �O���錾
//=============================
class CCamera;
class CRuleManager;
class CMapManager;
//*****************************
//�}�N����`
//*****************************
#define MAX_PLAYER (4)	// �v���C���[�̍ő�l��

//*****************************
//�N���X��`
//*****************************

//�Q�[���N���X
class CGame : public CScene
{
public:
	//*****************************
	// �񋓒�`
	//*****************************

	//*****************************
	// �����o�֐�
	//*****************************
	CGame();
	~CGame();

	static CGame *Create(void); // �N���X����

	HRESULT Init(void); // ������
	void Uninit(void);  // �I��
	void Update(void);  // �X�V
	void Draw(void);    // �`��

	// �擾����
	static CRuleManager *GetRuleManager(void) { return m_pRuleManager; } // ���[���}�l�[�W���[�|�C���^
	static CMap* GetStage(void) { return m_pMap; }
	static CMapManager::MAP_TYPE GetMapType(void) { return m_MapType; }
	static void SetMapType(CMapManager::MAP_TYPE MapType) { m_MapType = MapType; }
private:

	//*****************************
	// �����o�ϐ�
	//*****************************
	static CRuleManager* m_pRuleManager; // ���[���}�l�[�W���[
	static CMap *m_pMap;			 // �X�e�[�W�|�C���^
	static CMapManager::MAP_TYPE m_MapType;// �}�b�v�̃^�C�v
};

#endif
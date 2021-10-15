//=============================================================================
//
// playerヘッダ [player.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************
// インクルード
//*****************************
#include "main.h"
#include "model.h"

//*****************************
// 前方宣言
//*****************************
class CCollision;
class CActRange;
//*****************************
// クラス定義
//*****************************

// プレイヤークラス
class CPlayer : public CModel
{
public:
	typedef enum
	{
		KEY_PROGRESS = 0,
		KEY_RECESSION,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_MAX
	}CONTROLL_KEY;

	typedef enum
	{
		PLAYER_STATE_NORMAL = 0,	//通常状態
		PLAYER_STATE_DEATH			//死亡状態
	}PLAYER_STATE;

	//メンバ関数
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, int nPlayerNumber);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);	// 死亡処理関数

	int GetColorNumber(void) { return m_nColor; }
	CCollision * GetCollision(void) { return  m_pCollison; }
	int GetPlayerNumber(void) { return m_nPlayerNumber; }
	void SetState(PLAYER_STATE PlayerState) {m_PlayerState = PlayerState;}
	PLAYER_STATE GetState(void) { return m_PlayerState; }
private:
	void Move(void);		// 移動処理
	void Respawn(void);		// リスポーン処理
	void Invincible(void);	// 無敵処理
	// メンバ変数
	static int m_anControllKey[4][KEY_MAX];

	int m_nPlayerNumber;		// プレイヤー番号
	int m_nColor;				// 色ナンバー
	bool m_bMove;				// 移動可否フラグ
	bool m_bInvincible;			// 無敵フラグ
	PLAYER_STATE m_PlayerState;	// プレイヤーステータス
	int	m_nRespawnCount;		// リスポーンまでのカウント
	int m_nInvincibleCount;		// 無敵時間のカウント
	D3DXVECTOR3	 m_Move;		// 移動量
	int			 m_MoveCount;	// 移動時のカウント
	D3DXCOLOR	 m_color;		// 色
	CCollision * m_pCollison;	// 当たり判定
	CActRange *	 m_pActRange;	// 行動判定
	D3DXVECTOR3  m_RespawnPoa;	// リスポーン位置
};

#endif
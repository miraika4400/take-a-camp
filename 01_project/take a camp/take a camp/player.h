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
#include "player_model.h"
#include "resource_character.h"

//*****************************
// 前方宣言
//*****************************
class CCollision;
class CActRange;
class CAttackBased;
class CMotion;
class CKillCount;
class CSkillgauge;

//*****************************
// マクロ定義
//*****************************
#define STICK_DECISION_RANGE	(32768.0f / 1.001f)				// スティックの上下左右の判定する範囲

//*****************************
// クラス定義
//*****************************

// プレイヤークラス
class CPlayer : public CPlayerModel
{
public:
	// 列挙

	// キー
	typedef enum
	{
		KEY_PROGRESS = 0,
		KEY_RECESSION,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_BULLET,
		KEY_ATTCK_FINAL,
		KEY_MAX
	}CONTROLL_KEY;

	// ステート
	typedef enum
	{
		PLAYER_STATE_NORMAL = 0,	//通常状態
		PLAYER_STATE_STOP,			//停止状態
		PLAYER_STATE_DEATH			//死亡状態
	}PLAYER_STATE;

	// アイテムステート
	typedef enum
	{
		ITEM_STATE_NONE = 0,	//通常
		ITEM_STATE_DASH,		//加速
		ITEM_STATE_REVERSE,		//操作逆転
		ITEM_STATE_MAX
	}ITEM_STATE;

	//メンバ関数
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber);
	static CPlayer*GetPlayerByPlayerNumber(int nPlayerNum);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);		// 死亡処理関数
	void Attack(void);		// 攻撃処理
	void AttackFinal(void); // 必殺技処理

	//セッター・ゲッター
	// カラー番号取得
	int GetColorNumber(void) { return m_nColor; }		
	// 当たり判定取得
	CCollision * GetCollision(void) { return  m_pCollision; }	
	// プレイヤー番号取得
	int GetPlayerNumber(void) { return m_nPlayerNumber; }		
	// プレイヤー状態
	void SetState(PLAYER_STATE PlayerState) { m_PlayerState = PlayerState; }	
	PLAYER_STATE GetState(void) { return m_PlayerState; }			
	// 無敵状態取得
	bool GetInvincible(void) { return m_bInvincible; }		
	//向きと位置の移動量
	D3DXVECTOR3 GetRotDest(void) { return m_rotDest; }					
	D3DXVECTOR3 GetPosDest(void) { return m_Move; }
	// アイテム状態
	void SetItemState(ITEM_STATE ItemState) { m_ItemState = ItemState; }	
	ITEM_STATE GetItemState(void) { return m_ItemState; }		
	// キルカウントポインタ
	CKillCount * GetKillCount(void) { return m_pKillCount; }
	// 移動フラグ
	bool GetMoveFlag(void) { return m_bMove; }
	// 攻撃関係フラグ
	void SetAttack(bool bAttack) { m_bAttack = bAttack; }				
	void SetFinalAttack(bool bFinalAttack) { m_bFinalAttack = bFinalAttack; }	
	// 攻撃ポインタ
	CAttackBased * GetAttack(void) { return m_pAttack; }		
	//プレイヤー
	static int GetPlayerControllKey(int nPlayerNum, CONTROLL_KEY keyEnum) { return m_anControllKey[nPlayerNum][keyEnum]; }
	// 必殺技ゲージポインタ
	CSkillgauge *GetSkillgauge(void) { return m_pSkillgauge; }
private:
	void InitCharacterData(void); // キャラデータの初期化
	void Move(void);			// 移動処理
	void ControlMove(void);		// コントロール処理
	void ManageRot(void);		// 向きの管理
	void Respawn(void);			// リスポーン処理
	void Invincible(void);		// 無敵処理
	void ManageItemState(void); // アイテムステートの管理

	// メンバ変数
	static int m_anControllKey[MAX_PLAYER][KEY_MAX];

	CKillCount * m_pKillCount;	// プレイヤーのキルカウントポインタ
	CAttackBased* m_pAttack;	// 攻撃用クラス
	int m_nPlayerNumber;		// プレイヤー番号
	D3DXCOLOR	 m_color;		// 色
	int m_nColor;				// 色ナンバー
	int m_nControllNum;         // コントロール番号
	bool m_bController;         // コントローラー操作かキーボード操作か
	bool m_bMove;				// 移動可否フラグ
	bool m_bOldMove;			// 前回の移動可否フラグの状態
	bool m_bAttack;				// 攻撃可否フラグ
	bool m_bFinalAttack;		// 必殺可否フラグ
	bool m_bInvincible;			// 無敵フラグ
	int m_nInvincibleCount;		// 無敵時間のカウント
	PLAYER_STATE m_PlayerState;	// プレイヤーステータス
	int	m_nRespawnCount;		// リスポーンまでのカウント
	D3DXVECTOR3	m_Move;					// 移動量
	int			m_nMoveCount;			// 移動回数
	int			m_nMoveFrame;			// 移動速度
	int			m_nMoveCountData;		// 加速までの移動回数保存
	int			m_nMoveFrameInitialData;// 移動時初動フレーム数保存
	int			m_nMoveFrameData;		// 移動時フレーム数保存
	int			m_nMoveFrameDataDash;	// 移動時フレーム数*ダッシュ時保存
	int			m_nMoveFrameCount;		// 移動時カウント
	ITEM_STATE m_ItemState;		// アイテムステータス
	int	m_ReverseCount;			// アイテム効果 操作反転カウント
	int m_nDashCnt;				// アイテム効果 速度アップカウント
	CCollision * m_pCollision;	// 当たり判定
	CActRange *	 m_pActRange;	// 行動判定
	D3DXVECTOR3  m_rotDest;		// 回転(目標の値)
	D3DXVECTOR3  m_RespawnPos;	// リスポーン位置
	CSkillgauge * m_pSkillgauge;// 必殺技ゲージ
	int m_nChargeTilelevel;			// チャージ開始タイルの塗り段階

	// モーション用変数
	CMotion *m_apMotion[CResourceCharacter::MOTION_MAX];  // アニメーションポインタ

};

#endif
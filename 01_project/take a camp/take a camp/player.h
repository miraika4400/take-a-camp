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
#include "model_hierarchy.h"
#include "resource_character.h"

//*****************************
// 前方宣言
//*****************************
class CCollision;
class CActRange;
class CAttackBased;
class CMotion;
class CKillCount;

//*****************************
// クラス定義
//*****************************

// プレイヤークラス
class CPlayer : public CModelHierarchy
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
		KEY_MAX
	}CONTROLL_KEY;

	// ステート
	typedef enum
	{
		PLAYER_STATE_NORMAL = 0,	//通常状態
		PLAYER_STATE_REVERSE,		//操作逆転
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
	//// キャラタイプ
	//typedef enum
	//{
	//	CHARA_TYPE_FIGHTER = 0, // 戦士
	//	CHARA_TYPE_LANCER,      // 槍使い
	//	CHARA_TYPE_WIZARD,      // 魔法使い
	//	CHARA_TYPE_MAX
	//}CHARA_TYPE;

	//メンバ関数
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Death(void);		// 死亡処理関数
	void SkillDeath(void);	// スキルでの死亡処理関数
	void Attack(void);	// 攻撃処理

	int GetColorNumber(void) { return m_nColor; }
	CCollision * GetCollision(void) { return  m_pCollision; }
	int GetPlayerNumber(void) { return m_nPlayerNumber; }

	void SetState(PLAYER_STATE PlayerState) {m_PlayerState = PlayerState;}
	PLAYER_STATE GetState(void) { return m_PlayerState; }

	D3DXVECTOR3 GetRotDest(void) { return m_rotDest; }						
	D3DXVECTOR3 GetPosDest(void) { return m_Move; }
	void SetItemState(ITEM_STATE ItemState) { m_ItemState = ItemState; }
	ITEM_STATE GetItemState(void) { return m_ItemState; }
	CKillCount * GetKillCount(void) { return m_pKillCount; }

	static int GetPlayerControllKey(int nPlayerNum, CONTROLL_KEY keyEnum) { return m_anControllKey[nPlayerNum][keyEnum]; }
private:
	void Move(void);		// 移動処理
	void ManageRot(void);   // 向きの管理
	void Respawn(void);		// リスポーン処理
	void Invincible(void);	// 無敵処理
	void ManageMotion(void);// モーション管理
	void DrawModel(void);	// モデルの描画処理
	void SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData);// シェーダに値を送る

	// メンバ変数
	static int m_anControllKey[MAX_PLAYER][KEY_MAX];

	CKillCount * m_pKillCount;	// プレイヤーのキルカウントポインタ
	ITEM_STATE m_ItemState;		// アイテムステータス
	int m_nMoveframe;			// 移動速度
	int m_nDashCnt;				// 速度アップカウント
	CAttackBased* m_pAttack;	// 攻撃用クラス
	int m_nPlayerNumber;		// プレイヤー番号
	int m_nColor;				// 色ナンバー
	int m_nControllNum;         // コントロール番号
	bool m_bController;         // コントローラー捜査課キーボード操作か
	bool m_bMove;				// 移動可否フラグ
	bool m_bInvincible;			// 無敵フラグ
	PLAYER_STATE m_PlayerState;	// プレイヤーステータス
	int	m_nRespawnCount;		// リスポーンまでのカウント
	int m_nInvincibleCount;		// 無敵時間のカウント
	D3DXVECTOR3	 m_Move;		// 移動量
	int			 m_MoveCount;	// 移動時のカウント
	int			m_ReverseCount;	// 操作反転カウント
	D3DXCOLOR	 m_color;		// 色
	CCollision * m_pCollision;	// 当たり判定
	CActRange *	 m_pActRange;	// 行動判定
	D3DXVECTOR3  m_rotDest;		// 回転(目標の値)
	D3DXVECTOR3  m_RespawnPos;	// リスポーン位置
	CResourceCharacter::CHARACTER_TYPE m_characterType; // キャラタイプ

	// モーション用変数
	CMotion *m_apMotion[CResourceCharacter::MOTION_MAX];  // アニメーションポインタ

};

#endif
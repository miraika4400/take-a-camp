//=============================================================================
//
// 攻撃範囲 [attack.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _ATTACK_H_
#define _ATTACK_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "scene.h"
#include "resource_attack.h"
//*****************************
// 前方宣言
//*****************************
class CPlayer;
//*****************************
// マクロ定義
//*****************************
#define MAX_ATTACK (4)	//攻撃の最大回数

//=============================================================================
// クラス定義
//=============================================================================
class CAttackBased : public CScene
{
public:

	//関数定義
	CAttackBased();
	~CAttackBased();
	HRESULT Init(void);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);
	
	void	SetAttackType(CAttackManager::ATTACK_TYPE AttackType);			//攻撃タイプセッター
	CAttackManager::ATTACK_TYPE GetAttackType(void);						//攻撃タイプゲッター
	void	SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare);	//攻撃マスデータセッター
	CAttackManager::ATTACK_SQUARE_DATA GetAttackSquare(void);					//攻撃マスデータゲッター
	void		SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void);
	void		SetRot(D3DXVECTOR3 rot);
	D3DXVECTOR3 GetRot(void);
	void		SetAttackFlag(bool bAttack);	
	void		AttackSwitch(void);
	bool		GetAttackFlag(void);
	void		Attack(CAttackManager::ATTACK_RANGE_TYPE AttackType);
	void		SetPlayer(CPlayer* pPlayer);
	CPlayer*	GetPlayer(void);
	virtual void AttackCreate(void) = 0;//攻撃生成処理 
private:
	CPlayer* m_pPlayer;	//プレイヤークラス
	CAttackManager::ATTACK_TYPE			m_nAttackType;		// 攻撃タイプ
	CAttackManager::ATTACK_SQUARE_DATA	m_AttackSquare;	// 攻撃マスデータ
	D3DXVECTOR3 m_pos;								// 位置
	D3DXVECTOR3 m_rot;								// 向き
	bool		m_bAttack;							// 攻撃フラグ
};
#endif
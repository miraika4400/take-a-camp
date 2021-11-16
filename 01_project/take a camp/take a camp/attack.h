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
class CAttackArea;
//*****************************
// マクロ定義
//*****************************
#define MAX_ATTACK (4)	//攻撃の最大回数
#define MAX_ATTACK_AREA_NUM 128
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
	
	void	SetAttackType(CResourceCharacter::CHARACTER_TYPE AttackType);			//攻撃タイプセッター
	CResourceCharacter::CHARACTER_TYPE GetAttackType(void);						//攻撃タイプゲッター
	void	SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare);	//攻撃マスデータセッター
	CAttackManager::ATTACK_SQUARE_DATA GetAttackSquare(void);							//攻撃マスデータゲッター
	void		SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos(void);
	void		SetRot(D3DXVECTOR3 rot);
	D3DXVECTOR3 GetRot(void);
	void		SetAttackFlag(bool bAttack);	
	void		AttackSwitch(int nLevel);
	bool		GetAttackFlag(void);
	void		Attack(int AttackType);
	void		SetPlayer(CPlayer* pPlayer);
	CPlayer*	GetPlayer(void);
	virtual void AttackCreate(void) = 0;//攻撃生成処理 
	void		VisualizationAttackArea(int nAttackType = 0); // 攻撃範囲の可視化
	void        ResetAttackArea(void);
private:
	CPlayer* m_pPlayer;	//プレイヤークラス
	CAttackArea * m_apAttackArea[MAX_ATTACK_AREA_NUM];
	CResourceCharacter::CHARACTER_TYPE			m_nAttackType;	// 攻撃タイプ
	CAttackManager::ATTACK_SQUARE_DATA	m_AttackSquare[MAX_ATTACK_LEVEL];	// 攻撃マスデータ
	D3DXVECTOR3 m_pos;									// 位置
	D3DXVECTOR3 m_rot;									// 向き
	bool		m_bAttack;								// 攻撃フラグ
	int			m_nLevel;			//攻撃のレベル

};

#endif
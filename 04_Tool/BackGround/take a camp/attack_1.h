//=============================================================================
//
// 攻撃範囲タイプ1 [attack_1.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// クラス定義
//=============================================================================
class CAttack1 : public CAttackBased
{
public:
	//関数定義
	CAttack1();
	~CAttack1();
	static CAttack1 *Create(CPlayer* pPlayer);
	HRESULT Init(void);

private:
	void	AttackCreate(void);	//攻撃生成処理
	int		m_nAttackCount;		//攻撃までのカウント
	int		m_nType;			//攻撃の間隔用のタイプ
};
#endif
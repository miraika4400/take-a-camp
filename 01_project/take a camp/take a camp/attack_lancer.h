//=============================================================================
//
// 攻撃範囲 タイプ槍兵 [attack_lancer.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _ATTACK_LANCER_H_
#define _ATTACK_LANCER_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// クラス定義
//=============================================================================
class CAttackLancer : public CAttackBased
{
public:
	//関数定義
	CAttackLancer();
	~CAttackLancer();
	static CAttackLancer *Create(CPlayer* pPlayer);

private:
	void CreateEffect(D3DXVECTOR3 pos);
	//void	AttackCreate(void);	//攻撃生成処理

	//int		m_nAttackCount;		//攻撃までのカウント
	//int		m_nType;			//攻撃の間隔用のタイプ
};
#endif
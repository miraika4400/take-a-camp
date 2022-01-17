//=============================================================================
//
// 攻撃範囲 タイプ盗賊[attack_thief.h]
// Author : 増澤 未来
//
//=============================================================================
#ifndef _ATTACK_THIEF_H_
#define _ATTACK_THIEF_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack.h"
#include "scene.h"

//=============================================================================
// クラス定義
//=============================================================================
class CAttackThief : public CAttackBased
{
public:
	//関数定義
	CAttackThief();
	~CAttackThief();

	static CAttackThief *Create(CPlayer* pPlayer);

	void PlaySE(void);

private:
	void CreateEffect(D3DXVECTOR3 pos, ATTACK_STATE state); // エフェクト生成


	


};
#endif
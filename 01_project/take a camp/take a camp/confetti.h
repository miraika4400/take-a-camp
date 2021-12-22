//=============================================================================
//
// confettiヘッダ [confetti.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _CONFETTI_H_
#define _CONFETTI_H_

//*****************************
//インクルード
//*****************************
#include "scene2d.h"

//*****************************
//クラス定義
//*****************************

// 紙吹雪クラス
class CConfetti : public CScene2d
{
public:
	//============
	// メンバ関数
	//============
	CConfetti();
	~CConfetti();

	static CConfetti *Create(void); // クラス生成

	virtual HRESULT Init(void); // 初期化
	virtual void Update(void);  // 更新

private:
	//============
	// メンバ変数
	//============
	D3DXVECTOR3 m_move, m_moveDist;
};

#endif
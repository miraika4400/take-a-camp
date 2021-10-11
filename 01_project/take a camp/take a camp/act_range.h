//=============================================================================
//
// 行動範囲ヘッダ [act_range.h]
// Author : 吉田 悠人
//
//=============================================================================

//二重インクルード防止
#ifndef _ACT_RAGE_H_
#define _ACT_RAGE_H_

//*****************************
// インクルード
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
// 前方宣言
//*****************************
class CPlayer;

//*****************************
// クラス定義
//*****************************
// 行動範囲クラス
class CActRange : public CScene
{
public:
	//メンバ関数
	CActRange();
	~CActRange();
	static CActRange *Create(CPlayer* pPlayer);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	D3DXVECTOR3		m_size;
};

#endif
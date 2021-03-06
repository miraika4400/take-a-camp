//=============================================================================
//
// 影（ポリゴン）の処理 [shadow.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _SHADOW_H_
#define _SHADOW_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "scene3d.h"

//=============================================================================
// クラス宣言
//=============================================================================
class CShadow : public CScene3d
{
public:
	CShadow();	// コンストラクタ
	~CShadow();	// デストラクタ

	static CShadow * Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);	// 生成処理
private:
	//=============================================================================
	// メンバ変数宣言
	//=============================================================================
};

#endif // !_SHADOW_H_

//=============================================================================
//
// tileヘッダ [tile.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _TILE_H_
#define _TILE_H_

//*****************************
// インクルード
//*****************************
#include "main.h"
#include "model.h"

//*****************************
// クラス定義
//*****************************

// タイルクラス
class CTile : public CModel
{
public:
	//メンバ関数
	CTile();
	~CTile();
	static CTile *Create(D3DXVECTOR3 pos);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:

	// メンバ変数

};

#endif
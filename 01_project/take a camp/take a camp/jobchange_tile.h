//====================================================
//
// jobchange_tileヘッダ [jobchange_tile.h]
// Author : 伊藤　陽梧
//
//====================================================

//二重インクルード防止
#ifndef _JOBCHANGE_TILE_H_
#define _JOBCHANGE_TILE_H_

//====================================================
// インクルード
//====================================================
#include "tile.h"

//====================================================
//前方宣言
//====================================================
class CScene3d;

//====================================================
// クラス定義
//====================================================

// ダミータイルクラス
class CJobchangeTile : public CTile
{
public:
	//============
	// メンバ関数
	//===========
	CJobchangeTile();
	~CJobchangeTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
private:

	//============
	// メンバ変数
	//===========
	CScene3d *m_pCrossPolygon;	// マーク
};

#endif
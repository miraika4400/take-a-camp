//=============================================================================
//
// spawn_tileヘッダ [spawn_tile.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _SPAWN_TILE_H_
#define _SPAWN_TILE_H_

//*****************************
// インクルード
//*****************************
#include "tile.h"

//*****************************
//前方宣言
//*****************************
class CScene3d;
class CBullet;
//*****************************
//マクロ定義
//*****************************

//*****************************
// クラス定義
//*****************************

// リスポーンタイルクラス
class CSpawnTile : public CTile
{
public:
	//メンバ関数
	CSpawnTile();
	~CSpawnTile();

	static CSpawnTile *Create(D3DXVECTOR3 pos, D3DXCOLOR col);

	HRESULT Init(void);
	void Uninit(void);
private:
	void HitBulletAction(CBullet*pBullet);

	// メンバ変数
	CScene3d *m_pCrossPolygon;        // マーク

};

#endif
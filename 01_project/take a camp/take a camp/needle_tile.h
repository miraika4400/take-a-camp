//=============================================================================
//
// needle_tileヘッダ [needle_tile.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _NEEDLE_TILE_H_
#define _NEEDLE_TILE_H_

//*****************************
// インクルード
//*****************************
#include "color_tile.h"

//*****************************
//前方宣言
//*****************************
class CModel;

//*****************************
//マクロ定義
//*****************************

//*****************************
// クラス定義
//*****************************

// とげタイルクラス
class CNeedleTile : public CColorTile
{
public:
	//メンバ関数
	CNeedleTile();
	~CNeedleTile();

	static CNeedleTile *Create(D3DXVECTOR3 pos);
	void Update(void);
private:
	void HitPlayerAction(CPlayer*pPlayer);
	void ManageNeedle(void); // とげの管理
	// メンバ変数
	CModel *m_pNeedleModel;        // マーク
	int m_nCntHit;                 // hitしているフレーム数のカウント
	bool m_bUp;                    // とげを上げる
	int m_nUpCnt;                  // 上がっている間のカウント
	CScene3d *m_pHole;             // 穴
};

#endif
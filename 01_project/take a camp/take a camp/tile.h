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
//前方宣言
//*****************************
class CCollision;
class CScene3d;

//*****************************
//マクロ定義
//*****************************
#define TILE_ONE_SIDE 20.0f			// タイルのサイズ*一辺
#define TILE_SIZE_Y TILE_ONE_SIDE/2
#define TILE_SIZE D3DXVECTOR3(TILE_ONE_SIDE,TILE_SIZE_Y,TILE_ONE_SIDE)  // タイルのサイズ

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
	void CollisionPlayer(void);   // プレイヤーとの当たり判定
	void ManageFrame(void);        // アイコン管理
	void Peint(int nColorNumber, int nPlayerNum); // 塗処理

	// メンバ変数
	CCollision * m_pCollison; // 当たり判定
	D3DXCOLOR m_color;        // カラー
	CScene3d *m_pFrame;        // アイコン
	int m_nPrevNum;           // 今塗られているカラーの番号*デフォルトは-1
	int m_nStep;              // 今の塗段階
	int m_nCntStep;           // 再度塗り可能カウント
	int m_nLastHitPlayerNum;  // 最後に当たったプレイヤー番号
	bool m_bHitOld;           // 一個前のフレームで当たっていたか保存するよう
};

#endif
//=============================================================================
//
// color_tileヘッダ [color_tile.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _COLOR_TILE_H_
#define _COLOR_TILE_H_

//*****************************
// インクルード
//*****************************
#include "tile.h"

//*****************************
//前方宣言
//*****************************
class CCollision;
class CScene3d;
class CPaintTime;

//*****************************
//マクロ定義
//*****************************

//*****************************
// クラス定義
//*****************************

// 色付きタイルクラス
class CColorTile : public CTile
{
public:
	//メンバ関数
	CColorTile();
	~CColorTile();

	static void Create(D3DXVECTOR3 pos, D3DXCOLOR col = TILE_DEFAULT_COLOR);
	static void CountColorTile(void); // タイルの数字の数を数える

	static int GetTileNum(int nIndex) { return m_anTileNum[nIndex][0]; } // 特定カラーのタイル数
	static int GetTileNum(int nIndex, int nStep) { return m_anTileNum[nIndex][nStep]; } // 特定カラーの特定段階のタイル数

	static CColorTile*GetHitColorTile(D3DXVECTOR3 pos); // 指定座標とぶつかっているタイルの取得処理

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	int GetPeintNum(void) { return m_nPrevNum; } // 塗られている色の取得
	int GetStepNum(void) { return m_nStep; }     // ステップの取得

	void ResetTile(void); // タイルのリセット
	
	void Peint(int nColorNumber, int nPlayerNum); // 塗処理
	
	CScene3d *GetFrame(void) { return m_pFrame; }
private:
	void HitPlayerActionTrigger(CPlayer * pPlayer);  // 弾と当たったときのアクション*トリガー
	void HItPeint(CPeintCollision * pPeint);		 // 塗り判定と当たった時のアクション
	void ManageFrame(void);        // アイコン管理
	void ManageColor(void); // 色の管理

	// メンバ変数
	static int m_anTileNum[MAX_TILE_COLOR_NUM][COLOR_STEP_NUM + 1];
	D3DXCOLOR m_distColor;    // 目標カラー
	CScene3d *m_pFrame;       // 枠
	CPaintTime * m_pPaintTime;// 再度塗り可能時間
	int m_nPrevNum;           // 今塗られているカラーの番号*デフォルトは-1
	int m_nStep;              // 今の塗段階
	int m_nCntStep;           // 再度塗り可能カウント
	int m_nLastHitPlayerNum;  // 最後に当たったプレイヤー番号
	int	m_nCntFrem;			  // インターバル用カウント

};

#endif
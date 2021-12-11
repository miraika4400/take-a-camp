//=============================================================================
//
// 塗った数のUI [paintnum.h]
// Author : 伊藤陽梧
//
//=============================================================================

//二重インクルード防止
#ifndef _PAINTNUM_H_
#define _PAINTNUM_H_

//=============================================================================
// インクルード
//=============================================================================
#include "main.h"
#include "scene.h"

//=============================================================================
// クラス定義
//=============================================================================
class CPolygon;

// 塗った数のUIクラス
class CPaintnum : public CScene
{
public:
	//============
	// メンバ関数
	//============
	CPaintnum();
	~CPaintnum();
	static CPaintnum *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size); // クラス生成

	HRESULT Init(void); // 初期化
	void Uninit(void);	// 終了
	void Update(void);	// 更新
	void Draw(void);	// 描画

	int GetRank(int nPlayer) { return m_nRank[nPlayer]; } // プレイヤーの順位獲得処理
private:
	struct PaintInfo
	{
		D3DXVECTOR3 pos;  // 座標
		D3DXVECTOR3 size; // 大きさ
		D3DXCOLOR col;    // 色
	};

	//============
	// メンバ関数
	//============
	float ShiftSize(int nCount); // ずらす大きさの計算
	void PlayerRank(void);       // プレイヤーごとの順位
	void SetPolygonPos(int nCount); // ポリゴンの座標のセット

	//============
	// メンバ変数
	//============
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	// 頂点バッファへのポインタ
	CPolygon * m_pPolygon[MAX_PLAYER];  // ライフ描画用のポリゴン
	D3DXVECTOR3 m_pos;                  // 座標
	D3DXVECTOR3 m_size;                 // 大きさ
	PaintInfo m_PaintInfo[MAX_PLAYER];  // プレイヤーごとの塗り情報
	int m_nPlayerNum;                   // プレイヤーの人数
	int m_nRank[MAX_PLAYER];            // プレイヤーの順位
	float m_fChangeSize[MAX_PLAYER];    // 徐々に変えていく大きさ
};

#endif
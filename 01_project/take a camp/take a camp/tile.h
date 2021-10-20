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
#include "color_manager.h"
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
#define MAX_TILE_COLOR_NUM 16
#define TILE_DEFAULT_COLOR D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)

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
	virtual void Update(void);
	virtual void Draw(void);

	// 色のセット/取得
	void SetColor(D3DXCOLOR col) { m_color = col; }
	D3DXCOLOR GetColor(void) { return m_color; }

	CCollision*GetCollision(void) { return m_pCollison; }
private:
	void DrawModel(void);
	void SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData);// シェーダに値を送る
	void CollisionBullet(void);    // 弾との当たり判定

	// メンバ変数
	D3DXCOLOR m_color;        // カラー
	CCollision * m_pCollison; // 当たり判定
};

#endif
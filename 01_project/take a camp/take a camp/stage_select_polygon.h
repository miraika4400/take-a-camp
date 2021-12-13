//=============================================================================
//
// stage_select_polygonヘッダ [stage_select_polygon.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _STAGE_SELECT_POLYGON_H_
#define _STAGE_SELECT_POLYGON_H_

//*****************************
// インクルード
//*****************************
#include "scene.h"

//*****************************
// 前方宣言
//*****************************
class CScene2d;
class CDynamicTexture;

//=============================
// マクロ定義
//=============================
#define STAGE_SELECT_POLYGON_NUM 2

//*****************************
//クラス定義
//*****************************

//ゲージクラス
class CStageSelectPolygon : public CScene
{
public:

	//============
	// メンバ関数
	//============
	CStageSelectPolygon();
	~CStageSelectPolygon();

	// static
	static CStageSelectPolygon *Create(void); // クラス生成

	HRESULT Init(void); // 初期化
	void Uninit(void);  // 終了
	void Update(void);  // 更新
	void Draw(void);    // 描画

private:
	// メンバ変数
	const static std::vector<int> m_anDrawObjNum;         // 描画するオブジェクト番号
	CScene2d * m_apPolygon[STAGE_SELECT_POLYGON_NUM]; // 名前ポリゴン
	CDynamicTexture *m_pDynamicTex; // 動的テクスチャ
};

#endif
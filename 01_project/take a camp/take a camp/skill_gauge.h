//=============================================================================
//
// スキルゲージのヘッダ [skill_gauge.h]
// Author : 伊藤陽梧
//
//=============================================================================

//二重インクルード防止
#ifndef _SKILL_GAUGE_H_
#define _SKILL_GAUGE_H_

//=============================================================================
// インクルード
//=============================================================================
#include "main.h"
#include "billboard.h"

//=============================================================================
// 前方宣言
//=============================================================================
class CPolygon;

//=============================================================================
// クラス定義
//=============================================================================

// スキルゲージクラス
class CSkillgauge : public CBillboard
{
public:

	typedef enum
	{
		SKILLGAUGE_BG = 0,	// ゲージの背景
		SKILLGAUGE_STENCIL,	// ステンシル
		SKILLGAUGE_ICON,	// スキルゲージのアイコン
		SKILLGAUGE_MAX,		// タイプの最大数
	}SKILLGAUGE_TYPE;

	//============
	// メンバ関数
	//============
	CSkillgauge();
	~CSkillgauge();
	static CSkillgauge *Create(const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType); // クラス生成

	HRESULT Init(void); // 初期化
	void Uninit(void);	// 終了
	void Update(void);	// 更新
	void Draw(void);	// 描画

private:
	//============
	// メンバ変数
	//============
	SKILLGAUGE_TYPE m_SkillGaugeType;	// スキルゲージのタイプ
	D3DXVECTOR3 m_pos;		// 座標
	D3DXVECTOR3 m_size;		// 大きさ
	D3DXCOLOR m_col;		// 色
	int m_nPlayerNum;		// プレイヤーの番号
	float m_fGauge;

};

#endif
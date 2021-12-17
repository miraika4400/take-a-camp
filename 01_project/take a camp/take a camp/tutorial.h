//=============================================================================
//
// tutorialヘッダ [tutorial.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

//*****************************
//インクルード
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
// 前方宣言
//*****************************
class CMap;
class CPolygon;
class CText;

//*****************************
// マクロ定義
//*****************************
#define TUTORIAL_NUM (1) // チュートリアルページ数

//*****************************
//クラス定義
//*****************************

//チュートリアルクラス
class CTutorial : public CScene
{
public:
	enum TUTORIALPHASE
	{
		PHASE_START = 0,
		PHASE_MOVE,
		PHASE_PAINT,
		PHASE_OVERPAINT,
		PHASE_ATTACK,
		PHASE_FINALATTACK,
		PHASE_FINISH,
	};

	//============
	// メンバ関数
	//===========
	CTutorial();
	~CTutorial();
	static CTutorial *Create(void); // クラス生成

	HRESULT Init(void); // 初期化
	void Uninit(void);  // 終了
	void Update(void);  // 更新
	void Draw(void);    // 描画

	TUTORIALPHASE GetTutorialPhase(void) { return m_Tutorialphase; }	// チュートリアルの状態の取得
private:
	//============
	// メンバ関数
	//===========
	void CheckTaskClear(const int nCurTaskNum, const int nTargetNum, const int nPlayernum);
	void UpdateText(void);
	//============
	// メンバ変数
	//===========
	static LPDIRECT3DTEXTURE9 m_pTexture[TUTORIAL_NUM]; // テクスチャへのポインタ
	CMap *m_pMap;										// マップのポインタ
	CPolygon *m_pPolygon;								// ポリゴンのポインタ
	CText *m_pText;										// テキストのポインタ
	TUTORIALPHASE m_Tutorialphase;						// チュートリアルの状態
	bool m_bTask[MAX_PLAYER];
	bool m_bEntry[MAX_PLAYER];
	int m_nTextNum;
	bool m_bNextText;
	bool m_bTextEnd;
};

#endif
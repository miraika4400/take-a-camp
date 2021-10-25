//=============================================================================
//
// timeヘッダ [time.h]
// Author : 西潟 栞那汰
//
//=============================================================================

//二重インクルード防止
#ifndef _TIME_H_
#define _TIME_H_

//*****************************
//インクルード
//*****************************
#include "main.h"
#include "scene.h"

//*****************************
//前方宣言
//*****************************
class CNumber;

//*****************************
//マクロ定義
//*****************************
#define MAX_TIME_DIGIT 3  // タイムの最大桁数

#ifdef _DEBUG
#define TIME_UP 120			//時間制限*デバッグ
#else
#define TIME_UP 60			//時間制限*リリース
#endif

//*****************************
//クラス定義
//*****************************

//スコアクラス
class CTime : public CScene
{
public:
	//============
	// メンバ関数
	//============
	CTime();
	~CTime();

	static CTime *Create(void); // クラス生成

	HRESULT Init(void);// 初期化
	void Uninit(void); // 終了
	void Update(void); // 更新
	void Draw(void);   // 描画

private:
	//============
	// メンバ変数
	//============
	CNumber* m_apNumber[MAX_TIME_DIGIT]; // ナンバーポリゴン
	int m_nTime;										//タイム変数
	int m_nA;
};

#endif
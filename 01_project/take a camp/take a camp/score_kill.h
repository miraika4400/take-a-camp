//=============================================================================
//
// キルスコア表示処理 [score_kill.h]
// Author : 吉田 悠人
//
//=============================================================================

//二重インクルード防止
#ifndef _SCORE_KILL_H_
#define _SCORE_KILL_H_

//*****************************
//インクルード
//*****************************
#include "main.h"
#include "scene.h"
#include "game.h"

//*****************************
//前方宣言
//*****************************
class CNumber;

//*****************************
//マクロ定義
//*****************************
#define MAX_KILL_SCORE_DIGIT (3)  // スコアの最大桁数

//*****************************
//クラス定義
//*****************************

//スコアクラス
class CScoreKill : public CScene
{
public:
	//============
	// メンバ関数
	//============
	CScoreKill();
	~CScoreKill();

	static CScoreKill *Create(void); // クラス生成

	HRESULT Init(void);		// 初期化
	void	Uninit(void);	// 終了
	void	Update(void);	// 更新
	void	Draw(void);		// 描画
	void	SetKillScore(int nPlayer, int nScore);	// スコア

private:
	//============
	// メンバ変数
	//============
	CNumber* m_apNumber[MAX_PLAYER][MAX_KILL_SCORE_DIGIT];	// ナンバーポリゴン
	D3DXVECTOR3 m_pos[MAX_PLAYER];							// 位置
	D3DXCOLOR	m_col[MAX_PLAYER];							// カラー
	int			m_nPlayerNum;								// プレイヤー人数取得用変数
};

#endif
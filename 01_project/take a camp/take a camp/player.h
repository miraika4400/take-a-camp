//=============================================================================
//
// playerヘッダ [player.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************
// インクルード
//*****************************
#include "main.h"
#include "model.h"

//*****************************
// クラス定義
//*****************************

// 当たり判定クラス
class CPlayer : public CModel
{
public:
	//メンバ関数
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, int nPlayerNumber);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	void Move(void); // 移動処理

	// メンバ変数
	int m_nPlayerNumber; // プレイヤー番号
	bool m_bMove;        // 移動可否フラグ
};

#endif
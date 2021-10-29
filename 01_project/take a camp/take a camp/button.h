//=============================================================================
//
// ボタンの処理 [button.h]
// Author : 佐藤颯紀
//
//=============================================================================
#ifndef  _BUTTON_H_
#define  _BUTTON_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "scene2d.h"

//=============================================================================
// 前方宣言
//=============================================================================

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// クラス宣言
//=============================================================================
class CButton : public CScene2d
{
public:
	CButton();
	~CButton();

	static CButton *Create(D3DXVECTOR3 pos);	// 生成処理
	virtual HRESULT Init(void);				// 初期化処理
	virtual void Uninit(void);				// 終了処理
	virtual void Update(void);				// 更新処理
	virtual void Draw(void);				// 描画処理

	void SelectColor(void);					// 選択中の色の処理
	void NotSelectColor(void);				// 選択されてない時の色の処理
private:
	//=============================================================================
	// メンバ変数宣言
	//=============================================================================
	D3DXCOLOR m_color;		// 色
};
#endif // ! _BUTTON_H_

//=============================================================================
//
// テキストヘッダ [text.h]
// Author : 伊藤陽梧
//
//=============================================================================

//二重インクルード防止
#ifndef _TEXT_H_
#define _TEXT_H_

//=============================
// インクルード
//=============================
#include "main.h"
#include "scene.h"

//=============================
// 前方宣言
//=============================
class CPolygon;


//=============================
// クラス定義
//=============================

// テキストクラス
class CText : public CScene
{
public:
	enum FORMAT
	{
		ALIGN_LEFT = 0,
		ALIGN_CENTER,
		ALIGN_RIGHT
	};

	//============
	// メンバ関数
	//===========
	CText();
	~CText();
	static CText *Create(const D3DXVECTOR2 pos, const float fHeight, const float fWidth, const FORMAT format, const D3DCOLOR col); // クラス生成

	HRESULT Init(void); // 初期化
	void Uninit(void);  // 終了
	void Update(void);  // 更新
	void Draw(void);    // 描画

	void AddText(std::string str_text);	// テキストの追加
	void ClearText(void);				// 表示されているテキストの削除

	bool GetAllShowText(void) { return m_bAllShow; }	// テキストが全部表示されたかの取得

	void SetWindowRange(D3DXVECTOR2 WindowRange[2]);
	void SetFontSize(D3DXVECTOR2 FontSize);
	void SetColor(D3DXCOLOR color);
	void SetPos(D3DXVECTOR2 pos);

private:
	//============
	// メンバ変数
	//===========
	LPD3DXFONT m_pFont;				// フォント保存用変数
	D3DXVECTOR2 m_pos;				// 座標
	float m_fHeight;				// 文字のサイズ
	float m_fWidth;					// 文字列の幅の上限
	D3DCOLOR m_col;					// 色
	DWORD m_format;					// 整列方法変換用変数
	D3DXVECTOR2 m_WindowRange[2];	// 文字の表示範囲
	std::string m_str;				// 表示する文字列
	int m_nCountBite;				// 1バイトずつのカウント
	int m_nShowTime;				// 文字を見せる時間
	bool m_bAllShow;				// すべて表示されたかどうか
};

#endif
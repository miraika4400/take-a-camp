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
	static CText *Create(const D3DXVECTOR3 pos, const float fHeight, const float fWidth, const char* pStr, const FORMAT format, const D3DCOLOR col); // クラス生成

	HRESULT Init(void); // 初期化
	void Uninit(void);  // 終了
	void Update(void);  // 更新
	void Draw(void);    // 描画

private:
	//============
	// メンバ変数
	//===========
	LPD3DXFONT m_pFont;		//フォント保存用変数
	D3DXVECTOR3 m_pos;		//座標
	float m_fHeight;		//文字のサイズ
	float m_fWidth;			//文字列の幅の上限
	D3DCOLOR m_col;			//色
	DWORD m_format;			//整列方法変換用変数
	char m_fontName[128];	//フォントの名前
	char m_str[512];		//表示する文字列
};

#endif
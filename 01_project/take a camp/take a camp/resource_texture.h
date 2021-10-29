//=============================================================================
//
// textureヘッダ [texture.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************
//インクルード
//*****************************
#include "main.h"

//*****************************
//クラス定義
//*****************************

//テクスチャクラス
class CResourceTexture
{
public:
	// 列挙
	// テクスチャ種類
	typedef enum
	{
		TEXTURE_TITLE = 0,       // タイトル
		TEXTURE_TUTORIAL,        // チュートリアル
		TEXTURE_TUTORIAL_FLAG,   // チュートリアル(はたあげ)
		TEXTURE_TUTORIAL_FRY,    // チュートリアル(連打)
		TEXTURE_TUTORIAL_REMEMBER,// チュートリアル(記憶)
		TEXTURE_PARTICLE_SQUARE,    // パーティクル*箱
		TEXTURE_PARTICLE_TEARS,  // パーティクル*涙
		TEXTURE_PARTICLE_CIRCLE, // パーティクル*円
		TEXTURE_NUMBER,          // ナンバー
		TEXTURE_FRAME,           // 枠
		TEXTURE_CROSS_MARK,      // ×マーク
		TEXTURE_NEEDLE,          // とげ穴
		TEXTURE_SHADOW,			 // 影
		TEXTURE_BUTTON_START,	 // タイトルのボタン(スタート)
		TEXTYRE_BUTTON_TUTORIAL, // タイトルのボタン(チュートリアル)
		TEXTURE_MAX              // テクスチャ数
	}TEXTURE_TYPE;
	// テクスチャ種類
	typedef enum
	{
		TECTURE_CUBE_SLY,        // キューブテクスチャ(空)
		TEXTURE_CUBE_MAX              // テクスチャ数
	}TEXTURE_CUBE_TYPE;

	// メンバ関数
	static CResourceTexture * Create(void);                  // クラス生成
	static void Release(void);                               // クラス破棄
	static LPDIRECT3DTEXTURE9 GetTexture(TEXTURE_TYPE type); // テクスチャの取得処理*引数：取得したいテクスチャ
	static LPDIRECT3DCUBETEXTURE9 GetCubeTexture(TEXTURE_CUBE_TYPE type); // テクスチャの取得処理*引数：取得したいテクスチャ
private:
	CResourceTexture();//隠しコンストラクタ
public:
	~CResourceTexture();

private:
	void Load(void); // テクスチャ読み込み
	void Unload(void); // テクスチャ破棄

	// メンバ変数
	static const std::string m_aTexPath[TEXTURE_MAX]; // テクスチャのパス
	static const std::string m_aCubeTexPath[TEXTURE_CUBE_MAX]; // テクスチャのパス
	static CResourceTexture *m_pSingleTex;			  // テクスチャクラスのポインタ*シングルトン用
	LPDIRECT3DTEXTURE9 m_apTexture[TEXTURE_MAX];      // テクスチャのポインタ
	LPDIRECT3DCUBETEXTURE9 m_apCubeTexture[TEXTURE_CUBE_MAX];      // テクスチャのポインタ
};

#endif
////////////////////////////////////////////////////
//
//    scene3dクラスの処理[scene3d.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "resource_texture.h"
#include "renderer.h"
#include "manager.h"
#include <assert.h>

//******************************
// マクロ定義
//******************************

//******************************
// 静的メンバ変数宣言
//******************************
CResourceTexture *CResourceTexture::m_pSingleTex = NULL; // テクスチャクラスのポインタ*シングルトン用
// テクスチャのパス
const std::string CResourceTexture::m_aTexPath[CResourceTexture::TEXTURE_MAX]
{
	"./data/Textures/00_title.png",					 // タイトル背景
	"./data/Textures/frame/knight_flame.png",		 // リザルト(ナイトの背景)
	"./data/Textures/frame/lancer_flame.png",	     // リザルト(ランサーの背景)
	"./data/Textures/frame/wizard_flame.png",		 // リザルト(ウィザードの背景)
	"./data/Textures/frame/thief_flame.png",		 // リザルト(シーフの背景)
	"./data/Textures/frame/magician_flame.png",		 // リザルト(奇術師の背景)
	"./data/Textures/frame/archer_flame.png",	     // リザルト(アーチャーの背景)
	"./data/Textures/kill.png",						 // リザルトのキルUI
	"./data/Textures/tile.png",						 // リザルトのタイルUI
	"./data/Textures/effect/kirakira.png",		  	 // パーティクル*ダイヤ
	"./data/Textures/effect/00_wave.png",			 // パーティクル*波紋
	"./data/Textures/effect/shoot.png",				 // パーティクル*円
	"./data/Textures/effect/arrow.png",				 // パーティクル*矢
	"./data/Textures/effect/trump.png",				 // パーティクル*トランプ
	"./data/Textures/effect/shoot.png",				 // パーティクル*弓軌道
	"./data/Textures/effect/meteor.png",			 // パーティクル*爆発
	"./data/Textures/effect/meteor_shadow.png",		 // パーティクル*爆発
	"./data/Textures/effect/slash.png",				 // 斬撃エフェクト
	"./data/Textures/guruguru.png",					 // ぐるぐる
	"./data/Textures/number.png",					 // ナンバー
	"./data/Textures/frame.png",					 // 枠
	"./data/Textures/cross_mark.png",				 // バツマーク
	"./data/Textures/needle_hole.png",				 // とげ穴
	"./data/Textures/move_tile.png",				 // 移動タイルのテクスチャ
	"./data/Textures/warp_tile.png",				 // ワープタイルのテクスチャ
	"./data/Textures/shadow.png",					 // 影
	"./data/Textures/player_number.png",			 // プレイヤー番号
	"./data/Textures/none_logo.png",				 // NONE
	"./data/Textures/joypad.png",					 // コントローラーアイコン
	"./data/Textures/keyboars.png",					 // キーボードアイコン
	"./data/Textures/chara_select_frame.png",		 // キャラ選択背景
	"./data/Textures/00_gamestart.png",				 // タイトルのボタン(スタート)
	"./data/Textures/00_tutorial.png",				 // タイトルのボタン(チュートリアル)
	"./data/Textures/tile_effect_00.png",			 // 最大塗段階時のエフェクト
	"./data/Textures/attack_area.png",				 // 攻撃範囲
	"./data/Textures/clock_frame.png",		         // 時計の枠
	"./data/Textures/clock_hands.png",				 // 時計の針
	"./data/Textures/Toon_Shadow.png",				 // トゥーンシャドウ
	"./data/Textures/tile_effect_charge.png",		 // タイルのチャージ
	"./data/Textures/icon_bg.png",					 // アイコンの背景
	"./data/Textures/sword_icon.png",				 // 剣アイコン
	"./data/Textures/stage_name.png",				 // ステージ名
	"./data/Textures/stage_polygon_bg.png",			 // ステージ選択背景
	"./data/Textures/00_ready.png",					 // ready
	"./data/Textures/01_go!!.png",					 // go
	"./data/Textures/00_finish.png",				 // finish
	"./data/Textures/00_nanbyou.png",				 // 残り何秒
	"./data/Textures/lance_icon.png",				 // 槍アイコン
	"./data/Textures/arrow_icon.png",				 // 矢アイコン
	"./data/Textures/magicstick_icon.png",			 // 魔法杖アイコン
	"./data/Textures/knife_icon.png",				 // ナイフアイコン
	"./data/Textures/stick_icon.png",				 // 杖アイコン
	"./data/Textures/effect_explosion.png",			 // リザルトエクスプロージョン
	"./data/Textures/color_gauge_ui.png",			 // 色のゲージの枠
    "./data/Textures/attack_area/00_knight_attack.png",     // 攻撃範囲
    "./data/Textures/attack_area/01_lancer_attack.png",     // 攻撃範囲
    "./data/Textures/attack_area/02_wizard_attack.png",     // 攻撃範囲
    "./data/Textures/attack_area/03_thief_attack.png",      // 攻撃範囲
    "./data/Textures/attack_area/04_magician_attack.png",	// 攻撃範囲
    "./data/Textures/attack_area/05_archer_attack.png",     // 攻撃範囲
    "./data/Textures/status/00_beginner.png",      // 初心者
    "./data/Textures/status/01_intermediate.png",  // 中級者
    "./data/Textures/status/02_advanced.png",      // 上級者
    "./data/Textures/status/03_short.png",         // 近距離
    "./data/Textures/status/04_medium.png",        // 中距離
    "./data/Textures/status/05_long.png",          // 遠距離
    "./data/Textures/navi_attack_area.png",		   // 攻撃範囲誘導UI
	"./data/Textures/alltext.png",			// チュートリアルで表示するテキスト
	"./data/Textures/check.png",			// チェック
    "./data/Textures/character_name/00_kisi.png",      // 
    "./data/Textures/character_name/01_yari.png",      // 
    "./data/Textures/character_name/02_mahou.png",     // 
    "./data/Textures/character_name/03_touzoku.png",   // 
    "./data/Textures/character_name/04_kijutusi.png",  // 
    "./data/Textures/character_name/05_kariudo.png",   // 
	"./data/Textures/tutorial_paint.png",			   // 塗り説明用
	"./data/Textures/tutorial_attack.png",			   // 攻撃説明用
	"./data/Textures/tutorial_finalattack.png",		   // 必殺技説明用
};

// テクスチャのパス
const std::string CResourceTexture::m_aCubeTexPath[CResourceTexture::TEXTURE_CUBE_MAX]
{
	"./data/Textures/cube_sky.dds",     // キューブテクスチャ空
};

//===================================
// コンストラクタ
//===================================
CResourceTexture::CResourceTexture()
{
	memset(&m_apTexture, 0, sizeof(m_apTexture));
}

//===================================
// デストラクタ
//===================================
CResourceTexture::~CResourceTexture()
{
}

//=============================================================================
//モデルクラスのクリエイト処理
//=============================================================================
CResourceTexture * CResourceTexture::Create(void)
{
	if (m_pSingleTex == NULL)
	{
		// メモリ確保
		m_pSingleTex = new CResourceTexture;

		if (m_pSingleTex != NULL)
		{
			// メモリ確保に成功したとき
			m_pSingleTex->Load();
		}
		else
		{
			// メモリ確保に失敗したとき
			return NULL;
		}
	}

	return m_pSingleTex;
}

//===================================
// クラスの破棄
//===================================
void CResourceTexture::Release(void)
{
	if (m_pSingleTex != NULL)
	{
		// テクスチャ破棄
		m_pSingleTex->Unload();
		// メモリの破棄
		delete m_pSingleTex;
		m_pSingleTex = NULL;
	}
}

//===================================
// テクスチャ取得
//===================================
LPDIRECT3DTEXTURE9 CResourceTexture::GetTexture(TEXTURE_TYPE type)
{
	if (m_pSingleTex != NULL)
	{
		return m_pSingleTex->m_apTexture[type];
	}
	else
	{
		return NULL;
	}
}

LPDIRECT3DCUBETEXTURE9 CResourceTexture::GetCubeTexture(TEXTURE_CUBE_TYPE type)
{
	if (m_pSingleTex != NULL)
	{
		return m_pSingleTex->m_apCubeTexture[type];
	}
	else
	{
		return NULL;
	}
}

//===================================
// テクスチャ読み込み
//===================================
void CResourceTexture::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// テクスチャ数分ループ
	for (int nCnt = 0; nCnt < TEXTURE_MAX; nCnt++)
	{
		// テクスチャの生成
		D3DXCreateTextureFromFile(pDevice, m_aTexPath[nCnt].c_str(), &m_apTexture[nCnt]);
	}

	// テクスチャ数分ループ
	for (int nCnt = 0; nCnt < TEXTURE_CUBE_MAX; nCnt++)
	{
		// テクスチャの生成
		D3DXCreateCubeTextureFromFile(pDevice, m_aCubeTexPath[nCnt].c_str(), &m_apCubeTexture[nCnt]);
	}
}

//===================================
// テクスチャ破棄
//===================================
void CResourceTexture::Unload(void)
{
	// テクスチャ数分ループ
	for (int nCnt = 0; nCnt < TEXTURE_MAX; nCnt++)
	{
		if (m_apTexture[nCnt] != NULL)
		{
			// テクスチャの破棄
			m_apTexture[nCnt]->Release();
			m_apTexture[nCnt] = NULL;
		}
	}
}
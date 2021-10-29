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
	"./data/Textures/title.png",        // タイトル背景
	"./data/Textures/tutorial_0.png",   // チュートリアル
    "./data/Textures/tutorial_1.png",   // チュートリアル
    "./data/Textures/tutorial_2.png",   // チュートリアル
    "./data/Textures/tutorial_3.png",   // チュートリアル
	"./data/Textures/effect/kirakira.png",		// パーティクル*四角
	"./data/Textures/Tears.png",        // パーティクル*涙
	"./data/Textures/particle004.png",  // パーティクル*円
	"./data/Textures/number.png",       // ナンバー
	"./data/Textures/frame.png",        // 枠
	"./data/Textures/cross_mark.png",   // バツマーク
	"./data/Textures/needle_hole.png",  // とげ穴
	"./data/Textures/shadow.png",		// 影
	"./data/Textures/suma.png",		// タイトルのボタン(スタート)
	"./data/Textures/ka-bi-.jpg",		// タイトルのボタン(チュートリアル)
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
	int n = 0;
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

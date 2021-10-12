////////////////////////////////////////////////////
//
//    color_managerクラスの処理[color_manager.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "color_manager.h"

//*****************************
// マクロ定義
//*****************************
#define COLOR_DATA_PATH "data/Text/color_data.txt"

//*****************************
// 静的メンバ変数宣言
//*****************************
// メンバ変数
CColorManager * CColorManager::m_pInstance = NULL;

//******************************
// コンストラクタ
//******************************
CColorManager::CColorManager()
{
	m_aColorData.clear();
}

//******************************
// デストラクタ
//******************************
CColorManager::~CColorManager()
{
}

//******************************
// クラス生成
//******************************
CColorManager * CColorManager::Create(void)
{
	if (m_pInstance == NULL)
	{
		// メモリの確保
		m_pInstance = new CColorManager;

		// 初期化
		m_pInstance->Init();
	}

	return m_pInstance;
}

//******************************
// 初期化処理
//******************************
HRESULT CColorManager::Init(void)
{
	// ベクターの初期化
	m_aColorData.clear();

	// カラーデータの読み込み
	LoadText();

	return S_OK;
}

//******************************
// 終了処理
//******************************
void CColorManager::Uninit(void)
{
}

//******************************
// 破棄処理
//******************************
void CColorManager::Release(void)
{
	m_pInstance->Uninit();
	delete m_pInstance;
}

//******************************
// テキストデータの読み込み
//******************************
void CColorManager::LoadText(void)
{
	// ファイルオープン
	FILE*pFile = NULL;
	pFile = fopen(COLOR_DATA_PATH, "r");

	if (pFile != NULL)
	{
		// テキストファイルの解析

		// 特定の文字判定用
		char chChar[256] = {};
		fscanf(pFile, "%s", chChar);

		// "COLOR_NUM"読み込むまでループ
		while (strcmp(chChar, "COLOR_NUM") != 0)
		{
			fscanf(pFile, "%s", chChar);
		}

		int nColorElementNum;

		// = カラー数
		fscanf(pFile, "%*s %d", &nColorElementNum);
		// 要素数分確保
		m_aColorData.resize(nColorElementNum);

		// "END"読み込むまでループ
		while (strcmp(chChar, "END") != 0)
		{
			// "COLOR_DATA"読み込むまでループ
			while (strcmp(chChar, "COLOR_DATA") != 0)
			{
				fscanf(pFile, "%s", chChar);
			}

			int nIndex = 0;

			// 配列番号
			fscanf(pFile, "%*s %*c %d", &nIndex);

			for (int nCnColStep = 0; nCnColStep < COLOR_STEP_NUM; nCnColStep++)
			{// 色段階の格納
				fscanf(pFile, "%*s %*s %f %f %f %f", &m_aColorData[nIndex].aCol[nCnColStep].r, 
					                                 &m_aColorData[nIndex].aCol[nCnColStep].g, 
					                                 &m_aColorData[nIndex].aCol[nCnColStep].b, 
					                                 &m_aColorData[nIndex].aCol[nCnColStep].a);
			}
			// アイコンカラー					  	 
			fscanf(pFile, "%*s %*s %f %f %f %f", &m_aColorData[nIndex].iconColor.r,
				                                 &m_aColorData[nIndex].iconColor.g,
				                                 &m_aColorData[nIndex].iconColor.b,
				                                 &m_aColorData[nIndex].iconColor.a);

			fscanf(pFile, "%*s %s", chChar);
		}

		// ファイルクローズ
		fclose(pFile);
	}
}

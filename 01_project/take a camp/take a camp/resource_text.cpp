////////////////////////////////////////////////////
//
//    resource_model_hierarchyクラスの処理[resource_model_hierarchy.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "resource_text.h"
#include "renderer.h"
#include "manager.h"
#include <map>
#include "text.h"
#include <fstream>

//******************************
// マクロ定義
//******************************
#define TUTORIAL_FILENAME ("data/Text/tutorial.txt")

//******************************
// 静的メンバ変数宣言
//******************************
CResourceText *CResourceText::m_pSingle = nullptr; // テキストポインタ*シングルトン用

//===================================
// コンストラクタ
//===================================
CResourceText::CResourceText()
{
	memset(&m_pSingle, 0, sizeof(m_pSingle));
}

//===================================
// デストラクタ
//===================================
CResourceText::~CResourceText()
{
}

//=============================================================================
//モデルクラスのクリエイト処理
//=============================================================================
CResourceText * CResourceText::Create(void)
{
	if (m_pSingle == NULL)
	{
		// メモリ確保
		m_pSingle = new CResourceText;

		if (m_pSingle != NULL)
		{
			// メモリ確保に成功したとき
			m_pSingle->Load();
		}
		else
		{
			// メモリ確保に失敗したとき
			return NULL;
		}
	}

	return m_pSingle;
}

//===================================
// クラスの破棄
//===================================
void CResourceText::Release(void)
{
	if (m_pSingle != NULL)
	{
		// テクスチャ破棄
		m_pSingle->Unload();
		// メモリの破棄
		delete m_pSingle;
		m_pSingle = NULL;
	}
}

//===================================
// テクスチャ読み込み
//===================================
void CResourceText::Load(void)
{
	// ファイルポイント
	FILE *pFile = NULL;

	// 変数宣言
	char cReadText[256];	// 文字として読み取り用
	char cHeadText[256];	// 文字の判別用
	char cDie[256];			// 使わない文字
	int nTextNum = 0;		// タイプのナンバー
	std::map<int, std::string> Map;

	std::ifstream ifs(TUTORIAL_FILENAME);
	std::string str;
	if (ifs)
	{
		// SCRIPTの文字が見つかるまで
		while (str.find("SCRIPT") != 0)
		{
			getline(ifs, str);
		}
		// strがSCRIPTの時
		if (str.find("SCRIPT") == 0)
		{
			// cHeadTextがEND_SCRIPTになるまで
			while (str.find("END_SCRIPT") != 0)
			{
				getline(ifs, str);
				// cHeadTextがEFFECT_DATASETの時
				if (str.find("TEXT_DATASET") == 0)
				{
					// cHeadTextがEND_EFFECT_DATASETになるまで
					while (str.find("END_TEXT_DATASET") != 0)
					{
						getline(ifs, str);

						if (str.find("SS") == 0)
						{
							Map[nTextNum] = str;
						}

						if (str.find("ENTER") == 0)
						{
							Map[nTextNum] = str;
						}
						nTextNum++;
					}
				}
			}
		}

		// ファイルを閉じる
		fclose(pFile);
	}

	//======================================================================================
	//// チュートリアルテキストファイルを開く
	//pFile = fopen(TUTORIAL_FILENAME, "r");

	//// 開けたら
	//if (pFile != NULL)
	//{
	//	// SCRIPTの文字が見つかるまで
	//	while (strcmp(cHeadText, "SCRIPT") != 0)
	//	{
	//		// テキストからcReadText分文字を受け取る
	//		fgets(cReadText, sizeof(cReadText), pFile);

	//		// cReedTextをcHeadTextに格納
	//		sscanf(cReadText, "%s", &cHeadText);
	//	}
	//	// cHeadTextがSCRIPTの時
	//	if (strcmp(cHeadText, "SCRIPT") == 0)
	//	{
	//		// cHeadTextがEND_SCRIPTになるまで
	//		while (strcmp(cHeadText, "END_SCRIPT") != 0)
	//		{
	//			fgets(cReadText, sizeof(cReadText), pFile);
	//			sscanf(cReadText, "%s", &cHeadText);

	//			// cHeadTextがEFFECT_DATASETの時
	//			if (strcmp(cHeadText, "TEXT_DATASET") == 0)
	//			{
	//				// cHeadTextがEND_EFFECT_DATASETになるまで
	//				while (strcmp(cHeadText, "END_TEXT_DATASET") != 0)
	//				{
	//					fgets(cReadText, sizeof(cReadText), pFile);
	//					sscanf(cReadText, "%s", &cHeadText);

	//					if (strcmp(cHeadText, "SS") == 0)
	//					{
	//						sscanf(cReadText, "%s %s %s", &cDie, &cDie, Map[nTextNum].c_str());
	//					}

	//					if (strcmp(cHeadText, "ENTER") == 0)
	//					{
	//						sscanf(cReadText, "%s %s %s", &cDie, &cDie, Map[nTextNum].c_str());
	//					}


	//					nTextNum++;
	//				}
	//			}
	//		}
	//	}

	//	// ファイルを閉じる
	//	fclose(pFile);
	//}
	//// 開けなかったら
	//else
	//{
	//	printf("開けれませんでした\n");
	//}
	//======================================================================================



	//for (int nCount = 0; nCount < 100; nCount++)
	//{
	//	Map[0] = "aiueo";
	//}

	//CText::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 600.0f, 0.0f), 25.0f, 10.0f, Map[0].c_str(), CText::ALIGN_LEFT, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));

}

//===================================
// 破棄
//===================================
void CResourceText::Unload(void)
{
}
////////////////////////////////////////////////////
//
//    resource_characterクラスの処理[resource_character.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "resource_character.h"

//******************************
// マクロ定義
//******************************

//******************************
// 静的メンバ変数宣言
//******************************
// インスタンス
CResourceCharacter *CResourceCharacter::m_pInstance = NULL;
// キャラクターラベルリスト
const std::vector<CResourceCharacter::LabelData> m_aLabelList =
{
	{ "KNIGHT", CResourceModelHierarchy::MODEL_HIERARCHY_KNIGHT },
	{ "LANCER", CResourceModelHierarchy::MODEL_HIERARCHY_LANCER },
	{ "WIZARD", CResourceModelHierarchy::MODEL_HIERARCHY_WIZARD },
}; 
// キャラクターデータのテキストのパス
const std::string CResourceCharacter::m_aCharacterDataTxtPath[CResourceCharacter::CHARACTER_MAX] =
{
	"data/Text/caracter/CharacterData_Knight.txt",
	"data/Text/caracter/CharacterData_Knight.txt",
	"data/Text/caracter/CharacterData_Knight.txt",
};

//===================================
// コンストラクタ
//===================================
CResourceCharacter::CResourceCharacter()
{
	m_aCharacterData.clear();
}

//===================================
// デストラクタ
//===================================
CResourceCharacter::~CResourceCharacter()
{
}

//=============================================================================
//モデルクラスのクリエイト処理
//=============================================================================
CResourceCharacter * CResourceCharacter::Create(void)
{
	if (m_pInstance == NULL)
	{
		// メモリ確保
		m_pInstance = new CResourceCharacter;

		if (m_pInstance != NULL)
		{
			// メモリ確保に成功したとき
			m_pInstance->Load();
		}
		else
		{
			// メモリ確保に失敗したとき
			return NULL;
		}
	}

	return m_pInstance;
}

//===================================
// クラスの破棄
//===================================
void CResourceCharacter::Release(void)
{
	if (m_pInstance != NULL)
	{
		// メモリの破棄
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

//===================================
// テクスチャ読み込み
//===================================
void CResourceCharacter::Load(void)
{
	//ファイルポインタ
	FILE*	pFile = NULL;

	for (int nCntText = 0; nCntText < CHARACTER_MAX; nCntText++)
	{
		//ファイル読み込み
		pFile = fopen(m_aCharacterDataTxtPath[nCntText].c_str(), "r");

		if (pFile == NULL)
		{
			continue;
		}
		
		// ファイルクローズ
		fclose(pFile);
	}
}

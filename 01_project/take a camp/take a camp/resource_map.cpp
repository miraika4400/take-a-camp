//=============================================================================
//
// マップ読み込みクラス[resource_map.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "resource_map.h"
#include "tile.h"
#include "player.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define SQUARE_SIZE (20)	//１マス縦横のサイズ

//=============================================================================
// 静的メンバー変数
//=============================================================================
char* CMapManager::m_pFileName[MAP_TYPE_MAX] =
{
	"data/Text/stage02.csv" ,
	"",
	"",
	""
};
CMapManager *CMapManager::m_pMapBasis = NULL;
//=============================================================================
// コンストラクタ
//=============================================================================
CMapManager::CMapManager()
{
	memset(&m_MapData, 0, sizeof(MAP_DATA));
}

//=============================================================================
// デストラクタ
//=============================================================================
CMapManager::~CMapManager()
{
}

//=============================================================================
// クラス生成
//=============================================================================
CMapManager * CMapManager::Create(void)
{
	// NULLチェック
	if (m_pMapBasis == NULL)
	{
		//メモリ確保
		m_pMapBasis = new CMapManager;

		if (m_pMapBasis != NULL)
		{
			// メモリ確保成功
			m_pMapBasis->Load();
		}
		else
		{
			// メモリ確保失敗
			return NULL;
		}
	}

	return m_pMapBasis;
}

//=============================================================================
// クラス破棄
//=============================================================================
void CMapManager::Release(void)
{
	if (m_pMapBasis != NULL)
	{
		// メモリの破棄
		delete m_pMapBasis;
		m_pMapBasis = NULL;
	}

}

//=============================================================================
// マップデータゲッター生成
//=============================================================================
CMapManager::MAP_DATA CMapManager::GetMapData(MAP_TYPE MapData)
{
	if (m_pMapBasis != NULL)
	{
		return m_pMapBasis->m_MapData[MapData];
	}
	else
	{
		return{};
	}
	
}

//=============================================================================
// ロード関数
//=============================================================================
void CMapManager::Load(void)
{
	for (int nMap = 0; nMap < MAP_TYPE_MAX; nMap++)
	{
		//ファイルポインタ
		FILE*	pFile = NULL;
		//読み込み用データ
		char cFileString[258];
		//文字認識
		int nFileText;
		//列、行
		int nCol, nRow;
		//ブロック数
		int nBlock;
		//初期化
		pFile = NULL;
		nCol = 1;
		nRow = 0;
		nBlock = 0;
		memset(cFileString, 0, sizeof(cFileString));

		//ファイル読み込み
		fopen_s(&pFile, m_pFileName[nMap], "r");

		if (pFile != NULL)
		{

			//生成位置読み込み
			fscanf_s(pFile, "POS,%f,%f,%f", &m_MapData[nMap].m_pos.x, &m_MapData[nMap].m_pos.y, &m_MapData[nMap].m_pos.z);
			//ヘッダー読み飛ばし
			while (fgetc(pFile) != '\n');

			while (1)
			{
				while (1)
				{
					nFileText = fgetc(pFile);

					//末尾ならループを抜ける。
					if (nFileText == EOF)
					{
						goto out;
					}
					//カンマか改行でなければ、文字としてつなげる
					if (nFileText != ',' && nFileText != '\n')
					{
						strcat_s(cFileString, (const char*)&nFileText);
					}
					//カンマか改行ならループ抜ける。
					else
					{
						break;
					}
				}
				//文字列読み込み
				switch (atoi(cFileString))
				{
				case BLOCK_TYPE_NONE:
					m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NONE;
					break;
				case BLOCK_TYPE_1P_START:
					m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_1P_START;
					break;
				case BLOCK_TYPE_2P_START:
					m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_2P_START;
					break;
				case BLOCK_TYPE_3P_START:
					m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_3P_START;
					break;
				case BLOCK_TYPE_4P_START:
					m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_4P_START;
					break;
				case BLOCK_TYPE_BLOCK:
					m_MapData[nMap].BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_BLOCK;
					break;
				}
				//バッファの初期化
				memset(cFileString, 0, sizeof(cFileString));
				//列数を足す
				nCol++;

				//もし読み込んだ文字が改行だったら列数を初期化して行数を増やす
				if (nFileText == '\n')
				{
					//行数保存
					m_MapData[nMap].BlockData[nRow].nStageSizeX = nCol;
					//行数初期化
					nCol = 1;
					//列の進行
					nRow++;
				}

			}

		out:								//末尾ならここに跳ぶ
			m_MapData[nMap].nStageSizeY = nRow;	//ブロック数を保存
			fclose(pFile);					//ファイルを閉じる
		}
	}

}

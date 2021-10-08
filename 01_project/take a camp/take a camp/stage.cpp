//=============================================================================
//
// ステージ [stage.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "stage.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define SQUARE_SIZE (50)	//１マス縦横のサイズ

//=============================================================================
// 静的メンバー変数
//=============================================================================
char* CStage::m_pFileName = "data/Text/stage.csv";
CStage::MAP_DATA CStage::m_pMapData = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CStage::CStage()
{
	m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
}

//=============================================================================
// デストラクタ
//=============================================================================
CStage::~CStage()
{
}

//=============================================================================
// ロード関数
//=============================================================================
void CStage::Load(void)
{
	//ファイルポインタ
	FILE*	pFile;
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
	fopen_s(&pFile, m_pFileName, "r");

	if (pFile != NULL)
	{
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
				m_pMapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NONE;
				break;
			case BLOCK_TYPE_:
				m_pMapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_;
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
				m_pMapData.BlockData[nRow].nStageSizeX = nCol;
				//行数初期化
				nCol = 1;
				//列の進行
				nRow++;
			}

		}
	
	out:								//末尾ならここに跳ぶ
		m_pMapData.nStageSizeY = nRow;	//ブロック数を保存
		fclose(pFile);					//ファイルを閉じる
	
	}

}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CStage::Init(void)
{

	//マップ生成
	MapCreate();

	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CStage::Uninit(void)
{
}

//=============================================================================
// 描画関数
//=============================================================================
void CStage::Draw(void)
{
}

//=============================================================================
// 更新関数
//=============================================================================
void CStage::Update(void)
{
}

//=============================================================================
// マップ生成関数
//=============================================================================
void CStage::MapCreate(void)
{
	//マップデータがあるか
	if (&m_pMapData != NULL)
	{
		for (int nBlockY = 0; nBlockY < m_pMapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_pMapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				//マス目のタイプ取得
				switch (m_pMapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case BLOCK_TYPE::BLOCK_TYPE_NONE:	//なし

					break;
				case BLOCK_TYPE::BLOCK_TYPE_:		//仮置きタイル
					CModel::Create(D3DXVECTOR3((float)SQUARE_SIZE * -nBlockX, 0.0f, (float)SQUARE_SIZE * nBlockY) + m_pos, CResourceModel::MODEL_GENERAL_BOX, D3DXVECTOR3(50.0f, 50.0f, 50.0f));
					break;
				}
			}
		}
	}
}
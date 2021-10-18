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
#include "tile.h"
#include "player.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define SQUARE_SIZE (20)	//１マス縦横のサイズ

//=============================================================================
// 静的メンバー変数
//=============================================================================
char* CStage::m_pFileName = "data/Text/stage.csv";
CStage::MAP_DATA CStage::m_MapData = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CStage::CStage()
{
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
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_NONE;
				break;
			case BLOCK_TYPE_1P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_1P_START;
				break;
			case BLOCK_TYPE_2P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_2P_START;
				break;
			case BLOCK_TYPE_3P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_3P_START;
				break;
			case BLOCK_TYPE_4P_START:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_4P_START;
				break;
			case BLOCK_TYPE_BLOCK:
				m_MapData.BlockData[nRow].nBlockType[nCol] = BLOCK_TYPE_BLOCK;
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
				m_MapData.BlockData[nRow].nStageSizeX = nCol;
				//行数初期化
				nCol = 1;
				//列の進行
				nRow++;
			}

		}
	
	out:								//末尾ならここに跳ぶ
		m_MapData.nStageSizeY = nRow;	//ブロック数を保存
		fclose(pFile);					//ファイルを閉じる
	
	}

}

//=============================================================================
// 生成処理関数
//=============================================================================
CStage * CStage::Create(D3DXVECTOR3 pos)
{
	// メモリの確保
	CStage *pStage;
	pStage = new CStage;

	pStage->m_MapData.m_pos = pos;	//位置セット
	pStage->Init();

	return pStage;
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
	//オブジェクトの破棄
	Release();
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
	if (&m_MapData != NULL)
	{
		for (int nBlockY = 0; nBlockY < m_MapData.nStageSizeY; nBlockY++)
		{
			for (int nBlockX = 0; nBlockX < m_MapData.BlockData[nBlockY].nStageSizeX; nBlockX++)
			{
				//マス目のタイプ取得
				switch (m_MapData.BlockData[nBlockY].nBlockType[nBlockX])
				{
				case BLOCK_TYPE::BLOCK_TYPE_NONE:	//なし
					break;
				case BLOCK_TYPE::BLOCK_TYPE_1P_START:	//1Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f,0.0f,0.0f), 0);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case BLOCK_TYPE::BLOCK_TYPE_2P_START:	//2Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 1);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case BLOCK_TYPE::BLOCK_TYPE_3P_START:	//3Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 2);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case BLOCK_TYPE::BLOCK_TYPE_4P_START:	//4Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case BLOCK_TYPE::BLOCK_TYPE_BLOCK:	//仮置きタイル
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				}
			}
		}
	}
}
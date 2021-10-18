//=============================================================================
//
// マップクラス [map.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "map.h"
#include "tile.h"
#include "player.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CMap::CMap()
{
	memset(&m_MapData, 0, sizeof(CMapManager::MAP_DATA));
}

//=============================================================================
// デストラクタ
//=============================================================================
CMap::~CMap()
{
}

//=============================================================================
// 生成処理関数
//=============================================================================
CMap * CMap::Create(CMapManager::MAP_TYPE MapType)
{
	// メモリの確保
	CMap *pMap;
	pMap = new CMap;
	if (pMap != NULL)
	{
		//マップ情報取得
		pMap->SetMapData(CMapManager::GetMapData(MapType));
		//初期化処理
		pMap->Init();
	}

	return pMap;
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CMap::Init(void)
{
	//マップ生成
	MapCreate();
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CMap::Uninit(void)
{
	//オブジェクトの破棄
	Release();
}

//=============================================================================
// 更新関数
//=============================================================================
void CMap::Update(void)
{
}

//=============================================================================
// 描画関数
//=============================================================================
void CMap::Draw(void)
{

}
//=============================================================================
// マップ生成関数
//=============================================================================
void CMap::MapCreate(void)
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
				case CMapManager::BLOCK_TYPE_NONE:	//なし
					break;
				case CMapManager::BLOCK_TYPE_1P_START:	//1Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 0);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_2P_START:	//2Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 1);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_3P_START:	//3Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 2);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_4P_START:	//4Pスタート位置
					CPlayer::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, 0.0f, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos, 3);
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				case CMapManager::BLOCK_TYPE_BLOCK:	//仮置きタイル
					CTile::Create(D3DXVECTOR3(TILE_ONE_SIDE * -nBlockX, -TILE_SIZE_Y / 2, TILE_ONE_SIDE * nBlockY) + m_MapData.m_pos);
					break;
				}
			}
		}
	}
}

void CMap::SetMapData(CMapManager::MAP_DATA MapData)
{
	m_MapData = MapData;
}

CMapManager::MAP_DATA CMap::GetMapData(void)
{
	return m_MapData;
}

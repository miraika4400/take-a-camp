//=============================================================================
//
// ステージ [stage.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _STAGE_H_
#define _STAGE_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_STAGE_SIZE_X	(50)	//最大ブロック数
#define MAX_STAGE_SIZE_Y	(50)	//最大ステージサイズ
#define MAX_STAGE_COUNT		(3)		//最大ステージ数

//=============================================================================
// クラス定義
//=============================================================================
class CStage : public CScene
{
public:
	typedef struct //一行のブロック情報
	{
		int			nBlockType[MAX_STAGE_SIZE_X];	//ブロックデータ
		int			nStageSizeX;					//その行のブロック数
	}BLOCK_DATA;

	typedef struct	//ステージ情報
	{
		BLOCK_DATA	BlockData[MAX_STAGE_SIZE_Y];	//ブロック
		int			nStageSizeY;					//ブロックの列
	}MAP_DATA;

	typedef enum	//タイルの種類
	{
		BLOCK_TYPE_NONE = 0,	//なし
		BLOCK_TYPE_,			//仮置き
	}BLOCK_TYPE;

	//関数定義
	CStage();
	~CStage();
	static void	Load(void);
	static CStage *Create(D3DXVECTOR3 pos);
	HRESULT Init(void);
	void	Uninit(void);
	void	Draw(void);
	void	Update(void);
	void	MapCreate(void);							//マップの生成
	void	SetPos(D3DXVECTOR3 pos) { m_pos = pos; }	//位置セッター
	MAP_DATA GetMapData(void) { return m_pMapData; }	//マップ情報ゲッター
private:
	static char*		m_pFileName;	// ファイルネーム
	static MAP_DATA		m_pMapData;		// ステージの情報
	D3DXVECTOR3			m_pos;			// 位置		
};
#endif
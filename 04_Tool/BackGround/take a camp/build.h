//=============================================================================
//
// 背景オブジェクトの処理 [building.h]
// Author : 西潟栞那汰
//
//=============================================================================
#ifndef _BUILD_H_
#define _BUILD_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "model.h"

//=============================================================================
// 前方宣言
//=============================================================================

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
// クラス宣言
//=============================================================================
class CBuild : public CModel
{
public:
	//建物タイプ
	typedef enum
	{
		BUILD_TYPE_TREE = 0,//
		BUILD_TYPE_MATO,		//
		BUILD_TYPE_BUKIKAKE,
		BUILD_TYPE_CHEST,
		BUILD_TYPE_TARU,
		BUILD_TYPE_GAITOU,
		BUILD_TYPE_HATA,
		BUILD_TYPE_SAKU,
		BUILD_TYPE_ENOGU,
		BUILD_TYPE_ENPITU,
		BUILD_TYPE_MAGCUP,
		BUILD_TYPE_MAX
	}BUILD_TYPE;
	
	typedef enum
	{
		BUILD_TRUE=0,
		BUILD_FALSE
	}BUILD_BOOL;

	CBuild();	// コンストラクタ
	~CBuild();	// デストラクタ

	static CBuild * Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, BUILD_TYPE type, BUILD_BOOL bBuild);	// 生成処理

	HRESULT Init(void);		// 初期化処理
	void Uninit(void);		// 終了処理
	void Update(void);		// 更新処理
	void Draw(void);		// 描画処理

	void MoveUpdate(void);	//移動更新
	void RotUpdate(void);	//角度更新

	void Save(void);
	static void Load(void);

	void SetBuildType(BUILD_TYPE BuildType) { m_BuildType = BuildType; }
	BUILD_TYPE GetBuildTypel(void) { return m_BuildType; }
	void SetBuildBool(BUILD_BOOL bBuild) { m_BuildBool = bBuild; }
	BUILD_BOOL GetBuildBool(void) { return m_BuildBool; }
private:
	//=============================================================================
	// メンバ変数宣言
	//=============================================================================
	D3DXVECTOR3 m_size;		//大きさ
	D3DXVECTOR3 m_rot;		//角度
	D3DXVECTOR3 m_move;		//移動

	BUILD_TYPE m_BuildType;			//
	BUILD_BOOL m_BuildBool;			

	bool m_bUp;				//上限判定
	bool m_bGet;			//取得フラグ

};

#endif // !_ITEM_H_

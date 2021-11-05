////////////////////////////////////////////////////
//
//    攻撃範囲クラスの処理[attack_area.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "attack_area.h"
#include "tile.h"
#include "resource_texture.h"

//******************************
// マクロ定義
//******************************
#define SIZE (D3DXVECTOR3(TILE_ONE_SIDE -2, 0.0f, TILE_ONE_SIDE - 2))

//******************************
// コンストラクタ
//******************************
CAttackArea::CAttackArea()
{
	m_bDraw = false;
}

//******************************
// デストラクタ
//******************************
CAttackArea::~CAttackArea()
{
}

//******************************
// クラス生成
//******************************
CAttackArea * CAttackArea::Create(D3DXVECTOR3 pos)
{
	// クラス生成
	CAttackArea * pInstace = new CAttackArea;
	// 初期化処理
	pInstace->Init();
	// 座標の設定
	pInstace->SetPos(pos);

	return pInstace;
}

//******************************
// 初期化処理
//******************************
HRESULT CAttackArea::Init(void)
{
	// 初期化
	CScene3d::Init();

	// テクスチャの割り当て
	BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_FRAME));

	// サイズの設定
	SetSize(SIZE);

	// 描画フラグ
	m_bDraw = false;

	SetPriority(OBJTYPE_EFFECT);
	return S_OK;
}

//******************************
// 描画処理
//******************************
void CAttackArea::Draw(void)
{
	if (!m_bDraw)
	{
		return;
	}

	CScene3d::Draw();
}

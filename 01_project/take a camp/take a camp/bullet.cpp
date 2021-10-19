//=============================================================================
//
// 弾の処理 [Bullet.cpp]
// Author : 佐藤颯紀
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "Bullet.h"
#include "manager.h"
#include "player.h"
#include "collision.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define MODEL_SIZE D3DXVECTOR3(0.5f, 0.5f, 0.5f)	// サイズ
#define BULLET_LIFE		(20)	// 弾のライフ
#define COLLISION_SIZE (D3DXVECTOR3(10.0f,10.0f,10.0f))	// 当たり判定の大きさ
#define BULLET_ONE_SIDE 20.0f
//=============================================================================
// コンストラクタ
//=============================================================================
CBullet::CBullet() :CModel(OBJTYPE_BULLET)
{
	m_move = VEC3_ZERO;		// 移動量
	m_size = VEC3_ZERO;		// サイズ
	m_nLife = 0;			// ライフ
	m_fSpeed = 0.0f;		// 速さ
	m_pCollision = NULL;	// 当たり判定
}
//=============================================================================
// デストラクタ
//=============================================================================
CBullet::~CBullet()
{

}
//=============================================================================
// 生成処理
//=============================================================================
CBullet * CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nPlayerNum)
{
	CBullet *pBullet = NULL;

	// メモリの確保
	pBullet = new CBullet;

	// 初期化処理呼び出し
	pBullet->Init();

	pBullet->SetPos(pos);

	pBullet->m_move = move;

	pBullet->m_nPlayerNum = nPlayerNum;

	// オブジェクトタイプ
	pBullet->SetPriority(OBJTYPE_BULLET);

	return pBullet;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CBullet::Init(void)
{
	// 初期化処理
	CModel::Init();

	// サイズの設定
	SetSize(MODEL_SIZE);

	// モデル割り当て
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_BULLET01));
	
	// ライフ
	m_nLife = BULLET_LIFE;
	
	// フラグの初期化
	m_bHitOld = false;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CBullet::Uninit()
{
	// 終了処理
	CModel::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CBullet::Update()
{
	// 位置の取得
	D3DXVECTOR3 BulletPos = GetPos();

	if (m_pCollision == NULL)
	{
		m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(BulletPos.x, BulletPos.y + BULLET_ONE_SIDE / 2, BulletPos.z), BULLET_ONE_SIDE / 2);
	}
	else
	{
		m_pCollision->SetPos(D3DXVECTOR3(BulletPos.x, BulletPos.y + BULLET_ONE_SIDE / 2, BulletPos.z));
	}
	// プレイヤーとの当たり判定
	CollisionPlayer();

	// 位置に移動量を加算する
	BulletPos += m_move;

	// ライフを毎フレームごと減らしていく
	m_nLife--;

	// 位置の設定
	SetPos(BulletPos);

	// ライフが０になったら
	if (m_nLife == 0)
	{
		// 終了処理
		Uninit();
	}

}

//=============================================================================
// 描画処理
//=============================================================================
void CBullet::Draw()
{
	// 描画処理
	CModel::Draw();
}

//=============================================================================
// 当たり判定の処理
//=============================================================================
void CBullet::CollisionPlayer(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() != m_nPlayerNum)
		{
			if (CCollision::CollisionSphere(m_pCollision, pPlayer->GetCollision()))
			{
				if (!m_bHitOld)
				{
					// 死亡状態にする
					pPlayer->Death();
				}

				// ヒットフラグの保存*当たってない
				m_bHitOld = true;

				return;
			}
		}
			pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	// ヒットフラグの保存*当たってる
	m_bHitOld = false;
}
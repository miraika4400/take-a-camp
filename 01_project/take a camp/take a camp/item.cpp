////////////////////////////////////////////////////
//
//    アイテムクラスの処理[item.cpp]
//    Author:西潟栞那汰
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "item.h"
#include "manager.h"
#include "player.h"
#include	"collision.h"

//*****************************
// マクロ定義
//*****************************
#define MODEL_SIZE D3DXVECTOR3( 0.6f, 0.6f, 0.6f)
#define ITEM_ONE_SIDE (10.0f)

//******************************
// コンストラクタ
//******************************
CItem::CItem() : CModel(OBJTYPE_ITEM)
{
	m_rot = D3DXVECTOR3(0.0f, 0.05f, 0.0f);//角度
	m_move = D3DXVECTOR3(0.0f, 0.1f, 0.0f);//移動

	m_pCollision = NULL;	//コリジョンのポインタ
	m_pPlayer = NULL;		//プレイヤーのポインタ

	m_bUp = false;			//上限判定
	m_bDeath = false;		//死亡フラグ
}

//******************************
// デストラクタ
//******************************
CItem::~CItem()
{
}

//******************************
// クラス生成
//******************************
CItem * CItem::Create(D3DXVECTOR3 pos)
{
	//メモリの確保
	CItem *pItem;
	pItem = new CItem;

	//初期化処理
	pItem->Init();

	//位置セット
	pItem->SetPos(pos);

	return pItem;
}

//******************************
// 初期化処理
//******************************
HRESULT CItem::Init(void)
{
	//モデル初期化
	CModel::Init();

	// モデル割り当て
	BindModel(CResourceModel::GetModel(CResourceModel::MODEL_PLAYER01));

	// モデルのサイズの設定
	SetSize(MODEL_SIZE);

	return E_NOTIMPL;
}

//******************************
// 終了処理
//******************************
void CItem::Uninit(void)
{
	//コリジョンの終了処理
	if (m_pCollision != NULL)
	{
		m_pCollision->ReConnection();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}

	//モデルの終了処理
	CModel::Uninit();
}

//******************************
// 更新処理
//******************************
void CItem::Update(void)
{
	//位置の取得
	D3DXVECTOR3 ItemPos = GetPos();

	if (m_pCollision == NULL)
	{
		m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(ItemPos.x, ItemPos.y + ITEM_ONE_SIDE / 2, ItemPos.z), ITEM_ONE_SIDE / 2);
	}
	else
	{
		m_pCollision->SetPos(D3DXVECTOR3(ItemPos.x, ItemPos.y + ITEM_ONE_SIDE / 2, ItemPos.z));
	}
	// プレイヤーとの当たり判定
	CollisionItem();

	//上下の移動
	MoveUpdate();
	//回転
	RotUpdate();

	if (m_bDeath == true)
	{
		Uninit();
	}
}

//******************************
// 描画処理
//******************************
void CItem::Draw(void)
{
	CModel::Draw();
}

//******************************
// 移動の更新処理
//******************************
void CItem::MoveUpdate(void)
{
	//位置の取得
	D3DXVECTOR3 ItemPos = GetPos();

	if (m_bUp == false)//上限に到達していないなら
	{
		//位置に移動量を加算
		ItemPos += m_move;
	}
	else
	{
		//位置に移動量を減算
		ItemPos -= m_move;
	}

	//位置の再設定
	SetPos(ItemPos);

	//上限到達
	if (ItemPos.y >= 10.0f)
	{
		m_bUp = true;
	}
	//下限到達
	else if (ItemPos.y <= 3.0f)
	{
		m_bUp = false;
	}
}

//******************************
// 回転の更新処理
//******************************
void CItem::RotUpdate(void)
{
	//角度の取得
	D3DXVECTOR3 ItemRot = GetRot();

	//角度の加算
	ItemRot += m_rot;

	//角度の設定
	SetRot(ItemRot);
}

void CItem::CollisionItem(void)
{
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);

	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() != m_nPlayerNum)
		{
			if (CCollision::CollisionSphere(m_pCollision, pPlayer->GetCollision()))
			{

				m_bDeath = true;
				pPlayer->SetItemState(CPlayer::ITEM_STATE_DASH);
				return;
			}
		}
		pPlayer = (CPlayer*)pPlayer->GetNext();
	}
}

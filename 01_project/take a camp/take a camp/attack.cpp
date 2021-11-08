//=============================================================================
//
// 攻撃種類 [attack.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack.h"
#include "tile.h"
#include "resource_attack.h"
#include "player.h"
#include "bullet.h"
#include "scene3d.h"
#include "attack_area.h"
#include "color_tile.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackBased::CAttackBased() :CScene(OBJTYPE_SYSTEM)
{
	//初期化処理
	m_nAttackType = CAttackManager::ATTACK_TYPE_1;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	memset(&m_AttackSquare, 0, sizeof(CAttackManager::ATTACK_SQUARE_DATA));
	m_bAttack = false;
	m_pPlayer = NULL;
	m_nLevel = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackBased::~CAttackBased()
{
}

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT CAttackBased::Init(void)
{
	//攻撃タイプセット
	for (int nLevel = 0; nLevel < MAX_ATTACK_LEVEL; nLevel++)
	{
		m_AttackSquare[nLevel] = CAttackManager::GetAttack(m_nAttackType, nLevel);

	}
	return S_OK;
}

//=============================================================================
// 終了関数
//=============================================================================
void CAttackBased::Uninit(void)
{
	//オブジェクトの破棄
	Release();
}

//=============================================================================
// 更新関数
//=============================================================================
void CAttackBased::Update(void)
{
	AttackCreate();
}

//=============================================================================
// 描画関数
//=============================================================================
void CAttackBased::Draw(void)
{
}

//=============================================================================
// 攻撃タイプセッター関数
//=============================================================================
void CAttackBased::SetAttackType(CAttackManager::ATTACK_TYPE AttackType)
{
	m_nAttackType = AttackType;
}

//=============================================================================
// 攻撃タイプゲッター関数
//=============================================================================
CAttackManager::ATTACK_TYPE CAttackBased::GetAttackType(void)
{
	return m_nAttackType;
}

//=============================================================================
// 攻撃マスデータゲッター関数
//=============================================================================
void CAttackBased::SetAttackSquare(CAttackManager::ATTACK_SQUARE_DATA AttackSquare)
{
	m_AttackSquare[m_nLevel] = AttackSquare;
}

//=============================================================================
// 攻撃マスデータゲッター関数
//=============================================================================
CAttackManager::ATTACK_SQUARE_DATA CAttackBased::GetAttackSquare()
{
	return m_AttackSquare[m_nLevel];
}

//=============================================================================
// 位置セッター関数
//=============================================================================
void CAttackBased::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//=============================================================================
// 位置ゲッター関数
//=============================================================================
D3DXVECTOR3 CAttackBased::GetPos(void)
{
	return m_pos;
}

//=============================================================================
// 向きセッター関数
//=============================================================================
void CAttackBased::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//=============================================================================
// 向きゲッター関数
//=============================================================================
D3DXVECTOR3 CAttackBased::GetRot(void)
{
	return m_rot;
}

//=============================================================================
// 攻撃フラグセッター関数
//=============================================================================
void CAttackBased::SetAttackFlag(bool bAttack)
{
	m_bAttack = bAttack;
}

//=============================================================================
// 攻撃スイッチ関数
//=============================================================================
void CAttackBased::AttackSwitch(int nLevel)
{
	//攻撃されていなかったら
	if (!m_bAttack)
	{
		//フラグオン
		SetAttackFlag(true);
		//位置取得
		SetPos(m_pPlayer->GetPos());
		//向き取得
		SetRot(m_pPlayer->GetRotDest());
		//レベル取得
		m_nLevel = nLevel;
	}
}

//=============================================================================
// 攻撃フラグゲッター関数
//=============================================================================
bool CAttackBased::GetAttackFlag(void)
{
	return m_bAttack;
}

//=============================================================================
// プレイヤーポインタゲッター関数
//=============================================================================
void CAttackBased::SetPlayer(CPlayer * pPlayer)
{
	m_pPlayer = pPlayer;
}

//=============================================================================
// プレイヤーポインタゲッター関数
//=============================================================================
CPlayer * CAttackBased::GetPlayer(void)
{
	return m_pPlayer;
}

//=============================================================================
// 攻撃関数
//=============================================================================
void CAttackBased::Attack(int AttackType)
{
	for (int nAttack = 0; nAttack < m_AttackSquare[m_nLevel].nMaxHitRange; nAttack++)
	{
		//タイプが一致しているか
		if (m_AttackSquare[m_nLevel].SquareData[nAttack].RangeType == AttackType + (int)CAttackManager::ATTACK_RANGE_HIT_1)
		{
			//行列計算
			D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//攻撃位置
			D3DXVECTOR3 AttackPos = m_AttackSquare[m_nLevel].SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(m_rot.y)*AttackPos.x) + (sinf(m_rot.y)*AttackPos.z));
			CreatePos.y = 1 * AttackPos.y;
			CreatePos.z = ((-sinf(m_rot.y)*AttackPos.x) + (cosf(m_rot.y)*AttackPos.z));
			//当たり判定生成
			CBullet::Create(CreatePos + m_pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_pPlayer->GetPlayerNumber());
		}

	}
}


//=============================================================================
// 攻撃範囲の枠の色を変える処理
// Akuthor: 増澤 未来
//=============================================================================
void CAttackBased::ChangeFrameColor()
{
	//攻撃フラグが立っているか
	if (GetAttackFlag())
	{
		//タイプが一致しているか
		for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
		{
			//行列計算
			D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//攻撃位置
			D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
			CreatePos.x = ((cosf(GetRot().y)*AttackPos.x) + (sinf(GetRot().y)*AttackPos.z));
			CreatePos.y = 1 * AttackPos.y;
			CreatePos.z = ((-sinf(GetRot().y)*AttackPos.x) + (cosf(GetRot().y)*AttackPos.z));

			CTile*pTile = CTile::GetHitTile(CreatePos + GetPos());
			if (pTile != NULL)
			{
				pTile->GetAttackAreaPolygon()->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
				pTile->GetAttackAreaPolygon()->SetPos(pTile->GetPos() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
				pTile->GetAttackAreaPolygon()->SetDrawFlag(true);
			}
		}
	}
	else
	{
		CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPlayer()->GetPos());
		if (pHitTile != NULL)
		{
			m_nLevel = pHitTile->GetStepNum() - 1;
			//タイプが一致しているか
			for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
			{
				//行列計算
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//攻撃位置
				D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
				CreatePos.x = ((cosf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (sinf(GetPlayer()->GetRotDest().y)*AttackPos.z));
				CreatePos.y = 1 * AttackPos.y;
				CreatePos.z = ((-sinf(GetPlayer()->GetRotDest().y)*AttackPos.x) + (cosf(GetPlayer()->GetRotDest().y)*AttackPos.z));

				CTile*pTile = CTile::GetHitTile(CreatePos + GetPlayer()->GetPos());
				if (pTile != NULL)
				{
					pTile->GetAttackAreaPolygon()->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					pTile->GetAttackAreaPolygon()->SetPos(pTile->GetPos() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
					pTile->GetAttackAreaPolygon()->SetDrawFlag(true);
				}
			}
		}
	}
}

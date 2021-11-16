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
// マクロ定義
//=============================================================================
#define CHARGE_COUNT (60*1)	//チャージにかかる時間

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackBased::CAttackBased() :CScene(OBJTYPE_SYSTEM)
{
	//初期化処理
	m_nAttackType	= CAttackManager::ATTACK_TYPE_1;
	m_pos			= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	memset(&m_AttackSquare, 0, sizeof(m_AttackSquare));
	m_pPlayer		= NULL;
	m_nLevel		= 0;
	m_nChargeCount	= 0;
	ZeroMemory(&m_apAttackArea, sizeof(m_apAttackArea));
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
	int nMaxAttackNum = 0;
	
	//攻撃タイプセット
	for (int nLevel = 0; nLevel < MAX_ATTACK_LEVEL; nLevel++)
	{
		m_AttackSquare[nLevel] = CAttackManager::GetAttack(m_nAttackType, nLevel);
		if (nMaxAttackNum < m_AttackSquare[nLevel].nMaxHitRange)
		{
			nMaxAttackNum = m_AttackSquare[nLevel].nMaxHitRange;
		}
	}

	for(int nCntArea = 0 ; nCntArea < nMaxAttackNum; nCntArea++)
	{
		m_apAttackArea[nCntArea] = CAttackArea::Create();
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
	//ステートごとの処理
	switch (m_AttackState)
	{
	case ATTACK_STATE_NORMAL:	//通常状態
		
		//数値の初期化
		if (m_nLevel != 0)
		{
			m_nLevel = 0;
		}
		
		//プレイヤーが死んでいるとき
		if (m_pPlayer->GetState() == CPlayer::PLAYER_STATE_DEATH)
		{
			// チャージをしているプレイヤーの取得
			CColorTile * pColorTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

			while (pColorTile != NULL)
			{
				//チャージをしているタイル取得
				if (pColorTile->GetColorTileState() == CColorTile::COLOR_TILE_CHARGE
					&&pColorTile->GetLasthitPlayerNum() == m_pPlayer->GetPlayerNumber())
				{
					//タイルステート
					pColorTile->SetColorTileState(CColorTile::COLOR_TILE_NORMAL);
					return;
				}
				// リストを進める
				pColorTile = (CColorTile*)pColorTile->GetNext();
			}

		}
		break;

	case ATTACK_STATE_CHARGE:	//チャージ状態
		// チャージ処理
		Charge();
		break;

	case ATTACK_STATE_ATTACK:	//攻撃状態
		// 攻撃生成処理
		AttackCreate();
		break;

	//それ以外の状態
	default:
		m_AttackState = ATTACK_STATE_NORMAL;
		break;
	}

}

//=============================================================================
// 描画関数
//=============================================================================
void CAttackBased::Draw(void)
{
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
// チャージフラグ処理関数
//=============================================================================
void CAttackBased::ChargeFlag(int nMaxLevel)
{
	//現在の状態が通常の場合
	if (m_AttackState == ATTACK_STATE_NORMAL)
	{
		//チャージ状態に移行
		m_AttackState = ATTACK_STATE_CHARGE;
		//レベルの最大値の取得
		m_nMaxLevel = nMaxLevel;
	}
}

//=============================================================================
// チャージ処理関数
// Akuthor: 吉田 悠人
//=============================================================================
void CAttackBased::Charge(void)
{
	//カウントアップ
	m_nChargeCount++;

	//一定に達しているか
	if (m_nChargeCount>CHARGE_COUNT)
	{
		//現在のレベルが限界のレベルより低い
		if (m_nLevel<m_nMaxLevel)
		{
			m_nLevel++;
		}
		//カウント初期化
		m_nChargeCount = 0;
	}

}

//=============================================================================
// 攻撃スイッチ関数
//=============================================================================
void CAttackBased::AttackSwitch(void)
{
	//攻撃をしていなかったら
	if (m_AttackState == ATTACK_STATE_CHARGE)
	{
		//攻撃状態に移行
		m_AttackState = ATTACK_STATE_ATTACK;
		//位置取得
		SetPos(m_pPlayer->GetPos());
		//向き取得
		SetRot(m_pPlayer->GetRotDest());
		//カウント初期化
		m_nChargeCount = 0;
	
		// チャージをしているプレイヤーの取得
		CColorTile * pColorTile = (CColorTile*)GetTop(OBJTYPE_COLOR_TILE);

		while (pColorTile != NULL)
		{
			//チャージをしているタイル取得
			if (pColorTile->GetColorTileState() == CColorTile::COLOR_TILE_CHARGE
				&&pColorTile->GetLasthitPlayerNum()== m_pPlayer->GetPlayerNumber())
			{
				//塗り段階の消費
				pColorTile->ColorDown(m_nLevel+1);
				//タイルステート
				pColorTile->SetColorTileState(CColorTile::COLOR_TILE_NORMAL);
				return;
			}
			// リストを進める
			pColorTile = (CColorTile*)pColorTile->GetNext();
		}


	}
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
// 攻撃範囲の枠の色を変える処理
// Akuthor: 増澤 未来
//=============================================================================
void CAttackBased::VisualizationAttackArea(int nAttackType)
{
	//攻撃フラグが立っているか
	if (m_AttackState == ATTACK_STATE_ATTACK)
	{
		//タイプが一致しているか
		for (int nAttack = 0; nAttack < GetAttackSquare().nMaxHitRange; nAttack++)
		{
			//タイプが一致しているか
			if (m_AttackSquare[m_nLevel].SquareData[nAttack].RangeType >= nAttackType + (int)CAttackManager::ATTACK_RANGE_HIT_1)
			{
				//行列計算
				D3DXVECTOR3 CreatePos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				//攻撃位置
				D3DXVECTOR3 AttackPos = GetAttackSquare().SquareData[nAttack].AttackPos * TILE_ONE_SIDE;
				CreatePos.x = ((cosf(GetRot().y)*AttackPos.x) + (sinf(GetRot().y)*AttackPos.z));
				CreatePos.y = 1 * AttackPos.y;
				CreatePos.z = ((-sinf(GetRot().y)*AttackPos.x) + (cosf(GetRot().y)*AttackPos.z));

				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					m_apAttackArea[nAttack]->SetPos(CreatePos + m_pos + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
					m_apAttackArea[nAttack]->SetDrawFlag(true);
				}
			}
			else
			{
				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetDrawFlag(false);
				}
			}
		}
	}
	else
	{
		CColorTile*pHitTile = CColorTile::GetHitColorTile(GetPlayer()->GetPosDest());
		if (pHitTile != NULL)
		{
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

				if (m_apAttackArea[nAttack] != NULL)
				{
					m_apAttackArea[nAttack]->SetColor(GET_COLORMANAGER->GetIconColor(GetPlayer()->GetColorNumber()));
					m_apAttackArea[nAttack]->SetPos(CreatePos + GetPlayer()->GetPosDest() + D3DXVECTOR3(0.0f, 10.0f, 0.0f));
					m_apAttackArea[nAttack]->SetDrawFlag(true);
				}

			}
		}
	}
}

//=============================================================================
// 攻撃範囲ポリゴンのリセット
// Akuthor: 増澤 未来
//=============================================================================
void CAttackBased::ResetAttackArea(void)
{
	for (int nCntArea = 0; nCntArea < MAX_ATTACK_AREA_NUM; nCntArea++)
	{
		if (m_apAttackArea[nCntArea] != NULL)
		{
			m_apAttackArea[nCntArea]->SetDrawFlag(false);
			m_apAttackArea[nCntArea]->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_apAttackArea[nCntArea]->SetSize(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		}
	}
}

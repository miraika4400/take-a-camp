////////////////////////////////////////////////////
//
//    playerクラスの処理[player.cpp]
//    Author:増澤 未来
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "player.h"
#include "manager.h"
#include "renderer.h"
#include "keyboard.h"
#include "joypad.h"
#include "collision.h"
#include "debug_log.h"
#include "act_range.h"
#include "tile.h"
#include "number_array.h"
#include "color_manager.h"
#include "bullet.h"
#include "attack.h"
#include "attack_1.h"
#include "resource_shader.h"
#include "light.h"
#include "camera_base.h"
#include "motion.h"
#include "resource_texture.h"

//*****************************
// マクロ定義
//*****************************
#define HIERARCHY_TEXT_PATH1 "data/Text/hierarchy/knight.txt"   // 階層構造テキストのパス
#define MOVE_DIST (TILE_ONE_SIDE)	// 移動距離
#define MOVE_FRAME 15				// 移動速度
#define COLLISION_RADIUS 18.0f
#define MODL_COLOR D3DXCOLOR(0.3f,0.3f,0.3f,1.0f)
//#define MODEL_SIZE D3DXVECTOR3( 0.3f, 0.3f, 0.3f)
#define MODEL_SIZE D3DXVECTOR3( 1.0f, 1.0f, 1.0f)
#define RESPAWN_MAX_COUNT (60*5)	// リスポーンまでの最大カウント
#define INVINCIBLE_COUNT (60*2)		// 無敵時間
#define ROTDEST_PREVIOUS 0.0f		// 前方向き
#define ROTDEST_AFTER 	180.0f		// 後方向き
#define ROTDEST_LEFT 270.0f			// 左向き
#define ROTDEST_RIGHT 90.0f			// 右向き
#define ROT_SPEED 0.3f				// 回転速度
#define ROT_FACING_01 180			// 回転の基準
#define ROT_FACING_02 360			// 回転向き
#define RIM_POWER     0.5f          // リムライトの強さ
#define DASH_FRAME      300
#define DASH_MOVE_FRAME  MOVE_FRAME*0.8f
#define STICK_DECISION_RANGE (32768.0f / 1.001f)	// スティックの上下左右の判定する範囲

//*****************************
// 静的メンバ変数宣言
//*****************************
int CPlayer::m_anControllKey[4][CPlayer::KEY_MAX] =
{
	{ DIK_W,DIK_S,DIK_A,DIK_D,DIK_E },
	{ DIK_UP,DIK_DOWN,DIK_LEFT,DIK_RIGHT,DIK_NUMPAD1 },
	{ DIK_U,DIK_J,DIK_H,DIK_K,DIK_I },
	{ DIK_NUMPAD8,DIK_NUMPAD5,DIK_NUMPAD4,DIK_NUMPAD6,DIK_NUMPAD9 }
};
CResourceModel::Model CPlayer::m_model[MAX_PARTS_NUM] = {};
int CPlayer::m_nPartsNum = 0;
char CPlayer::m_achAnimPath[MOTION_MAX][64]
{
	{ "data/Text/motion/run.txt" },         // 歩きアニメーション
};

//******************************
// コンストラクタ
//******************************
CPlayer::CPlayer() :CModelHierarchy(OBJTYPE_PLAYER)
{
	m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_nRespawnCount = 0;
	m_nPlayerNumber = 0;
	m_nInvincibleCount = 0;
	m_bMove = false;
	m_bInvincible = false;
	m_PlayerState = PLAYER_STATE_NORMAL;
	m_pCollision = NULL;
	m_nColor = 0;
	m_pActRange = NULL;
	memset(&m_Move, 0, sizeof(D3DXVECTOR3));
	memset(&m_RespawnPos, 0, sizeof(D3DXVECTOR3));
	m_MoveCount = 0;
	m_pAttack = NULL;
	memset(&m_apMotion, 0, sizeof(m_apMotion));
	m_ItemState = ITEM_STATE_NONE;
	m_nMoveframe = 0;				// 移動速度
	m_nDashCnt = 1;		//速度アップカウント
}

//******************************
// デストラクタ
//******************************
CPlayer::~CPlayer()
{
}

//******************************
// テクスチャのロード
//******************************
HRESULT CPlayer::Load(void)
{
	// モデルの読み込み
	LoadModels(HIERARCHY_TEXT_PATH1, &m_model[0], &m_nPartsNum);

	return S_OK;
}

//******************************
// テクスチャのアンロード
//******************************
void CPlayer::Unload(void)
{
	for (int nCnt = 0; nCnt < m_nPartsNum; nCnt++)
	{
		//メッシュの破棄
		if (m_model[nCnt].pMesh != NULL)
		{
			m_model[nCnt].pMesh->Release();
			m_model[nCnt].pMesh = NULL;
		}
		//マテリアルの破棄
		if (m_model[nCnt].pBuffMat != NULL)
		{
			m_model[nCnt].pBuffMat->Release();
			m_model[nCnt].pBuffMat = NULL;
		}
	}
}

//******************************
// クラス生成
//******************************
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nPlayerNumber)
{
	// メモリの確保
	CPlayer *pPlayer;
	pPlayer = new CPlayer;

	// initで使うから先に代入
	pPlayer->m_nPlayerNumber = nPlayerNumber;

	// 初期化
	pPlayer->Init();

	// 各値の代入・セット
	pPlayer->SetPos(pos);
	pPlayer->SetRot(rot);
	pPlayer->SetPriority(OBJTYPE_PLAYER); // オブジェクトタイプ
	pPlayer->m_Move = pos;
	pPlayer->m_RespawnPos = pos;
	CNumberArray::Create(0, pos, D3DXVECTOR3(10.0f, 10.0f, 0.0f), GET_COLORMANAGER->GetIconColor(pPlayer->m_nColor), pPlayer->m_nColor);

	//攻撃用クラス生成
	pPlayer->m_pAttack = CAttack1::Create(pPlayer);

	//移動範囲クラスの生成
	pPlayer->m_pActRange = CActRange::Create(pPlayer);

	return pPlayer;
}

//******************************
// 初期化処理
//******************************
HRESULT CPlayer::Init(void)
{
	if (FAILED(CModelHierarchy::Init(m_nPartsNum, &m_model[0], HIERARCHY_TEXT_PATH1)))
	{
		return E_FAIL;
	}

	// 移動フラグの初期化
	m_bMove = true;
	// 無敵フラグの初期化
	m_bInvincible = false;
	//プレイヤーステータス初期化
	m_PlayerState = PLAYER_STATE_NORMAL;
	//色設定
	m_color = MODL_COLOR;

	////////////////////////////////////////
	// 仮	
	m_nColor = m_nPlayerNumber;
	CColorManager::GetColorManager()->SetUsePlayerNum(m_nPlayerNumber, m_nColor);
	////////////////////////////////////////

	// モデルのサイズの設定
	SetSize(MODEL_SIZE);

	//CNumberArray::Create(10, GetPos() + D3DXVECTOR3(0.0f, 100.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);	

	//for (int nCntAnim = 0; nCntAnim < MOTION_MAX; nCntAnim++)
	//{
	//	m_apMotion[nCntAnim] = CMotion::Create(GetPartsNum(), m_achAnimPath[nCntAnim], GetModelData());
	//}

	//m_apMotion[MOTION_WALK]->SetActiveMotion(true);


	m_rotDest = D3DXVECTOR3(0.0f, D3DXToRadian(0.0f), 0.0f);

	// アイテムステート
	m_ItemState = ITEM_STATE_NONE;

	m_nMoveframe = MOVE_FRAME;				// 移動速度
	m_nDashCnt = 1;		//速度アップカウント
	return S_OK;
}

//******************************
// 終了処理
//******************************
void CPlayer::Uninit(void)
{
	if (m_pCollision != NULL)
	{
		m_pCollision->ReConnection();
		m_pCollision->Uninit();
		delete m_pCollision;
		m_pCollision = NULL;
	}

	CModelHierarchy::Uninit();
}

//******************************
// 更新処理
//******************************
void CPlayer::Update(void)
{
	switch (m_PlayerState)
	{
	case PLAYER_STATE_NORMAL:	//通常状態
		// 移動処理
		Move();
		//無敵処理
		Invincible();
		// 当たり判定の位置
		if (m_pCollision == NULL)
		{
			m_pCollision = CCollision::CreateSphere(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z), COLLISION_RADIUS / 2);
		}
		else
		{
			m_pCollision->SetPos(D3DXVECTOR3(GetPos().x, GetPos().y + COLLISION_RADIUS / 2, GetPos().z));
		}
		break;
	case PLAYER_STATE_DEATH:	//死亡状態
		//リスポーン処理
		Respawn();
		break;
	}

	// 弾の処理
	Bullet();

	// 向きの取得
	D3DXVECTOR3 rot = GetRot();

	while (m_rotDest.y - rot.y > D3DXToRadian(ROT_FACING_01))
	{
		m_rotDest.y -= D3DXToRadian(ROT_FACING_02);
	}

	while (m_rotDest.y - rot.y < D3DXToRadian(-ROT_FACING_01))
	{
		m_rotDest.y += D3DXToRadian(ROT_FACING_02);
	}

	// 目標の向きに変える
	rot += (m_rotDest - rot)*ROT_SPEED;

	// 向き設定
	SetRot(rot);

	// 
#ifdef _DEBUG
	// キーボードの取得
	if (m_nPlayerNumber == 0)
	{
		CInputKeyboard * pKey = CManager::GetKeyboard();
		if (pKey->GetKeyPress(DIK_1))
		{
			Death();
		}
		if (pKey->GetKeyPress(DIK_2))
		{
			m_pAttack->AttackSwitch(0);
		}
		if (pKey->GetKeyPress(DIK_3))
		{
			m_pAttack->AttackSwitch(1);
		}
	}

#endif // _DEBUG

}

//******************************
// 描画処理
//******************************
void CPlayer::Draw(void)
{
	// 色の設定
	for (int nCntParts = 0; nCntParts < GetPartsNum(); nCntParts++)
	{
		for (int nCntMat = 0; nCntMat < GetModelData()[nCntParts].nNumMat; nCntMat++)
		{
			D3DXMATERIAL* mat = (D3DXMATERIAL*)GetModelData()[nCntParts].pBuffMat->GetBufferPointer();
			mat[nCntMat].MatD3D.Ambient = m_color;
			mat[nCntMat].MatD3D.Diffuse = m_color;
			mat[nCntMat].MatD3D.Specular = m_color;
			mat[nCntMat].MatD3D.Emissive = m_color;
		}
	}

	CModelHierarchy::Draw();
}

//******************************
// 死亡処理
//******************************
void CPlayer::Death(void)
{
	if (!m_bInvincible)
	{
		//死亡状態に移行
		SetState(PLAYER_STATE_DEATH);

		//当たり判定を消す
		if (m_pCollision != NULL)
		{
			m_pCollision->ReConnection();
			m_pCollision->Uninit();
			delete m_pCollision;
			m_pCollision = NULL;
		}

		//行動クラスに死亡状態になったフラグを送る
		m_pActRange->SetDeath(true);
		//透明にする
		m_color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

		//位置セット
		SetPos(m_RespawnPos);
	}

}

//******************************
// 移動処理
//******************************
void CPlayer::Move(void)
{
	if (m_bMove)
	{
		// キーボードとジョイパッドの取得
		CInputKeyboard * pKey = CManager::GetKeyboard();
		CInputJoypad* pJoypad = CManager::GetJoypad();

		// スティックの座標
		D3DXVECTOR2 StickPos = pJoypad->GetStickState(pJoypad->PAD_LEFT_STICK, m_nPlayerNumber);

		if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_PROGRESS])
			|| (StickPos.y > 0.0f && StickPos.x < STICK_DECISION_RANGE && StickPos.x > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_UP, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_UP))
		{// 前進
			m_Move.z -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, -1);

			m_rotDest.y= D3DXToRadian(ROTDEST_PREVIOUS);
		}
		else if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RECESSION])
			|| (StickPos.y < 0.0f && StickPos.x < STICK_DECISION_RANGE && StickPos.x > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_DOWN, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_DOWN))
		{// 後退
			m_Move.z += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(0, 1);

			m_rotDest.y = D3DXToRadian(ROTDEST_AFTER);
		}
		else if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_LEFT])
			|| (StickPos.x < 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_LEFT, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_LEFT))
		{// 左
			m_Move.x += MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(-1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_LEFT);
		}
		else if ((pKey->GetKeyPress(m_anControllKey[m_nPlayerNumber][KEY_RIGHT])
			|| (StickPos.x > 0.0f && StickPos.y < STICK_DECISION_RANGE && StickPos.y > -STICK_DECISION_RANGE)
			|| pJoypad->GetButtonState(XINPUT_GAMEPAD_DPAD_RIGHT, pJoypad->BUTTON_PRESS, m_nPlayerNumber))
			&& m_pActRange->GetPlayerMove(CActRange::PLAYER_MOVE_RIGHT))
		{// 右
			m_Move.x -= MOVE_DIST;
			m_bMove = false;
			m_pActRange->ActMove(1, 0);

			m_rotDest.y = D3DXToRadian(ROTDEST_RIGHT);
		}
	}
	else
	{
		// 座標の取得
		D3DXVECTOR3 pos = GetPos();

		//移動計算
		pos += (m_Move - pos) / (float)(m_nMoveframe - m_MoveCount);

		//位置設定
		SetPos(pos);

		//カウントアップ
		m_MoveCount++;

		//カウントが一定に達する
		if (m_MoveCount >= m_nMoveframe)
		{
			//カウント初期化
			m_MoveCount = 0;
			//移動できるように
			m_bMove = true;
		}

		switch (m_ItemState)
		{
		case ITEM_STATE_NONE:

			//カウントが一定に達する
			if (m_MoveCount >= m_nMoveframe)
			{
				//カウント初期化
				m_MoveCount = 0;
				//移動できるように
				m_bMove = true;
			}
			break;
		case ITEM_STATE_DASH:
			//カウントが一定に達する
			//if (m_MoveCount >= m_nMoveframe / 2)
			//{
			//	//ダッシュタイムをカウント
			//	m_nDashCnt++;
			//	//カウント初期化
			//	m_MoveCount = 0;
			//	//移動できるように
			//	m_bMove = true;
			//}

			//ダッシュタイムをカウント
			m_nDashCnt++;

			m_nMoveframe = (int)DASH_MOVE_FRAME;

			if (m_nDashCnt % DASH_FRAME == 0)
			{
				m_nDashCnt = 0;
				m_nMoveframe = MOVE_FRAME;
				m_ItemState = ITEM_STATE_NONE;
			}
			break;
		}
	}
}//******************************
// 弾の処理
//******************************
void CPlayer::Bullet(void)
{
	// キーボードとジョイパッドの取得
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CInputJoypad* pJoypad = CManager::GetJoypad();

	// 座標の取得
	D3DXVECTOR3 pos = GetPos();

	// 攻撃ボタンを押したら
	if (pKey->GetKeyTrigger(m_anControllKey[m_nPlayerNumber][KEY_BULLET])
		|| pJoypad->GetButtonState(XINPUT_GAMEPAD_X, pJoypad->BUTTON_TRIGGER, m_nPlayerNumber))
	{
		//// 方向指定
		//D3DXVECTOR3 bulletMove;
		//bulletMove.x = cosf(GetRot().y)*-BULLET_MOVE;
		//bulletMove.y = 0.0f;
		//bulletMove.z = sinf(GetRot().y)*BULLET_MOVE;
		//// 弾の生成
		//CBullet::Create(D3DXVECTOR3(pos.x, pos.y, pos.z), bulletMove, m_nPlayerNumber);

		m_pAttack->AttackSwitch(0);
	}

	//位置設定
	SetPos(pos);
}

//******************************
// リスポーン処理
//******************************
void CPlayer::Respawn(void)
{
	//プレイヤーステートが死亡状態の時
	if (m_PlayerState == PLAYER_STATE_DEATH)
	{
		//カウントアップ
		m_nRespawnCount++;
		
		//カウントが一定までに達したとき
		if (m_nRespawnCount >= RESPAWN_MAX_COUNT)
		{
			//位置セット
			SetPos(m_RespawnPos);
			m_Move = m_RespawnPos;
			//行動クラスに通常状態になったフラグを送る
			m_pActRange->SetDeath(false);
			//行動クラスに位置設定をするように送る
			m_pActRange->PlayerPos();
			//無敵処理
			m_bInvincible = true;
			//色設定
			m_color = MODL_COLOR;
			//通常状態に移行
			SetState(PLAYER_STATE_NORMAL);
			//カウント初期化
			m_nRespawnCount = 0;
		}
	}
}

//******************************
// 無敵処理
//******************************
void CPlayer::Invincible(void)
{
	//無敵フラグが立っているか
	if (m_bInvincible)
	{
		//無敵カウントアップ
		m_nInvincibleCount++;

		//5の倍数でカラーを変更（点滅するように）
		if ((m_nInvincibleCount % 5) == 0)
		{
			//点滅
			if (m_color.a <= 0.0f)
			{
				m_color.a = 1.0f;
			}
			else
			{
				m_color.a = 0.0f;
			}
		}

		//カウントが一定になったら
		if (m_nInvincibleCount >= INVINCIBLE_COUNT)
		{
			//初期化
			m_nInvincibleCount = 0;
			m_color.a = 1.0f;
			m_bInvincible = false;
		}
	}
}

//******************************
// モデル描画処理
//******************************
void CPlayer::DrawModel(void)
{
	//デバイス情報の取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DMATERIAL9 matDef;	//現在のマテリアル保持用
	D3DXMATERIAL*pMat;	//マテリアルデータへのポインタ

	CResourceModel::Model *pModelData = GetModelData();

	for (int nCntParts = 0; nCntParts < GetPartsNum(); nCntParts++)
	{
		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &pModelData[nCntParts].mtxWorld);

		//現在のマテリアルを取得する
		pDevice->GetMaterial(&matDef);

		// シェーダー情報の取得
		CResourceShader::Shader shader = CResourceShader::GetShader(CResourceShader::SHADER_PLAYER);

		if (shader.pEffect != NULL)
		{
			// シェーダープログラムに値を送る
			SetShaderVariable(shader.pEffect, &pModelData[nCntParts]);

			//マテリアルデータへのポインタを取得
			pMat = (D3DXMATERIAL*)pModelData[nCntParts].pBuffMat->GetBufferPointer();

			// パス数の取得
			UINT numPass = 0;
			shader.pEffect->Begin(&numPass, 0);

			// パス数分描画処理のループ

			for (int nCntMat = 0; nCntMat < (int)pModelData[nCntParts].nNumMat; nCntMat++)
			{
				//マテリアルのアンビエントにディフューズカラーを設定
				pMat[nCntMat].MatD3D.Ambient = pMat[nCntMat].MatD3D.Diffuse;

				//マテリアルの設定
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
				// テクスチャ
				pDevice->SetTexture(0, pModelData[nCntParts].apTexture[nCntMat]);

				// テクスチャをシェーダーに送る
				shader.pEffect->SetTexture("Tex", pModelData[nCntParts].apTexture[nCntMat]);
				// 色
				shader.pEffect->SetFloatArray("DiffuseColor", (float*)&pMat[nCntMat].MatD3D.Diffuse, 4);
				if (pModelData[nCntParts].apTexture[nCntMat] == NULL)
				{
					// シェーダパスの描画開始
					shader.pEffect->BeginPass(0);
				}
				else
				{
					// シェーダパスの描画開始
					shader.pEffect->BeginPass(1);
				}
				// モデルパーツの描画
				pModelData[nCntParts].pMesh->DrawSubset(nCntMat);
				// シェーダパスの終了
				shader.pEffect->EndPass();

				pMat[nCntMat] = pModelData[nCntParts].defMat[nCntMat];

			}
			// シェーダー終了
			shader.pEffect->End();
		}

		//保持していたマテリアルを戻す
		pDevice->SetMaterial(&matDef);
		// テクスチャの初期化
		pDevice->SetTexture(0, 0);
	}
}


//=============================
// シェーダーに値を送る
//=============================
void CPlayer::SetShaderVariable(LPD3DXEFFECT pEffect, CResourceModel::Model * pModelData)
{
	if (pEffect != NULL)
	{
		// シェーダーに情報を渡す
		D3DXMATRIX mat;
		D3DXMatrixIdentity(&mat);
		mat = pModelData->mtxWorld * (*CManager::GetCamera()->GetViewMtx())* (*CManager::GetCamera()->GetProjectionMtx());
		// ワールドプロジェクション
		pEffect->SetMatrix("WorldViewProj", &mat);
		// ワールド座標
		pEffect->SetMatrix("World", &pModelData->mtxWorld);
		// ライトディレクション
		D3DXVECTOR3 lightDir = LIGHT_DIR_BASE;
		pEffect->SetFloatArray("LightDirection", (float*)&D3DXVECTOR3(lightDir.x, -lightDir.y, -lightDir.z), 3);
		// 視点位置
		D3DXVECTOR3 eye = CManager::GetCamera()->GetPos();
		pEffect->SetFloatArray("Eye", (float*)&D3DXVECTOR3(eye.x, eye.y, eye.z), 3);
		// スペキュラの情報を送る
		pEffect->SetFloatArray("SpecularColor", (float*)&D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 4);
		// リムから―の情報を送る
		pEffect->SetFloatArray("RimColor", (float*)&GET_COLORMANAGER->GetColorDataByPlayerNumber(m_nColor).iconColor, 4);
		pEffect->SetFloat("RimPower", RIM_POWER);
		// キューブテクスチャ
		pEffect->SetTexture("CubeTex", CResourceTexture::GetCubeTexture(CResourceTexture::TECTURE_CUBE_SLY));
	}
}

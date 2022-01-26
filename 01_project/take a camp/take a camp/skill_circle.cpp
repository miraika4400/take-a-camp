//=============================================================================
//
// スキルサークル処理 [skill_circle.cpp]
// Author : 齋藤大行
//
//=============================================================================

//=============================================================================
//インクルードファイル
//=============================================================================
#include "skill_circle.h"
#include "skill_effect.h"
#include "base_Cylinder.h"
#include "resource_texture.h"
#include "manager.h"
#include "renderer.h"
#include "player.h"
#include "color_manager.h"
//=============================================================================
//静的メンバー変数
//=============================================================================

//=============================================================================
// マクロ定義
//=============================================================================

//=============================================================================
//コンストラクタ
//=============================================================================
CSkill_circle::CSkill_circle(int nPliority)
{
	m_apTexture[EFFECTTYPE_MAX] = {};
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 50;
	m_fRotAngle = 0.0f;
	m_fFadeout = 0.0f;
	m_bFadeoutFlag = true;
	m_col = { 1.0f,0.0f,0.0f,1.0f };
	m_mtxWorld = {};
	m_bAddMode = false;
	m_type = EFFECTTYPE_SKIIL;
	m_bEffectTrigger = false;
	m_pPlayer = NULL;
}

//=============================================================================
//デストラクタ
//=============================================================================
CSkill_circle::~CSkill_circle()
{
}

//=============================================================================
//生成処理関数
//=============================================================================
CSkill_circle * CSkill_circle::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col,const int nlife, const EFFECTTYPE type, CPlayer * pPlayer)
{
	//インスタンス生成
	CSkill_circle *pSkill_circle;
	pSkill_circle = new CSkill_circle;

	//タイプ代入
	pSkill_circle->m_type = type;
	pSkill_circle->SetPlayer(pPlayer);
	//初期化処理
	pSkill_circle->Init();
	//加算合成設定(オフ)
	pSkill_circle->SetAddMode(false);
	//タイプごとの設定
	switch (type)
	{
		//衝撃波
	case EFFECTTYPE_SKIIL:
		//円柱の傾斜設定　
		pSkill_circle->SetHighRot(NORMAL_SKIIL_HIGHROT);	//上辺
		pSkill_circle->SetRowRot(NORMAL_SKIIL_ROWROT);		//下辺
		break;
		//衝撃波ミニ
	case EFFECTTYPE_SKIILMINI:
		//円柱の傾斜設定　
		pSkill_circle->SetHighRot(NORMAL_SKIIL_HIGHROT);	  //上辺
		pSkill_circle->SetRowRot(NORMAL_SKIIL_ROWROT);		  //下辺
		break;
		// 落ちたメテオ
	case EFFECTTYPE_METEOR:
		//円柱の傾斜設定　
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_HIGHROT);		 //上辺
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_ROWROT);		 //下辺
		break;
		//メテオ本体
	case EFFECTTYPE_METEOR_CENTER:
		//円柱の傾斜設定　
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_CENTER_HIGHROT);	  //上辺
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_CENTER_ROWROT);	  //下辺

		break;

		// メテオの衝撃波
	case EFFECTTYPE_METEOR_IMPACT:
		//円柱の傾斜設定　
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_IMPACT_HIGHROT);		//上辺
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_IMPACT_ROWROT);		//下辺
		break;

		//衝撃波の火柱
	case EFFECTTYPE_IMPACT:
		//円柱の傾斜設定　
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_CENTER_HIGHROT);		   //上辺
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_CENTER_ROWROT);		   //下辺
		//テクスチャのUV設定
		pSkill_circle->SetTextureUV(EXPLOSION_SKIIL_METEOR_IMPACT_UV1, EXPLOSION_SKIIL_METEOR_IMPACT_UV2);
		break;

	default:
		break;
	}

	//位置設定
	pSkill_circle->SetPos(D3DXVECTOR3(pos.x, pos.y + size.y, pos.z));
	//サイズ設定
	pSkill_circle->SetSize(size);
	//サイズ代入
	pSkill_circle->m_size = size;
	//位置代入
	pSkill_circle->m_pos = pos;
	//カラー設定 
	pSkill_circle->SetColor(col);
	//カラー値代入
	pSkill_circle->m_col = col;
	//ライフ値代入
	pSkill_circle->m_nLife = nlife;


	return pSkill_circle;
}

//=============================================================================
//初期化処理関数
//=============================================================================
HRESULT CSkill_circle::Init(void)
{	
	//ベースサークルの初期化処理読み込み
	if (FAILED(Cbase_Cylinder::Init()))//初期化処理判定
	{
		return E_FAIL;
	}
	//テクスチャのゲット
	m_apTexture[EFFECTTYPE_SKIIL] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_SKIILMINI] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR_CENTER] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR_IMPACT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_IMPACT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	

	//テクスチャ割り当て
	BindTexture(m_apTexture[m_type]);
	
	return S_OK;
}

//=============================================================================
//終了処理関数
//=============================================================================
void CSkill_circle::Uninit(void)
{
	//ベースサークルの終了処理
	Cbase_Cylinder::Uninit();
}

//=============================================================================
//更新処理関数
//=============================================================================
void CSkill_circle::Update(void)
{	
	//プレイヤーのポインタ　
	CPlayer *pPlayer = GetPlayer();
	//エフェクトを使用しているか判定変数
	bool bUse = true;

	//サイズ 位置 カラー所得
	m_pos = GetPos();
	m_size = GetSize();
	m_col = GetColor();

	//タイプごとの更新処理
	switch (m_type)
	{
		//衝撃波
	case EFFECTTYPE_SKIIL:
		
	
		m_col.a -= 0.009f;			//アルファ値減算
		m_fRotAngle += 0.5f;		//角度加算
		m_rot.y += 0.05f;			//回転角度加算

		//サイズ加算
		m_size.x += 0.1f;			
		m_size.z += 0.1f;			

		if (m_fRotAngle >= 5.0f)	//5.0fまで加算
		{
			m_fRotAngle = 5.0f;		//傾斜角度固定
		}

		break;

		//衝撃波ミニ
	case EFFECTTYPE_SKIILMINI:
		

		m_col.a -= 0.009f;			 //アルファ値減算
		m_fRotAngle += 0.1f;		 //角度加算
		m_rot.y -= 0.05f;			 //回転角度加算

		//サイズ加算
		m_size.x += 0.1f;			 
		m_size.z += 0.1f;

		if (m_fRotAngle >= 5.0f)	 //5.0fまで加算
		{
			m_fRotAngle = 5.0f;		 //傾斜角度固定
		}							
		break;

		//落ちたメテオ
	case EFFECTTYPE_METEOR:

		m_col.a -= 0.01f;			 //アルファ値減算
		m_rot.y -= 0.05f;			 //回転角度加算

		//サイズ加算
		m_size.x += 0.05f;			 
		m_size.z += 0.05f;


		break;

		//メテオ本体
	case EFFECTTYPE_METEOR_CENTER:

		m_col.a -= 0.009f;			//アルファ値減算
		m_rot.y -= 0.05f;			//角度加算

		//サイズ加算
		m_size.x += 0.0001f;		
		m_size.y += 1.0f;
		m_size.z += 0.0001f;
		m_pos.y += 1.0f;			//位置加算
		

		break;

		//メテオ衝撃波
	case EFFECTTYPE_METEOR_IMPACT:

		m_col.a -= 0.01f;			//アルファ値減算
		m_rot.y -= 0.05f;			//角度加算

		//サイズ加算
		m_size.x += 0.15f;
		m_size.z += 0.15f;


		break;

		//衝撃波の火柱
	case EFFECTTYPE_IMPACT:

		m_col.a -= 0.03f;			//アルファ値減算
		m_size.y += 0.25f;			//角度加算

		//位置減算
		m_pos.y -= 1.25f;

		if (m_pos.y <= 6.0f)		 //6.0fまで加算
		{
			m_pos.y = 6.0f;			 //位置固定
			m_size = GetSize();		 //サイズ所得

			m_bEffectTrigger = true; //エフェクト生成オン
			
		}


		break;

	default:
		break;
	}

		SetPos(m_pos);				//位置の設定
		SetSize(m_size);			//サイズの設定
		SetRot(m_rot);				//回転の設定
		SetColor(m_col);			//サイズの設定
		SetAddRotValue(m_fRotAngle);//角度の設定

	if (m_bEffectTrigger)
	{
		//テクスチャUVの設定
		SetTextureUV(EXPLOSION_SKIIL_METEOR_IMPACT_UV2, EXPLOSION_SKIIL_METEOR_IMPACT_UV1);
		//衝撃波の生成
		CSkill_circle::Create(m_pos, WIZARD_EFFECT_SIZE + EXPLOSION_SKIIL_IMPACT_SIZE - EXPLOSION_SKIIL_IMPACT_SIZESHIFT, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 1), m_nLife, CSkill_circle::EFFECTTYPE_METEOR_IMPACT, pPlayer);
		CSkill_circle::Create(m_pos, WIZARD_EFFECT_SIZE, GET_COLORMANAGER->GetStepColor(pPlayer->GetColorNumber(), 2), m_nLife, CSkill_circle::EFFECTTYPE_METEOR, pPlayer);
		
		//エフェクト生成　オフ
		bUse = false;				
	}

	if (m_nLife <= 0 || m_col.a <= 0)		//エフェクト終了処理フラグ
	{
		bUse = false;
	}
	if (!bUse)//終了処理判定
	{
		//終了処理
		Uninit();
	}
}

//=============================================================================
//描画処理関数
//=============================================================================
void CSkill_circle::Draw(void)
{
	//ベースサークルの描画読み込み
	Cbase_Cylinder::Draw();
}
















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
#include "base_Cylinder.h"
#include "resource_texture.h"
#include "manager.h"
#include "renderer.h"
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
CSkill_circle * CSkill_circle::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, const D3DXCOLOR col,const int nlife, const EFFECTTYPE type)
{
	//インスタンス生成
	CSkill_circle *pSkill_circle;
	pSkill_circle = new CSkill_circle;

	//タイプ代入
	pSkill_circle->m_type = type;

	//初期化処理
	pSkill_circle->Init();

	switch (type)
	{
	case EFFECTTYPE_SKIIL:

		pSkill_circle->SetAddMode(false);
		pSkill_circle->SetHighRot(NORMAL_SKIIL_HIGHROT);
		pSkill_circle->SetRowRot(NORMAL_SKIIL_ROWROT);
		break;

	case EFFECTTYPE_SKIILMINI:

		pSkill_circle->SetAddMode(false);
		pSkill_circle->SetHighRot(NORMAL_SKIIL_HIGHROT);
		pSkill_circle->SetRowRot(NORMAL_SKIIL_ROWROT);
		break;

	case EFFECTTYPE_METEOR:

		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_ROWROT);
		break;

	case EFFECTTYPE_METEOR_CENTER:
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_CENTER_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_CENTER_ROWROT);


		break;
	case EFFECTTYPE_METEOR_IMPACT:
		pSkill_circle->SetHighRot(EXPLOSION_SKIIL_IMPACT_HIGHROT);
		pSkill_circle->SetRowRot(EXPLOSION_SKIIL_IMPACT_ROWROT);
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
	pSkill_circle->m_col = col;



	return pSkill_circle;
}

//=============================================================================
//初期化処理関数
//=============================================================================
HRESULT CSkill_circle::Init(void)
{	
	if (FAILED(Cbase_Cylinder::Init()))
	{
		return E_FAIL;
	}
	//テクスチャのゲット
	m_apTexture[EFFECTTYPE_SKIIL] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_SKIILMINI] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR_CENTER] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[EFFECTTYPE_METEOR_IMPACT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);

	//テクスチャ割り当て

	BindTexture(m_apTexture[m_type]);
	
	return S_OK;
}

//=============================================================================
//終了処理関数
//=============================================================================
void CSkill_circle::Uninit(void)
{
	Cbase_Cylinder::Uninit();
}

//=============================================================================
//更新処理関数
//=============================================================================
void CSkill_circle::Update(void)
{
	bool bUse = true;

	m_pos = GetPos();
	m_size = GetSize();
	
	



	switch (m_type)
	{
	case EFFECTTYPE_SKIIL:
		
		m_col.a -= 0.02;
		m_fRotAngle += 0.5f;
		m_rot.y += 0.05f;
		m_size.x += 0.1f;
		m_size.z += 0.1f;
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetAddRotValue(m_fRotAngle);
		if (m_fRotAngle >= 5.0f)
		{
			m_fRotAngle = 5.0f;
		}
		break;
	case EFFECTTYPE_SKIILMINI:
		
		m_col.a -= 0.02;
		m_fRotAngle += 0.075f;
		m_rot.y -= 0.05f;
		m_size.x += 0.1f;
		m_size.z += 0.1f;
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);
		SetAddRotValue(m_fRotAngle);
		if (m_fRotAngle >= 5.0f)
		{
			m_fRotAngle = 5.0f;
		}
		break;

	case EFFECTTYPE_METEOR:

		m_nLife--;
		m_rot.y-= 0.05f;
		m_size.x += 0.05f;
		m_size.z += 0.05f;
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);

		break;

	case EFFECTTYPE_METEOR_CENTER:

		m_nLife--;
		m_rot.y -= 0.05f;
		m_size.x += 0.0001f;
		m_size.y += 2.0f;
		m_size.z += 0.0001f;
		m_pos.y += 2.0f;
		
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);

		break;

	case EFFECTTYPE_METEOR_IMPACT:

		m_nLife--;
		m_rot.y -= 0.05f;
		m_size.x += 0.25f;
		m_size.z += 0.25f;
		SetPos(m_pos);
		SetSize(m_size);
		SetRot(m_rot);

		break;

	default:
		break;
	}
	if (m_nLife <= 0 || m_col.a <= 0)
	{
		bUse = false;
	}
	if (!bUse)
	{
		Uninit();
	}
}

//=============================================================================
//描画処理関数
//=============================================================================
void CSkill_circle::Draw(void)
{
	Cbase_Cylinder::Draw();
}
















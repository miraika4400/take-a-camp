////////////////////////////////////////////////////
//
//    particleクラスの処理[particle.cpp]
//    Author:齋藤大行
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "particle.h"
#include "manager.h"
#include "renderer.h"
#include "resource_texture.h"
#include "skill_effect.h" 

//*****************************
// マクロ定義
//*****************************

//******************************
// 静的メンバ変数宣言
//*****************************

//******************************
// コンストラクタ
//******************************
CParticle::CParticle()
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	m_nLife = 0;
	m_type = PARTICLE_SQUARE;
	m_bFadeoutFlag = true;
	m_fRotAngle = 0.0f;
	m_fFadeout = 0.0f; 
	m_nPattern = 0;
	m_nAnimation = 0;

	m_nEffectId = 0;
}

//******************************
// デストラクタ
//******************************
CParticle::~CParticle()
{
}


//*****************************
// 静的メンバ変数宣言
//*****************************


//******************************
// クリエイト
//******************************
CParticle * CParticle::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move, const D3DXVECTOR3 size, const int nLife, const D3DXCOLOR col,const float fadeout, const PARTICLE_TYPE type)
{
	// メモリの確保
	CParticle *pParticle;
	pParticle = new CParticle;

	// タイプの設定
	pParticle->m_type = type;

	// 初期化
	pParticle->Init();

	// 各値の代入・セット

	pParticle->m_move = move;                // 移動量
	pParticle->m_size = size;				 // サイズ代入
	pParticle->SetSize(size);                // サイズ
	pParticle->m_nLife = nLife;				 // 寿命
	pParticle->m_col = col;					 // 代入
	pParticle->m_fFadeout = fadeout;		 // フェードアウト
	pParticle->m_fRotAngle = 0.0f;           // 回転角度
	pParticle->SetColor(col);                // カラー設定
	//pParticle->SetAngle((float)(rand() % 360));       // 回転角度をランダム
	pParticle->SetAddMode(false);             // 加算合成
	

	switch (type)
	{
	case PARTICLE_SQUARE:
		pParticle->SetAngle((float)(rand() % 360));       // 回転角度をランダム

		break;

	case PARTICLE_TEARS:
		break;

	case PARTICLE_SHOOT:
		break;

	case PARTICLE_METEOR:
		pParticle->SetAddMode(true); 
	
		break;
	case PARTICLE_METEOR_SHADOW:
		pParticle->SetAddMode(false);
		break;

	case PARTICLE_GURUGURU:
		pParticle->SetAngle((float)(rand() % 360));       // 回転角度をランダム
		break;

	case PARTICLE_SLASH:
		pParticle->m_pos = pos;					      // 初期位置代入
		pParticle->SetAngle((float)(rand() % 360));       // 回転角度をランダム
		pParticle->SetTextureManualUV(TEXTURE_ANIMA_PATTERN, pParticle->m_nPattern);

	default:
		break;
	}
	
	return pParticle;
}

//******************************
// 初期化処理
//******************************
HRESULT CParticle::Init(void)
{
	if (FAILED(CBillboard::Init()))
	{
		return E_FAIL;
	}

	m_apTexture[PARTICLE_SQUARE] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SQUARE);
	m_apTexture[PARTICLE_TEARS] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SKILL);
	m_apTexture[PARTICLE_SHOOT] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SHOOT);
	m_apTexture[PARTICLE_METEOR] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_METEOR);
	m_apTexture[PARTICLE_METEOR_SHADOW] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_METEOR_SHADOW);
	m_apTexture[PARTICLE_GURUGURU] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_GURUGURU);
	m_apTexture[PARTICLE_SLASH] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_PARTICLE_SLASH);
	// テクスチャ割り当て
	BindTexture(m_apTexture[m_type]);

	SetPriority(OBJTYPE_PARTICLE);
	return S_OK;
}

//******************************
// 終了処理
//******************************
void CParticle::Uninit(void)
{
	CBillboard::Uninit();
}

//******************************
// 更新処理
//******************************
void CParticle::Update(void)
{
	
	
	// 移動
	SetPos(GetPos() + m_move);
	m_nAnimation++;


	switch (m_type)
	{
	case PARTICLE_SQUARE:
		m_col.a -= m_fFadeout;
		SetColor(m_col);

		break;

	case PARTICLE_TEARS:
		break;

	case PARTICLE_SHOOT:
		break;

	case PARTICLE_METEOR:
		m_col.r += m_fFadeout;
		SetColor(m_col);
		break;

	case PARTICLE_METEOR_SHADOW:
		break;

	case PARTICLE_GURUGURU:
		m_col.a -= m_fFadeout;
		SetColor(m_col);
		break;

	case PARTICLE_SLASH:

		if (m_nAnimation >= TEXTURE_ANIMA_LATE)
		{
			SetTextureManualUV(TEXTURE_ANIMA_PATTERN, m_nPattern);
			m_nPattern++;
			m_nAnimation = 0;


			if (m_nEffectId <= EFFECT_MAX)
			{
				if (m_nPattern == TEXTURE_ANIMA_CREATE_POINT)
				{

					CParticle * pPar = CParticle::Create(m_pos, SLASH_SKIIL_MOVE, m_size, m_nLife, m_col, 0.05, CParticle::PARTICLE_SLASH);
					pPar->m_nEffectId = m_nEffectId + 1;
					SetPos(D3DXVECTOR3(m_pos.x + (float)(rand() % 14 - 7), m_pos.y, m_pos.z + (float)(rand() % 14 - 7)));

				}

			}
			if (m_nPattern >= TEXTURE_ANIMA_PATTERN)
			{
				m_bFadeoutFlag = false;
			}

		}
	
		break;


	default:
		break;
	}

	SetAngle(GetAngle() + m_fRotAngle);

	if (m_col.a <= 0)
	{
		m_bFadeoutFlag = false;
	}

	if (!m_bFadeoutFlag)
	{
		Uninit();
	}

	// 寿命
	/*m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
	}*/
}

//******************************
// 描画処理
//******************************
void CParticle::Draw(void)
{
	CBillboard::Draw();
}

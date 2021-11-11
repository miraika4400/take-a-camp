//===================================================
//
// スキルゲージの処理[skill_gauge.cpp]
// Author:伊藤陽梧
//
//====================================================

//**********************************
// インクルード
//**********************************
#include "skill_gauge.h"
#include "manager.h"
#include "billboard.h"
#include "resource_texture.h"
#include "renderer.h"
#include "polygon.h"
#include "keyboard.h"
#include "player.h"
#include "color_tile.h"

//==================================
// マクロ定義
//==================================
#define SKILLGAUGE_ADDPOS (D3DXVECTOR3(0.0f, 35.0f, 0.0f))

//==================================
// コンストラクタ
//==================================
CSkillgauge::CSkillgauge()
{
	m_SkillGaugeType = SKILLGAUGE_BG;
	memset(&m_pos, 0, sizeof(m_pos));
	memset(&m_size, 0, sizeof(m_size));
	memset(&m_col, 0, sizeof(m_col));
	m_fGauge = 0.0f;
}

//==================================
// デストラクタ
//==================================
CSkillgauge::~CSkillgauge()
{
}

//==================================
// クリエイト
//==================================
CSkillgauge * CSkillgauge::Create(const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType)
{
	// メモリの確保
	CSkillgauge * pSkillgauge = new CSkillgauge;

	pSkillgauge->m_size = size;
	pSkillgauge->m_col = col;
	pSkillgauge->m_SkillGaugeType = SkillGaugeType;
	pSkillgauge->m_nPlayerNum = nPlayerNum;

	// 初期化処理
	pSkillgauge->Init();

	return pSkillgauge;
}

//==================================
// 初期化処理
//==================================
HRESULT CSkillgauge::Init()
{
	// 初期化処理
	CBillboard::Init();

	// 頂点座標の設定
	D3DXVECTOR3 Pos[NUM_VERTEX];

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));

		SetPos(m_pos);
		SetSize(m_size);
		SetColor(m_col);
		break;

	case SKILLGAUGE_STENCIL:

		//BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));

		SetPos(m_pos);
		SetSize(m_size);
		SetColor(m_col);

		Pos[0] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[1] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[2] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);
		Pos[3] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);

		SetVertexPos(Pos);
		break;

	default:
		break;
	}

	return S_OK;
}

//==================================
// 終了処理
//==================================
void CSkillgauge::Uninit(void)
{
	// 終了処理
	CBillboard::Uninit();
}

//==================================
// 更新処理
//==================================
void CSkillgauge::Update(void)
{
	// 更新処理
	CBillboard::Update();

	CInputKeyboard* pInputKeyboard = CManager::GetKeyboard();

	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() == m_nPlayerNum)
		{
			m_pos = pPlayer->GetPos();
		}

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	// 頂点座標の設定
	D3DXVECTOR3 Pos[NUM_VERTEX];

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		SetPos(m_pos + SKILLGAUGE_ADDPOS);
		break;

	case SKILLGAUGE_STENCIL:
		m_fGauge = (float)CColorTile::GetTileNum(m_nPlayerNum);

		if (m_fGauge > m_size.y)
		{
			m_fGauge = m_size.y;
		}

		Pos[0] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f + m_fGauge, 0.0f);
		Pos[1] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f + m_fGauge, 0.0f);
		Pos[2] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);
		Pos[3] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);

		SetPos(m_pos + SKILLGAUGE_ADDPOS);
		SetVertexPos(Pos);
		break;

	default:
		break;
	}
}

//==================================
// 描画処理
//==================================
void CSkillgauge::Draw(void)
{
	// ステンシルバッファを使う
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	// ステンシルテストを有効に
	pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

		// ステンシルテストと比較する参照値設定
		pDevice->SetRenderState(D3DRS_STENCILREF, 0x01);

		// ステンシルテストの値に対してのマスク設定 0xff(全て真)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// この描画での参照値 == ステンシルバッファの参照値なら合格
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);

		// ステンシルテストの結果に対しての反映設定
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);

		break;

	case SKILLGAUGE_STENCIL:
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

		// ステンシルテストと比較する参照値設定
		pDevice->SetRenderState(D3DRS_STENCILREF, 0x01);

		// ステンシルテストの値に対してのマスク設定 0xff(全て真)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// この描画での参照値 == ステンシルバッファの参照値なら合格
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);

		// ステンシルテストの結果に対しての反映設定
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);

		break;
	default:
		break;
	}

	// 描画処理
	CBillboard::Draw();

	// ZBUFFER比較設定変更 => (参照値 <= バッファ値)(戻す)
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	//// Zバッファ設定 => 有効
	//pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	//// ZBUFFER比較設定変更 => (参照値 <= バッファ値)
	//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	// ステンシルテストを無効に
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);

}
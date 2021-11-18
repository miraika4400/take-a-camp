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
#include "player.h"
#include "color_tile.h"
#include "keyboard.h"
#include "joypad.h"
#include "attack_final.h"

//==================================
// マクロ定義
//==================================
#define SKILLGAUGE_ADDPOS (D3DXVECTOR3(0.0f, 35.0f, 0.0f))
#define SKILLGAUGE_ADDFLAME (10.0f)
#define SKILLGAUGE_SIZE (D3DXVECTOR3(20.0f, 20.0f, 0.0f))

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
// スキルゲージすべてのクリエイト
// nPlayerNum：プレイヤーの番号
//==================================
void CSkillgauge::AllCreate(const int nPlayerNum)
{
	// 上からスキルゲージの背景、色つけるやつ、アイコン
	CSkillgauge::Create(SKILLGAUGE_SIZE, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), nPlayerNum, CSkillgauge::SKILLGAUGE_BG);
	CSkillgauge::Create(SKILLGAUGE_SIZE, GET_COLORMANAGER->GetIconColor(nPlayerNum), nPlayerNum, CSkillgauge::SKILLGAUGE_STENCIL);
	CSkillgauge::Create(SKILLGAUGE_SIZE, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), nPlayerNum, CSkillgauge::SKILLGAUGE_ICON);
}

//==================================
// クリエイト
// size：スキルゲージの大きさ
// col：スキルゲージの色
// nPlayerNum：プレイヤーの番号
// SkillGaugeType：スキルゲージのタイプ
//==================================
CSkillgauge * CSkillgauge::Create(const D3DXVECTOR3 size, const D3DXCOLOR col, const int nPlayerNum, const SKILLGAUGE_TYPE SkillGaugeType)
{
	// メモリの確保
	CSkillgauge * pSkillgauge = new CSkillgauge;

	pSkillgauge->m_size = size;
	pSkillgauge->m_col = col;
	pSkillgauge->m_nPlayerNum = nPlayerNum;
	pSkillgauge->m_SkillGaugeType = SkillGaugeType;
	pSkillgauge->SetPriority(OBJTYPE_UI);

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

	// 座標、サイズ、色のセット
	SetPos(m_pos);
	SetSize(m_size);
	SetColor(m_col);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ICON_BG));
		break;

	case SKILLGAUGE_STENCIL:
		// ステンシルを表示する座標
		Pos[0] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[1] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f - m_fGauge, 0.0f);
		Pos[2] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);
		Pos[3] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);

		SetVertexPos(Pos);
		break;

	case SKILLGAUGE_ICON:
		// キャラクターのタイプごとにテクスチャを変える
		switch (GetPlayerinfo(m_nPlayerNum)->GetCharacterType())
		{
		case CResourceCharacter::CHARACTER_TYPE::CHARACTER_KNIGHT:
			BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
			break;
		case CResourceCharacter::CHARACTER_TYPE::CHARACTER_LANCER:
			BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
			break;
		case CResourceCharacter::CHARACTER_TYPE::CHARACTER_WIZARD:
			BindTexture(CResourceTexture::GetTexture(CResourceTexture::TEXTURE_SWORD_ICON));
			break;
		default:
			break;
		}

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

	// 座標のセット
	SetPos(m_pos + SKILLGAUGE_ADDPOS);

	// プレイヤーの座標を取得
	CPlayer * pPlayer = GetPlayerinfo(m_nPlayerNum);
	m_pos = pPlayer->GetPos();

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_STENCIL:
		// ステンシルの更新
		UpdateStencil();
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

	//アルファテストを有効化
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	//アルファテスト基準値の設定
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	//アルファテストの比較方法の設定
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	switch (m_SkillGaugeType)
	{
	case SKILLGAUGE_BG:
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);

		// ステンシルテストと比較する参照値設定
		pDevice->SetRenderState(D3DRS_STENCILREF, 0x01);

		// ステンシルテストの値に対してのマスク設定 0xff(全て真)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// この描画での参照値 == ステンシルバッファの参照値なら合格
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_GREATER);

		// ステンシルテストの結果に対しての反映設定
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
		break;

	case SKILLGAUGE_STENCIL:
		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);

		// ステンシルテストと比較する参照値設定
		pDevice->SetRenderState(D3DRS_STENCILREF, 0x01);

		// ステンシルテストの値に対してのマスク設定 0xff(全て真)
		pDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// この描画での参照値 == ステンシルバッファの参照値なら合格
		pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);

		// ステンシルテストの結果に対しての反映設定
		pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
		break;

	default:
		break;
	}

	// 描画処理
	CBillboard::Draw();

	// Zバッファを戻す
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	//アルファテストを無効化
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// ステンシルテストを無効に
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
}

//==================================
// プレイヤーの情報取得処理
//==================================
CPlayer * CSkillgauge::GetPlayerinfo(int nPlayerNum)
{
	// プレイヤーのポインタを取得
	CPlayer * pPlayer = (CPlayer*)GetTop(OBJTYPE_PLAYER);
	while (pPlayer != NULL)
	{
		if (pPlayer->GetPlayerNumber() == m_nPlayerNum)
		{
			break;
		}

		pPlayer = (CPlayer*)pPlayer->GetNext();
	}

	return pPlayer;
}

//==================================
// ステンシルの更新処理
//==================================
void CSkillgauge::UpdateStencil(void)
{
	// キーボードとジョイパッドの取得
	CInputKeyboard * pKey = CManager::GetKeyboard();
	CInputJoypad* pJoypad = CManager::GetJoypad();

	// 頂点座標の設定
	D3DXVECTOR3 Pos[NUM_VERTEX];

	// キャラデータの取得
	CResourceCharacter::CharacterData charaData =
		CResourceCharacter::GetResourceCharacter()->GetCharacterData(GetPlayerinfo(m_nPlayerNum)->GetCharacterType());

	// キャラクターごとの必殺技秒数*1秒間のフレーム数
	m_fGauge += m_size.y / ((float)charaData.nFinalAttackTime * SKILLGAUGE_ADDFLAME);

	// サイズ分を超えないように
	if (m_fGauge > m_size.y)
	{
		m_fGauge = m_size.y;

	}
	
	// ゲージが溜まったら
	if(m_fGauge == m_size.y)
	{
		// 必殺技のフラグ立て
		GetPlayerinfo(m_nPlayerNum)->SetFinalAttack(true);

		// 必殺技を打ったら
		if (GetPlayerinfo(m_nPlayerNum)->GetAttackFinal()->GetAttackFinalFlag() == true)
		{
			GetPlayerinfo(m_nPlayerNum)->SetFinalAttack(false);
			m_fGauge = 0.0f;
		}
	}

	// ゲージ用ポリゴンの座標
	Pos[0] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f + m_fGauge, 0.0f);
	Pos[1] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f + m_fGauge, 0.0f);
	Pos[2] = D3DXVECTOR3(-m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);
	Pos[3] = D3DXVECTOR3(+m_size.x / 2.0f, -m_size.y / 2.0f, 0.0f);

	SetVertexPos(Pos);
}
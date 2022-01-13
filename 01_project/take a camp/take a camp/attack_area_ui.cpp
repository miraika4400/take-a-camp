//=============================================================================
//
// 攻撃範囲UIの処理 [attack_area_ui.cpp]
// Author : 増澤未来
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "attack_area_ui.h"
#include "resource_texture.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define LEVEL_CHANGE_COUNT (100)
#define SIZE (D3DXVECTOR3(1260.0f,1944,0.0f)/5.0f)
#define COLOR (D3DXCOLOR(1.0f,1.0f,1.0f,0.9f))

//=============================================================================
// コンストラクタ
//=============================================================================
CAttackAreaUi::CAttackAreaUi() :CScene2d(OBJTYPE_UI_2)
{
	m_nLevel = 0;
	m_nCharaType = CResourceCharacter::CHARACTER_KNIGHT;
	m_bDraw = false;
	m_nCntLevel = 0;
	ZeroMemory(&m_apTex, sizeof(m_apTex));
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackAreaUi::~CAttackAreaUi()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CAttackAreaUi * CAttackAreaUi::Create(D3DXVECTOR3 pos)
{
	// メモリの確保
	CAttackAreaUi *pPointa;
	pPointa = new CAttackAreaUi;
	// 初期化
	pPointa->Init();

	// 各値の代入
	pPointa->SetPos(pos);

	return pPointa;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CAttackAreaUi::Init(void)
{
	// 初期化処理
	CScene2d::Init();

	// 初期化
	m_nLevel = 0;
	m_nCharaType = CResourceCharacter::CHARACTER_KNIGHT;
	m_bDraw = false;
	m_nCntLevel = 0;

	// 騎士
    m_apTex[CResourceCharacter::CHARACTER_KNIGHT][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT1);
	m_apTex[CResourceCharacter::CHARACTER_KNIGHT][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT2);
	m_apTex[CResourceCharacter::CHARACTER_KNIGHT][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_KNIGHT3);
	// 槍
    m_apTex[CResourceCharacter::CHARACTER_LANCER][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER1);
    m_apTex[CResourceCharacter::CHARACTER_LANCER][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER2);
    m_apTex[CResourceCharacter::CHARACTER_LANCER][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_LANCER3);
	// 魔法
    m_apTex[CResourceCharacter::CHARACTER_WIZARD][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD1);
    m_apTex[CResourceCharacter::CHARACTER_WIZARD][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD2);
    m_apTex[CResourceCharacter::CHARACTER_WIZARD][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_WIZARD3);
	// 盗賊
    m_apTex[CResourceCharacter::CHARACTER_THIEF][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF1);
    m_apTex[CResourceCharacter::CHARACTER_THIEF][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF2);
    m_apTex[CResourceCharacter::CHARACTER_THIEF][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_THIEF3);
	// 奇術師
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN1);
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN2);
    m_apTex[CResourceCharacter::CHARACTER_MAGICIAN][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_MAGICIAN3);
	// 弓
    m_apTex[CResourceCharacter::CHARACTER_ARCHER][0] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER1);
    m_apTex[CResourceCharacter::CHARACTER_ARCHER][1] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER2);
    m_apTex[CResourceCharacter::CHARACTER_ARCHER][2] = CResourceTexture::GetTexture(CResourceTexture::TEXTURE_ATTACK_AREA_ARCHER3);

	SetSize(SIZE);
	SetColor(COLOR);
	return S_OK;
}

//=============================================================================
// 更新処理
//=============================================================================
void CAttackAreaUi::Update(void)
{
	// カウントを進める
	m_nCntLevel++;
	if (m_nCntLevel > LEVEL_CHANGE_COUNT)
	{
		// カウントの初期化
		m_nCntLevel = 0;
		// レベルを進める
		m_nLevel++;
		if (m_nLevel >= (MAX_ATTACK_LEVEL - 1))
		{
			m_nLevel = 0;
		}

        if (m_nCharaType == CResourceCharacter::CHARACTER_NONE) return;
		// テクスチャの切り替え
		BindTexture(m_apTex[m_nCharaType][m_nLevel]);
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CAttackAreaUi::Draw(void)
{
	// 描画処理
	if(m_bDraw) CScene2d::Draw();
}

//=============================================================================
// リセット
//=============================================================================
void CAttackAreaUi::Reset(void)
{
	// カウントの初期化
	m_nLevel = 0;
    // テクスチャの切り替え
    BindTexture(m_apTex[m_nCharaType][m_nLevel]);
}

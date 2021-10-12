//=============================================================================
//
// color_managerヘッダ [color_manager.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _COLOR_MANAGER_H_
#define _COLOR_MANAGER_H_

//*****************************
// インクルード
//*****************************
#include "manager.h"

//*****************************
//前方宣言
//*****************************

//*****************************
//マクロ定義
//*****************************
#define COLOR_STEP_NUM 3
#define GET_COLORMANAGER CColorManager::GetColorManager()

//*****************************
// クラス定義
//*****************************

// 色管理クラス
class CColorManager
{
private:
	//コンストラクタ
	CColorManager();
public:
	typedef struct
	{
		D3DXCOLOR aCol[COLOR_STEP_NUM];
		D3DXCOLOR iconColor;
	}ColorData;

	//メンバ関数
	~CColorManager();
	static CColorManager *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	static void Release(void);

	// 取得処理
	static CColorManager*GetColorManager(void) { return m_pInstance; }
	D3DXCOLOR GetStepColor(int nIndex, int nStep) { return m_aColorData[nIndex].aCol[nStep]; }

private:
	void LoadText(void); // テキストデータの読み込み

	// メンバ変数
	static CColorManager * m_pInstance;  // インスタンス
	std::vector<ColorData> m_aColorData; // カラーデータ
};

#endif
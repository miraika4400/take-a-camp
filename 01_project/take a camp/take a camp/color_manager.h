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

private:
	void LoadText(void);

	// メンバ変数
	static CColorManager * m_pInstance;
	static std::vector<ColorData> m_aColorData;
};

#endif
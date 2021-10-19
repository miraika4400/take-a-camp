//=============================================================================
//
// 攻撃管理クラス [attack_manager.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _ATTACK_MANAGER_H_
#define _ATTACK_MANAGER_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_ATTACK_SIZE_X	(5)	//最大ブロック数
#define MAX_ATTACK_SIZE_Y	(5)	//最大ステージサイズ

//=============================================================================
// クラス定義
//=============================================================================
class CAttackManager
{
public:
	typedef struct	//一行の攻撃範囲情報
	{
		int			nRangeType[MAX_ATTACK_SIZE_X];	// ブロックデータ
		int			nAttackRangeX;					// その行のブロック数
	}RANGE_DATA;

	typedef struct	//攻撃情報
	{
		RANGE_DATA	RangeData[MAX_ATTACK_SIZE_Y];	// ブロック
		int			nAttackRangeY;					// ブロックの列
		D3DXVECTOR3	m_pos;							// 位置		
	}ATTACK_DATA;

	typedef enum	//攻撃タイルの種類
	{
		ATTACK_RANGE_NONE = 0,	//なし
		ATTACK_RANGE_CENTER,	//中心
		ATTACK_RANGE_HIT,		//攻撃
	}ATTACK_RANGE_TYPE;

	typedef enum	//攻撃の種類
	{
		ATTACK_TYPE_1 = 0,	//なし
		ATTACK_TYPE_2,
		ATTACK_TYPE_3,
		ATTACK_TYPE_4,
		ATTACK_TYPE_MAX
	}ATTACK_TYPE;

	//関数定義
	CAttackManager();
	~CAttackManager();
	static CAttackManager * Create(void);	// クラス生成
	static void Release(void);				// クラス破棄
	static ATTACK_DATA GetAttackData(ATTACK_TYPE Attack);

private:
	void	Load(void);		//攻撃範囲読み込み

	static char*	m_pFileName[ATTACK_TYPE_MAX];	// ファイルネーム
	static CAttackManager* m_pAttackBasis;				// 攻撃範囲クラスのポインタ
	ATTACK_DATA	m_AttackData[ATTACK_TYPE_MAX];			// 攻撃の情報
};
#endif
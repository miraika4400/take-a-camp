//=============================================================================
//
// 必殺技範囲読み込みクラスヘッダー [resource_final_attack.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _RESOURCE_FINAL_ATTACK_H_
#define _RESOURCE_FINAL_ATTACK_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "model.h"
#include "scene.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_FINAL_ATTACK_SIZE_X	(20)	//最大ブロック数
#define MAX_FINAL_ATTACK_SIZE_Y	(20)	//最大ステージサイズ
#define MAX_FINAL_HIT_TYPE			(4)		//ヒットマスタイプの最大数
//=============================================================================
// クラス定義
//=============================================================================
class CFinalAttackManager
{
public:
	typedef struct	//一行の攻撃範囲情報
	{
		int			nRangeType[MAX_FINAL_ATTACK_SIZE_X];	// ブロックデータ
		int			nAttackRangeX;							// その行のブロック数
	}RANGE_DATA;

	typedef struct	//攻撃情報
	{
		RANGE_DATA	RangeData[MAX_FINAL_ATTACK_SIZE_Y];	// ブロック
		int			nAttackRangeY;						// ブロックの列
		int			nAttackFrame[MAX_FINAL_HIT_TYPE];			// フレーム数の保存
	}FINAL_ATTACK_RANGE_DATA;


	typedef enum	//攻撃タイルの種類
	{
		FINAL_ATTACK_RANGE_NONE = 0,//なし
		FINAL_ATTACK_RANGE_CENTER,	//中心
		FINAL_ATTACK_RANGE_HIT_1,	//攻撃(数値が上がるほど後に攻撃する)
		FINAL_ATTACK_RANGE_HIT_2,
		FINAL_ATTACK_RANGE_HIT_3,
		FINAL_ATTACK_RANGE_HIT_4,
		FINAL_ATTACK_RANGE_HIT_5,
		FINAL_ATTACK_RANGE_HIT_6,
		FINAL_ATTACK_RANGE_HIT_7,
		FINAL_ATTACK_RANGE_HIT_8
	}FINAL_ATTACK_RANGE_TYPE;

	typedef struct	//攻撃マス目情報
	{
		FINAL_ATTACK_RANGE_TYPE	RangeType;	//攻撃マスタイプ 
		D3DXVECTOR3				AttackPos;	//攻撃のマス位置
	}SQUARE_DATA;

	typedef struct	//攻撃マス全体の情報
	{
		int			nMaxHitRange;													// 最大ヒットマス
		SQUARE_DATA SquareData[MAX_FINAL_ATTACK_SIZE_Y*MAX_FINAL_ATTACK_SIZE_X];	// 攻撃のマスデータ[読み込み限界の縦横]
		int			nAttackFrame[MAX_FINAL_HIT_TYPE];										// 攻撃速度
	}FINAL_ATTACK_SQUARE_DATA;

	typedef enum	//攻撃の種類
	{
		FINAL_ATTACK_TYPE_1 = 0,	//なし
		FINAL_ATTACK_TYPE_2,
		FINAL_ATTACK_TYPE_3,
		FINAL_ATTACK_TYPE_4,
		FINAL_ATTACK_TYPE_MAX
	}FINAL_ATTACK_TYPE;

	//関数定義
	CFinalAttackManager();
	~CFinalAttackManager();
	static CFinalAttackManager * Create(void);	// クラス生成
	static void Release(void);					// クラス破棄
	static FINAL_ATTACK_RANGE_DATA GetFinalAttackData(FINAL_ATTACK_TYPE Attack);
	static FINAL_ATTACK_SQUARE_DATA GetFinalAttack(FINAL_ATTACK_TYPE AttackType);

private:
	void	Load(void);		//攻撃範囲読み込み
	void	PosCalc(void);	//位置計算

	static char*				m_pFileName[FINAL_ATTACK_TYPE_MAX];		// ファイルネーム
	static CFinalAttackManager*	m_pAttackBasis;							// 攻撃範囲クラスのポインタ
	FINAL_ATTACK_RANGE_DATA		m_AttackData[FINAL_ATTACK_TYPE_MAX];	// 攻撃の情報
	FINAL_ATTACK_SQUARE_DATA	m_AttackSwuare[FINAL_ATTACK_TYPE_MAX];	// 攻撃マスの情報

};
#endif
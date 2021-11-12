//=============================================================================
//
// resource_characterヘッダ [resource_character.h]
// Author : 増澤 未来
//
//=============================================================================

//二重インクルード防止
#ifndef _RESOURCE_CHARACTER_H_
#define _RESOURCE_CHARACTER_H_

//*****************************
//インクルード
//*****************************
#include "main.h"
#include "player.h"
#include "resource_model_hierarchy.h"

//*****************************
// マクロ定義
//*****************************
#define ATTACK_PATTARN_NUM (4) // 攻撃パターン数

//*****************************
//クラス定義
//*****************************

//テクスチャクラス
class CResourceCharacter
{
public:

	// 列挙
	// テクスチャ種類
	typedef enum
	{
		CHARACTER_KNIGHT = 0,  // 騎士
		CHARACTER_LANCER,      // 槍兵
		CHARACTER_WIZARD,      // 魔術師
		CHARACTER_MAX // キャラクタ数
	}CHARACTER_TYPE;

	// 構造体定義
	//characterデータ
	typedef struct
	{
		CResourceModelHierarchy::MODEL_HIERARCHY_TYPE modelType; // モデルタイプ番号
		int nMoveFrame;                        // 移動フレーム数
		int nMoveFrameDash;                    // 移動フレーム数*ダッシュ時
		std::string attackTextPath;            // 攻撃テキストのパス
		std::string finalAttackPath;           // 必殺技テキストのパス
		int nFinalAttackTime;                  // 必殺技発動可能時間
		int anChargeTime[ATTACK_PATTARN_NUM];  // 各攻撃のチャージタイムのリスト
		std::string aMotionTextPath[CPlayer::MOTION_MAX]; // モーションファイルパスリスト
	}CharacterData;

	// キャラクターラベルデータ
	typedef struct
	{
		std::string labelName; // ラベルネーム
		CResourceModelHierarchy::MODEL_HIERARCHY_TYPE modelType; // モデルタイプ
	}LabelData;

private:
	CResourceCharacter();  //隠しコンストラクタ
public:
	~CResourceCharacter(); // デストラクタ
	// メンバ関数
	static CResourceCharacter * Create(void); // クラス生成
	static void Release(void);                // クラス破棄

private:
	void Load(void); // テクスチャ読み込み

	// メンバ変数
	static CResourceCharacter* m_pInstance;           // インスタンスの保持
	static const std::vector<LabelData> m_aLabelList; // キャラクターラベルリスト
	static const std::string m_aCharacterDataTxtPath[CHARACTER_MAX]; // キャラクターデータのテキストのパス
	std::vector<CharacterData> m_aCharacterData;
};

#endif
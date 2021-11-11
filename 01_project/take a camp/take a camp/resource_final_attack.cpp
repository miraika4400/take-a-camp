//=============================================================================
//
// 必殺技範囲読み込みクラス [resource_final_attack.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "resource_final_attack.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define SQUARE_SIZE (20)	//１マス縦横のサイズ

//=============================================================================
// 静的メンバー変数
//=============================================================================
char* CFinalAttackManager::m_pFileName[FINAL_ATTACK_TYPE_MAX] =
{
	"data/Text/final_attack_1.csv" ,
	"",
	"",
	""
};
CFinalAttackManager* CFinalAttackManager::m_pAttackBasis = NULL;
//=============================================================================
// コンストラクタ
//=============================================================================
CFinalAttackManager::CFinalAttackManager()
{
	memset(&m_AttackData, 0, sizeof(m_AttackData));
	memset(&m_AttackSwuare, 0, sizeof(m_AttackSwuare));

}

//=============================================================================
// デストラクタ
//=============================================================================
CFinalAttackManager::~CFinalAttackManager()
{
}


//=============================================================================
// ロード関数
//=============================================================================
void CFinalAttackManager::Load(void)
{
	for (int nAttack = 0; nAttack < FINAL_ATTACK_TYPE_MAX; nAttack++)
	{
		//ファイルポインタ
		FILE*	pFile = NULL;
		//読み込み用データ
		char cFileString[258];
		//文字認識
		int nFileText;
		//列、行
		int nCol, nRow;
		//初期化
		pFile = NULL;
		nCol = 1;
		nRow = 0;

		//初期化
		memset(cFileString, 0, sizeof(cFileString));

		//ファイル読み込み
		fopen_s(&pFile, m_pFileName[nAttack], "r");

		if (pFile != NULL)
		{
			//ヘッダー読み飛ばし
			while (fgetc(pFile) != '\n');

			while (1)
			{
				while (1)
				{
					nFileText = fgetc(pFile);

					//末尾ならループを抜ける。
					if (nFileText == EOF)
					{
						goto out;
					}
					//カンマか改行でなければ、文字としてつなげる
					if (nFileText != ',' && nFileText != '\n')
					{
						strcat_s(cFileString, (const char*)&nFileText);
					}
					//カンマか改行ならループ抜ける。
					else
					{
						break;
					}
				}
				//文字列読み込み
				switch (atoi(cFileString))
				{
				case FINAL_ATTACK_RANGE_NONE:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_NONE;
					break;
				case FINAL_ATTACK_RANGE_CENTER:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_CENTER;
					break;
				case FINAL_ATTACK_RANGE_HIT_1:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_1;
					break;
				case FINAL_ATTACK_RANGE_HIT_2:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_2;
					break;
				case FINAL_ATTACK_RANGE_HIT_3:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_3;
					break;
				case FINAL_ATTACK_RANGE_HIT_4:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_4;
					break;
				case FINAL_ATTACK_RANGE_HIT_5:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_5;
					break;
				case FINAL_ATTACK_RANGE_HIT_6:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_6;
					break;
				case FINAL_ATTACK_RANGE_HIT_7:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_7;
					break;
				case FINAL_ATTACK_RANGE_HIT_8:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = FINAL_ATTACK_RANGE_HIT_8;
					break;

				}
				//攻撃タイプごとの速度
				if (strcmp(cFileString, "AttackFrame") == 0)
				{
					fscanf_s(pFile, "Ⅰ:%d,Ⅱ:%d,Ⅲ:%d,Ⅳ:%d,Ⅴ:%d,Ⅵ:%d,Ⅶ:%d,Ⅷ:%d",
						&m_AttackData[nAttack].nAttackFrame[0],
						&m_AttackData[nAttack].nAttackFrame[1],
						&m_AttackData[nAttack].nAttackFrame[2],
						&m_AttackData[nAttack].nAttackFrame[3],
						&m_AttackData[nAttack].nAttackFrame[4],
						&m_AttackData[nAttack].nAttackFrame[5],
						&m_AttackData[nAttack].nAttackFrame[6],
						&m_AttackData[nAttack].nAttackFrame[7]);
				}

				//バッファの初期化
				memset(cFileString, 0, sizeof(cFileString));
				//列数を足す
				nCol++;


				//もし読み込んだ文字が改行だったら列数を初期化して行数を増やす
				if (nFileText == '\n')
				{
					//行数保存
					m_AttackData[nAttack].RangeData[nRow].nAttackRangeX = nCol;
					//行数初期化
					nCol = 1;
					//列の進行
					nRow++;
				}

			}

		out:								//末尾ならここに跳ぶ
			m_AttackData[nAttack].nAttackRangeY = nRow;	//ブロック数を保存
			fclose(pFile);					//ファイルを閉じる
		}
	}

}

//=============================================================================
// 位置の計算関数
//=============================================================================
void CFinalAttackManager::PosCalc(void)
{
	for (int nAttack = 0; nAttack < FINAL_ATTACK_TYPE_MAX; nAttack++)
	{
		//攻撃マス用変数
		D3DXVECTOR3 RangePos[MAX_FINAL_ATTACK_SIZE_Y*MAX_FINAL_ATTACK_SIZE_X] = {};
		//プレイヤーがいる中心マス用変数
		D3DXVECTOR3 Center = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//マップデータがあるか
		if (&m_AttackData[nAttack] != NULL)
		{
			// 位置取得
			for (int nBlockY = 0; nBlockY < m_AttackData[nAttack].nAttackRangeY; nBlockY++)
			{
				for (int nBlockX = 0; nBlockX < m_AttackData[nAttack].RangeData[nBlockY].nAttackRangeX; nBlockX++)
				{
					//マス目のタイプ取得
					switch (m_AttackData[nAttack].RangeData[nBlockY].nRangeType[nBlockX])
					{
					case CFinalAttackManager::FINAL_ATTACK_RANGE_NONE:		//なし
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_CENTER:	//プレイヤーがいる中心ます
						Center = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_1:	//攻撃範囲
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_1;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_2:	//攻撃範囲
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_2;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;

					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_3:	//攻撃範囲
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_3;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;

					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_4:	//攻撃範囲
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_4;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_5:	/*攻撃範囲*/
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_5;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_6:	/*攻撃範囲*/
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_6;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_7:	/*攻撃範囲*/
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_7;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					case CFinalAttackManager::FINAL_ATTACK_RANGE_HIT_8:	/*攻撃範囲*/
																//位置取得
						RangePos[m_AttackSwuare[nAttack].nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].SquareData[m_AttackSwuare[nAttack].nMaxHitRange].RangeType = FINAL_ATTACK_RANGE_HIT_8;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].nMaxHitRange++;
						break;
					default:
						break;
					}
				}
			}
			//攻撃速度の取得
			for (int nAttackFrame = 0; nAttackFrame < MAX_FINAL_HIT_TYPE; nAttackFrame++)
			{
				m_AttackSwuare[nAttack].nAttackFrame[nAttackFrame] = m_AttackData[nAttack].nAttackFrame[nAttackFrame];
			}

			// 位置計算
			for (int nAttackPos = 0; nAttackPos < m_AttackSwuare[nAttack].nMaxHitRange; nAttackPos++)
			{
				m_AttackSwuare[nAttack].SquareData[nAttackPos].AttackPos = RangePos[nAttackPos] - Center;
			}
		}

	}

}

//=============================================================================
// クラス生成
//=============================================================================
CFinalAttackManager * CFinalAttackManager::Create(void)
{
	// NULLチェック
	if (m_pAttackBasis == NULL)
	{
		//メモリ確保
		m_pAttackBasis = new CFinalAttackManager;

		if (m_pAttackBasis != NULL)
		{
			// メモリ確保成功
			m_pAttackBasis->Load();
			// 位置計算
			m_pAttackBasis->PosCalc();
		}
		else
		{
			// メモリ確保失敗
			return NULL;
		}
	}

	return m_pAttackBasis;
}

//=============================================================================
// クラス破棄
//=============================================================================
void CFinalAttackManager::Release(void)
{
	if (m_pAttackBasis != NULL)
	{
		// メモリの破棄
		delete m_pAttackBasis;
		m_pAttackBasis = NULL;
	}
}

//=============================================================================
// 攻撃範囲ゲッター生成
//=============================================================================
CFinalAttackManager::FINAL_ATTACK_RANGE_DATA CFinalAttackManager::GetFinalAttackData(FINAL_ATTACK_TYPE Attack)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackData[Attack];
	}
	else
	{
		return{};
	}
}

//=============================================================================
// 攻撃マス情報ゲッター関数
//=============================================================================
CFinalAttackManager::FINAL_ATTACK_SQUARE_DATA CFinalAttackManager::GetFinalAttack(FINAL_ATTACK_TYPE AttackType)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackSwuare[AttackType];
	}
	else
	{
		return{};
	}
}

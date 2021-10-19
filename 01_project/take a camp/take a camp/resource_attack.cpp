//=============================================================================
//
// 攻撃範囲読み込みクラス [resource_attack.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "resource_attack.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define SQUARE_SIZE (20)	//１マス縦横のサイズ

//=============================================================================
// 静的メンバー変数
//=============================================================================
char* CAttackManager::m_pFileName[ATTACK_TYPE_MAX] =
{
	"data/Text/attack_1.csv" ,
	"",
	"",
	""
};
CAttackManager* CAttackManager::m_pAttackBasis = NULL;
//=============================================================================
// コンストラクタ
//=============================================================================
CAttackManager::CAttackManager()
{
	memset(&m_AttackData, 0, sizeof(ATTACK_RANGE_DATA[ATTACK_TYPE_MAX]));
	memset(&m_AttackSwuare,0,sizeof(ATTACK_SQUARE_DATA[ATTACK_TYPE_MAX]));
	
}

//=============================================================================
// デストラクタ
//=============================================================================
CAttackManager::~CAttackManager()
{
}


//=============================================================================
// ロード関数
//=============================================================================
void CAttackManager::Load(void)
{
	for (int nAttack = 0; nAttack < ATTACK_TYPE_MAX; nAttack++)
	{
		//ファイルポインタ
		FILE*	pFile = NULL;
		//読み込み用データ
		char cFileString[258];
		//文字認識
		int nFileText;
		//列、行
		int nCol, nRow;
		//ブロック数
		int nBlock;
		//初期化
		pFile = NULL;
		nCol = 1;
		nRow = 0;
		nBlock = 0;
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
				case ATTACK_RANGE_NONE:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_NONE;
					break;
				case ATTACK_RANGE_CENTER:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_CENTER;
					break;
				case ATTACK_RANGE_HIT_1:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_1;
					break;
				case ATTACK_RANGE_HIT_2:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_2;
					break;
				case ATTACK_RANGE_HIT_3:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_3;
					break;
				case ATTACK_RANGE_HIT_4:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT_4;
					break;

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
void CAttackManager::PosCalc(void)
{
	for (int nAttack = 0; nAttack < ATTACK_TYPE_MAX; nAttack++)
	{
		//攻撃マス用変数
		D3DXVECTOR3 RangePos[MAX_ATTACK_SIZE_Y*MAX_ATTACK_SIZE_X] = {};
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
					case CAttackManager::ATTACK_RANGE_NONE:		//なし
						break;
					case CAttackManager::ATTACK_RANGE_CENTER:	//プレイヤーがいる中心ます
						Center = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						break;
					case CAttackManager::ATTACK_RANGE_HIT_1:	//攻撃範囲
						//位置取得
						RangePos[m_AttackSwuare[nAttack].m_nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].m_SquareData[m_AttackSwuare[nAttack].m_nMaxHitRange].m_RangeType = ATTACK_RANGE_HIT_1;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].m_nMaxHitRange++;
						break;
					case CAttackManager::ATTACK_RANGE_HIT_2:	//攻撃範囲
						//位置取得
						RangePos[m_AttackSwuare[nAttack].m_nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].m_SquareData[m_AttackSwuare[nAttack].m_nMaxHitRange].m_RangeType = ATTACK_RANGE_HIT_2;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].m_nMaxHitRange++;
						break;

					case CAttackManager::ATTACK_RANGE_HIT_3:	//攻撃範囲
						//位置取得
						RangePos[m_AttackSwuare[nAttack].m_nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].m_SquareData[m_AttackSwuare[nAttack].m_nMaxHitRange].m_RangeType = ATTACK_RANGE_HIT_3;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].m_nMaxHitRange++;
						break;

					case CAttackManager::ATTACK_RANGE_HIT_4:	//攻撃範囲
						//位置取得
						RangePos[m_AttackSwuare[nAttack].m_nMaxHitRange] = D3DXVECTOR3((float)nBlockX, 0.0f, (float)nBlockY);
						//マスのタイプ取得
						m_AttackSwuare[nAttack].m_SquareData[m_AttackSwuare[nAttack].m_nMaxHitRange].m_RangeType = ATTACK_RANGE_HIT_4;
						//攻撃マスの最大を増やす
						m_AttackSwuare[nAttack].m_nMaxHitRange++;
						break;
					default:
						break;
					}
				}
			}

			// 位置計算
			for (int nAttackPos = 0; nAttackPos < m_AttackSwuare[nAttack].m_nMaxHitRange; nAttackPos++)
			{
				m_AttackSwuare[nAttack].m_SquareData[nAttackPos].m_AttackPos = RangePos[nAttackPos] - Center;
			}
		}

	}

}

//=============================================================================
// クラス生成
//=============================================================================
CAttackManager * CAttackManager::Create(void)
{
	// NULLチェック
	if (m_pAttackBasis == NULL)
	{
		//メモリ確保
		m_pAttackBasis = new CAttackManager;

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
void CAttackManager::Release(void)
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
CAttackManager::ATTACK_RANGE_DATA CAttackManager::GetAttackData(ATTACK_TYPE Attack)
{
	if (m_pAttackBasis != NULL)
	{
		return m_pAttackBasis->m_AttackData[Attack];
	}
	else
	{
		return {};
	}
}

//=============================================================================
// 攻撃マス情報ゲッター関数
//=============================================================================
CAttackManager::ATTACK_SQUARE_DATA CAttackManager::GetAttack(ATTACK_TYPE AttackType)
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

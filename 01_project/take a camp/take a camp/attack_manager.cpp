//=============================================================================
//
// ステージ [stage.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "attack_manager.h"

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
	memset(&m_AttackData, 0, sizeof(ATTACK_DATA[ATTACK_TYPE_MAX]));
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
				case ATTACK_RANGE_HIT:
					m_AttackData[nAttack].RangeData[nRow].nRangeType[nCol] = ATTACK_RANGE_HIT;
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
CAttackManager::ATTACK_DATA CAttackManager::GetAttackData(ATTACK_TYPE Attack)
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


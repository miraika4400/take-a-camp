////////////////////////////////////////////////////
//
//    アイテムクラスの処理[item.cpp]
//    Author:西潟栞那汰
//
////////////////////////////////////////////////////

//******************************
// インクルード
//******************************
#include "build.h"
#include "manager.h"
#include "keyboard.h"
#include "shadow.h"

//*****************************
// マクロ定義
//*****************************
#define MODEL_SIZE		(D3DXVECTOR3( 0.6f, 0.6f, 0.6f))
#define ITEM_ONE_SIDE	(10.0f)

//******************************
// コンストラクタ
//******************************
CBuild::CBuild() : CModel(OBJTYPE_ITEM)
{
	m_rot = D3DXVECTOR3(0.5f, 0.5f, 0.5f);//角度
	m_move = D3DXVECTOR3(0.5f, 0.5f, 0.5f);//移動

	m_pShadow = NULL;		//影のポインタ

	m_bUp = false;			//上限判定
}

//******************************
// デストラクタ
//******************************
CBuild::~CBuild()
{
}

//******************************
// クラス生成
//******************************
CBuild * CBuild::Create(D3DXVECTOR3 pos, BUILD_TYPE type, BUILD_BOOL bBuild)
{
	//メモリの確保
	CBuild *pBuild;
	pBuild = new CBuild;

	//効果処理セット
	pBuild->SetBuildType(type);

	//初期化処理
	pBuild->Init();

	pBuild->SetBuildBool(bBuild);
	//位置セット
	pBuild->SetPos(pos);

	//影生成
	pBuild->m_pShadow = CShadow::Create(D3DXVECTOR3(pos.x, 0.2f, pos.z), D3DXVECTOR3(8.0f, 0.0f, 8.0f));

	return pBuild;
}

//******************************
// 初期化処理
//******************************
HRESULT CBuild::Init(void)
{
	//モデル初期化
	CModel::Init();

	// モデル割り当て
	switch (m_BuildType)
	{
	case BUILD_TYPE_0:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ITEM_DASH));
		break;
	case BUILD_TYPE_1:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ITEM_REVERSE));
		break;
	default:
		break;
	}

	// モデルのサイズの設定
	SetSize(MODEL_SIZE);

	return E_NOTIMPL;
}

//******************************
// 終了処理
//******************************
void CBuild::Uninit(void)
{
	//モデルの終了処理
	CModel::Uninit();
}

//******************************
// 更新処理
//******************************
void CBuild::Update(void)
{
	if (m_BuildBool == BUILD_TRUE)
	{
		//上下の移動
		MoveUpdate();
		//回転
		RotUpdate();
	}
}

//******************************
// 描画処理
//******************************
void CBuild::Draw(void)
{
	//モデルの描画
	CModel::Draw();
}

//******************************
// 移動の更新処理
//******************************
void CBuild::MoveUpdate(void)
{
	//位置の取得
	D3DXVECTOR3 BuildPos = GetPos();

	if (CManager::GetKeyboard()->GetKeyPress(DIK_W))
	{
		//
		BuildPos.z -= m_move.z;
	}
	if (CManager::GetKeyboard()->GetKeyPress(DIK_S))//
	{
		//
		BuildPos.z += m_move.z;
	}	
	if (CManager::GetKeyboard()->GetKeyPress(DIK_D))//
	{
		//
		BuildPos.x -= m_move.x;
	}	
	if (CManager::GetKeyboard()->GetKeyPress(DIK_A))//
	{
		//
		BuildPos.x += m_move.x;
	}
	if (CManager::GetKeyboard()->GetKeyPress(DIK_SPACE))//
	{
		//
		BuildPos.y += m_move.y;
	}
	if (CManager::GetKeyboard()->GetKeyPress(DIK_LSHIFT))//
	{
		//
		BuildPos.y -= m_move.y;
	}
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_RETURN))
	{
		Save();
		m_BuildBool = BUILD_FALSE;
	}
	//位置の再設定
	SetPos(BuildPos);
}

//******************************
// 回転の更新処理
//******************************
void CBuild::RotUpdate(void)
{
	//角度の取得
	D3DXVECTOR3 BuildRot = GetRot();
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_Q))
	{
		BuildRot.y += m_rot.y;
	}
	if (CManager::GetKeyboard()->GetKeyTrigger(DIK_E))
	{
		BuildRot.y -= m_rot.y;
	}
	//角度の設定
	SetRot(BuildRot);
}

void CBuild::Save(void)
{
	FILE* pFile = NULL;
	D3DXVECTOR3 buildPos = GetPos();

	pFile = fopen("data/BuildingInfo.txt", "a");
	if (pFile != NULL)
	{
		fprintf(pFile, "%d\n", m_BuildType);
		fprintf(pFile, "%d %d %d\n", (int)buildPos.x, (int)buildPos.y, (int)buildPos.z);
		fclose(pFile);
	}

}

void CBuild::Load(void)
{
	FILE* pFile = NULL;
	D3DXVECTOR3 buildPos = {};
	BUILD_TYPE type = BUILD_TYPE_0;
	BUILD_BOOL bBuild = BUILD_FALSE;

	pFile = fopen("data/BuildingInfo.txt", "r");

	if (pFile != NULL)
	{
		while (fscanf(pFile, "%d", &type) != EOF)
		{

			fscanf(pFile, "%f %f %f", &buildPos.x, &buildPos.y, &buildPos.z);
			CBuild::Create(buildPos, type, bBuild);
		}

	}
	fclose(pFile);
}


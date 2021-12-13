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
	case BUILD_TYPE_TREE:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_TREE));
		break;
	case BUILD_TYPE_MATO:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_MATO));
		break;
	case BUILD_TYPE_BUKIKAKE:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_BUKITATE));
		break;
	case BUILD_TYPE_CHEST:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_CHEST));
		break;
	case BUILD_TYPE_TARU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODLE_TARU));
		break;
	case BUILD_TYPE_GAITOU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_GAITOU));
		break;
	case BUILD_TYPE_HATA:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_HATA));
		break;
	case BUILD_TYPE_SAKU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_SAKU));
		break;
	case BUILD_TYPE_ENOGU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ENOGU));
		break;
	case BUILD_TYPE_ENPITU:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_ENPITU));
		break;
	case BUILD_TYPE_MAGCUP:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_MAGCUP));
		break;
	case BUILD_TYPE_MOKUZIN:
		BindModel(CResourceModel::GetModel(CResourceModel::MODEL_MOKUZIN));
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
	BUILD_TYPE type = BUILD_TYPE_TREE;
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


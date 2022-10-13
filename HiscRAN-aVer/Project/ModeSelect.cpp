#include "ModeSelect.h"
#include "GameApp.h"

//変更するシーン（外部参照、実態はGameApp.cpp）
extern int	gChangeScene;

#define MenuCnt (4)

int MenuNow = 0;

//コンストラクタ
ModeSelect::ModeSelect() {}

//デストラクタ
ModeSelect::~ModeSelect()
{

}

//初期化
void  ModeSelect::Initialize()
{

}

//ロード
void ModeSelect::Load()
{

}

//更新
void ModeSelect::Update()
{
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
	}
	//F2キーでチュートリアル画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		gChangeScene = SCENENO_TUTORIAL;
	}
	//F3キーでゲーム画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		gChangeScene = SCENENO_GAME;
	}
	//F4キーでギャラリー画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F4))
	{
		gChangeScene = SCENENO_GALLERY;
	}
	//F5キーでオプション画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F5))
	{
		gChangeScene = SCENENO_OPTION;
	}

	//矢印キー下で選択が下がるようにする
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		if (MenuNow < MenuCnt - 1)
		{
			++MenuNow;
		}
	}
	//矢印キー上で選択が上がるようにする
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		if (MenuNow > 0)
		{
			--MenuNow;
		}
	}

	//エンターを押したら各画面へ移動
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		switch (MenuNow)
		{
		case 0:
			gChangeScene = SCENENO_TUTORIAL;
			break;

		case 1:
			gChangeScene = SCENENO_GAME;
			break;

		case 2:
			gChangeScene = SCENENO_GALLERY;
			break;

		case 3:
			gChangeScene = SCENENO_OPTION;
		}
	}
}

void ModeSelect::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "モードセレクト画面");
	CGraphicsUtilities::RenderString(10, 40, "Enterキーで画面遷移");
	CGraphicsUtilities::RenderString(10, 70, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 100, "F2キーでチュートリアル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 130, "F3キーでゲーム画面へ遷移");
	CGraphicsUtilities::RenderString(10, 160, "F4キーでギャラリー画面へ遷移");
	CGraphicsUtilities::RenderString(10, 190, "F5キーでオプション画面へ遷移");


	const char* MenuString[MenuCnt] =
	{
		"チュートリアル(入学説明)",
		"ゲーム開始（入学）",
		"ギャラリー（図書室）",
		"オプション（ホームルーム）",
	};

	MofU32 color[MenuCnt];

	for (int i = 0; i < MenuCnt; i++)
	{
		color[i] = MOF_COLOR_BLACK;
	}

	color[MenuNow] = MOF_COLOR_HRED;

	//文字描画
	for (int i = 0; i < MenuCnt; ++i)
	{
		CGraphicsUtilities::RenderString(400, 300 + 40 * i, color[i], MenuString[i]);
	}
}

void ModeSelect::Release(void)
{

}
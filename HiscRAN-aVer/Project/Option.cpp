#include "Option.h"
#include "GameApp.h"

//変更するシーン（外部参照、実態はGameApp.cpp）
extern int			gChangeScene;

Option::Option() {}

Option::~Option()
{

}

//初期化
void Option::Initialize(void)
{

}

//更新
void Option::Update(void)
{
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
	}
	//エンターキーでモードセレクト画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}
}

//描画
void Option::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "オプション画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");
}

//素材読み込み
void Option::Load(void)
{

}

//素材解放
void Option::Release(void)
{

}
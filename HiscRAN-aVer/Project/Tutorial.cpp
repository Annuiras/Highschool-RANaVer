#include "Tutorial.h"
#include "Define.h"

CTutorial::CTutorial() :
	Texture(),
	ScreenTexture(),
	BGTexture(),
	BackButton(),
	ButtonSelect(),
	m_Scroll(0.0f),
	gPosX(0.0f),
	count(0.0f),
	MoveX(0.0f),
	bShow(false)
{

}

CTutorial::~CTutorial()
{

}

//素材読み込み
bool CTutorial::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Tutorial");

	if (!Texture.Load("tutorialBG.png"))
	{
		return false;
	}

	if (!BGTexture.Load("TutorialMak.png"))
	{
		return false;
	}

	if (!ScreenTexture.Load("tutorialScreen.png"))
	{
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	if (!BackButton.Load("BackButton.png"))
	{
		return false;
	}

	if (!ButtonSelect.Load("Select_s.png"))
	{
		return false;
	}

	return true;

}

//初期化
void CTutorial::Initialize(CGameProgMgmt* mamt)
{
	m_Scroll = 0;
	count = 0;
	MoveX = 0;
	gPosX = 0;
	bShow = false;
	m_GameProgMamt = mamt;
	Load();
}

//更新
void CTutorial::Update(void)
{

	//チュートリアル画像最大枚数以下
	//動いているフラグがFALSE（動いていないという意味になる）
	//右矢印キーを押している
	//だったら、カウントしてページ送りする
	if (count < 5 && bShow == false && g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		count = count + 1;
		MoveX = -20;
		bShow = true;
	}

	//-1以上（変数の関係上、0が1枚目の意味になるため）
	//動いているフラグがFALSE（動いていない）
	//左矢印キーを押している
	//だったら、カウントしてページ送りする
	else if (count > -1 && bShow == false && g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		count = count - 1;
		MoveX = 20;
		bShow = true;
	}

	//実際に座標を動かす
	m_Scroll += MoveX;
	gPosX += MoveX;

	//1280×カウントの数値で止める
	//カウントが-1もしくは4の場合は、戻るボタンに飛ぶのでそもそも移動がない
	if (m_Scroll == -1280 * count || m_Scroll == 1280 * count || count == -1 || count == 5)
	{
		MoveX = 0;
		bShow = false;

		if (count == -1 || count == 0)
		{
			gPosX = 0;
		}
		else if (count == 4 || count == 5)
		{
			gPosX = -5120;
		}
	}

	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//エンターキーでモードセレクト画面へ
	if (count == 5 && g_pInput->IsKeyPush(MOFKEY_RETURN) || count == -1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

}

//描画
void CTutorial::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "チュートリアル画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	Texture.Render(gPosX, 0);

	ScreenTexture.Render(0, 0);
	BGTexture.Render(0, 0);

	BackButton.Render(60, 650);

	if (count == 5 || count == -1)
	{
		ButtonSelect.Render(60, 650);
	}

}

void CTutorial::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "チュートリアル画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");
	CGraphicsUtilities::RenderString(10, 100, "0→左矢印画像カーソル　　5→右矢印画像カーソル");
	if (bShow == true)
	{
		CGraphicsUtilities::RenderString(10, 130, MOF_COLOR_BLACK, "フラグTrue");
	}
	else if (bShow == false)
	{
		CGraphicsUtilities::RenderString(10, 130, MOF_COLOR_BLACK, "フラグFalse");
	}
	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "ページ数:%d", count);
}



//素材解放
void CTutorial::Release(void)
{
	ScreenTexture.Release();
	Texture.Release();
	BGTexture.Release();
	BackButton.Release();
	ButtonSelect.Release();
}

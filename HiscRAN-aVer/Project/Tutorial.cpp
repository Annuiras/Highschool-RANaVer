#include "Tutorial.h"

CTutorial::CTutorial() :
	BGTexture(),
	CurtainBGTexture(),
	BackButton(),
	ButtonSelect(),
	m_Scroll(0.0f),
	gPosX(0.0f),
	count(0.0f),
	MoveX(0.0f),
	bShow(false),
	TMenuCnt(0)
{

}

CTutorial::~CTutorial()
{

}

//素材読み込み
void CTutorial::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Tutorial");

	//説明テクスチャ
	if (!ExTextTexture.Load("tutorialBG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//背景テクスチャ
	if (!BGTexture.Load("Tutorial_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//スクリーンテクスチャ
	if (!ScreenTexture.Load("Tutorial_Screen.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ
	if (!CurtainBGTexture.Load("Tutorial_Mak.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ左
	if (!CurtainBGTextureLeft.Load("Tutorial_MakLef.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ右
	if (!CurtainBGTextureRight.Load("Tutorial_MakRig.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ上
	if (!CurtainBGTextureTop.Load("Tutorial_MakTop.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//戻るボタン
	if (!BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//戻るボタン選択枠
	if (!ButtonSelect.Load("BackButton_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//ロード完了
	b_LoadSitu = LOAD_DONE;

}

//初期化
void CTutorial::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//初期化
	m_Scroll = 0;
	count = 0;
	MoveX = 0;
	gPosX = 0;
	bShow = false;

	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;

	//状態を設定
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//素材ロード
	Load();

	//現在のシーンセット
	m_NowScene = SCENENO_TUTORIAL;

}

//更新
void CTutorial::Update(void)
{

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}
	//戻るボタンにカーソル合わせる必要あんまりないかもね～
	//Enterで戻るでええかも

	//チュートリアル画像最大枚数以下
	//動いているフラグがFALSE（動いていないという意味になる）
	//右矢印キーを押している
	//だったら、カウントしてページ送りする
	if (bShow == false && g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		switch (count)
		{
		case -1:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 0:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 1:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 2:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 3:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 4:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 5:
			count = 5;
			TMenuCnt = 1;
			break;
		}
	}
	else if (bShow == false && g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		switch (count)
		{
		case -1:
			count = -1;
			TMenuCnt = 1;
			break;

		case 0:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 1:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 2:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 3:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 4:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			TMenuCnt = 0;
			break;

		case 5:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			TMenuCnt = 0;
			break;
		}
	}
	//矢印キー下を押した時、戻るボタンにカーソルを合わせる
	else if (TMenuCnt == 0 && g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		TMenuCnt = 1;
	}
	//矢印キー上を押した時、カーソルを外す
	else if (TMenuCnt == 1 && g_pInput->IsKeyPush(MOFKEY_UP))
	{

		TMenuCnt = 0;

		if (count == 5)
		{
			count = count - 1;
			MoveX = 20;
			bShow = true;
		}
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

	//エンターキーでモードセレクト画面へ
	if (TMenuCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

}

//描画
void CTutorial::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "チュートリアル画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_COLOR_WHITE);

	ExTextTexture.Render(gPosX, 18);

	//背景画像描画
	BGTexture.Render(0, 0);

	//Screen画像描画
	ScreenTexture.Render(0, 0);

	//幕描画
	CurtainBGTexture.Render(0, 0);

	//幕左
	CurtainBGTextureLeft.Render(-646, 0);

	//幕右
	CurtainBGTextureRight.Render(646, 0);

	//幕上
	CurtainBGTextureTop.Render(0, 0);

	//戻るボタン
	BackButton.Render(60, 650);

	//もしTMenuCntが1なら
	if (TMenuCnt == 1)
	{
		//戻るボタンにカーソルを合わせる
		ButtonSelect.Render(60, 650);
	}

	//フェード用黒背景
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));

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
	ExTextTexture.Release();
	BGTexture.Release();
	ScreenTexture.Release();
	CurtainBGTexture.Release();
	CurtainBGTextureLeft.Release();
	CurtainBGTextureRight.Release();
	CurtainBGTextureTop.Release();
	BackButton.Release();
	ButtonSelect.Release();
}

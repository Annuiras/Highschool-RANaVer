#include "ModeSelect.h"


#define MenuCnt (4)

int MenuNow_Mode = 0;

//コンストラクタ
CModeSelect::CModeSelect() :
	m_TutorialTextTexture(),
	m_Scroll(0.0f)
{

}

//デストラクタ
CModeSelect::~CModeSelect()
{

}

//ロード
void CModeSelect::Load()
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("ModeSelect");

	if (!m_TutorialTextureSmall.Load("ModeSelect_Min.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	
	if (!m_TutorialTextureBig.Load("ModeSelect_Big.png")) 
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialTextTexture.Load("ModeSelect_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialTextBox.Load("ModeSelect_TextBox.png")) 
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialTextTexture.Load("ModeSelectTexture.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;

	}

	if (!m_TutorialBG[0].Load("ModeSelect_AddmissionEx_BG.png")) 
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialBG[1].Load("ModeSelect_Addmission_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	
	if (!m_TutorialBG[2].Load("ModeSelect_Library_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialBG[3].Load("ModeSelect_Broadcasting_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//ロード完了
	b_LoadSitu = LOAD_COMP;
}

//初期化
void  CModeSelect::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CLoad* loma)
{
	m_Scroll = 0;
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;
	m_LoadMamt = loma;

	//素材ロード
	Load();
	//初期化完了
	b_LoadSitu = LOAD_DONE;

	m_NowScene = SCENENO_SELECTMODE;

	m_BakAlph = 255;

	b_Fadein = FADE_IN;

}


//更新
void CModeSelect::Update()
{
	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph);
	}

	g_MusicManager->BGMStart(BGMT_MOOP);

	m_Scroll -= SCROLL_SPEED;

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {
		switch (MenuNow_Mode)
		{
		case 0:
			m_bEnd = true;
			m_NextScene = SCENENO_TUTORIAL;
			break;

		case 1:
			m_bEnd = true;
			m_NextScene = SCENENO_GAME;
			break;

		case 2:
			m_bEnd = true;
			m_NextScene = SCENENO_GALLERY;
			break;

		case 3:
			m_bEnd = true;
			m_NextScene = SCENENO_OPTION;
			break;
		}
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph);
		return;
	}


	//矢印キー下で選択が下がるようにする
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		g_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode < MenuCnt - 1)
		{
			++MenuNow_Mode;
		}
	}
	//矢印キー上で選択が上がるようにする
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		g_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode > 0)
		{
			--MenuNow_Mode;
		}
	}

	//エンターを押したら各画面へ移動
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		g_MusicManager->SEStart(SE_T_DECISION);
		b_Fadein = FADE_OUT;
	}

	//メニューの更新
	if (gMenu.IsShow())
	{
		gMenu.Update();
		if (gMenu.IsEnter())
		{
			if (gMenu.GetSelect() == 0)
			{
				PostQuitMessage(0);
			}
			gMenu.Hide();
		}
	}
	//エスケープキーで終了メニューを表示
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		Menuflag = true;
		gMenu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else
	{
		Menuflag = false;
	}
}

void CModeSelect::Render(void)
{
	//画像を切り取るための矩形
	//下に出す説明文の画像矩形
	CRectangle recTutorialTex(0, 0, 1780, 45);
	CRectangle recGameTex(0, 45, 1780, 90);
	CRectangle recGalleryTex(0, 90, 1780, 135);
	CRectangle recOptionTex(0, 135, 1780, 180);
	

	//メニュー表示用画像の矩形(大)
	CRectangle recTutorialSelbig(0, 0, 477, 188);
	CRectangle recGameSelbig(0, 188, 477, 371);
	CRectangle recGallerySelbig(0, 371, 477, 568);
	CRectangle recOptionSelbig(0, 568, 477, 750);


		//メニュー表示用画像の矩形(小)
	CRectangle recTutorialSelmin(0, 168, 413, 350);
	CRectangle recGameSelmin(0, 0, 413, 168);
	CRectangle recOptionSelmin(0, 350, 413, 523);
	CRectangle recGallerySelmin(0, 523, 413, 700);
	
	//背景描画
	//下のswitch文に入れ込むとレイヤー順の加減でメニュー表示を何度も描画しないといけなくなるので
	//ここで分岐させてます。

	//スクロール
	int W = m_TutorialTextTexture.GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	switch (MenuNow_Mode)
	{
	case 0:
		//背景画像
		m_TutorialBG[0].Render(0, 0);

		//チュートリアル画像(大)
		m_TutorialTextureBig.Render(803, 35, recTutorialSelbig);

		//ゲーム本編画像(小)
		m_TutorialTextureSmall.Render(867, 190, recGameSelmin);

		//ギャラリー画像(小)
		m_TutorialTextureSmall.Render(867, 337, recGallerySelmin);

		//オプション画像(小)
		m_TutorialTextureSmall.Render(867, 489, recOptionSelmin);

		//下に出すテキストの下地
		m_TutorialTextBox.Render(0, 612);

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recTutorialTex);
		}
		break;

	case 1:
		//背景画像
		m_TutorialBG[1].Render(0, 0);

		//チュートリアル画像(小)
		m_TutorialTextureSmall.Render(867, 45, recTutorialSelmin);

		//ゲーム本編画像(大)
		m_TutorialTextureBig.Render(803, 181, recGameSelbig);

		//ギャラリー画像(小)
		m_TutorialTextureSmall.Render(867, 337, recGallerySelmin);

		//オプション画像(小)
		m_TutorialTextureSmall.Render(867, 489, recOptionSelmin);

		//下に出すテキストの下地
		m_TutorialTextBox.Render(0, 612);

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recGameTex);
		}
		break;

	case 2:
		
		//背景画像
		m_TutorialBG[2].Render(0, 0);

		//チュートリアル画像(小)
		m_TutorialTextureSmall.Render(867, 45, recTutorialSelmin);

		//ゲーム本編画像(小)
		m_TutorialTextureSmall.Render(867, 190, recGameSelmin);

		//ギャラリー画像(大)
		m_TutorialTextureBig.Render(803, 330, recGallerySelbig);

		//オプション画像(小)
		m_TutorialTextureSmall.Render(867, 489, recOptionSelmin);

		//下に出すテキストの下地
		m_TutorialTextBox.Render(0, 612);

	
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recGalleryTex);
		}
		break;

	case 3:
		//背景画像
		m_TutorialBG[3].Render(0, 0);

		//チュートリアル画像(小)
		m_TutorialTextureSmall.Render(867, 45, recTutorialSelmin);

		//ゲーム本編画像(小)
		m_TutorialTextureSmall.Render(867, 190, recGameSelmin);

		//ギャラリー画像(小)
		m_TutorialTextureSmall.Render(867, 337, recGallerySelmin);

		//オプション画像(大)
		m_TutorialTextureBig.Render(803, 481, recOptionSelbig);

		//下に出すテキストの下地
		m_TutorialTextBox.Render(0, 612);

	
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recOptionTex);
		}

		
		break;
	}

	//フェードアウト
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 0, 0, 0));


}

void CModeSelect::RenderDebug(void)
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

	color[MenuNow_Mode] = MOF_COLOR_HRED;

	//文字描画
	for (int i = 0; i < MenuCnt; ++i)
	{
		CGraphicsUtilities::RenderString(400, 300 + 40 * i, color[i], MenuString[i]);
	}
}

void CModeSelect::Release(void)
{
	m_TutorialTextureSmall.Release();
	m_TutorialTextureBig.Release();
	for (int i = 0; i < 4; i++) 
	{
		m_TutorialBG[i].Release();
	}
	m_TutorialTextTexture.Release();
	m_TutorialTextBox.Release();
	gMenu.Release();

	g_MusicManager->BGMStop(BGMT_MOOP);

}
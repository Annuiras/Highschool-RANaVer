///////////////////////////////////////////
//　モードセレクト画面のプログラムです   //
//								   　　　//
//　作成者：松浦未羽　　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/17		   　　　//
///////////////////////////////////////////

#include "ModeSelect.h"

//コンストラクタ
CModeSelect::CModeSelect() :
	m_TutorialTextureSmall(),
	m_TutorialTextureBig(),
	m_TutorialBG(),
	m_TutorialTextBox(),
	m_TutorialTextTexture(),
	MenuNow_Mode(),
	m_BakAlph(),
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
void  CModeSelect::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//画面下文字スクロール値初期化
	m_Scroll = 500;
	
	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//素材ロード
	Load();

	//エラー状態でない場合
	if (b_LoadSitu == LOAD_COMP) {
		//初期化完了
		b_LoadSitu = LOAD_DONE;
	}

	//現在のシーン
	m_NowScene = SCENENO_SELECTMODE;

	//フェードイン用初期化
	m_BakAlph = 255;

	//フェード状態
	b_Fadein = FADE_IN;


}


//更新
void CModeSelect::Update()
{
	//BGM再生
	b_MusicManager->BGMStart(BGMT_MOOP);

	//リセット
	if (m_Scroll <= -1845) {
		m_Scroll = 1845;
	}
	//画面下文字スクロール
	m_Scroll -= SCROLL_SPEED;

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}


	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {
		switch (MenuNow_Mode)
		{
		case 0:
			//入学説明画面
			m_bEnd = true;
			m_NextScene = SCENENO_TUTORIAL;
			break;

		case 1:
			//入学
			m_bEnd = true;
			m_NextScene = SCENENO_DPDECISION;
			break;

		case 2:
			//図書室
			m_bEnd = true;
			m_NextScene = SCENENO_GALLERY;
			break;

		case 3:
			//放送室
			m_bEnd = true;
			m_NextScene = SCENENO_OPTION;
			break;
		}
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}


	//メニューの更新
	if (b_MenuMamt->IsShow())
	{
		//更新
		b_MenuMamt->Update();

		//項目選択時
		if (b_MenuMamt->IsEnter())
		{
			if (b_MenuMamt->GetSelect() == 0)
			{
				//アプリケーション終了
				PostQuitMessage(0);
			}

			//メニュー非表示
			b_MenuMamt->Hide();
		}

		return;
	}
	//エスケープキーで終了メニューを表示
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		b_MenuMamt->Show(MENUT_END);
	}


	//矢印キー下で選択が下がるようにする
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		b_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode < MenuCnt - 1)
		{
			++MenuNow_Mode;
		}
	}
	//矢印キー上で選択が上がるようにする
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		b_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode > 0)
		{
			--MenuNow_Mode;
		}
	}

	//エンターを押したら各画面へ移動
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_MusicManager->SEStart(SE_T_DECISION);
		b_Fadein = FADE_OUT;
	}
}


void CModeSelect::UpdateDebug(void)
{

}

void CModeSelect::Render(void)
{
	//画像を切り取るための矩形
	//下に出す説明文の画像矩形
	CRectangle recTutorialTex(0, 0, 1845, 41);
	CRectangle recGameTex(0, 45, 1845, 85);
	CRectangle recGalleryTex(0, 90, 1845, 130);
	CRectangle recOptionTex(0, 135, 1845, 175);
	

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

	b_MenuMamt->Render();

	//フェードアウト
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 255, 255, 255));


}

void CModeSelect::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "モードセレクト画面");
	CGraphicsUtilities::RenderString(10, 40, "Enterキーで画面遷移");
	CGraphicsUtilities::RenderString(10, 70, "Scroll%f",m_Scroll);

	CGraphicsUtilities::RenderLine(m_Scroll, 0, m_Scroll, WINDOWSIZE_HEIGHT, MOF_COLOR_BLUE);
}

//解放
void CModeSelect::Release(void)
{
	//素材開放
	m_TutorialTextureSmall.Release();
	m_TutorialTextureBig.Release();
	for (int i = 0; i < 4; i++) 
	{
		m_TutorialBG[i].Release();
	}
	m_TutorialTextTexture.Release();
	m_TutorialTextBox.Release();

	//BGMストップ
	b_MusicManager->BGMStop(BGMT_MOOP);

}


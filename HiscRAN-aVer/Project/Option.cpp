#include "Option.h"

//変更するシーン（外部参照、実態はGameApp.cpp）
extern int			gChangeScene;

#define MenuCnt (4)

int OptionCnt = 0;

COption::COption() :
	m_Font1(),
	m_BG(),
	m_mount(),
	m_Button1_1(),
	m_Button1_2(),
	m_Button2(),
	m_Button3_Win(),
	m_Button3_Full(),
	m_Select_BGM(),
	m_Select_SE(),
	m_Select_Screen(),
	m_Select_s(),
	m_ExTexture(),
	m_BackButton(),
	VolumeBGM(0.0),
	VolumeSE(0.0),
	y_1(0.0),
	y_2(0.0),
	flagBGM(false),
	flagSE(false),
	flagSC(false),
	ScreenSize(false)
{

}

COption::~COption()
{

}

//素材読み込み
void COption::Load(void)
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Option");

	//背景
	if (!m_BG.Load("Option_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//土台
	if (!m_mount.Load("Option_mount.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//BGM調整ボタン
	if (!m_Button1_1.Load("Option_slide.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//SE調整ボタン
	if (!m_Button1_2.Load("Option_slide.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//SE再生ボタン
	if (!m_Button2.Load("Option_Button_SE.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//Screenサイズ調整ボタン
	if (!m_Button3_Win.Load("Option_Button_Win.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_Button3_Full.Load("Option_Button_Full.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//選択枠
	if (!m_Select_BGM.Load("Option_Sbgm.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_Select_SE.Load("Option_Sse.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_Select_Screen.Load("Option_Sscreen.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//説明
	if (!m_ExTexture.Load("Option_Ex.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//小さい選択枠
	if (!m_Select_s.Load("Select_s.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//戻るボタン
	if (!m_BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//ロード完了
	b_LoadSitu = LOAD_COMP;
}


//初期化
void COption::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{

	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//素材ロード
	Load();
	//初期化完了
	b_LoadSitu = LOAD_DONE;

	//フォント
	m_Font1.Create(35, "UD デジタル 教科書体 N-B");

	//ボリューム取得
	VolumeBGM = g_MusicManager->GetBGMVolume();
	VolumeSE = g_MusicManager->GetSEVolume();

	//BGMに選択枠を合わせておく
	OptionCnt = 0;

	//BGM再生
	g_MusicManager->BGMLoop(BGMT_MOOP, true);
	g_MusicManager->BGMStart(BGMT_MOOP);

	//:オプションのシークバーの位置が音量によって変わらない
	double BGM = VolumeBGM - 0.01;
	double SE = VolumeSE - 0.01;

	y_1 = 200.0 / BGM;
	y_2 = 200.0 / SE;

	//ボタン座標初期化
	if (y_1 < 242)
	{
		y_1 = 242;
	}
	else if (y_1 > 542)
	{
		y_1 = 542;
	}

	if (y_2 < 242)
	{
		y_2 = 242;
	}
	else if (y_2 > 542)
	{
		y_2 = 542;
	}

	if (VolumeBGM == 0.0)
	{
		y_1 = 542;
	}

	if (VolumeSE == 0.0)
	{
		y_2 = 542;
	}

	m_NowScene = SCENENO_OPTION;

	//状態を設定
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

}

//更新
void COption::Update(void)
{
	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph);
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph);
		return;
	}

	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//説明表示
	if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		if (flag == true)
		{
			flag = false;
		}
		else
		{
			flag = true;
		}
	}

	//戻るボタンでモードセレクト画面へ
	//Enterで戻るかは検討中
	if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	//矢印キー右で選択が右に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//メニューカウントがオプションカウントより大きく、BGM・SE・スクリーンサイズ変更が選択になっていない場合
		if (OptionCnt < MenuCnt - 1 && flagBGM == false && flagSE == false && flagSC == false)
		{
			//右に行くことができる
			OptionCnt++;
		}
		else if (OptionCnt == 3)
		{
			OptionCnt = 0;
		}

	}
	//矢印キー左で左に行くようにする
	else if (g_pInput->IsKeyPush(MOFKEY_LEFT) && flagBGM == false && flagSE == false && flagSC == false)
	{
		if (OptionCnt > 0)
		{
			OptionCnt--;
		}
		else if (OptionCnt == 0)
		{
			OptionCnt = 3;
		}
	}

	//戻るボタンにカーソルがあって、上ボタンを押したらBGMに選択枠が行く
	if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_UP))
	{
		OptionCnt = 0;
	}
	//下ボタンを押したら戻るボタンに行く
	else if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		OptionCnt = 3;
	}


	//BGM音量を上げる
	if (OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		g_MusicManager->BGMSetVolume(g_MusicManager->GetBGMVolume() + 0.01f);
		VolumeBGM = g_MusicManager->GetBGMVolume();
	}
	//音量を下げる
	else if (OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		g_MusicManager->BGMSetVolume(g_MusicManager->GetBGMVolume() - 0.01f);
		VolumeBGM = g_MusicManager->GetBGMVolume();
	}

	//BGM調節ボタンの上げ下げ
	if (g_MusicManager->GetBGMVolume() < 1 && OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_UP) && y_1 >= 242)
	{
		y_1 -= 3.0;
	}
	else if (g_MusicManager->GetBGMVolume() > 0 && OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_DOWN) && y_1 <= 542)
	{
		y_1 += 3.0;
	}


	//SEの音量を上げる
	if (g_MusicManager->GetSEVolume() < 1 && OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		g_MusicManager->SESetVolume(g_MusicManager->GetSEVolume() + 0.01f);
		VolumeSE = g_MusicManager->GetSEVolume();
	}
	//SEの音量を下げる
	else if (g_MusicManager->GetSEVolume() > 0 && OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		g_MusicManager->SESetVolume(g_MusicManager->GetSEVolume() - 0.01f);
		VolumeSE = g_MusicManager->GetSEVolume();
	}

	//SE調整ボタンの上げ下げ
	if (g_MusicManager->GetSEVolume() < 1 && OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_UP) && y_2 >= 242)
	{
		y_2 -= 3.0;
	}
	else if (g_MusicManager->GetSEVolume() > 0 && OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_DOWN) && y_2 <= 542)
	{
		y_2 += 3.0;
	}

	//SE再生
	if (OptionCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		g_MusicManager->SEStart(SE_T_OPTION_CHIME);
	}


	//フルスクリーン
	if (OptionCnt == 2 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		g_pGraphics->ChangeScreenMode();
		if (ScreenSize)
		{
			//ウィンドウ判定にする
			ScreenSize = false;
		}
		else
		{
			//フルスクリーン判定にする
			ScreenSize = true;
		}
	}
}

//描画
void COption::Render(void)
{

	m_BG.Render(0, 0);

	//土台描画
	m_mount.Render(241, 116);

	//音量ボタン描画
	m_Button1_1.Render(365, y_1);
	m_Button1_2.Render(520, y_2);

	//SE再生ボタン描画
	m_Button2.Render(622, 414);

	if (OptionCnt != 1)
	{
		m_Button2.Render(622, 414, MOF_ARGB(155, 20, 20, 20));
	}

	//戻るボタン
	m_BackButton.Render(60, 650);

	//もしScreenサイズがフルスクリーンなら
	if (ScreenSize)
	{
		//フルスクリーンボタンを表示
		m_Button3_Full.Render(803, 377);
	}
	//そうじゃなければ
	else if (!ScreenSize)
	{
		//そのまま
		m_Button3_Win.Render(803, 377);
	}

	//メニュー内容
	const char* MenuString[MenuCnt] =
	{
		"BGM音量",
		"SE音量",
		"Screenサイズ"
	};

	////説明文は後日メニューと似た感じで実装します。
	//m_Font1.RenderString(267, 8, MOF_COLOR_BLACK, "スペースキーで調整したい項目を選択、選択の解除ができます。\n上下矢印ででスライダーが動かせます。\nボタンはエンターキーで動かせます。\n戻るでモードセレクト画面に戻ることができますよ。");
	//m_Font1.RenderString(260, 135, MOF_COLOR_BLACK, MenuString[0]);
	//m_Font1.RenderString(600, 135, MOF_COLOR_BLACK, MenuString[1]);
	//m_Font1.RenderString(880, 135, MOF_COLOR_BLACK, MenuString[2]);
	//m_Font1.RenderString(940, 325, MOF_COLOR_BLACK, "Full");
	//m_Font1.RenderString(950, 453, MOF_COLOR_BLACK, "Win");
	//m_Font1.RenderString(786, 620, MOF_COLOR_BLACK, "機械は大切に扱いましょう。\n放送委員会");

	CRectangle redBGM(0, 0, 51, 20);
	CRectangle yellowBGM(0, 20, 51, 40);
	CRectangle redScreen(0, 0, 74, 19);
	CRectangle yellowScreen(0, 19, 74, 38);
	CRectangle redSE(0, 0, 28, 20);
	CRectangle yellowSE(0, 20, 28, 40);

	//処理を変数によって変える
	switch (OptionCnt)
	{
		//BGM
	case 0:
		m_Select_BGM.Render(375, 181, yellowBGM);
		/*if (flagBGM == true)
		{
			m_Select_BGM.RenderLoad(375, 181,redBGM);
		}*/
		break;

		//SE
	case 1:
		m_Select_SE.Render(543, 183, yellowSE);
		/*if (OptionCnt==1)
		{
			m_Select_SE.RenderLoad(543, 183, redSE);
		}*/

		if (OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_RETURN))
		{
			m_Button2.Render(622, 414, MOF_ARGB(155, 20, 20, 20));
		}
		break;

		//Screenサイズ
	case 2:
		m_Select_Screen.Render(815, 340, yellowScreen);
		/*if (flagSC == true)
		{
			m_Select_Screen.RenderLoad(815, 340,redScreen);
		}*/
		break;

		//戻るボタン
	case 3:
		m_Select_s.Render(60, 650);
		break;

	}

	if (flag != false)
	{
		m_ExTexture.Render(0, 0);
	}

	//フェード用黒背景
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));

}

//デバッグ
void COption::RenderDebug(void)
{
	if (flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, MOF_COLOR_BLACK, "BGM弄ってる");
	}
	else if (!flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, MOF_COLOR_BLACK, "BGM弄ってない");
	}

	if (flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, MOF_COLOR_BLACK, "SE弄ってる");
	}
	else if (!flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, MOF_COLOR_BLACK, "SE弄ってない");
	}

	if (flagSE && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CGraphicsUtilities::RenderString(10, 390, MOF_COLOR_BLACK, "SE鳴らした");
	}
	else
	{
		CGraphicsUtilities::RenderString(10, 390, MOF_COLOR_BLACK, "SE鳴らしてない");
	}

	if (flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, MOF_COLOR_BLACK, "スクリーン弄ってる");
	}
	else if (!flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, MOF_COLOR_BLACK, "スクリーン弄ってない");
	}

	if (ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, MOF_COLOR_BLACK, "フルスクリーン");
	}
	else if (!ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, MOF_COLOR_BLACK, "ウィンドウサイズ");
	}

	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "オプション画面");
	CGraphicsUtilities::RenderString(10, 40, MOF_COLOR_BLACK, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "0キーでモードセレクト画面へ遷移");
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "BGM音量：%.2f", VolumeBGM);
	CGraphicsUtilities::RenderString(10, 130, MOF_COLOR_BLACK, "SE音量：%.2f", VolumeSE);
	CGraphicsUtilities::RenderString(100, 100, MOF_COLOR_BLACK, "SE音量：%f", y_1);

	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "BGM音量");
	CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_BLACK, "SE音量");
	CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_BLACK, "スクリーンサイズ");

	switch (OptionCnt)
	{
	case 0:
		CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_GREEN, "BGM音量");
		if (flagBGM == true)
		{
			CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_RED, "BGM音量");
		}
		break;

	case 1:
		CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_GREEN, "SE音量");
		if (flagSE == true)
		{
			CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_RED, "SE音量");
		}
		break;

	case 2:
		CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_GREEN, "スクリーンサイズ");
		if (flagSC == true)
		{
			CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_RED, "スクリーンサイズ");
		}
		break;
	}
}


//素材解放
void COption::Release(void)
{
	g_MusicManager->BGMSetVolume(VolumeBGM);
	g_MusicManager->SESetVolume(VolumeSE);

	m_Button1_1.Release();
	m_Button1_2.Release();
	m_Button2.Release();
	m_Button3_Full.Release();
	m_Button3_Win.Release();
	m_mount.Release();
	m_Select_BGM.Release();
	m_Select_SE.Release();
	m_Select_Screen.Release();
	m_Select_s.Release();
	m_BackButton.Release();
	m_Font1.Release();
	m_BG.Release();
	m_ExTexture.Release();
	g_MusicManager->SEALLStop();
	g_MusicManager->BGMStop(BGMT_MOOP);

}
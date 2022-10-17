#include "Option.h"
#include "Define.h"

//変更するシーン（外部参照、実態はGameApp.cpp）
extern int			gChangeScene;

#define MenuCnt (3)

int OptionCnt = 0;
double VolumeBGM = 0;
double VolumeSE = 0;

double y_1 = 224;
double y_2 = 224;

bool flagBGM = false;
bool flagSE = false;
bool flagSC = false;

bool ScreenSize = false;

Option::Option() :
	m_BGM(),
	m_SE(),
	m_mount(),
	m_Stick1(),
	m_Stick2(),
	m_Button1_1(),
	m_Button1_2(),
	m_Button2(),
	m_Button3(),
	m_Select()
{

}

Option::~Option()
{

}

//素材読み込み
bool Option::Load(void)
{
	if (!m_BGM.Load("makiba no kaze.mp3"))
	{
		return false;
	}

	if (!m_SE.Load("Chime-Announce07-1.mp3"))
	{
		return false;
	}

	if (!m_mount.Load("Option_mount.png"))
	{
		return false;
	}

	if (!m_Stick1.Load("Option_stick.png"))
	{
		return false;
	}

	if (!m_Stick2.Load("Option_stick.png"))
	{
		return false;
	}

	if (!m_Button1_1.Load("Option_Button1.png"))
	{
		return false;
	}

	if (!m_Button1_2.Load("Option_Button1.png"))
	{
		return false;
	}

	if (!m_Button2.Load("Option_Button2.png"))
	{
		return false;
	}

	if (!m_Button3.Load("Option_Button3.png"))
	{
		return false;
	}

	if (m_Select.Load("Option_Select.png"))
	{
		return false;
	}

	return true;
}


//初期化
void Option::Initialize(void)
{
	m_BGM.SetLoop(TRUE);
	m_BGM.Play();
	VolumeBGM = m_BGM.GetVolume();
	VolumeSE = m_SE.GetVolume();
}

//更新
void Option::Update(void)
{
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
		m_BGM.Stop();
	}
	//エンターキーでモードセレクト画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		gChangeScene = SCENENO_SELECTMODE;
		m_BGM.Stop();

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
	}
	//矢印キー左で左に行くようにする
	else if (g_pInput->IsKeyPush(MOFKEY_LEFT) && flagBGM == false && flagSE == false && flagSC == false)
	{
		if (OptionCnt > 0)
		{
			OptionCnt--;
		}
	}


	//BGM音量設定にカーソルが当たった状態で、スペースキーを押した場合
	if (OptionCnt == 0 && g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		if (flagBGM)
		{
			//選択済みになっている場合は選択解除する
			flagBGM = false;
		}
		else
		{
			//選択解除になっている場合は選択済みにする
			flagBGM = true;
		}
	}

	//SE音量設定にカーソルが当たった状態で、スペースキーを押した場合
	if (OptionCnt == 1 && g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		if (flagSE)
		{
			//選択済みになっている場合は選択解除する
			flagSE = false;
		}
		else
		{
			//選択解除になっている場合は選択済みにする
			flagSE = true;
		}
	}

	if (OptionCnt == 1 && flagSE == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SE.Play();
	}

	//BGM音量設定にカーソルが当たった状態で、スペースキーを押した場合
	if (OptionCnt == 2 && g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		if (flagSC)
		{
			//選択済みになっている場合は選択解除する
			flagSC = false;
		}
		else
		{
			//選択解除になっている場合は選択済みにする
			flagSC = true;
		}
	}


	//音量を上げる
	if (flagBGM == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		m_BGM.SetVolume(m_BGM.GetVolume() + 0.01f);
		VolumeBGM = m_BGM.GetVolume();
	}
	//音量を下げる
	else if (flagBGM == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		m_BGM.SetVolume(m_BGM.GetVolume() - 0.01f);
		VolumeBGM = m_BGM.GetVolume();
	}

	if (m_BGM.GetVolume() < 1 && flagBGM == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		y_1 -= 2.5;
	}
	else if (m_BGM.GetVolume() > 0 && flagBGM == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		y_1 += 2.5;
	}



	//音量を上げる
	if (flagSE == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		m_SE.SetVolume(m_SE.GetVolume() + 0.01f);
		VolumeSE = m_SE.GetVolume();
	}
	//音量を下げる
	else if (flagSE == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		m_SE.SetVolume(m_SE.GetVolume() - 0.01f);
		VolumeSE = m_SE.GetVolume();
	}

	if (m_SE.GetVolume() < 1 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		y_2 -= 2.5;
	}
	else if (m_SE.GetVolume() > 0 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		y_2 += 2.5;
	}

	//フルスクリーン
	if (flagSC == true && g_pInput->IsKeyPush(MOFKEY_1))
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
void Option::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "オプション画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "0キーでモードセレクト画面へ遷移");
	CGraphicsUtilities::RenderString(10, 100, "BGM音量：%.2f", VolumeBGM);
	CGraphicsUtilities::RenderString(10, 130, "SE音量：%.2f", VolumeSE);
	CGraphicsUtilities::RenderString(100, 100, "SE音量：%f", y_1);


	m_mount.Render(145, 126);
	m_Stick1.Render(187, 206);
	m_Button1_1.Render(178, y_1);
	m_Stick2.Render(512, 206);
	m_Button1_2.Render(503, y_2);
	m_Button2.Render(639, 429);
	m_Button3.Render(912, 287);


	const char* MenuString[MenuCnt] =
	{
		"BGM音量",
		"SE音量",
		"Screenサイズ"
	};

	CGraphicsUtilities::RenderString(10, 160, MenuString[0]);
	CGraphicsUtilities::RenderString(100, 160, MenuString[1]);
	CGraphicsUtilities::RenderString(500, 160, MenuString[2]);

	if (flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, "BGM弄ってる");
	}
	else if (!flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, "BGM弄ってない");
	}

	if (flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, "SE弄ってる");
	}
	else if (!flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, "SE弄ってない");
	}

	if (flagSE && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CGraphicsUtilities::RenderString(10, 390, "SE鳴らした");
	}
	else
	{
		CGraphicsUtilities::RenderString(10, 390, "SE鳴らしてない");
	}

	if (flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, "スクリーン弄ってる");
	}
	else if (!flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, "スクリーン弄ってない");
	}

	if (ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, "フルスクリーン");
	}
	else if (!ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, "ウィンドウサイズ");
	}



	switch (OptionCnt)
	{
	case 0:
		m_Select.Render(145, 126);
		CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_GREEN, MenuString[0]);
		if (flagBGM == true)
		{
			m_Select.Render(145, 126, MOF_COLOR_RED);
			CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_RED, MenuString[0]);
		}
		break;

	case 1:
		m_Select.Render(475, 126);
		CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_GREEN, MenuString[1]);
		if (flagSE == true)
		{
			m_Select.Render(475, 126, MOF_COLOR_RED);
			CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_RED, MenuString[1]);
		}
		break;

	case 2:
		m_Select.Render(805, 126);
		CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_GREEN, MenuString[2]);
		if (flagSC == true)
		{
			m_Select.Render(805, 126, MOF_COLOR_RED);
			CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_RED, MenuString[2]);
		}
		break;

	}
}


//素材解放
void Option::Release(void)
{
	m_BGM.Release();
	m_SE.Release();
	m_Stick1.Release();
	m_Stick2.Release();
	m_Button1_1.Release();
	m_Button1_2.Release();
	m_Button2.Release();
	m_Button3.Release();
	m_mount.Release();
	m_Select.Release();
}
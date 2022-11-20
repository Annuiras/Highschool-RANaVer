#include "ModeSelect.h"
#include "Define.h"


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

//初期化
void  CModeSelect::Initialize(CGameProgMgmt* mamt)
{
	m_Scroll = 0;
	m_GameProgMamt = mamt;
	//メニューの生成
	gMenu.Create(gMenuItemCount);

	Load();
}

//ロード
bool CModeSelect::Load()
{
	if (!m_TutorialTextTexture.Load("ModeSelectTexture.png"))
	{
		return false;
	}

	if (!m_Illustrat.Load("ModeSelectIllust.png"))
	{
		return false;
	}

	return true;
}

//更新
void CModeSelect::Update()
{
	m_Scroll -= SCROLL_SPEED;

	//矢印キー下で選択が下がるようにする
	if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		if (MenuNow_Mode < MenuCnt - 1)
		{
			++MenuNow_Mode;
		}
	}
	//矢印キー上で選択が上がるようにする
	if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_UP))
	{
		if (MenuNow_Mode > 0)
		{
			--MenuNow_Mode;
		}
	}

	//エンターを押したら各画面へ移動
	if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{

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

	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}
	//F2キーでチュートリアル画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TUTORIAL;
	}
	//F3キーでゲーム画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAME;
	}
	//F4キーでギャラリー画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F4))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GALLERY;
	}
	//F5キーでオプション画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F5))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_OPTION;
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
	CRectangle recTextile(0, 180, 1280, 234);

	//メニュー表示用画像の矩形
	CRectangle recGameSel(0, 234, 498, 329);
	CRectangle recGallerySel(0, 328, 498, 424);
	CRectangle recOptionSel(0, 423, 498, 519);
	CRectangle recTutorialSel(0, 519, 498, 614);

	//イラスト表示用矩形
	CRectangle recAdmissionExIll(533, 613, 1066, 1226);
	CRectangle recAdmissionIll(0, 0, 533, 613);
	CRectangle recLibraryIll(533, 0, 1066, 613);
	CRectangle reccastingIll(0, 613, 533, 1226);

	//チュートリアル画像
	m_TutorialTextTexture.Render(782, 44, recTutorialSel);

	//ゲーム本編画像
	m_TutorialTextTexture.Render(782, 201, recGameSel);

	//ギャラリー画像
	m_TutorialTextTexture.Render(782, 359, recGallerySel);

	//オプション画像
	m_TutorialTextTexture.Render(782, 518, recOptionSel);

	//下に出すテキストの下地
	m_TutorialTextTexture.Render(0, 654, recTextile);


	int W = m_TutorialTextTexture.GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	switch (MenuNow_Mode)
	{
	case 0:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recTutorialTex);
		}

		m_TutorialTextTexture.RenderScale(560, 23, 1.5f, recTutorialSel);
		m_Illustrat.Render(11, 22, recAdmissionExIll);

		break;

	case 1:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recGameTex);
		}

		m_TutorialTextTexture.RenderScale(560, 180, 1.5f, recGameSel);
		m_Illustrat.Render(11, 22, recAdmissionIll);

		break;

	case 2:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recGalleryTex);
		}

		m_TutorialTextTexture.RenderScale(560, 338, 1.5f, recGallerySel);
		m_Illustrat.Render(11, 22, recLibraryIll);

		break;

	case 3:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recOptionTex);
		}

		m_TutorialTextTexture.RenderScale(560, 496, 1.5f, recOptionSel);
		m_Illustrat.Render(11, 22, reccastingIll);
		break;
	}

	//メニューの描画
	gMenu.Render(1);


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
	m_TutorialTextTexture.Release();
	m_Illustrat.Release();
	gMenu.Release();
}
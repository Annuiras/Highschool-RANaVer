///////////////////////////////////////////
//　タイトル画面のプログラムです   　　　//
//								   　　　//
//　作成者：松浦未羽  　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/17		   　　　//
///////////////////////////////////////////

#include "Title.h"

//コンストラクタ
CTitle::CTitle() :
	m_BackTexture(),
	m_TitleTexture(),
	m_TiTleUITexture(),
	m_Scroll(0.0f),
	Rondom(0.0f),
	gAlpha(),
	isStop(),
	m_BakAlph(),
	m_Bak_Type()
{
}

//デストラクタ
CTitle::~CTitle()
{

}

//素材ロード
void CTitle::Load(void)
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game/StageBak");

	//背景テクスチャの読み込み
	char* name[BACK_TYPE] =
	{
		"Stairs.png",
		"Wall_L.png",
		"Window_2.png",
		"Door_R.png",
		"Door_L.png"
	};

	for (int i = 0; i < BACK_TYPE; i++)
	{
		if (!m_BackTexture[i].Load(name[i]))
		{
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}


	CUtilities::SetCurrentDirectoryA("../../");

	CUtilities::SetCurrentDirectoryA("Title");

	//タイトルロゴ読み込み
	if (!m_TitleTexture.Load("GameLogo_s.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//タイトルUI読み込み
	if (!m_TiTleUITexture.Load("TitleUI.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	b_LoadSitu = LOAD_COMP;
}

//初期化
void CTitle::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;


	//初期化
	m_Scroll =200 /*m_BackTexture->GetWidth()*/;

	//状態を設定
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	isStop = false;
	gAlpha = 0;

	//ランダム数値を取得
	for (int i = 0; i < 3; i++)
	{
		m_Bak_Type[i] = RandmuBak.GetRandomNumbe(0, BACK_TYPE - 1);
	}

	//現在のシーン
	m_NowScene = SCENENO_TITLE;	
}

//更新
void CTitle::Update(void)
{

	//左にスクロールしていく
	m_Scroll -= SCROLL_SPEED;		
	//m_Scroll -=  + 10;

	
	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//BGM再生
	b_MusicManager->BGMStart(BGMT_TITLE);

	//α値変更処理
	//ちかちかさせてる
	if (!isStop)
	{
		gAlpha += 3;

		if (gAlpha >= 255)
		{
			isStop = true;
		}
	}
	else
	{
		gAlpha -= 3;
		if (gAlpha <= 0)
		{
			isStop = false;
		}
	}

	//エンターキーでセレクト画面へ
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		//モードセレクトへ移動
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

}

void CTitle::UpdateDebug(void)
{
}

//描画
void CTitle::Render(void)
{
	//テクスチャの描画
	int W = m_BackTexture->GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	if (m_Scroll <= 0) {

		//0以下で初期化
		m_Scroll = m_BackTexture->GetWidth();

		//次の背景を用意
		m_Bak_Type[0] = m_Bak_Type[1];
		m_Bak_Type[2] = RandmuBak.GetRandomNumbe(0, BACK_TYPE - 1);
		m_Bak_Type[1] = m_Bak_Type[2];

	}

	//背景スクロール処理
	for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
	{
		if (x > 0)
		{
			m_BackTexture[m_Bak_Type[1]].Render(x, 0.0f);

		}
		else
		{
			m_BackTexture[m_Bak_Type[0]].Render(x, 0.0f);
		}
	}
	

	//真ん中にLogo描画
	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	//真ん中にUI描画
	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500, MOF_ARGB(gAlpha, 255, 255, 255));


	//フェード用黒背景
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));
}

void CTitle::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "タイトル画面");
	CGraphicsUtilities::RenderString(10, 40, "Scroll%f",m_Scroll);
	CGraphicsUtilities::RenderLine(m_Scroll, 0, m_Scroll, WINDOWSIZE_HEIGHT,MOF_COLOR_BLUE);

}

void CTitle::Release(void)
{
	//素材解放
	for (int i = 0; i < BACK_TYPE; i++)
	{
		m_BackTexture[i].Release();
	}	
	
	m_TitleTexture.Release();
	m_TiTleUITexture.Release();
	gFont.Release();
	gFont2.Release();

	//BGM停止
	b_MusicManager->BGMStop(BGMT_TITLE);
}
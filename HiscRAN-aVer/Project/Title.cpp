#include "Title.h"


//コンストラクタ
CTitle::CTitle() :
	m_BackTexture1(),
	m_BackTexture2(),
	m_BackTexture3(),
	m_TitleTexture(),
	m_TiTleUITexture(),
	m_Scroll(0.0f),
	Rondom(0.0f)
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
	CUtilities::SetCurrentDirectoryA("Title");

	//背景テクスチャの読み込み
	if (!m_BackTexture1.Load("TitleBG1.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_BackTexture2.Load("TitleBG2.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_BackTexture3.Load("TitleBG3.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

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
void CTitle::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	//各マネージャーセット
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;


	//初期化
	m_Scroll = 0;

	//状態を設定
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//ランダム数値を取得
	Rondom = CUtilities::Random(0, 3);

	//現在のシーン
	m_NowScene = SCENENO_TITLE;	
}

//更新
void CTitle::Update(void)
{


	//左にスクロールしていく
	m_Scroll -= SCROLL_SPEED;

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, FADE_OUT_SPEED);
		return;
	}

	//BGM再生
	g_MusicManager->BGMStart(BGMT_TITLE);

	//エンターキーでセレクト画面へ
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, FADE_OUT_SPEED);
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		//モードセレクトへ移動
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

}

//描画
void CTitle::Render(void)
{
	//ランダムの値ごとにテクスチャを変える
	if (Rondom == 0)
	{
		//テクスチャの描画
		int W = m_BackTexture1.GetWidth();
		int scw = g_pGraphics->GetTargetWidth();

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_BackTexture1.Render(x, 0.0f);
		}
	}
	else if (Rondom == 1)
	{
		//テクスチャの描画
		int W = m_BackTexture2.GetWidth();
		int scw = g_pGraphics->GetTargetWidth();

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_BackTexture2.Render(x, 0.0f);
		}
	}
	else if (Rondom == 2)
	{
		//テクスチャの描画
		int W = m_BackTexture3.GetWidth();
		int scw = g_pGraphics->GetTargetWidth();

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_BackTexture3.Render(x, 0.0f);
		}
	}


	//真ん中にLogo描画
	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	//真ん中にUI描画
	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500);

	//フェード用黒背景
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));
}

void CTitle::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "タイトル画面");
	CGraphicsUtilities::RenderString(10, 40, "Enterキーで画面遷移");
}

void CTitle::Release(void)
{
	m_BackTexture1.Release();
	m_BackTexture2.Release();
	m_BackTexture3.Release();
	m_TitleTexture.Release();
	m_TiTleUITexture.Release();
	gFont.Release();
	gFont2.Release();

	g_MusicManager->BGMStop(BGMT_TITLE);
}
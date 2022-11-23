#include "Define.h"
#include "Title.h"

//変更するシーン（外部参照。実態はGameApp.cpp）
extern int gChangeScene;

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
bool CTitle::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Title");

	//背景テクスチャの読み込み
	if (!m_BackTexture1.Load("TitleBG1.png"))
	{
		return false;
	}

	if (!m_BackTexture2.Load("TitleBG2.png"))
	{
		return false;
	}

	if (!m_BackTexture3.Load("TitleBG3.png"))
	{
		return false;
	}

	if (!m_TitleTexture.Load("GameLogo_s.png"))
	{
		return false;
	}

	if (!m_TiTleUITexture.Load("TitleUI.png"))
	{
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;

}

//初期化
void CTitle::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_Scroll = 0;
	Rondom = CUtilities::Random(0, 3);
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;
	Load();
}

//更新
void CTitle::Update(void)
{
	m_Scroll -= SCROLL_SPEED;

	//エンターキーでセレクト画面へ
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}
}

//描画
void CTitle::Render(void)
{
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



	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500);

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
}
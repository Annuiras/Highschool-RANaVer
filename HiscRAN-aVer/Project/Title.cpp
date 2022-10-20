#include "GameApp.h"
#include "Title.h"

//変更するシーン（外部参照。実態はGameApp.cpp）
extern int gChangeScene;

//コンストラクタ
Title::Title() :
	m_BackTexture(),
	m_TitleTexture(),
	m_TiTleUITexture(),
	m_Scroll(0.0f)
{

}

//デストラクタ
Title::~Title()
{

}

//素材ロード
bool Title::Load(void)
{
	//背景テクスチャの読み込み
	if (!m_BackTexture.Load("rouka.png"))
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

	return true;

}

//初期化
void Title::Initialize(void)
{
	m_Scroll = 0;

}

//更新
void Title::Update(void)
{
	m_Scroll -= SCROLL_SPEED;

	//エンターキーでセレクト画面へ
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}

	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_GAME;
	}
}

//描画
void Title::Render(void)
{
	//テクスチャの描画
	int W = m_BackTexture.GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
	{
		m_BackTexture.Render(x, 0.0f);
	}

	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500);


	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "タイトル画面");
	CGraphicsUtilities::RenderString(10, 40,MOF_COLOR_BLACK, "Enterキーで画面遷移");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "F1キーでゲーム画面遷移");
}

void Title::Release(void)
{
	m_BackTexture.Release();
	m_TitleTexture.Release();
	m_TiTleUITexture.Release();
	gFont.Release();
	gFont2.Release();
}
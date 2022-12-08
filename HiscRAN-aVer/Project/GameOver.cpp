#include "Define.h"
#include "GameOver.h"


#define MenuCnt (2)

int GameOverCount = 0;

//コンストラクタ
CGameOver::CGameOver() :
	m_BackTexture1(),
	m_BackTexture2(),
	m_BackTexture3(),
	m_UITexture(),
	m_SelectTexture(),
	Rondom(0.0f)
{

}

//デストラクタ
CGameOver::~CGameOver()
{

}

//素材ロード
bool CGameOver::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("GameOver");

	if (!m_BackTexture1.Load("GameOverBG1.png"))
	{
		return false;
	}
	if (!m_BackTexture2.Load("GameOverBG2.png"))
	{
		return false;
	}
	if (!m_BackTexture3.Load("GameOverBG3.png"))
	{
		return false;
	}
	if (!m_UITexture.Load("GameOverUI.png"))
	{
		return false;
	}
	if (!m_SelectTexture.Load("GameOverSelect.png"))
	{
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//初期化
void CGameOver::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//黒画面表示
	m_Alpha = 255;

	//推移状態
	m_FadeOutflg = false;

	Rondom = CUtilities::Random(0, 3);
	Load();


}

//更新
void CGameOver::Update(void)
{

	//画面開始時フェードイン
	if (!m_FadeOutflg) {
		//値調整
		m_Alpha -= FADE_OUT_SPEED+2;
		if (m_Alpha <= 0) {
			m_Alpha = 0;
			m_FadeOutflg = true;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		if (GameOverCount < MenuCnt - 1)
		{
			GameOverCount++;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		if (GameOverCount > 0)
		{
			GameOverCount--;
		}
	}


	//やめるのボタン上でエンターキーでモードセレクト画面へ
	if (GameOverCount == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//はじめからのボタン上でエンターキーでゲーム画面へ
	if (GameOverCount == 0 && g_pInput->IsKeyHold(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAME;
	}

	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}
}

//描画
void CGameOver::Render(void)
{
	CRectangle Button1(0, 0, 479, 111);
	CRectangle Button2(0, 111, 479, 224);
	CRectangle Extex1(0, 224, 809, 293);
	CRectangle Extex2(0, 293, 809, 362);

	if (Rondom == 0)
	{
		m_BackTexture1.Render(0, 0);
	}
	else if (Rondom == 1)
	{
		m_BackTexture2.Render(0, 0);
	}
	else if (Rondom == 2)
	{
		m_BackTexture3.Render(0, 0);
	}

	m_UITexture.Render(140, 407, Button1);
	m_UITexture.Render(668, 407, Button2);

	if (GameOverCount == 0)
	{
		m_UITexture.Render(236, 629, Extex1);
		m_SelectTexture.Render(140, 407);
	}
	else if (GameOverCount == 1)
	{
		m_UITexture.Render(236, 629, Extex2);
		m_SelectTexture.Render(668, 407);
	}

	//画面遷移用の黒画面
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_Alpha, 0, 0, 0));

}

void CGameOver::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "ゲームオーバー画面");
	CGraphicsUtilities::RenderString(10, 40, MOF_COLOR_BLACK, "エンターでモードセレクト");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "F1でタイトル");
}

void CGameOver::Release(void)
{
	m_BackTexture1.Release();
	m_BackTexture2.Release();
	m_BackTexture3.Release();
	m_UITexture.Release();
	m_SelectTexture.Release();
}


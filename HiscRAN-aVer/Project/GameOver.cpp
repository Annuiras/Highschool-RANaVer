#include "GameOver.h"


#define MenuCnt (2)

int GameOverCount = 0;

//コンストラクタ
CGameOver::CGameOver() :
	m_BackTexture(),
	m_BackButton(),
	m_StartButton(),
	m_TextBack(),
	m_TextStart(),
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
	CUtilities::SetCurrentDirectoryA("Game/GameOver");

	if (!m_BackTexture.Load("GameOver_BG.png"))
	{
		return false;
	}
	if (!m_BackButton.Load("GameOver_Button_End.png"))
	{
		return false;
	}
	if (!m_StartButton.Load("GameOver_Button_Beginning.png"))
	{
		return false;
	}
	if (!m_TextBack.Load("GameOver_Text_End.png"))
	{
		return false;
	}
	if (!m_TextStart.Load("GameOver_Text_Beginning.png"))
	{
		return false;
	}
	if (!m_ENDText.Load("GameOver_Text_flavor.png"))
	{
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../../");

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

	m_NowScene = SCENENO_GAMEOVER;

	//ゲームオーバー原因をセット
	DPEND = m_GameProgMamt->GetGame_Over_HP();

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
	m_BackTexture.Render(0, 0);

	if (HPEND)
	{
		m_ENDText.Render(PosXHPEND[Rondom], 140, recHPENDTex[Rondom]);
	}
	else 
	{
		m_ENDText.Render(PosXDPEND[Rondom], 140, recDPENDTex[Rondom]);
	}

	if (GameOverCount == 0)
	{
		m_StartButton.Render(133, 260);
		m_TextStart.Render(168, 618);
	}
	else if (GameOverCount == 1)
	{
		m_BackButton.Render(133, 260);
		m_TextBack.Render(168, 618);
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
	m_BackButton.Release();
	m_BackTexture.Release();
	m_StartButton.Release();
	m_TextBack.Release();
	m_TextStart.Release();
	m_ENDText.Release();
}


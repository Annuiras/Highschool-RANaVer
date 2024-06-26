//////////////////////////////////////////////
//	ゲームオーバー画面のプログラムです　　  //
//									　　　　//
//　作成者：松浦未羽　　　　　　　　　　 　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#include "GameOver.h"



//コンストラクタ
CGameOver::CGameOver() :
	m_BackTexture(),
	m_BackButton(),
	m_StartButton(),
	m_TextBack(),
	m_TextStart(),
	m_ENDText(),
	Rondom(0.0f),
	m_BlackBakAlph(),
	m_WhiteBakAlph(),
	GameOverCount()
{
}

//デストラクタ
CGameOver::~CGameOver()
{

}

//素材ロード
void CGameOver::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("GameOver");

	if (!m_BackTexture.Load("GameOver_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_BackButton.Load("GameOver_Button_End.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_StartButton.Load("GameOver_Button_Beginning.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_TextBack.Load("GameOver_Text_End.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_TextStart.Load("GameOver_Text_Beginning.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_ENDText.Load("GameOver_Text_flavor.png"))
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
void CGameOver::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;

	//素材ロード
	Load();
	//エラー状態でない場合
	if (b_LoadSitu != LOAD_ERROR) {
		//初期化完了
		b_LoadSitu = LOAD_DONE;
	}

	//黒画面表示
	m_BlackBakAlph = 255;
	m_WhiteBakAlph = 0;
	b_Fadein = FADE_IN;

	//ランダムで変数を決める
	Rondom = CUtilities::Random(0, 3);

	//現在のシーンセット
	m_NowScene = SCENENO_GAMEOVER;

}

//更新
void CGameOver::Update(void)
{

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BlackBakAlph = FadeIn(m_BlackBakAlph, true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {
		m_bEnd = true;
		return;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {

		switch (m_NextScene)
		{
		case SCENENO_SELECTMODE:
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
			break;
		case SCENENO_GAME:
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
			break;
		default:
			break;
		}
		return;
	}

	//右矢印キーを押した時
	//やめるにカーソルが行く
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		if (GameOverCount < MenuCnt - 1)
		{
			GameOverCount++;
		}
	}
	//左矢印キーを押した時
	//初めからにカーソルが行く
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
		b_Fadein = FADE_OUT;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//はじめからのボタン上でエンターキーでゲーム画面へ
	if (GameOverCount == 0 && g_pInput->IsKeyHold(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
		m_NextScene = SCENENO_GAME;
	}

	
}

void CGameOver::UpdateDebug(void)
{
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
	//背景
	m_BackTexture.Render(0, 0);

	//ゲームオーバーテキスト
	m_ENDText.Render(PosXENDText[Rondom], 140, recENDText[Rondom]);
	
	//ボタン
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

	//フェードアウト暗転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BlackBakAlph, 0, 0, 0));

	//フェードアウト明転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

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


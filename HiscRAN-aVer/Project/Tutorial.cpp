#include "Tutorial.h"

CTutorial::CTutorial() :
	BGTexture(),
	CurtainBGTexture(),
	BackButton(),
	ButtonSelect(),
	gPosX(),
	m_Cursor(0.0f),
	MoveX(0.0f),
	TMenuCnt(0)
{

}

CTutorial::~CTutorial()
{

}

//素材読み込み
void CTutorial::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Tutorial");

	//説明テクスチャ
	char* name[PAGES_NUM] =
	{
		"無題685_20230113163526.png",
		"setumei.png",
		"無題685_20230113163526.png",
		"setumei.png",
		"無題685_20230113163526.png",
		"setumei.png",
		"無題685_20230113163526.png",
	};

	for (int i = 0; i < PAGES_NUM; i++)
	{
		if (!ExTextTexture[i].Load(name[i]))
		{
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	//背景テクスチャ
	if (!BGTexture.Load("Tutorial_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//スクリーンテクスチャ
	if (!ScreenTexture.Load("Tutorial_Screen.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ
	if (!CurtainBGTexture.Load("Tutorial_Mak.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ左
	if (!CurtainBGTextureLeft.Load("Tutorial_MakLef.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ右
	if (!CurtainBGTextureRight.Load("Tutorial_MakRig.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//カーテン部分テクスチャ上
	if (!CurtainBGTextureTop.Load("Tutorial_MakTop.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//戻るボタン
	if (!BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//戻るボタン選択枠
	if (!ButtonSelect.Load("BackButton_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//ロード完了
	b_LoadSitu = LOAD_COMP;

}

//初期化
void CTutorial::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//初期化
	m_Cursor = 0;
	Is_Move = false;
	MoveX = 0;
	TMenuCnt = false;

	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;

	//状態を設定
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//素材ロード
	Load();

	//エラー状態でない場合
	if (b_LoadSitu != LOAD_ERROR) {
		//初期化完了
		b_LoadSitu = LOAD_DONE;
	}


	for (int i = 0; i < PAGES_NUM; i++)
	{
		//初期位置セット
		//300:ページとページの隙間
		gPosX[i] = PAGES_X + ExTextTexture[0].GetWidth()+300;
	}

	//最初のページをセンターに
	gPosX[0] = PAGES_X;

	//現在のシーンセット
	m_NowScene = SCENENO_TUTORIAL;

}

//更新
void CTutorial::Update(void)
{

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}

	//BGM再生
	b_MusicManager->BGMStart(BGMT_TUTORIAL);

	//移動中か？
	if (Is_Move) {

		//スクロール
		//移動方向確認
		if (MoveX > 0) {

			//右移動
			//固定を過ぎたら
			if (gPosX[m_Cursor] <= PAGES_X) {

				//固定
				gPosX[m_Cursor] = PAGES_X;

				//移動終了
				Is_Move = false;

				//初期
				MoveX = 0;

			}
			else
			{
				//移動
				gPosX[m_Cursor] -= MoveX;
				gPosX[m_Cursor - 1] -= MoveX;
			}

		}
		else
		{
			//左移動
			//固定を過ぎたら
			if (gPosX[m_Cursor] >= PAGES_X)
			{
				//固定
				gPosX[m_Cursor] = PAGES_X;

				//移動終了
				Is_Move = false;

				//初期
				MoveX = 0;
			}
			else
			{
				//移動
				gPosX[m_Cursor] -= MoveX;
				gPosX[m_Cursor + 1] -= MoveX;
			}

		}

	}
	else
	{
		//移動中でない
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			//右に移動
			if (m_Cursor != PAGES_NUM - 1) {
				Is_Move = true;
				MoveX = PAGES_SPEED;
				m_Cursor++;
			}
		}
		else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
		{
			//左に移動
			if (m_Cursor != 0) {
				Is_Move = true;
				MoveX = -PAGES_SPEED;
				m_Cursor--;
			}
		}

		//矢印キー下を押した時、戻るボタンにカーソルを合わせる
		else if (!TMenuCnt&& g_pInput->IsKeyPush(MOFKEY_DOWN))
		{
			TMenuCnt = true;
		}
		//矢印キー上を押した時、カーソルを外す
		else if (TMenuCnt && g_pInput->IsKeyPush(MOFKEY_UP))
		{
			TMenuCnt = false;
		}

	}

	//エンターキーでモードセレクト画面へ
	if (TMenuCnt&& g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

}

//描画
void CTutorial::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "チュートリアル画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_COLOR_WHITE);

	//センターに来る画像
	ExTextTexture[m_Cursor].Render(gPosX[m_Cursor], PAGES_Y);

	//移動中の表示
	if (MoveX > 0) {

		//右に抜けていく画像
		ExTextTexture[m_Cursor - 1].Render(gPosX[m_Cursor - 1], PAGES_Y);

	}
	else if (MoveX < 0)
	{
		//左に抜けていく画像
		ExTextTexture[m_Cursor + 1].Render(gPosX[m_Cursor + 1], PAGES_Y);
	}

	//背景画像描画
	BGTexture.Render(0, 0);

	//Screen画像描画
	ScreenTexture.Render(0, 0);

	//幕描画
	CurtainBGTexture.Render(0, 0);

	//幕左
	CurtainBGTextureLeft.Render(-646, 0);

	//幕右
	CurtainBGTextureRight.Render(646, 0);

	//幕上
	CurtainBGTextureTop.Render(0, 0);

	//戻るボタン
	BackButton.Render(60, 650);


	if (TMenuCnt)
	{
		//戻るボタンにハイライト
		ButtonSelect.Render(60, 650);
	}

	//フェード用黒背景
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));

}

void CTutorial::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "チュートリアル画面");
	//CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	//CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");
	//CGraphicsUtilities::RenderString(10, 100, "0→左矢印画像カーソル　　5→右矢印画像カーソル");
	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "ページ数:%d", m_Cursor);

	for (int i = 0; i < PAGES_NUM; i++)
	{
		if (m_Cursor == i) {
			CGraphicsUtilities::RenderString(0, 200 + (30 * i),MOF_COLOR_RED, "X:%d", gPosX[i]);

		}
		else
		{
			CGraphicsUtilities::RenderString(0, 200 + (30 * i), "X:%d", gPosX[i]);

		}
	}

}



//素材解放
void CTutorial::Release(void)
{
	//BGM停止
	b_MusicManager->BGMStop(BGMT_TUTORIAL);

	for (int i = 0; i < PAGES_NUM; i++)
	{
		ExTextTexture[i].Release();
	}
	BGTexture.Release();
	ScreenTexture.Release();
	CurtainBGTexture.Release();
	CurtainBGTextureLeft.Release();
	CurtainBGTextureRight.Release();
	CurtainBGTextureTop.Release();
	BackButton.Release();
	ButtonSelect.Release();
}

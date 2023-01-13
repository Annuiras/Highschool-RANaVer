#include "DPDecision.h"
#include "Define.h"

//コンストラクタ
CDPDecision::CDPDecision() :
	RandmuBak(),
	m_BackTextureA(),
	m_BackTextureC(),
	m_TextTexture(),
	m_SelectTexture(),
	m_WhiteBakAlph(),
	DPDecCnt(),
	flagD(true),
	SP_flg()
{

}

//デストラクタ
CDPDecision::~CDPDecision()
{

}

//素材ロード
void CDPDecision::Load(void)
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("DPDecision");

	//背景黒板
	if (!m_BackTextureA.Load("DPDecision_BGA.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//選択枠
	if (!m_SelectTexture.Load("DPDecision_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//黒塗りキャラ
	if (!m_BackTextureC.Load("DPDecision_BGC.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//説明文字
	if (!m_TextTexture.Load("DPDecision_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//画面説明
	if (!m_ExTexture.Load("DPDecision_ExText.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//ロード状況更新
	b_LoadSitu = LOAD_COMP;

}

//初期化
void CDPDecision::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//素材ロード
	Load();

	//エラー状態でない場合
	if (b_LoadSitu == LOAD_COMP) {
		//初期化完了
		b_LoadSitu = LOAD_DONE;
	}

	//選択肢初期化
	DPDecCnt = 0;

	//説明表示
	flagD = true;

	//フェードイン
	m_WhiteBakAlph = 255;
	b_Fadein = FADE_IN;

	//SPステージかどうかを判定
	SP_flg =false;
	if (RandmuBak.GetRandomNumbe(0, 5) == 50) {
		//五分の一の確率でSPステージ発生
		SP_flg = true;
	}

}

//更新
void CDPDecision::Update(void)
{

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph,true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		//メニューのタイプ処理
		if (b_MenuMamt->GetMenuType()== MENUT_GAME_END) {
			m_bEnd = true;
			m_NextScene = SCENENO_SELECTMODE;
		}
		else
		{
			//項目を選んでいる
			m_bEnd = true;
			m_NextScene = SCENENO_GAME;
		}

	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}

	if (g_pInput->IsKeyPush(MOFKEY_P))
	{
		SP_flg = !SP_flg;
	}

	//説明表示中
	if (flagD == true)
	{
		//エンターで非表示
		if (g_pInput->IsKeyPush(MOFKEY_RETURN)) {
			flagD = false;
		}		
		return;
	}

	if (b_MenuMamt->IsShow())
	{
		//メニューの更新
		b_MenuMamt->Update();

		//メニュー決定時
		if (b_MenuMamt->IsEnter())
		{
			//メニューのタイプ処理
			switch (b_MenuMamt->GetMenuType())
			{
			case MENUT_DPCONFIRM:
				if (b_MenuMamt->GetSelect() == 0)
				{
					//DPの選択を記録
					b_Fadein = FADE_OUT;
					b_GameProgMamt->SetDPdec_type(DPDecCnt);
					//メニュー非表示
					b_MenuMamt->Hide();
				}
				else if (b_MenuMamt->GetSelect() == 1)
				{
					//メニュー非表示
					b_MenuMamt->Hide();
				}

				break;

			case MENUT_GAME_END:
				if (b_MenuMamt->GetSelect() == 0)
				{
					b_Fadein = FADE_OUT;
					//メニュー非表示
					b_MenuMamt->Hide();
				}
				else if (b_MenuMamt->GetSelect() == 1)
				{
					//メニュー非表示
					b_MenuMamt->Hide();
				}
				break;
			default:
				break;
			}

		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//DP選択確定メニュー表示
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if(g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//終了メニュー表示
		b_MenuMamt->Show(MENUT_GAME_END);
	}
	else 
	{
		//矢印キー右で選択が右に行くようにする
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			if (DPDecCnt < DPDECISION_MENUCNT - 1)
			{
				DPDecCnt++;
			}
		}
		//矢印キー左で選択が左に行くようにする
		else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
		{
			if (DPDecCnt > 0)
			{
				DPDecCnt--;
			}
		}
		//矢印キー下で選択が下がるようにする
		//下に下がる＝３つ先のものになる
		if (g_pInput->IsKeyPush(MOFKEY_DOWN))
		{
			if (DPDecCnt < DPDECISION_MENUCNT - 1 && DPDecCnt < 2)
			{
				DPDecCnt += 3;
			}
			else if (DPDecCnt == 3)
			{
				DPDecCnt = 3;
			}
		}

		//矢印キー上で選択が上がるようにする
		//上に上がる＝３つ前のものになる
		if (g_pInput->IsKeyPush(MOFKEY_UP))
		{
			if (DPDecCnt > 0 && DPDecCnt - 3 >= 0)
			{
				DPDecCnt -= 3;
			}
		}

	}
}

//描画
void CDPDecision::Render(void)
{
	//配列の番号とDP名の対応は以下の通りです。
	//[0]→想像力
	//[1]→行動力
	//[2]→魅力
	//[3]→コミュ力
	//[4]→学力

	//選択画像矩形
	CRectangle recSelect[5] = { {0,0,300,300},{300,0,600,301},{600,0,900,300},{0,301,300,601},{300,301,600,601} };

	//選択画像表示位置X
	int	PosSelectX[5] = { 93,488,885,94,489 };
	//選択画像表示位置Y
	int PosSelectY[5] = { 46,45,46,371,375 };

	//説明文字矩形
	CRectangle recExText[5] = { {0,0,343,259},{344,0,687,259},{688,0,1031,259},{0,259,344,518},{343,259,708,519} };

	//説明文字表示位置X
	int	PosTextX[5] = { 867,867,867,867,850 };
	//説明文字表示位置Y
	int PosTextY = 397;

	//背景黒板
	m_BackTextureA.Render(0, 0);

	//選択枠
	m_SelectTexture.Render(PosSelectX[DPDecCnt], PosSelectY[DPDecCnt], recSelect[DPDecCnt]);

	//黒塗りキャラ
	m_BackTextureC.Render(0, 0);

	//説明文字
	m_TextTexture.Render(PosTextX[DPDecCnt], PosTextY, recExText[DPDecCnt]);

	//初回表示時説明表示
	if (flagD == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_ExTexture.Render(0, 124);
	}

	//メニューの描画
	if (b_MenuMamt->GetMenuType() == MENUT_DPCONFIRM){

		//DP選択決定メニュー画面
		b_MenuMamt->Render(DPDecCnt);

	}
	else
	{
		//ゲーム画面終了画面
		b_MenuMamt->Render();
	}

	//フェードアウト
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}

//デバック描画
void CDPDecision::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 300, "DPDecCnt:%d", DPDecCnt);

	if (SP_flg) {
		CGraphicsUtilities::RenderString(10, 330, "SPあり");

	}
	else
	{
		CGraphicsUtilities::RenderString(10, 330, "SPなし");

	}

}

void CDPDecision::Release(void)
{
	m_BackTextureA.Release();
	m_BackTextureC.Release();
	m_TextTexture.Release();
	m_SelectTexture.Release();
	m_ExTexture.Release();


	b_GameProgMamt->SetDPdec_SPflg(SP_flg);
	b_GameProgMamt->InitializeStatus();

}
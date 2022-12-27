#include "DPDecision.h"
#include "Define.h"



#define DPDecisionMenuCnt (6)

int DPDecCnt = 0;

int	DPDecMenuItemCnt = 2;

bool flagD = true;


//コンストラクタ
CDPDecision::CDPDecision() :
	m_BackTextureA(),
	m_BackTextureC(),
	m_TextTexture(),
	m_SelectTexture()
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

	if (!m_BackTextureA.Load("DPDecision_BGA.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_SelectTexture.Load("DPDecision_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_BackTextureC.Load("DPDecision_BGC.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TextTexture.Load("DPDecision_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_ExTexture.Load("DPDecision_ExText.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

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

	for (int i = 0; i < 5; i++)
	{
		//m_SelectDP[i] = false;
	}

	//素材ロード
	Load();
	//エラー状態でない場合
	if (b_LoadSitu != LOAD_ERROR) {
		//初期化完了
		b_LoadSitu = LOAD_DONE;
	}

	DPDecCnt = 0;
	flagD = true;

	//フェードイン
	m_WhiteBakAlph = 255;
	b_Fadein = FADE_IN;
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

		//戻るボタン
		if (DPDecCnt == 5) {
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

	//戻るボタンにカーソルがあって、エンターでモードセレクト画面へ
	if (DPDecCnt == 5 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	if (flagD == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		flagD = false;
	}
	else if (b_MenuMamt->IsShow())
	{
		b_MenuMamt->Update();
		if (b_MenuMamt->IsEnter())
		{
			if (b_MenuMamt->GetSelect() == 0)
			{
				//ここでフラグをゲームに受け渡し？
				b_Fadein = FADE_OUT;
				b_GameProgMamt->SetDPdec_type(DPDecCnt);
				//消す
				b_MenuMamt->Hide();
			}
			else if (b_MenuMamt->GetSelect() == 1)
			{
				//初期化
				for (int i = 0; i < 5; i++)
				{
					//m_SelectDP[i] = false;
				}
				b_MenuMamt->Hide();
			}

		}
	}
	else if (DPDecCnt == 0 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[0] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[1] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 2 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[2] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 3 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[3] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 4 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[4] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else
	{
		//矢印キー右で選択が右に行くようにする
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			if (DPDecCnt < DPDecisionMenuCnt - 1)
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
			if (DPDecCnt < DPDecisionMenuCnt - 1 && DPDecCnt < 3)
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

	m_BackTextureA.Render(0, 0);

	m_SelectTexture.Render(PosSelectX[DPDecCnt], PosSelectY[DPDecCnt], recSelect[DPDecCnt]);

	m_BackTextureC.Render(0, 0);

	m_TextTexture.Render(PosTextX[DPDecCnt], PosTextY, recExText[DPDecCnt]);

	if (flagD == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_ExTexture.Render(0, 200);
	}

	//メニューの描画
	b_MenuMamt->Render(DPDecCnt);

	//フェードアウト
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}

//デバック描画
void CDPDecision::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 300, "DPDecCnt:%d", DPDecCnt);
}

void CDPDecision::Release(void)
{
	m_BackTextureA.Release();
	m_BackTextureC.Release();
	m_TextTexture.Release();
	m_SelectTexture.Release();
	m_ExTexture.Release();
}
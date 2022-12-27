#include "Gallery.h"


#define MenuCnt (16)

int galleryCnt = 0;



CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
	m_NotLastApp(),
	m_SelectTexture(),
	m_SelectTexture_s(),
	m_BackButton(),
	m_PickUp(),
	m_Text()
{

}

CGallery::~CGallery()
{

}

//ロード
void CGallery::Load(void)
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Gallery");

	//背景テクスチャの読み込み
	if (!m_BackTexture.Load("CollectionBG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//最終容姿選択画像読み込み
	if (!m_LastApp.Load("collection.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//説明文
	if (!m_PickUpText.Load("Collection_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//未解放最終容姿選択画像読み込み
	char* NotFound_name[] = {
		"collection_NotFound_00.png",
		"collection_NotFound_01.png",
		"collection_NotFound_02.png",
		"collection_NotFound_03.png",
		"collection_NotFound_04.png",
		"collection_NotFound_05.png",
		"collection_NotFound_06.png",
		"collection_NotFound_07.png",
		"collection_NotFound_08.png",
		"collection_NotFound_09.png",
		"collection_NotFound_10.png",
		"collection_NotFound_11.png",
		"collection_NotFound_12.png",
		"collection_NotFound_13.png",
		"collection_NotFound_14.png"
	};

	for (int i = 0; i < 15; i++)
	{
		if (!m_NotLastApp[i].Load(NotFound_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	if (!m_NotLastApp[3].Load("collection_NotFound_03.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[4].Load("collection_NotFound_04.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[5].Load("collection_NotFound_05.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[6].Load("collection_NotFound_06.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[7].Load("collection_NotFound_07.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[8].Load("collection_NotFound_08.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[9].Load("collection_NotFound_09.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[10].Load("collection_NotFound_10.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[11].Load("collection_NotFound_11.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[12].Load("collection_NotFound_12.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[13].Load("collection_NotFound_13.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_NotLastApp[14].Load("collection_NotFound_14.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//最終容姿の台紙テクスチャ(バラ&ピックアップ用)
	char* Picup_name[] = {
		"Picup1.png",
		"Picup2.png",
		"Picup3.png",
		"Picup4.png",
		"Picup5.png",
		"Picup6.png",
		"Picup7.png",
		"Picup8.png",
		"Picup9.png",
		"Picup10.png",
		"Picup11.png",
		"Picup12.png",
		"Picup13.png",
		"Picup14.png",
		"Picup15.png"
	};

	for (int i = 0; i < 15; i++)
	{
		if (!m_LastAppPic[i].Load(Picup_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}


	if (!m_PickUp.Load("Picup.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_Text.Load("Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//選択時の四角形
	if (!m_SelectTexture.Load("Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	if (!m_SelectTexture_s.Load("Select_s.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//戻るボタン
	if (!m_BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	b_LoadSitu = LOAD_COMP;

}

//初期化
void CGallery::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
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

	//現在のシーンセット
	m_NowScene = SCENENO_GALLERY;

	//フェードイン用
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

}

//更新
void CGallery::Update(void)
{
	b_MusicManager->BGMStart(BGMT_GALLERY);

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}

	//フェードアウト終了->次のシーンへ
	if (b_Fadein == FADE_NEXT) {

		//モードセレクトへ
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}


	//Enterで戻るかは検討
	if (galleryCnt == 15 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//矢印キー右で選択が右に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//SE再生被りなし調整可
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1)
		{
			galleryCnt++;
		}
	}

	//矢印キー左で選択が左に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0)
		{
			galleryCnt--;
		}
	}

	//矢印キー下で選択が下がるようにする
	//下に下がる＝5つ先のものになる
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1 && galleryCnt <= 10)
		{
			galleryCnt += 5;
		}
		else if (galleryCnt > 10)
		{
			galleryCnt = 15;
		}
	}
	//矢印キー上で選択が上がるようにする
	//上に上がる＝5つ前のものになる
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0 && galleryCnt - 5 >= 0)
		{
			galleryCnt -= 5;
		}
	}


}

//描画
void CGallery::Render(void)
{

	//最終容姿台紙
	m_BackTexture.Render(0, 0);

	//最終容姿解放済み画像
	m_LastApp.Render(60, 40);

	//最終容姿表示位置
	m_PickUp.Render(766, 40);

	//テキストボックス
	m_Text.Render(766, 461);

	//戻るボタン
	m_BackButton.Render(60, 650);

	//フラグがfalseの場合、最終容姿を隠す処理
	//画像に差し替える
	for (int i = 0; i < 15; i++)
	{
		if (LastAddFlag[i] == false)
		{
			m_NotLastApp[i].Render(pos[i].x, pos[i].y);
		}

	}
	//選択時囲み枠の表示
	if (galleryCnt == 15)
	{
		m_SelectTexture_s.Render(60, 650);
		m_PickUp.Render(766, 50);
	}
	else if (galleryCnt != 15)
	{
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
	}

	//もし最終容姿解放フラグがFalseだった場合
	if (LastAddFlag[galleryCnt] == false)
	{
		//最終容姿を表示せず別画像を表示
		m_PickUp.Render(766, 50);

		//未解放時の表記にする
		m_NotPickUpText.Render(766, 461, RecTextBox[galleryCnt]);
	}
	else
	{
		//最終容姿を表示
		m_LastAppPic[galleryCnt].Render(766, 50);

		m_PickUpText.Render(766, 461, RecTextBox[galleryCnt]);
	}

	//フェードアウト明転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 255, 255, 255));


}

void CGallery::RenderDebug(void)
{
	//矩形数確認用
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "galleryCnt:%d", galleryCnt);

	CGraphicsUtilities::RenderString(10, 10, "ギャラリー画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	//フラグ切り換え
	//後日デバックに書き写し
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		if (LastAddFlag[0] == false)
		{
			LastAddFlag[0] = true;
		}
		else
		{
			LastAddFlag[0] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		if (LastAddFlag[1] == false)
		{
			LastAddFlag[1] = true;
		}
		else
		{
			LastAddFlag[1] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_3))
	{
		if (LastAddFlag[2] == false)
		{
			LastAddFlag[2] = true;
		}
		else
		{
			LastAddFlag[2] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_4))
	{
		if (LastAddFlag[3] == false)
		{
			LastAddFlag[3] = true;
		}
		else
		{
			LastAddFlag[3] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_5))
	{
		if (LastAddFlag[4] == false)
		{
			LastAddFlag[4] = true;
		}
		else
		{
			LastAddFlag[4] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_6))
	{
		if (LastAddFlag[5] == false)
		{
			LastAddFlag[5] = true;
		}
		else
		{
			LastAddFlag[5] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_7))
	{
		if (LastAddFlag[6] == false)
		{
			LastAddFlag[6] = true;
		}
		else
		{
			LastAddFlag[6] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_8))
	{
		if (LastAddFlag[7] == false)
		{
			LastAddFlag[7] = true;
		}
		else
		{
			LastAddFlag[7] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_9))
	{
		if (LastAddFlag[8] == false)
		{
			LastAddFlag[8] = true;
		}
		else
		{
			LastAddFlag[8] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		if (LastAddFlag[9] == false)
		{
			LastAddFlag[9] = true;
		}
		else
		{
			LastAddFlag[9] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_Q))
	{
		if (LastAddFlag[10] == false)
		{
			LastAddFlag[10] = true;
		}
		else
		{
			LastAddFlag[10] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_W))
	{
		if (LastAddFlag[11] == false)
		{
			LastAddFlag[11] = true;
		}
		else
		{
			LastAddFlag[11] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_E))
	{
		if (LastAddFlag[12] == false)
		{
			LastAddFlag[12] = true;
		}
		else
		{
			LastAddFlag[12] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_R))
	{
		if (LastAddFlag[13] == false)
		{
			LastAddFlag[13] = true;
		}
		else
		{
			LastAddFlag[13] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_T))
	{
		if (LastAddFlag[14] == false)
		{
			LastAddFlag[14] = true;
		}
		else
		{
			LastAddFlag[14] = false;
		}
	}
}


//リリース
void CGallery::Release(void)
{
	m_BackTexture.Release();
	m_SelectTexture.Release();
	m_SelectTexture_s.Release();
	m_BackButton.Release();

	m_LastApp.Release();

	for (int i = 0; i < 15; i++)
	{
		m_NotLastApp[i].Release();
	}

	for (int i = 0; i < 15; i++)
	{
		m_LastAppPic[i].Release();
	}

	m_PickUp.Release();
	m_Text.Release();

	b_MusicManager->BGMStop(BGMT_GALLERY);

}



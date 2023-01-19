////////////////////////////////////////
//	ギャラリーのプログラムです　　　　//
//									　//
//　作成者：松浦未羽　　　　　		　//
//									　//
//　リファクタリングした人：田中環　　//
//									　//
//　最終更新：2023/01/17			　//
////////////////////////////////////////

#include "Gallery.h"

CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
	m_SelectTexture(),
	m_SelectTexture_s(),
	m_BakLastAp(),
	S_LastParameter(),
	m_BakLastRect(),
	m_PickUpText(),
	m_NotPickUpText(),
	m_BackButton(),
	m_Text(),
	m_BakAlph(),
	m_galleryCnt()
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

	//未解放本棚画像読み込み
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
		if (!S_LastParameter[i].s_NotLastApp.Load(NotFound_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}


	//最終容姿のテクスチャ
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
		if (!S_LastParameter[i].s_LastAppPic.Load(Picup_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	//最終容姿背景
	if (!m_BakLastAp.Load("collection_Picup_Rare.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//未解放時のヒントアイコン
	if (!m_NotPickUpText.Load("Collection_NotFoundText.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//テキストボックス背景
	if (!m_Text.Load("Collection_TextBox.png"))
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

	//戻るボタン選択枠
	if (!m_SelectTexture_s.Load("BackButton_Select.png"))
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

	//最終容姿背景の表示矩形を設定
	//ノーマル
	m_BakLastRect[BL_NORMAL].SetValue(800,400,1200,800);

	//スーパーレディ
	m_BakLastRect[BL_SUPERLADY].SetValue(0, 0, 400, 400);

	//お調子者
	m_BakLastRect[BL_OTYOUSI].SetValue(400, 0, 800, 400);

	//文学少女
	m_BakLastRect[BL_BUNGAKU].SetValue(800, 0, 1200, 400);

	//中二病
	m_BakLastRect[BL_TYUNI].SetValue(0, 400, 400, 800);

	//神対応
	m_BakLastRect[BL_KAMITAIOU].SetValue(400, 400, 800, 800);

	//解放状況を取得
	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_LastAddFlag = b_GameProgMamt->GetGallery_flg(i);
	}

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

	//カーソル初期化
	m_galleryCnt = 0;
}

//更新
void CGallery::Update(void)
{
	//BGM再生
	b_MusicManager->BGMStart(BGMT_GALLERY);

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//フェードアウト終了->次のシーンへ
	if (b_Fadein == FADE_NEXT) {

		//モードセレクトへ
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}


	//フラグ切り換え
	//後日デバックに書き写し
	if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		S_LastParameter[m_galleryCnt].s_LastAddFlag = S_LastParameter[m_galleryCnt].s_LastAddFlag ? !S_LastParameter[m_galleryCnt].s_LastAddFlag : !S_LastParameter[m_galleryCnt].s_LastAddFlag;
	}


	//Enterで戻る
	if (m_galleryCnt == 15 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	
	//矢印キー右で選択が右に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//SE再生被りなし調整可
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt < MenuCnt)
		{
			m_galleryCnt++;
		}
	}

	//矢印キー左で選択が左に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt > 0)
		{
			m_galleryCnt--;
		}
	}

	//矢印キー下で選択が下がるようにする
	//下に下がる＝5つ先のものになる
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt < MenuCnt&& m_galleryCnt <= 10)
		{
			m_galleryCnt += 5;
		}
		else if (m_galleryCnt > 10)
		{
			m_galleryCnt = 15;
		}
	}
	//矢印キー上で選択が上がるようにする
	//上に上がる＝5つ前のものになる
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (m_galleryCnt > 0 && m_galleryCnt - 5 >= 0)
		{
			m_galleryCnt -= 5;
		}
	}


}

//描画
void CGallery::Render(void)
{

	//ギャラリー画面背景
	m_BackTexture.Render(0, 0);

	//左側本棚表示
	m_LastApp.Render(60, 40);

	//戻るボタン
	m_BackButton.Render(60, 650);

	//フラグがfalseの場合、最終容姿を隠す処理
	//画像に差し替える
	for (int i = 0; i < 15; i++)
	{
		if (S_LastParameter[i].s_LastAddFlag == false)
		{
			//未開放本テクスチャ
			S_LastParameter[i].s_NotLastApp.Render(60 + (120 * (i % 5)), 40 + ((i / 5) * 200));
		}

	}

	//選択時囲み枠の表示
	//戻るボタン
	if (m_galleryCnt == 15)
	{
		m_SelectTexture_s.Render(60, 650);

	}
	else
	{
		//テキストボックス背景
		m_Text.Render(766, 461);

		//最終容姿解放フラグ
		if (S_LastParameter[m_galleryCnt].s_LastAddFlag)
		{

			//最終容姿背景
			if (m_galleryCnt == LT_SUPERLADY) {

				//スーパーレディ
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_SUPERLADY]);
			}
			else if (m_galleryCnt == LT_OTYOUSI)
			{
				//お調子者
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_OTYOUSI]);
			}
			else if (m_galleryCnt == LT_BUNGAKU)
			{
				//文学少女
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_BUNGAKU]);
			}
			else if (m_galleryCnt == LT_TYUNI)
			{
				//中二病
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_TYUNI]);
			}
			else if (m_galleryCnt == LT_KAMITAIOU)
			{
				//神対応
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_KAMITAIOU]);
			}
			else
			{
				//その他ノーマル
				m_BakLastAp.Render(766, 50, m_BakLastRect[BL_NORMAL]);
			}

			//最終容姿を表示
			S_LastParameter[m_galleryCnt].s_LastAppPic.Render(766, 50);

			//説明テキスト表示矩形
			CRectangle r_Text = { (400.f * (m_galleryCnt % 3)),(m_galleryCnt / 3) * 189.f,
								400.f + (400 * (m_galleryCnt % 3)),189.f + (189 * (m_galleryCnt / 3))
			};

			//説明文
			m_PickUpText.Render(766, 461, r_Text);

		}
		else
		{

			//説明テキスト表示矩形
			CRectangle r_Text = { (400.f * (m_galleryCnt % 3)),(m_galleryCnt / 3) * 189.f,
								400.f + (400 * (m_galleryCnt % 3)),189.f + (189 * (m_galleryCnt / 3)) };

			//未解放時の表記にする
			m_NotPickUpText.Render(766, 461, r_Text);
		}

		//本棚に選択囲み枠
		m_SelectTexture.Render(60 + (120 * (m_galleryCnt % 5)), 40 + ((m_galleryCnt / 5) * 200));
	}


	//フェードアウト明転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 255, 255, 255));

}

void CGallery::RenderDebug(void)
{
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//矩形数確認用
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "m_galleryCnt:%d", m_galleryCnt);

	CGraphicsUtilities::RenderString(10, 10, "ギャラリー画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");


}


//リリース
void CGallery::Release(void)
{
	m_BackTexture.Release();
	m_SelectTexture.Release();
	m_SelectTexture_s.Release();
	m_BackButton.Release();
	m_LastApp.Release();
	m_BakLastAp.Release();
	m_PickUpText.Release();

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_LastAppPic.Release();
	}

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_NotLastApp.Release();
	}

	m_Text.Release();
	m_NotPickUpText.Release();

	//BGMストップ
	b_MusicManager->BGMStop(BGMT_GALLERY);

}


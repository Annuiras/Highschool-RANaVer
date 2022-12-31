#include "Gallery.h"


#define MenuCnt (16)

int galleryCnt = 0;


CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
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
		if (!S_LastParameter[i].s_NotLastApp.Load(NotFound_name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}


	//最終容姿のテクスチャ(バラ&ピックアップ用)
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

	//Vector2{}		：本座標
	//CRectangle{}	：説明文表示矩形
	//解放フラグ	：true,解放済

	//姉御
	S_LastParameter[0] = SetLastParameter({ 60, 40 }, { 0,0,400,189 },true);

	//クラスの人気者
	S_LastParameter[1] = SetLastParameter({ 180,40 }, { 400,0,800,189 },true);

	//ギャル
	S_LastParameter[2] = SetLastParameter({ 300,40 }, { 800,0,1200,189 },true);

	//応援団長
	S_LastParameter[3] = SetLastParameter({ 420,40 }, { 0,189,400,378 },true);

	//図書室の長
	S_LastParameter[4] = SetLastParameter({ 540,40 }, { 400,189,800,378 },true);

	//オタク
	S_LastParameter[5] = SetLastParameter({ 60,240 }, { 800,189,1200,378 },true);

	//インフルエンサー
	S_LastParameter[6] = SetLastParameter({ 180,240 }, { 0,378,400,567 },true);

	//委員長
	S_LastParameter[7] = SetLastParameter({ 300,240 }, { 400,378,800,567 },true);

	//高嶺の花
	S_LastParameter[8] = SetLastParameter({ 420,240 }, { 800,378,1200,567 },true);

	//ヤンキー
	S_LastParameter[9] = SetLastParameter({ 540,240 }, { 0,567,400,756 },true);

	//スーパーレディ
	S_LastParameter[10] = SetLastParameter({ 60,440 }, { 400,567,800,756 },true);

	//お調子者
	S_LastParameter[11] = SetLastParameter({ 180,440 }, { 800,567,1200,756 },true);

	//文学少女
	S_LastParameter[12] = SetLastParameter({ 300,440 }, { 0,756,400,945 },true);

	//中二病
	S_LastParameter[13] = SetLastParameter({ 420,440 }, { 400,756,800,945 },true);

	//神対応
	S_LastParameter[14] = SetLastParameter({ 540,440 }, { 800,756,1200,945 },true);


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
		if (S_LastParameter[i].s_LastAddFlag == false)
		{
			//未開放本テクスチャ
			S_LastParameter[i].s_NotLastApp.Render(S_LastParameter[i].s_Mount_Pos.x, S_LastParameter[i].s_Mount_Pos.y);
		}

	}

	//選択時囲み枠の表示
	if (galleryCnt == 15)
	{
		m_SelectTexture_s.Render(60, 650);
		m_PickUp.Render(766, 50);
	}
	else
	{
		//選択矩形
		m_SelectTexture.Render(S_LastParameter[galleryCnt].s_Mount_Pos.x, S_LastParameter[galleryCnt].s_Mount_Pos.y);
	}

	//もし最終容姿解放フラグがFalseだった場合
	if (S_LastParameter[galleryCnt].s_LastAddFlag == false)
	{
		//最終容姿を表示せず別画像を表示
		m_PickUp.Render(766, 50);

		//未解放時の表記にする
		m_NotPickUpText.Render(766, 461,S_LastParameter[galleryCnt].s_TextBoxRect);
	}
	else
	{
		//最終容姿を表示
		S_LastParameter[galleryCnt].s_LastAppPic.Render(766, 50);

		//説明文
		m_PickUpText.Render(766, 461, S_LastParameter[galleryCnt].s_TextBoxRect);
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
	if (g_pInput->IsKeyPush(MOFKEY_O))
	{
		if (S_LastParameter[galleryCnt].s_LastAddFlag == false)
		{
			S_LastParameter[galleryCnt].s_LastAddFlag = true;
		}
		else
		{
			S_LastParameter[galleryCnt].s_LastAddFlag = false;
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

	m_PickUpText.Release();

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_LastAppPic.Release();
	}

	for (int i = 0; i < 15; i++)
	{
		S_LastParameter[i].s_NotLastApp.Release();
	}

	m_PickUp.Release();
	m_Text.Release();

	b_MusicManager->BGMStop(BGMT_GALLERY);

}


#include "GameClear.h"


//コンストラクタ
CGameClear::CGameClear() :
	m_BackTexture(),
	m_UITexture(),
	gAlpha(0.0f),
	m_BlackBakAlph(0),
	m_WhiteBakAlph(0),
	Memory1(),
	Memory2(),
	Status(),
	StatusRender(),
	LastDetailNo(),
	isStop(false)
{}

//デストラクタ
CGameClear::~CGameClear()
{

}

//ステータスから最終容姿を判定する
void CGameClear::StatusJudgement(void)
{
	//ステータス上位２つの添え字
	int m_Status_1=0, m_Status_2=0;

	//:同数の処理聞く
	//ステータスの大きさ一番目の添え字保存
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (Status[i] > Status[m_Status_1])
		{
			m_Status_1 = i;
		}
	}

	//二番目の初期値
	m_Status_2 = m_Status_1 + 1;
	if (m_Status_2 >= DP_COUNT)
		m_Status_2 = 0;

	//ステータスの大きさ二番目の添え字保存
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (m_Status_1 == i) {
			continue;
		}

		if (Status[i] > Status[m_Status_2])
		{
			m_Status_2 = i;
		}
	}

	//学力一点突破
	if (m_Status_1 == DP_SCHOLASTIC && Status[m_Status_1]>= 100) {
		//文学少女
		LastDetailNo = LT_BUNGAKU;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//行動力一点突破
	if (m_Status_1 == DP_ACTION&& Status[m_Status_1] >= 100) {
		//お調子者
		LastDetailNo = LT_OTYOUSI;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//想像力一点突破
	if (m_Status_1 == DP_IMAGINATION && Status[m_Status_1] >= 100) {
		//厨二病
		LastDetailNo = LT_TYUNI;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//コミュ力一点突破
	if (m_Status_1 == DP_COMMUNICATION && Status[m_Status_1] >= 100) {
		//神対応
		LastDetailNo = LT_KAMITAIOU;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//魅力一点突破
	if (m_Status_1 == DP_CHARM && Status[m_Status_1] >= 100) {
		//スーパーレディ
		LastDetailNo = LT_SUPERLADY;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}

	//以下二点参照
	//学力
	if (m_Status_1 == DP_SCHOLASTIC || m_Status_2 == DP_SCHOLASTIC) {

		//と行動力
		if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {
			//委員長
			LastDetailNo = LT_IINTYOU;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//と想像力
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//図書室の長
			LastDetailNo = LT_TOSYO;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//とコミュ力
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//人気者
			LastDetailNo = LT_NINKIMONO;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//高嶺の花
			LastDetailNo = LT_TAKANE;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

	//行動力
	if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {

		//と想像力
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//オタク
			LastDetailNo = LT_OTAKU;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//とコミュ力
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//応援団長
			LastDetailNo = LT_OUEN;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//ヤンキー
			LastDetailNo = LT_YABKI;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

	//想像力
	if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {

		//とコミュ力
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//姉御
			LastDetailNo = LT_ANEGO;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//インフルエンサー
			LastDetailNo = LT_INFLUENCER;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

	//コミュ力
	if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {

		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//ギャル
			LastDetailNo = LT_GYARU;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

}

//チャート土台作成
void CGameClear::buildChart(int* Status, Vector2* PointsStatus)
{
	double kosu = ((double)360.0 / ITEM_NUM);


	// 項目ごとの回転角度
	double radian = MOF_ToRadian(kosu);

	// 開始角度
	double startRadian = (double)MOF_ToRadian(-90.0f);

	for (int i = 0; i < ITEM_NUM; i++) {

		// 中心からの距離を求める
		double length = CHART_SIZE * ((double)Status[i] / MAX_STATUS);

		// 単位ベクトルに距離を乗算
		double cos_X = cosf(startRadian + radian * i);
		double x = cos_X * length;
		double y = sinf(startRadian + radian * i) * length;

		PointsStatus[i].x = (float)x;
		PointsStatus[i].y = (float)y;

	}
}

//線の描画を行う
void CGameClear::drawChart(Vector2* PointsStatus, MofU32 cl)
{
	for (int i = 0; i < ITEM_NUM; i++) {

		int x1 = (int)PointsStatus[i].x;
		int y1 = (int)PointsStatus[i].y;

		int x2 = (int)PointsStatus[(i + 1) % ITEM_NUM].x;
		int y2 = (int)PointsStatus[(i + 1) % ITEM_NUM].y;



		//線の描画
		CGraphicsUtilities::RenderLine((int)(x1 + CHART_CENTER_X),
			(int)(y1 + CHART_CENTER_Y),
			(int)(x2 + CHART_CENTER_X),
			(int)(y2 + CHART_CENTER_Y),
			cl);
	}
}

//素材ロード
void CGameClear::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("GameClear");

	char* name[15] =
	{
		"GameClearBG_OlderSister.png",	 //姉御
		"GameClearBG_ClassFavorite.png", //人気者
		"GameClearBG_Gal.png",			 //ギャル
		"GameClearBG_CheerLeader.png",	 //応援団長
		"GameClearBG_LibraryManager.png",//図書室の長
		"GameClearBG_Otaku.png",		 //オタク
		"GameClearBG_Infulencer.png",	 //インフルエンサー
		"GameClearBG_Chairman.png",		 //委員長
		"GameClearBG_LoftyDream.png",	 //高嶺の花
		"GameClearBG_Yankee.png",		 //ヤンキー
		"GameClearBG_SuperLady.png",	 //スーパーレディ
		"GameClearBG_FussyPerson.png",	 //お調子者
		"GameClearBG_LiteratureGirl.png",//文学少女
		"GameClearBG_Chu-nibyou.png",	 //厨二病
		"GameClearBG_GodSupport.png",	 //神対応
		
	};

	for (int i = 0; i < 15; i++)
	{
		if (!m_BackTexture[i].Load(name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	if (!m_UITexture.Load("GameClearUI.png"))
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
void CGameClear::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
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

	//最大値メモリ用
	for (int i = 0; i < ITEM_NUM; i++)
	{
		Memory1[i] = MAX_STATUS;

	}

	//グラフ半分値メモリ用
	for (int i = 0; i < ITEM_NUM; i++)
	{
		Memory2[i] = MAX_STATUS / 2;

	}

	//動的なステータス初期化
	for (int i = 0; i < ITEM_NUM; i++)
	{
		StatusRender[i] = 0;
	}

	//ゲーム画面からDP取得数受けとる
	for (int i = 0; i < DP_COUNT; i++)
	{
		Status[i] = *(b_GameProgMamt->GetGame_DPNum()+i);
	}

	//文字用アルファ値
	gAlpha = 0;

	//フェードイン用アルファ値
	m_WhiteBakAlph = 255;
	m_BlackBakAlph = 0;
	b_Fadein = FADE_IN;

	isStop = false;

	//最終容姿番号
	LastDetailNo = 0;

	//ステータスから最終容姿を判定する
	StatusJudgement();


	//BGM再生
	b_MusicManager->BGMStart(BGMT_CLEAR);
}



//更新
void CGameClear::Update(void)
{

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph, true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}

	//エンターキーでモードセレクト画面へ
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}


	//α値変更処理
	//ちかちかさせてる
	if (!isStop)
	{
		gAlpha += 3;

		if (gAlpha >= 255)
		{
			isStop = true;
		}
	}
	else
	{
		gAlpha -= 3;
		if (gAlpha <= 0)
		{
			isStop = false;
		}
	}


	//グラフがじわじわ動く
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (Status[i]>= StatusRender[i])
		{
			if (Status[i] >= 100) {
				StatusRender[i]+=5;
			}
			StatusRender[i]++;
		}
	}


	// チャートを生成
	buildChart(StatusRender, PointsStatus);
	buildChart(Memory1, MemoryPoints1);
	buildChart(Memory2, MemoryPoints2);
}

//描画
void CGameClear::Render(void)
{
	m_BackTexture[LastDetailNo].Render(0, 0);

	// チャートを描画
	drawChart(PointsStatus, MOF_COLOR_RED);
	drawChart(MemoryPoints1, MOF_COLOR_BLACK);
	drawChart(MemoryPoints2, MOF_COLOR_BLACK);

	//座標取得
	Vector2 center(CHART_CENTER_X, CHART_CENTER_Y);
	Vector2 point1(PointsStatus[0].x+ CHART_CENTER_X, PointsStatus[0].y+ CHART_CENTER_Y);
	Vector2 point2(PointsStatus[1].x+ CHART_CENTER_X, PointsStatus[1].y+ CHART_CENTER_Y);
	Vector2 point3(PointsStatus[2].x + CHART_CENTER_X, PointsStatus[2].y + CHART_CENTER_Y);
	Vector2 point4(PointsStatus[3].x + CHART_CENTER_X, PointsStatus[3].y + CHART_CENTER_Y);
	Vector2 point5(PointsStatus[4].x + CHART_CENTER_X, PointsStatus[4].y + CHART_CENTER_Y);

	//三角形を描いてグラフを塗りつぶす
	CGraphicsUtilities::RenderFillTriangle(center, point1, point2, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point2, point3, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point3, point4, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point4, point5, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point5, point1, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);


	//半透明にしていく
	g_pGraphics->SetBlending(BLEND_NORMAL);
	m_UITexture.Render(370, 2, MOF_ARGB(gAlpha, 255, 255, 255));

	//フェードアウト明転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

	//フェードアウト暗転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BlackBakAlph, 0, 0, 0));

}

void CGameClear::RenderDebug(void)
{
	//CGraphicsUtilities::RenderString(10, 10, "ゲームクリア画面");
	//CGraphicsUtilities::RenderString(10, 40, "エンターでモードセレクト");

	//文字アルファ値表示
	//CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "%d", gAlpha);

	//中心点
	CGraphicsUtilities::RenderFillCircle(CHART_CENTER_X, CHART_CENTER_Y, 2, MOF_COLOR_YELLOW);

	//円の描画
	CGraphicsUtilities::RenderCircle(CHART_CENTER_X,
		CHART_CENTER_Y,
		CHART_SIZE,
		MOF_COLOR_BLACK);

	for (int i = 0; i < ITEM_NUM; i++)
	{
		//CGraphicsUtilities::RenderString(0, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].x);
		//CGraphicsUtilities::RenderString(150, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].y);
		CGraphicsUtilities::RenderString(100, 40 * i + 450, MOF_COLOR_BLACK, StatusName[i], Status[i]);

		CGraphicsUtilities::RenderLine((int)(CHART_CENTER_X),
			(int)(CHART_CENTER_Y),
			(int)(MemoryPoints1[i].x + CHART_CENTER_X),
			(int)(MemoryPoints1[i].y + CHART_CENTER_Y),
			MOF_COLOR_BLACK);
	}

}

void CGameClear::Release(void)
{
	m_UITexture.Release();

	for (int i = 0; i < 15; i++)
	{
		m_BackTexture[i].Release();
	}
	
	//BGM停止
	b_MusicManager->BGMStop(BGMT_CLEAR);

}

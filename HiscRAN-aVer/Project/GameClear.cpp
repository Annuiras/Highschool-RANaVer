//////////////////////////////////////////////
//	ゲームクリア画面のプログラムです　　　  //
//									　　　　//
//　作成者：松浦未羽　　　　　　　　　　 　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#include "GameClear.h"

//コンストラクタ
CGameClear::CGameClear() :
	RandmuBak(),
	m_BackTexture(),
	m_UITexture(),
	gAlpha(0.0f),
	m_BlackBakAlph(0),
	m_WhiteBakAlph(0),
	Memory1(),
	Memory2(),
	Status(),
	StatusSame(),
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
	//ステータス上位２つの添え字,同数カウント
	int m_Status_1 = 0, m_Status_2 = 0, m_Samecont = 0;

	//ステータスの大きさ一番目の添え字保存
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (Status[i] > Status[m_Status_1])
		{
			m_Status_1 = i;
		}
	}

	//大きさ一番目と同数の数字があるか
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (Status[m_Status_1] == Status[i])
		{
			//添え字を保存
			StatusSame[m_Samecont] = i;

			//カウント
			m_Samecont++;
		}
	}

	//同数のステータスが存在する場合
	if (m_Samecont > 0) {

		//ランダムで一番大きいステータスを決める
		m_Status_1 = StatusSame[RandmuBak.GetRandomNumbe(0, m_Samecont - 1)];

		//リセット
		m_Samecont = 0;
	}

	//二番目の初期値
	m_Status_2 = m_Status_1 + 1;
	if (m_Status_2 >= DP_COUNT)
		m_Status_2 = 0;

	//ステータスの大きさ二番目の添え字保存
	for (int i = 0; i < DP_COUNT; i++)
	{
		//一番に採用されているものはスルー
		if (m_Status_1 == i) {
			continue;
		}

		if (Status[i] > Status[m_Status_2])
		{
			m_Status_2 = i;
		}
	}

	//大きさ二番目と同数の数字があるか
	for (int i = 0; i < DP_COUNT; i++)
	{
		//一番に採用されているものはスルー
		if (m_Status_1 == i) {
			continue;
		}

		if (Status[m_Status_2] == Status[i])
		{
			//添え字を保存
			StatusSame[m_Samecont] = i;

			//カウント
			m_Samecont++;
		}
	}

	//同数のステータスが存在する場合
	if (m_Samecont > 0) {

		//ランダムで一番大きいステータスを決める
		m_Status_2 = StatusSame[RandmuBak.GetRandomNumbe(0, m_Samecont - 1)];

		//リセット
		m_Samecont = 0;
	}


	//一番と二番の差を算出
	int m_StatusDiff = Status[m_Status_1] - Status[m_Status_2];

	//学力一点突破
	if (m_Status_1 == DP_SCHOLASTIC && m_StatusDiff >= DIFFERENCE_NUM) {
		//文学少女
		LastDetailNo = LT_BUNGAKU;
		return;
	}
	//行動力一点突破
	if (m_Status_1 == DP_ACTION&& m_StatusDiff >= DIFFERENCE_NUM) {
		//お調子者
		LastDetailNo = LT_OTYOUSI;
		return;
	}
	//想像力一点突破
	if (m_Status_1 == DP_IMAGINATION && m_StatusDiff >= DIFFERENCE_NUM) {
		//厨二病
		LastDetailNo = LT_TYUNI;
		return;
	}
	//コミュ力一点突破
	if (m_Status_1 == DP_COMMUNICATION && m_StatusDiff >= DIFFERENCE_NUM) {
		//神対応
		LastDetailNo = LT_KAMITAIOU;
		return;
	}
	//魅力一点突破
	if (m_Status_1 == DP_CHARM && m_StatusDiff >= DIFFERENCE_NUM) {
		//スーパーレディ
		LastDetailNo = LT_SUPERLADY;
		return;
	}

	//以下二点参照
	//学力
	if (m_Status_1 == DP_SCHOLASTIC || m_Status_2 == DP_SCHOLASTIC) {

		//と行動力
		if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {
			//委員長
			LastDetailNo = LT_IINTYOU;
			return;
		}
		//と想像力
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//図書室の長
			LastDetailNo = LT_TOSYO;
			return;
		}
		//とコミュ力
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//人気者
			LastDetailNo = LT_NINKIMONO;
			return;
		}
		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//高嶺の花
			LastDetailNo = LT_TAKANE;
			return;
		}
	}

	//行動力
	if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {

		//と想像力
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//オタク
			LastDetailNo = LT_OTAKU;
			return;
		}
		//とコミュ力
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//応援団長
			LastDetailNo = LT_OUEN;
			return;
		}
		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//ヤンキー
			LastDetailNo = LT_YABKI;
			return;
		}
	}

	//想像力
	if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {

		//とコミュ力
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//姉御
			LastDetailNo = LT_ANEGO;
			return;
		}
		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//インフルエンサー
			LastDetailNo = LT_INFLUENCER;
			return;
		}
	}

	//コミュ力
	if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {

		//と魅力
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//ギャル
			LastDetailNo = LT_GYARU;
			return;
		}
	}

}

//五角形を生成作成
//引数
//Status--ステータス値

//戻り値
//PointsStatus--
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

		//保存
		PointsStatus[i].x = (float)x;
		PointsStatus[i].y = (float)y;

	}
}

//デバック用
//現在は使用していません
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

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	if (!m_UITexture.Load("BackButton_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

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


	//最終容姿番号
	LastDetailNo = LT_ANEGO;


	//文字用アルファ値
	gAlpha = 0;

	//フェードイン用アルファ値
	m_WhiteBakAlph = 255;
	m_BlackBakAlph = 0;
	b_Fadein = FADE_IN;

	isStop = false;

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

	//ステータス計算
	for (int i = 0; i < DP_COUNT; i++)
	{
		//ゲーム画面からDP数を受けとる
		Status[i] = (*(b_GameProgMamt->Get_DPNum()+i)* DP_CONVERSION_STATUS);
	}
	//SP
	Status[b_GameProgMamt->GetDPdec_type()] += b_GameProgMamt->Get_SP_DPNum() * SP_DP_CONVERSION_STATUS;

	//ステータスから最終容姿を判定する
	StatusJudgement();

	//開始時刻
	m_StartTime = timeGetTime();

}

//更新
void CGameClear::Update(void)
{

	//BGM再生
	b_MusicManager->BGMStart(BGMT_CLEAR);

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph, true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
		return;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}

	//エンターキーでモードセレクト画面へ
	if (gAlpha>=255&&g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}


	//カウントダウン判定
	if (m_StartCount < 5 && timeGetTime() - m_StartTime > 1000)
	{
		//開始時刻
		m_StartTime = timeGetTime();

		//カウント増加
		m_StartCount++;

		if (m_StartCount == 4)
		{
			isStop = true;
		}
	}

	//α値変更処理
	if (isStop)
	{
		gAlpha += 5;
		if (gAlpha >= 255)
		{
			gAlpha = 255;
			isStop = false;
		}
	}

	//グラフがじわじわ動く
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (Status[i]>= StatusRender[i])
		{
			if (Status[i] >= 100) {
				StatusRender[i]+=2;
			}
			StatusRender[i]++;
		}
	}


	// チャートを生成
	//グラフ生成
	buildChart(StatusRender, PointsStatus);

	//デバック用
	buildChart(Memory1, MemoryPoints1);
}

void CGameClear::UpdateDebug(void) {

	//デバッグ用使いにくい修正する
	if (g_pInput->IsKeyHold(MOFKEY_RCONTROL)) {

		if (g_pInput->IsKeyPull(MOFKEY_1)) {

			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[0] -= 1;

			}
			else
			{
				//DP
				Status[0] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_2)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[1] -= 1;

			}
			else
			{
				//DP
				Status[1] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_3)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[2] -= 1;

			}
			else
			{
				//DP
				Status[2] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_4)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[3] -= 1;

			}
			else
			{
				//DP
				Status[3] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_5)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[4] -= 1;

			}
			else
			{
				//DP
				Status[4] += 1;

			}
		}

	}
	else
	{
		if (g_pInput->IsKeyHold(MOFKEY_1)) {

			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[0] -= 1;

			}
			else
			{
				//DP
				Status[0] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_2)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[1] -= 1;

			}
			else
			{
				//DP
				Status[1] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_3)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[2] -= 1;

			}
			else
			{
				//DP
				Status[2] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_4)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[3] -= 1;

			}
			else
			{
				//DP
				Status[3] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_5)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[4] -= 1;

			}
			else
			{
				//DP
				Status[4] += 1;

			}
		}

	}

	//デバッグ用
	if (g_pInput->IsKeyHold(MOFKEY_0)) {
		for (int i = 0; i < ITEM_NUM; i++)
		{
			StatusRender[i] = 0;
		}
	}

	//デバック用
	if (g_pInput->IsKeyPull(MOFKEY_SPACE)) {
		//再判定
		StatusJudgement();
		for (int i = 0; i < ITEM_NUM; i++)
		{
			StatusRender[i] = 0;
		}

	}

}
//描画
void CGameClear::Render(void)
{
	//最終容姿表示
	m_BackTexture[LastDetailNo].Render(0, 0);

	//座標取得
	Vector2 point[ITEM_NUM + 1];

	for (int i = 0; i < ITEM_NUM; i++)
	{
		point[i].x = PointsStatus[i].x + CHART_CENTER_X;
		point[i].y = PointsStatus[i].y + CHART_CENTER_Y;
	}
	point[ITEM_NUM].x = CHART_CENTER_X;
	point[ITEM_NUM].y = CHART_CENTER_Y;

	for (int i = 0; i < ITEM_NUM; i++)
	{
		//クリップ
		int ynum = i+1;
		if (ynum >= ITEM_NUM) {
			ynum = ynum % ITEM_NUM;
		}

		//三角形を描いてグラフを塗りつぶす
		CGraphicsUtilities::RenderFillTriangle(point[ITEM_NUM], point[i], point[ynum],
			Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	}


	//戻るボタン
	m_UITexture.Render(5, 650, MOF_ARGB(gAlpha, 255, 255, 255));

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
	//CGraphicsUtilities::RenderFillCircle(CHART_CENTER_X, CHART_CENTER_Y, 2, MOF_COLOR_YELLOW);

	////円の描画
	//CGraphicsUtilities::RenderCircle(CHART_CENTER_X,
	//	CHART_CENTER_Y,
	//	CHART_SIZE,
	//	MOF_COLOR_BLACK);

	for (int i = 0; i < ITEM_NUM; i++)
	{
		//CGraphicsUtilities::RenderString(0, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].x);
		//CGraphicsUtilities::RenderString(150, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].y);
		CGraphicsUtilities::RenderString(550, 40 * i + 450, MOF_COLOR_BLACK, StatusName[i], Status[i]);

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
	
	//フラグ解放保存
	b_GameProgMamt->SetGallery_flg(LastDetailNo, true);

	//BGM停止
	b_MusicManager->BGMStop(BGMT_CLEAR);

}

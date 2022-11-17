#include "Define.h"
#include "GameClear.h"

//変更するシーン（外部参照。実態はGameApp.cpp）
extern int gChangeScene;

//コンストラクタ
CGameClear::CGameClear() :
	m_BackTexture(),
	m_UITexture(),
	gAlpha(0.0f),
	isStop(false),
	point1x(0),
	point1y(0),
	point2x(0),
	point2y(0),
	point3x(0),
	point3y(0),
	point4x(0),
	point4y(0),
	point5x(0),
	point5y(0)
{

}

//デストラクタ
CGameClear::~CGameClear()
{

}

//素材ロード
bool CGameClear::Load(void)
{
	if (!m_BackTexture.Load("GameClearBG.png"))
	{
		return false;
	}

	if (!m_UITexture.Load("GameClearUI.png"))
	{
		return false;
	}

	return true;
}

//初期化
void CGameClear::Initialize(void)
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		Memory1[i] = MAX_STATUS;

	}

	for (int i = 0; i < ITEM_NUM; i++)
	{
		Memory2[i] = MAX_STATUS / 2;

	}


	//魅力
	Status[0] = 100;

	//行動力
	Status[1] = 27;

	//学力
	Status[2] = 60;

	//想像力
	Status[3] = 2;

	//コミュ力
	Status[4] = 18;

	gAlpha = 0;
	isStop = false;
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

//更新
void CGameClear::Update(void)
{
	//エンターキーでモードセレクト画面へ
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
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
	//魅力
	if (point1x != (int)PointsStatus[0].x + CHART_CENTER_X)
	{
		point1x += 1;
	}
	if (point1y != (int)PointsStatus[0].y + CHART_CENTER_Y)
	{
		point1y += 1;
	}

	//行動力
	if (point2x != (int)PointsStatus[1].x + CHART_CENTER_X)
	{
		point2x += 1;
	}
	if (point2y != (int)PointsStatus[1].y + CHART_CENTER_Y)
	{
		point2y += 1;
	}

	//学力
	if (point3x != (int)PointsStatus[2].x + CHART_CENTER_X)
	{
		point3x += 1;
	}
	if (point3y != (int)PointsStatus[2].y + CHART_CENTER_Y)
	{
		point3y += 1;
	}

	//想像力
	if (point4x != (int)PointsStatus[3].x + CHART_CENTER_X)
	{
		point4x += 1;
	}
	if (point4y != (int)PointsStatus[3].y + CHART_CENTER_Y)
	{
		point4y += 1;
	}

	//コミュ力
	if (point5x != (int)PointsStatus[4].x + CHART_CENTER_X)
	{
		point5x += 1;
	}
	if (point5y != (int)PointsStatus[4].y + CHART_CENTER_Y)
	{
		point5y += 1;
	}

	// チャートを生成
	buildChart(Status, PointsStatus);
	buildChart(Memory1, MemoryPoints1);
	buildChart(Memory2, MemoryPoints2);
}

//描画
void CGameClear::Render(void)
{
	m_BackTexture.Render(0, 0);

	//半透明にしていく
	g_pGraphics->SetBlending(BLEND_NORMAL);
	m_UITexture.Render(370, 2, MOF_ARGB(gAlpha, 255, 255, 255));

	// チャートを描画
	drawChart(PointsStatus, MOF_COLOR_RED);
	drawChart(MemoryPoints1, MOF_COLOR_BLACK);
	drawChart(MemoryPoints2, MOF_COLOR_BLACK);

	//座標取得
	Vector2 center(CHART_CENTER_X, CHART_CENTER_Y);
	Vector2 point1(point1x, point1y);
	Vector2 point2(point2x, point2y);
	Vector2 point3(point3x, point3y);
	Vector2 point4(point4x, point4y);
	Vector2 point5(point5x, point5y);

	//三角形を描いてグラフを塗りつぶす
	CGraphicsUtilities::RenderFillTriangle(center, point1, point2, MOF_COLOR_BLUE, MOF_COLOR_BLUE, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderFillTriangle(center, point2, point3, MOF_COLOR_BLUE, MOF_COLOR_BLUE, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderFillTriangle(center, point3, point4, MOF_COLOR_BLUE, MOF_COLOR_BLUE, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderFillTriangle(center, point4, point5, MOF_COLOR_BLUE, MOF_COLOR_BLUE, MOF_COLOR_BLUE);
	CGraphicsUtilities::RenderFillTriangle(center, point5, point1, MOF_COLOR_BLUE, MOF_COLOR_BLUE, MOF_COLOR_BLUE);




}

void CGameClear::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "ゲームクリア画面");
	CGraphicsUtilities::RenderString(10, 40, "エンターでモードセレクト");
	CGraphicsUtilities::RenderString(10, 70, "F1でタイトル");

	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "%d", gAlpha);

	//中心点
	CGraphicsUtilities::RenderFillCircle(CHART_CENTER_X, CHART_CENTER_Y, 2, MOF_COLOR_YELLOW);

	//円の描画
	CGraphicsUtilities::RenderCircle(CHART_CENTER_X,
		CHART_CENTER_Y,
		CHART_SIZE,
		MOF_COLOR_BLACK);

	for (int i = 0; i < ITEM_NUM; i++)
	{
		CGraphicsUtilities::RenderString(0, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].x);
		CGraphicsUtilities::RenderString(150, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].y);
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
	m_BackTexture.Release();
	m_UITexture.Release();
}

#pragma once
#include "Mof.h"
#include "SceneBase.h"

#define CHART_SIZE 248			// チャート半径
#define CHART_CENTER_X 325	    // チャート中心座標 X
#define CHART_CENTER_Y 478	    // チャート中心座標 Y

#define MAX_STATUS 100			// ステータス最大値
#define ITEM_NUM 5				// ステータス個数

class CGameClear:public CSceneBase
{
private:
	CTexture	m_BackTexture;
	CTexture	m_UITexture;

	int gAlpha = 0;
	bool isStop = false;

	// ステータスを収納する配列
	int Status[ITEM_NUM];

	//グラフ描画用配列
	int StatusRender[ITEM_NUM];


	// ステータス用チャートのポリゴン座標を収納する配列
	Vector2 PointsStatus[ITEM_NUM];

	//グラフメモリ用配列
	int Memory1[ITEM_NUM];
	// ステータス用チャートのポリゴン座標を収納する配列
	Vector2 MemoryPoints1[ITEM_NUM];

	//グラフメモリ用配列
	int Memory2[ITEM_NUM];
	// ステータス用チャートのポリゴン座標を収納する配列
	Vector2 MemoryPoints2[ITEM_NUM];

	char* StatusName[ITEM_NUM] = { "1魅力:%d","2行動力:%d","3学力:%d","4想像力:%d","5コミュ力:%d" };

public:
	CGameClear();
	~CGameClear();
	void Initialize(void);
	void buildChart(int* Status, Vector2* PointsStatus);
	void drawChart(Vector2* PointsStatus, MofU32 cl);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};


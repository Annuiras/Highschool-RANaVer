#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "RandomValue.h"


class CGameClear:public CSceneBase
{
private:

	//乱数生成
	RandomValue RandmuBak;

	//背景
	CTexture	m_BackTexture[15];

	//グラフ塗りつぶしカラー
	MofU32 Chartcol[15] =
	{
		MOF_XRGB(250, 157, 185),
		MOF_XRGB(255, 232, 87),
		MOF_XRGB(233, 255, 111),
		MOF_XRGB(210, 54, 43),
		MOF_XRGB(69, 101, 87),
		MOF_XRGB(106,106, 106),
		MOF_XRGB(248, 54, 141),
		MOF_XRGB(255, 156, 123),
		MOF_XRGB(255, 232, 87),
		MOF_XRGB(53, 78, 177),
		MOF_XRGB(255, 89, 0),
		MOF_XRGB(255, 123, 41),
		MOF_XRGB(80, 132, 93),
		MOF_XRGB(95, 59, 116),
		MOF_XRGB(255, 209, 46)
	};

	//文字テクスチャ
	CTexture	m_UITexture;


	//ステータスから最終容姿を判定する
	void StatusJudgement(void);


	//文字用アルファ値
	int gAlpha;
	//文字用フラグ
	bool isStop = false;

	//フェードイン用アルファ値
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	// ステータスを収納する配列
	int Status[DP_COUNT];

	//同数のステータスを保存
	int StatusSame[DP_COUNT];

	//グラフ描画用配列
	int StatusRender[ITEM_NUM];

	//最終容姿番号
	int LastDetailNo;

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

	char* StatusName[ITEM_NUM] = { "1学力:%d","2行動力:%d","3想像力:%d","4コミュ力:%d","5魅力:%d" };

public:
	CGameClear();
	~CGameClear();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void buildChart(int* Status, Vector2* PointsStatus);
	void drawChart(Vector2* PointsStatus, MofU32 cl);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};


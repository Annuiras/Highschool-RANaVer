#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "RandomValue.h"

//制作者：松浦 未羽 、田中 環

//ゲームクリア画面
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
		MOF_ARGB(200,201, 168, 212),	//姉御
		MOF_ARGB(200,251, 232, 124),	//人気者
		MOF_ARGB(200,233, 255, 111),	//ギャル
		MOF_ARGB(200,210, 54, 43),		//応援団長
		MOF_ARGB(200,69, 101, 87),		//図書室の長
		MOF_ARGB(200,53, 78, 177),		//オタク
		MOF_ARGB(200,248, 54, 141),		//インフルエンサー
		MOF_ARGB(200,255, 156, 123),	//委員長
		MOF_ARGB(200,210, 60, 83),		//高嶺の花
		MOF_ARGB(200,106,106, 106),		//ヤンキー
		MOF_ARGB(200,255, 89, 0),		//スーパーレディ
		MOF_ARGB(200,255, 123, 41),		//お調子者
		MOF_ARGB(200,80, 132, 93),		//文学少女
		MOF_ARGB(200,95, 59, 116),		//中二病
		MOF_ARGB(200,255, 209, 46)		//神対応	
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

	//時間計測
	int m_StartCount = 0;
	int m_StartTime = 0;


	// ステータスを収納する配列
	float Status[DP_COUNT];

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

	//デバック用文章
	char* StatusName[ITEM_NUM] = { "1学力:%f","2行動力:%f","3想像力:%f","4コミュ力:%f","5魅力:%f" };


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


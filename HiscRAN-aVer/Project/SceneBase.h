#pragma once
#include	"Define.h"
#include	"GameProgMgmt.h"
#include "MusicManager.h"
#include "EffectManager.h"
#include	"Load.h"


class CSceneBase {
protected:

	//シーン終了フラグ
	//true:終了
	bool		m_bEnd;

	//現在のシーン
	tag_SCENENO m_NowScene;

	//次のシーン
	tag_SCENENO		m_NextScene;

	//マネージャーポインタ
	CGameProgMgmt* m_GameProgMamt;
	CMusicMgmt* g_MusicManager;
	CEffectMgmt* g_EffectManeger;

	//ロード画面クラス
	CLoad* m_LoadMamt;

	//推移フラグ
	tag_SceneSituation b_Fadein;

	//ロード状況
	tag_LoadSituation b_LoadSitu;


public:
	CSceneBase() :

		m_GameProgMamt(),
		g_MusicManager(),
		g_EffectManeger(),
		m_LoadMamt(),
		b_Fadein(),
		b_LoadSitu(LOAD_YET),
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE),
		m_NowScene(SCENENO_TITLE)
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize(CGameProgMgmt* mamt,CMusicMgmt* musi, 
							CEffectMgmt* effec,CLoad* loma) = 0;
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderDebug() = 0;
	virtual void Release() = 0;


	//次のシーン取得
	int GetNextScene(void) { return m_NextScene; }

	//終了フラグ取得
	bool IsEnd(void) { return m_bEnd; }

	//現在のシーン取得
	int IsNow(void) { return m_NowScene; }

	//子クラス以外からシーン遷移
	void SetEnd(bool b) { m_bEnd = b; }
	void SetNextScene(tag_SCENENO i) { m_NextScene = i; }

	//ロード状況セット
	void SetLoadSitu(tag_LoadSituation l) { b_LoadSitu = l; }
	//ロード状況取得
	tag_LoadSituation GetLoadSitu(void) { return b_LoadSitu; }

	//フェードイン処理
	float FadeIn(float A);

	//フェードアウト処理
	float FadeOut(float A);

};
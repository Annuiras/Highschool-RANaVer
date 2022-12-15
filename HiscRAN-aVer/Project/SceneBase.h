#pragma once
#include	"Define.h"
#include	"GameProgMgmt.h"
#include "MusicManager.h"
#include "EffectManager.h"
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

public:
	CSceneBase() :
		m_GameProgMamt(),
		g_MusicManager(),
		g_EffectManeger(),
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE),
		m_NowScene()
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize(CGameProgMgmt* mamt,CMusicMgmt* musi, CEffectMgmt* effec) = 0;
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
	
};
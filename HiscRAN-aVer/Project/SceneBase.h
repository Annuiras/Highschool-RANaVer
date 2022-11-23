#pragma once
#include	"Define.h"
#include	"GameProgMgmt.h"
#include "MusicManager.h"
#include "EffectManager.h"
class CSceneBase {
protected:
	bool		m_bEnd;
	tag_SCENENO		m_NextScene;
	CGameProgMgmt* m_GameProgMamt;
	CMusicMgmt* g_MusicManager;
	CEffectMgmt* g_EffectManeger;

public:
	CSceneBase() :
		m_GameProgMamt(),
		g_MusicManager(),
		g_EffectManeger(),
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE)
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize(CGameProgMgmt* mamt,CMusicMgmt* musi, CEffectMgmt* effec) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderDebug() = 0;
	virtual void Release() = 0;

	int GetNextScene(void) { return m_NextScene; }
	bool IsEnd(void) { return m_bEnd; }
};
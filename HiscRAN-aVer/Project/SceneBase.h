#pragma once
#include	"Define.h"
class CSceneBase {
protected:
	bool		m_bEnd;
	tag_SCENENO		m_NextScene;

public:
	CSceneBase() :
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE)
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderDebug() = 0;
	virtual void Release() = 0;

	int GetNextScene(void) { return m_NextScene; }
	bool IsEnd(void) { return m_bEnd; }
};
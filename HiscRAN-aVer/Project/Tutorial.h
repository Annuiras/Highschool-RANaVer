#pragma once
#include "Define.h"
#include "SceneBase.h"

class CTutorial:public CSceneBase
{
private:
	CTexture Texture;
	CTexture ScreenTexture;
	CTexture BGTexture;
	CTexture BackButton;
	CTexture ButtonSelect;

	int m_Scroll = 0;
	int gPosX = 0;
	int count = 0;
	int MoveX = 0;
	bool bShow = false;

public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};


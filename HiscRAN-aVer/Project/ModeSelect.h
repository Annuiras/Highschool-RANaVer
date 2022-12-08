#pragma once

#include "SceneBase.h"
#include	"Menu.h"
#include "Define.h"

//スクロール速度
#define		SCROLL_SPEED	1;

class CModeSelect :public CSceneBase
{
private:
	CTexture		m_TutorialTextTexture;
	CTexture		m_Illustrat;
	float			m_Scroll;
	CMenu			gMenu;
	bool			Menuflag = false;
	int				gMenuItemCount = 2;


public:
	CModeSelect();
	~CModeSelect();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);

};


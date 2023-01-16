#pragma once

//制作者：松浦 未羽 、田中 環

#include "SceneBase.h"
#include	"Menu.h"
#include "Define.h"
#include <thread>
using namespace std;


//スクロール速度
#define		SCROLL_SPEED	1;

class CModeSelect :public CSceneBase
{
private:

	//素材ロードスレッド
	thread Thread_Load;

	CTexture		m_TutorialTextureSmall;
	CTexture		m_TutorialTextureBig;
	CTexture		m_TutorialBG[4];
	CTexture		m_TutorialTextBox;
	CTexture		m_TutorialTextTexture;
	float			m_Scroll;

	int m_BakAlph;

public:
	CModeSelect();
	~CModeSelect();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effecs, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);

};


#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "Define.h"
#include "GameApp.h"
#include "Player.h"
#include "Stage.h"


class CGAME :public CSceneBase
{

private:
	CMenu			gMenu;
	bool			Menuflag = false;
	int				gMenuItemCount = 2;

	//プレイヤークラス
	CPlayer g_Player;

	//ステージクラス
	CStage g_Stage;


	bool Clearflag = false;
	bool GameOverflag = false;



public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);


};


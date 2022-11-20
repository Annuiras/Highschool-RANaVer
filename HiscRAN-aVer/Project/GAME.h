#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "MusicManager.h"
#include "EffectManager.h"
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

	//エフェクトマネージャー
	CEffectManager g_EffectManeger;

	//SE・BGMマネージャー
	CMusicManager g_MusicManager;

	//プレイヤークラス
	CPlayer g_Player;

	//ステージクラス
	CStage g_Stage;


	bool Clearflag = false;
	bool GameOverflag = false;



public:
	CGAME();
	~CGAME();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);


};


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

	bool Collosopn(CRectangle r1, CRectangle r2);
	//ゲーム開始時のカウントダウンテクスチャ　仮素材
	CTexture	gStartThreeTexture;
	CTexture	gStartTwoTexture;
	CTexture	gStartOneTexture;
	CTexture	gStartGoTexture;

	//ゲーム開始時のカウントダウン
	DWORD	gStartTime;
	int gStartCount = 0;

	//ToDo	フェードインフェードアウト用
	int m_Alpha;

	//デバッグ用
	bool _GameOver;

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


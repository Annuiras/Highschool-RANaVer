#pragma once
#include "GAME.h"
#include "GameApp.h"
#include "Player.h"
#include "Stage.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
#include "StageA_DP.h"
#include "StageA_Bar.h"
#include "StageA_Obstacle.h"


//変更するシーン（外部参照。実態はGameApp.cpp）
extern int			gChangeScene;

//プレイヤークラス
CPlayer g_Plater;

//ステージクラス
CStage g_Stage;

GAME::GAME() {}

GAME::~GAME()
{

}

void GAME::Load(void)
{
	g_Plater.Load();
	g_Stage.Load();
}

//初期化
void GAME::Initialize(void)
{
	g_Plater.Initialize();

	g_Stage.Initialize(s_stageAdp, s_stageAdpcount, s_stageAbar, s_stageAbarcount, s_stageAob, s_stageAobcount);
}

//更新
void GAME::Update(void)
{

	g_Stage.Update(g_Plater.GetOver(),g_Plater.GetRect());

	g_Plater.Update();

	
	//一時的なコメントアウトです
	////F1でTitle画面へ
	//if (g_pInput->IsKeyPush(MOFKEY_F1))
	//{
	//	gChangeScene = SCENENO_TITLE;
	//}
	////エンターキーでモードセレクト画面へ
	//else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	//{
	//	gChangeScene = SCENENO_SELECTMODE;
	//}

	//一時的な追加です
	//Pキーでフルスクリーンに切り替え
	if (g_pInput->IsKeyPush(MOFKEY_P)) {
		g_pGraphics->ChangeScreenMode();
	}


}

void GAME::Render(void)
{

	g_Stage.Render();


	//CGraphicsUtilities::RenderString(10, 10, "ゲーム画面");
	//CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	//CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	g_Plater.Render();


	g_Stage.DebuggingRender();
}


void GAME::Release(void)
{
	g_Plater.Release();

	g_Stage.Release();
}

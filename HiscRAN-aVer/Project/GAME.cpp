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
CPlayer g_Player;

//ステージクラス
CStage g_Stage;

GAME::GAME() {}

GAME::~GAME()
{

}

void GAME::Load(void)
{
	g_Player.Load();
	g_Stage.Load();
}

//初期化
void GAME::Initialize(void)
{
	g_Player.Initialize();

	g_Stage.Initialize(s_stageAdp, s_stageAdpcount, s_stageAbar, s_stageAbarcount, s_stageAob, s_stageAobcount);
}

//更新
void GAME::Update(void)
{

	//ゲーム開始切り替え
	if (g_pInput->IsKeyPush(MOFKEY_RETURN)&&!g_Stage.GetClear())
	{
		g_Player.GameStopPlayChange();
	}

	//ステージ更新
	g_Stage.Update(g_Player.GetOver(),g_Player.GetRect());


	//プレイヤー更新
	g_Player.Update();

	//ステージクリアかつ開始状態の時実行
	if (g_Stage.GetClear()&&g_Player.GetGameStopPlay()) {

		g_Player.GameStopPlayChange();

	}

	//地面との当たり判定
	if (g_Player.CollosopnGround(g_Stage.g_ground.GetPosY())) {

		g_Player.UPdateCollisionGround(g_Stage.g_ground.GetPosY());
	}

	//足場との当たり判定
	for (int i = 0; i < BAR_MAX; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnBar(g_Stage.b_bar[i].GetRect())) {

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//障害物との当たり判定
	for (int i = 0; i < OB_VOLUME; i++)
	{
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnOB(g_Stage.ob_array[i].GetRect())) {

			g_Player.UPdateCollisionOB();
		}
	}
	
	//F2でTitle画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		gChangeScene = SCENENO_TITLE;
	}
	//エンターキーでモードセレクト画面へ
	else if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}

	//一時的な追加です
	//Pキーでフルスクリーンに切り替え
	if (g_pInput->IsKeyPush(MOFKEY_P)) {
		g_pGraphics->ChangeScreenMode();
	}

	//一時的な追加です
	//リスタート
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//初期化
		g_Player.Initialize();

		g_Stage.Initialize(s_stageAdp, s_stageAdpcount, s_stageAbar, s_stageAbarcount, s_stageAob, s_stageAobcount);

	}

}

void GAME::Render(void)
{

	g_Stage.Render();


	//CGraphicsUtilities::RenderString(10, 10, "ゲーム画面");
	//CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	//CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	g_Player.Render();

	
	g_Stage.DebuggingRender();
	g_Player.DebuggingRender();
}


void GAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();
}

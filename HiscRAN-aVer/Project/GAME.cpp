#pragma once
#include "GAME.h"
#include "StageA_DP.h"
#include "StageA_Bar.h"
#include "StageA_Obstacle.h"



CGAME::CGAME() {}

CGAME::~CGAME()
{

}

//素材読み込み
void CGAME::Load(void)
{
	g_Player.Load();
	g_Stage.Load();
	g_MusicManager.Load();
	g_EffectManeger.Load();
}

//初期化
void CGAME::Initialize(void)
{
	//素材読み込み
	Load();

	gMenu.Create(gMenuItemCount);

	//マネージャー初期化
	g_MusicManager.Initialize();
	g_EffectManeger.Initialize();

	//プレイヤー初期化
	g_Player.Initialize();
	g_Player.SetMusicManager(&g_MusicManager);
	g_Player.SetEffectManager(&g_EffectManeger);

	//ステージ初期化
	g_Stage.Initialize(s_stageAdp,s_stageAbar, s_stageAOB);
	g_Stage.SetMusicManager(&g_MusicManager);
	g_Stage.SetEffectManager(&g_EffectManeger);
}

//更新
void CGAME::Update(void)
{

	//ゲーム開始切り替え
	if (g_pInput->IsKeyPush(MOFKEY_RETURN)&&!g_Stage.GetClear()&&!Menuflag)
	{
		g_Stage.GameStopPlayChange();
	}

	//一時的な追加です
	//F2でTitle画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//一時的な追加です
	//エンターキーでモードセレクト画面へ
	else if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_F3))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//一時的な追加です
	//Pキーでフルスクリーンに切り替え
	if (g_pInput->IsKeyPush(MOFKEY_P)) {
		g_pGraphics->ChangeScreenMode();
	}

	//一時的な追加です
	//デバッグ表示非表示切り替え
	if (g_pInput->IsKeyPush(MOFKEY_9)) {
		if (Debuggingflg) {
			Debuggingflg = false;
		}
		else
		{
			Debuggingflg = true;
		}
	}

	//Cでゲームクリア画面へ
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMECLEAR;
	}

	//Vでゲームオーバー画面
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMEOVER;
	}

	//一時的な追加です
	//リスタート
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//初期化
		g_Player.Initialize();

		g_Stage.Initialize(s_stageAdp, s_stageAbar, s_stageAOB);

	}

	//メニューの更新
	if (gMenu.IsShow())
	{
		gMenu.Update();
		if (gMenu.IsEnter())
		{
			if (gMenu.GetSelect() == 0)
			{
				m_bEnd = true;
				m_NextScene = SCENENO_SELECTMODE;

				//gChangeScene = SCENENO_SELECTMODE;
			}
			gMenu.Hide();
		}
	}
	//エスケープキーで終了メニューを表示
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//プレイ中であれば停止
		if (g_Stage.GetGameStopPlay())
			g_Stage.GameStopPlayChange();

		Menuflag = true;
		gMenu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else
	{
		Menuflag = false;
	}


	//ストップ中はゲーム処理を実行しない
	if (!g_Stage.GetGameStopPlay()) {

		return;
	}


	//ステージ更新
	g_Stage.Update(g_Player.GetRect());

	//プレイヤー更新
	g_Player.Update();

	//ステージクリアかつ開始状態の時実行
	if (g_Stage.GetClear()&& g_Stage.GetGameStopPlay()) {

		g_Stage.GameStopPlayChange();

	}

	//地面との当たり判定
	if (g_Player.CollosopnGround(g_Stage.g_ground.GetRect())) {

		g_Player.UPdateCollisionGround(g_Stage.g_ground.GetPosY());
	}

	//足場との当たり判定
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnBar(g_Stage.b_bar[i].GetRect(g_Stage.b_bar[i].Gettype()))) {

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//障害物との当たり判定
	for (int i = 0; i < OB_VOLUME; i++)
	{
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		//判定
		if (g_Player.CollosopnOB(g_Stage.ob_array[i].GetRect(g_Stage.ob_array[i].GetType())))
		{
 			g_Player.UPdateCollisionOB();
		}
		//障害物からのダメージを受けていない場合だけ上の足場判定
		else if(g_Player.CollosopnBar(g_Stage.ob_array[i].GetTopBarRect(g_Stage.ob_array[i].GetType())))
		{
			g_Player.UPdateCollisionBra(g_Stage.ob_array[i].GetY(g_Stage.ob_array[i].GetType()));
		}
	}

	//エフェクトの更新
	g_EffectManeger.Update();

	//一時的な追加です
	//F2でTitle画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

}

void CGAME::Render(void)
{

	//ステージ描画
	g_Stage.Render();

	//プレイヤー描画
	g_Player.Render();

	//メニューの描画
	gMenu.Render(2);

	//エフェクトの描画
	g_EffectManeger.Render();

	//デバッグ描画
	if (Debuggingflg) {
		g_Stage.RenderDebugging();
		g_Player.RenderDebugging();
	}

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	g_EffectManeger.Release();
	g_MusicManager.Release();

	gMenu.Release();

}

void CGAME::RenderDebug(void)
{

}
	

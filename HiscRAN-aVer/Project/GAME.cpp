#pragma once
#include "GAME.h"
#include "Stage_DP.h"
#include "Stage_Bar.h"
#include "Stage_Obstacle.h"



CGAME::CGAME() {}

CGAME::~CGAME()
{

}

//素材読み込み
void CGAME::Load(void)
{

	//g_MusicManager.Load();
	//g_EffectManeger.Load();
	g_Player.Load();
	g_Stage.Load();

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game");

	//カウントダウン画像の読み込み
	gStartThreeTexture.Load("CountdownThree.png");
	gStartTwoTexture.Load("CountdownTwo.png");
	gStartOneTexture.Load("CountdownOne.png");
	gStartGoTexture.Load("CountdownGo.png");

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

}

//初期化
//引数：ゲーム進捗管理クラス
void CGAME::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	//素材読み込み
	Load();

	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//メニュー
	gMenu.Create(gMenuItemCount);

	//マネージャー初期化
 //	g_MusicManager.Initialize(m_GameProgMamt->GetSEVolume(),m_GameProgMamt->GetBGMVolume());
	//g_EffectManeger.Initialize();

	//プレイヤー初期化
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//ステージ初期化
	g_Stage.Initialize(s_stageAdp,s_stageAbar, s_stageAOB);
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);
}

//更新
void CGAME::Update(void)
{

	//ゲーム開始切り替え
	//ToDo　開始時にカウントダウン開始
	if (g_pInput->IsKeyPush(MOFKEY_RETURN) && !g_Stage.GetClear())
	{
		gStartTime = timeGetTime();
	}
	if (timeGetTime() - gStartTime > 1000 && gStartCount < 5) {
		gStartTime = timeGetTime();
		gStartCount++;
		if (gStartCount == 4) {
			g_Stage.GameStopPlayChange();
		}
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
	g_EffectManeger->Update(g_Player.GetRect());


}

void CGAME::Render(void)
{

	//ステージ描画
	g_Stage.Render();

	//プレイヤー描画
	g_Player.Render();

	//メニューの描画
	gMenu.Render(2);

	//ToDo　ゲーム開始時のカウントダウンの表示
	if (gStartCount == 1) {
		gStartThreeTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartThreeTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartThreeTexture.GetHeight() / 2);
	}
	else if (gStartCount == 2) {
		gStartTwoTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartTwoTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartTwoTexture.GetHeight() / 2);
	}
	else if (gStartCount == 3) {
		gStartOneTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartOneTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartOneTexture.GetHeight() / 2);
	}
	else if (gStartCount == 4) {
		gStartGoTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartGoTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartGoTexture.GetHeight() / 2);
	}

	//エフェクトの描画
	g_EffectManeger->Render();

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	gMenu.Release();

	//ToDo	カウントダウン画像の開放
	gStartThreeTexture.Release();
	gStartTwoTexture.Release();
	gStartOneTexture.Release();
	gStartGoTexture.Release();

}

void CGAME::RenderDebug(void)
{
	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();
}
	

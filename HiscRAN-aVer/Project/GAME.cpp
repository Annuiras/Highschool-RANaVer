#pragma once
#include "GAME.h"



//DPと当たった場合
//dpt->DPの種類
void CGAME::UPdeteCollisionDP(int dpt) {

	g_MusicManager->SEStart(SE_T_DP_HIT);

	m_DPNum[dpt]++;

	switch (dpt)
	{
		//学力
	case DP_SCHOLASTIC:
		//エフェクト再生
		g_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		break;

		//行動力
	case DP_ACTION:
		//エフェクト再生
		g_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		break;

		//想像力
	case DP_IMAGINATION:
		//エフェクト再生
		g_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		break;

		//コミュ力
	case DP_COMMUNICATION:
		//エフェクト再生
		g_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		break;

		//魅力
	case DP_CHARM:
		//エフェクト再生
		g_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		break;
	default:
		break;
	}
}

CGAME::CGAME():
	m_Menu(),
	m_MenuItemCount(),
	m_StartCount(),
	m_BlackAlpha(),
	m_WhiteAlpha(),
	_GameOver(),
	_GameClear(),
	m_StartTime(),
	m_DPNum()
{}

CGAME::~CGAME()
{

}

//素材読み込み
void CGAME::Load(void)
{
	g_Player.Load();
	g_Stage.Load();

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game");

	//カウントダウン画像の読み込み
	m_StartThreeTexture.Load("ハイスク　カウントダウンロゴ無し　３.png");
	m_StartTwoTexture.Load("ハイスク　カウントダウンロゴ無し　２.png");
	m_StartOneTexture.Load("ハイスク　カウントダウンロゴ無し　１.png");
	m_StartGoTexture.Load("CountdownGo.png");

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
	m_Menu.Create(m_MenuItemCount);

	//プレイヤー初期化
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//ステージ初期化
	g_Stage.Initialize();
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);

	//カウントダウン用カウンタ初期化
	m_StartCount = 0;

	//ゲームオーバ時のフェードインフェードアウト用
	m_BlackAlpha = 0;
	m_WhiteAlpha = 0;

	//デバッグ用
	_GameClear = false;
	_GameOver = false;

	//ステージ内で取得したDPの数初期化
	for (int i = 0; i < DP_COUNT; i++)
	{
		m_DPNum[i] = 0;
	}
	m_StartScale = 0.0f;

	//BGM開始
	g_MusicManager->BGMStart(BGMT_STAGE);

	m_NowScene = SCENENO_GAME;


}

//更新
void CGAME::Update(void)
{

	//ゲーム開始切り替え
	//開始時にカウントダウン開始
	if (g_pInput->IsKeyPush(MOFKEY_RETURN) && !g_Stage.GetClear())
	{
		//開始時刻
		m_StartTime = timeGetTime();
	}

	//カウントダウン判定
	if (m_StartCount < 5&&timeGetTime() - m_StartTime > 1000) {
		//開始時刻
		m_StartTime = timeGetTime();
		//カウント増加
		m_StartCount++;

		//ズームインリセット
		m_StartScale = 0.0f;

		
		if (m_StartCount == 4) {
			//ゲーム開始
			g_Stage.GameStopPlayChange();
		}
	}

	//ズームイン数値更新　1.0f最大画像サイズ　0.0f最小画像サイズ
	if (m_StartCount < 5) {
		m_StartScale += 0.08f;
		if (m_StartScale >= 1.0f) {
			m_StartScale = 1.0f;
		}
	}

	//一時的な追加です
	//ゲーム一時停止
	if (g_pInput->IsKeyPush(MOFKEY_0)) {
		g_Stage.GameStopPlayChange();

	}

	//Cでゲームクリア画面へ
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		_GameClear = true;
	}

	//Vでゲームオーバー画面
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		_GameOver = true;
	}

	//一時的な追加です
	//リスタート
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//初期化
		g_Player.Initialize();

		g_Stage.Initialize();

	}

	if (g_pInput->IsKeyPush(MOFKEY_1)) {
		//DPと接触した場合
		UPdeteCollisionDP(DP_SCHOLASTIC);
	}
	if (g_pInput->IsKeyPush(MOFKEY_2)) {
		//DPと接触した場合
		UPdeteCollisionDP(DP_ACTION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_3)) {
		//DPと接触した場合
		UPdeteCollisionDP(DP_IMAGINATION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_4)) {
		//DPと接触した場合
		UPdeteCollisionDP(DP_COMMUNICATION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_5)) {
		//DPと接触した場合
		UPdeteCollisionDP(DP_CHARM);
	}


	//メニューの更新
	if (m_Menu.IsShow())
	{
		//カウントダウンを停止するため
		m_StartTime = timeGetTime();

		m_Menu.Update();
		if (m_Menu.IsEnter())
		{
			//やめる
			if (m_Menu.GetSelect() == 0)
			{
				//モードセレクトへ
				m_bEnd = true;
				m_NextScene = SCENENO_SELECTMODE;
			}
			//メニューを非表示
			m_Menu.Hide();
		}
	}
	//エスケープキーで終了メニューを表示
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//プレイ中であれば停止
		if (g_Stage.GetGameStopPlay())
			g_Stage.GameStopPlayChange();

		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}


	//ゲームオーバー時の場合フェードアウト
	if (g_Player.GetOver()||_GameOver) {

		//フェードアウト
		m_BlackAlpha += FADE_OUT_SPEED;

		if (m_BlackAlpha >= 255) {
			//SEをすべて停止
			g_MusicManager->SEALLStop();

			//SE再生
			g_MusicManager->SEStart(SE_T_GAMEOVER);

			//ゲームオーバー画面へ
			m_bEnd = true;
			m_NextScene = SCENENO_GAMEOVER;
		}
	}

	//ストップ中,ゲームオーバー中は以下の処理を実行しない
	if (!g_Stage.GetGameStopPlay()||g_Player.GetOver()||_GameOver) {
		return;
	}

	//クリア時の処理
	if (g_Stage.GetClear()|| _GameClear)
	{
		m_WhiteAlpha += 1;//明転

		//クリア時のキャラクター処理
		g_Player.UpdateClear();

		if (m_WhiteAlpha >= 255)
		{
			//SEをすべて停止
			g_MusicManager->SEALLStop();

			//DPの取得数を保存
			m_GameProgMamt->SetGame_DPNum(m_DPNum);

			//画面切り替え
			m_bEnd = true;
			m_NextScene = SCENENO_GAMECLEAR;
		}
	}

	if (g_Stage.GetClear()||_GameClear) {
		//エフェクトの更新
		g_EffectManeger->Update(g_Player.GetRect());

		//クリア時は以下の処理をしない
		return;
	}

	//プレイヤー更新
	g_Player.Update();

	//ステージ更新
	g_Stage.Update(g_Player.GetRect());	

	//足場との当たり判定
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.GetLegsRect().CollisionRect((g_Stage.b_bar[i].GetRect()))){

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//障害物との当たり判定
	for (int i = 0; i < OB_VOLUME; i++)
	{
		//非表示のものは判定しない
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		//プレイヤーと判定
		if (g_Stage.ob_array[i].GetRect().CollisionRect(g_Player.GetRect()))
		{
 			g_Player.UPdateCollisionOB();
		}
		//障害物からのダメージを受けていない場合だけ上の足場判定
		else if(g_Player.GetLegsRect().CollisionRect(g_Stage.ob_array[i].GetTopBarRect()))
		{
			g_Player.UPdateCollisionBra(g_Stage.ob_array[i].GetY());
		}

		//敵
		for (int e = 0; e < ENEMY_VOLUME; e++)
		{
			if (!g_Stage.ene_array[e].Getshow())
				continue;

			if (g_Stage.ene_array[e].GetRect().CollisionRect(g_Stage.ob_array[i].GetTopBarRect())) {
				g_Stage.ene_array[e].SetPosY(g_Stage.ob_array[i].GetY());
			}
		}
	}

	//敵との当たり判定
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		//非表示のものは判定しない
		if (!g_Stage.ene_array[i].Getshow()) {
			continue;
		}
		//プレイヤーと敵の当たり判定
		if (g_Player.GetRect().CollisionRect(g_Stage.ene_array[i].GetRect()))
		{
			g_Player.UPdateCollisionOB();
		}
	}

	//DPとの当たり判定
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//非表示の場合は判定しない
		if (!g_Stage.dp_array[i].Getshow()) {
			continue;
		}

		if (g_Player.GetRect().CollisionRect(g_Stage.dp_array[i].GetRect())) {
			//DPと接触した場合
			UPdeteCollisionDP(g_Stage.dp_array[i].Gettype());
			g_Stage.dp_array[i].Setshow(false);
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
	m_Menu.Render(2);

	//ゲーム開始時のカウントダウンの表示
	//画面中央に配置
	if (m_StartCount == 1) {
		m_StartThreeTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartThreeTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartThreeTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 2) {
		m_StartTwoTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartTwoTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartTwoTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 3) {
		m_StartOneTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartOneTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartOneTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 4) {
		m_StartGoTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartGoTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartGoTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}


	//エフェクトの描画
	g_EffectManeger->Render();

	//フェードアウト明転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteAlpha, 255, 255, 255));

	//フェードアウト暗転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),MOF_ARGB(m_BlackAlpha,0,0,0));

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	m_Menu.Release();

	//カウントダウン画像の開放
	m_StartThreeTexture.Release();
	m_StartTwoTexture.Release();
	m_StartOneTexture.Release();
	m_StartGoTexture.Release();

	//BGM停止
	g_MusicManager->BGMStop(BGMT_STAGE);

}

void CGAME::RenderDebug(void)
{
	for (int i = 0; i < DP_COUNT; i++)
	{
		CGraphicsUtilities::RenderString(200 + i * 30, 0, MOF_COLOR_BLACK,"%d", m_DPNum[i]);
	}

	//FPS表示
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "FPS：%d", CUtilities::GetFPS());

	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();
}
	

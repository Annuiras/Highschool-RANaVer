//////////////////////////////////////////////
//	ゲーム管理のプログラムです　　　　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "GAME.h"


CGAME::CGAME():
	m_StartCount(),
	m_GameOverflg(),
	m_GameClearflg(),
	m_StartTime(),
	m_DPDeci(),
	m_DPNum(),
	m_SP_DPNum(),
	m_ClearTexture(),
	m_ClearScale(),
	m_BlackBakAlph(),
	m_StartScale(),
	m_WhiteBakAlph()
{}

CGAME::~CGAME()
{

}


void CGAME::UpdateDebug(void)
{

	//一時的な追加です
	//ゲーム一時停止
	if (g_pInput->IsKeyPush(MOFKEY_0)) {
		g_Stage.GameStopPlayChange();

	}

	//Cでゲームクリア画面
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		m_GameClearflg = true;
	}

	//Vでゲームオーバー画面
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		m_GameOverflg = true;
	}

	//一時的な追加です
	//リスタート
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//初期化
		Initialize(b_GameProgMamt, b_MusicManager, b_EffectManeger, b_MenuMamt);
	}

	//デバッグ用
	if (g_pInput->IsKeyPush(MOFKEY_1)) {
		//DP
		UPdeteCollisionDP(DP_SCHOLASTIC);
	}
	if (g_pInput->IsKeyPush(MOFKEY_2)) {
		//DP
		UPdeteCollisionDP(DP_ACTION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_3)) {
		//DP
		UPdeteCollisionDP(DP_IMAGINATION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_4)) {
		//DP
		UPdeteCollisionDP(DP_COMMUNICATION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_5)) {
		//DP
		UPdeteCollisionDP(DP_CHARM);
	}

	g_Player.UpdateDebug();
	g_Stage.UpdateDebug();
}

//素材読み込み
void CGAME::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game");

	if (!g_Player.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!g_Stage.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//カウントダウン画像の読み込み
	if (!m_StartThreeTexture.Load("Countdown_3.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_StartTwoTexture.Load("Countdown_2.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_StartOneTexture.Load("Countdown_1.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_StartGoTexture.Load("Countdown_Go.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_ClearTexture.Load("GameClear.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//ロード完了
	b_LoadSitu = LOAD_COMP;

}

//初期化
//引数：ゲーム進捗管理クラス
void CGAME::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{

	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//プレイヤー初期化
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//ステージ初期化
	g_Stage.Initialize(b_GameProgMamt->GetDPdec_SPflg(),b_GameProgMamt->GetDPdec_type());
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);

	//カウントダウン用カウンタ初期化
	m_StartCount = 0;

	m_Stopflg = true;
	//状態を設定
	b_Fadein = FADE_IN;

	//DP目標をセット
	m_DPDeci = b_GameProgMamt->GetDPdec_type();

	//フェードイン用
	m_BlackBakAlph = 0;
	m_WhiteBakAlph = 255;

	//クリア、オーバーフラグ初期化
	m_GameClearflg = false;
	m_GameOverflg = false;

	//ステージ内で取得したDPの数初期化
	for (int i = 0; i < DP_COUNT; i++)
	{
		m_DPNum[i] = 0;
	}
	//SODP初期化
	m_SP_DPNum = 0;

	
	m_StartScale = 0.0f;

	//デバック用

	//現在のシーン
	m_NowScene = SCENENO_GAME;
}

//更新
void CGAME::Update(void)
{

	//ゲームオーバーフラグを受け取る
	m_GameOverflg = g_Player.GetOver();

	//クリアフラグを受け取る
	m_GameClearflg = g_Stage.GetClear();
	

	//ヒットストップの処理
	if (m_GameOverflg && m_Stopflg)
	{
		m_Stopflg = false;
		m_StopCount = 30;
	}
	if (m_StopCount > 0)
	{
		m_StopCount--;
		return;
	}



	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph, true);

		//フェードイン終わり次第カウント開始
		if (!g_Stage.GetClear())
		{
			//開始時刻
			m_StartTime = timeGetTime()+1000;
		}
		return;
	}

	//BGM開始
	b_MusicManager->BGMStart(BGMT_STAGE);

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		//SEをすべて停止
		b_MusicManager->SEALLStop();

		//クリア画面
		if (m_GameClearflg) {

			//DPの取得数を保存
			b_GameProgMamt->SetGame_DPNum(m_DPNum);
			b_GameProgMamt->SetGame_SP_DPNum(m_SP_DPNum);
			m_bEnd = true;
			m_NextScene = SCENENO_GAMECLEAR;

		}
		//ゲームオーバー画面
		else if(m_GameOverflg)
		{
			b_MusicManager->SEStart(SE_T_GAMEOVER);
			m_bEnd = true;
			m_NextScene = SCENENO_GAMEOVER;
		}
		//メニューからモードセレクトへ
		else
		{
			//メニューを非表示
			b_MenuMamt->Hide();
			m_bEnd = true;
			m_NextScene = SCENENO_SELECTMODE;
		}

		return;
	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {

		//クリア時
		if (m_GameClearflg) {
			//白
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true,1.0f);

			//表示倍率加算
			m_ClearScale += 0.01f;
			if (m_ClearScale >= 0.25f) {
				m_ClearScale = 0.25f;
			}

			//クリア時のキャラクター処理
			g_Player.UpdateClear();

		}
		//ゲームオーバー時
		else if(m_GameOverflg)
		{
			//黒
			m_BlackBakAlph = FadeOut(m_BlackBakAlph, true);
		}
		//メニューで戻る場合
		else
		{
			
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		}
		return;
	}

	//メニュー表示中
	if (b_MenuMamt->IsShow()) {

		//更新
		b_MenuMamt->Update();

		//選択肢
		if (b_MenuMamt->IsEnter())
		{
			//選択肢の番号によって処理
			if (b_MenuMamt->GetSelect() == 0)
			{
				//モードセレクト画面へ
				b_Fadein = FADE_OUT;
			}
			else
			{
				//メニューを非表示
				b_MenuMamt->Hide();

				//カウントダウン開始
				m_StartCount = 0;
				m_StartTime = timeGetTime() + 1000;

				//停止
				g_Stage.GameStopPlayChange();
			}
		}
		return;
	}
	else if(g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//ゲーム中断メニュー表示
		b_MenuMamt->Show(MENUT_GAME_END);

		//SE停止
		b_MusicManager->SEALLStop();
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


	//ゲームオーバー時の場合フェードアウト
	if (m_GameOverflg) {

		//ゲームオーバー原因フラグを保存(HP)
		if (g_Player.GetOver()) {
			b_GameProgMamt->SetGame_Over_HP(true);
		}

		b_Fadein = FADE_OUT;
	}

	//ゲームストップ中,ゲームオーバー中は以下の処理を実行しない
	if (!g_Stage.GetGameStopPlay()||m_GameOverflg) {
		return;
	}

	//クリア時の処理
	if (m_GameClearflg)
	{
		//フェードアウト
		b_Fadein = FADE_OUT;

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
			//非表示のものは判定しない
			if (!g_Stage.ene_array[e].Getshow())
				continue;

			if (g_Stage.ene_array[e].GetRect().CollisionRect(g_Stage.ob_array[i].GetTopBarRect())) {

				//障害物の高さに調整
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
	b_EffectManeger->Update(g_Player.GetRect());

}

//DPと当たった場合
//dpt->DPの種類
void CGAME::UPdeteCollisionDP(int dpt) {

	//SE再生
	b_MusicManager->SEStart(SE_T_DP_HIT);


	switch (dpt)
	{
		//学力
	case DP_SCHOLASTIC:

		//追加
		m_DPNum[DP_SCHOLASTIC]++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC_AROOW);
		break;

		//行動力
	case DP_ACTION:

		//追加
		m_DPNum[DP_ACTION]++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION_AROOW);
		break;

		//想像力
	case DP_IMAGINATION:

		//追加
		m_DPNum[DP_IMAGINATION]++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION_AROOW);
		break;

		//コミュ力
	case DP_COMMUNICATION:

		//追加
		m_DPNum[DP_COMMUNICATION]++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION_AROOW);
		break;

		//魅力
	case DP_CHARM:

		//追加
		m_DPNum[DP_CHARM]++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM_AROOW);
		break;

	case DP_SP_SCHOLASTIC:

		//追加
		m_SP_DPNum++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC_AROOW);
		break;

	case DP_SP_ACTION:

		//追加
		m_SP_DPNum++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION_AROOW);
		break;

	case DP_SP_IMAGINATION:

		//追加
		m_SP_DPNum++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION_AROOW);
		break;

	case DP_SP_COMMUNICATION:

		//追加
		m_SP_DPNum++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION_AROOW);
		break;

	case DP_SP_CHARM:

		//追加
		m_SP_DPNum++;

		//エフェクト再生
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM_AROOW);
		break;


	default:
		break;
	}
}

void CGAME::Render(void)
{

	//ステージ描画
	g_Stage.Render();

	//プレイヤー描画
	g_Player.Render();


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

	//クリアテキスト表示
	if (m_GameClearflg) {
		m_ClearTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_ClearTexture.GetWidth() / 2 * m_ClearScale,
			g_pGraphics->GetTargetHeight() / 2 - m_ClearTexture.GetHeight() / 2 * m_ClearScale, m_ClearScale);

	}

	//エフェクトの描画
	b_EffectManeger->Render();

	//メニューの描画
	b_MenuMamt->Render();

	//フェードアウト暗転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),MOF_ARGB(m_BlackBakAlph,0,0,0));

	//フェードアウト明転用
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	//カウントダウン画像の開放
	m_StartThreeTexture.Release();
	m_StartTwoTexture.Release();
	m_StartOneTexture.Release();
	m_StartGoTexture.Release();

	m_ClearTexture.Release();

	//BGM停止
	b_MusicManager->BGMStop(BGMT_STAGE);

}

void CGAME::RenderDebug(void)
{
	for (int i = 0; i < DP_COUNT; i++)
	{
		CGraphicsUtilities::RenderString(200 + i * 30, 0, MOF_COLOR_BLACK,"%d", m_DPNum[i]);
	}

	CGraphicsUtilities::RenderString(200, 30, MOF_COLOR_BLACK, "%d", m_SP_DPNum);
	

	//FPS表示
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "FPS：%d", CUtilities::GetFPS());

	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();

	//DP目標表示（仮）
	switch (m_DPDeci)
	{

		case 0:
			CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP目標:学力");
			break;
		case 1:
			CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP目標:行動力");
			break;

		case 2:
			CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP目標:想像力");
			break;

		case 3:
			CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP目標:コミュ力");
			break;

		case 4:
			CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP目標:魅力");
			break;

		default:
			break;
	}

}
	

/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"Define.h"
#include	"Title.h"
#include	"ModeSelect.h"
#include	"Tutorial.h"
#include	"GAME.h"
#include	"GameOver.h"
#include	"GameClear.h"
#include	"Gallery.h"
#include	"Option.h"
#include	"GameProgMgmt.h"
#include	"Menu.h"
#include	"DPDecision.h"
#include	"Load.h"

//デバッグ
bool		gDebagflag = false;

//シーンベースクラスポインタ
CSceneBase* gpScene = NULL;

//ゲーム管理クラス
CGameProgMgmt g_GameProgMamt;

//エフェクトマネージャー
CEffectMgmt g_EffectManeger;

//SE・BGMマネージャー
CMusicMgmt g_MusicManager;

//メニュークラス
CMenu		g_Menu;
int			gMenuItemCount = 2;

//ロード画面クラス
CLoad gLoad;

//エフェクト,ミュージック,メニュー,ロードフラグ
tag_LoadSituation Eff_Loadflg = LOAD_YET, Mu_Loadflg = LOAD_YET, Me_Loadflg = LOAD_YET;

//最初のシーンに必要なエフェクト、ミュージック,メニューをロード：初期化出来ているか
//true::ロード出来ている
bool LoadCheckInitial(void) {

	bool flg = true;
	if (Eff_Loadflg != LOAD_DONE|| Mu_Loadflg != LOAD_DONE|| Me_Loadflg != LOAD_DONE) {
		flg = false;
	}

	return flg;
}

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Resource");

	//最初に実行される,マネージャーの初期化 
	g_GameProgMamt.Initialize();

	//ロード画面素材
	gLoad.Load();

	//ロード画面初期化
	gLoad.Initialize(0, 100);

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//キーの更新
	g_pInput->RefreshKey();

	//デバッグ切り替え
	if(g_pInput->IsKeyPush(MOFKEY_BACKSPACE))
	gDebagflag = gDebagflag ? !gDebagflag : !gDebagflag;

	//ロード画面更新
	gLoad.Update();

	//エフェクトがロード前の場合
	if (Eff_Loadflg == LOAD_YET && !gLoad.Thread_Load.joinable()) {
		//ロード処理をスレッドに渡す
		//戻り値を記録する
		gLoad.Thread_Load = thread{ [] {Eff_Loadflg = g_EffectManeger.Load(); } };
	}
	//音声がロード前の場合
	else 
	if (Mu_Loadflg == LOAD_YET && !gLoad.Thread_Load.joinable())
	{
		//ロード処理をスレッドに渡す
		//戻り値を記録する
		gLoad.Thread_Load = thread{ [] {Mu_Loadflg=g_MusicManager.Load(); } };
	}
	else
	//メニューがロード前の場合
	if (Me_Loadflg == LOAD_YET && !gLoad.Thread_Load.joinable())
	{
		//ロード処理をスレッドに渡す
		//戻り値を記録する
		gLoad.Thread_Load = thread{ [] {Me_Loadflg = g_Menu.Load(); } };

	}

	//エフェクトがロード完了状態の場合
	if (Eff_Loadflg == LOAD_COMP) {
		//スレッド解放
		gLoad.Thread_Load.join();
		//初期化
		g_EffectManeger.Initialize();
		//フラグ更新
		Eff_Loadflg = LOAD_DONE;
	}

	//ミュージックがロード完了状態の場合
	if (Mu_Loadflg == LOAD_COMP) {
		//スレッド解放
		gLoad.Thread_Load.join();
		//初期化
		g_MusicManager.Initialize(0.2,0.2);
		//フラグ更新
		Mu_Loadflg = LOAD_DONE;
	}

	//メニューがロード完了状態の場合
	if (Me_Loadflg == LOAD_COMP) {
		//スレッド解放
		gLoad.Thread_Load.join();

		//メニューにマネージャーをセット
		g_Menu.SetEffectManager(&g_EffectManeger);
		g_Menu.SetMusicManager(&g_MusicManager);

		//フラグ更新
		Me_Loadflg = LOAD_DONE;
	}


	//エフェクト、ミュージック,メニューをロード：初期化出来ていない場合は更新終了
	if (!LoadCheckInitial()) {
		return TRUE;
	}

	//シーンをまだ生成していない場合
	//最初のシーンを生成
	if (gpScene == nullptr) {

		gpScene = new CTutorial();
		gLoad.Thread_Load = thread{ [=] {gpScene->Load(); } };
		gLoad.Initialize(0,100);
	}


	//シーンのロード完了時
	if (gpScene->GetLoadSitu() == LOAD_COMP)
	{
		//スレッド解放
		gLoad.Thread_Load.join();

		//シーンの初期化
		gpScene->Initialize(&g_GameProgMamt, &g_MusicManager, &g_EffectManeger,&g_Menu);

		//フラグ更新
		gpScene->SetLoadSitu(LOAD_DONE);
	}
	else
	//ロード前かエラー時は更新なし
	if ((gpScene->GetLoadSitu() == LOAD_YET || gpScene->GetLoadSitu() == LOAD_ERROR)||
		!gLoad.IsLoadEnd()){
		return TRUE;
	}
	
	//シーンの更新
	gpScene->Update();
	

	//画面遷移完了した場合
	if (gpScene->IsEnd()) {

		//解放
		gpScene->Release();

		//次のシーンを取得 
		int change = gpScene->GetNextScene();

		//古いシーンを消去する 
		delete gpScene;

		//次のシーン番号に応じてシーンを作って初期化する 
		switch (change)
		{
			//タイトル画面
		case SCENENO_TITLE:
			gpScene = new CTitle();
			break;

			//モードセレクト画面
		case SCENENO_SELECTMODE:
			gpScene = new CModeSelect();
			break;

			//チュートリアル画面
		case SCENENO_TUTORIAL:
			gpScene = new CTutorial();
			break;

			//DP目標設定画面
		case SCENENO_DPDECISION:
			gpScene = new CDPDecision();
			break;

			//ゲーム画面
		case SCENENO_GAME:
			gpScene = new CGAME();
			//ロードをスレッド渡す
			gLoad.Thread_Load = thread{ [=] {gpScene->Load(); } };
			//ロード画面の初期化
			gLoad.Initialize(255,100);
			break;

			//ゲームオーバー画面
		case SCENENO_GAMEOVER:
			gpScene = new CGameOver();
			break;

			//ゲームクリア画面
		case SCENENO_GAMECLEAR:
			gpScene = new CGameClear();
			break;

			//ギャラリー画面
		case SCENENO_GALLERY:
			gpScene = new CGallery();
			break;

			//オプション画面
		case SCENENO_OPTION:
			gpScene = new COption();
			break;

		}
		//初期化
		g_EffectManeger.InitializeIn_middle();

		//スレッドが動いてない場合初期化
		if (!gLoad.Thread_Load.joinable()) {
			gpScene->Initialize(&g_GameProgMamt, &g_MusicManager, &g_EffectManeger, &g_Menu);
		}

	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0);

	//描画
	//初期ロードでエラーが起きた場合
	if (Eff_Loadflg == LOAD_ERROR || Mu_Loadflg == LOAD_ERROR) {
		gLoad.RenderError();
	}
	else
	//シーン生成前
	//シーンのロード前
	//ロード画面終了前の場合
	if(gpScene == nullptr||gpScene->GetLoadSitu()== LOAD_YET||!gLoad.IsLoadEnd())
	{
		//ロード画面
		gLoad.RenderLoad();
	}
	else
	//シーンのロードでエラーが出た場合
	if (gpScene->GetLoadSitu() == LOAD_ERROR) {
		gLoad.RenderError();
	}
	else
	{
		//シーン画面
		gpScene->Render();

		if (gDebagflag)
		{
			if (gpScene != nullptr) {
				//デバッグ描画
				gpScene->RenderDebug();
			}
			else
			{
				gLoad.RenderDebug();
			}
		}

	}


	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void){


	if (gpScene != nullptr) {
		gpScene->Release();
	}
	g_EffectManeger.Release();
	g_MusicManager.Release();
	g_Menu.Release();
	gLoad.Release();

	if (gLoad.Thread_Load.joinable()) {
		gLoad.Thread_Load.detach();
	}

	return TRUE;
}
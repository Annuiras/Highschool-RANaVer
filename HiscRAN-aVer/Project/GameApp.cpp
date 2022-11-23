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


/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Resource");

	//最初に実行されるシーンの初期化 
	gpScene = new CTitle();
	g_GameProgMamt.Initialize();
	g_EffectManeger.Initialize();
	g_MusicManager.Initialize(0.5,0.5);
	gpScene->Initialize(&g_GameProgMamt,&g_MusicManager,&g_EffectManeger);


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

	//更新
	gpScene->Update();

	//画面遷移した場合
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
		case SCENENO_TITLE:
			gpScene = new CTitle();
			break;
		case SCENENO_SELECTMODE:
			gpScene = new CModeSelect();
			break;
		case SCENENO_TUTORIAL:
			gpScene = new CTutorial();
			break;
		case SCENENO_GAME:
			gpScene = new CGAME();
			break;
		case SCENENO_GAMEOVER:
			gpScene = new CGameOver();
			break;
		case SCENENO_GAMECLEAR:
			gpScene = new CGameClear();
			break;
		case SCENENO_GALLERY:
			gpScene = new CGallery();
			break;
		case SCENENO_OPTION:
			gpScene = new COption();
			break;

		}
		//初期化
		gpScene->Initialize(&g_GameProgMamt,&g_MusicManager,&g_EffectManeger);

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
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

	//描画
	gpScene->Render();

	if (gDebagflag)
	{
		//デバッグ描画
		gpScene->RenderDebug();
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
		g_EffectManeger.Release();
		g_MusicManager.Release();
	}

	return TRUE;
}
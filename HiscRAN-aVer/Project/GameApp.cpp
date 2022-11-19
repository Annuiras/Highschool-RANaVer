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

//現在のシーン
int			gScene = SCENENO_TITLE;

//変更するシーン
int			gChangeScene = SCENENO_TITLE;

//デバッグ
bool		gDebagflag = false;

CSceneBase* gpScene = NULL;

//各シーンクラス
//CTitle		gTitleScene;
//CModeSelect	gModeSelectScene;
//CTutorial	gTutorialScene;
//CGAME		gGAMEScene;
//CGameOver	gGameOverScene;
//CGameClear	gGameClearScene;
//CGallery		gGalleryScene;
//COption		gOptionScene;

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Resource");

	//gTitleScene.Load();
	//gModeSelectScene.Load();
	//gTutorialScene.Load();
	//gGAMEScene.Load();
	//gGameOverScene.Load();
	//gGameClearScene.Load();
	//gGalleryScene.Load();
	//gOptionScene.Load();


	//最初に実行されるシーンの初期化
	//gTitleScene.Initialize();

	//最初に実行されるシーンの初期化 
	gpScene = new CTitle();
	gpScene->Initialize();


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

	gpScene->Update();

	if (gpScene->IsEnd()) {

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
		gpScene->Initialize();

	}
	////シーン番号によって更新
	//switch (gScene)
	//{
	//case SCENENO_TITLE:
	//	gTitleScene.Update();
	//	break;
	//case SCENENO_SELECTMODE:
	//	gModeSelectScene.Update();
	//	break;
	//case SCENENO_TUTORIAL:
	//	gTutorialScene.Update();
	//	break;
	//case SCENENO_GAME:
	//	gGAMEScene.Update();
	//	break;
	//case SCENENO_GAMEOVER:
	//	gGameOverScene.Update();
	//	break;
	//case SCENENO_GAMECLEAR:
	//	gGameClearScene.Update();
	//	break;
	//case SCENENO_GALLERY:
	//	gGalleryScene.Update();
	//	break;
	//case SCENENO_OPTION:
	//	gOptionScene.Update();
	//	break;
	//}

	////シーン変更があった場合変更先シーンの初期化
	//if (gChangeScene != gScene)
	//{
	//	switch (gChangeScene)
	//	{
	//	case SCENENO_TITLE:
	//		gTitleScene.Initialize();
	//		break;
	//	case SCENENO_SELECTMODE:
	//		gModeSelectScene.Initialize();
	//		break;
	//	case SCENENO_TUTORIAL:
	//		gTutorialScene.Initialize();
	//		break;
	//	case SCENENO_GAME:
	//		gGAMEScene.Initialize();
	//		break;
	//	case SCENENO_GAMEOVER:
	//		gGameOverScene.Initialize();
	//		break;
	//	case SCENENO_GAMECLEAR:
	//		gGameClearScene.Initialize();
	//		break;
	//	case SCENENO_GALLERY:
	//		gGalleryScene.Initialize();
	//		break;
	//	case SCENENO_OPTION:
	//		gOptionScene.Initialize();
	//		break;
	//	}

	//	gScene = gChangeScene;
	//}

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


	gpScene->Render();

	////シーン番号によって描画
	//switch (gScene)
	//{
	//case SCENENO_TITLE:
	//	gTitleScene.Render();
	//	break;
	//case SCENENO_SELECTMODE:
	//	gModeSelectScene.Render();
	//	break;
	//case SCENENO_TUTORIAL:
	//	gTutorialScene.Render();
	//	break;
	//case SCENENO_GAME:
	//	gGAMEScene.Render();
	//	break;
	//case SCENENO_GAMEOVER:
	//	gGameOverScene.Render();
	//	break;
	//case SCENENO_GAMECLEAR:
	//	gGameClearScene.Render();
	//	break;
	//case SCENENO_GALLERY:
	//	gGalleryScene.Render();
	//	break;
	//case SCENENO_OPTION:
	//	gOptionScene.Render();
	//	break;
	//}

	//if (gDebagflag == true)
	//{
	//	switch (gScene)
	//	{
	//	case SCENENO_TITLE:
	//		gTitleScene.RenderDebug();
	//		break;
	//	case SCENENO_SELECTMODE:
	//		gModeSelectScene.RenderDebug();
	//		break;
	//	case SCENENO_TUTORIAL:
	//		gTutorialScene.RenderDebug();
	//		break;
	//	case SCENENO_GAME:
	//		gGAMEScene.RenderDebug();
	//		break;
	//	case SCENENO_GAMEOVER:
	//		gGameOverScene.RenderDebug();
	//		break;
	//	case SCENENO_GAMECLEAR:
	//		gGameClearScene.RenderDebug();
	//		break;
	//	case SCENENO_GALLERY:
	//		gGalleryScene.RenderDebug();
	//		break;
	//	case SCENENO_OPTION:
	//		gOptionScene.RenderDebug();
	//		break;
	//	}
	//}


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
	//gTitleScene.Release();
	//gModeSelectScene.Release();
	//gTutorialScene.Release();
	//gGAMEScene.Release();
	//gGameOverScene.Release();
	//gGameClearScene.Release();
	//gGalleryScene.Release();
	//gOptionScene.Release();

	return TRUE;
}
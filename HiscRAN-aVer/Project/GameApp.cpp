/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

#include	"Title.h"
#include	"ModeSelect.h"
#include	"Tutorial.h"
#include	"GAME.h"
#include	"Gallery.h"
#include	"Option.h"

//現在のシーン
int			gScene = SCENENO_TITLE;

//変更するシーン
int			gChangeScene = SCENENO_TITLE;

//各シーンクラス
Title		gTitleScene;
ModeSelect	gModeSelectScene;
Tutorial	gTutorialScene;
GAME		gGAMEScene;
Gallery		gGalleryScene;
Option		gOptionScene;

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	// リソース
	CUtilities::SetCurrentDirectoryA("Resource");

	gTitleScene.Load();
	gModeSelectScene.Load();
	gTutorialScene.Road();
	gGAMEScene.Load();
	gGalleryScene.Load();
	gOptionScene.Load();


	//最初に実行されるシーンの初期化
	gTitleScene.Initialize();



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

	//シーン番号によって更新
	switch (gScene)
	{
	case SCENENO_TITLE:
		gTitleScene.Update();
		break;
	case SCENENO_SELECTMODE:
		gModeSelectScene.Update();
		break;
	case SCENENO_TUTORIAL:
		gTutorialScene.Update();
		break;
	case SCENENO_GAME:
		gGAMEScene.Update();
		break;
	case SCENENO_GALLERY:
		gGalleryScene.Update();
		break;
	case SCENENO_OPTION:
		gOptionScene.Update();
		break;
	}

	//シーン変更があった場合変更先シーンの初期化
	if (gChangeScene != gScene)
	{
		switch (gChangeScene)
		{
		case SCENENO_TITLE:
			gTitleScene.Initialize();
			break;
		case SCENENO_SELECTMODE:
			gModeSelectScene.Initialize();
			break;
		case SCENENO_TUTORIAL:
			gTutorialScene.Initialize();
			break;
		case SCENENO_GAME:
			gGAMEScene.Initialize();
			break;
		case SCENENO_GALLERY:
			gGalleryScene.Initialize();
			break;
		case SCENENO_OPTION:
			gOptionScene.Initialize();
			break;
		}

		gScene = gChangeScene;
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

	//シーン番号によって描画
	switch (gScene)
	{
	case SCENENO_TITLE:
		gTitleScene.Render();
		break;
	case SCENENO_SELECTMODE:
		gModeSelectScene.Render();
		break;
	case SCENENO_TUTORIAL:
		gTutorialScene.Render();
		break;
	case SCENENO_GAME:
		gGAMEScene.Render();
		break;
	case SCENENO_GALLERY:
		gGalleryScene.Render();
		break;
	case SCENENO_OPTION:
		gOptionScene.Render();
		break;
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

	gTitleScene.Release();
	gModeSelectScene.Release();
	gTutorialScene.Release();
	gGAMEScene.Release();
	gGalleryScene.Release();
	gOptionScene.Release();

	return TRUE;
}
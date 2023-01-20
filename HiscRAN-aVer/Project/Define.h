#pragma once
#include	"Mof.h"
//////////////////////////////////////////////////////////
//　ゲーム全体で使用する定数などを宣言している場所です　//
//								   　　　　　　　　　　 //
//　作成者：田中環　  　　　　　　　　　  　　　　　　　//
//								   　　　 　　　　　　　//
//　リファクタリングした人：田中環 　　　 　　　　　　　//
//								   　　　　　　　　　　 //
//　最終更新：2023/01/20		   　　　 　　　　　　　//
//////////////////////////////////////////////////////////


//定数宣言

//画面のサイズ
#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720

//フェードアウト速度
#define FADE_OUT_SPEED 4

//ロード状態を定義
enum tag_LoadSituation {

	LOAD_YET,		//ロード前
	LOAD_COMP,		//ロード完了
	LOAD_DONE,		//ロード済:初期化済
	LOAD_ERROR,		//ロードエラー
};

//シーン推移状況
enum tag_SceneSituation
{
	FADE_IN,		//フェードイン
	FADE_OUT,		//フェードアウト	
	FADE_NOT,		//推移なし
	FADE_NEXT		//次のシーンへ
	
};

//ロードが必要シーン
//存在するシーン
enum tag_SCENENO {
	//タイトル画面
	SCENENO_TITLE,

	//モードセレクト画面
	SCENENO_SELECTMODE,

	//DP目標設定画面
	SCENENO_DPDECISION,

	//ゲーム本編
	SCENENO_GAME,

	//ゲームオーバー画面
	SCENENO_GAMEOVER,

	//ゲームクリア画面
	SCENENO_GAMECLEAR,

	//チュートリアル画面
	SCENENO_TUTORIAL,

	//オプション画面
	SCENENO_OPTION,

	//ギャラリー画面
	SCENENO_GALLERY,

	//エフェクト
	RESOURCE_EFFECT,

	//ミュージック
	RESOURCE_MUSIC,

	//総数
	SCENE_COUNT
};

#pragma once
#include	"Mof.h"

//todo:マップパターンの数を追加です

//マップDPパターン数
#define DP_INFO_PATTERN 15

//DP1パターンの要素数
#define DP_INFO_STRUCT 11

//マップ障害物パターン数
#define OB_INFO_PATTERN 15

//障害物1パターンの要素数
//（1マップ中にある障害物数＋1）
#define OB_INFO_STRUCT 4

//マップ足場パターン数
#define BAR_INFO_PATTERN 15

//足場1パターンの要素数
//（1マップ中にある足場数＋1）
#define BAR_INFO_STRUCT 4


//存在するシーン
enum tag_SCENENO {
	//タイトル画面
	SCENENO_TITLE,

	//モードセレクト画面
	SCENENO_SELECTMODE,

	//ゲーム本編
	SCENENO_GAME,

	//チュートリアル画面
	SCENENO_TUTORIAL,

	//オプション画面
	SCENENO_OPTION,

	//ギャラリー画面
	SCENENO_GALLERY,
};

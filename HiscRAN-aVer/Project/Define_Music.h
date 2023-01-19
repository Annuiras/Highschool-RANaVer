#pragma once

//ミュージック定数

//管理SEの数
#define		SE_MGMT_COUNT 5

//SE種類列挙
enum tag_SE_TYPE {

	//ゲーム,オーバー,クリア画面
	SE_T_JUMP,			//ジャンプ候補
	SE_T_GREAT_JUMP,	//グレートジャンプ
	SE_T_JUMP_LANDING,	//ジャンプ着地
	SE_T_DP_HIT,		//DP_GET候補
	SE_T_HIT,			//被弾_候補
	SE_T_GAMEOVER,		//Gameover_候補
	SE_T_GAMECLEAR,		//クリア_候補

	//DP選択画面
	SE_T_SE_DEC,	//DPカーソル移動時

	//ギャラリー画面
	SE_T_GALL_CURSORMOVE,		//ギャラリー_カーソル移動候補1

	//モードセレクト,オプション画面
	SE_T_MOOP_CURSORMOVE,	//モードセレクト、オプション画面カーソル移動_候補
	SE_T_DECISION,			//決定_候補
	SE_T_OPTION_CHIME,		//オプションチャイム

	SE_TYPE_COUNT,		//総数
};

//BGM種類列挙
enum tag_BGM_TYPE
{
	//タイトル画面
	BGMT_TITLE,//候補

	//入学説明画面
	BGMT_TUTORIAL,

	//ゲーム,クリア画面
	BGMT_STAGE,		//候補
	//BGMT_STAGE_SP_1,	//SP候補
	BGMT_CLEAR,			//クリア候補

	//DP選択画面
	BGMT_DPDECISION,

	//ギャラリー画面
	BGMT_GALLERY,		//候補

	//モードセレクト,オプション画面
	BGMT_MOOP,			//候補

	BGM_TYPE_COUNT		//総数
};

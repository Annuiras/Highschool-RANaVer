#pragma once
#include	"Mof.h"

//画面のサイズ
#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720

//マップパターン数
#define MAP_INFO_PATTERN 21

//１ステージ内のマップパターン数
#define SATAGE_MAP_PATTERN 15

//SPアイテムあるマップパターンの出現位置(何マップ目)
#define MAP_SP_ITEM_PATTERN_NUM 1

//ステージ変化する背景枚数
#define SATGE_CHANGE_BAK 200

//ステージクリアの背景枚数
#define STAGE_CLEAR_BAK 31

//ステージスクロールスピード
#define STAGE_SPEED 7

//重力
#define  GRAVITY	0.7f

//フェードアウト速度
#define FADE_OUT_SPEED 3

#pragma region DP定数群

//DP1パターンの要素数
//（1マップ中にあるDP数＋1）
#define DP_INFO_STRUCT 25

//DPタイプ定義
enum tag_DP_TYPE
{
	DP_SCHOLASTIC,		//学力
	DP_ACTION,			//行動力
	DP_IMAGINATION,		//想像力
	DP_COMMUNICATION,	//コミュ力
	DP_CHARM,			//魅力
	DP_SP_ITEM,			//SPアイテム
	DP_COUNT			//総数（終端要素）	
};


#pragma endregion

#pragma region 障害物定数群

//障害物タイプ定義
enum tag_OBTYPE
{
	OB_DESK,				//机
	OB_TWODESK,				//２段机
	OB_TRACHCAN,			//ごみ箱
	OB_LOCKER,				//ロッカー
	OB_TEXTBOOKCHEM,		//教科書_理科
	OB_VAULTINGHORSE,		//跳び箱
	OB_SCOTCHTAPE,			//セロハンテープ
	OB_BLOACKBOARDERASER,	//黒板消し
	OB_COUNT				//総数（終端要素）
}; 

//クラス数
#define OB_VOLUME 15

//障害物1パターンの要素数
//（1マップ中にある障害物数＋1）
#define OB_INFO_STRUCT 10

//障害物当たり判定高さ減衰用
#define OB_HITRECT_SPACE_Y 12

//乗れる矩形判定高さ
#define OB_TOPBAR_HEIGHT 80


#pragma endregion

#pragma region 敵定数群

//クラス数
#define		ENEMY_VOLUME 10

//敵1パターンの要素数
//（1マップ中にある敵数＋1）
#define ENEMY_INFO_STRUCT 5

//敵当たり判定
#define		ENEMY_SIZE_WIDTH	160	//横
#define		ENEMY_SIZE_HEIGHT	185	//縦


enum tag_ENEMY
{
	ENEMY_1,
	ENEMY_2, 
	ENEMY_COUNT,//総数（終端要素）
};

#pragma endregion

#pragma region 足場定数群

//足場タイプ定義
enum tag_BAR
{
	BAR_BIG,		//大
	BAR_MEDIUM,		//中
	BAR_SMALL,		//小
	BAR_COUNT		//総数（終端要素）
};

//足場1パターンの要素数
//（1マップ中にある足場数＋1）
#define BAR_INFO_STRUCT 10


#pragma endregion

#pragma region プレイヤー定数群

//プレイヤー初期位置
#define PLAYER_START_POS_X 50
#define PLAYER_START_POS_Y 500


//大ジャンプ値
#define  BIGJUMP -17.0f
//小ジャンプ値
#define  SMALLJUMP	-15.0f

//最大スライディング値
#define  SLIDING	100
//スライディングクールタイム
#define  SLIDINGCOOL 60

//プレイヤー当たり判定
#define PLAYER_HIT_X 150
#define PLAYER_HIT_Y 185

//足当たり判定
#define PLAYER_LEGS_Y 100

//当たり判定調整幅
#define PLAYER_ADMENT_SPACE 80

#pragma endregion

#pragma region 最終容姿画面定数群

#define CHART_SIZE 248			// チャート半径
#define CHART_CENTER_X 325	    // チャート中心座標 X
#define CHART_CENTER_Y 478	    // チャート中心座標 Y

#define MAX_STATUS 100			// ステータス最大値
#define ITEM_NUM 5				// ステータス個数

#pragma endregion


//地面高さ
#define GROUND_Y 700

//管理エフェクトの数
#define		EFFECT_MGMT_COUNT 5

//管理SEの数
#define		SE_MGMT_COUNT 5


//SE種類列挙
enum tag_SE_TYPE {

	//ゲーム,オーバー,クリア画面
	SE_T_JUMP,			//ジャンプ候補
	SE_T_GREAT_JUMP,	//グレートジャンプ
	SE_T_JUMP_LANDING,	//ジャンプ着地
	SE_T_HALLDASH,		//学校の廊下を走る
	SE_T_DP_HIT,		//DP_GET候補
	//SE_T_HIT_LOCKER,	//障害物ロッカ_候補1
	//SE_T_HIT_DESK1,		//障害物机_候補1
	//SE_T_HIT_DESK2,		//障害物机_候補2
	//SE_T_HIT_DESK3,		//障害物机_候補3
	//SE_T_HIT_1,			//被弾_候補1
	SE_T_HIT,			//被弾_候補
	SE_T_GAMEOVER,		//Gameover_候補
	SE_T_GAMECLEAR,		//クリア_候補

	//ギャラリー画面
	SE_T_GALL_CURSORMOVE,		//ギャラリー_カーソル移動候補1
	SE_T_UNOPENED,			//未開放選択時_候補1

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

	//ゲーム,オーバー,クリア画面
	BGMT_STAGE,		//候補
	//BGMT_STAGE_SP_1,	//SP候補
	BGMT_CLEAR,			//クリア候補

	//ギャラリー画面
	BGMT_GALLERY,		//候補

	//モードセレクト,オプション画面
	BGMT_MOOP,			//候補

	BGM_TYPE_COUNT		//総数
};

//エフェクト種類列挙
enum tag_EFFECTTYPE {
	EFC_GET_DP,						//DP取得

	EFC_TYPE_COUNT,
};

//ステージの状態を定義
enum class  tag_StageSituation
{
	STAGE_SP_YET,			//まだSPステージでない
	STAGE_SP_START,			//SPが始まった時
	STAGE_SP_STILL,			//SPの途中
	STAGE_SP_IMMEDIATELY,	//SPを終えた直後
	STAGE_SP_ALREADY		//SPを終えたあと
};

//存在するシーン
enum tag_SCENENO {
	//タイトル画面
	SCENENO_TITLE,

	//モードセレクト画面
	SCENENO_SELECTMODE,

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
};

#pragma once
#include	"Mof.h"

//画面のサイズ
#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720


//マップパターンの数を追加です

//todo:当たり判定調整中です
//当たり判定調整用
#define ITIZI_GENSUI_Y 12
#define ITIZI_GENSUI_Y2 

//todo:ステージ情報を統合したのでDPだけではよくない
//マップDPパターン数
#define DP_INFO_PATTERN 15

//DP1パターンの要素数
//（1マップ中にあるDP数＋1）
#define DP_INFO_STRUCT 15


//DPタイプ定義
enum tag_DP_TYPE
{
	DP_SCHOLASTIC,		//学力
	DP_ACTION,			//行動力
	DP_IMAGINATION,		//想像力
	DP_COMMUNICATION,	//コミュ力
	DP_CHARM			//魅力

};

#pragma region 障害物定数群

//障害物タイプ定義
enum tag_OBTYPE
{
	OB_DESK,		//机
	OB_TWODESK,		//２段机
	OB_LOCKER		//ロッカー
}; 

//クラス数
#define OB_VOLUME 15

//机横・縦幅
#define OB_DESK_WIDTH 131
#define OB_DESK_HEIGHT 172

//二段机横・縦幅
#define OB_TOWDESK_WIDTH 131
#define OB_TOWDESK_HEIGHT 292

//ロッカー横・縦幅
#define OB_LOCKER_WIDTH 138
#define OB_LOCKER_HEIGHT 308

//乗れる矩形判定高さ
#define OB_TOPBAR_HEIGHT 20+60


#pragma endregion




//足場タイプ定義
enum tag_BAR
{
	BAR_BIG,		//大
	BAR_MEDIUM,		//中
	BAR_SMALL		//小
};

//地面高さ
#define GROUND_Y 700

//マップ障害物パターン数
#define OB_INFO_PATTERN 15

//障害物1パターンの要素数
//（1マップ中にある障害物数＋1）
#define OB_INFO_STRUCT 10

//マップ足場パターン数
#define BAR_INFO_PATTERN 15

//足場1パターンの要素数
//（1マップ中にある足場数＋1）
#define BAR_INFO_STRUCT 10


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

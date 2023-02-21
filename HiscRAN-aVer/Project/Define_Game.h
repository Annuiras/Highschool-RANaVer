#pragma once

////////////////////////////////////////////////////////
//　ゲーム本編で使用する定数を宣言している場所です　  //
//								   　　　　　　　　　 //
//　作成者：田中環　  　　　　　　　　　  　　　　　  //
//								   　　　 　　　　　  //
//　リファクタリングした人：田中環 　　　 　　　　　  //
//								   　　　　　　　　   //
//　最終更新：2023/01/20		   　　　 　　　　　  //
////////////////////////////////////////////////////////

//マップパターン数
#define MAP_INFO_PATTERN 18

//1ゲーム内のマップパターン数
#define SATAGE_MAP_PATTERN 15

//SP開始マップパターン数(何パターン目)
#define MAP_SP_START_PATTERN 7

//SPステージパターン数
#define MAP_SP_LENGTH 2

//ステージクリアの背景枚数
#define STAGE_CLEAR_BAK 31

//ステージスクロールスピード
#define STAGE_SPEED1 7

//2年 ステージスクロールスピード
#define STAGE_SPEED2 7.5

//3年 ステージスクロールスピード
#define STAGE_SPEED3 8.0

//重力
#define  GRAVITY	0.7f

//地面高さ
#define GROUND_Y 700

#pragma region プレイヤー定数群

//HP
#define START_HP 5

//無敵時間
#define INVINCIBLE_TIME 60

//大ジャンプ値
#define  BIGJUMP -17.0f
//小ジャンプ値
#define  SMALLJUMP	-15.0f

//最大スライディング値
#define  SLIDING	100
//スライディングクールタイム
#define  SLIDINGCOOL 60

//プレイヤー当たり判定
#define PLAYER_HIT_X 70
#define PLAYER_HIT_Y 185

//足当たり判定
#define PLAYER_LEGS_Y 100

//当たり判定調整幅
#define PLAYER_ADMENT_SPACE 80

//プレイヤー初期位置
#define PLAYER_START_POS_X 50
#define PLAYER_START_POS_Y GROUND_Y - PLAYER_HIT_Y


#pragma endregion

#pragma region 障害物定数群

//障害物タイプ定義
enum tag_OBTYPE
{
	OB_TRACHCAN,			//ごみ箱
	OB_LOCKER,				//ロッカー
	OB_TEXTBOOKNL,			//教科書_国語
	OB_TEXTBOOKMATH,		//教科書_数学
	OB_TEXTBOOKCHEM,		//教科書_理科
	OB_TEXTBOOKSOC,			//教科書_社会
	OB_TEXTBOOKENG,			//教科書_英語
	OB_VAULTINGHORSE,		//跳び箱
	OB_SCOTCHTAPE,			//セロハンテープ
	OB_BLOACKBOARDERASER,	//黒板消し
	OB_SEAWEED,				//スティックのり
	OB_SMARTPHONE1,			//スマホ１
	OB_ERASER,				//消しゴム
	OB_SMARTPHONEVERTICAL,	//スマホ縦
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
#define		ENEMY_SIZE_WIDTH	70	//横
#define		ENEMY_SIZE_HEIGHT	185	//縦

//敵種類
enum tag_ENEMY
{
	ENEMY_1,
	ENEMY_COUNT,//総数（終端要素）
};

#pragma endregion

#pragma region 足場定数群

//クラス数
#define BAR_VOLUME	5

//大
#define BAR_BIG_WIDTH	800
#define BAR_BIG_HEIGHT	40

//中
#define BAR_MEDIUM_WIDTH	500
#define BAR_MEDIUM_HEIGHT	25

//足場タイプ定義
enum tag_BAR
{
	BAR_BIG,		//大
	BAR_MEDIUM,		//中
	BAR_COUNT		//総数（終端要素）
};

//足場1パターンの要素数
//（1マップ中にある足場数＋1）
#define BAR_INFO_STRUCT 10



#pragma endregion

#pragma region DP定数群

//DP1パターンの要素数
//（1マップ中にあるDP数＋1）
#define DP_INFO_STRUCT 40

//DPタイプ定義
enum tag_DP_TYPE
{
	DP_SCHOLASTIC,		//学力
	DP_ACTION,			//行動力
	DP_IMAGINATION,		//想像力
	DP_COMMUNICATION,	//コミュ力
	DP_CHARM,			//魅力

	DP_COUNT,			//種類総数（終端要素）	

	DP_SP_SCHOLASTIC,	//SP学力
	DP_SP_ACTION,		//SP行動力
	DP_SP_IMAGINATION,	//SP想像力
	DP_SP_COMMUNICATION,//SPコミュ力
	DP_SP_CHARM,		//SP魅力

};


#pragma endregion

//ステージの状態を定義
enum class  tag_StageSituation
{
	STAGE_SP_YET,			//SPでない
	STAGE_SP_STILL,			//SPの途中
};


//ステージの背景種類を定義
enum tag_StageBakType
{
	STAGE_BAKT_START,		//ステージ最初
	STAGE_BAKT_RDOOR,		//ステージ右扉
	STAGE_BAKT_RWALL,		//ステージ右壁
	STAGE_BAKT_LDOOR,		//ステージ左扉
	STAGE_BAKT_LWALL,		//ステージ左壁
	STAGE_BAKT_WINDOW,		//ステージ二窓
	STAGE_BAKT_SRAIRS,		//ステージ階段
	STAGE_BAKT_END,			//ステージ終わり
	STAGE_BAKT_SPSTART,		//SPステージ最初
	STAGE_BAKT_SP1,			//SPステージ１
	STAGE_BAKT_SP2,			//SPステージ２
	STAGE_BAKT_SPEND,		//SPステージ終わり

	STAGE_BAKT_COUNT,		//総数
};

////DPの出現位置情報用構造体
typedef struct tag_DP_POS
{
	float Scroll;	//DP出現スクロール値
	float Pos_y;	//DP出現Y座標
	tag_DP_TYPE	Type;		//DPタイプ

} DP_info;

//障害物の出現位置情報用構造体
typedef struct tag_OBSTAClE_POS
{
	float Scroll;	//障害物出現スクロール値
	float Pos_y;	//障害物出現Y座標
	tag_OBTYPE	Type;		//障害物タイプ

} OB_info;


//足場の出現位置情報用構造体
typedef struct tag_BAR_POS
{
	float Scroll;	//足場出現スクロール値
	float Pos_y;	//足場出現Y座標
	tag_BAR	Type;		//足場タイプ（仮）

} BAR_info;

//敵の出現位置情報構造体
typedef struct tag_ENEMY_POS
{
	float Scroll;
	float Pos_y;
	int	  Type;
} ENEMY_info;

//敵モーション種類定義
enum tag_ENEMY_MOTION {
	ENEMY_MOTION_MOVE,

	ENEMY_MOTION_COUNT,
};

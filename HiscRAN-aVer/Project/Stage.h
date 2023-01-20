//////////////////////////////////////////////
//	ステージ管理のプログラムです			//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "RandomValue.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "EffectManager.h"
#include "MusicManager.h"

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

//モーション種類定義
enum tag_ENEMY_MOTION {
	ENEMY_MOTION_MOVE,

	ENEMY_MOTION_COUNT,
};

class CStage
{
private:

	//乱数生成
	RandomValue RandmuBak;

	//エフェクトマネージャー
	CEffectMgmt* m_pEffectMgmt;

	//SE・BGMマネージャー
	CMusicMgmt* m_MusicMgmt;


	#pragma region ステージテクスチャ

	//廊下始まり
	CTexture m_BakStart;

	//右扉
	CTexture m_BakRdoor;
	
	//右壁
	CTexture m_BakRwall;

	//左扉
	CTexture m_Bakldoor;

	//左壁
	CTexture m_Baklwall;

	//二窓
	CTexture m_BakWindow;

	//階段
	CTexture m_BakStairs;

	//廊下終わり
	CTexture m_BakEnd;

	//SPステージ始まり
	CTexture m_SPBak_Start;

	//SPステージ１
	CTexture m_SPBak_1;

	//SPステージ２
	CTexture m_SPBak_2;

	//SPステージ終わり
	CTexture m_SPBak_End;

#pragma endregion

	#pragma region DPテクスチャ

	//仮DPテクスチャ：学力
	CTexture dp_Textuer_Scholastic;

	//仮DPテクスチャ：行動力
	CTexture dp_Textuer_Action;

	//仮DPテクスチャ：想像力
	CTexture dp_Textuer_Imagination;

	//仮DPテクスチャ：コミュ力
	CTexture dp_Textuer_Communication;

	//仮DPテクスチャ：魅力
	CTexture dp_Textuer_Charm;


#pragma endregion

	#pragma region 障害物テクスチャ

	//テクスチャ：机
	CTexture ob_Textuer_Desk;

	//テクスチャ：２段机
	CTexture ob_Textuer_TwoDesk;

	//テクスチャ：ごみ箱
	CTexture ob_Textuer_TrachCan;

	//テクスチャ：ロッカー
	CTexture ob_Textuer_Locker;

	//テクスチャ：教科書_国語
	CTexture ob_Textuer_TextBookNL;

	//テクスチャ：教科書_数学
	CTexture ob_Textuer_TextBookMATH;

	//テクスチャ：教科書_理科
	CTexture ob_Textuer_TextBookCHEM;

	//テクスチャ：教科書_社会
	CTexture ob_Textuer_TextBookSOC;

	//テクスチャ：教科書_英語
	CTexture ob_Textuer_TextBookENG;

	//テクスチャ：跳び箱
	CTexture ob_Textuer_VaultingHorse;

	//テクスチャ：セロハンテープ
	CTexture ob_Textuer_ScotchTape;

	//テクスチャ：黒板消し
	CTexture ob_Textuer_BloackboardEraser;

	//テクスチャ：スティックのり
	CTexture ob_Seaweed;

	//テクスチャ：スマホ１
	CTexture ob_Smartphone1;

	//テクスチャ：消しゴム
	CTexture ob_Eraser;

	//テクスチャ：スマホ縦
	CTexture ob_SmartphoneVertical;

#pragma endregion

	#pragma region 足場テクスチャ

	//仮テクスチャ：足場大
	CTexture bar_Textuer_Big;

	//仮テクスチャ：足場中
	CTexture bar_Textuer_Medium;

#pragma endregion

	#pragma region 敵テクスチャ

	//敵テクスチャ : 敵1
	CTexture ene_Texture_1;
	//敵テクスチャ : 敵2
	CTexture ene_Texture_2;

#pragma endregion

	//敵アニメーション
	CSpriteMotionController Enemy_Motion;

	//進行度バー
	CTexture m_BarTextuer;
	//進行度中アイコン
	CTexture m_CharaProgressTextuer;
	//キャラアイコンの表示
	CTexture m_CharaIconTexture;
	//学年の表示
	CTexture m_GradeOneTexture;
	CTexture m_GradeTwoTexture;
	CTexture m_GradeThreeTexture;
	//進行度表示用
	int m_BarProgress;

	//学年画像表示の位置
	float	m_GradeOffset;

	//マップパターン添え字
	int m_MapNo;

	//ステージ構成を決める配列
	int m_StageComposition[SATAGE_MAP_PATTERN] = { 1 };


	//表示済みDP数
	int m_dpcount;

	//表示済障害物
	int m_obcount;

	//表示済み足場数
	int m_barcount;

	//表示済み敵数
	int m_enecount;

	//背景用スクロール値
	float	m_BakScroll;

	//ステージ用スクロール
	float	m_StageScroll;

	//背景構成
	int m_BakComposition[(SATAGE_MAP_PATTERN * 2)+1];
	//背景カウント
	int m_countbak;


	//中間背景用ランダム数値
	//左側
	int m_RandamuBakLeft;
	//右側
	int m_RandamuBakRight;
	//保存用
	int m_RandamuBakRightSave;

	//使用済みパターン番号記録用配列
	int	m_AlreadyUsedArray[MAP_INFO_PATTERN];

	//採用済カウント
	int m_AdoptCount;


	//スクロールスピード
	float m_Scroll_Speed;

	//ステージ変化
	bool				v_StageChangeflg;//変化フラグ true:変化済

	//SPありフラグ
	//true:あり
	bool SP_flg;

	//背景α値
	int m_BakAVal;

	//SPステージ
	//SPの状態を現す
	tag_StageSituation	m_SPSitua;

	int					m_SPcountbak;

	//DP目標設定画面で選んだDP番号
	int DP_Deci_Type;

	//SPフェードアウトフラグ
	bool				m_SPflg;

	//クリアフラグ
	bool m_bClear;

	//ゲーム開始フラグ
	bool					m_Startflg;

public:
	CStage();
	~CStage();

	//spflg:SPありフラグ
	//dptype:DP目標設定画面で選んだDP番号
	void Initialize(bool spflg,int dptype);

	//SP内のDP配置をするための関数
	void SPInitialize(void);


	void Update(CRectangle plrect);

	//素材ロード
	bool Load(void);

	void Render(void);
	void Release(void);
	void RenderDebugging(void);

	//マップパターン
	void MapChange(void);

	//足場生成
	void OccurrenceBar(void);

	//DP生成
	void OccurrenceDP(void);

	//障害物生成
	void OccurrenceOB(void);

	//敵生成
	void OccurrenceENE(void);

	//クリア判定の取得
	bool GetClear(void);

	//SE・BGMマネージャーセット
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//エフェクトマネージャーセット
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }

	//障害物
	CObstacle ob_array[OB_VOLUME];

	//足場クラス
	Bar	b_bar[BAR_VOLUME];

	//一画面に表示するDPの数だけ用意
	//DPクラス
	DetailPoint dp_array[DP_VOLUME];

	//敵クラス
	CEnemy ene_array[ENEMY_VOLUME];

	//ゲーム停止：再生切り替え
	void GameStopPlayChange();

	//ステージが動いているか取得
	bool GetGameStopPlay();

	//SPの状態をセット
	void SetSPSitua(tag_StageSituation i) { m_SPSitua = i; }


};
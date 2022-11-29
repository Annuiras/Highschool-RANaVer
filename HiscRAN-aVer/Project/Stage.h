#pragma once
#include "Mof.h"
#include "Define.h"
#include "RandomValue.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
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

	//SPステージテクスチャ
	CTexture m_SPBak;

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

	//仮テクスチャ：机
	CTexture ob_Textuer_Desk;

	//仮テクスチャ：２段机
	CTexture ob_Textuer_TwoDesk;

	//仮テクスチャ：ロッカー
	CTexture ob_Textuer_Locker;



#pragma endregion

#pragma region 足場テクスチャ

	//仮テクスチャ：足場中
	CTexture bar_Textuer_Medium;

#pragma endregion

	//マップパターン添え字
	int m_MapNo;

	//ステージ構成を決める配列
	int m_StageComposition[MAP_INFO_PATTERN] = { 1 };


	//DPの配置情報受け取る配列
	//[]:マップDPパターン情報数
	//[]:マップDPパターン1枚分にいくつ構造体があるか
	//DPの配置情報
	DP_info m_dpinfo[MAP_INFO_PATTERN][DP_INFO_STRUCT];

	//表示済みDP数
	int m_dpcount;


	//OBの配置情報受け取る配列
	//[]:マップOBパターン情報数
	//[]:マップOBパターン1枚分にいくつ構造体があるか
	//OBの配置情報
	OB_info m_obinfo[MAP_INFO_PATTERN][OB_INFO_STRUCT];

	//表示済障害物
	int m_obcount;


	//足場の配置情報受け取る配列
	//[]:マップ足場パターン情報数
	//[]:マップ足場パターン1枚分にいくつ構造体があるか
	//足場の配置情報
	BAR_info m_barinfo[MAP_INFO_PATTERN][OB_INFO_STRUCT];


	//表示済み足場数
	int m_barcount;


	//背景用スクロール値
	float	m_BakScroll;

	//ステージ用スクロール
	float	m_StageScroll;

	//中間背景用ランダム数値
	//左側
	int m_RandamuBakLeft;
	//右側
	int m_RandamuBakRight;

	//使用済みパターン番号記録用配列
	int	m_AlreadyUsedArray[MAP_INFO_PATTERN];

	//採用済カウント
	int m_AdoptCount;

	//背景カウント
	int m_countbak;

	//スクロールスピード
	float m_Scroll_Speed;

	//ステージ内で取得したDPの数
	int	m_Scholastic;		//学力
	int	m_Action;			//行動力
	int	m_Imagination;		//想像力
	int	m_Communication;	//コミュ力
	int	m_Charm;			//魅力

	//ステージ変化
	int					m_StageChange;
	bool				m_bStart;//変化フラグ true:変化済
	//todo:背景α値
	int m_BakAVal;

	//todo SPステージ
	int					m_SPSitua;
	int					m_SPcountbak;
	bool				m_SPflg;

	//クリアフラグ
	bool m_bClear;

	//ゲーム開始フラグ
	bool					m_Startflg;

public:
	CStage();
	~CStage();

	//dpin[][]:DPの配置情報
	//[]:マップパターンがいくつあるか
	//[]:1マップパターンにいくつ構造体があるか
	void Initialize(DP_info dpin[][DP_INFO_STRUCT], BAR_info barin[][BAR_INFO_STRUCT], OB_info obin[][OB_INFO_STRUCT]);

	//todo SP内のDP配置をするための関数
	void SPInitialize(void);


	void Update(CRectangle plrect);
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

	//DPと接触処理
	void UPdeteCollisionDP(int dpt);

	//クリア判定の取得
	bool GetClear(void);

	//SE・BGMマネージャーセット
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//エフェクトマネージャーセット
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }

	//障害物
	CObstacle ob_array[OB_VOLUME];

	//地面クラス
	Ground g_ground;

	//足場クラス
	Bar	b_bar[BAR_VOLUME];

	//一画面に表示するDPの数だけ用意
	//DPクラス
	DetailPoint dp_array[DP_VOLUME];

	//ゲーム停止：再生切り替え
	void GameStopPlayChange();

	//ステージが動いているか取得
	bool GetGameStopPlay();




};


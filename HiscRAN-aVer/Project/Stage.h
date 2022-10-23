#pragma once
#include "Mof.h"
#include "RandomValue.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"

////DPの出現位置情報用構造体
typedef struct tag_DP_POS
{
	float Pos_y;	//DP出現Y座標
	float Scroll;	//DP出現スクロール値
	int	Type;		//DPタイプ

} DP_info;

//障害物の出現位置情報用構造体
typedef struct tag_OBSTAClE_POS
{
	float Pos_y;	//障害物出現Y座標
	float Scroll;	//障害物出現スクロール値

} OB_info;


//足場の出現位置情報用構造体
typedef struct tag_BAR_POS
{
	float Pos_y;	//足場出現Y座標
	float Scroll;	//足場出現スクロール値

} BAR_info;

class CStage
{
private:

	//乱数生成
	RandomValue RandmuBak;

	//背景テクスチャ
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

	//DPの配置情報
	DP_info* m_dpinfo;

	//DPの情報数
	int m_dpvolume;

	//表示済みDP数
	int m_dpcount;


	//足場の配置情報
	BAR_info* m_barinfo;

	//足場の情報数
	int m_barvolume;

	//表示済み足場数
	int m_barcount;


	//障害物の配置情報
	OB_info* m_obinfo;

	//障害物の情報数
	int m_obvolume;

	//表示済障害物
	int m_obcount;


	//背景用スクロール値
	float	m_BakScroll;

	//ステージ用スクロール
	float	m_StageScroll;

	//中間背景用ランダム数値
	//左側
	int m_RandamuBakLeft;
	//右側
	int m_RandamuBakRight;


	//座標位置
	float					m_PosX;
	float					m_PosY;

	//移動速度
	float					m_MoveX;
	float					m_MoveY;

	//背景カウント
	int m_countbak;

	//オーバー値
	float	m_Over;

	//SPステージフラグ
	bool m_spflg;

	//ステージ内で取得したDPの数
	int	m_gaku;
	int	m_sou;
	int	m_kou;
	int	m_komyu;
	int	m_miryoku;

	//クリアフラグ
	bool m_bClear;


	//背景デバック用
	float m_baklineX;


public:
	CStage();
	~CStage();

	void Initialize(DP_info* dpin, int dpco, BAR_info* barin, int barco, OB_info* obin, int obco);
	
	//引数追加 CRectangle pl2, float suckingX, float suckingY
	void Update(float over, CRectangle pl,CRectangle pl2, float suckingX, float suckingY);
	bool Load(void);
	void Render(void);
	void Release(void);
	void DebuggingRender(void);

	//DPと接触処理
	void UPdeteCollisionDP(int dpt);

	//クリア判定の取得
	bool GetClear(void);

	//障害物
	CObstacle ob_array[OB_VOLUME];

	//地面クラス
	Ground g_ground;

	//足場クラス
	Bar	b_bar[BAR_MAX];

	//DPクラス
	DetailPoint dp_array[DP_VOLUME];


};


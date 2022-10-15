#pragma once
#include "Mof.h"
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



	//背景テクスチャ
	CTexture m_Bak;
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



public:
	CStage();
	~CStage();

	void Initialize(DP_info* dpin, int dpco, BAR_info* barin, int barco, OB_info* obin, int obco);
	void Update(float over, CRectangle pl);
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


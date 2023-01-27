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


class CStage
{
private:

	//乱数生成
	RandomValue RandmuBak;

	//エフェクトマネージャー
	CEffectMgmt* m_pEffectMgmt;

	//SE・BGMマネージャー
	CMusicMgmt* m_MusicMgmt;

	//ステージテクスチャ
	CTexture m_BakTex[STAGE_BAKT_COUNT];

	//DPテクスチャ
	CTexture m_DPTex[DP_COUNT];

	//障害物テクスチャ
	CTexture ob_Textuer[OB_COUNT];

	#pragma region 足場テクスチャ

	//仮テクスチャ：足場大
	CTexture bar_Textuer_Big;

	//仮テクスチャ：足場中
	CTexture bar_Textuer_Medium;

#pragma endregion

	#pragma region 敵テクスチャ

	//敵テクスチャ : 敵1
	CTexture ene_Texture_1;

	//敵アニメーション
	CSpriteMotionController Enemy_Motion;
#pragma endregion

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

	CTexture m_DPDEcisionTexture[DP_COUNT];


	//進行度表示用
	int m_BarProgress;

	//学年画像表示の位置
	float	m_GradeOffset;

	//マップパターン添え字
	int m_MapNo;

	//ステージ構成を決める配列
	int m_StageComposition[SATAGE_MAP_PATTERN + 1];

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

	//進行度計算用
	int m_BarProgressCount;

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
	//true:開始中
	bool					m_Startflg;

public:
	CStage();
	~CStage();

	//spflg:SPありフラグ
	//dptype:DP目標設定画面で選んだDP番号
	void Initialize(bool spflg,int dptype);

	void Update(CRectangle plrect);

	//デバック更新
	void UpdateDebug(void);

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
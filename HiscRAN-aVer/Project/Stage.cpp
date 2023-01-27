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
#include "Stage.h"
#include "ctime"
#include "string"
#include "Stage_DP.h"
#include "Stage_Bar.h"
#include "Stage_Obstacle.h"
#include "Stage_Enemy.h"

CStage::CStage() :

	m_countbak(0),
	m_BakTex(),
	m_dpcount(0),
	m_barcount(0),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f), 
	m_BakAVal(0),
	m_AdoptCount(0),
	m_AlreadyUsedArray(),
	SP_flg(),
	m_bClear(false),
	m_RandamuBakRightSave(),
	m_Scroll_Speed(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

	//ステージ背景ロード
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("StageBak");

	char* Bakname[STAGE_BAKT_COUNT] =
	{
		"HallStart.png",
		"Door_R.png",
		"Wall_R.png",
		"Door_L.png",
		"Wall_L.png",
		"Stairs.png",
		"Window_2.png",
		"HallEnd.png",
		"SPStart.png",
		"SP1.png",
		"SP2.png",
		"SPEnd.png",
	};

	//ステージ背景ロード
	for (int i = 0; i < STAGE_BAKT_COUNT; i++)
	{
		if (!m_BakTex[i].Load(Bakname[i])) {
			return false;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");


	//DPテクスチャロード
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("DetailPoint");

	char* DPname[DP_COUNT] =
	{
		"DPScholastic.png",
		"DPAction.png",
		"DPImagination.png",
		"DPCommunication.png",
		"DPCharm.png",
	};

	for (int i = 0; i < DP_COUNT; i++)
	{
		if (!m_DPTex[i].Load(DPname[i])) {
			return false;
		}
	}
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");


	//障害物テクスチャロード
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Obstacle");

	char* OBname[OB_COUNT] =
	{
		"TrachCan.png",
		"Locker.png",
		"TextBookNL.png",
		"TextBookMATH.png",
		"TextBookCHEM.png",
		"TextBookSOC.png",
		"TextBookENG.png",
		"VaultingHorse.png",
		"ScotchTape.png",
		"BloackboardEraser.png",
		"Seaweed.png",
		"Smartphone1.png",
		"Eraser.png",
		"SmartphoneVertical.png",
	};

	for (int i = 0; i < OB_COUNT; i++)
	{
		ob_Textuer[i].Load(OBname[i]);
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

#pragma endregion

#pragma region 足場テクスチャロード

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Bar");

	//仮テクスチャ：足場大
	if (!bar_Textuer_Big.Load("Big.png")) {
		return false;
	}

	//仮テクスチャ：足場中
	if (!bar_Textuer_Medium.Load("Medium.png")) {
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

#pragma endregion

	//進行度バー、進行度中アイコン、アイコンの表示
	if (!m_BarTextuer.Load("Game_Bar.png")) {
		return false;
	}
	if (!m_CharaProgressTextuer.Load("Game_CharaProgress.png")) {
		return false;
	}


#pragma region 敵

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Character");

	//敵1
	if (!ene_Texture_1.Load("Motion.png"))
	{
		return false;
	}
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//敵アニメーションを用意

	//コマ数
	float Encoma = 4;
	//段数
	MofS32 Enedan = 4;
	//アニメーション
	SpriteAnimationCreate EneAnim[] =
	{
		{
			"敵移動",
			0, 370,
			160, 185,
			TRUE,{ {Encoma,0,Enedan},{Encoma,1,Enedan},{Encoma,2,Enedan},{Encoma,3,Enedan},{Encoma,4,Enedan},{Encoma,5,Enedan},{Encoma,6,Enedan},{Encoma,7,Enedan},{Encoma,8,Enedan},{Encoma,9,Enedan},{Encoma,10,Enedan}
			,{Encoma,11,Enedan},{Encoma,12,Enedan},{Encoma,13,Enedan},{Encoma,14,Enedan}}

		},
	};
	Enemy_Motion.Create(EneAnim, ENEMY_MOTION_COUNT);

#pragma endregion

	//todoロード
	if (!m_DPDEcisionTexture.Load("mokuhixyou_souzourixyoku.png")) {
		return false;
	}

	return true;
}

//初期化
//spflg:SPありフラグ
void CStage::Initialize(bool spflg, int dptype) {

	//SPありフラグセット
	SP_flg = spflg;

	//DP目標設定画面で選んだDP番号セット
	DP_Deci_Type = dptype;

	//進行度バーアイコンの初期化
	m_BarProgress = 0;

	//学年表示の表示位置の初期化
	m_GradeOffset = g_pGraphics->GetTargetWidth();

	//スクロール値初期化
	m_BakScroll = 1.0f;

	//ステージスクロール値初期化
	m_StageScroll = g_pGraphics->GetTargetWidth()*2;

	//背景カウント初期化
	m_countbak = 0;

	//α値初期化
	m_BakAVal = 255;

	//ステージ変化フラグ
	v_StageChangeflg = false;		

	//SPステージ状態用
	m_SPSitua = tag_StageSituation::STAGE_SP_YET;

	//SP背景カウント
	m_SPcountbak = 0;

	//マップパターン添え字
	m_MapNo = 0;

	//初期化
	m_AdoptCount = 0;

	//ステージ構成をセット
	//低確率で同じステージが選択されてしまうため試行回数は多め
	for (int z = 1; z < 1000; z++)
	{
		//1ゲーム分のステージが用意出来たら終了
		if (m_AdoptCount >= SATAGE_MAP_PATTERN) {
			break;
		}

		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (m_AlreadyUsedArray[x] == 1)
			{
				//どこまで採用済みかカウント
				m_AdoptCount += 1;
			}
		}

		//SPマップを採用
		if (m_AdoptCount == MAP_SP_START_PATTERN && SP_flg)
		{
			//SP採用数
			int SPAdopCount = 0;

			//SPマップパターンをセット
			for (int i = 0; i < 100; i++)
			{
				//ランダム生成
				int SPrandmu = RandmuBak.GetRandomNumbe(15, 16);

				//仕様済みでない場合
				if (m_AlreadyUsedArray[SPrandmu] == 0) {

					//SPステージセット
					m_StageComposition[m_AdoptCount+ SPAdopCount] = SPrandmu;
					//増加
					SPAdopCount++;
					//使用したパターンの場所に１をセット
					m_AlreadyUsedArray[SPrandmu] = 1;

				}
				//1SPステージ分のステージが用意出来たら終了
				if (m_AdoptCount+ MAP_SP_LENGTH <= m_AdoptCount+ SPAdopCount) {
					break;
				}

			}
		}
		else 
		{
			//通常ステージの中からランダムパターンをセット
			int randam= RandmuBak.GetRandomNumbe(0, 14);

			//まだ使用していない場合のみ採用(1=使用済み)
			if (m_AlreadyUsedArray[randam] == 0)
			{

				//採用
				m_StageComposition[m_AdoptCount] = randam;

				//使用したパターンの場所に１をセット
				m_AlreadyUsedArray[randam] = 1;
			
			}			

		}

		//採用済カウント
		m_AdoptCount = 0;
	}

	//最後のマップ番号
	m_StageComposition[15] = MAP_INFO_PATTERN-1;

	//背景構成を決める処理
	for (int i = 0; i < SATAGE_MAP_PATTERN*2; i++)
	{
		//ランダムで種類を決定する
		int randamu=RandmuBak.GetRandomNumbe(STAGE_BAKT_RDOOR, STAGE_BAKT_SRAIRS);

		//一番最初以外で、同じ背景の場合
		//違う背景にする処理
		if (i != 0&&randamu == m_BakComposition[i - 1]) {

			if (randamu == 6) {
				randamu = 1;
			}
			else
			{
				randamu++;
			}
		}

		//↑同じ背景が連続しないようにするものなくてもよし
		m_BakComposition[i] = randamu;

	}

	//背景構成の一番最後用の物を適用する
	m_BakComposition[SATAGE_MAP_PATTERN * 2] = STAGE_BAKT_END;

	//右側から背景構成を読むための初期化
	//一番最初の背景
	m_RandamuBakRight = STAGE_BAKT_START;
	m_RandamuBakLeft = m_BakComposition[0];

	//スペシャルステージが発生する場合
	//背景をスペシャルステージに変更する
	if (SP_flg) {

		//SP開始位置にSPステージ開始背景をセット
		m_BakComposition[(MAP_SP_START_PATTERN * 2)] = STAGE_BAKT_SPSTART;

		for (int i = 1; i < MAP_SP_LENGTH * 2; i++)
		{
			//SPステージ背景をランダムでセット
			m_BakComposition[(MAP_SP_START_PATTERN * 2) + i] = RandmuBak.GetRandomNumbe(STAGE_BAKT_SP1, STAGE_BAKT_SP2);
		}

		//SPステージ終わり背景をセット
		m_BakComposition[(MAP_SP_START_PATTERN * 2)+(MAP_SP_LENGTH*2)-1] = STAGE_BAKT_SPEND;
	}

	//使用済み背景記録を初期化
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		m_AlreadyUsedArray[i] = 0;
	}


	//デバッグ用のステージ指定コマンド、必要に応じていじってください
	//m_StageComposition[0] = 0;
	//m_StageComposition[1] = 1;
	//m_StageComposition[2] = 2;
	//m_StageComposition[3] = 3;
	//m_StageComposition[4] = 4;
	//m_StageComposition[5] = 5;
	//m_StageComposition[6] = 6;
	//m_StageComposition[7] = 7;
	//m_StageComposition[8] = 8;
	//m_StageComposition[9] = 9;
	//m_StageComposition[10] = 10;
	//m_StageComposition[11] = 0;
	//m_StageComposition[12] = 8;
	//m_StageComposition[13] = 8;
	//m_StageComposition[14] = 2;


	//表示済みカウント初期化
	m_barcount = 0;
	m_dpcount = 0;
	m_obcount = 0;
	m_enecount = 0;

	//クリアフラグ初期化
	m_bClear = false;

	//ステージスクロール速度
	m_Scroll_Speed = 0;

	//開始フラグ
	m_Startflg = false;

	//足場
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		//初期配置
		b_bar[i].Initialize();
	}

	//DP
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//初期化
		dp_array[i].Initialize();
	}

	//障害物
	for (int i = 0; i < OB_VOLUME; i++)
	{
		//初期化
		ob_array[i].Initialize();
	}

	//敵
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		//初期化
		ene_array[i].Initialize();
	}

}

//更新
//plrect:プレイヤーの当たり判定矩形
void CStage::Update(CRectangle plrect) {


	//背景カウント
	if (m_BakScroll <= 0) {

		//背景カウント
		m_countbak += 1;

		//初期化
		m_BakScroll = m_BakTex[0].GetWidth();

	}

	//ステージ速度変更
	//二年開始時
	if (m_countbak == 10) {
		m_Scroll_Speed = STAGE_SPEED2;
	}

	//三年開始時
	if (m_countbak == 20) {
		m_Scroll_Speed = STAGE_SPEED3;
	}

	//SPステージ開始
	if (m_countbak == (MAP_SP_START_PATTERN * 2) + 1 && SP_flg) {
		m_SPSitua = tag_StageSituation::STAGE_SP_STILL;
	}


	//画像幅:1280 枚数:31 進行バー:680   1280*31/680=58
	if (m_BarProgressCount + 58 < m_StageScroll) {
		m_BarProgress++;
		m_BarProgressCount = m_StageScroll;
	}
	//m_StageScrollがリセットされたとき
	else if (m_BarProgressCount >= m_StageScroll) {
		m_BarProgressCount = 0;
	}									//2560は画像幅＊2
	else if (m_BarProgressCount + 58 >= 2560) {
		m_BarProgressCount = m_BarProgressCount + 58 - 2560;
	}

	//クリアフラグ変更
	if (m_countbak == 32) {

		m_bClear = true;
	}
	else
	{
		//後ろに下げる
		m_BakScroll -= m_Scroll_Speed;
	}

	//ステージ生成用スクロール値
	m_StageScroll += m_Scroll_Speed;

	//ステージスクロール値
	if (m_StageScroll >=g_pGraphics->GetTargetWidth()*2)
	{
		//スクロール値リセット
		m_StageScroll = 0;
	}

	//マップパターンの切り替え
	MapChange();

	//同じX座標の場合の複数回判定
	for (int i = 0; i < 3; i++)
	{
		//足場生成
		OccurrenceBar();
	}


	//同じX座標の場合の複数回判定
	for (int i = 0; i < 10; i++)
	{
		//ディテールポイント生成
		OccurrenceDP();
	}

	//同じX座標の場合の複数回判定
	for (int i = 0; i < 5; i++)
	{
		//障害物OB生成
		OccurrenceOB();
	}

	//同じX座標の場合の複数回判定
	for (int i = 0; i < 3; i++)
	{
		//敵生成
		OccurrenceENE();
	}

	//足場更新
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].Update(m_Scroll_Speed);
	}

	//DP更新
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Update(m_Scroll_Speed);
	}

	//障害物更新
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Update(m_Scroll_Speed);
	}
	
	//敵更新
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].Update(m_Scroll_Speed);
	}

	//SP中の処理
	if (m_SPSitua == tag_StageSituation::STAGE_SP_STILL)
	{
		//SPの背景カウント
		if (m_BakScroll <= 0)
		{
			//SP背景カウント
			m_SPcountbak += 1;
		}
		//SP背景カウント
		if (m_SPcountbak == (MAP_SP_LENGTH*2))
		{
 			m_SPSitua = tag_StageSituation::STAGE_SP_YET;
		}

	}

}

void CStage::UpdateDebug(void)
{
	//一時的な追加です
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT)) {
		m_Scroll_Speed += 10;
	}

	//一時的な追加です
	if (g_pInput->IsKeyPush(MOFKEY_LEFT)) {
		m_Scroll_Speed -= 10;
	}

}





//描画
void CStage::Render(void) {


	//テクスチャの描画
	//乱数使ってるけど配列とかでもいいかも
	//同じテクスチャを繰り返しで画面端を超えるまで行う
	int h = m_BakTex[0].GetWidth();
	int sch = g_pGraphics->GetTargetWidth();

	//次の背景を用意
	if (m_BakScroll <= 0) {

		//右側で表示していたものと同じものを左側で表示
		m_RandamuBakLeft = m_RandamuBakRight;

		//一時保存
		m_RandamuBakRightSave = m_RandamuBakRight;

		//右側に次の背景番号を入れる
		m_RandamuBakRight = m_BakComposition[m_countbak];

		//0で停止した場合の背景バグの軽減
		//0で止まった,
		//最後の背景以外
		if (m_BakScroll == 0 && m_countbak < 30) {

			//保存したものを採用
			m_RandamuBakRight = m_RandamuBakRightSave;

		}
	}

	//背景スクロール値＝背景画像の横幅：だんだん減る
	//初期値X:背景スクロール値/背景横幅のあまり引く背景横幅 
	//条件	：Xが画面横幅よりも小さい場合
	//増加量：X＋＝背景横幅
	for (float x = ((int)m_BakScroll % h) - h; x < sch; x += h) {

		//消えていく画像
		if (x <= 0)
		{
			//最初と最後以外の中間を埋める背景
			m_BakTex[m_RandamuBakLeft].Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
		}
		else//出てくる画像
		{			
			//最初と最後以外の中間を埋める背景
			m_BakTex[m_RandamuBakRight].Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));		
		}
	}


	//足場描画
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].Render();
	}


	//障害物
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Render();
	}

	//ポイント描画
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Render();
	}

	//敵描画
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].Render();
	}


	//学年のカットイン
	m_GradeOneTexture.Render(0 + m_GradeOffset, 50);
	m_GradeTwoTexture.Render(0 + m_GradeOffset, 50);
	m_GradeThreeTexture.Render(0 + m_GradeOffset, 50);


	//進行度バー、進行度中アイコン、アイコンの表示
	m_BarTextuer.Render(270, 25);
	m_CharaProgressTextuer.Render(285 + m_BarProgress, 45);

	//todo表示
	m_DPDEcisionTexture.Render(0, 0);

}

//解放
void CStage::Release(void) {

	//進行度バー、進行度中アイコン、アイコンの解放
	m_BarTextuer.Release();
	m_CharaProgressTextuer.Release();
	m_CharaIconTexture.Release();
	//学年画像の開放
	m_GradeOneTexture.Release();
	m_GradeTwoTexture.Release();
	m_GradeThreeTexture.Release();

	//ステージ背景

	for (int i = 0; i < STAGE_BAKT_COUNT; i++)
	{
		m_BakTex[i].Release();
	}

	//DPテクスチャ
	for (int i = 0; i < DP_COUNT; i++)
	{
		m_DPTex[i].Release();
	}

	//障害物テクスチャ
	for (int i = 0; i < OB_COUNT; i++)
	{
		ob_Textuer[i].Release();
	}

	//足場テクスチャ
	bar_Textuer_Medium.Release();
	bar_Textuer_Big.Release();

	//敵テクスチャ
	ene_Texture_1.Release();

	//todo 解放
	m_DPDEcisionTexture.Release();
}

//デバック描画
void CStage::RenderDebugging() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "背景：%d枚目", m_countbak);
	//CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "背景スクロール値%f", m_BakScroll);
	//CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "ステージスクロール値%f", m_StageScroll);

	//全体のパターン表示
	for (int i = 0; i < SATAGE_MAP_PATTERN+1; i++)
	{
		CGraphicsUtilities::RenderString(40*i, 680, "%d", m_StageComposition[i]);
	}

	//障害物デバッグ表示
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].RenderDebugging();
	}

	//DPデバック表示
	for (int i = 0; i < OB_VOLUME; i++)
	{
		dp_array[i].RenderDebugging();
	}

	//足場描画
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].RenderDebugging();
	}

	//敵
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].RenderDebug();
	}


	CGraphicsUtilities::RenderLine(m_BakScroll,0, m_BakScroll,g_pGraphics->GetTargetHeight(), MOF_COLOR_BLUE);

#pragma region パターンデバッグ用

	CGraphicsUtilities::RenderString(40, 650, "%d", m_StageComposition[m_MapNo]);

	if (SP_flg) {
	CGraphicsUtilities::RenderString(40, 620, "SP：あり");

	}
	else
	{
		CGraphicsUtilities::RenderString(40, 620, "SP：なし");

	}
	
	CGraphicsUtilities::RenderString(40, 590, "%d", m_SPcountbak);

#pragma endregion

	//クリアフラグ表示
	if (m_bClear)
	{
		//CGraphicsUtilities::RenderString(500, 350, MOF_XRGB(255, 0, 0), "クリア!\nF1でリスタート");
	}

}

//マップパターン切り替え
void CStage::MapChange(void) {

	//スクロールが切り替わる時かつそれぞれのマップパターン情報で終端要素にたどり着いているなら
	if (m_StageScroll <= 0 &&
		s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Type >= BAR_COUNT &&
		s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Type == DP_COUNT &&
		s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type >= OB_COUNT&&
		s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Type >= ENEMY_COUNT)
	{
		//表示済みカウント初期化
		m_barcount = 0;
		m_dpcount = 0;
		m_obcount = 0;
		m_enecount = 0;

		//マップ番号を次に
		m_MapNo += 1;

		//最後のマップ足場パターン情報の場合
		if (m_MapNo >= 15)
		{
			m_MapNo = 15;
		}
	}
}

//足場生成
void CStage::OccurrenceBar(void) {


	//m_MapNo_Bar->マップパターン番号
	//m_obcount->表示済み足場数
	//マップパターン番号が用意している数以下のときかつ
	//スクロール値が出現値よりも小さくなった場合表示
	//スクロール値をプラスに変更しました
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Scroll)
	{

		//割り当てられていない足場クラスを探す
		for (int i = 0; i < BAR_VOLUME; i++)
		{
			//表示中ならスルー
			if (b_bar[i].Getshow()) {
				continue;
			}

			//表示テクスチャ準備
			//出現位置とタイプを渡す
			switch (s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Type)
			{

			case BAR_BIG:
				b_bar[i].SetTexture(&bar_Textuer_Big);
				break;

			case BAR_MEDIUM:
				b_bar[i].SetTexture(&bar_Textuer_Medium);
				break;
			default:
				break;
			}


			//表示準備
			//出現位置とタイプを渡す
			b_bar[i].Start(s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Pos_y,
				s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Type);
			break;
		}

		//表示済み足場を加算
		m_barcount++;
	}

}

//ディテールポイント生成
void CStage::OccurrenceDP(void) {


	//m_MapNo_DP->マップパターン番号
	//m_dpcount->表示済みDP数
	//マップDPパターン番号が用意している数以下のときかつ
	//スクロール値が出現値よりも小さくなった場合表示
	//スクロール値をプラスに変更しました
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Scroll)
	{

		//割り当てられていないDPクラスを探す
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//表示中ならスルー
			if (dp_array[i].Getshow()) {
				continue;
			}

			//初期化
			int type= DP_SCHOLASTIC;
			if (SP_flg && m_SPSitua == tag_StageSituation::STAGE_SP_STILL) {

				//SP中はDP選択画面に変換
				type = DP_Deci_Type;
			}
			else
			{
				//構成情報のタイプを参照
				type = s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Type;
			}

			

			//表示テクスチャ準備
			//出現位置とタイプを渡す
			dp_array[i].SetTexture(&m_DPTex[type]);
			if (SP_flg && m_SPSitua == tag_StageSituation::STAGE_SP_STILL) {

				//SP中はSPDPに変換
				type = DP_Deci_Type + 6;
			}

			//生成
			dp_array[i].Start(s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Pos_y, type);
			break;
		}

		//表示済みDPを加算
		m_dpcount++;

	}

}

//障害物OB生成
void CStage::OccurrenceOB(void) {

	//m_MapNo_OB->マップパターン番号
	//m_obcount->表示済みDP数
	//マップパターン番号が用意している数以下のときかつ
	//スクロール値が出現値よりも小さくなった場合表示
	//スクロール値をプラスに変更しました
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Scroll)
	{

		//割り当てられていないDPクラスを探す
		for (int i = 0; i < OB_VOLUME; i++)
		{
			//表示中ならスルー
			if (ob_array[i].Getshow()) {
				continue;
			}
			//表示テクスチャ準備
			//出現位置とタイプを渡す
			ob_array[i].SetTexture(&ob_Textuer[s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type]);


			//表示準備
			//出現位置とタイプを渡す
			ob_array[i].Start(s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Pos_y,
				s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type);
			break;
		}

		//表示済みDPを加算
		m_obcount++;

	}

}

//敵生成
void CStage::OccurrenceENE(void)
{
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Scroll)
	{

		//割り当てられていないENEクラスを探す
		for (int i = 0; i < ENEMY_VOLUME; i++)
		{
			//表示中ならスルー
			if (ene_array[i].Getshow()) {
				continue;
			}

			//表示テクスチャ準備
			ene_array[i].SetTexture(&ene_Texture_1);
			ene_array[i].SetAnime(&Enemy_Motion);
			ene_array[i].Start(s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Pos_y, s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Type);

			break;
		}

		//表示済みDPを加算
		m_enecount++;

	}
}

//ゲームスタート切り替え
void CStage::GameStopPlayChange()
{
	if (m_Startflg) {

		m_Startflg = false;
		m_Scroll_Speed = 0;

	}
	else
	{
		m_Startflg = true;
		m_Scroll_Speed = STAGE_SPEED1;
	}
}

//キャラが動いているか取得
bool CStage::GetGameStopPlay() {

	return m_Startflg;

}

//クリア判定の取得
bool CStage::GetClear(void) {
	return m_bClear;
}


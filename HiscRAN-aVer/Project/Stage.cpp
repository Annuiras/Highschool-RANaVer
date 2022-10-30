#pragma once
#include "Stage.h"
#include "ctime"
#include "string"


CStage::CStage() :

	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_Over(0.0f),
	m_countbak(0),
	m_BakStart(),
	m_SPBak(),
	m_dpinfo(),
	m_dpcount(0),
	m_barinfo(),
	m_barvolume(0),
	m_barcount(0),
	m_obinfo(),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f),
	m_spflg(false),
	m_gaku(0),
	m_sou(0),
	m_kou(0),
	m_komyu(0),
	m_miryoku(0),
	m_bClear(false),
	m_baklineX(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

	//背景画像の読み込み
	if (!m_BakStart.Load("廊下始まり.png")) {
		return false;
	}

	if (!m_BakRdoor.Load("右扉.png")) {
		return false;
	}

	if (!m_BakRwall.Load("右壁.png")) {
		return false;
	}

	if (!m_Bakldoor.Load("左扉.png")) {
		return false;
	}

	if (!m_Baklwall.Load("左壁.png")) {
		return false;
	}

	if (!m_BakStairs.Load("階段.png")) {
		return false;
	}

	if (!m_BakWindow.Load("二窓.png")) {
		return false;
	}

	if (!m_BakEnd.Load("廊下終わり.png")) {
		return false;
	}

	if (!m_SPBak.Load("SPbak.png")) {
		return false;
	}


	for (int i = 0; i < DP_VOLUME; i++)
	{
		if (!dp_array[i].Load()) {

			return false;
		}
	}

	return true;
}


//dpin:DP配置情報
//dpco:DP配置情報数
//barin:足場の配置情報
//barco:足場の情報数
//obin:障害物の配置情報
//obco:障害物の情報数
void CStage::Initialize(DP_info dpin[][DP_INFO_STRUCT], BAR_info barin[][BAR_INFO_STRUCT], OB_info obin[][OB_INFO_STRUCT]) {
	//スクロール値初期化
	m_BakScroll = 0.0f;

	//todo:ステージスクロール値初期化プラスの値に変更しました
	//todo:試作：０からスタート
	m_StageScroll = g_pGraphics->GetTargetWidth()*2;

	//背景カウント初期化
	m_countbak = 0;

	//todo:クリア用スクロール値初期化
	m_Scroll_Clear = 0;


	//todo:マップDPパターンランダムに初期化
	for (int y = 0; y < DP_INFO_PATTERN; y++)
	{
		m_StageDPConstitution[y] = RandmuBak.GetRandomNumbe(0, 14);
	}

	//todo:デバッグ用の指定コマンド、必要に応じていじってください
	m_StageDPConstitution[0] = 0;
	m_StageDPConstitution[1] = 1;
	m_StageDPConstitution[2] = 2;
	m_StageDPConstitution[3] = 3;
	m_StageDPConstitution[4] = 4;
	m_StageDPConstitution[5] = 5;
	m_StageDPConstitution[6] = 6;
	m_StageDPConstitution[7] = 7;
	m_StageDPConstitution[8] = 8;
	m_StageDPConstitution[9] = 9;
	m_StageDPConstitution[10] = 10;
	m_StageDPConstitution[11] = 11;
	m_StageDPConstitution[12] = 12;
	m_StageDPConstitution[13] = 13;
	m_StageDPConstitution[14] = 14;

	//todo:マップDPパターン添え字初期化
	m_MapNo_DP = 0;

	//todo:DP配置情報コピー引数で受け取る場合の処理なのでなくなる可能性あり
	//マップ一枚の情報分
	for (int y = 0; y < DP_INFO_PATTERN; y++)
	{
		//マップ一枚分の情報に構造体
		for (int x = 0; x < DP_INFO_STRUCT; x++) {


			m_dpinfo[y][x] = dpin[y][x];
		}
	}


	//todo:マップOBパターンランダムに初期化
	for (int y = 0; y < OB_INFO_PATTERN; y++)
	{
		m_StageOBConstitution[y] = RandmuBak.GetRandomNumbe(0, 14);
	}

	//todo:デバッグ用の指定コマンド、必要に応じていじってください
	m_StageOBConstitution[0] = 0;
	m_StageOBConstitution[1] = 1;
	m_StageOBConstitution[2] = 2;
	m_StageOBConstitution[3] = 3;
	m_StageOBConstitution[4] = 4;
	m_StageOBConstitution[5] = 5;
	m_StageOBConstitution[6] = 6;
	m_StageOBConstitution[7] = 7;
	m_StageOBConstitution[8] = 8;
	m_StageOBConstitution[9] = 9;
	m_StageOBConstitution[10] = 10;
	m_StageOBConstitution[11] = 11;
	m_StageOBConstitution[12] = 12;
	m_StageOBConstitution[13] = 13;
	m_StageOBConstitution[14] = 14;

	//todo:マップOBパターン添え字初期化
	m_MapNo_OB = 0;

	//障害物配置情報
	//todo:障害物配置情報コピー引数で受け取る場合の処理なのでなくなる可能性あり
	//マップ一枚の情報分
	for (int y = 0; y < OB_INFO_PATTERN; y++)
	{
		//マップ一枚分の情報に構造体
		for (int x = 0; x < OB_INFO_STRUCT; x++) {


			m_obinfo[y][x] = obin[y][x];
		}
	}


	//todo:マップ足場パターンランダムに初期化
	for (int y = 0; y < BAR_INFO_PATTERN; y++)
	{
		m_StageBarConstitution[y] = RandmuBak.GetRandomNumbe(0, 14);
	}

	//todo:デバッグ用の指定コマンド、必要に応じていじってください
	m_StageBarConstitution[0] = 0;
	m_StageBarConstitution[1] = 1;
	m_StageBarConstitution[2] = 2;
	m_StageBarConstitution[3] = 3;
	m_StageBarConstitution[4] = 4;
	m_StageBarConstitution[5] = 5;
	m_StageBarConstitution[6] = 6;
	m_StageBarConstitution[7] = 7;
	m_StageBarConstitution[8] = 8;
	m_StageBarConstitution[9] = 9;
	m_StageBarConstitution[10] = 10;
	m_StageBarConstitution[11] = 11;
	m_StageBarConstitution[12] = 12;
	m_StageBarConstitution[13] = 13;
	m_StageBarConstitution[14] = 14;

	//todo:マップOBパターン添え字初期化
	m_MapNo_Bar = 0;


	//todo:足場配置情報コピー引数で受け取る場合の処理なのでなくなる可能性あり
	//マップ一枚の情報分
	for (int y = 0; y < BAR_INFO_PATTERN; y++)
	{
		//マップ一枚分の情報に構造体
		for (int x = 0; x < BAR_INFO_STRUCT; x++) {

			m_barinfo[y][x] = barin[y][x];
		}
	}



	//表示済みカウント初期化
	m_barcount = 0;
	m_dpcount = 0;
	m_obcount = 0;

	//クリアフラグ初期化
	m_bClear = false;

	//背景用ランダム数値初期化
	m_RandamuBakLeft = RandmuBak.GetRandomNumbe(1, 6); 
	m_RandamuBakRight = 0;

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

	g_ground.Initialize();

}

//更新
//over:キャラクターのオーバー値
//plrect:プレイヤーの当たり判定矩形
//pl2:スキル；吸い寄せ範囲矩形
//suckingX,suckingY:プレイヤーのXY座標
void CStage::Update(float over, CRectangle plrect,CRectangle pl2, float suckingX, float suckingY) {

	//背景カウント
	if (m_BakScroll <= 0) {

		//初期化
		m_BakScroll = m_BakStart.GetWidth();

		//背景カウント
		m_countbak += 1;

		m_spflg = false;

		//SPフラグＯＮ
		if (m_countbak == 2) {
			m_spflg = true;
		}
	}


	//プレイヤーのオーバーした分だけ後ろに下げる
	m_BakScroll -= over;

	//todo:試作ステージ生成用スクロール値
	m_StageScroll += over;


	m_Scroll_Clear += over;

	//ステージスクロール値
	if (m_StageScroll >=g_pGraphics->GetTargetWidth()*2)
	{
		//todo:試作スクロール値リセット

		m_StageScroll = 0;

	}

	//足場生成
	OccurrenceBar();

	//ディテールポイント生成
	OccurrenceDP();

	//障害物OB生成
	OccurrenceOB();

	//足場
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].Update(over);
	}

	//DP
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Update(over);
	}

	//障害物
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Update(over);
	}

	//DPとの当たり判定
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//非表示の場合は判定しない
		if (!dp_array[i].Getshow()) {
			continue;
		}

		//DPと吸い込み判定矩形
		if (dp_array[i].CollosopnDP(pl2)) {

			dp_array[i].UpdateAtraction(suckingX, suckingY);
		}

		if (dp_array[i].CollosopnDP(plrect)) {
			//DPと接触した場合
			UPdeteCollisionDP(dp_array[i].Gettype());
			dp_array[i].Setshow(false);

		}
	}

	//todo:フラグを＋値に変更
	//クリアフラグ変更
	if (m_Scroll_Clear >= 38400||g_pInput->IsKeyPush(MOFKEY_0)) {

		m_bClear = true;

	}

}

//DPと当たった場合
void CStage::UPdeteCollisionDP(int dpt) {

	switch (dpt)
	{

	case 1:
		m_gaku += 1;
		if (m_gaku > 100) {
			m_gaku = 100;
		}
		break;

	case 2:
		m_kou += 1;
		if (m_kou > 100) {
			m_kou = 100;
		}
		break;

	case 3:
		m_sou += 1;
		if (m_sou > 100) {
			m_sou = 100;
		}
		break;

	case 4:
		m_komyu += 1;
		if (m_komyu > 100) {
			m_komyu = 100;
		}
		break;

	case 5:
		m_miryoku += 1;
		if (m_miryoku > 100) {
			m_miryoku = 100;
		}
		break;

	default:
		m_gaku = -100;
		break;
	}
}


//描画
void CStage::Render(void) {


	//テクスチャの描画
	//乱数使ってるけど配列とかでもいいかも
	//同じテクスチャを繰り返しで画面端を超えるまで行う
	int h = m_BakStart.GetWidth();
	int sch = g_pGraphics->GetTargetWidth();


	if (m_BakScroll <= 0) {
		
		//右側で表示していたものと同じものを左側で表示
		m_RandamuBakLeft = m_RandamuBakRight;

		//右側はランダムに数値を入れる
		m_RandamuBakRight = RandmuBak.GetRandomNumbe(1,6);

		//一番初めの背景
		if (m_countbak == 0) {
			m_RandamuBakLeft = 7;
		}

		//一番最後の背景
		if (m_countbak + 1 == 30 ) {
			m_RandamuBakRight = 8;
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
			switch (m_RandamuBakLeft)
			{

				case 1:
					m_BakRdoor.Render(x, 0.0f);
					break;

				case 2:
					m_BakRwall.Render(x, 0.0f);
					break;

				case 3:
					m_Bakldoor.Render(x, 0.0f);
					break;

				case 4:
					m_Baklwall.Render(x, 0.0f);
					break;

				case 5:
					m_BakWindow.Render(x, 0.0f);
					break;

				case 6:
					m_BakStairs.Render(x, 0.0f);
					break;

				case 7:
					m_BakStart.Render(x, 0.0f);
					break;

				case 8:
					m_BakEnd.Render(x, 0.0f);
					break;

				default:
					break;

			}

		}
		else//出てくる画像
		{
			
			//最初と最後以外の中間を埋める背景
			switch (m_RandamuBakRight)
			{

			case 1:
				m_BakRdoor.Render(x, 0.0f);
				break;

			case 2:
				m_BakRwall.Render(x, 0.0f);
				break;

			case 3:
				m_Bakldoor.Render(x, 0.0f);
				break;

			case 4:
				m_Baklwall.Render(x, 0.0f);
				break;

			case 5:
				m_BakWindow.Render(x, 0.0f);
				break;

			case 6:
				m_BakStairs.Render(x, 0.0f);
				break;

			case 8:
				m_BakEnd.Render(x, 0.0f);
				break;

			default:
				break;

			}

		}
	}

	//地面描画
	g_ground.Render();

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

}

//解放
void CStage::Release(void) {

	m_BakStart.Release();
	m_BakRdoor.Release();
	m_BakRwall.Release();
	m_Bakldoor.Release();
	m_Baklwall.Release();
	m_BakWindow.Release();
	m_BakStairs.Release();
	m_BakEnd.Release();
	m_SPBak.Release();

	//DPの解放
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Release();
	}
}

//デバック描画
void CStage::RenderDebugging() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "背景：%d枚目", m_countbak);
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "背景スクロール値%f", m_BakScroll);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "ステージスクロール値%f", m_StageScroll);
	CGraphicsUtilities::RenderString(880, 690, MOF_XRGB(80, 80, 80), "Pキーでフルスクリーンに切り替え");
	CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "このステージ内での取得数  学力：%d　行動力：%d　想像力：%d　コミュ力：%d　魅力：%d",
		m_gaku, m_kou, m_sou, m_komyu, m_miryoku);

	//地面デバック表示
	g_ground.RenderDebugging();


	//クリアフラグ表示
	if (m_bClear)
	{
		CGraphicsUtilities::RenderString(500, 350, MOF_XRGB(255, 0, 0), "クリア!\nF1でリスタート");
		CGraphicsUtilities::RenderString(0, 350, MOF_XRGB(80, 80, 80), "クリアフラグ:true");

	}
	else
	{
		CGraphicsUtilities::RenderString(0, 350, MOF_XRGB(80, 80, 80), "クリアフラグ:false");
	}


	CGraphicsUtilities::RenderLine(m_BakScroll,0, m_BakScroll,g_pGraphics->GetTargetHeight(), MOF_COLOR_BLUE);

	////todo:足場デバック表示
	////todo:足場マップパターン現在表示
	//CGraphicsUtilities::RenderString(0, 700, "マップ足場パターン:%d", m_StageBarConstitution[m_MapNo_Bar]);

	////todo:足場マップパターン全体表示
	//for (int i = 0; i < 15; i++)
	//{
	//	CGraphicsUtilities::RenderString(40 * i, 680, "%d", m_StageBarConstitution[i]);

	//}

	////todo:表示済み足場カウント
	//CGraphicsUtilities::RenderString(0, 650, "足場カウント%d", m_barcount);

	//todo：足場高さの対応
	//CGraphicsUtilities::RenderString(500, 50, MOF_XRGB(80, 80, 80), "50Yパターン10～14");
	//CGraphicsUtilities::RenderString(500, 250, MOF_XRGB(80, 80, 80), "250Yパターン5～9");
	//CGraphicsUtilities::RenderString(500, 450, MOF_XRGB(80, 80, 80), "450Yパターン0～4");



	////todo:OBデバック表示
	////todo:OBマップパターン現在表示
	//CGraphicsUtilities::RenderString(0, 700, "マップOBパターン:%d", m_StageOBConstitution[m_MapNo_OB]);

	////todo:OBマップパターン全体表示
	//for (int i = 0; i < 15; i++)
	//{
	//	CGraphicsUtilities::RenderString(40 * i, 680, "%d", m_StageOBConstitution[i]);

	//}

	////todo:表示済みOBカウント
	//CGraphicsUtilities::RenderString(0, 650, "OBカウント%d", m_obcount);

	////todo:色OB対応を表示
	//CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "1:椅子,    パターン0,3,6,9,12");
	//CGraphicsUtilities::RenderString(0, 430, MOF_XRGB(80, 80, 80), "2:黒板消し,パターン1,4,7,10,13");
	//CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "3:ボール,  パターン2,5,8,11,14");
	////CGraphicsUtilities::RenderString(0, 550, "m_Scroll_Clear%f", m_Scroll_Clear);


	////todo：OB高さの対応
	//CGraphicsUtilities::RenderString(500, 144, MOF_XRGB(80, 80, 80), "144Yパターン0～2");
	//CGraphicsUtilities::RenderString(500, 288, MOF_XRGB(80, 80, 80), "288Yパターン3～5");
	//CGraphicsUtilities::RenderString(500, 432, MOF_XRGB(80, 80, 80), "432Yパターン6～8");
	//CGraphicsUtilities::RenderString(500, 576, MOF_XRGB(80, 80, 80), "556Yパターン9～11");
	//CGraphicsUtilities::RenderString(500, 720, MOF_XRGB(80, 80, 80), "720Yパターン12～14");


	//todo:DPデバック表示
	//todo:DPマップパターン現在表示
	CGraphicsUtilities::RenderString(0, 700, MOF_XRGB(80, 80, 80), "マップDPパターン:%d", m_StageDPConstitution[m_MapNo_DP]);

	//todo:DPマップパターン全体表示
	for (int i = 0; i < 15; i++)
	{
		CGraphicsUtilities::RenderString(40 * i, 680, MOF_XRGB(80, 80, 80), "%d", m_StageDPConstitution[i]);

	}

	//todo:表示済みDPカウント
	CGraphicsUtilities::RenderString(0, 650, MOF_XRGB(80, 80, 80), "DPカウント%d", m_dpcount);

	//todo:色DP対応を表示
	CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(222, 184, 135), "1:学力,    パターン0,5,10");
	CGraphicsUtilities::RenderString(0, 430, MOF_COLOR_YELLOW, "2:行動力,  パターン1,6,11");
	CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(0, 191, 255), "3:想像力,  パターン2,7,12");
	CGraphicsUtilities::RenderString(0, 490, MOF_XRGB(255, 99, 71), "4:コミュ力,パターン3,8,13");
	CGraphicsUtilities::RenderString(0, 520, MOF_XRGB(186, 85, 211), "5:魅力,    パターン4,9,14");
	CGraphicsUtilities::RenderString(0, 550, MOF_XRGB(80, 80, 80), "m_Scroll_Clear%f", m_Scroll_Clear);


	////todo：DP高さの対応
	//CGraphicsUtilities::RenderString(500, 50, MOF_XRGB(80, 80, 80), "50Yパターン10～14");
	//CGraphicsUtilities::RenderString(500, 250, MOF_XRGB(80, 80, 80), "250Yパターン5～9");
	//CGraphicsUtilities::RenderString(500, 450, MOF_XRGB(80, 80, 80), "450Yパターン0～4");



}

//足場生成
void CStage::OccurrenceBar(void) {

	//todo:マップの足場情報が終端要素かどうか検出
	//todo:試作スクロール値の条件変更
	if (m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Type > 10 && m_StageScroll <= 0)
	{
		//マップOBパターンを変更
		m_barcount = 0;
		m_MapNo_Bar += 1;


		//最後のマップ足場パターン情報の場合
		if (m_MapNo_Bar >= BAR_INFO_PATTERN)
		{
			//todo:最後の場合最後まで描画した場合の処理
			//どうしようか悩み中
			m_MapNo_Bar = 0;
		}

	}


	//todo:処理を変更しました
	//m_MapNo_Bar->マップパターン番号
	//m_obcount->表示済み足場数
	//マップパターン番号が用意している数以下のときかつ
	//スクロール値が出現値よりも小さくなった場合表示
	//スクロール値をプラスに変更しました
	if (m_MapNo_Bar < BAR_INFO_PATTERN && m_StageScroll > m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Scroll)
	{

		//割り当てられていない足場クラスを探す
		for (int i = 0; i < BAR_VOLUME; i++)
		{
			//表示中ならスルー
			if (b_bar[i].Getshow()) {
				continue;
			}

			//表示準備
			//出現位置とタイプを渡す
			b_bar[i].Start(m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Pos_y,
				m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Type);
			break;
		}

		//表示済み足場を加算
		m_barcount++;

	}

}

//ディテールポイント生成
void CStage::OccurrenceDP(void) {

	//todo:マップのDP情報が終端要素かどうか検出
	//todo:試作スクロール値の条件変更
	if (m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Type > 10 && m_StageScroll <=0)
	{
		//マップパターンを変更
		m_dpcount = 0;
		m_MapNo_DP += 1;


		//最後のマップパターン情報の場合
		if (m_MapNo_DP >= DP_INFO_PATTERN)
		{
			//todo:最後の場合最後まで描画した場合の処理
			//どうしようか悩み中
			m_MapNo_DP = 0;
		}

	}

	//todo:処理を変更しました
	//m_MapNo_DP->マップパターン番号
	//m_dpcount->表示済みDP数
	//マップDPパターン番号が用意している数以下のときかつ
	//スクロール値が出現値よりも小さくなった場合表示
	//スクロール値をプラスに変更しました
	if (m_MapNo_DP < DP_INFO_PATTERN && m_StageScroll > m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Scroll)
	{

		//割り当てられていないDPクラスを探す
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//表示中ならスルー
			if (dp_array[i].Getshow()) {
				continue;
			}

			//表示準備
			//出現位置とタイプを渡す
			dp_array[i].Start(m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Pos_y, m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Type);
			break;
		}

		//表示済みDPを加算
		m_dpcount++;

	}

}

//障害物OB生成
void CStage::OccurrenceOB(void) {

	//todo:マップのOB情報が終端要素かどうか検出
	//todo:試作スクロール値の条件変更
	if (m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Type > 10 && m_StageScroll <= 0)
	{
		//マップOBパターンを変更
		m_obcount = 0;
		m_MapNo_OB += 1;


		//最後のマップOBパターン情報の場合
		if (m_MapNo_OB >= OB_INFO_PATTERN)
		{
			//todo:最後の場合最後まで描画した場合の処理
			//どうしようか悩み中
			m_MapNo_OB = 0;
		}

	}


	//todo:処理を変更しました
	//m_MapNo_OB->マップパターン番号
	//m_obcount->表示済みDP数
	//マップパターン番号が用意している数以下のときかつ
	//スクロール値が出現値よりも小さくなった場合表示
	//スクロール値をプラスに変更しました
	if (m_MapNo_OB < OB_INFO_PATTERN && m_StageScroll > m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Scroll)
	{

		//割り当てられていないDPクラスを探す
		for (int i = 0; i < OB_VOLUME; i++)
		{
			//表示中ならスルー
			if (ob_array[i].Getshow()) {
				continue;
			}

			//表示準備
			//出現位置とタイプを渡す
			ob_array[i].Start(m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Pos_y,
							m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Type);
			break;
		}

		//表示済みDPを加算
		m_obcount++;

	}

}
bool CStage::GetClear(void) {

	return m_bClear;

}


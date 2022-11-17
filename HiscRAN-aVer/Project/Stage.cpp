#pragma once
#include "Stage.h"
#include "ctime"
#include "string"


CStage::CStage() :

	m_countbak(0),
	m_BakStart(),
	m_SPBak(),
	m_dpinfo(),
	m_dpcount(0),
	m_barinfo(),
	m_barcount(0),
	m_obinfo(),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f),
	m_Scholastic(0),
	m_Imagination(0),
	m_Action(0),
	m_Communication(0),
	m_Charm(0),
	m_bClear(false),
	m_Scroll_Speed(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

#pragma region ステージ背景ロード

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


#pragma endregion

#pragma region DPテクスチャロード

	//仮テクスチャ：学力
	if (!dp_Textuer_Scholastic.Load("ハイスク　DP_0000_DP　学力.png")) {
		return false;
	}

	//仮テクスチャ：行動力
	if (!dp_Textuer_Action.Load("ハイスク　DP_0004_DP　行動力.png")) {
		return false;
	}

	//仮テクスチャ：想像力
	if (!dp_Textuer_Imagination.Load("ハイスク　DP_0003_DP　想像力.png")) {
		return false;
	}

	//仮テクスチャ：コミュ力
	if (!dp_Textuer_Communication.Load("ハイスク　DP_0001_DP　コミュ力.png")) {
		return false;
	}

	//仮テクスチャ：魅力
	if (!dp_Textuer_Charm.Load("ハイスク　DP_0002_DP-魅力.png")) {
		return false;
	}


#pragma endregion

#pragma region 障害物テクスチャロード

	//仮テクスチャ：机
	if (!ob_Textuer_Desk.Load("ハイスク素材２　障害物 机.png")) {
		return false;
	}

	//仮テクスチャ：２段机
	if (!ob_Textuer_TwoDesk.Load("ハイスク素材２　障害物 ２段机.png")) {
		return false;
	}

	//仮テクスチャ：ロッカー
	if (!ob_Textuer_Locker.Load("ハイスク素材２　障害物 ロッカー.png")) {
		return false;
	}


#pragma endregion

#pragma region 足場テクスチャロード

	//仮テクスチャ：足場中
	if (!bar_Textuer_Medium.Load("ハイスク_障害物_鉛筆_中.png")) {
		return false;
	}


#pragma endregion



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

	//ステージスクロール値初期化
	m_StageScroll = g_pGraphics->GetTargetWidth()*2;

	//背景カウント初期化
	m_countbak = 0;


	//マップパターンをランダム化
	for (int i = 0; i < 15; i++)
	{
		m_StageConstitution[i] = RandmuBak.GetRandomNumbe(0, 0);
	}

	//マップパターン添え字
	m_MapNo = 0;

	//初期化
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		AlreadyUsedArray[i] = 0;
	}


	//低確率で同じステージが選択されてしまうため試行回数は多め
	for (int z = 1; z < 100; z++)
	{
		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (AlreadyUsedArray[x] == 1)
			{
				//どこまで採用済みかカウント
				AdoptCount += 1;
			}
		}
		//todo ランダムパターンをセット
		int randam= RandmuBak.GetRandomNumbe(0, 14);

		//まだ使用していない場合のみ採用(1=使用済み)
		if (AlreadyUsedArray[randam] == 0)
		{
			//採用
			m_StageConstitution[AdoptCount] = randam;

			//使用したパターンの場所に１をセット
			AlreadyUsedArray[randam] = 1;
		}			
		//採用済カウント
		AdoptCount = 0;
	}

	//デバッグ用の指定コマンド、必要に応じていじってください
	m_StageConstitution[0] = 0;
	m_StageConstitution[1] = 1;
	m_StageConstitution[2] = 2;
	m_StageConstitution[3] = 1;
	m_StageConstitution[4] = 0;
	m_StageConstitution[5] = 2;
	m_StageConstitution[6] = 2;
	m_StageConstitution[7] = 1;
	m_StageConstitution[8] = 0;
	m_StageConstitution[9] = 1;
	m_StageConstitution[10] = 1;
	m_StageConstitution[11] = 0;
	m_StageConstitution[12] = 0;
	m_StageConstitution[13] = 2;
	m_StageConstitution[14] = 2;


	//DP配置情報コピー,
	//マップ一枚の情報分

	for (int y = 0; y < MAP_INFO_PATTERN; y++)
	{
		//マップ一枚分の情報に構造体
		for (int x = 0; x < DP_INFO_STRUCT; x++) {


			m_dpinfo[y][x] = dpin[y][x];
		}
	}

	//障害物配置情報コピー
	//マップ一枚の情報分
	for (int y = 0; y < MAP_INFO_PATTERN; y++)
	{
		//マップ一枚分の情報に構造体
		for (int x = 0; x < OB_INFO_STRUCT; x++) {


			m_obinfo[y][x] = obin[y][x];
		}
	}

	//足場配置情報コピー
	//マップ一枚の情報分
	for (int y = 0; y < MAP_INFO_PATTERN; y++)
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

	//ステージスクロール速度
	m_Scroll_Speed = 0;

	//開始フラグ
	m_Startflg = false;


	//ステータスを初期化
	m_Scholastic = 0;
	m_Action = 0;
	m_Imagination = 0;
	m_Communication = 0;
	m_Charm = 0;


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
void CStage::Update(CRectangle plrect,CRectangle pl2, float suckingX, float suckingY) {


	//背景カウント
	if (m_BakScroll <= 0) {

		//初期化
		m_BakScroll = m_BakStart.GetWidth();

		//背景カウント
		m_countbak += 1;

	}

	//一時的な追加です
	if (g_pInput->IsKeyHold(MOFKEY_RIGHT)) {
		m_Scroll_Speed +=10;
	}

	//一時的な追加です
	if (g_pInput->IsKeyHold(MOFKEY_LEFT)) {
		m_Scroll_Speed -= 10;
	}


	//プレイヤーのオーバーした分だけ後ろに下げる
	m_BakScroll -= m_Scroll_Speed;

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

	//足場生成
	OccurrenceBar();

	//ディテールポイント生成
	OccurrenceDP();

	//障害物OB生成
	OccurrenceOB();

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

	//クリアフラグ変更
	if (m_countbak + 1 == 33) {
		m_bClear = true;
	}

}

//DPと当たった場合
void CStage::UPdeteCollisionDP(int dpt) {

	switch (dpt)
	{

	case DP_SCHOLASTIC:
		m_Scholastic += 1;
		if (m_Scholastic > 100) {
			m_Scholastic = 100;
		}
		break;

	case DP_ACTION:
		m_Action += 1;
		if (m_Action > 100) {
			m_Action = 100;
		}
		break;

	case DP_IMAGINATION:
		m_Imagination += 1;
		if (m_Imagination > 100) {
			m_Imagination = 100;
		}
		break;

	case DP_COMMUNICATION:
		m_Communication += 1;
		if (m_Communication > 100) {
			m_Communication = 100;
		}
		break;

	case DP_CHARM:
		m_Charm += 1;
		if (m_Charm > 100) {
			m_Charm = 100;
		}
		break;
	default:
		m_Scholastic = -100;
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
		if (m_countbak + 1 == 31 ) {
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

	CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "このステージ内での取得数  学力：%d　行動力：%d　想像力：%d　コミュ力：%d　魅力：%d",
		m_Scholastic, m_Action, m_Imagination, m_Communication, m_Charm);

	//クリアフラグ表示
	if (m_bClear)
	{
		CGraphicsUtilities::RenderString(500, 350, MOF_XRGB(255, 0, 0), "クリア!\nF1でリスタート");
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

	dp_Textuer_Scholastic.Release();
	dp_Textuer_Action.Release();
	dp_Textuer_Imagination.Release();
	dp_Textuer_Communication.Release();
	dp_Textuer_Charm.Release();

	ob_Textuer_Desk.Release();
	ob_Textuer_TwoDesk.Release();
	ob_Textuer_Locker.Release();

	bar_Textuer_Medium.Release();

}

//デバック描画
void CStage::RenderDebugging() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "背景：%d枚目", m_countbak);
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "背景スクロール値%f", m_BakScroll);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "ステージスクロール値%f", m_StageScroll);
	CGraphicsUtilities::RenderString(880, 690, MOF_XRGB(80, 80, 80), "Pキーでフルスクリーンに切り替え");

	//全体のパターン表示
	for (int i = 0; i < 15; i++)
	{
		CGraphicsUtilities::RenderString(40*i, 680, "%d", m_StageConstitution[i]);
	}

	//地面デバック表示
	g_ground.RenderDebugging();

	//障害物デバッグ表示
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].RenderDebugging();
	}

	for (int i = 0; i < OB_VOLUME; i++)
	{
		dp_array[i].RenderDebugging();
	}


	CGraphicsUtilities::RenderLine(m_BakScroll,0, m_BakScroll,g_pGraphics->GetTargetHeight(), MOF_COLOR_BLUE);

#pragma region パターンデバッグ用

	CGraphicsUtilities::RenderString(40, 650, "%d", m_StageConstitution[m_MapNo]);

#pragma endregion

}

//マップパターン切り替え
void CStage::MapChange(void) {

	//スクロールが切り替わる時かつそれぞれのマップパターン情報で終端要素にたどり着いているなら
	if (m_StageScroll <= 0 &&
		m_barinfo[m_StageConstitution[m_MapNo]][m_barcount].Type > 10 &&
		m_dpinfo[m_StageConstitution[m_MapNo]][m_dpcount].Type > 10 &&
		m_obinfo[m_StageConstitution[m_MapNo]][m_obcount].Type > 10) 
	{
		m_barcount = 0;
		m_dpcount = 0;
		m_obcount = 0;

		m_MapNo += 1;

		//todo:最初の要素が終端要素のみの場合 
		//連続で切り替わってしまうのを防止（0の時しか使えない）
		//一番最初のマップパターンがスキップされてしまう
		//m_StageScroll++;

		//最後のマップ足場パターン情報の場合
		if (m_MapNo >= 15)
		{
			//todo:最後の場合最後まで描画した場合の処理
			//どうしようか悩み中
			m_MapNo = 100;
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
	if (m_MapNo < MAP_INFO_PATTERN && m_StageScroll > m_barinfo[m_StageConstitution[m_MapNo]][m_barcount].Scroll)
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
			switch (m_barinfo[m_StageConstitution[m_MapNo]][m_barcount].Type)
			{

			case BAR_MEDIUM:
				b_bar[i].SetTexture(&bar_Textuer_Medium);
				break;

			//case BAR_MEDIUM:
			//	break;

			//case BAR_SMALL:
			//	break;

			default:
				break;
			}


			//表示準備
			//出現位置とタイプを渡す
			b_bar[i].Start(m_barinfo[m_StageConstitution[m_MapNo]][m_barcount].Pos_y,
				m_barinfo[m_StageConstitution[m_MapNo]][m_barcount].Type);
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
	if (m_MapNo < MAP_INFO_PATTERN && m_StageScroll > m_dpinfo[m_StageConstitution[m_MapNo]][m_dpcount].Scroll)
	{

		//割り当てられていないDPクラスを探す
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//表示中ならスルー
			if (dp_array[i].Getshow()) {
				continue;
			}

			//表示テクスチャ準備
			//出現位置とタイプを渡す
			switch (m_dpinfo[m_StageConstitution[m_MapNo]][m_dpcount].Type)
			{

			case DP_SCHOLASTIC:
				dp_array[i].SetTexture(&dp_Textuer_Scholastic);
				break;

			case DP_ACTION:
				dp_array[i].SetTexture(&dp_Textuer_Action);
				break;

			case DP_IMAGINATION:
				dp_array[i].SetTexture(&dp_Textuer_Imagination);
				break;

			case DP_COMMUNICATION:
				dp_array[i].SetTexture(&dp_Textuer_Communication);
				break;

			case DP_CHARM:
				dp_array[i].SetTexture(&dp_Textuer_Charm);
				break;

			default:
				break;
			}
			dp_array[i].Start(m_dpinfo[m_StageConstitution[m_MapNo]][m_dpcount].Pos_y, m_dpinfo[m_StageConstitution[m_MapNo]][m_dpcount].Type);
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
	if (m_MapNo < MAP_INFO_PATTERN && m_StageScroll > m_obinfo[m_StageConstitution[m_MapNo]][m_obcount].Scroll)
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
			switch (m_obinfo[m_StageConstitution[m_MapNo]][m_obcount].Type)
			{

			case OB_DESK:
				ob_array[i].SetTexture(&ob_Textuer_Desk);
				break;

			case OB_TWODESK:
 				ob_array[i].SetTexture(&ob_Textuer_TwoDesk);
				break;

			case OB_LOCKER:
				ob_array[i].SetTexture(&ob_Textuer_Locker);
				break;

			default:
				break;
			}


			//表示準備
			//出現位置とタイプを渡す
			ob_array[i].Start(m_obinfo[m_StageConstitution[m_MapNo]][m_obcount].Pos_y,
				m_obinfo[m_StageConstitution[m_MapNo]][m_obcount].Type);
			break;
		}

		//表示済みDPを加算
		m_obcount++;

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
		m_Scroll_Speed = STAGE_SPEED;
	}
}

//キャラが動いているか取得
bool CStage::GetGameStopPlay() {

	return m_Startflg;

}

bool CStage::GetClear(void) {

	return m_bClear;

}


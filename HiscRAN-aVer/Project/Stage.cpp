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
	m_BakAVal(0),
	m_Scholastic(0),
	m_Imagination(0),
	m_Action(0),
	m_AdoptCount(0),
	m_AlreadyUsedArray(),
	m_Communication(0),
	m_Charm(0),
	m_bClear(false),
	m_Scroll_Speed(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

#pragma region ステージ背景ロード

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game/StageBak");

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

	if (!m_SPBak.Load("スプライト-0001.png")) {
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../../");

#pragma endregion

#pragma region DPテクスチャロード

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game/DetailPoint");

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

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../../");

#pragma endregion

#pragma region 障害物テクスチャロード

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game/Obstacle");

	//テクスチャ：机
	if (!ob_Textuer_Desk.Load("ハイスク素材２　障害物 机.png")) {
		return false;
	}

	//:同じ当たり判定の画像違いを作成する
	////仮テクスチャ：２段机
	//if (!ob_Textuer_TwoDesk.Load("ハイスク素材２　障害物 ２段机.png")) {
	//	return false;
	//}
	if (!ob_Textuer_TwoDesk.Load("ハイスク_障害物_ゴミ箱.png")) {
		return false;
	}

	//テクスチャ：ごみ箱
	if (!ob_Textuer_TrachCan.Load("ハイスク_障害物_ゴミ箱.png")) {
		return false;
	}

	//テクスチャ：ロッカー
	if (!ob_Textuer_Locker.Load("ハイスク素材２　障害物 ロッカー.png")) {
		return false;
	}

	//テクスチャ：教科書_理科
	if (!ob_Textuer_TextBookChem.Load("ハイスク_障害物_理科.png")) {
		return false;
	}

	//テクスチャ：跳び箱
	if (!ob_Textuer_VaultingHorse.Load("ハイスク_障害物＿跳び箱.png")) {
		return false;
	}

	//テクスチャ：セロハンテープ
	if (!ob_Textuer_ScotchTape.Load("ハイスク_障害物_セロハンテープ.png")) {
		return false;
	}

	//テクスチャ：黒板消し
	if (!ob_Textuer_BloackboardEraser.Load("ハイスク_障害物_黒板けし.png")) {
		return false;
	}



	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../../");

#pragma endregion

#pragma region 足場テクスチャロード

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game/Bar");

	//仮テクスチャ：足場中
	if (!bar_Textuer_Medium.Load("ハイスク_障害物_鉛筆_中.png")) {
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../../");

#pragma endregion

#pragma region 敵

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Game/Enemy");

	//todo 仮テクスチャ : 敵1
	if (!ene_Texture_1.Load("Enemy1.png"))
	{
		return false;
	}
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../../");

#pragma endregion

		return true;
}

//dpin:DP配置情報
//dpco:DP配置情報数
//barin:足場の配置情報
//barco:足場の情報数
//obin:障害物の配置情報
//obco:障害物の情報数
void CStage::Initialize(DP_info dpin[][DP_INFO_STRUCT], BAR_info barin[][BAR_INFO_STRUCT], OB_info obin[][OB_INFO_STRUCT], ENEMY_info enein[][ENEMY_INFO_STRUCT]) {

	//スクロール値初期化
	m_BakScroll = 0.0f;

	//ステージスクロール値初期化
	m_StageScroll = g_pGraphics->GetTargetWidth()*2;

	//背景カウント初期化
	m_countbak = -1;

	//α値初期化
	m_BakAVal = 255;

	//ステージ変化フラグ
	v_StageChangeflg = false;		

	//SPステージ状態用
	m_SPSitua = tag_StageSituation::STAGE_SP_YET;
	//SP背景カウント
	m_SPcountbak = 0;
	//SPのaフラグ
	m_SPflg = false;		


	//マップパターンをランダム化
	for (int i = 0; i < 15; i++)
	{
		m_StageComposition[i] = RandmuBak.GetRandomNumbe(0, 0);
	}

	//マップパターン添え字
	m_MapNo = 0;


	//初期化
	m_AdoptCount = 0;

	//低確率で同じステージが選択されてしまうため試行回数は多め
	for (int z = 1; z < 100; z++)
	{
		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (m_AlreadyUsedArray[x] == 1)
			{
				//どこまで採用済みかカウント
				m_AdoptCount += 1;
			}
		}
		//ランダムパターンをセット
		int randam= RandmuBak.GetRandomNumbe(0, 14);

		//まだ使用していない場合のみ採用(1=使用済み)
		if (m_AlreadyUsedArray[randam] == 0)
		{
			//採用
			m_StageComposition[m_AdoptCount] = randam;

			//SPアイテムがあるマップを採用
			if (m_AdoptCount == MAP_SP_ITEM_PATTERN_NUM)
			{
				//15:SPアイテムがあるマップ
				m_StageComposition[m_AdoptCount] = 15;
				//使用したパターンの場所に１をセット
				m_AlreadyUsedArray[15] = 1;
			}

			//使用したパターンの場所に１をセット
			m_AlreadyUsedArray[randam] = 1;
		}			
		//採用済カウント
		m_AdoptCount = 0;
	}

	//初期化
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		m_AlreadyUsedArray[i] = 0;
	}


	//デバッグ用の指定コマンド、必要に応じていじってください
	m_StageComposition[0] = 0;
	//m_StageComposition[1] = 1;
	//m_StageComposition[2] = 2;
	//m_StageComposition[3] = 1;
	//m_StageComposition[4] = 0;
	//m_StageComposition[5] = 2;
	//m_StageComposition[6] = 2;
	//m_StageComposition[7] = 1;
	//m_StageComposition[8] = 0;
	//m_StageComposition[9] = 1;
	//m_StageComposition[10] = 1;
	//m_StageComposition[11] = 0;
	//m_StageComposition[12] = 0;
	//m_StageComposition[13] = 2;
	//m_StageComposition[14] = 2;


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

	//todo 敵配置情報コピー
	for (int y = 0; y < MAP_INFO_PATTERN; y++)
	{
		//マップ一枚分の情報に構造体
		for (int x = 0; x < ENEMY_INFO_STRUCT; x++)
		{
			m_eneinfo[y][x] = enein[y][x];
		}
	}


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

	//todo 敵
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		//初期化
		ene_array[i].Initialize();
	}

	g_ground.Initialize();

}

//SP内のステージをセット配置
void CStage::SPInitialize(void)
{
	//上のステージ内のDP配置と同じ処理
	for (int z = 1; z < 100; z++)
	{
		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (m_AlreadyUsedArray[x] == 1)
			{
				//どこまで採用済みかカウント
				m_AdoptCount += 1;
			}
		}
		//SP内のDP用の処理  SP内のDP配置は2枚分だけ
		int randam = RandmuBak.GetRandomNumbe(16, 17);

		//未採用だった場合
		if (m_AlreadyUsedArray[randam] == 0)
		{
			//SPの出現位置に合わせてSPステージ枚数分ずらしてます
			m_StageComposition[m_AdoptCount + MAP_SP_ITEM_PATTERN_NUM + 1] = randam;
			//使用したパターンの場所に１をセット
			m_AlreadyUsedArray[randam] = 1;
		}
		//採用済カウント
		m_AdoptCount = 0;
	}

	//初期化
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		m_AlreadyUsedArray[i] = 0;
	}

}

//更新
//plrect:プレイヤーの当たり判定矩形
void CStage::Update(CRectangle plrect) {


	//背景カウント
	if (m_BakScroll <= 0) {

		//初期化
		m_BakScroll = m_BakStart.GetWidth();

		//背景カウント
		m_countbak += 1;

	}

	//一時的な追加です
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT)) {
		m_Scroll_Speed +=10;
	}

	//一時的な追加です
	if (g_pInput->IsKeyPush(MOFKEY_LEFT)) {
		m_Scroll_Speed -= 10;
	}


	//後ろに下げる
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

	//todo 敵生成
	OccurrenceENE();

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
	
	//todo 敵更新
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].Update(m_Scroll_Speed);
	}

	//DPとの当たり判定
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//非表示の場合は判定しない
		if (!dp_array[i].Getshow()) {
			continue;
		}

		if (dp_array[i].CollosopnDP(plrect)) {
			//DPと接触した場合
			UPdeteCollisionDP(dp_array[i].Gettype());
			dp_array[i].Setshow(false);

		}

	}

	//ステージ変化
	if (m_countbak == SATGE_CHANGE_BAK) {

		//フェードアウト済フラグ
		if (!v_StageChangeflg) {
			//フェードアウト
			m_BakAVal -= 5;
			if (m_BakAVal <= 0) {
				//変化済
				v_StageChangeflg = true;
			}

		}
		else if (m_BakAVal < 255)
		{
			//フェードイン
			m_BakAVal += 5;

		}
	}

	//SP開始直後の処理 
	if (m_SPSitua == tag_StageSituation::STAGE_SP_START)
	{
		//フェードアウト
		if (m_BakAVal > 0 && !m_SPflg)
		{
			m_BakAVal -= 5;

		}
		//フェードイン
		else if (m_BakAVal < 255)
		{
			//α値増加
			m_BakAVal += 5;

			//両背景セット
			m_RandamuBakRight = 9;
			m_RandamuBakLeft = m_RandamuBakRight;

			//もう一回フェードアウトしないためにflgをfalseに
			m_SPflg = true;	
		}
		else
		{
			//状態移行
			m_SPSitua = tag_StageSituation::STAGE_SP_STILL;
		}
		
	}
	//SP中の処理
	else if (m_SPSitua == tag_StageSituation::STAGE_SP_STILL)
	{
		//SPの背景カウント
		if (m_BakScroll <= 0)
		{
			//SP背景カウント
			m_SPcountbak += 1;
		}
		//SP背景カウント
		else if (m_SPcountbak == 4)
		{
			m_SPSitua = tag_StageSituation::STAGE_SP_IMMEDIATELY;
			m_SPflg = false;
		}

	}
	//SPが終了した直後の処理
	else if (m_SPSitua == tag_StageSituation::STAGE_SP_IMMEDIATELY)
	{
		//フェードアウト
		if (m_BakAVal > 0 && !m_SPflg)
		{
			m_BakAVal -= 5;
		}
		//フェードイン
		else if (m_BakAVal < 255)
		{
			m_RandamuBakRight = 1;//本当はランダムにしたいけど、ランダムにすると描画バグるので1代入
			m_RandamuBakLeft = m_RandamuBakRight;	//左も同時に描画
			m_BakAVal += 5;
			m_SPflg = true;		//flgをtrueにすることでフェードアウトしないようにする
		}
		if (m_BakAVal >= 255)
		{
			m_SPSitua = tag_StageSituation::STAGE_SP_ALREADY;	//フェードインしたタイミングで、SP終了
		}

	}


	//クリアフラグ変更
	if (m_countbak  == 31) {
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

		//エフェクト再生
		m_pEffectMgmt->Start(0, 0, EFC_GET_DP);
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
		//SPアイテム取得時、カウントスタート
	case DP_SP_ITEM:
		m_SPSitua = tag_StageSituation::STAGE_SP_START;
		//SP内のステージに変更
		SPInitialize();		
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

	//次の背景を用意
	if (m_BakScroll <= 0) {
		
		//右側で表示していたものと同じものを左側で表示
		m_RandamuBakLeft = m_RandamuBakRight;

		//右側はランダムに数値を入れる
		m_RandamuBakRight = RandmuBak.GetRandomNumbe(1,6);

		//一番初めの背景
		if (m_countbak == -1) {
			m_RandamuBakLeft = 7;
		}

		//クリア時に一番最後の背景が表示されているように早めにセット
		if (m_countbak == STAGE_CLEAR_BAK-2) {
  			m_RandamuBakRight = 8;
		}

	}

	//SP中の処理
	if (m_SPSitua == tag_StageSituation::STAGE_SP_STILL) {

		//フェードインした後に描画される用にするための処理
		m_RandamuBakRight = 9;
		m_RandamuBakLeft = m_RandamuBakRight;
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
					m_BakRdoor.Render(x, 0.0f,MOF_ARGB(m_BakAVal,255,255,255));
					break;

				case 2:
					m_BakRwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 3:
					m_Bakldoor.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 4:
					m_Baklwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 5:
					m_BakWindow.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 6:
					m_BakStairs.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 7:
					m_BakStart.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 8:
					m_BakEnd.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 9:
					m_SPBak.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
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
				m_BakRdoor.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 2:
				m_BakRwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 3:
				m_Bakldoor.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 4:
				m_Baklwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 5:
				m_BakWindow.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 6:
				m_BakStairs.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 8:
				m_BakEnd.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 9:
				m_SPBak.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
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

	//todo 敵描画
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].Render();
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
	ob_Textuer_TrachCan.Release();
	ob_Textuer_Locker.Release();
	ob_Textuer_TextBookChem.Release();
	ob_Textuer_VaultingHorse.Release();
	ob_Textuer_ScotchTape.Release();
	ob_Textuer_BloackboardEraser.Release();

	bar_Textuer_Medium.Release();

	//todo 敵
	ene_Texture_1.Release();
	ene_Texture_2.Release();

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
		CGraphicsUtilities::RenderString(40*i, 680, "%d", m_StageComposition[i]);
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


	//足場描画
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].RenderDebugging();
	}

	//todo 敵
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].RenderDebug();
	}


	CGraphicsUtilities::RenderLine(m_BakScroll,0, m_BakScroll,g_pGraphics->GetTargetHeight(), MOF_COLOR_BLUE);

#pragma region パターンデバッグ用

	CGraphicsUtilities::RenderString(40, 650, "%d", m_StageComposition[m_MapNo]);

#pragma endregion

}

//マップパターン切り替え
void CStage::MapChange(void) {

	//スクロールが切り替わる時かつそれぞれのマップパターン情報で終端要素にたどり着いているなら
	if (m_StageScroll <= 0 &&
		m_barinfo[m_StageComposition[m_MapNo]][m_barcount].Type >= BAR_COUNT &&
		m_dpinfo[m_StageComposition[m_MapNo]][m_dpcount].Type >= DP_COUNT &&
		m_obinfo[m_StageComposition[m_MapNo]][m_obcount].Type >= OB_COUNT&&
		m_eneinfo[m_StageComposition[m_MapNo]][m_enecount].Type >= ENEMY_COUNT)
	{
		m_barcount = 0;
		m_dpcount = 0;
		m_obcount = 0;
		m_enecount = 0;
		m_MapNo += 1;


		//最後のマップ足場パターン情報の場合
		if (m_MapNo >= 15)
		{
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
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > m_barinfo[m_StageComposition[m_MapNo]][m_barcount].Scroll)
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
			switch (m_barinfo[m_StageComposition[m_MapNo]][m_barcount].Type)
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
			b_bar[i].Start(m_barinfo[m_StageComposition[m_MapNo]][m_barcount].Pos_y,
				m_barinfo[m_StageComposition[m_MapNo]][m_barcount].Type);
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
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > m_dpinfo[m_StageComposition[m_MapNo]][m_dpcount].Scroll)
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
			switch (m_dpinfo[m_StageComposition[m_MapNo]][m_dpcount].Type)
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
			dp_array[i].Start(m_dpinfo[m_StageComposition[m_MapNo]][m_dpcount].Pos_y, m_dpinfo[m_StageComposition[m_MapNo]][m_dpcount].Type);
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
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > m_obinfo[m_StageComposition[m_MapNo]][m_obcount].Scroll)
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
			switch (m_obinfo[m_StageComposition[m_MapNo]][m_obcount].Type)
			{

			case OB_DESK:
				ob_array[i].SetTexture(&ob_Textuer_Desk);
				break;

			case OB_TWODESK:
 				ob_array[i].SetTexture(&ob_Textuer_TwoDesk);
				break;

			case OB_TRACHCAN:
				ob_array[i].SetTexture(&ob_Textuer_TrachCan);
				break;

			case OB_LOCKER:
				ob_array[i].SetTexture(&ob_Textuer_Locker);
				break;

			case OB_TEXTBOOKCHEM:
				ob_array[i].SetTexture(&ob_Textuer_TextBookChem);
				break;

			case OB_VAULTINGHORSE:
				ob_array[i].SetTexture(&ob_Textuer_VaultingHorse);
				break;

			case OB_SCOTCHTAPE:
				ob_array[i].SetTexture(&ob_Textuer_ScotchTape);
				break;

			case OB_BLOACKBOARDERASER:
				ob_array[i].SetTexture(&ob_Textuer_BloackboardEraser);
				break;

			default:
				break;
			}


			//表示準備
			//出現位置とタイプを渡す
			ob_array[i].Start(m_obinfo[m_StageComposition[m_MapNo]][m_obcount].Pos_y,
				m_obinfo[m_StageComposition[m_MapNo]][m_obcount].Type);
			break;
		}

		//表示済みDPを加算
		m_obcount++;

	}

}

//todo 敵生成
void CStage::OccurrenceENE(void)
{
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > m_eneinfo[m_StageComposition[m_MapNo]][m_enecount].Scroll)
	{

		//割り当てられていないDPクラスを探す
		for (int i = 0; i < ENEMY_VOLUME; i++)
		{
			//表示中ならスルー
			if (ene_array[i].Getshow()) {
				continue;
			}

			//表示テクスチャ準備
			//出現位置とタイプを渡す
			switch (m_eneinfo[m_StageComposition[m_MapNo]][m_enecount].Type)
			{

			case ENEMY_1:
				ene_array[i].SetTexture(&ene_Texture_1);
				break;

				/*case ENEMY_2:
					ene_array[i].SetTexture(&ene_Texture_2);
					break;*/

			default:
				break;
			}

			ene_array[i].Start(m_eneinfo[m_StageComposition[m_MapNo]][m_enecount].Pos_y, m_eneinfo[m_StageComposition[m_MapNo]][m_enecount].Type);
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


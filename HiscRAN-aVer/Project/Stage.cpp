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
	m_Bak(),
	m_SPBak(),
	m_dpinfo(NULL),
	m_dpvolume(0),
	m_dpcount(0),
	m_barinfo(NULL),
	m_barvolume(0),
	m_barcount(0),
	m_obinfo(NULL),
	m_obvolume(0),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f),
	m_spflg(false),
	m_bClear(false)
{}

CStage::~CStage() {

}

bool CStage::Load() {

	//背景画像の読み込み
	if (!m_Bak.Load("rouka3-k.png")) {
		return false;
	}

	if (!m_SPBak.Load("SPbak.png")) {
		return false;
	}

	return true;
}


//dpin:DP配置情報
//dpco:DP配置情報数
//barin:足場の配置情報
//barco:足場の情報数
//obin:障害物の配置情報
//obco:障害物の情報数
void CStage::Initialize(DP_info* dpin, int dpco, BAR_info* barin, int barco, OB_info* obin, int obco) {
	//スクロール値初期化
	m_BakScroll = 0.0f;
	m_StageScroll = 0.0f;

	m_countbak = 0;

	//DP配置情報
	m_dpinfo = dpin;

	//DP配置情報数
	m_dpvolume = dpco;


	//足場配置情報
	m_barinfo = barin;

	//足場配置情報数
	m_barvolume = barco;


	//障害物配置情報
	m_obinfo = obin;

	//障害物配置情報数
	m_obvolume = obco;

	m_barcount = 0;
	m_dpcount = 0;
	m_obcount = 0;

	//クリアフラグ初期化
	m_bClear = false;

	//足場
	for (int i = 0; i < BAR_MAX; i++)
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
//
void CStage::Update(float over, CRectangle plrect) {


	//プレイヤーのオーバーした分だけ後ろに下げる
	m_BakScroll -= over;
	m_StageScroll -= over;


	//背景カウント
	if (m_BakScroll <= 0) {
		m_BakScroll = m_Bak.GetWidth();
		m_countbak += 1;

		m_spflg = false;

		//SPフラグＯＮ
		if (m_countbak == 2) {
			m_spflg = true;
		}

	}

	//表示済み足場数が足場情報数以下でスクロールが出現位置よりも小さくなったら
	//※m_StageScrollはマイナス値です
	if (m_barcount < m_barvolume && m_StageScroll < m_barinfo[m_barcount].Scroll)
	{
		for (int i = 0; i < BAR_MAX; i++)
		{
			//表示中ならスルー
			if (b_bar[i].Getshow()) {
				continue;
			}

			//表示準備
			b_bar[i].Start(m_barinfo[m_barcount].Pos_y);
			break;
		}

		//表示済み足場を加算
		m_barcount++;

	}

	//表示済みDP数がDP情報数以下でスクロールが出現位置よりも小さくなったら
	//※m_StageScrollはマイナス値です
	if (m_dpcount < m_dpvolume && m_StageScroll < m_dpinfo[m_dpcount].Scroll)
	{
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//表示中ならスルー
			if (dp_array[i].Getshow()) {
				continue;
			}

			//表示準備
			dp_array[i].Start(m_dpinfo[m_dpcount].Pos_y, m_dpinfo[m_dpcount].Type);
			break;
		}

		//表示済みDPを加算
		m_dpcount++;
	}

	//表示済み障害物数が障害物情報数以下でスクロールが出現位置よりも小さくなったら
	//※m_StageScrollはマイナス値です
	if (m_obcount < m_obvolume && m_StageScroll < m_obinfo[m_obcount].Scroll)
	{
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//表示中ならスルー
			if (ob_array[i].Getshow()) {
				continue;
			}

			//表示準備
			ob_array[i].Start(m_obinfo[m_obcount].Pos_y);
			break;
		}

		//表示済み障害物を加算
		m_obcount++;
	}

	//足場
	for (int i = 0; i < BAR_MAX; i++)
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

		if (dp_array[i].CollosopnDP(plrect)) {

			//DPと接触した場合
			UPdeteCollisionDP(dp_array[i].Gettype());
			dp_array[i].Setshow(false);
		}

	}

	//クリアフラグ変更
	if (m_StageScroll <= -37000||g_pInput->IsKeyPush(MOFKEY_0)) {

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
	//同じテクスチャを繰り返しで画面端を超えるまで行う
	int h = m_Bak.GetWidth();
	int sch = g_pGraphics->GetTargetWidth();
	for (float x = ((int)m_BakScroll % h) - h; x < sch; x += h) {

		//ここでSPステージ用の背景を表示させる感じやと思うけどやり方わからん
		m_Bak.Render(x, 0.0f);

		if (m_spflg)
		{

		}
	}

	//地面描画
	g_ground.Render();

	//足場描画
	for (int i = 0; i < BAR_MAX; i++)
	{
		b_bar[i].Render();
	}

	//ポイント描画
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Render();
	}

	//障害物
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Render();
	}

}

//解放
void CStage::Release(void) {

	m_Bak.Release();
	m_SPBak.Release();
}

//デバック描画
void CStage::DebuggingRender() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "背景：%d枚目", m_countbak);
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "背景スクロール値%f", m_BakScroll);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "ステージスクロール値%f", m_StageScroll);
	CGraphicsUtilities::RenderString(880, 690, MOF_XRGB(80, 80, 80), "Pキーでフルスクリーンに切り替え");
	CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "このステージ内での取得数  学力：%d　行動力：%d　想像力：%d　コミュ力：%d　魅力：%d",
		m_gaku, m_kou, m_sou, m_komyu, m_miryoku);

	//地面デバック表示
	g_ground.DebuggingRender();

	//DPデバック表示

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

}

bool CStage::GetClear(void) {

	return m_bClear;

}


#pragma once
#include "DetailPoint.h"


DetailPoint::DetailPoint() :
	dp_PosX(0.0f),
	dp_PosY(0.0f),
	dp_Show(false),
	dp_hitboxX(0.0f),
	dp_hitboxY(0.0f),
	dp_value(0.0f),
	dp_SpeedX(0.0f),
	dp_SpeedY(0.0f),
	dp_attraction(false),
	dp_texture(NULL),
	dp_Type(0)
{};

DetailPoint::~DetailPoint() {



};

//テクスチャをセット
void DetailPoint::SetTexture(CTexture* dptex) {

	dp_texture = dptex;

}


//DPの数値初期化
void DetailPoint::Initialize(void) {

	dp_PosX = 0;
	dp_PosY = 0;
	dp_Type = 0;
	dp_hitboxX = 80;
	dp_hitboxY = 80;
	dp_value = 0.5;
	dp_Show = false;
}


//表示ための準備
void DetailPoint::Start(float posy, int type) {

	dp_PosX = g_pGraphics->GetTargetWidth();

	dp_PosY = posy;

	//コイン種類
	dp_Type = type;

	//表示フラグ
	dp_Show = true;

}


void DetailPoint::Update(float over) {

	//表示中に実行
	if (dp_Show)
	{
		dp_PosX -= over;

		//画面左端で消去
		if (dp_PosX + dp_hitboxX < 0) {
			dp_Show = false;
		}
	}

	//V押したとき切り替え
	if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		//DP吸い寄せフラグ
		if (!dp_attraction)
		{
			dp_attraction = true;
		}
		else
		{
			dp_attraction = false;
		}
	}


}


void DetailPoint::UpdateFire(float sx, float sy)
{
	dp_SpeedX = sx;
	dp_SpeedY = sy;
	//*30は速度足りないため使ってます
	dp_PosX -= dp_SpeedX * 30;
	dp_PosY -= dp_SpeedY * 30;
}



//ゲームPGの教科書ⅠP100参照
//px,py：プレイヤーのXY座標
void DetailPoint::UpdateAtraction(float px, float py)
{
	//弾の発射位置
	float stx = dp_PosX;
	float sty = dp_PosY;

	//開始地点 - プレイヤーの位置 方向計算
	float dx = stx - px;
	float dy = sty - py;

	//距離計算
	float d = sqrt(dx * dx + dy * dy);
	if (d <= 0)
	{
		return;
	}
	//正規化で数字を1にすることで速度調整
	dx /= d;
	dy /= d;
	if (dp_attraction)
	{
		UpdateFire(dx, dy);
	}
}



//DPと当たり判定
bool DetailPoint::CollosopnDP(CRectangle r) {

	if (GetRect().CollisionRect(r)) {
		return true;
	}

	return false;
}


void DetailPoint::Render(void) {

	if (!dp_Show) {
		return;
	}

	dp_texture->Render(dp_PosX, dp_PosY);

}

void DetailPoint::RenderDebugging() {

	CGraphicsUtilities::RenderString(620, 660, MOF_XRGB(80, 80, 80), "コイン矩形 X:%.1f Y:%.1f", dp_hitboxX, dp_hitboxY);

	CGraphicsUtilities::RenderString(620, 30, MOF_XRGB(80, 80, 80), "ステータス上昇値:%.2f", dp_value);

}


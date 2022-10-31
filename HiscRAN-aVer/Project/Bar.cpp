#pragma once
#include "Bar.h"

Bar::Bar() :
	b_PosX(0.0f),
	b_PosY(0.0f),
	b_HitWidth(0.0f),
	b_Show(true),
	b_Type(0)
{};


Bar::~Bar() {


};

//初期化
void Bar::Initialize() {

	b_PosX = 0;
	b_PosY = 0;
	b_Type = 0;
	b_HitWidth = 0.0f;
	b_Show = false;
}

//表示のため準備
//posy:Y座標
void Bar::Start(float posy, int type) {

	b_PosX = g_pGraphics->GetTargetWidth();
	b_PosY = posy;

	//タイプ初期化
	b_Type = type;

	b_Show = true;

	switch (type)
	{
	case 1://大
		b_HitWidth = BAR_BIG_WIDTH;
		break;

	case 2://中
		b_HitWidth = BAR_MEDIUM_WIDTH;
		break;

	case 3://小
		b_HitWidth = BAR_SMALL_WIDTH;
		break;

	default:
		break;
	}

}

void Bar::Update(float over) {


	//表示中のみ
	if (b_Show)
	{
		b_PosX -= over;

		//幅をタイプ別に判定
		if (b_PosX + b_HitWidth < 0) {
			b_Show = false;
		}
	}



}

void Bar::Render(void) {

	if (!b_Show) {
		return;
	}

	//足場描画
	CGraphicsUtilities::RenderFillRect(GetRect(b_Type), MOF_COLOR_GREEN);

}

CRectangle Bar::GetRect(int type) {
	

	//タイプ別で大きさを変更
	//足場の大きさが中いが確定していないので仮置き
	switch (type)
	{

	case 1://大
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_BIG_WIDTH, b_PosY + BAR_BIG_HEIGHT);
		break;

	case 2://中
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_MEDIUM_WIDTH, b_PosY + BAR_MEDIUM_HEIGHT);
		break;

	case 3://小
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_SMALL_WIDTH, b_PosY + BAR_SMALL_HEIGHT);
		break;

	default:
		//エラーの場合
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_BIG_WIDTH, b_PosY + BAR_BIG_HEIGHT);

		break;
	}
	
}







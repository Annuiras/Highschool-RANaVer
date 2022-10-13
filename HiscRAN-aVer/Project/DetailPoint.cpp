#include "DetailPoint.h"


DetailPoint::DetailPoint() :
	dp_PosX(0.0f),
	dp_PosY(0.0f),
	dp_Show(false),
	dp_hitboxX(0.0f),
	dp_hitboxY(0.0f),
	dp_value(0.0f),
	dp_Type(0)
{};

DetailPoint::~DetailPoint() {



};

//DPの数値初期化
void DetailPoint::Initialize(void) {

	dp_PosX = 0;
	dp_PosY = 0;
	dp_Type = 0;
	dp_hitboxX = 30;
	dp_hitboxY = 30;
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

	switch (dp_Type)
	{

	case 1:
		//学力
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(222, 184, 135));
		break;

	case 2:
		//行動力
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_YELLOW);
		break;

	case 3:
		//想像力
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(0, 191, 255));
		break;

	case 4:
		//コミュ力
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(255, 99, 71));
		break;

	case 5:
		//魅力
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(186, 85, 211));
		break;

	default:
		//エラー
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_BLACK);
		break;
	}


}

void DetailPoint::DebuggingRender() {

	CGraphicsUtilities::RenderString(620, 660, MOF_XRGB(80, 80, 80), "コイン矩形 X:%.1f Y:%.1f", dp_hitboxX, dp_hitboxY);

	CGraphicsUtilities::RenderString(620, 30, MOF_XRGB(80, 80, 80), "ステータス上昇値:%.2f", dp_value);

	//DPナンバーを表示できんかな
	//CGraphicsUtilities::RenderString(dp_PosX,dp_addY,dp_)
}


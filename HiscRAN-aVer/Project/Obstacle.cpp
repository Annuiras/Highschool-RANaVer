#pragma once
#include "Obstacle.h"


CObstacle::CObstacle() :

	ob_PosX(0.0f),
	ob_PosY(0.0f),
	ob_Show(false),
	ob_Type(0),
	ob_HitWidth(0.0f),
	ob_Textuer()

{};

CObstacle::~CObstacle() {

}


//初期化
void  CObstacle::Initialize() {

	ob_PosX = 0;
	ob_PosY = 0;
	ob_Show = false;
	ob_HitWidth = 0;
	ob_Type = 0;

}


void CObstacle::Start(float posy, int type) {

	ob_PosX = g_pGraphics->GetTargetWidth();

	ob_PosY = posy;

	ob_Type = type;

	ob_Show = true;

	switch (type)
	{
	case OB_DESK://机
		ob_HitWidth = OB_DESK_WIDTH;
		break;

	case OB_TWODESK://２段机
		ob_HitWidth = OB_DESK_WIDTH;
		break;

	case OB_LOCKER://ロッカー
		ob_HitWidth = OB_LOCKER_WIDTH;
		break;

	default:
		break;
	}

}

void CObstacle::Update(float over) {

	//表示中に実行
	if (ob_Show)
	{
		ob_PosX -= over;

		//画面左端で消去
		if (ob_PosX + ob_HitWidth < 0)
			ob_Show = false;

	}
}

void CObstacle::SetTexture(CTexture* obtex) {

	ob_Textuer = obtex;

}

void CObstacle::Render() {

	//表示中？
	if (!ob_Show) {
		return;
	}
	if (ob_Textuer == NULL) {
		//テクスチャがない場合は描画しない
	}
	else
	{
		ob_Textuer->Render(ob_PosX, ob_PosY);
	}
	
}

//デバッグ表示
void CObstacle::RenderDebugging(void) {

	if (!ob_Show) {
		return;
	}

	//ダメージ判定
	CGraphicsUtilities::RenderRect(GetRect(ob_Type), MOF_COLOR_YELLOW);

	//上に乗れる判定
	CGraphicsUtilities::RenderRect(GetTopBarRect(ob_Type), MOF_COLOR_GREEN);
}


//ダメージ矩形取得
CRectangle CObstacle::GetRect(int type){

	//タイプ別で大きさを変更
	switch (type)
	{
		//机
	case OB_DESK:
		return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_DESK_HEIGHT);
		break;

		//２段机
	case OB_TWODESK:
		return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_,
			ob_PosX + OB_TOWDESK_WIDTH, ob_PosY + OB_TOWDESK_HEIGHT);
		break;

		//ロッカー
	case OB_LOCKER:
		return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_,
			ob_PosX + OB_LOCKER_WIDTH, ob_PosY + OB_LOCKER_HEIGHT);
		break;


	default:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);

		break;
	}
}

//試作障害物上に乗れる当たり判定取得
CRectangle CObstacle::GetTopBarRect(int type) {

	//タイプ別で大きさを変更
	switch (type)
	{

	case OB_DESK://机
		return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_);
		break;


	case OB_TWODESK://２段机
		return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_);
		break;

		
	case OB_LOCKER://ロッカー
		return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_,
			ob_PosX + OB_LOCKER_WIDTH, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_);
		break;


	default:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);

		break;
	}
}

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

	ob_HitWidth = ob_Textuer->GetWidth();
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

	//タイプで大きさ変更する場合
	switch (type)
	{
	//	//ロッカー
	//case OB_LOCKER:
	//	return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y,
	//		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + ob_Textuer->GetHeight());
	//	break;


	default:
		break;
	}

	return CRectangle(ob_PosX, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y,
		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + ob_Textuer->GetHeight());

}

//障害物上に乗れる当たり判定取得
CRectangle CObstacle::GetTopBarRect(int type) {

	//タイプ別で大きさを変更
	switch (type)
	{

	//case OB_DESK://机
	//	return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_Y,
	//		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y);
	//	break;

	default:
		break;
	}
	return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_Y,
		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y);

}

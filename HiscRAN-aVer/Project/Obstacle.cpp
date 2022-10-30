#include "Obstacle.h"


CObstacle::CObstacle() :

	ob_PosX(0.0f),
	ob_PosY(0.0f),
	ob_Show(false),
	ob_Type(0)

{};

CObstacle::~CObstacle() {

}


//todo:ロード追加です
bool CObstacle::Load(void) {

	//仮テクスチャ：机
	if (!ob_Textuer_Desk.Load("")) {
		return false;
	}

	return true;
}

//初期化
void  CObstacle::Initialize() {

	ob_PosX = 0;
	ob_PosY = 0;
	ob_Show = false;
	ob_HitWidth = 0;
	ob_Type = 0;

	Load();
}


void CObstacle::Start(float posy, int type) {

	ob_PosX = g_pGraphics->GetTargetWidth();

	ob_PosY = posy;

	ob_Type = type;

	ob_Show = true;

	switch (type)
	{
	case 1://机
		ob_HitWidth = OB_DESK_WIDTH;
		break;

	case 2://２段机
		ob_HitWidth = OB_DESK_WIDTH;
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

void CObstacle::Render() {

	//表示中？
	if (!ob_Show) {
		return;
	}

	//ob_Textuer_Desk.Render(GetRect(ob_Type));
	
	CGraphicsUtilities::RenderFillRect(GetRect(ob_Type), MOF_COLOR_RED);
}

CRectangle CObstacle::GetRect(int type){

	//todo:タイプ別で大きさを変更
	switch (type)
	{
	
	case 1://机
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_DESK_HEIGHT);
		break;

		
	case 2://２段机
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 137, ob_PosY + 306);
		break;

	default:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);

		break;
	}
}
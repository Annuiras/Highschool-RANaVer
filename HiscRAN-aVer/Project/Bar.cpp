#include "Bar.h"

Bar::Bar() :
	b_PosX(0.0f),
	b_PosY(0.0f),
	b_Show(true)
{};


Bar::~Bar() {


};

//初期化
void Bar::Initialize() {

	b_PosX = 0;
	b_PosY = 0;
	b_Show = false;
}

//表示のため準備
//posy:Y座標
void Bar::Start(float posy) {

	b_PosX = g_pGraphics->GetTargetWidth();
	b_PosY = posy;
	b_Show = true;

}

void Bar::Update(float over) {


	//表示中のみ
	if (b_Show)
	{
		b_PosX -= over;

		if (b_PosX + BAR_WIDTH < 0) {
			b_Show = false;
		}
	}



}

void Bar::Render(void) {

	if (!b_Show) {
		return;
	}

	//足場描画
	CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_RED);

}






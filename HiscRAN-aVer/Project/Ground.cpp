#include "Ground.h"


Ground::Ground() :

	g_PosX(0.0f),
	g_PosY(0.0f)

{};


Ground::~Ground() {


};

void Ground::Initialize(void) {

	g_PosY = GROUND_Y;

}

void Ground::Render() {

}

void Ground::RenderDebugging() {

	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_HGREEN);

	CGraphicsUtilities::RenderString(1060, g_PosY, MOF_XRGB(80, 80, 80), "地面高さ：%.1f", g_PosY);

}
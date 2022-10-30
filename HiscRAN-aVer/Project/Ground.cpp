#include "Ground.h"


Ground::Ground() :

	g_PosX(0.0f),
	g_PosY(0.0f)

{};


Ground::~Ground() {


};

void Ground::Initialize(void) {

	g_PosY = 700;

}

void Ground::Render() {

	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_HGREEN);
}

void Ground::RenderDebugging() {

	CGraphicsUtilities::RenderString(1060, g_PosY, MOF_XRGB(80, 80, 80), "ínñ çÇÇ≥ÅF%.1f", g_PosY);

}
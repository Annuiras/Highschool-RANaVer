#pragma once
#include "DetailPoint.h"

//制作者：田中 環、石川 由妃、永井 悠太

DetailPoint::DetailPoint() :
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_Show(false),
	m_HitboxX(0.0f),
	m_HitboxY(0.0f),
	m_Texture(NULL),
	m_Type(0)
{};

DetailPoint::~DetailPoint() {



};

//テクスチャをセット
void DetailPoint::SetTexture(CTexture* dptex) {

	m_Texture = dptex;

}


//DPの数値初期化
void DetailPoint::Initialize(void) {

	m_PosX = 0;
	m_PosY = 0;
	m_Type = 0;
	m_HitboxX = 0;
	m_HitboxY = 0;
	m_Show = false;
}


//表示ための準備
void DetailPoint::Start(float posy, int type) {

	m_PosX = g_pGraphics->GetTargetWidth();

	m_PosY = posy;

	//コイン種類
	m_Type = type;

	//表示フラグ
	m_Show = true;

	//画像サイズと合わせる
	m_HitboxX = m_Texture->GetWidth();
	m_HitboxY = m_Texture->GetHeight();
}


void DetailPoint::Update(float scroll) {

	//表示中に実行
	if (m_Show)
	{
		m_PosX -= scroll;

		//画面左端で消去
		if (m_PosX + m_HitboxX < 0) {
			m_Show = false;
		}
	}
}

//描画
void DetailPoint::Render(void) {

	if (!m_Show) {
		return;
	}

	m_Texture->Render(m_PosX, m_PosY);

}

void DetailPoint::RenderDebugging() {
	
	if (!m_Show) {
		return;
	}

	CGraphicsUtilities::RenderRect(m_PosX, m_PosY, m_PosX + m_HitboxX, m_PosY + m_HitboxY, MOF_COLOR_YELLOW);


}


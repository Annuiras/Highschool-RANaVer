#pragma once
#include "Bar.h"

Bar::Bar() :
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_HitWidth(0.0f),
	m_Show(true),
	m_Type(0),
	m_Texture()
{};


Bar::~Bar() {


};

//初期化
void Bar::Initialize() {

	m_PosX = 0;
	m_PosY = 0;
	m_Type = 0;
	m_HitWidth = 0.0f;
	m_Show = false;
	m_Texture = NULL;
}

//表示のため準備
//posy:Y座標
void Bar::Start(float posy, int type) {

	m_PosX = g_pGraphics->GetTargetWidth();
	m_PosY = posy;

	//タイプ初期化
	m_Type = type;

	m_Show = true;

	switch (type)
	{
	case BAR_BIG://大
		m_HitWidth = BAR_BIG_WIDTH;
		break;

	case BAR_MEDIUM://中
		m_HitWidth = BAR_MEDIUM_WIDTH;
		break;

	default:
		break;
	}

}

void Bar::Update(float over) {

	//表示中のみ
	if (m_Show)
	{
		m_PosX -= over;

		//画面外で非表示
		if (m_PosX + m_HitWidth < 0) {
			m_Show = false;
		}
	}
}

//描画
void Bar::Render(void) {

	if (!m_Show) {
		return;
	}

	//描画
	m_Texture->Render(m_PosX, m_PosY);
}

void Bar::RenderDebugging(void)
{	
	if (!m_Show) {
		return;
	}

	//足場描画
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_GREEN);
}

CRectangle Bar::GetRect(void) {
	

	//タイプ別で大きさを変更
	//足場の大きさが中いが確定していないので仮置き
	switch (m_Type)
	{

	case BAR_BIG://大
		return CRectangle(m_PosX, m_PosY,
			m_PosX + BAR_BIG_WIDTH, m_PosY + BAR_BIG_HEIGHT);
		break;

	case BAR_MEDIUM://中
		return CRectangle(m_PosX, m_PosY,
			m_PosX + BAR_MEDIUM_WIDTH, m_PosY + BAR_MEDIUM_HEIGHT);
		break;

	default:
		//エラーの場合
		return CRectangle(m_PosX, m_PosY,
			m_PosX + BAR_BIG_WIDTH, m_PosY + BAR_BIG_HEIGHT);

		break;
	}
	
}

//テクスチャをセット
void Bar::SetTexture(CTexture* bartex)
{
	m_Texture = bartex;
}







#pragma once
#include "Obstacle.h"


CObstacle::CObstacle() :

	m_PosX(0.0f),
	m_PosY(0.0f),
	m_Show(false),
	m_Type(0),
	m_HitWidth(0.0f),
	m_Textuer()

{};

CObstacle::~CObstacle() {

}


//初期化
void  CObstacle::Initialize() {

	m_PosX = 0;
	m_PosY = 0;
	m_Show = false;
	m_HitWidth = 0;
	m_Type = 0;

}

//生成
void CObstacle::Start(float posy, int type) {

	m_PosX = g_pGraphics->GetTargetWidth();

	m_PosY = posy;

	m_Type = type;

	m_Show = true;

	m_HitWidth = m_Textuer->GetWidth();
}

void CObstacle::Update(float over) {

	//表示中に実行
	if (m_Show)
	{
		m_PosX -= over;

		//画面左端で消去
		if (m_PosX + m_HitWidth < 0)
			m_Show = false;

	}
}

//OBテクスチャをセット
void CObstacle::SetTexture(CTexture* obtex) {
	m_Textuer = obtex;
}

//描画
void CObstacle::Render() {

	//表示中？
	if (!m_Show) {
		return;
	}
	m_Textuer->Render(m_PosX, m_PosY);
}

//デバッグ表示
void CObstacle::RenderDebugging(void) {

	if (!m_Show) {
		return;
	}

	//ダメージ判定
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_YELLOW);

	//上に乗れる判定
	CGraphicsUtilities::RenderRect(GetTopBarRect(), MOF_COLOR_GREEN);
}


//ダメージ矩形取得
CRectangle CObstacle::GetRect(void){

	//タイプで大きさ変更する場合
	switch (m_Type)
	{

	default:
		break;
	}

	//基本は画像の大きさ程度
	return CRectangle(m_PosX, m_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y,
		m_PosX + m_Textuer->GetWidth(), m_PosY + m_Textuer->GetHeight());

}

//障害物上に乗れる当たり判定取得
CRectangle CObstacle::GetTopBarRect(void) {

	//タイプ別で大きさを場合
	switch (m_Type)
	{

	default:
		break;
	}
	return CRectangle(m_PosX, m_PosY + OB_HITRECT_SPACE_Y,
		m_PosX + m_Textuer->GetWidth(), m_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y);

}

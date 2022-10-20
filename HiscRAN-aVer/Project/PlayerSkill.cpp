//#include "PlayerSkill.h"
//
//CPlayerSkill::CPlayerSkill() :
//	m_PosX(),
//	m_PosY()
//{
//}
//
//CPlayerSkill::~CPlayerSkill() {
//}
//
////初期化
//void CPlayerSkill::Initialize(void) {
//	m_PosX = 50;
//	m_PosY = 410;
//	m_CircleWait = 0;
//}
//
////更新
//void CPlayerSkill::Update()
//{
//	//押した時カウントスタート
//	if (g_pInput->IsKeyPush(MOFKEY_V))
//	{
//		m_CircleWait = 60;
//	}
//
//	if (m_CircleWait > 0)
//	{
//		m_CircleWait--;
//	}
//}
//
////描画
//void CPlayerSkill::Render()
//{
//	//カウント10以上の時描画
//	if (m_CircleWait >= 10)
//	{
//		CGraphicsUtilities::RenderCircle(gPlayer.CircleX() + 100, gPlayer.CircleY() + 500, 150, MOF_COLOR_RED);
//	}
//}
//
////デバッグ
//void CPlayerSkill::RenderDebug()
//{
//	CRectangle Circle = m_CircleRect();
//
//	if (m_CircleWait >= 10) {
//
//		CGraphicsUtilities::RenderRect(Circle, MOF_COLOR_BLUE);
//
//	}
//}
//
//todo:スキルクラス削除

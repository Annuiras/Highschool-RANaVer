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
////������
//void CPlayerSkill::Initialize(void) {
//	m_PosX = 50;
//	m_PosY = 410;
//	m_CircleWait = 0;
//}
//
////�X�V
//void CPlayerSkill::Update()
//{
//	//���������J�E���g�X�^�[�g
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
////�`��
//void CPlayerSkill::Render()
//{
//	//�J�E���g10�ȏ�̎��`��
//	if (m_CircleWait >= 10)
//	{
//		CGraphicsUtilities::RenderCircle(gPlayer.CircleX() + 100, gPlayer.CircleY() + 500, 150, MOF_COLOR_RED);
//	}
//}
//
////�f�o�b�O
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
//todo:�X�L���N���X�폜

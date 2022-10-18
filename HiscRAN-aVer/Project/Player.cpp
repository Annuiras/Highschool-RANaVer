#include "Player.h"

CPlayer::CPlayer() :
	m_Texture(),
	m_SrcRect(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_hitboxX(0.0f),
	m_hitboxY(0.0f),
	m_legsboxY(0.0f),
	m_OverX(0.0f),
	m_OverY(0.0f),
	m_StopX(0.0f),
	m_HP(0),
	m_DamageWait(0),
	m_Startflg(false),
	m_deathflg(false),
	m_Jumpflg(false),
	m_JumpCount(0.0f),
	m_BSflg(true),//todo
	m_Slidingflg(false) {
}

CPlayer::~CPlayer() {


}

//�ǂݍ���
bool CPlayer::Load(void) {

	////�L�����N�^�[�ǂݍ���
	//if (!m_Texture.Load("player.png")) {
	//	return false;
	//}

	//�L�����N�^�[�ǂݍ���
	if (!m_Texture.Load("880�~153RunMotion.png")) {
		return false;
	}

	//if (!m_TEX.Load("880�~153RunMotion.png")) {
	//	return false;
	//}

	//�A�j���[�V����
	SpriteAnimationCreate anim[] = {

		{
			"�ҋ@",
			0,0,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
		},
		{
			//"�ړ�",
			//0,70,
			//60,64,
			//TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}

			//�����[�V�����p
			"�ړ�",
			0,0,
			110,153,
			TRUE,{{10,0,0},{10,1,0},{10,2,0},{10,3,0},{10,4,0},{10,5,0},{10,6,0},{10,7,0}}

		},
		//�W�����v
		{
			"�W�����v�J�n",
			0,140,
			60,64,
			FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}}
		},
		//�X���C�f�B���O�i���F�U���j
		//todo
		{
			"�X���C�f�B���O",
			0,350,
			90,64,
			TRUE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0}}
		},
		{
			//�g���ĂȂ��ł�
			"�W�����v�I��",
			240,140,
			60,64,
			FALSE,{{2,0,0},{2,1,0}}
		},
		//�_���[�W
		{
			"�_���[�W",
			480,0,
			60,64,
			FALSE,{{20,0,0}}
		},
	};
	m_Motion.Create(anim, MOTION_COUNT);
	return true;
}

//������
void CPlayer::Initialize(void) {


	m_PosX = 50;
	m_PosY = 300;
	m_MoveX = 7.0f;
	m_MoveY = 0.0f;
	m_hitboxX = 160;
	m_hitboxY = 185;
	m_legsboxY = 100;
	m_StopX = 50;
	m_Jumpflg = false;
	m_HP = 3;
	m_DamageWait = 0;
	m_deathflg = false;
	m_Startflg = false;
	m_OverX = 0;

	m_Slidingflg = false;//todo

	m_Motion.ChangeMotion(MOTION_WAIT);

}

//�X�V
void CPlayer::Update(void) {


	//�ҋ@���̏ꍇ�̏���
	if (!m_Startflg)
	{
		//�\����`���Z�b�g
		m_SrcRect = m_Motion.GetSrcRect();

		//�I�[�o�[������������
		m_OverX = 0;

		return;
	}

	//�I�[�o�[������������
	m_OverX = 0;

	//�_���[�W���̓���
	if (m_Motion.GetMotionNo() == MOTION_DAMAGE)
	{
		//�I���őҋ@�ɖ߂�
		if (m_Motion.IsEndMotion())
		{
			m_Motion.ChangeMotion(MOTION_WAIT);
		}
	}

	//�X���C�f�B���O����GAME�ɏ����A������ړ�
	if (g_pInput->IsKeyHold(MOFKEY_DOWN)) {

		if (CollosopnBar(GetRect()) || CollosopnGround(GetRect())) {

			m_Slidingflg = true;

			m_Motion.ChangeMotion(MOTION_SLIDING);

		}
		
	}
	else
	{
		m_Slidingflg = false;
	}

	//todo
	//�W�����v����
	if (g_pInput->IsKeyHold(MOFKEY_SPACE) && !m_Slidingflg && m_BSflg) {

		//�W�����v�J�n
		if (!m_Jumpflg) {
			m_MoveY = SMALLJUMP;
		}

		m_JumpCount++;
		m_Jumpflg = true;
		m_Motion.ChangeMotion(MOTION_JUMPSTART);

		//�召�W�����v�؂�ւ�
			//�����Ă���ԂɈ�莞�Ԓ�����Α�W�����v
			if (m_JumpCount >= 10&& m_BSflg) {
   				m_MoveY = BIGJUMP;
				m_BSflg = false;
			}
		

	}



	//�d�͔��f
	m_MoveY += GRAVITY;

	//�X�s�[�h���f
	m_PosY += m_MoveY;
	m_PosX += m_MoveX;

	

	//��ʏ�ł�X�ʒu�����Ȃ��悤�ɒ���
	if (m_PosX > m_StopX) {

		m_OverX += m_PosX - m_StopX;
		m_PosX = m_StopX;

	}

	//todo
	if (m_MoveY >= 0) {
		m_Jumpflg = false;
	}

	//�A�j���[�V�����Đ�
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
	//�_���[�W�̃C���^�[�o�������炷
	if (m_DamageWait > 0)
	{
		m_DamageWait--;
	}
}

//���ꓖ���蔻��
bool CPlayer::CollosopnBar(CRectangle r) {
	if (legsGetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}


//����Ɠ��������ꍇ
void CPlayer::UPdateCollisionBra(float y) {

	m_PosY = y;
	m_PosY -= m_hitboxY;

	m_JumpCount = 0;
	
	m_MoveY = 0;
	m_Jumpflg = false;
	m_BSflg = true;

	//�ړ����[�V����
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}
}

//�n�ʂƓ����蔻��
//CRectangle ����̋�`
bool CPlayer::CollosopnGround(CRectangle r) {

	//�n�ʋ�`�Ɣ���
	if (GetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}
//�n�ʂƓ��������ꍇ
//float y:�n�ʂ̍���
void CPlayer::UPdateCollisionGround(float y) {

	m_PosY = y - m_hitboxY;

	m_MoveY = 0;

	m_Jumpflg = false;

	//ToDo
	m_BSflg = true;

	m_JumpCount = 0;


	//�ړ����[�V����
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}

}


//��Q���Ɠ����蔻��
bool CPlayer::CollosopnOB(CRectangle r) {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r))
	{
		m_Motion.ChangeMotion(MOTION_DAMAGE);
		return true;
	}
	return false;
}


//��Q���E�G�Ɠ��������ꍇ
void CPlayer::UPdateCollisionOB() {

	m_HP -= 1;
	m_DamageWait = 60;
	if (m_HP <= 0) {
		m_deathflg = true;
		m_HP = 0;
	}
}

//�Q�[���X�^�[�g�؂�ւ�
void CPlayer::GameStopPlayChange()
{
	//�ҋ@���[�V��������ړ����[�V������
	//m_Motion.ChangeMotion(MOTION_MOVE);
	if (m_Startflg) {

		m_Startflg = false;

	}
	else
	{
		m_Startflg = true;

	}
}

//�L�����������Ă��邩�擾
bool CPlayer::GetGameStopPlay() {

	return m_Startflg;

}

//���g�p:�G�����蔻��
bool CPlayer::CollosopnEnemy(CRectangle r) {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {
		m_DamageWait = 60;
		m_Motion.ChangeMotion(MOTION_DAMAGE);
		return true;
	}
	return false;
}


//�`��
void CPlayer::Render()
{
	if (m_DamageWait % 4 >= 2)
	{
		return;
	}

	CRectangle br = m_SrcRect;

	//�`��ʒu
	float px = m_PosX;
	float py = m_PosY;

	//m_Texture.Render(px, py, br);

	//���L����
	//m_TEX.Render(px, py);
	
	//�L�����N�^�[�̔����`
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(legsGetRect(), MOF_COLOR_GREEN);
}

//�f�o�b�N�\��
void CPlayer::DebuggingRender() {

	switch (m_Motion.GetMotionNo())
	{

		case MOTION_WAIT:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_WAIT");
			break;

		case MOTION_MOVE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_MOVE");
			break;

		case MOTION_JUMPSTART:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_JUMPSTART");
			break;

		case MOTION_JUMPEND:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_JUMPEND");
			break;
		case MOTION_DAMAGE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_DAMAGE");
			break;
	}

	//HP�\��
	CGraphicsUtilities::RenderString(0, 260, MOF_XRGB(80, 80, 80), "HP:%d", m_HP);

	//�W�����v�t���O�\��
	if (m_Jumpflg) {
		CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "m_Jumoflg=true");
	}	
	else
	{
		CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "m_Jumoflg=false");
	}

	//�X���C�f�B���O�t���O
	if (m_Slidingflg) {
		CGraphicsUtilities::RenderString(0, 430, MOF_XRGB(80, 80, 80), "m_Slidingflg=true");
	}
	else
	{
		CGraphicsUtilities::RenderString(0, 430, MOF_XRGB(80, 80, 80), "m_Slidingflg=false");
	}

	//��W�����v�t���O
	if (m_BSflg) {
		CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "m_BSflg=true");
	}
	else
	{
		CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "m_BSflg=false");
	}

}

//���
void CPlayer::Release(void) {
	m_Texture.Release();
	m_Motion.Release();
	m_TEX.Release();
}

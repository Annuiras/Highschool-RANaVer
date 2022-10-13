#include "Player.h"

CPlayer::CPlayer() :
	m_Texture(),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_OverX(0.0f),
	m_OverY(0.0f),
	m_hitboxX(0.0f),
	m_hitboxY(0.0f),
	m_JumpPower(0.0f),
	m_Jumpflg(false),
	m_HP(0),
	m_deathflg(false),
	m_Startflg(/*true*/ false) //stage�ɌĂяo����Ă���true�ɕύX�����B��ŕύX
{

}

CPlayer::~CPlayer() {


}

//�ǂݍ���
bool CPlayer::Load(void) {

	//�L�����N�^�[�ǂݍ���
	if (!m_Texture.Load("player.png")) {
		return false;
	}

	//�A�j���[�V����
	SpriteAnimationCreate anim[] = {

		{
			"�ҋ@",
			0,0,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
		},
		//�ړ�
		{
			"�ړ�",
			0,70,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
		},
		//�W�����v
		{
			"�W�����v�J�n",
			0,140,
			60,64,
			FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}}
		},
		{
			//�g���ĂȂ��ł�s
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
	m_PosY = 410;
	m_MoveX = 7.0f;
	m_MoveY = 0.0f;
	m_JumpPower = 0.0f;
	m_hitboxX = 100;
	m_hitboxY = 150;
	m_legsboxY = 140;
	m_StopX = 50;
	m_Jumpflg = false;
	m_HP = 3;
	m_DamageWait = 0;
	m_deathflg = false;
	m_standby = true;

	m_Motion.ChangeMotion(MOTION_WAIT);

}

//�X�V
void CPlayer::Update(void) {

	//�ҋ@���̏ꍇ�̏���
	if (!m_Startflg) {

		m_OverX = 0;
		m_SrcRect = m_Motion.GetSrcRect();

		return;
	}

	//todo:�Q�[���J�n�t���O�̓���
	//�Q�[���X�^�[�g
	if (m_Startflg == true) {

		//todo:MOTION_DAMAGE���Z�b�g���鏈���̒ǉ�
		//�Z�b�g���ĂȂ����炱�̏����̈Ӗ�����������Ă�
		//�_���[�W���̓���
		if (m_Motion.GetMotionNo() == MOTION_DAMAGE)
		{
			//�I���őҋ@�ɖ߂�
			if (m_Motion.IsEndMotion())
			{
				m_Motion.ChangeMotion(MOTION_WAIT);
			}
		}

		////Enter������������
		//if (g_pInput->IsKeyPush(MOFKEY_RETURN))
		//{
		//	if (!m_deathflg)
		//	{
		//		m_standby = false;
		//	}
		//	m_Motion.ChangeMotion(MOTION_MOVE);
		//}


		//�W�����v����
		if (g_pInput->IsKeyHold(MOFKEY_SPACE)) {
			m_JumpCount++;
		}
		//�������Ƃ��ɃW�����v����
		if (g_pInput->IsKeyPull(MOFKEY_SPACE) && !m_Jumpflg) {
			//�W�����v�J�n
			m_Jumpflg = true;

			if (m_JumpCount >= 15) {
				m_MoveY = BIGJUMP;
			}
			else {
				m_MoveY = SMALLJUMP;
			}

			m_Motion.ChangeMotion(MOTION_JUMPSTART);
		}

		//�X���C�f�B���O����
		if (g_pInput->IsKeyHold(MOFKEY_DOWN)) {

		}


		//�d�͔��f
		m_MoveY += GRAVITY;
		//�X�s�[�h���f
		m_PosY += m_MoveY;

		//�n�ʒ��n
		if (m_PosY >= 550)
		{
			if (m_Jumpflg) {
				m_JumpCount = 0;
			}
			m_PosY = 550;
			m_MoveY = 0;
			m_Jumpflg = false;

			//�ړ����[�V����
			if (m_Motion.GetMotionNo() == MOTION_JUMPSTART) {
				m_Motion.ChangeMotion(MOTION_MOVE);
			}
		}

		//todo:�A�j���[�V�����̍Đ����d�����Ă���o�O�̉���->�����炭����
		//�A�j���[�V�����Đ�
		m_Motion.AddTimer(CUtilities::GetFrameSecond());
		m_SrcRect = m_Motion.GetSrcRect();
	}
	else {
		m_Motion.ChangeMotion(MOTION_WAIT);
	}

	//�I�[�o�[������������
	m_OverX = 0;
	//�X�s�[�h���f
	m_PosX += m_MoveX;

	//��ʏ�ł�X�ʒu�����Ȃ��悤�ɒ���
	if (m_PosX > m_StopX) {

		m_OverX += m_PosX - m_StopX;
		m_PosX = m_StopX;
	}

	//todo:�A�j���[�V�����̍Đ����d�����Ă���o�O�̉���->�Ƃ���
	//�A�j���[�V�����Đ�
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
	//�_���[�W�̃C���^�[�o�������炷
	if (m_DamageWait > 0)
	{
		m_DamageWait--;
	}
}
//todo:�n�ʂƐڐG�����ꍇ�̊֐��̒ǉ�->
//�v���g�^�C�v���Q�l�ɂȂ�Ǝv���A�����F�n�ʂ̍���
//�n�ʓ����蔻��
bool CPlayer::CollosopnObje(CRectangle r) {
	if (legsGetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}

//��Q���Ɠ����蔻��
bool CPlayer::CollosopnOB(CRectangle r) {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {

		//todo:�����̖��G���ԏ�����UPdeteCollisionOB�Ɉړ����Ă����ƌ��₷���Ă��ꂵ��
		m_DamageWait = 60;
		return true;
	}
	return false;
}

//�G�����蔻��
bool CPlayer::CollosopnEnemy(CRectangle r) {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {
		m_DamageWait = 60;
		return true;
	}
	return false;
}

//��Q���E�G�Ɠ��������ꍇ
void CPlayer::UPdeteCollisionOB() {

	m_HP -= 1;
	if (m_HP <= 0) {
		m_deathflg = true;
		m_HP = 0;
		m_standby = true;
	}
}

//todo:�Q�[���X�^�[�g�̐؂�ւ��̒ǉ�->���̏����Ăяo����ĂȂ�����t���O�؂�ւ����Ȃ��ł�
//�Q�[���X�^�[�g�؂�ւ�
bool CPlayer::GameStart() {
	//�ҋ@���[�V��������ړ����[�V������
	m_Motion.ChangeMotion(MOTION_MOVE);
	m_Startflg = true;
	return true;
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

	m_Texture.Render(px, py, br);
	//�L�����N�^�[�̔����`
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(legsGetRect(), MOF_COLOR_GREEN);
}

//�f�o�b�N�\��
void CPlayer::DebuggingRender() {

}

//���
void CPlayer::Release(void) {
	m_Texture.Release();
	m_Motion.Release();
}

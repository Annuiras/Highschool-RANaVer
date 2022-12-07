#include "Player.h"

CPlayer::CPlayer() :
	m_Texture(),
	m_SrcRect(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveY(0.0f),
	m_legsboxY(0.0f),
	m_HP(0),
	m_DamageWait(0),
	m_deathflg(false),
	m_Jumpflg(false),
	m_JumpCount(0.0f),
	m_BSflg(true)
{
}

CPlayer::~CPlayer() {


}

//�ǂݍ���
bool CPlayer::Load(void) {


	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("PlayerCharacter");

	//�L�����N�^�[�ǂݍ���
	if (!m_Texture.Load("����ƃW�����v���[�V����2022_11_08.png")) {
		return false;
	}

	//���u���ł�
	float n = 2;

	//�A�j���[�V����
	SpriteAnimationCreate anim[] = 
	{
		{
			//���[�V����
			"�ړ�",
			0,0,
			160,185,
			TRUE,{{n,0,0},{n,1,0},{n,2,0},{n,3,0},{n,4,0},{n,5,0},{n,6,0},{n,7,0},{n,8,0},{n,9,0},{n,10,0}
			,{n,11,0},{n,12,0},{n,13,0},{n,14,0}}

		},
		//�W�����v
		{
			"�W�����v�J�n",
			0,185,
			160,185,
			FALSE,{{5,0,2}}
		}
	};
	m_Motion.Create(anim, MOTION_COUNT);

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//������
void CPlayer::Initialize(void) {


	m_PosX = PLAYER_START_POS_X;
	m_PosY = PLAYER_START_POS_Y;
	m_MoveY = 0.0f;
	m_legsboxY = PLAYER_LEGS_Y;
	m_Jumpflg = false;
	m_HP = 3;
	m_DamageWait = 0;
	m_deathflg = false;


	m_Motion.ChangeMotion(MOTION_MOVE);

}

//�X�V
void CPlayer::Update(void) {

	//�W�����v����
	if (g_pInput->IsKeyHold(MOFKEY_SPACE) && m_BSflg) {

		//�W�����v�J�n
		if (!m_Jumpflg) {
			m_MoveY = SMALLJUMP;
		}

		//SE�Đ�
		m_MusicMgmt->SEStart(SET_PAWANN);

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

	//���W�����v�̉�����ł�����j�~�������
	if (g_pInput->IsKeyPull(MOFKEY_SPACE)) {
		m_BSflg = false;
	}

	//�d�͔��f
	m_MoveY += GRAVITY;

	//�X�s�[�h���f
	m_PosY += m_MoveY;
	
	//���~���x�N���b�v
	if (m_MoveY >= 20) {
		m_MoveY = 20 - 0.1f;
	}

	//���~��
	if (m_MoveY >= 0) {
		m_Jumpflg = false;
		m_BSflg = false;
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

	//�㏸���t���O��false�ɂȂ������ɏォ��o�[�ɏ��
	if (!m_Jumpflg) {
		m_PosY = y;
		m_PosY -= PLAYER_HIT_Y;

		m_MoveY = 0;

		//�W�����v�I����ɃN�[���^�C��
		m_JumpCount--;
		if (m_JumpCount > 10)
		{
			m_JumpCount = 10;
		}
		else if (m_JumpCount <= 0)
		{
			m_BSflg = true;
			m_JumpCount = 0;
		}
	}

	//�ړ����[�V����
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}
}

//�n�ʂƓ����蔻��
//CRectangle ����̋�`
bool CPlayer::CollosopnGround(CRectangle r) {

	//�n�ʋ�`�Ɣ���
	if (legsGetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}

//�n�ʂƓ��������ꍇ
//float y:�n�ʂ̍���
void CPlayer::UPdateCollisionGround(float y) {

	//�n�ʂ̍����Ɉړ�
	m_PosY = y - PLAYER_HIT_Y;

	//�c�ړ���
	m_MoveY = 0;

	//�W�����v���Ă��Ȃ�
	m_Jumpflg = false;

	//�W�����v�I����ɃN�[���^�C��
	m_JumpCount--;
	if (m_JumpCount > 10)
	{
		m_JumpCount = 10;
	}
	else if (m_JumpCount <= 0)
	{
		m_BSflg = true;
		m_JumpCount = 0;
	}

	//�ړ����[�V����
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}

}


//��Q���Ɠ����蔻��
bool CPlayer::CollosopnOB(CRectangle r) {

	if (GetRect().CollisionRect(r))
	{

		return true;
	}
	return false;
}


//��Q���E�G�Ɠ��������ꍇ
void CPlayer::UPdateCollisionOB() {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0)
	{
		return;
	}
	m_HP -= 1;
	m_DamageWait = 60;

	if (m_HP <= 0) {
		m_deathflg = true;
		//m_HP = 0;
	}
}

//�G�����蔻��
bool CPlayer::CollosopnEnemy(CRectangle r) {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {
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

	m_Texture.Render(px, py, br);

	//���L����
	//m_TEX.Render(px, py);
		//HP�\��
	CGraphicsUtilities::RenderString(0, 260, MOF_XRGB(80, 80, 80), "HP:%d", m_HP);

}

//�f�o�b�N�\��
void CPlayer::RenderDebugging() {

	switch (m_Motion.GetMotionNo())
	{


		case MOTION_MOVE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_MOVE");
			break;

		case MOTION_JUMPSTART:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "���݃��[�V�����FMOTION_JUMPSTART");
			break;
	}

	//�L�����N�^�[�̔����`
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(legsGetRect(), MOF_COLOR_GREEN);

#pragma region �f�o�b�O�p

	//CGraphicsUtilities::RenderString(500, 500, MOF_XRGB(80, 80, 80), "m_DamageWait%d", m_DamageWait);

	//if (m_Jumpflg) {
	//CGraphicsUtilities::RenderString(500, 500, MOF_XRGB(80, 80, 80), "m_Jumpflg=true");

	//}
	//else
	//{
	//	CGraphicsUtilities::RenderString(500, 500, MOF_XRGB(80, 80, 80), "m_Jumpflg=false");

	//}

	//if (m_BSflg) {
	//	CGraphicsUtilities::RenderString(500, 560, MOF_XRGB(80, 80, 80), "m_BSflg=true");

	//}
	//else
	//{
	//	CGraphicsUtilities::RenderString(500, 560, MOF_XRGB(80, 80, 80), "m_BSflg=false");

	//}


	////�W�����v�t���O�\��
	//if (m_Jumpflg) {
	//	CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "m_Jumoflg=true");
	//}	
	//else
	//{
	//	CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "m_Jumoflg=false");
	//}


	////��W�����v�t���O
	//if (m_BSflg) {
	//	CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "m_BSflg=true");
	//}
	//else
	//{
	//	CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "m_BSflg=false");
	//}



#pragma endregion

}

//���
void CPlayer::Release(void) {
	m_Texture.Release();
	m_Motion.Release();
}

#include "Player.h"
//����ҁF�c�� �A�ΐ� �R�܁A�i�� �I��

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
	m_BSflg(true),
	m_MusicMgmt(),
	m_pEffectMgmt(),
	_unrivaled()
{
}

CPlayer::~CPlayer() {


}

//�ǂݍ���
bool CPlayer::Load(void) {


	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Character");

	//�L�����N�^�[�ǂݍ���
	if (!m_Texture.Load("Motion.png")) {
		return false;
	}


	//HP�\���e�N�X�`���ǂݍ���
	if (!m_HPTexture.Load("Game_HP.png")) {
		return false;
	}
	if (!m_HPFrame.Load("Game_HPFrame.png")) {
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
			FALSE,{{5,0,0}}
		}
	};
	m_Motion.Create(anim, MOTION_COUNT);

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//������
void CPlayer::Initialize(void) {

	//�����ʒu
	m_PosX = PLAYER_START_POS_X;
	m_PosY = PLAYER_START_POS_Y;

	m_MoveY = 0.0f;
	m_legsboxY = PLAYER_LEGS_Y;
	m_Jumpflg = false;
	m_HP = START_HP;
	m_DamageWait = 0;
	m_deathflg = false;

	//���G�t���O
	_unrivaled = false;
	_chare_A = 255;

	//���[�V����������
	m_Motion.ChangeMotion(MOTION_MOVE);
	m_SrcRect = m_Motion.GetSrcRect();

}

//�X�V
void CPlayer::Update(void) {

	//�f�o�b�O�p
	if (g_pInput->IsKeyPull(MOFKEY_M)) {
		//���G��
		_unrivaled = _unrivaled ? !_unrivaled : !_unrivaled;

		//���G����������
		_chare_A = _unrivaled ? 125 : 255;
	}

	//�f�o�b�N
	if (g_pInput->IsKeyPull(MOFKEY_D)) {

		//�_���[�W����
		m_HP--;

		//�Q�[���I�[�o�[�X�V
		if (m_HP <= 0) {
			m_deathflg = true;
			m_HP = 0;
			m_DamageWait = 0;
		}

	}

	//�W�����v����
	if (g_pInput->IsKeyHold(MOFKEY_SPACE) && m_BSflg) {

		//SE�Đ�
		m_MusicMgmt->SEStart(SE_T_JUMP);

		m_JumpCount++;
		m_Jumpflg = false;
		m_Motion.ChangeMotion(MOTION_JUMPSTART);

		//�召�W�����v�؂�ւ�
		//�����Ă���ԂɈ�莞�Ԓ�����Α�W�����v
		if (m_JumpCount >= 10&& m_BSflg) {
   			m_MoveY = BIGJUMP;
			m_BSflg = false;
			m_MusicMgmt->SEStart(SE_T_GREAT_JUMP);
		}
		else if (!m_Jumpflg)
		{
			//�W�����v�J�n 
          	m_MoveY = SMALLJUMP;
		}
	}


	//�d�͔��f
	m_MoveY += GRAVITY;

	//�X�s�[�h���f
	m_PosY += m_MoveY;
	
	//���~���x�N���b�v
	if (m_MoveY >= 20) {
		m_MoveY = 20 - 0.1f;
	}

	//�n�ʂ��������H
	if (m_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {

		UPdateCollisionGround(GROUND_Y);

	}

	//���~��
	if (m_MoveY > 1) {
		m_Motion.ChangeMotion(MOTION_JUMPSTART);
		m_Jumpflg = true;
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

//����A��Q����Ɠ��������ꍇ
void CPlayer::UPdateCollisionBra(float y) {

	if (m_Jumpflg) {
		m_PosY = y- PLAYER_HIT_Y;

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


		//�ړ����[�V����
		if (m_Motion.GetMotionNo() != MOTION_MOVE) {
			m_Motion.ChangeMotion(MOTION_MOVE);
		}
	}

}

//�n�ʂƓ��������ꍇ
//float y:��鍂��
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

//��Q���E�G�Ɠ��������ꍇ
void CPlayer::UPdateCollisionOB() {

	//���G���Ԓ��͔��肵�Ȃ�
	if (m_DamageWait > 0|| _unrivaled)
	{
		return;
	}

	//SE�Đ�
	m_MusicMgmt->SEStart(SE_T_HIT);

	//HP���炷
	m_HP -= 1;

	//���G����
	m_DamageWait = INVINCIBLE_TIME;

	//�Q�[���I�[�o�[�X�V
	if (m_HP <= 0) {
		m_deathflg = true;
		m_HP = 0;
		m_DamageWait = 0;
	}
}

//�N���A���̍X�V
void CPlayer::UpdateClear(void)
{
	//�d�͔��f
	m_MoveY += GRAVITY;

	//�X�s�[�h���f
	m_PosY += m_MoveY;

	//���ړ�
	m_PosX += 7;

	//���~���x�N���b�v
	if (m_MoveY >= 20) {
		m_MoveY = 20 - 0.1f;

	}
	//�n�ʂ��������H
	if (m_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {
		UPdateCollisionGround(GROUND_Y);
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

//�`��
void CPlayer::Render()
{

	//��ʒ[0�@�]��15�@[4����1-�摜��/2]�@[4����2-�摜��/2]�@[4����3-�摜��/2]�@�]��15�@�i�s�x�摜280�@�i��̒i�j
	//��ʒ[0�@�]��15�@�@�@�@�@�@�@[3����1-�摜��/2]�@[3����2-�摜��/2]�@�@�@�@ �]��15�@�i�s�x�摜280�@�i���̒i�j
	//HP�̃t���[���`��
	m_HPFrame.Render(15 + 265 / 4 - m_HPFrame.GetWidth() / 2, 20);
	m_HPFrame.Render(15 + 265 / 2 - m_HPFrame.GetWidth() / 2, 20);
	m_HPFrame.Render(15 + 265 / 4 * 3 - m_HPFrame.GetWidth() / 2, 20);
	m_HPFrame.Render(15 + 265 / 3 - m_HPFrame.GetWidth() / 2 + 10, 70);
	m_HPFrame.Render(15 + 265 / 3 * 2 - m_HPFrame.GetWidth() / 2 - 10, 70);

	//HP�̕`��
	// m_DamageWait�i�_���[�W�j���������� m_HP �� +1 �����Ƃ��̉摜��_�Ł@m_DamageWait �̒l�� 0 �ɂȂ�Γ_�ŁA�\���̏I��
	if (m_HP >= 1 || m_DamageWait % 5 == 1 && m_HP == 0) {
		m_HPTexture.Render(15 + 265 / 4 - m_HPTexture.GetWidth() / 2, 20);			//����
	}
	if (m_HP >= 2 || m_DamageWait % 5 == 1 && m_HP == 1) {
		m_HPTexture.Render(15 + 265 / 3 - m_HPTexture.GetWidth() / 2 + 10, 70);		//����
	}
	if (m_HP >= 3 || m_DamageWait % 5 == 1 && m_HP == 2) {
		m_HPTexture.Render(15 + 265 / 2 - m_HPTexture.GetWidth() / 2, 20);			//����
	}
	if (m_HP >= 4 || m_DamageWait % 5 == 1 && m_HP == 3) {
		m_HPTexture.Render(15 + 265 / 3 * 2 - m_HPTexture.GetWidth() / 2 - 10, 70);	//�E��
	}
	if (m_HP >= 5 || m_DamageWait % 5 == 1 && m_HP == 4) {
		m_HPTexture.Render(15 + 265 / 4 * 3 - m_HPTexture.GetWidth() / 2, 20);		//�E��
	}

	//���G����2�t���[���`�悵�Ȃ�
	if (m_DamageWait % 4 >= 2)
	{
		return;
	}

	//�`���`
	CRectangle br = m_SrcRect;

	//�`��ʒu
	float px = m_PosX;
	float py = m_PosY;

	//�L�����N�^�[�`��
	m_Texture.Render(px, py, br,MOF_ARGB(_chare_A,255,255,255));

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

	//CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "m_MoveY=%f", m_MoveY);


	//�L�����N�^�[�̔����`
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(GetLegsRect(), MOF_COLOR_GREEN);

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

	//�`��̉��
	m_HPTexture.Release();
	m_HPFrame.Release();

}

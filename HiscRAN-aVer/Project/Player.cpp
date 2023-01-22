//////////////////////////////////////////////
//	����L�����N�^�[�̃v���O�����ł��@�@�@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

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
	m_BSflg(true),
	m_MusicMgmt(),
	m_pEffectMgmt(),
	_unrivaled(),
	_chare_A()
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

	//�A�j���[�V������`�ϐ�
	float AnimationSquare = 2;

	//�A�j���[�V����
	SpriteAnimationCreate anim[] = 
	{

		{
			//���[�V����
			"�ړ�",
			0,0,
			160,185,
			TRUE,{{AnimationSquare,0,0},{AnimationSquare,1,0},{AnimationSquare,2,0},{AnimationSquare,3,0},{AnimationSquare,4,0},{AnimationSquare,5,0},{AnimationSquare,6,0},{AnimationSquare,7,0},{AnimationSquare,8,0},{AnimationSquare,9,0},{AnimationSquare,10,0}
			,{AnimationSquare,11,0},{AnimationSquare,12,0},{AnimationSquare,13,0},{AnimationSquare,14,0}}

		},
		//�W�����v
		{
			"�W�����v�J�n",
			0,185,
			160,185,
			FALSE,{{5,0,0}}
		},

		{
			"����",
			0,185,
			160,185,
			FALSE,{{5,1,0}}
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

	//�W�����v����
	if (g_pInput->IsKeyHold(MOFKEY_SPACE) && m_BSflg) {

		//������~
		m_MusicMgmt->SEStop(SE_T_FOOTSTEPS);

		//SE�Đ�
		m_MusicMgmt->SEStart(SE_T_JUMP);

		//�W�����v�J�E���g��1���₷
		m_JumpCount++;

		//�W�����v�t���O��False��
		m_Jumpflg = false;

		//���[�V������ύX����
		m_Motion.ChangeMotion(MOTION_JUMPSTART);

		//�召�W�����v�؂�ւ�
		//�X�y�[�X�������Ă���ԂɈ�莞�Ԓ�����Α�W�����v
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

	//���W�����A���j�~
	if (g_pInput->IsKeyPull(MOFKEY_SPACE)) {
		m_BSflg = false;
	}
	//�����Đ�
	if (m_Motion.GetMotionNo()== MOTION_MOVE&& !m_MusicMgmt->SEisPlay(SE_T_FOOTSTEPS)) {
		m_MusicMgmt->SEStart(SE_T_FOOTSTEPS);
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

	//������
	if (m_MoveY > 1) {

		//���ꂩ��~�肽���ɐ�p���[�V�����ɐ؂�ւ�
		//�W�����v���͂��Ȃ�
		if (m_Motion.GetMotionNo() == MOTION_MOVE) {
			//���������[�V����
			m_Motion.ChangeMotion(MOTION_JUMPFALL);

		}
		//����ɏ�邽�߂̏���
		m_Jumpflg = true;
		m_BSflg = false;

		//�����Đ�
		m_MusicMgmt->SEStop(SE_T_FOOTSTEPS);

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

void CPlayer::UpdateDebug(void)
{

	//�f�o�b�O�p
//���G�ɂȂ�
	if (g_pInput->IsKeyPull(MOFKEY_M)) {
		//���G��
		_unrivaled = _unrivaled ? !_unrivaled : !_unrivaled;

		//���G����������
		_chare_A = _unrivaled ? 125 : 255;
	}

	//�f�o�b�N
	//�_���[�W��H�炤
	if (g_pInput->IsKeyPull(MOFKEY_D)) {

		//�_���[�W����
		m_HP--;

		//�Q�[���I�[�o�[�X�V
		if (m_HP <= 0) {
			//���S�t���O�Z�b�g
			m_deathflg = true;
			m_HP = 0;

			//���G���ԂȂ�
			m_DamageWait = 0;
		}

	}

	if (g_pInput->IsKeyPull(MOFKEY_F)) {

		//�_���[�W����
		m_HP++;
	}


}

//����A��Q����Ɠ��������ꍇ
//�����Ffloat		y		����������Q���̂x���W
void CPlayer::UPdateCollisionBra(float y) {

	if (m_Jumpflg) {

		//�v���C���[�̈ʒu����ɏグ��
		//��Q����Ƀv���C���[�̑���������悤�ɂ��Ă���
		m_PosY = y- PLAYER_HIT_Y;

		m_MoveY = 0;

		//�W�����v�I����ɃN�[���^�C��
		m_JumpCount--;

		//�W�����v�J�E���g��10�ȏ�ɂȂ�Ȃ��悤�ɂ���
		if (m_JumpCount > 10)
		{
			m_JumpCount = 10;
		}
		else if (m_JumpCount <= 0)
		{
			//��W�����v�t���O��true�ɂ���
			m_BSflg = true;

			//�W�����v�J�E���g��0�ɂ���
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

	//�_���[�W�G�t�F�N�g�Đ�
	m_pEffectMgmt->Start(0,0,EFC_DAMAGE_HIT);

	//���G����
	m_DamageWait = INVINCIBLE_TIME;

	//�Q�[���I�[�o�[�X�V
	if (m_HP <= 0) {

		//���S�t���O�Z�b�g
		m_deathflg = true;
		m_HP = 0;

		//���G���ԂȂ�
		m_DamageWait = 0;

		m_MusicMgmt->SEStop(SE_T_FOOTSTEPS);
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

	//�����Đ�
	if (m_Motion.GetMotionNo() == MOTION_MOVE && !m_MusicMgmt->SEisPlay(SE_T_FOOTSTEPS)) {
		m_MusicMgmt->SEStart(SE_T_FOOTSTEPS);
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

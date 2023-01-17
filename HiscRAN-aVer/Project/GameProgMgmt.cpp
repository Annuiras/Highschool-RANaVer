#include "GameProgMgmt.h"

//////////////////////////////////////////////
//	�Q�[���̏����Ǘ�����v���O�����ł��@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �@�@�@�@�@�@�@�@�@�@ �@  //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

CGameProgMgmt::CGameProgMgmt():
Game_DPNum (),
Game_SP_DPNum(),
Game_Over_HP(),
DPdec_type(),
DPdec_SPflg(),
Gallery_flg(),
Option_Button_Pos()
{
}

CGameProgMgmt::~CGameProgMgmt()
{
}

//������
void CGameProgMgmt::Initialize(void)
{
	//������
	for (int i = 0; i < DP_COUNT; i++)
	{
		Game_DPNum[i] = 0;
		Game_SP_DPNum = 0;
		Game_CalStatus[i] = 0;
	}
	Game_Over_HP = false;
	DPdec_type = 0;

	for (int i = 0; i < 15; i++)
	{
		Gallery_flg[i] = false;
	}
	DPdec_SPflg = false;
}

//DP�ڕW�ݒ��ʁF�I��DP���Z�b�g
void CGameProgMgmt::SetDPdec_type(int type)
{
	DPdec_type = type;
}

//DP�ڕW�ݒ��ʁF�I��DP���Q�b�g
int CGameProgMgmt::GetDPdec_type(void)
{
	int Game_dp = 0;

	//DP�ڕW�ݒ��ʂƃQ�[����ʂ�DP�̎��ʔԍ����Ⴄ�̂ŕϊ����Ă��܂�
	switch (DPdec_type)
	{
	case 0:
		Game_dp = DP_IMAGINATION;
		break;
	case 1:
		Game_dp = DP_ACTION;
		break;

	case 2:
		Game_dp = DP_CHARM;
		break;

	case 3:
		Game_dp = DP_COMMUNICATION;
		break;

	case 4:
		Game_dp = DP_SCHOLASTIC;
		break;

	default:
		Game_dp = 100;
		break;
	}
	return Game_dp;
}

//DP�ڕW�ݒ��ʁFSP�t���O��
void CGameProgMgmt::SetDPdec_SPflg(bool b)
{
	DPdec_SPflg = b;
}

bool CGameProgMgmt::GetDPdec_SPflg(void)
{
	return DPdec_SPflg;
}

//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Z�b�g
void CGameProgMgmt::SetGame_Over_HP(bool b)
{
	Game_Over_HP = b;
}

//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Q�b�g
bool CGameProgMgmt::GetGame_Over_HP(void)
{
	return Game_Over_HP;
}

//DP�I����ʁF�X�e�[�^�X��������
void CGameProgMgmt::InitializeStatus(void)
{	
	//�X�e�[�^�X��������
	for (int i = 0; i < DP_COUNT; i++)
	{
		Game_CalStatus[i] = 0;
	}

}

//�Q�[����ʁFDP�擾�����Z�b�g
void CGameProgMgmt::SetGame_DPNum(int DP[])
{

	for (int i = 0; i < DP_COUNT; i++)
	{
		//�ʏ�X�e�[�W���Ɏ擾����DP�̐���ۑ�
		Game_DPNum[i] = DP[i];

		//�X�e�[�^�X�ɉ��Z
		Game_CalStatus[i] += Game_DPNum[i] * DP_CONVERSION_STATUS;
	}
}

//�Q�[����ʁFDP�擾�����Z�b�g
void CGameProgMgmt::SetGame_SP_DPNum(int SPDP)
{
	//SP���Ɏ擾����DP�̐���ۑ�
	Game_SP_DPNum = SPDP;

	//�X�e�[�^�X�ɉ��Z
	Game_CalStatus[GetDPdec_type()] += Game_SP_DPNum * SP_DP_CONVERSION_STATUS;
	
}

//�N���A��ʁFDP�擾������X�e�[�^�X��Ԃ�
int* CGameProgMgmt::GetCal_Status(void)
{
	return Game_CalStatus;
}

//�I�v�V������ʁF�{�^���ʒu���Z�b�g
void CGameProgMgmt::SetOption_Button_Pos(float BGM, float SE)
{

	Option_Button_Pos[0] = BGM;
	Option_Button_Pos[1] = SE;
	
}

//�I�v�V������ʁF�{�^���ʒu���Q�b�g
float CGameProgMgmt::GetOption_Button_Pos(int i)
{
	return Option_Button_Pos[i];
}

//�N���A��ʁF����󋵂��Z�b�g
//i:�e�p�ԍ�
//b:�Z�b�g����t���O
void CGameProgMgmt::SetGallery_flg(int i, bool b)
{
	Gallery_flg[i] = b;
}

//�M�������[��ʁF����󋵂��Q�b�g
//i:�e�p�ԍ�
bool CGameProgMgmt::GetGallery_flg(int i)
{
	return Gallery_flg[i];
}


//////////////////////////////////////////////
//	�Q�[���̏����Ǘ�����v���O�����ł��@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �@�@�@�@�@�@�@�@�@�@ �@  //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#include "GameProgMgmt.h"

CGameProgMgmt::CGameProgMgmt():
Game_DPNum (),
Game_SP_DPNum(),
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
	}
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
		//�G���[
		Game_dp = -1;
		break;
	}
	return Game_dp;
}

//DP�ڕW�ݒ��ʁFSP�t���O���Z�b�g
void CGameProgMgmt::SetDPdec_SPflg(bool b)
{
	DPdec_SPflg = b;
}

//�Q�[����ʁFSP�t���O���Q�b�g
bool CGameProgMgmt::GetDPdec_SPflg(void)
{
	return DPdec_SPflg;
}

//�Q�[����ʁFDP�擾�����Z�b�g
void CGameProgMgmt::SetGame_DPNum(int DP[])
{

	for (int i = 0; i < DP_COUNT; i++)
	{
		//�ʏ�X�e�[�W���Ɏ擾����DP�̐���ۑ�
		Game_DPNum[i] = DP[i];
	}
}

//�Q�[����ʁFDP�擾�����Z�b�g
void CGameProgMgmt::SetGame_SP_DPNum(int SPDP)
{
	//SP���Ɏ擾����DP�̐���ۑ�
	Game_SP_DPNum = SPDP;	
}

//�N���A��ʁFDP�擾����Ԃ�
int* CGameProgMgmt::Get_DPNum(void)
{
	return Game_DPNum;
}

//�N���A��ʁFSP_DP�擾����Ԃ�
int CGameProgMgmt::Get_SP_DPNum(void)
{
	return Game_SP_DPNum;
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


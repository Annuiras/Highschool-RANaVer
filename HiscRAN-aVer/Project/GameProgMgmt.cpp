#include "GameProgMgmt.h"

CGameProgMgmt::CGameProgMgmt():
Game_DPNum (),
Game_Over_HP()
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
	}


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

//�Q�[����ʁFDP�擾�����Z�b�g
void CGameProgMgmt::SetGame_DPNum(int DP[])
{
	for (int i = 0; i < DP_COUNT; i++)
	{
		Game_DPNum[i] = DP[i];
	}
}

//�Q�[����ʁFDP�擾�����Q�b�g
int* CGameProgMgmt::GetGame_DPNum(void)
{
	return Game_DPNum;
}


#include "GameProgMgmt.h"

CGameProgMgmt::CGameProgMgmt():
Game_DPNum ()
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


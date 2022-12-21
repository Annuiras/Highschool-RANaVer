#include "GameProgMgmt.h"

CGameProgMgmt::CGameProgMgmt():
Game_DPNum (),
Game_Over_HP()
{
}

CGameProgMgmt::~CGameProgMgmt()
{
}

//初期化
void CGameProgMgmt::Initialize(void)
{
	//初期化
	for (int i = 0; i < DP_COUNT; i++)
	{
		Game_DPNum[i] = 0;
	}


}

//ゲーム画面：ゲームオーバー原因フラグセット
void CGameProgMgmt::SetGame_Over_HP(bool b)
{
	Game_Over_HP = b;
}

//ゲーム画面：ゲームオーバー原因フラグゲット
bool CGameProgMgmt::GetGame_Over_HP(void)
{
	return Game_Over_HP;
}

//ゲーム画面：DP取得数をセット
void CGameProgMgmt::SetGame_DPNum(int DP[])
{
	for (int i = 0; i < DP_COUNT; i++)
	{
		Game_DPNum[i] = DP[i];
	}
}

//ゲーム画面：DP取得数をゲット
int* CGameProgMgmt::GetGame_DPNum(void)
{
	return Game_DPNum;
}


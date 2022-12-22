#include "GameProgMgmt.h"

CGameProgMgmt::CGameProgMgmt():
Game_DPNum (),
Game_Over_HP(),
DPdec_type()
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
	Game_Over_HP = false;
	DPdec_type = 0;
}

//DP目標設定画面：選択DPをセット
void CGameProgMgmt::SetDPdec_type(int type)
{
	DPdec_type = type;
}

//DP目標設定画面：選択DPをゲット
int CGameProgMgmt::GetDPdec_type(void)
{
	int Game_dp = 0;

	//DP目標設定画面とゲーム画面でDPの識別番号が違うので変換しています
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

//オプション画面：ボタン位置をセット
void CGameProgMgmt::SetOption_Button_Pos(float BGM, float SE)
{

	Option_Button_Pos[0] = BGM;
	Option_Button_Pos[1] = SE;
	
}

//オプション画面：ボタン位置をゲット
float CGameProgMgmt::GetOption_Button_Pos(int i)
{
	return Option_Button_Pos[i];
}


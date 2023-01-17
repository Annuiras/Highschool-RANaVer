#include "GameProgMgmt.h"

//////////////////////////////////////////////
//	ゲームの情報を管理するプログラムです　　//
//									　　　　//
//　作成者：田中 環　　　　　　　　　　 　  //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
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

//初期化
void CGameProgMgmt::Initialize(void)
{
	//初期化
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

//DP目標設定画面：SPフラグを
void CGameProgMgmt::SetDPdec_SPflg(bool b)
{
	DPdec_SPflg = b;
}

bool CGameProgMgmt::GetDPdec_SPflg(void)
{
	return DPdec_SPflg;
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

//DP選択画面：ステータスを初期化
void CGameProgMgmt::InitializeStatus(void)
{	
	//ステータスを初期化
	for (int i = 0; i < DP_COUNT; i++)
	{
		Game_CalStatus[i] = 0;
	}

}

//ゲーム画面：DP取得数をセット
void CGameProgMgmt::SetGame_DPNum(int DP[])
{

	for (int i = 0; i < DP_COUNT; i++)
	{
		//通常ステージ中に取得したDPの数を保存
		Game_DPNum[i] = DP[i];

		//ステータスに加算
		Game_CalStatus[i] += Game_DPNum[i] * DP_CONVERSION_STATUS;
	}
}

//ゲーム画面：DP取得数をセット
void CGameProgMgmt::SetGame_SP_DPNum(int SPDP)
{
	//SP中に取得したDPの数を保存
	Game_SP_DPNum = SPDP;

	//ステータスに加算
	Game_CalStatus[GetDPdec_type()] += Game_SP_DPNum * SP_DP_CONVERSION_STATUS;
	
}

//クリア画面：DP取得数からステータスを返す
int* CGameProgMgmt::GetCal_Status(void)
{
	return Game_CalStatus;
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

//クリア画面：解放状況をセット
//i:容姿番号
//b:セットするフラグ
void CGameProgMgmt::SetGallery_flg(int i, bool b)
{
	Gallery_flg[i] = b;
}

//ギャラリー画面：解放状況をゲット
//i:容姿番号
bool CGameProgMgmt::GetGallery_flg(int i)
{
	return Gallery_flg[i];
}


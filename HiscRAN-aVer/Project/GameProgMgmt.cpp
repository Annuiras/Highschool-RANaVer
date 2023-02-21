//////////////////////////////////////////////
//	ゲームの情報を管理するプログラムです　　//
//									　　　　//
//　作成者：田中 環　　　　　　　　　　 　  //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
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

//初期化
void CGameProgMgmt::Initialize(void)
{
	//初期化
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
		//エラー
		Game_dp = -1;
		break;
	}
	return Game_dp;
}

//DP目標設定画面：SPフラグをセット
void CGameProgMgmt::SetDPdec_SPflg(bool b)
{
	DPdec_SPflg = b;
}

//ゲーム画面：SPフラグをゲット
bool CGameProgMgmt::GetDPdec_SPflg(void)
{
	return DPdec_SPflg;
}

//ゲーム画面：DP取得数をセット
void CGameProgMgmt::SetGame_DPNum(int DP[])
{

	for (int i = 0; i < DP_COUNT; i++)
	{
		//通常ステージ中に取得したDPの数を保存
		Game_DPNum[i] = DP[i];
	}
}

//ゲーム画面：DP取得数をセット
void CGameProgMgmt::SetGame_SP_DPNum(int SPDP)
{
	//SP中に取得したDPの数を保存
	Game_SP_DPNum = SPDP;	
}

//クリア画面：DP取得数を返す
int* CGameProgMgmt::Get_DPNum(void)
{
	return Game_DPNum;
}

//クリア画面：SP_DP取得数を返す
int CGameProgMgmt::Get_SP_DPNum(void)
{
	return Game_SP_DPNum;
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


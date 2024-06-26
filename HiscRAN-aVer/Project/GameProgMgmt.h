//////////////////////////////////////////////
//	ゲームの情報を管理するプログラムです　　//
//									　　　　//
//　作成者：田中 環　　　　　　　　　　 　  //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Game.h"
#include "Define_Clear.h"

//ゲーム情報受け渡しクラス
class CGameProgMgmt
{

private:

	//ゲームクリア時のDPの取得数保存用
	//0:学力
	//1:行動力
	//2:想像力
	//3:コミュ力
	//4:魅力
	int Game_DPNum[DP_COUNT];
	int Game_SP_DPNum;

	//DP目標設定画面：選択DP番号
	int DPdec_type;

	//DP目標設定画面：SPありフラグ
	bool DPdec_SPflg;

	//オプション画面：ボタン位置保存
	//0:BGM
	//1:SE
	float Option_Button_Pos[2];

	//ギャラリー解放状況を保存
	bool Gallery_flg[15];

public:
	CGameProgMgmt(); 
	~CGameProgMgmt();

	//初期化
	void Initialize(void);

	//DP目標設定画面：選択DPをセット
	void SetDPdec_type(int type);
	//ゲーム画面：選択DPをゲット
	int GetDPdec_type(void);

	//DP選択画面画面：SPフラグをセット
	void SetDPdec_SPflg(bool b);
	//ゲーム画面：SPフラグをゲット
	bool GetDPdec_SPflg(void);

	//ゲーム画面：DP取得数をセット
	void SetGame_DPNum(int DP[]);
	//ゲーム画面：SP_DP取得数をセット
	void SetGame_SP_DPNum(int SPDP);

	//クリア画面：DP取得数を返す
	int* Get_DPNum(void);

	//クリア画面：SP_DP取得数を返す
	int Get_SP_DPNum(void);

	//オプション画面：ボタン位置をセット
	void SetOption_Button_Pos(float BGM,float SE);

	//オプション画面：ボタン位置をゲット
	//0:BGM
	//1:SE
	float GetOption_Button_Pos(int i);

	//ギャラリー画面：解放状況をセット
	//i:容姿番号
	//b:セットするフラグ
	void SetGallery_flg(int i, bool b);

	//ギャラリー画面：解放状況をゲット
	//i:容姿番号
	bool GetGallery_flg(int i);

};


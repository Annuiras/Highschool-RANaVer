#pragma once
#include "Define.h"

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


public:
	CGameProgMgmt(); 
	~CGameProgMgmt();

	//初期化
	void Initialize(void);

	//ゲーム画面：DP取得数をセット
	void SetGame_DPNum(int DP[]);
	//ゲーム画面：DP取得数をゲット
	int* GetGame_DPNum(void);
};


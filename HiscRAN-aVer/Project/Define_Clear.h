#pragma once

///////////////////////////////////////////////////////
//　クリア画面で使用する定数を宣言している場所です　 //
//								   　　　　　　　　　//
//　作成者：田中環　  　　　　　　　　　  　　　　　 //
//								   　　　 　　　　　 //
//　リファクタリングした人：田中環 　　　 　　　　　 //
//								   　　　　　　　　  //
//　最終更新：2023/01/20		   　　　 　　　　　 //
///////////////////////////////////////////////////////

#pragma region クリア画面定数群

#define CHART_SIZE 248			// チャート半径
#define CHART_CENTER_X 325	    // チャート中心座標 X
#define CHART_CENTER_Y 478	    // チャート中心座標 Y

#define MAX_STATUS 100			// ステータス最大値
#define ITEM_NUM 5				// ステータス個数

#define DIFFERENCE_NUM 15		// 一点突破用,2位との差が以上の場合一点突破 

#define DP_CONVERSION_STATUS 2.5	//通常DP倍率

#define SP_DP_CONVERSION_STATUS 1	//SPステージDP倍率

#pragma endregion

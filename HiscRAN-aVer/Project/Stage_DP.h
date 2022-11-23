#pragma once
#include "Stage.h"
#include "Define.h"
//vectorを使った動的配列試したけどうまく宣言できなかった


//s_stageAdp
//[]:マップ一枚の情報がいくつあるか(数値は省略可能)
//[DP_INFO_STRUCT]:マップ一枚分の情報にいくつ構造体があるか
//1分ステージのDP配置情報

//仕様上、値を昇順にしないとうまく表示できない
//スクロール値は0にならないため0.0fで出現はエラー
//{0,0,100}->終端文字の役割、この要素を参照すると次のパターンに移行
DP_info s_stageAdp[][DP_INFO_STRUCT] =
{
	//マップパターン0 S1
	{		
		{245.0f,336.0f,	DP_IMAGINATION},
		{611.0f,219.0f,	DP_CHARM},
		{1346.0f,339.0f,DP_ACTION},
		{1963.0f,207.0f,DP_SCHOLASTIC},
		{2402.0f,168.0f,DP_COMMUNICATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン1 S2
	{
		{253.0f,319.0f,DP_SCHOLASTIC},
		{820.0f,202.0f,DP_COMMUNICATION},
		{1253.0f,441.0f,DP_CHARM},
		{1291.0f,118.0f,DP_IMAGINATION},
		{1540.0f,513.0f,DP_CHARM},
		{1573.0f,188.0f,DP_IMAGINATION},
		{2009.0f,22.0f,DP_SCHOLASTIC},
		{2042.0f,486.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン2 S3
	{
		{328.0f,210.0f,DP_COMMUNICATION},
		{338.0f,536.0f,DP_ACTION},
		{1265.0f,48.0f,DP_SCHOLASTIC},
		{1258.0f,526.0f,DP_IMAGINATION},
		{1696.0f,526.0f,DP_CHARM},
		{2104.0f,196.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン3 S4
	{
		{104.0f,462.0f,	DP_IMAGINATION},
		{142.0f,270.0f,	DP_SCHOLASTIC},
		{268.0f,89.0f,	DP_SCHOLASTIC},
		{329.0f,549.0f,	DP_COMMUNICATION},
		{479.0f,119.0f,	DP_CHARM},
		{535.0f,360.0f,	DP_SCHOLASTIC},
		{737.0f,72.0f,	DP_ACTION},
		{803.0f,320.0f,	DP_COMMUNICATION},
		{843.0f,549.0f,	DP_CHARM},//
		{920.0f,17.0f,	DP_ACTION},
		{955.0f,320.0f,	DP_COMMUNICATION},
		{1287.0f,327.0f,DP_IMAGINATION},
		{1450.0f,327.0f,DP_IMAGINATION},
		{1509.0f,111.0f,DP_CHARM},
		{1509.0f,550.0f,DP_ACTION},
		{1623.0f,326.0f,DP_CHARM},
		{1935.0f,4.0f,	DP_SCHOLASTIC},
		{1962.0f,366.0f,DP_COMMUNICATION},
		{2218.0f,554.0f,DP_IMAGINATION},
		{2308.0f,88.0f,	DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン4 S5
	{
		{58.0f,292.0f,	DP_IMAGINATION},
		{180.0f,25.0f,	DP_IMAGINATION},
		{278.0f,292.0f,	DP_COMMUNICATION},
		{400.0f,25.0f,	DP_COMMUNICATION},
		{499.0f,292.0f,	DP_SCHOLASTIC},
		{621.0f,25.0f,	DP_SCHOLASTIC},
		{720.0f,292.0f,	DP_ACTION},
		{842.0f,25.0f,	DP_ACTION},
		{939.0f,291.0f,	DP_CHARM},
		{1061.0f,24.0f,	DP_CHARM},
		{1485.0f,418.0f,DP_ACTION},
		{1605.0f,187.0f,DP_IMAGINATION},
		{1704.0f,471.0f,DP_CHARM},
		{1825.0f,187.0f,DP_SCHOLASTIC},
		{2046.0f,187.0f,DP_SCHOLASTIC},

		{10000,0,DP_COUNT}
	},
	//マップパターン5
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン6
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン7
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン8
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン9
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン10
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン11
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン12
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン13
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン14
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION一時的な変更
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	}

};
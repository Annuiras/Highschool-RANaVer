#pragma once
#include "Stage.h"
#include <vector>

//vectorを使った動的配列試したけどうまく宣言できなかった


//ステージのBAR配置情報
//仕様上:値を昇順にしないとうまく表示できません
//スクロール値は0にならないため0.0fで出現はエラー
//{10000,0,BAR_COUNT}->終端文字の役割、この要素を参照すると次のパターンに移行
BAR_info s_stageBAR[][BAR_INFO_STRUCT] =
{
	//マップパターン0 S1
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン1 S2
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン2 S3
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン3 S4
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン4 S5
	{
		{482.0f,345.0f,BAR_MEDIUM},
		{10000,0,BAR_COUNT}
	},
	//マップパターン5 S6
	{
		{1392.0f,345.0f,BAR_BIG},
		{10000,0,BAR_COUNT}
	},
	//マップパターン6 S7
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン7 S8
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン8 S9
	{
		{1695.0f,345.0f,BAR_MEDIUM},
		{10000,0,BAR_COUNT}

	},
	//マップパターン9
	{
		{405.0f,345.0f,BAR_BIG},
		{1582.0f,345.0f,BAR_MEDIUM},
		{10000,0,BAR_COUNT}
	},
	//マップパターン10
	{
		{371.0f,345.0f,BAR_MEDIUM},
		{1925.0f,345.0f,BAR_MEDIUM},
		{10000,0,BAR_COUNT}
	},
	//マップパターン11
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン12
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン13
	{
		{1717,345,BAR_MEDIUM},

		{10000,0,BAR_COUNT}
	},
	//マップパターン14
	{
		{590.0f,345.0f,BAR_BIG},
		{2045.0f,575.0f,BAR_MEDIUM},
		{10000,0,BAR_COUNT}
	},
	//マップパターン15
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン16
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン17
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン18
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン19
	{
		{10000,0,BAR_COUNT}
	},
	//マップパターン20
	{
		{10000,0,BAR_COUNT}
	}

};
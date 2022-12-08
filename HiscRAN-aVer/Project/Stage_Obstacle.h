#pragma once
#include "Stage.h"
#include "Define.h"

//ステージのDP配置情報

//仕様:値を昇順にしないとうまく表示できません
//スクロール値は0にならないため0.0fで出現はエラー
//{10000,0,OB_COUNT}->終端文字の役割、この要素を参照すると次のパターンに移行
OB_info s_stageOB[][OB_INFO_STRUCT] =
{
	//マップパターン0 S1
	{
		{316.0f,524.0f,OB_DESK},
		{447.0f,524.0f,OB_DESK},
		{578.0f,404.0f,OB_TWODESK},
		{709.0f,404.0f,OB_TWODESK},
		{1343.0f,524.0f,OB_DESK},
		{2091.0f,388.0f,OB_LOCKER},
		{2229.0f,388.0f,OB_LOCKER},
		{10000,0,OB_COUNT}
	},
	//マップパターン1 S2
	{
		{288.0f,524.0f,OB_DESK},
		{419.0f,524.0f,OB_DESK},
		{550.0f,524.0f,OB_DESK},
		{680.0f,404.0f,OB_TWODESK},
		{810.0f,404.0f,OB_TWODESK},
		{940.0f,404.0f,OB_TWODESK},
		{10000,0,OB_COUNT}
	},
	//マップパターン2 S3
	{
		{906.0f,524.0f,OB_DESK},
		{1038.0f,524.0f,OB_DESK},
		{2032.0f,404.0f,OB_TWODESK},
		{2166.0f,524.0f,OB_DESK},
		{10000,0,OB_COUNT}
	},
	//マップパターン3 S4
	{
		{579.0f,519.0f,OB_TEXTBOOKCHEM},
		{710.0f,519.0f,OB_TEXTBOOKCHEM},
		{1747.0f,507.0f,OB_VAULTINGHORSE},
		{1964.0f,507.0f,OB_VAULTINGHORSE},
		{10000,0,OB_COUNT}
	},
	//マップパターン4 S5
	{
		{548.0f,520.0f,OB_SCOTCHTAPE},
		{868.0f,520.0f,OB_SCOTCHTAPE},
		{1188.0f,398.0f,OB_TRACHCAN},
		{1319.0f,580.0f,OB_BLOACKBOARDERASER},
		{1569.0f,580.0f,OB_BLOACKBOARDERASER},

		{10000,0,OB_COUNT}
	},
	//マップパターン5
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン6
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン7
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン8
	{
		{10000,0,OB_COUNT}

	},
	//マップパターン9
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン10
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン11
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン12
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン13
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン14
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン15
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン16
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン17
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン18
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン19
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン20
	{
		{10000,0,OB_COUNT}
	}

};
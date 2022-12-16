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
		{889.0f,398.0f,OB_TRACHCAN},
		{1020.0f,398.0f,OB_TRACHCAN},
		{1151.0f,398.0f,OB_TRACHCAN},
		{10000,0,OB_COUNT}
	},
	//マップパターン1 S2
	{
		{360.0f,519.0f,OB_TEXTBOOKSOC},
		{491.0f,519.0f,OB_TEXTBOOKSOC},
		{622.0f,519.0f,OB_TEXTBOOKENG},
		{1274.0f,519.0f,OB_TEXTBOOKNL},
		{1956.0f,519.0f,OB_TEXTBOOKCHEM},
		{2087.0f,519.0f,OB_TEXTBOOKMATH},
		{10000,0,OB_COUNT}
	},
	//マップパターン2 S3
	{
		{948.0f,520.0f,OB_SCOTCHTAPE},
		{1268.0f,520.0f,OB_SCOTCHTAPE},
		{1588.0f,396.0f,OB_SEAWEED},
		{1698.0f,396.0f,OB_SEAWEED},
		{10000,0,OB_COUNT}
	},
	//マップパターン3 S4
	{
		{660.0f,460.0f,OB_SMARTPHONE1},
		{1090.0f,570.0f,OB_ERASER},
		{1290.0f,570.0f,OB_ERASER},
		{10000,0,OB_COUNT}
	},
	//マップパターン4 S5
	{
		{1771.0f,383.0f,OB_LOCKER},
		{1909.0f,507.0f,OB_VAULTINGHORSE},

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
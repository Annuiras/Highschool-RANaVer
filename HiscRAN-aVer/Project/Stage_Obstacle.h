//////////////////////////////////////////////
//	障害物の配置情報です			　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "Stage.h"

//ステージの障害物配置情報

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
	//マップパターン5 S6
	{
		{650.0f,580.0f,OB_BLOACKBOARDERASER},
		{900.0f,580.0f,OB_BLOACKBOARDERASER},
		{10000,0,OB_COUNT}
	},
	//マップパターン6 S7
	{
		{311.0f,520.0f,OB_TEXTBOOKMATH},
		{902.0f,520.0f,OB_TEXTBOOKMATH},
		{1033.0f,520.0f,OB_TEXTBOOKMATH},
		{1587.0f,520.0f,OB_SCOTCHTAPE},
		{1907.0f,395.0f,OB_SEAWEED},
		{10000,0,OB_COUNT}
	},
	//マップパターン7 S8
	{
		{434.0f,508.0f,OB_VAULTINGHORSE},
		{651.0f,508.0f,OB_VAULTINGHORSE},
		{1007.0f,579.0f,OB_BLOACKBOARDERASER},
		{1257.0f,579.0f,OB_BLOACKBOARDERASER},
		{1507.0f,398.0f,OB_TRACHCAN},
		{10000,0,OB_COUNT}
	},
	//マップパターン8 S9
	{
		{320.0f,519.0f,OB_TEXTBOOKNL},
		{452.0f,519.0f,OB_TEXTBOOKMATH},
		{583.0f,519.0f,OB_TEXTBOOKENG},
		{1123.0f,570.0f,OB_ERASER},
		{1324.0f,570.0f,OB_ERASER},
		{10000,0,OB_COUNT}

	},
	//マップパターン9 S10
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン10 S11
	{
		{1221.0f,460.0f,OB_SMARTPHONE1},
		{10000,0,OB_COUNT}
	},
	//マップパターン11 S12
	{
		{629,519,OB_SCOTCHTAPE},
		{949,519,OB_SCOTCHTAPE},
		{1269,382,OB_LOCKER},
		{1408,382,OB_LOCKER},
		{1546,382,OB_LOCKER},
		{1684,259,OB_SMARTPHONEVERTICAL},
		{10000,0,OB_COUNT}
	},
	//マップパターン12 S13
	{

		{438,507,OB_VAULTINGHORSE},
		{1526,507,OB_VAULTINGHORSE},
		{1743,570,OB_ERASER},
		{1943,570,OB_ERASER},
		{10000,0,OB_COUNT}
	},
	//マップパターン13 S14
	{

		{474,382,OB_LOCKER},
		{612,459,OB_SMARTPHONE1},
		{1042,579,OB_BLOACKBOARDERASER},
		{10000,0,OB_COUNT}
	},
	//マップパターン14 S15
	{
		{1259.0f,519.0f,OB_TEXTBOOKSOC},
		{1390.0f,519.0f,OB_TEXTBOOKCHEM},
		{10000,0,OB_COUNT}
	},
	//マップパターン15 SP1
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン16 SP2
	{
		{10000,0,OB_COUNT}
	},
	//マップパターン17 最後
	{
		{10000,0,OB_COUNT}
	},
};
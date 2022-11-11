#pragma once
#include "Stage.h"
#include <vector>

//vectorを使った動的配列試したけどうまく宣言できなかった


//s_stageAdp
//[]:マップ一枚の情報がいくつあるか(数値は省略可能)
//[DP_INFO_STRUCT]:マップ一枚分の情報にいくつ構造体があるか
//1分ステージのDP配置情報
//障害物種類（仮）
//1:机
//2:２段机
//仕様上、値を昇順にしないとうまく表示できない
//スクロール値は0にならないため0.0fで出現はエラー
//{0,0,100}->終端文字の役割、この要素を参照すると次のパターンに移行
OB_info s_stageAOB[][OB_INFO_STRUCT] =
{
	//マップパターン0
	{
		{316.0f,520.0f,OB_DESK},
		{447.0f,520.0f,OB_DESK},
		{578.0f,399.0f,OB_TWODESK},
		{709.0f,399.0f,	OB_TWODESK},
		{1252.0f,399.0f,OB_TWODESK},
		{1383.0f,519.0f,OB_DESK},
		{2091.0f,382.0f,OB_LOCKER},
		{2229.0f,382.0f,OB_LOCKER},

		//{184.0f,511.0f ,OB_DESK},
		//{1800.0f,511.0f ,OB_DESK},
		//{1937.0f,384.0f,OB_TWODESK},
		{10000,0,100}
	},
	//マップパターン1
	{
		{316.0f,520.0f,OB_DESK},
		{447.0f,520.0f,OB_DESK},
		{578.0f,399.0f,OB_TWODESK},	
		{709.0f,399.0f,	OB_TWODESK},
		{1252.0f,399.0f,OB_TWODESK},
		{1383.0f,519.0f,OB_DESK},
		{2091.0f,382.0f,OB_LOCKER},
		{2229.0f,382.0f,OB_LOCKER},
		{10000,0,100}
	},
	//マップパターン2
	{
		{10000,0,100}
	},
	//マップパターン3
	{
		{10000,0,100}
	},
	//マップパターン4
	{
		{10000,0,100}
	},
	//マップパターン5
	{
		{10000,0,100}
	},
	//マップパターン6
	{
		{10000,0,100}
	},
	//マップパターン7
	{
		{10000,0,100}
	},
	//マップパターン8
	{
		{10000,0,100}

	},
	//マップパターン9
	{
		{10000,0,100}
	},
	//マップパターン10
	{
		{10000,0,100}
	},
	//マップパターン11
	{
		{10000,0,100}
	},
	//マップパターン12
	{
		{10000,0,100}
	},
	//マップパターン13
	{
		{10000,0,100}
	},
	//マップパターン14
	{
		{10000,0,100}
	}

};
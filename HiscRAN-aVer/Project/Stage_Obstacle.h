#pragma once
#include "Stage.h"
#include "Define.h"

//vectorを使った動的配列試したけどうまく宣言できなかった

//地面に設置する形なら計算で算出出来るかもできたら定義が楽になる
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
	}

};
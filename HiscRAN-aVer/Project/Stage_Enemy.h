//////////////////////////////////////////////
//	敵（ヤンキー）の配置情報です			//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "Stage.h"

//ステージの敵配置情報
//仕様:値を昇順にしないとうまく表示できません
//スクロール値は0にならないため0.0fで出現はエラー
//{10000,0,DP_COUNT}->終端文字の役割、この要素を参照すると次のパターンに移行
ENEMY_info s_stageENEMY[][ENEMY_INFO_STRUCT] =
{
	//マップパターン0 S1
	{
		{2252.0f,503.0f,ENEMY_1},
		{ 10000,0,ENEMY_COUNT }
	},
	//マップパターン1 S2
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン2 S3
	{
		{788.0f,505.0f,ENEMY_1},
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン3 S4
	{
		{2361.0f,503.0f,ENEMY_1},
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン4 S5
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン5 S6
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン6 S7
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン7 S8
	{
		{2399.0f,505.0f,ENEMY_1},
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン8 S9
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン9 S10
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン10 S11
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン11 S12
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン12 S13
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン13 S14
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン14 S15
	{
		{1213.0f,160.0f,ENEMY_1},
		{2377.0f,505,ENEMY_1},
		{10000,0,ENEMY_COUNT}
	},
	//マップパターン15 SP1
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//マップパターン16 SP2
	{
		{ 10000,0,ENEMY_COUNT}
	},
	//最後17
	{
		{ 10000,0,ENEMY_COUNT}
	},

};
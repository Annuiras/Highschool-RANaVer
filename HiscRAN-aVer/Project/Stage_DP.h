#pragma once
#include "Stage.h"
#include "Define.h"

//ステージのDP配置情報
//仕様:値を昇順にしないとうまく表示できません
//スクロール値は0にならないため0.0fで出現はエラー
//{10000,0,DP_COUNT}->終端文字の役割、この要素を参照すると次のパターンに移行
DP_info s_stageDP[][DP_INFO_STRUCT] =
{
	//マップパターン0 S1
	{		
		{125.0f,464.0f,	DP_SCHOLASTIC},
		{226.0f,160.0f,	DP_ACTION},
		{592.0f,114.0f,DP_COMMUNICATION},
		{710.0f,516.0f,DP_CHARM},
		{1076.0f,20.0f,DP_IMAGINATION},
		{1323.0f,508.0f,DP_SCHOLASTIC},
		{1468.0f,84.0f,DP_ACTION},
		{1658.0f,332.0f,DP_COMMUNICATION},
		{2008.0f,174.0f,DP_CHARM},
		{2370.0f,280.0f,DP_IMAGINATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン1 S2
	{
		{31.0f,436.0f,DP_SCHOLASTIC},
		{279.0f,154.0f,DP_COMMUNICATION},
		{428.0f,327.0f,DP_COMMUNICATION},
		{569.0f,23.0f,DP_ACTION},
		{613.0f,327.0f,DP_CHARM},
		{786.0f,548.0f,DP_CHARM},
		{1077.0f,548.0f,DP_ACTION},
		{1279.0f,367.0f,DP_ACTION},
		{1279.0f,153.0f,DP_SCHOLASTIC},
		{1627.0f,231.0f,DP_COMMUNICATION},
		{1786.0f,540.0f,DP_IMAGINATION},
		{1943.0f,327.0f,DP_SCHOLASTIC},
		{2140.0f,324.0f,DP_IMAGINATION},
		{2310.0f,542.0f,DP_IMAGINATION},
		{2338.0f,76.0f,DP_CHARM},
		{10000,0,DP_COUNT}
	},
	//マップパターン2 S3
	{
		{75.0f,523.0f,DP_IMAGINATION},
		{433.0f,160.0f,DP_CHARM},
		{926.0f,371.0f,DP_ACTION},
		{1025.0f,37.0f,DP_COMMUNICATION},
		{1247.0f,32.0f,DP_SCHOLASTIC},
		{1234.0f,355.0f,DP_CHARM},
		{1628.0f,219.0f,DP_IMAGINATION},
		{1847.0f,541.0f,DP_COMMUNICATION},
		{1937.0f,31.0f,DP_SCHOLASTIC},
		{2203.0f,312.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン3 S4
	{
		{139.0f,527.0f,	DP_IMAGINATION},
		{412.0f,143.0f,	DP_COMMUNICATION},
		{498.0f,528.0f,	DP_SCHOLASTIC},
		{706.0f,306.0f,	DP_ACTION},
		{1110.0f,430.0f,DP_CHARM},
		{1184.0f,186.0f,DP_SCHOLASTIC},
		{1703.0f,123.0f,DP_IMAGINATION},
		{1780.0f,538.0f,DP_CHARM},
		{2292.0f,335.0f,DP_COMMUNICATION},
		{2366.0f,104.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン4 S5
	{
		{172.0f,486.0f,	DP_CHARM},
		{474.0f,197.0f,	DP_SCHOLASTIC},
		{616.0f,482.0f,	DP_ACTION},
		{711.0f,197.0f,	DP_IMAGINATION},
		{878.0f,482.0f,	DP_COMMUNICATION},
		{1108.0f,476.0f,DP_ACTION},
		{1216.0f,116.0f,DP_CHARM},
		{1530.0f,501.0f,DP_COMMUNICATION},
		{1984.0f,56.0f,	DP_IMAGINATION},
		{2260.0f,51.0f,	DP_SCHOLASTIC},
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
	},
		//マップパターン15  SPアイテム出現
	{
		{300.0f, 350.0f, DP_CHARM},	
		{ 700.0f,229.0f,	DP_CHARM },
		{ 1500.0f,300.0f,DP_IMAGINATION },
		{ 1775.0f,231.0f,DP_COMMUNICATION },
		{ 2000.0f,66.0f,	DP_SCHOLASTIC },
		{ 10000,0,DP_COUNT }
	},
		//マップパターン16  SP配置1
	{
		{250.0f,350.0f,DP_CHARM},
		{536.0f,229.0f,	DP_CHARM},
		{884.0f,302.0f,DP_CHARM},
		{1775.0f,231.0f,DP_CHARM},
		{1862.0f,66.0f,	DP_CHARM},
		{10000,0,DP_COUNT}
	},
			//マップパターン17  SP配置2
	{
		{180.0f,350.0f,DP_ACTION},
		{556.0f,229.0f,	DP_ACTION},
		{584.0f,222.0f,DP_ACTION},
		{1675.0f,231.0f,DP_ACTION},
		{1762.0f,66.0f,	DP_ACTION},
		{10000,0,DP_COUNT}
	},
			//マップパターン18  SP配置3
	{
		{270.0f, 350.0f, DP_ACTION},
		{796.0f,229.0f,	DP_IMAGINATION },
		{984.0f,222.0f,DP_CHARM },
		{1375.0f,231.0f,DP_SCHOLASTIC },
		{2162.0f,66.0f,	DP_COMMUNICATION },
		{10000,0,DP_COUNT }
	},
			//マップパターン19  SP配置4
	{
		{ 270.0f, 350.0f, DP_IMAGINATION},
		{ 796.0f,229.0f,	DP_CHARM },
		{ 984.0f,222.0f,DP_ACTION },
		{ 1375.0f,231.0f,DP_COMMUNICATION},
		{ 2162.0f,66.0f,DP_ACTION },
		{ 10000,0,DP_COUNT }
	},
			//マップパターン20  SP配置5
	{
		{270.0f, 350.0f, DP_ACTION},
		{796.0f,229.0f,	DP_COMMUNICATION },
		{984.0f,222.0f,DP_CHARM},
		{1375.0f,231.0f,DP_IMAGINATION },
		{2162.0f,66.0f,	DP_SCHOLASTIC },
		{10000,0,DP_COUNT }
	}

};
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
		{226.0f,585.0f,	DP_SCHOLASTIC},
		{226.0f,160.0f,	DP_ACTION},
		{672.0f,111.0f,DP_COMMUNICATION},
		{748.0f,551.0f,DP_CHARM},
		{1076.0f,20.0f,DP_IMAGINATION},
		{1323.0f,508.0f,DP_SCHOLASTIC},
		{1352.0f,14.0f,DP_ACTION},
		{2008.0f,174.0f,DP_CHARM},
		{2412.0f,184.0f,DP_COMMUNICATION},
		{2421.0f,580.0f,DP_IMAGINATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン1 S2
	{
		{1.0f,570.0f,DP_SCHOLASTIC},
		{279.0f,154.0f,DP_COMMUNICATION},
		{428.0f,327.0f,DP_COMMUNICATION},
		{569.0f,23.0f,DP_ACTION},
		{613.0f,327.0f,DP_CHARM},
		{786.0f,548.0f,DP_CHARM},
		{1146.0f,568.0f,DP_ACTION},
		{1279.0f,153.0f,DP_SCHOLASTIC},
		{1280.0f,399.0f,DP_ACTION},
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
		{42.0f,572.0f,DP_IMAGINATION},
		{433.0f,160.0f,DP_CHARM},
		{926.0f,371.0f,DP_ACTION},
		{1230.0f,407.0f,DP_CHARM},
		{1247.0f,32.0f,DP_ACTION},
		{1628.0f,219.0f,DP_IMAGINATION},
		{1813.0f,566.0f,DP_COMMUNICATION},
		{1937.0f,31.0f,DP_SCHOLASTIC},
		{2203.0f,312.0f,DP_SCHOLASTIC},
		{2427.0f,171.0f,DP_COMMUNICATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン3 S4
	{
		{118.0f,569.0f,	DP_IMAGINATION},
		{527.0f,137.0f,	DP_COMMUNICATION},
		{532.0f,568.0f,	DP_SCHOLASTIC},
		{927.0f,339.0f,	DP_ACTION},
		{1110.0f,430.0f,DP_CHARM},
		{1404.0f,149.0f,DP_SCHOLASTIC},
		{1497.0f,579.0f,DP_CHARM},
		{1891.0f,143.0f,DP_IMAGINATION},
		{2380.0f,150.0f,DP_ACTION},
		{2402.0f,568.0f,DP_COMMUNICATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン4 S5
	{
		{94.0f,576.0f,	DP_CHARM},
		{474.0f,197.0f,	DP_SCHOLASTIC},
		{616.0f,482.0f,	DP_ACTION},
		{711.0f,197.0f,	DP_IMAGINATION},
		{878.0f,482.0f,	DP_COMMUNICATION},
		{1216.0f,170.0f,DP_CHARM},
		{1216.0f,576.0f,DP_ACTION},
		{1629.0f,576.0f,DP_COMMUNICATION},
		{1984.0f,56.0f,	DP_IMAGINATION},
		{2132.0f,573.0f,DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン5 S6
	{
		{84.0f,573.0f,DP_COMMUNICATION},
		{425.0f,173.0f,	DP_SCHOLASTIC},
		{506.0f,550.0f,DP_ACTION},
		{716.0f,426.0f,DP_COMMUNICATION},
		{840.0f,54.0f,DP_IMAGINATION},
		{964.0f,426.0f,DP_CHARM},
		{1173.0f,164.0f,DP_SCHOLASTIC},
		{1159.0f,573.0f,DP_ACTION},
		{1436.0f,484.0f,DP_IMAGINATION},
		{1465.0f,46.0f,DP_CHARM},
		{1632.0f,484.0f,DP_ACTION},
		{1671.0f,46.0f,DP_SCHOLASTIC},
		{1822.0f,484.0f,DP_IMAGINATION},
		{1884.0f,46.0f,DP_CHARM},
		{2261.0f,300.0f,DP_COMMUNICATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン6 S7
	{
		{170.0f,144.0f,	DP_COMMUNICATION},
		{447.0f,574.0f,	DP_CHARM},
		{800.0f,574.0f,DP_SCHOLASTIC},
		{960.0f,357.0f,DP_IMAGINATION},
		{1171.0f,574.0f,DP_ACTION},
		{1270.0f,97.0f,DP_CHARM},
		{1463.0f,570.0f,DP_COMMUNICATION},
		{1784.0f,399.0f,DP_IMAGINATION},
		{2019.0f,574.0f,DP_SCHOLASTIC},
		{2361.0f,575.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン7 S8
	{
		{311.0f,574.0f,	DP_COMMUNICATION},
		{336.0f,174.0f,	DP_CHARM},
		{590.0f,395.0f,DP_ACTION},
		{680.0f,39.0f,DP_IMAGINATION},
		{917.0f,336.0f,DP_SCHOLASTIC},
		{1020.0f,33.0f,DP_CHARM},
		{1375.0f,456.0f,DP_COMMUNICATION},
		{1482.0f,94.0f,DP_SCHOLASTIC},
		{1637.0f,572.0f,DP_IMAGINATION},
		{2435.0f,573.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン8 S9
	{
		{197.0f,574.0f,	DP_ACTION},
		{491.0f,174.0f,	DP_SCHOLASTIC},
		{998.0f,574.0f,DP_CHARM},
		{1382.0f,156.0f,DP_COMMUNICATION},
		{1531.0f,573.0f,DP_IMAGINATION},
		{1724.0f,126.0f,DP_ACTION},
		{1917.0f,573.0f,DP_SCHOLASTIC},
		{1942.0f,22.0f,DP_COMMUNICATION},
		{2285.0f,300.0f,DP_CHARM},
		{2367.0f,574.0f,DP_IMAGINATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン9
	{
		{47.0f,574.0f,DP_IMAGINATION},
		{336.0f,166.0f,	DP_SCHOLASTIC},
		{461.0f,574.0f,DP_CHARM},
		{601.0f,32.0f,DP_ACTION},
		{677.0f,574.0f,DP_COMMUNICATION},
		{820.0f,32.0f,DP_SCHOLASTIC},
		{895.0f,574.0f,DP_CHARM},
		{1057.0f,32.0f,DP_ACTION},
		{1109.0f,574.0f,DP_COMMUNICATION},
		{1465.0f,156.0f,DP_IMAGINATION},
		{1581.0f,574.0f,DP_ACTION},
		{1707.0f,118.0f,DP_COMMUNICATION},
		{1901.0f,574.0f,DP_CHARM},
		{1937.0f,118.0f,DP_IMAGINATION},
		{2328.0f,574.0f,DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン10
	{
		{39.0f,368.0f,DP_ACTION},
		{353.0f,156.0f,DP_CHARM},
		{401.0f,478.0f,DP_COMMUNICATION},
		{578.0f,98.0f,DP_SCHOLASTIC},
		{759.0f,478.0f,DP_COMMUNICATION},
		{1007.0f,322.0f,DP_IMAGINATION},
		{1007.0f,22.0f,DP_CHARM},
		{1392.0f,164.0f,DP_SCHOLASTIC},
		{1677.0f,538.0f,DP_ACTION},
		{1739.0f,20.0f,DP_COMMUNICATION},
		{1933.0f,474.0f,DP_CHARM},
		{1997.0f,110.0f,DP_IMAGINATION},
		{2187.0f,474.0f,DP_ACTION},
		{2243.0f,24.0f,DP_IMAGINATION},
		{10000,0,DP_COUNT}
	},
	//マップパターン11
	{
		{406,541,DP_CHARM},
		{622,274,DP_COMMUNICATION},
		{1066,366,DP_IMAGINATION},
		{1489,211,DP_ACTION},
		{1887,64,DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン12
	{

		{150,529,DP_COMMUNICATION},
		{487,266,DP_CHARM},
		{797,522,DP_IMAGINATION},
		{1029,331,DP_ACTION},
		{1244,525,DP_SCHOLASTIC},
		{1572,359,DP_COMMUNICATION},
		{1849,64,DP_CHARM},
		{1925,404,DP_IMAGINATION},
		{2159,561,DP_ACTION},
		{2375,117,DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//マップパターン13
	{

		{157,473,DP_ACTION},
		{449,127,DP_IMAGINATION},
		{662,327,DP_COMMUNICATION},
		{837,23,DP_SCHOLASTIC},
		{1354,521,DP_CHARM},
		{1631,139,DP_IMAGINATION},
		{1784,521,DP_SCHOLASTIC},
		{2110,521,DP_CHARM},
		{2123,27,DP_COMMUNICATION},
		{2352,299,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//マップパターン14
	{
		{138.0f,574.0f,DP_IMAGINATION},
		{425.0f,168.0f,DP_COMMUNICATION},
		{598.0f,574.0f,DP_SCHOLASTIC},
		{1464.0f,368.0f,DP_ACTION},
		{2421.0f,112.0f,DP_CHARM},
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
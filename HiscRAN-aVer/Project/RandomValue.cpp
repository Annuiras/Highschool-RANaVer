#include "RandomValue.h"
#include <random>


// ランダムシード
std::random_device rnd;
std::mt19937 mt(rnd());



int RandomValue::GetRandomNumbe(int begin, int end)
{
	// 生成範囲設定
	std::uniform_int_distribution<int> dist(begin, end);
	int rnd_data;
	return rnd_data = dist(mt);
}
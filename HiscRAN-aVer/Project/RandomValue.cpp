#include "RandomValue.h"
#include <random>

///////////////////////////////////////////
//　ランダムの変数を決めるプログラムです //
//								   　　　//
//　作成者：田中環  　　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/17		   　　　//
///////////////////////////////////////////

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
#include "RandomValue.h"
#include <random>


// �����_���V�[�h
std::random_device rnd;
std::mt19937 mt(rnd());



int RandomValue::GetRandomNumbe(int begin, int end)
{
	// �����͈͐ݒ�
	std::uniform_int_distribution<int> dist(begin, end);
	int rnd_data;
	return rnd_data = dist(mt);
}
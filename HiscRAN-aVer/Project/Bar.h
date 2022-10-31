#pragma once
#include "Mof.h"

//大
#define BAR_BIG_WIDTH	800
#define BAR_BIG_HEIGHT	40

//中
#define BAR_MEDIUM_WIDTH	500
#define BAR_MEDIUM_HEIGHT	25

//小
#define BAR_SMALL_WIDTH		300
#define BAR_SMALL_HEIGHT	5


#define BAR_VOLUME	5


class Bar
{
private:


	//座標
	float b_PosX;
	float b_PosY;

	//足場タイプ別横幅
	float b_HitWidth;

	//表示フラグ:true：表示
	bool b_Show;

	//足場種類（仮）
	//1:大
	//2:中
	//3:小
	int b_Type;



public:

	Bar();
	~Bar();



	void Render(void);
	void Initialize(void);
	void Start(float posy,int type);
	void Update(float over);

	CRectangle GetRect(int type);


	float GetY(void) { return b_PosY; }

	bool Getshow(void) { return b_Show; }

	//足場の種類を取得
	int Gettype(void) { return b_Type; }


};


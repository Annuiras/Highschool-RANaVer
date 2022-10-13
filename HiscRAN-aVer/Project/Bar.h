#pragma once
#include "Mof.h"
#define BAR_WIDTH	300
#define BAR_HEIGHT	5
#define BAR_MAX	20

class Bar
{
private:



	float b_PosX;
	float b_PosY;


	bool b_Show;


public:

	Bar();
	~Bar();



	void Render(void);
	void Initialize(void);
	void Start(float posy);
	void Update(float over);

	CRectangle GetRect(void) {

		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_WIDTH, b_PosY + BAR_HEIGHT);
	}


	float GetY(void) { return b_PosY; }

	bool Getshow(void) { return b_Show; }



};


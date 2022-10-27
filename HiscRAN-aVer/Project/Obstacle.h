#pragma once
#include "Mof.h"
#define OB_VOLUME 5


class CObstacle
{

private:

	float ob_PosX;
	float ob_PosY;

	//表示フラグ:true：表示
	bool ob_Show;

	//当たり判定
	float ob_hitboxX;
	float ob_hitboxY;

	//todo:障害物種類（仮）
	//1:椅子
	//2:黒板消し
	//3:ボール
	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);
	void Update(float over);
	void Start(float posy,int type);

	void Render(void);
	void DebuggingRender(void);



	CRectangle GetRect(int type);

	bool Getshow(void) { return ob_Show; }

	bool GetType(void) { return ob_Type; }

	void Setshow(bool b) { ob_Show = b; }

};


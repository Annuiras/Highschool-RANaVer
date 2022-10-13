#pragma once
#include "Mof.h"
#define OB_VOLUME 5


class CObstacle
{

private:

	float ob_PosX;
	float ob_PosY;

	bool ob_Show;

	//当たり判定
	float ob_hitboxX;
	float ob_hitboxY;

	//プレイ中に追加される判定
	float ob_addX;
	float ob_addY;


public:

	CObstacle();
	~CObstacle();

	void Initialize(void);
	void Update(float over);
	void Start(float posy);

	void Render(void);
	void DebuggingRender(void);

	//セーブ
	void SaveRect(void)
	{
		//dp_option.SaveDPhitboxX(dp_hitboxX + dp_addX);
		//dp_option.SaveDPhitboxY(dp_hitboxY + dp_addY);

		//dp_option.SaveStatusValue(dp_value);
	}


	CRectangle GetRect(void) {

		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + ob_hitboxX + ob_addX, ob_PosY + ob_hitboxY + ob_addY);
	}

	bool Getshow(void) { return ob_Show; }

	void Setshow(bool b) { ob_Show = b; }

};


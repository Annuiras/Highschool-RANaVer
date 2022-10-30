#pragma once
#include "Mof.h"
#define OB_VOLUME 5

#define OB_DESK_WIDTH 137
#define OB_DESK_HEIGHT 180

class CObstacle
{

private:

	//todo:仮テクスチャ:椅子
	CTexture	ob_Textuer_Desk;

	////仮テクスチャ:
	//CTexture	ob__Textuer;

	////仮テクスチャ:
	//CTexture	ob__Textuer;

	float ob_PosX;
	float ob_PosY;

	//表示フラグ:true：表示
	bool ob_Show;

	//todo:障害物タイプ別横幅
	float ob_HitWidth;

	//todo:障害物種類（仮）
	//1:机
	//2:２段机
	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);

	//todo:ロード追加です
	bool Load(void);


	void Update(float over);
	void Start(float posy,int type);

	void Render(void);
	void RenderDebugging(void);



	CRectangle GetRect(int type);

	bool Getshow(void) { return ob_Show; }

	bool GetType(void) { return ob_Type; }

	void Setshow(bool b) { ob_Show = b; }

};


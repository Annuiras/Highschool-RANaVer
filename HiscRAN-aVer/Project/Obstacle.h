#pragma once
#include "Mof.h"
#include "Define.h"

class CObstacle
{

private:

	//仮テクスチャ
	CTexture*	ob_Textuer;

	//座標
	float ob_PosX;
	float ob_PosY;

	//表示フラグ:true：表示
	bool ob_Show;

	//障害物タイプ別横幅
	float ob_HitWidth;

	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);


	void Update(float over);
	void Start(float posy,int type);

	//OBテクスチャをセット
	void SetTexture(CTexture* obtex);

	void Render(void);
	void RenderDebugging(void);


	//ダメージ矩形取得
	CRectangle GetRect(int type);

	//障害物上に乗れる当たり判定取得
	CRectangle GetTopBarRect(int type);


	//表示中フラグ取得
	bool Getshow(void) { return ob_Show; }

	//障害物タイプ取得
	bool GetType(void) { return ob_Type; }

	//Y座標取得
	float GetY(int type) { return GetTopBarRect(type).Top; }

	//表示フラグセット
	void Setshow(bool b) { ob_Show = b; }

};


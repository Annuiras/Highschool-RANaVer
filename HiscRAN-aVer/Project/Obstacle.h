#pragma once
#include "Define.h"
//制作者：田中 環、石川 由妃、永井 悠太

class CObstacle
{

private:

	//仮テクスチャ
	CTexture*	m_Textuer;

	//座標
	float m_PosX;
	float m_PosY;

	//表示フラグ:true：表示
	bool m_Show;

	//障害物タイプ別横幅
	float m_HitWidth;

	//タイプ
	int m_Type;

public:

	CObstacle();
	~CObstacle();

	//初期化
	void Initialize(void);

	//更新
	void Update(float over);

	//生成
	//[posy]:Y座標
	//[type]:種類
	void Start(float posy,int type);

	//OBテクスチャをセット
	void SetTexture(CTexture* obtex);

	//描画
	void Render(void);
	void RenderDebugging(void);


	//ダメージ矩形取得
	CRectangle GetRect(void);

	//障害物上に乗れる当たり判定取得
	CRectangle GetTopBarRect(void);


	//表示中フラグ取得
	bool Getshow(void) { return m_Show; }

	//障害物タイプ取得
	bool GetType(void) { return m_Type; }

	//Y座標取得
	float GetY(void) { return GetTopBarRect().Top; }

	//表示フラグセット
	void Setshow(bool b) { m_Show = b; }

};


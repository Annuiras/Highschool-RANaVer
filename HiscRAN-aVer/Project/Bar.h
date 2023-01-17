#pragma once
#include "Define.h"
//////////////////////////////////////////////
//	足場のバー（えんぴつ）のプログラムです　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

class Bar
{
private:

	//足場のテクスチャを追加
	//足場テクスチャ
	CTexture* m_Texture;


	//座標
	float m_PosX;
	float m_PosY;

	//足場タイプ別横幅
	float m_HitWidth;

	//表示フラグ:true：表示
	bool m_Show;

	//タイプ
	int m_Type;

public:

	Bar();
	~Bar();

	//初期化
	void Initialize(void);

	//更新
	void Update(float over);

	//生成
	void Start(float posy, int type);

	//描画
	void Render(void);
	void RenderDebugging(void);

	//当たり判定渡す
	CRectangle GetRect(void);

	//Y座標を渡す
	float GetY(void) { return m_PosY; }

	//表示中？
	//true:表示中
	bool Getshow(void) { return m_Show; }

	//テクスチャをセット
	void SetTexture(CTexture* bartex);

	//足場の種類を取得
	int Gettype(void) { return m_Type; }


};


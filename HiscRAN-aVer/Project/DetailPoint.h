#pragma once
#include "Define.h"
//////////////////////////////////////////////
//	DPのプログラムです			　　　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

//一画面に存在する最大DP
#define DP_VOLUME	40

class DetailPoint
{
private:

	//座標
	float m_PosX;
	float m_PosY;

	//表示フラグ
	//true:表示中
	bool m_Show;

	//DPテクスチャ
	CTexture* m_Texture;

	//DPタイプ
	int m_Type;

	//当たり判定
	float	m_HitboxX;
	float	m_HitboxY;

public:

	DetailPoint();
	~DetailPoint();

	//描画
	void Render(void);

	//初期化
	void Initialize(void);

	//DPテクスチャをセット
	void SetTexture(CTexture* dptex);

	//表示開始
	void Start(float posy, int type);

	//[scroll]：スクロール値
	void Update(float scroll);

	void RenderDebugging(void);

	CRectangle GetRect(void) {

		return CRectangle(m_PosX, m_PosY,
			m_PosX + m_HitboxX, m_PosY + m_HitboxY);
	}

	//DPの種類を取得
	int Gettype(void) { return m_Type; }

	//表示true：非表示falseフラグ
	bool Getshow(void) { return m_Show; }

	//DPの表示切り替え
	void Setshow(bool b) { m_Show = b; }

};


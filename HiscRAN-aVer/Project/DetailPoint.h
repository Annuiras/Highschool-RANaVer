#pragma once
#include "Mof.h"
#define DP_VOLUME	50

class DetailPoint
{
private:

	float dp_PosX;
	float dp_PosY;

	bool dp_Show;

	//DPタイプ
	//１：学力
	//２：行動力
	//３：想像力
	//４：コミュ力
	//５：魅力
	int dp_Type;

	//ステータス上昇値
	float dp_value;

	//当たり判定
	float	dp_hitboxX;
	float	dp_hitboxY;

	//スピード
	float dp_SpeedX;
	float dp_SpeedY;


	//DP引き寄せ
	bool dp_attraction;


public:

	DetailPoint();
	~DetailPoint();

	void Render(void);
	void Initialize(void);

	void Start(float posy, int type);

	//[over]：プレイヤーのオーバー値
	void Update(float over);
	void DebuggingRender(void);

	//DPをプレイヤーへ飛ばす
	void UpdateAtraction(float px, float py);
	//DP引き寄せ
	void UpdateFire(float sx, float sy);


	//DP（ポイント）当たり判定
	bool CollosopnDP(CRectangle r);

	CRectangle GetRect(void) {

		return CRectangle(dp_PosX, dp_PosY,
			dp_PosX + dp_hitboxX, dp_PosY + dp_hitboxY);
	}

	//DPの種類を取得
	int Gettype(void) { return dp_Type; }

	//表示true：非表示falseフラグ
	bool Getshow(void) { return dp_Show; }

	float Getvalue(void) { return dp_value; }

	//DPの表示切り替え
	void Setshow(bool b) { dp_Show = b; }

};


#pragma once
#include "Mof.h"

//todo:一画面に存在する最大DPに変更
#define DP_VOLUME	10

class DetailPoint
{
private:

	float dp_PosX;
	float dp_PosY;

	bool dp_Show;

	//todo:仮テクスチャ追加です
	//仮テクスチャ：学力
	CTexture dp_Textuer_Scholastic;

	//仮テクスチャ：行動力
	CTexture dp_Textuer_Action;

	//仮テクスチャ：想像力
	CTexture dp_Textuer_Imagination;

	//仮テクスチャ：コミュ力
	CTexture dp_Textuer_Communication;

	//仮テクスチャ：魅力
	CTexture dp_Textuer_Charm;

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

	//todo:ロード追加です
	bool Load(void);

	//todo:リソース解放
	void Release(void);

	//表示開始
	void Start(float posy, int type);

	//[over]：プレイヤーのオーバー値
	void Update(float over);
	void RenderDebugging(void);

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


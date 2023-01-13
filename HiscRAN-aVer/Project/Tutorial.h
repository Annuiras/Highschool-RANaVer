#pragma once
#include "Define.h"
#include "SceneBase.h"

//ページ数
#define P_Z 3

//→見えない位置
#define R_Not 1043
//左見えない位置
#define L_Not -557

class CTutorial:public CSceneBase
{
private:

	//説明テクスチャ
	CTexture ExTextTexture[P_Z];

	//背景テクスチャ
	CTexture BGTexture;

	//スクリーンテクスチャ
	CTexture ScreenTexture;

	//カーテン部分テクスチャ
	CTexture CurtainBGTexture;

	//カーテン部分テクスチャ左
	CTexture CurtainBGTextureLeft;

	//カーテン部分テクスチャ右
	CTexture CurtainBGTextureRight;

	//カーテン上
	CTexture CurtainBGTextureTop;

	//戻るボタンテクスチャ
	CTexture BackButton;

	//選択枠
	CTexture ButtonSelect;

	//スクロール値
	int m_Scroll;

	//座標値（X軸方向）
	int gPosX[P_Z];

	//画像枚数カウント
	int count;

	//移動中フラグ
	bool Is_Move;

	//X軸方向にどれだけ動いたか
	int MoveX;

	//見えてるか見えてないか
	bool bShow;

	//戻るボタンにカーソルがあるかないか
	bool TMenuCnt;

	//背景α値
	int m_BakAlph;


public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};


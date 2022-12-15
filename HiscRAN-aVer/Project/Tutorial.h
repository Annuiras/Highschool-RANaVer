#pragma once
#include "Define.h"
#include "SceneBase.h"

class CTutorial:public CSceneBase
{
private:

	//背景テクスチャ
	CTexture BGTexture;

	//説明背景テクスチャ
	CTexture ScreenBGTexture;

	//カーテン部分テクスチャ（後日削除）
	CTexture CurtainBGTexture;

	//戻るボタンテクスチャ
	CTexture BackButton;

	//選択枠
	CTexture ButtonSelect;

	//スクロール値
	int m_Scroll;

	//座標値（X軸方向）
	int gPosX;

	//画像枚数カウント
	int count;

	//X軸方向にどれだけ動いたか
	int MoveX;

	//見えてるか見えてないか
	bool bShow;

	//戻るボタンにカーソルがあるかないか
	int TMenuCnt;

public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};


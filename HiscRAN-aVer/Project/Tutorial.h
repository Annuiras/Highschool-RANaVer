///////////////////////////////////////////
//　チュートリアルのプログラムです   　　//
//								   　　　//
//　作成者：松浦未羽  　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/17		   　　　//
///////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Music.h"
#include "SceneBase.h"

//ページ数
#define PAGES_NUM 7

//説明画像固定位置
#define PAGES_X 243
#define PAGES_Y 94

//スクロールスピード
#define PAGES_SPEED 20


class CTutorial:public CSceneBase
{
private:

	//説明テクスチャ
	CTexture ExTextTexture[PAGES_NUM];

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

	//ページごとのX座標
	int gPosX[PAGES_NUM];

	//現在のページ
	int m_Cursor;

	//移動中フラグ
	bool Is_Move;

	//
	int MoveX;

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


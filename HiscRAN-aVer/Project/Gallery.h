////////////////////////////////////////
//	ギャラリーのプログラムです　　　　//
//									　//
//　作成者：松浦未羽　　　　　		　//
//									　//
//　リファクタリングした人：田中環　　//
//									　//
//　最終更新：2023/01/17			　//
////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Gallery.h"
#include "Define_Music.h"
#include "SceneBase.h"

//選択肢数
#define MenuCnt (15)


class CGallery :public CSceneBase
{
private:

	//コレクション画面背景テクスチャ
	CTexture	m_BackTexture;

	//解放済み最終容姿選択:本棚テクスチャ
	CTexture	m_LastApp;

	//選択時の四角形（最終容姿）
	CTexture	m_SelectTexture;

	//選択時の四角形（戻るボタン）
	CTexture	m_SelectTexture_s;

	//最終容姿背景
	CTexture m_BakLastAp;

	//最終容姿パラメータ構造体
	//構造体定義
	typedef struct LastTexture
	{
		//最終容姿テクスチャ（ピックアップ用）
		CTexture s_LastAppPic;

		//未開放フラグ
		bool s_LastAddFlag;

		//未解放本テクスチャ
		CTexture s_NotLastApp;
	};

	//最終容姿パラメータ構造体
	LastTexture S_LastParameter[16];

	//最終容姿背景表示矩形
	CRectangle m_BakLastRect[BL_COUNT];

	//解放済み最終容姿テキスト
	CTexture	m_PickUpText;

	//未解放最終容姿テキスト
	CTexture	m_NotPickUpText;

	//テキストボックス背景
	CTexture	m_Text;

	//戻るボタン
	CTexture	m_BackButton;

	//フェードアウト用アルファ値
	int m_BakAlph;

	//カーソル番号
	int m_galleryCnt;

public:
	CGallery();
	~CGallery();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};


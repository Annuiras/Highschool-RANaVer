///////////////////////////////////////////
//　モードセレクト画面のプログラムです   //
//								   　　　//
//　作成者：松浦未羽　　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/17		   　　　//
///////////////////////////////////////////

#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "Define_Music.h"
#include "Define_Menu.h"

//選択肢数
#define MenuCnt (4)

//スクロール速度
#define		SCROLL_SPEED	1;

//モードセレクト画面
class CModeSelect :public CSceneBase
{
private:

	//非選択状態の選択肢まとめ
	CTexture		m_TutorialTextureSmall;

	//選択状態の選択肢まとめ
	CTexture		m_TutorialTextureBig;

	//背景画像まとめ
	CTexture		m_TutorialBG[4];

	//画面下テキスト背景
	CTexture		m_TutorialTextBox;

	//画面下テキスト
	CTexture		m_TutorialTextTexture;
	//画面下テキストスクロール値
	float			m_Scroll;

	//モードセレクトカーソル位置
	int MenuNow_Mode;

	//フェードアウト用アルファ値
	int m_BakAlph;

public:
	CModeSelect();
	~CModeSelect();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effecs, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);

};


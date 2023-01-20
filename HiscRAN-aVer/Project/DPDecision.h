///////////////////////////////////////////
//　DP選択画面のプログラムです   　　  　//
//								   　　　//
//　作成者：松浦未羽  　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/19		   　　　//
///////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Music.h"
#include "Define_Menu.h"
#include "RandomValue.h"
#include "SceneBase.h"

//選択肢数
#define DPDECISION_MENUCNT 5

class CDPDecision :public CSceneBase
{
private:

	//乱数生成
	RandomValue RandmuBak;

	//画面説明
	CTexture	m_Screen_Ex;

	//背景黒板
	CTexture	m_Back_BB;

	//黒塗りキャラ
	CTexture	m_BackChara_B;

	//説明文字
	CTexture	m_Target_Text;

	//選択枠
	CTexture	m_SelectTexture;
	
	//マグネット&名前
	CTexture	m_BackMagnet_Name;

	//フェードイン背景アルファ値
	int m_WhiteBakAlph;

	//選択肢番号
	int DPDecCnt;

	//DP選択説明表示フラグ
	//true:表示中
	bool flagD;

	//SPステージありフラグ
	//true：SPあり
	bool SP_flg;


public:
	CDPDecision();
	~CDPDecision();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);

	void UpdateDebug(void);

	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};


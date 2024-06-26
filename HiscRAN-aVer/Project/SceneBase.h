#pragma once
#include "Define.h"
#include "GameProgMgmt.h"
#include "MusicManager.h"
#include "EffectManager.h"
#include "Menu.h"

///////////////////////////////////////////
//　各ゲーム画面の根幹となる処理です　   //
//								   　　  //
//　作成者：田中環　  　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/20		   　　　//
///////////////////////////////////////////

class CSceneBase {
protected:

	//シーン終了フラグ
	//true:終了
	bool		m_bEnd;

	//現在のシーン
	tag_SCENENO m_NowScene;

	//次のシーン
	tag_SCENENO		m_NextScene;

	//マネージャーポインタ
	CGameProgMgmt* b_GameProgMamt;
	CMusicMgmt* b_MusicManager;
	CEffectMgmt* b_EffectManeger;
	CMenu* b_MenuMamt;

	//推移フラグ
	tag_SceneSituation b_Fadein;

	//ロード状況
	tag_LoadSituation b_LoadSitu;


public:
	CSceneBase() :

		b_GameProgMamt(),
		b_MusicManager(),
		b_EffectManeger(),
		b_Fadein(),
		b_LoadSitu(LOAD_YET),
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE),
		m_NowScene(SCENENO_TITLE)
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize(CGameProgMgmt* mamt,CMusicMgmt* musi, 
							CEffectMgmt* effec,CMenu* menu) = 0;
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void UpdateDebug() = 0;
	virtual void Render() = 0;
	virtual void RenderDebug() = 0;
	virtual void Release() = 0;


	//次のシーン取得
	int GetNextScene(void) { return m_NextScene; }

	//終了フラグ取得
	bool IsEnd(void) { return m_bEnd; }

	//現在のシーン取得
	int IsNow(void) { return m_NowScene; }

	//子クラス以外からシーン遷移
	void SetEnd(bool b) { m_bEnd = b; }
	void SetNextScene(tag_SCENENO i) { m_NextScene = i; }

	//ロード状況セット
	void SetLoadSitu(tag_LoadSituation l) { b_LoadSitu = l; }
	//ロード状況取得
	tag_LoadSituation GetLoadSitu(void) { return b_LoadSitu; }

	//フェードイン処理
	//A:減少させる変数
	//b:falseの場合フェード状態を変更しない
	//s：フェードインスピード　デフォは FADE_OUT_SPEED
	//値が255になるとフェード状態をFADE_NOTに移行させる
	//return:減少させた値
	float FadeIn(float A, bool b, float s = FADE_OUT_SPEED);

	//フェードアウト処理
	//A:増加させる変数
	//b:falseの場合フェード状態を変更しない
 	//s：フェードインスピード　デフォは FADE_OUT_SPEED
	//値が255になるとフェード状態をFADE_NEXTに移行させる
	//return:増加させた値
	float FadeOut(float A, bool b, float s = FADE_OUT_SPEED);

};
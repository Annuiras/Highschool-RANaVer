/////////////////////////////////////
//　メニュー画面のプログラムです   //
//								   //
//　作成者：松浦未羽　　　　　　　 //
//								   //
//　リファクタリングした人：田中環 //
//								   //
//　最終更新：2023/01/17		   //
/////////////////////////////////////

#pragma once
#include "EffectManager.h"
#include "MusicManager.h"
#include "Define.h"
#include "Define_Menu.h"

//メニュー管理クラスです
class CMenu
{
private:

	//マネージャー
	CMusicMgmt* m_MusicMamt;
	CEffectMgmt* m_EffectMamt;

	//アプリケーション終了メニュー
	CTexture	m_MenuEndTexture;

	//ゲームポーズメニュー
	CTexture	m_MenuPauseTexture;

	//DP選択決定メニュー
	CTexture	m_MenuDPTexture;

	//DP選択決定時のDP種類まとめ
	CTexture	m_MenuDPTexTexture;

	//メニュー選択チェックマーク
	CTexture	m_MenuCheck;

	//描画位置変数(X座標)
	float		m_cx;

	//描画位置変数(Y座標)
	float		m_cy;

	//選択肢数
	int			m_Count;

	//選択肢番号
	int			m_Select;

	//表示フラグ
	//true:表示中
	bool		m_bShow;

	//決定フラグ
	//true:決定済み
	bool		m_bEnter;

	//種類
	tag_MenuType m_Type;

	CRectangle		m_Rect;

public:
	CMenu();
	~CMenu();
	
	//素材ロード
	tag_LoadSituation Load(void);

	void Release(void);

	//表示
	//Type：メニュー種類
	void Show(tag_MenuType Type);

	//非表示処理
	void Hide(void) { m_bShow = false; }

	//更新
	void Update(void);

	//描画
	void Render(void);

	//DP選択確定用描画
	void Render(int Type);

	//表示中?
	//true：表示中
	bool IsShow(void) { return m_bShow; }

	//項目決定?
	//true:決定済み
	bool IsEnter(void) { return m_bEnter; }

	//選択肢番号取得
	int  GetSelect(void) { return m_Select; }

	//SE・BGMマネージャーセット
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMamt = mgmt; }

	//エフェクトマネージャーセット
	void SetEffectManager(CEffectMgmt* mgmt) { m_EffectMamt = mgmt; }

	//メニューの種類を取得
	tag_MenuType GetMenuType(void) {return m_Type;}

	//選択肢の数を取得
	//int  GetCount(void) { return m_Count; }

};
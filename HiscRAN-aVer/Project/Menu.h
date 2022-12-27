#pragma once
#include "EffectManager.h"
#include "MusicManager.h"
#include "Define.h"

//メニュー管理クラスです
class CMenu
{
private:

	//マネージャー
	CMusicMgmt* m_MusicMamt;
	CEffectMgmt* m_EffectMamt;

	CTexture	m_MenuEndTexture;
	CTexture	m_MenuPauseTexture;

	CTexture	m_MenuDPTexture;
	CTexture	m_MenuDPTexTexture;

	CTexture	m_MenuCheck;

	float		m_cx;
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

	int  GetCount(void) { return m_Count; }

};
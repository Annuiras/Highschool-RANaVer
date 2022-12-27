#pragma once

#include "Define.h"

//メニュー管理クラスです
class CMenu
{
private:

	CTexture	m_MenuEndTexture;
	CTexture	m_MenuPauseTexture;

	CTexture	m_MenuDPTexture;
	CTexture	m_MenuDPTexTexture;

	CTexture	m_MenuCheck;

	float		m_cx;
	float		m_cy;

	int			m_Count;

	int			m_Select;

	bool		m_bShow;
	bool		m_bEnter;

	CRectangle		m_Rect;

public:
	CMenu();
	~CMenu();
	void Create(int cnt);
	void Release(void);
	void Show(float cx, float cy);
	void Hide(void) { m_bShow = false; }
	void Update(void);
	void Render(int cnt);
	void RenderB(bool flag1, bool flag2, bool flag3, bool flag4, bool flag5);
	bool IsShow(void) { return m_bShow; }
	bool IsEnter(void) { return m_bEnter; }
	int  GetSelect(void) { return m_Select; }
	int  GetCount(void) { return m_Count; }

};
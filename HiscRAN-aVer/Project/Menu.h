#pragma once

#include "Mof.h"

class CMenu
{
private:
	CTexture	m_MenuTexture;

	CTexture	m_MenuText;

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
	bool IsShow(void) { return m_bShow; }
	bool IsEnter(void) { return m_bEnter; }
	int  GetSelect(void) { return m_Select; }
	int  GetCount(void) { return m_Count; }

};
#pragma once
#include "Mof.h"

class CGameOver
{
private:
	CTexture	m_BackTexture1;
	CTexture	m_BackTexture2;
	CTexture	m_BackTexture3;
	CTexture	m_UITexture;
	CTexture	m_SelectTexture;
	int			Rondom;

public:
	CGameOver();
	~CGameOver();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};


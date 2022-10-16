#pragma once
#include	"Mof.h"

class Option
{
private:
	CSoundBuffer	m_BGM;
	CSoundBuffer	m_SE;

	CTexture		m_mount;
	CTexture		m_Stick1;
	CTexture		m_Stick2;
	CTexture		m_Button1_1;
	CTexture		m_Button1_2;
	CTexture		m_Button2;
	CTexture		m_Button3;
	CTexture		m_Select;

public:
	Option();
	~Option();
	void Initialize(void);
	void Update(void);
	void Render(void);
	bool Load(void);
	void Release(void);
};


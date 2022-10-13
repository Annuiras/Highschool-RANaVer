#pragma once
#include	"Mof.h"

#define		SCROLL_SPEED	1;

class Title
{
private:
	//背景のテクスチャ
	CTexture	m_BackTexture;

	//タイトルのテクスチャ
	CTexture	m_TitleTexture;

	//TitleUIのテクスチャ
	CTexture	m_TiTleUITexture;

	//fontクラス
	CFont		gFont;
	CFont		gFont2;

	//スクロール値
	float		m_Scroll;
public:
	Title();
	~Title();
	void Initialize(void);
	void Update(void);
	void Render(void);
	bool Load(void);
	void Release(void);

};


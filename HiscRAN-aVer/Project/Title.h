#pragma once
#include	"Mof.h"
#include "SceneBase.h"
#include "Define.h"

//スクロール速度
#define		SCROLL_SPEED	1;

class CTitle :public CSceneBase
{
private:
	//背景のテクスチャ
	CTexture	m_BackTexture1;
	CTexture	m_BackTexture2;
	CTexture	m_BackTexture3;


	//タイトルのテクスチャ
	CTexture	m_TitleTexture;

	//TitleUIのテクスチャ
	CTexture	m_TiTleUITexture;

	//fontクラス
	CFont		gFont;
	CFont		gFont2;

	//スクロール値
	float		m_Scroll;

	//ランダム用
	int			Rondom;

public:
	CTitle();
	~CTitle();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);

};

